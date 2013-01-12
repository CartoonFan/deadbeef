/*
    WMA plugin for deadbeef
    Copyright (C) 2013 Alexey Yakovenko <waker@users.sourceforge.net>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#include "../../deadbeef.h"
#ifdef HAVE_CONFIG_H
#include "../../config.h"
#endif
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "libasf/asf.h"

//#define USE_FFMPEG 1

#if USE_FFMPEG
#include "libwma-ff/wma.h"
#else
#include "libwma/wmadec.h"
#endif

#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

#define trace(...) { fprintf(stderr, __VA_ARGS__); }
//#define trace(fmt,...)

static DB_decoder_t plugin;
DB_functions_t *deadbeef;

#define MAX_PACKET_SIZE 100000

typedef struct {
    DB_fileinfo_t info;
    asf_waveformatex_t wfx;
#if USE_FFMPEG
    WMACodecContext wmadec;
#else
    WMADecodeContext wmadec;
#endif
    DB_FILE *fp;
    int64_t first_frame_offset;
    int currentsample;
    int startsample;
    int endsample;
    char buffer[MAX_PACKET_SIZE];
    int remaining;
} wmaplug_info_t;

// allocate codec control structure
static DB_fileinfo_t *
wmaplug_open (uint32_t hints) {
    DB_fileinfo_t *_info = malloc (sizeof (wmaplug_info_t));
    wmaplug_info_t *info = (wmaplug_info_t *)_info;
    memset (info, 0, sizeof (wmaplug_info_t));
    return _info;
}

int get_asf_metadata(DB_FILE *fd, DB_playItem_t *it, asf_waveformatex_t *wfx, int64_t *first_frame_offset);

static int
wmaplug_init (DB_fileinfo_t *_info, DB_playItem_t *it) {
    wmaplug_info_t *info = (wmaplug_info_t *)_info;

    info->fp = deadbeef->fopen (deadbeef->pl_find_meta (it, ":URI"));
    if (!info->fp) {
        return -1;
    }


    get_asf_metadata (info->fp, NULL, &info->wfx, &info->first_frame_offset);
    deadbeef->fseek (info->fp, info->first_frame_offset, SEEK_SET);
#if USE_FFMPEG
    info->wmadec.sample_rate = info->wfx.rate;
    info->wmadec.nb_channels = info->wfx.channels;
    info->wmadec.channels = info->wfx.channels;
    info->wmadec.bit_rate = info->wfx.bitrate;
    info->wmadec.block_align = info->wfx.blockalign;
    info->wmadec.codec_id = info->wfx.codec_id;
    printf ("codec id: %x\n",  info->wmadec.codec_id);
    info->wmadec.extradata = info->wfx.data;
    if (wma_decode_init (&info->wmadec)) {
        trace ("wma_decode_init fail\n");
        return -1;
    }
    trace ("wma_decode_init success\n");
#else
    if (wma_decode_init(&info->wmadec,&info->wfx) < 0) {
        return -1;
    }
#endif

    info->currentsample = 0;
    info->startsample = it->startsample;
    info->endsample = it->endsample;
    _info->plugin = &plugin;
    _info->fmt.bps = info->wfx.bitspersample;
    _info->fmt.channels = info->wfx.channels;
    _info->fmt.samplerate = info->wfx.rate;
    for (int i = 0; i < _info->fmt.channels; i++) {
        _info->fmt.channelmask |= 1 << i;
    }
    return 0;
}

static void
wmaplug_free (DB_fileinfo_t *_info) {
    wmaplug_info_t *info = (wmaplug_info_t *)_info;
    if (info) {
#if USE_FFMPEG
        ff_wma_end (&info->wmadec);
#endif
        if (info->fp) {
            deadbeef->fclose (info->fp);
        }
        free (info);
    }
}

static int
wmaplug_read (DB_fileinfo_t *_info, char *bytes, int size) {
    wmaplug_info_t *info = (wmaplug_info_t *)_info;
    int samplesize = _info->fmt.channels * _info->fmt.bps / 8;
    if (!info->fp->vfs->is_streaming ()) {
        if (info->currentsample + size / samplesize > info->endsample) {
            size = (info->endsample - info->currentsample + 1) * samplesize;
            if (size <= 0) {
                trace ("wmaplug_read: eof (current=%d, total=%d)\n", info->currentsample, info->endsample);
                return 0;
            }
        }
    }
    int initsize = size;

#if !USE_FFMPEG
    while (size > 0) {
        if (info->remaining == 0) {
            int errcount = 0;
            int res = 0;
            uint8_t audiobuf_mem[40000];
            uint8_t* audiobuf = audiobuf_mem;
            int audiobufsize = 0;
            int packetlength = 0;
    new_packet:
            {
            int pos = deadbeef->ftell (info->fp);
            res = asf_read_packet(&audiobuf, &audiobufsize, &packetlength, &info->wfx, info->fp);
            int endpos = deadbeef->ftell (info->fp);
//            printf ("packet pos: %d, packet size: %d, data size: %d, blockalign: %d\n", pos, endpos-pos, packetlength, info->wfx.blockalign);
            }
            if (res > 0) {
                int nb = audiobufsize / info->wfx.blockalign;
                for (int b = 0; b < nb; b++) {
                    wma_decode_superframe_init(&info->wmadec, audiobuf + b * info->wfx.blockalign, info->wfx.blockalign);

                    int n = 0;
                    for (int i=0; i < info->wmadec.nb_frames; i++)
                    {
                        int wmares = wma_decode_superframe_frame(&info->wmadec,
                                audiobuf + b * info->wfx.blockalign, info->wfx.blockalign);

                        if (wmares < 0) {
                            /* Do the above, but for errors in decode. */
                            errcount++;
                            trace ("WMA decode error %d, errcount %d\n",wmares, errcount);
                            if (errcount > 5) {
                                break;
                            } else {
                                goto new_packet;
                            }
                        } else if (wmares > 0) {
                            int16_t *p = (int16_t *)&info->buffer[info->remaining];
                            for (int s = 0; s < wmares; s++) {
                                for (int ch = 0; ch < info->wfx.channels; ch++) {
                                    fixed32 *chan = info->wmadec.frame_out[ch];
                                    p[s*info->wfx.channels+ch] = chan[s] >> 16;
                                }
                            }
                            info->remaining += wmares * info->wfx.channels * info->wfx.bitspersample / 8;
                        }
                    }
                }
            }
        }

        int sz = min (size, info->remaining);
        if (sz == 0) {
            break;
        }
        memcpy (bytes, info->buffer, sz);
        if (info->remaining != sz) {
            memmove (info->buffer, info->buffer+sz, info->remaining-sz);
        }
        info->remaining -= sz;
        size -= sz;
    }
#else
// {{{ ffmpeg
    while (size > 0) {
        if (info->remaining == 0) {
            int errcount = 0;
            int res = 0;
            uint8_t audiobuf_mem[40000];
            uint8_t* audiobuf = audiobuf_mem;
            int audiobufsize = 0;
            int packetlength = 0;
    new_packet:
            //res = asf_read_packet(&audiobuf, &audiobufsize, &packetlength, &info->wfx, info->fp);
            {
            int pos = deadbeef->ftell (info->fp);
            res = asf_read_packet(&audiobuf, &audiobufsize, &packetlength, &info->wfx, info->fp);
            int endpos = deadbeef->ftell (info->fp);
            printf ("packet pos: %d, packet size: %d, data size: %d\n", pos, endpos-pos, packetlength);
            }
            if (res > 0) {
                int nblocks = audiobufsize / info->wfx.blockalign;
                for (int i = 0 ; i < nblocks; i++) {
                    int got_frame_ptr = 0;
                    char *data;
                    int bufsize = wma_decode_superframe (&info->wmadec, &got_frame_ptr, audiobuf + i * info->wfx.blockalign, info->wfx.blockalign);
                    printf ("got frame ptr: %d, bufsize: %d\n", got_frame_ptr, info->wmadec.nb_samples * 4);

                    int16_t *p = (int16_t *)&info->buffer[info->remaining];
                    memcpy (p, info->wmadec.output_buffer, info->wmadec.nb_samples * 4);
                    info->remaining += info->wmadec.nb_samples * 4;
                }
            }
        }

        int sz = min (size, info->remaining);
        if (sz == 0) {
            printf ("buffer is empty\n");
            break;
        }
        memcpy (bytes, info->buffer, sz);
        if (info->remaining != sz) {
            memmove (info->buffer, info->buffer+sz, info->remaining-sz);
        }
        info->remaining -= sz;
        size -= sz;
    }
#endif
// }}}

    return initsize-size;
}

static int
wmaplug_seek_sample (DB_fileinfo_t *_info, int sample) {
    wmaplug_info_t *info = (wmaplug_info_t *)_info;
    
    sample += info->startsample;

    /*flush the wma decoder state*/
    info->wmadec.last_superframe_len = 0;
    info->wmadec.last_bitoffset = 0;

    /*zero the frame out buffer so we don't overlap with a 
      stale samples*/
    memset(info->wmadec.frame_out, 0,
            sizeof(fixed32) * MAX_CHANNELS * BLOCK_MAX_SIZE * 2);

    int elapsedtime = asf_seek(sample * 1000 / _info->fmt.samplerate, &info->wfx, info->fp, info->first_frame_offset);
    if (elapsedtime <= 0) {
        // restart track
        info->currentsample = 0;
        printf ("seek failed\n");
    }
    else {
        // seek successful
        info->currentsample = elapsedtime * _info->fmt.samplerate / 1000;
        _info->readpos = (float)(info->currentsample - info->startsample)/_info->fmt.samplerate;
        printf ("seek success, sample=%d, pos=%f\n", info->currentsample, _info->readpos);
    }

    return 0;
}

static int
wmaplug_seek (DB_fileinfo_t *_info, float t) {
    return wmaplug_seek_sample (_info, t * _info->fmt.samplerate);
}

static int
wmaplug_read_metadata (DB_playItem_t *it) {
    return 0;
}

static DB_playItem_t *
wmaplug_insert (ddb_playlist_t *plt, DB_playItem_t *after, const char *fname) {
    asf_waveformatex_t wfx;

    DB_FILE *fp = deadbeef->fopen (fname);
    if (!fp) {
        return NULL;
    }

    int64_t first_frame_offset;

    DB_playItem_t *it = deadbeef->pl_item_alloc_init (fname, plugin.plugin.id);

    get_asf_metadata (fp, it, &wfx, &first_frame_offset);
    //printf ("datalen %d, channels %d, bps %d, rate %d\n", wfx.datalen, wfx.channels, wfx.bitspersample, wfx.rate);

    deadbeef->fseek (fp, first_frame_offset, SEEK_SET);

    int64_t i_count = (deadbeef->fgetlength (fp) - first_frame_offset) / wfx.packet_size;
    int64_t i_length = wfx.play_duration / 10 *
        i_count / wfx.numpackets - wfx.preroll * 1000;

    int64_t totalsamples = i_length / 1000 * wfx.rate / 1000;
//    printf ("totalsamples: %lld\n", totalsamples);

    deadbeef->plt_set_item_duration (plt, it, totalsamples / (float)wfx.rate);
    deadbeef->pl_append_meta (it, ":FILETYPE", "WMA");
    
    it->startsample = 0;
    it->endsample = totalsamples-1;

    after = deadbeef->plt_insert_item (plt, after, it);
    deadbeef->pl_item_unref (it);
    deadbeef->fclose (fp);
    return after;
}

static const char * exts[] = { "wma", NULL };

// define plugin interface
static DB_decoder_t plugin = {
    .plugin.api_vmajor = 1,
    .plugin.api_vminor = 0,
    .plugin.version_major = 1,
    .plugin.version_minor = 0,
    .plugin.type = DB_PLUGIN_DECODER,
    .plugin.id = "wma",
    .plugin.name = "WMA player",
    .plugin.descr = "plays WMA files",
    .plugin.copyright = 
        "WMA plugin for deadbeef\n"
        "Based on WMA and ASF code from RockBox (C) RockBox developers\n"
        "\n"
        "Copyright (C) 2013 Alexey Yakovenko <waker@users.sourceforge.net>\n"
        "\n"
        "This program is free software; you can redistribute it and/or\n"
        "modify it under the terms of the GNU General Public License\n"
        "as published by the Free Software Foundation; either version 2\n"
        "of the License, or (at your option) any later version.\n"
        "\n"
        "This program is distributed in the hope that it will be useful,\n"
        "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
        "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
        "GNU General Public License for more details.\n"
        "\n"
        "You should have received a copy of the GNU General Public License\n"
        "along with this program; if not, write to the Free Software\n"
        "Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.\n"
    ,
    .plugin.website = "http://deadbeef.sf.net",
    .open = wmaplug_open,
    .init = wmaplug_init,
    .free = wmaplug_free,
    .read = wmaplug_read,
    .seek = wmaplug_seek,
    .seek_sample = wmaplug_seek_sample,
    .insert = wmaplug_insert,
    .read_metadata = wmaplug_read_metadata,
    .exts = exts,
};

DB_plugin_t *
wma_load (DB_functions_t *api) {
    deadbeef = api;
    return DB_PLUGIN (&plugin);
}
