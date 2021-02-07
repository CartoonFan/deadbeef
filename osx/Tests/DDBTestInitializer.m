//
//  DDBTestInitializer.m
//  Tests
//
//  Created by Oleksiy Yakovenko on 19/06/2018.
//  Copyright © 2018 Alexey Yakovenko. All rights reserved.
//

#import "DDBTestInitializer.h"
#include "../../common.h"
#include "conf.h"
#include "logger.h"
#include "playlist.h"
#include "playmodes.h"
#include "plugins.h"
#include "vfs.h"

@implementation DDBTestInitializer
- (id)init {
    NSString *resPath = [NSBundle bundleForClass:self.class].resourcePath;
    const char *str = resPath.UTF8String;
    strcpy(dbplugindir, str);

    ddb_logger_init();
    conf_init();
    conf_enable_saving(0);
    streamer_playmodes_init();
    pl_init();

    if (plug_load_all()) { // required to add files to playlist from commandline
        exit(1);
    }

#if 0
    plug_disconnect_all ();
    plug_unload_all ();
    pl_free ();
    conf_free ();
    ddb_logger_free ();
#endif
    return self;
}
@end
