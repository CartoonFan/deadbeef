/* -----------------------------------------------------------------------------
Software License for The Fraunhofer FDK AAC Codec Library for Android

© Copyright  1995 - 2018 Fraunhofer-Gesellschaft zur Förderung der angewandten
Forschung e.V. All rights reserved.

 1.    INTRODUCTION
The Fraunhofer FDK AAC Codec Library for Android ("FDK AAC Codec") is software
that implements the MPEG Advanced Audio Coding ("AAC") encoding and decoding
scheme for digital audio. This FDK AAC Codec software is intended to be used on
a wide variety of Android devices.

AAC's HE-AAC and HE-AAC v2 versions are regarded as today's most efficient
general perceptual audio codecs. AAC-ELD is considered the best-performing
full-bandwidth communications codec by independent studies and is widely
deployed. AAC has been standardized by ISO and IEC as part of the MPEG
specifications.

Patent licenses for necessary patent claims for the FDK AAC Codec (including
those of Fraunhofer) may be obtained through Via Licensing
(www.vialicensing.com) or through the respective patent owners individually for
the purpose of encoding or decoding bit streams in products that are compliant
with the ISO/IEC MPEG audio standards. Please note that most manufacturers of
Android devices already license these patent claims through Via Licensing or
directly from the patent owners, and therefore FDK AAC Codec software may
already be covered under those patent licenses when it is used for those
licensed purposes only.

Commercially-licensed AAC software libraries, including floating-point versions
with enhanced sound quality, are also available from Fraunhofer. Users are
encouraged to check the Fraunhofer website for additional applications
information and documentation.

2.    COPYRIGHT LICENSE

Redistribution and use in source and binary forms, with or without modification,
are permitted without payment of copyright license fees provided that you
satisfy the following conditions:

You must retain the complete text of this software license in redistributions of
the FDK AAC Codec or your modifications thereto in source code form.

You must retain the complete text of this software license in the documentation
and/or other materials provided with redistributions of the FDK AAC Codec or
your modifications thereto in binary form. You must make available free of
charge copies of the complete source code of the FDK AAC Codec and your
modifications thereto to recipients of copies in binary form.

The name of Fraunhofer may not be used to endorse or promote products derived
from this library without prior written permission.

You may not charge copyright license fees for anyone to use, copy or distribute
the FDK AAC Codec software or your modifications thereto.

Your modified versions of the FDK AAC Codec must carry prominent notices stating
that you changed the software and the date of any change. For modified versions
of the FDK AAC Codec, the term "Fraunhofer FDK AAC Codec Library for Android"
must be replaced by the term "Third-Party Modified Version of the Fraunhofer FDK
AAC Codec Library for Android."

3.    NO PATENT LICENSE

NO EXPRESS OR IMPLIED LICENSES TO ANY PATENT CLAIMS, including without
limitation the patents of Fraunhofer, ARE GRANTED BY THIS SOFTWARE LICENSE.
Fraunhofer provides no warranty of patent non-infringement with respect to this
software.

You may use this FDK AAC Codec software or modifications thereto only for
purposes that are authorized by appropriate patent licenses.

4.    DISCLAIMER

This FDK AAC Codec software is provided by Fraunhofer on behalf of the copyright
holders and contributors "AS IS" and WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES,
including but not limited to the implied warranties of merchantability and
fitness for a particular purpose. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
CONTRIBUTORS BE LIABLE for any direct, indirect, incidental, special, exemplary,
or consequential damages, including but not limited to procurement of substitute
goods or services; loss of use, data, or profits, or business interruption,
however caused and on any theory of liability, whether in contract, strict
liability, or tort (including negligence), arising in any way out of the use of
this software, even if advised of the possibility of such damage.

5.    CONTACT INFORMATION

Fraunhofer Institute for Integrated Circuits IIS
Attention: Audio and Multimedia Departments - FDK AAC LL
Am Wolfsmantel 33
91058 Erlangen, Germany

www.iis.fraunhofer.de/amm
amm-info@iis.fraunhofer.de
----------------------------------------------------------------------------- */

/**************************** SBR decoder library ******************************

   Author(s):

   Description:

*******************************************************************************/

/*!
  \file
  \brief  Definition of constant tables

  This module contains most of the constant data that can be stored in ROM.
*/

#include "sbr_rom.h"

/*!
  \name   StartStopBands
  \brief  Start and stop subbands of the highband.

  k_o = startMin + offset[bs_start_freq];
  startMin = {3000,4000,5000} * (128/FS_sbr) / FS_sbr < 32Khz, 32Khz <= FS_sbr <
  64KHz, 64KHz <= FS_sbr The stop subband can also be calculated to save memory
  by defining #CALC_STOP_BAND.
*/
//@{
/* tables were created with ../addon/octave/sbr_start_freq_table.m */
const UCHAR FDK_sbrDecoder_sbr_start_freq_16[][16] = {
    {16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31},
    {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19}
};
const UCHAR FDK_sbrDecoder_sbr_start_freq_22[][16] = {
    {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 28, 30},
    {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 18, 20, 22}
};
const UCHAR FDK_sbrDecoder_sbr_start_freq_24[][16] = {
    {11, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 25, 27, 29, 32},
    {3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17, 19, 21, 24}
};
const UCHAR FDK_sbrDecoder_sbr_start_freq_32[][16] = {
    {10, 12, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 25, 27, 29, 32},
    {2, 4, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17, 19, 21, 24}
};
const UCHAR FDK_sbrDecoder_sbr_start_freq_40[][16] = {
    {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 26, 28, 30, 32},
    {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17, 19, 21, 23, 25}
};
const UCHAR FDK_sbrDecoder_sbr_start_freq_44[][16] = {
    {8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 25, 28, 32},
    {2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 17, 19, 22, 26}
};
const UCHAR FDK_sbrDecoder_sbr_start_freq_48[][16] = {
    {7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 22, 24, 27, 31},
    {1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16, 18, 21, 25}
};
const UCHAR FDK_sbrDecoder_sbr_start_freq_64[][16] = {
    {6, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19, 21, 23, 26, 30},
    {1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16, 18, 21, 25}
};
const UCHAR FDK_sbrDecoder_sbr_start_freq_88[][16] = {
    {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 18, 20, 23, 27, 31},
    {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 20, 24, 28}
};
const UCHAR FDK_sbrDecoder_sbr_start_freq_192[16] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 16, 19, 23, 27
};
const UCHAR FDK_sbrDecoder_sbr_start_freq_176[16] = {
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 20, 24, 28
};
const UCHAR FDK_sbrDecoder_sbr_start_freq_128[16] = {
    1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16, 18, 21, 25
};

//@}

/*!
  \name   Whitening
  \brief  Coefficients for spectral whitening in the transposer
*/
//@{
/*! Assignment of whitening tuning depending on the crossover frequency */
const USHORT FDK_sbrDecoder_sbr_whFactorsIndex[NUM_WHFACTOR_TABLE_ENTRIES] = {
    0, 5000, 6000, 6500, 7000, 7500, 8000, 9000, 10000
};

/*!
  \brief Whithening levels tuning table

  With the current tuning, there are some redundant entries:

  \li  NUM_WHFACTOR_TABLE_ENTRIES can be reduced by 3,
  \li  the first coloumn can be eliminated.

*/
const FIXP_DBL
FDK_sbrDecoder_sbr_whFactorsTable[NUM_WHFACTOR_TABLE_ENTRIES][6] = {
    /* OFF_LEVEL, TRANSITION_LEVEL, LOW_LEVEL, MID_LEVEL, HIGH_LEVEL */
    {   FL2FXCONST_DBL(0.00f), FL2FXCONST_DBL(0.6f), FL2FXCONST_DBL(0.75f),
        FL2FXCONST_DBL(0.90f), FL2FXCONST_DBL(0.98f)
    }, /* < 5000 */
    {   FL2FXCONST_DBL(0.00f), FL2FXCONST_DBL(0.6f), FL2FXCONST_DBL(0.75f),
        FL2FXCONST_DBL(0.90f), FL2FXCONST_DBL(0.98f)
    }, /* 5000 < 6000 */
    {   FL2FXCONST_DBL(0.00f), FL2FXCONST_DBL(0.6f), FL2FXCONST_DBL(0.75f),
        FL2FXCONST_DBL(0.90f), FL2FXCONST_DBL(0.98f)
    }, /* 6000 < 6500 */
    {   FL2FXCONST_DBL(0.00f), FL2FXCONST_DBL(0.6f), FL2FXCONST_DBL(0.75f),
        FL2FXCONST_DBL(0.90f), FL2FXCONST_DBL(0.98f)
    }, /* 6500 < 7000 */
    {   FL2FXCONST_DBL(0.00f), FL2FXCONST_DBL(0.6f), FL2FXCONST_DBL(0.75f),
        FL2FXCONST_DBL(0.90f), FL2FXCONST_DBL(0.98f)
    }, /* 7000 < 7500 */
    {   FL2FXCONST_DBL(0.00f), FL2FXCONST_DBL(0.6f), FL2FXCONST_DBL(0.75f),
        FL2FXCONST_DBL(0.90f), FL2FXCONST_DBL(0.98f)
    }, /* 7500 < 8000 */
    {   FL2FXCONST_DBL(0.00f), FL2FXCONST_DBL(0.6f), FL2FXCONST_DBL(0.75f),
        FL2FXCONST_DBL(0.90f), FL2FXCONST_DBL(0.98f)
    }, /* 8000 < 9000 */
    {   FL2FXCONST_DBL(0.00f), FL2FXCONST_DBL(0.6f), FL2FXCONST_DBL(0.75f),
        FL2FXCONST_DBL(0.90f), FL2FXCONST_DBL(0.98f)
    }, /* 9000 < 10000 */
    {   FL2FXCONST_DBL(0.00f), FL2FXCONST_DBL(0.6f), FL2FXCONST_DBL(0.75f),
        FL2FXCONST_DBL(0.90f), FL2FXCONST_DBL(0.98f)
    }, /* > 10000 */
};

//@}

/*!
  \name   EnvAdj
  \brief  Constants and tables used for envelope adjustment
*/
//@{

/*! Mantissas of gain limits */
const FIXP_SGL FDK_sbrDecoder_sbr_limGains_m[4] = {
    FL2FXCONST_SGL(0.5011932025f), /*!< -3 dB. Gain limit when limiterGains in
                                      frameData is 0 */
    FL2FXCONST_SGL(
        0.5f), /*!< 0 dB.  Gain limit when limiterGains in frameData is 1 */
    FL2FXCONST_SGL(0.9976346258f), /*!< +3 dB. Gain limit when limiterGains in
                                      frameData is 2 */
    FL2FXCONST_SGL(0.6776263578f)  /*!< Inf.   Gain limit when limiterGains in
                                      frameData is 3 */
};

/*! Exponents of gain limits */
const UCHAR FDK_sbrDecoder_sbr_limGains_e[4] = {0, 1, 1, 67};

/*! Constants for calculating the number of limiter bands */
const FIXP_SGL FDK_sbrDecoder_sbr_limiterBandsPerOctaveDiv4[4] = {
    FL2FXCONST_SGL(1.0f / 4.0f), FL2FXCONST_SGL(1.2f / 4.0f),
    FL2FXCONST_SGL(2.0f / 4.0f), FL2FXCONST_SGL(3.0f / 4.0f)
};

/*! Constants for calculating the number of limiter bands */
const FIXP_DBL FDK_sbrDecoder_sbr_limiterBandsPerOctaveDiv4_DBL[4] = {
    FL2FXCONST_DBL(1.0f / 4.0f), FL2FXCONST_DBL(1.2f / 4.0f),
    FL2FXCONST_DBL(2.0f / 4.0f), FL2FXCONST_DBL(3.0f / 4.0f)
};

/*! Ratio of old gains and noise levels for the first 4 timeslots of an envelope
 */
const FIXP_SGL FDK_sbrDecoder_sbr_smoothFilter[4] = {
    FL2FXCONST_SGL(0.66666666666666f), FL2FXCONST_SGL(0.36516383427084f),
    FL2FXCONST_SGL(0.14699433520835f), FL2FXCONST_SGL(0.03183050093751f)
};

/*! Real and imaginary part of random noise which will be modulated
  to the desired level. An accuracy of 13 bits is sufficient for these
  random numbers.
*/
const FIXP_SGL FDK_sbrDecoder_sbr_randomPhase[SBR_NF_NO_RANDOM_VAL][2] = {
    {   FL2FXCONST_SGL(-0.99948153278296f / 8.0),
        FL2FXCONST_SGL(-0.59483417516607f / 8.0)
    },
    {   FL2FXCONST_SGL(0.97113454393991f / 8.0),
        FL2FXCONST_SGL(-0.67528515225647f / 8.0)
    },
    {   FL2FXCONST_SGL(0.14130051758487f / 8.0),
        FL2FXCONST_SGL(-0.95090983575689f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.47005496701697f / 8.0),
        FL2FXCONST_SGL(-0.37340549728647f / 8.0)
    },
    {   FL2FXCONST_SGL(0.80705063769351f / 8.0),
        FL2FXCONST_SGL(0.29653668284408f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.38981478896926f / 8.0),
        FL2FXCONST_SGL(0.89572605717087f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.01053049862020f / 8.0),
        FL2FXCONST_SGL(-0.66959058036166f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.91266367957293f / 8.0),
        FL2FXCONST_SGL(-0.11522938140034f / 8.0)
    },
    {   FL2FXCONST_SGL(0.54840422910309f / 8.0),
        FL2FXCONST_SGL(0.75221367176302f / 8.0)
    },
    {   FL2FXCONST_SGL(0.40009252867955f / 8.0),
        FL2FXCONST_SGL(-0.98929400334421f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99867974711855f / 8.0),
        FL2FXCONST_SGL(-0.88147068645358f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.95531076805040f / 8.0),
        FL2FXCONST_SGL(0.90908757154593f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.45725933317144f / 8.0),
        FL2FXCONST_SGL(-0.56716323646760f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.72929675029275f / 8.0),
        FL2FXCONST_SGL(-0.98008272727324f / 8.0)
    },
    {   FL2FXCONST_SGL(0.75622801399036f / 8.0),
        FL2FXCONST_SGL(0.20950329995549f / 8.0)
    },
    {   FL2FXCONST_SGL(0.07069442601050f / 8.0),
        FL2FXCONST_SGL(-0.78247898470706f / 8.0)
    },
    {   FL2FXCONST_SGL(0.74496252926055f / 8.0),
        FL2FXCONST_SGL(-0.91169004445807f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.96440182703856f / 8.0),
        FL2FXCONST_SGL(-0.94739918296622f / 8.0)
    },
    {   FL2FXCONST_SGL(0.30424629369539f / 8.0),
        FL2FXCONST_SGL(-0.49438267012479f / 8.0)
    },
    {   FL2FXCONST_SGL(0.66565033746925f / 8.0),
        FL2FXCONST_SGL(0.64652935542491f / 8.0)
    },
    {   FL2FXCONST_SGL(0.91697008020594f / 8.0),
        FL2FXCONST_SGL(0.17514097332009f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.70774918760427f / 8.0),
        FL2FXCONST_SGL(0.52548653416543f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.70051415345560f / 8.0),
        FL2FXCONST_SGL(-0.45340028808763f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99496513054797f / 8.0),
        FL2FXCONST_SGL(-0.90071908066973f / 8.0)
    },
    {   FL2FXCONST_SGL(0.98164490790123f / 8.0),
        FL2FXCONST_SGL(-0.77463155528697f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.54671580548181f / 8.0),
        FL2FXCONST_SGL(-0.02570928536004f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.01689629065389f / 8.0),
        FL2FXCONST_SGL(0.00287506445732f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.86110349531986f / 8.0),
        FL2FXCONST_SGL(0.42548583726477f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.98892980586032f / 8.0),
        FL2FXCONST_SGL(-0.87881132267556f / 8.0)
    },
    {   FL2FXCONST_SGL(0.51756627678691f / 8.0),
        FL2FXCONST_SGL(0.66926784710139f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99635026409640f / 8.0),
        FL2FXCONST_SGL(-0.58107730574765f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99969370862163f / 8.0),
        FL2FXCONST_SGL(0.98369989360250f / 8.0)
    },
    {   FL2FXCONST_SGL(0.55266258627194f / 8.0),
        FL2FXCONST_SGL(0.59449057465591f / 8.0)
    },
    {   FL2FXCONST_SGL(0.34581177741673f / 8.0),
        FL2FXCONST_SGL(0.94879421061866f / 8.0)
    },
    {   FL2FXCONST_SGL(0.62664209577999f / 8.0),
        FL2FXCONST_SGL(-0.74402970906471f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.77149701404973f / 8.0),
        FL2FXCONST_SGL(-0.33883658042801f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.91592244254432f / 8.0),
        FL2FXCONST_SGL(0.03687901376713f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.76285492357887f / 8.0),
        FL2FXCONST_SGL(-0.91371867919124f / 8.0)
    },
    {   FL2FXCONST_SGL(0.79788337195331f / 8.0),
        FL2FXCONST_SGL(-0.93180971199849f / 8.0)
    },
    {   FL2FXCONST_SGL(0.54473080610200f / 8.0),
        FL2FXCONST_SGL(-0.11919206037186f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.85639281671058f / 8.0),
        FL2FXCONST_SGL(0.42429854760451f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.92882402971423f / 8.0),
        FL2FXCONST_SGL(0.27871809078609f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.11708371046774f / 8.0),
        FL2FXCONST_SGL(-0.99800843444966f / 8.0)
    },
    {   FL2FXCONST_SGL(0.21356749817493f / 8.0),
        FL2FXCONST_SGL(-0.90716295627033f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.76191692573909f / 8.0),
        FL2FXCONST_SGL(0.99768118356265f / 8.0)
    },
    {   FL2FXCONST_SGL(0.98111043100884f / 8.0),
        FL2FXCONST_SGL(-0.95854459734407f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.85913269895572f / 8.0),
        FL2FXCONST_SGL(0.95766566168880f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.93307242253692f / 8.0),
        FL2FXCONST_SGL(0.49431757696466f / 8.0)
    },
    {   FL2FXCONST_SGL(0.30485754879632f / 8.0),
        FL2FXCONST_SGL(-0.70540034357529f / 8.0)
    },
    {   FL2FXCONST_SGL(0.85289650925190f / 8.0),
        FL2FXCONST_SGL(0.46766131791044f / 8.0)
    },
    {   FL2FXCONST_SGL(0.91328082618125f / 8.0),
        FL2FXCONST_SGL(-0.99839597361769f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.05890199924154f / 8.0),
        FL2FXCONST_SGL(0.70741827819497f / 8.0)
    },
    {   FL2FXCONST_SGL(0.28398686150148f / 8.0),
        FL2FXCONST_SGL(0.34633555702188f / 8.0)
    },
    {   FL2FXCONST_SGL(0.95258164539612f / 8.0),
        FL2FXCONST_SGL(-0.54893416026939f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.78566324168507f / 8.0),
        FL2FXCONST_SGL(-0.75568541079691f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.95789495447877f / 8.0),
        FL2FXCONST_SGL(-0.20423194696966f / 8.0)
    },
    {   FL2FXCONST_SGL(0.82411158711197f / 8.0),
        FL2FXCONST_SGL(0.96654618432562f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.65185446735885f / 8.0),
        FL2FXCONST_SGL(-0.88734990773289f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.93643603134666f / 8.0),
        FL2FXCONST_SGL(0.99870790442385f / 8.0)
    },
    {   FL2FXCONST_SGL(0.91427159529618f / 8.0),
        FL2FXCONST_SGL(-0.98290505544444f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.70395684036886f / 8.0),
        FL2FXCONST_SGL(0.58796798221039f / 8.0)
    },
    {   FL2FXCONST_SGL(0.00563771969365f / 8.0),
        FL2FXCONST_SGL(0.61768196727244f / 8.0)
    },
    {   FL2FXCONST_SGL(0.89065051931895f / 8.0),
        FL2FXCONST_SGL(0.52783352697585f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.68683707712762f / 8.0),
        FL2FXCONST_SGL(0.80806944710339f / 8.0)
    },
    {   FL2FXCONST_SGL(0.72165342518718f / 8.0),
        FL2FXCONST_SGL(-0.69259857349564f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.62928247730667f / 8.0),
        FL2FXCONST_SGL(0.13627037407335f / 8.0)
    },
    {   FL2FXCONST_SGL(0.29938434065514f / 8.0),
        FL2FXCONST_SGL(-0.46051329682246f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.91781958879280f / 8.0),
        FL2FXCONST_SGL(-0.74012716684186f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99298717043688f / 8.0),
        FL2FXCONST_SGL(0.40816610075661f / 8.0)
    },
    {   FL2FXCONST_SGL(0.82368298622748f / 8.0),
        FL2FXCONST_SGL(-0.74036047190173f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.98512833386833f / 8.0),
        FL2FXCONST_SGL(-0.99972330709594f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.95915368242257f / 8.0),
        FL2FXCONST_SGL(-0.99237800466040f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.21411126572790f / 8.0),
        FL2FXCONST_SGL(-0.93424819052545f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.68821476106884f / 8.0),
        FL2FXCONST_SGL(-0.26892306315457f / 8.0)
    },
    {   FL2FXCONST_SGL(0.91851997982317f / 8.0),
        FL2FXCONST_SGL(0.09358228901785f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.96062769559127f / 8.0),
        FL2FXCONST_SGL(0.36099095133739f / 8.0)
    },
    {   FL2FXCONST_SGL(0.51646184922287f / 8.0),
        FL2FXCONST_SGL(-0.71373332873917f / 8.0)
    },
    {   FL2FXCONST_SGL(0.61130721139669f / 8.0),
        FL2FXCONST_SGL(0.46950141175917f / 8.0)
    },
    {   FL2FXCONST_SGL(0.47336129371299f / 8.0),
        FL2FXCONST_SGL(-0.27333178296162f / 8.0)
    },
    {   FL2FXCONST_SGL(0.90998308703519f / 8.0),
        FL2FXCONST_SGL(0.96715662938132f / 8.0)
    },
    {   FL2FXCONST_SGL(0.44844799194357f / 8.0),
        FL2FXCONST_SGL(0.99211574628306f / 8.0)
    },
    {   FL2FXCONST_SGL(0.66614891079092f / 8.0),
        FL2FXCONST_SGL(0.96590176169121f / 8.0)
    },
    {   FL2FXCONST_SGL(0.74922239129237f / 8.0),
        FL2FXCONST_SGL(-0.89879858826087f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99571588506485f / 8.0),
        FL2FXCONST_SGL(0.52785521494349f / 8.0)
    },
    {   FL2FXCONST_SGL(0.97401082477563f / 8.0),
        FL2FXCONST_SGL(-0.16855870075190f / 8.0)
    },
    {   FL2FXCONST_SGL(0.72683747733879f / 8.0),
        FL2FXCONST_SGL(-0.48060774432251f / 8.0)
    },
    {   FL2FXCONST_SGL(0.95432193457128f / 8.0),
        FL2FXCONST_SGL(0.68849603408441f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.72962208425191f / 8.0),
        FL2FXCONST_SGL(-0.76608443420917f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.85359479233537f / 8.0),
        FL2FXCONST_SGL(0.88738125901579f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.81412430338535f / 8.0),
        FL2FXCONST_SGL(-0.97480768049637f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.87930772356786f / 8.0),
        FL2FXCONST_SGL(0.74748307690436f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.71573331064977f / 8.0),
        FL2FXCONST_SGL(-0.98570608178923f / 8.0)
    },
    {   FL2FXCONST_SGL(0.83524300028228f / 8.0),
        FL2FXCONST_SGL(0.83702537075163f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.48086065601423f / 8.0),
        FL2FXCONST_SGL(-0.98848504923531f / 8.0)
    },
    {   FL2FXCONST_SGL(0.97139128574778f / 8.0),
        FL2FXCONST_SGL(0.80093621198236f / 8.0)
    },
    {   FL2FXCONST_SGL(0.51992825347895f / 8.0),
        FL2FXCONST_SGL(0.80247631400510f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.00848591195325f / 8.0),
        FL2FXCONST_SGL(-0.76670128000486f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.70294374303036f / 8.0),
        FL2FXCONST_SGL(0.55359910445577f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.95894428168140f / 8.0),
        FL2FXCONST_SGL(-0.43265504344783f / 8.0)
    },
    {   FL2FXCONST_SGL(0.97079252950321f / 8.0),
        FL2FXCONST_SGL(0.09325857238682f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.92404293670797f / 8.0),
        FL2FXCONST_SGL(0.85507704027855f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.69506469500450f / 8.0),
        FL2FXCONST_SGL(0.98633412625459f / 8.0)
    },
    {   FL2FXCONST_SGL(0.26559203620024f / 8.0),
        FL2FXCONST_SGL(0.73314307966524f / 8.0)
    },
    {   FL2FXCONST_SGL(0.28038443336943f / 8.0),
        FL2FXCONST_SGL(0.14537913654427f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.74138124825523f / 8.0),
        FL2FXCONST_SGL(0.99310339807762f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.01752795995444f / 8.0),
        FL2FXCONST_SGL(-0.82616635284178f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.55126773094930f / 8.0),
        FL2FXCONST_SGL(-0.98898543862153f / 8.0)
    },
    {   FL2FXCONST_SGL(0.97960898850996f / 8.0),
        FL2FXCONST_SGL(-0.94021446752851f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99196309146936f / 8.0),
        FL2FXCONST_SGL(0.67019017358456f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.67684928085260f / 8.0),
        FL2FXCONST_SGL(0.12631491649378f / 8.0)
    },
    {   FL2FXCONST_SGL(0.09140039465500f / 8.0),
        FL2FXCONST_SGL(-0.20537731453108f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.71658965751996f / 8.0),
        FL2FXCONST_SGL(-0.97788200391224f / 8.0)
    },
    {   FL2FXCONST_SGL(0.81014640078925f / 8.0),
        FL2FXCONST_SGL(0.53722648362443f / 8.0)
    },
    {   FL2FXCONST_SGL(0.40616991671205f / 8.0),
        FL2FXCONST_SGL(-0.26469008598449f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.67680188682972f / 8.0),
        FL2FXCONST_SGL(0.94502052337695f / 8.0)
    },
    {   FL2FXCONST_SGL(0.86849774348749f / 8.0),
        FL2FXCONST_SGL(-0.18333598647899f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99500381284851f / 8.0),
        FL2FXCONST_SGL(-0.02634122068550f / 8.0)
    },
    {   FL2FXCONST_SGL(0.84329189340667f / 8.0),
        FL2FXCONST_SGL(0.10406957462213f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.09215968531446f / 8.0),
        FL2FXCONST_SGL(0.69540012101253f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99956173327206f / 8.0),
        FL2FXCONST_SGL(-0.12358542001404f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.79732779473535f / 8.0),
        FL2FXCONST_SGL(-0.91582524736159f / 8.0)
    },
    {   FL2FXCONST_SGL(0.96349973642406f / 8.0),
        FL2FXCONST_SGL(0.96640458041000f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.79942778496547f / 8.0),
        FL2FXCONST_SGL(0.64323902822857f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.11566039853896f / 8.0),
        FL2FXCONST_SGL(0.28587846253726f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.39922954514662f / 8.0),
        FL2FXCONST_SGL(0.94129601616966f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99089197565987f / 8.0),
        FL2FXCONST_SGL(-0.92062625581587f / 8.0)
    },
    {   FL2FXCONST_SGL(0.28631285179909f / 8.0),
        FL2FXCONST_SGL(-0.91035047143603f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.83302725605608f / 8.0),
        FL2FXCONST_SGL(-0.67330410892084f / 8.0)
    },
    {   FL2FXCONST_SGL(0.95404443402072f / 8.0),
        FL2FXCONST_SGL(0.49162765398743f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.06449863579434f / 8.0),
        FL2FXCONST_SGL(0.03250560813135f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99575054486311f / 8.0),
        FL2FXCONST_SGL(0.42389784469507f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.65501142790847f / 8.0),
        FL2FXCONST_SGL(0.82546114655624f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.81254441908887f / 8.0),
        FL2FXCONST_SGL(-0.51627234660629f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99646369485481f / 8.0),
        FL2FXCONST_SGL(0.84490533520752f / 8.0)
    },
    {   FL2FXCONST_SGL(0.00287840603348f / 8.0),
        FL2FXCONST_SGL(0.64768261158166f / 8.0)
    },
    {   FL2FXCONST_SGL(0.70176989408455f / 8.0),
        FL2FXCONST_SGL(-0.20453028573322f / 8.0)
    },
    {   FL2FXCONST_SGL(0.96361882270190f / 8.0),
        FL2FXCONST_SGL(0.40706967140989f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.68883758192426f / 8.0),
        FL2FXCONST_SGL(0.91338958840772f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.34875585502238f / 8.0),
        FL2FXCONST_SGL(0.71472290693300f / 8.0)
    },
    {   FL2FXCONST_SGL(0.91980081243087f / 8.0),
        FL2FXCONST_SGL(0.66507455644919f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99009048343881f / 8.0),
        FL2FXCONST_SGL(0.85868021604848f / 8.0)
    },
    {   FL2FXCONST_SGL(0.68865791458395f / 8.0),
        FL2FXCONST_SGL(0.55660316809678f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99484402129368f / 8.0),
        FL2FXCONST_SGL(-0.20052559254934f / 8.0)
    },
    {   FL2FXCONST_SGL(0.94214511408023f / 8.0),
        FL2FXCONST_SGL(-0.99696425367461f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.67414626793544f / 8.0),
        FL2FXCONST_SGL(0.49548221180078f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.47339353684664f / 8.0),
        FL2FXCONST_SGL(-0.85904328834047f / 8.0)
    },
    {   FL2FXCONST_SGL(0.14323651387360f / 8.0),
        FL2FXCONST_SGL(-0.94145598222488f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.29268293575672f / 8.0),
        FL2FXCONST_SGL(0.05759224927952f / 8.0)
    },
    {   FL2FXCONST_SGL(0.43793861458754f / 8.0),
        FL2FXCONST_SGL(-0.78904969892724f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.36345126374441f / 8.0),
        FL2FXCONST_SGL(0.64874435357162f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.08750604656825f / 8.0),
        FL2FXCONST_SGL(0.97686944362527f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.96495267812511f / 8.0),
        FL2FXCONST_SGL(-0.53960305946511f / 8.0)
    },
    {   FL2FXCONST_SGL(0.55526940659947f / 8.0),
        FL2FXCONST_SGL(0.78891523734774f / 8.0)
    },
    {   FL2FXCONST_SGL(0.73538215752630f / 8.0),
        FL2FXCONST_SGL(0.96452072373404f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.30889773919437f / 8.0),
        FL2FXCONST_SGL(-0.80664389776860f / 8.0)
    },
    {   FL2FXCONST_SGL(0.03574995626194f / 8.0),
        FL2FXCONST_SGL(-0.97325616900959f / 8.0)
    },
    {   FL2FXCONST_SGL(0.98720684660488f / 8.0),
        FL2FXCONST_SGL(0.48409133691962f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.81689296271203f / 8.0),
        FL2FXCONST_SGL(-0.90827703628298f / 8.0)
    },
    {   FL2FXCONST_SGL(0.67866860118215f / 8.0),
        FL2FXCONST_SGL(0.81284503870856f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.15808569732583f / 8.0),
        FL2FXCONST_SGL(0.85279555024382f / 8.0)
    },
    {   FL2FXCONST_SGL(0.80723395114371f / 8.0),
        FL2FXCONST_SGL(-0.24717418514605f / 8.0)
    },
    {   FL2FXCONST_SGL(0.47788757329038f / 8.0),
        FL2FXCONST_SGL(-0.46333147839295f / 8.0)
    },
    {   FL2FXCONST_SGL(0.96367554763201f / 8.0),
        FL2FXCONST_SGL(0.38486749303242f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99143875716818f / 8.0),
        FL2FXCONST_SGL(-0.24945277239809f / 8.0)
    },
    {   FL2FXCONST_SGL(0.83081876925833f / 8.0),
        FL2FXCONST_SGL(-0.94780851414763f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.58753191905341f / 8.0),
        FL2FXCONST_SGL(0.01290772389163f / 8.0)
    },
    {   FL2FXCONST_SGL(0.95538108220960f / 8.0),
        FL2FXCONST_SGL(-0.85557052096538f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.96490920476211f / 8.0),
        FL2FXCONST_SGL(-0.64020970923102f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.97327101028521f / 8.0),
        FL2FXCONST_SGL(0.12378128133110f / 8.0)
    },
    {   FL2FXCONST_SGL(0.91400366022124f / 8.0),
        FL2FXCONST_SGL(0.57972471346930f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99925837363824f / 8.0),
        FL2FXCONST_SGL(0.71084847864067f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.86875903507313f / 8.0),
        FL2FXCONST_SGL(-0.20291699203564f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.26240034795124f / 8.0),
        FL2FXCONST_SGL(-0.68264554369108f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.24664412953388f / 8.0),
        FL2FXCONST_SGL(-0.87642273115183f / 8.0)
    },
    {   FL2FXCONST_SGL(0.02416275806869f / 8.0),
        FL2FXCONST_SGL(0.27192914288905f / 8.0)
    },
    {   FL2FXCONST_SGL(0.82068619590515f / 8.0),
        FL2FXCONST_SGL(-0.85087787994476f / 8.0)
    },
    {   FL2FXCONST_SGL(0.88547373760759f / 8.0),
        FL2FXCONST_SGL(-0.89636802901469f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.18173078152226f / 8.0),
        FL2FXCONST_SGL(-0.26152145156800f / 8.0)
    },
    {   FL2FXCONST_SGL(0.09355476558534f / 8.0),
        FL2FXCONST_SGL(0.54845123045604f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.54668414224090f / 8.0),
        FL2FXCONST_SGL(0.95980774020221f / 8.0)
    },
    {   FL2FXCONST_SGL(0.37050990604091f / 8.0),
        FL2FXCONST_SGL(-0.59910140383171f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.70373594262891f / 8.0),
        FL2FXCONST_SGL(0.91227665827081f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.34600785879594f / 8.0),
        FL2FXCONST_SGL(-0.99441426144200f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.68774481731008f / 8.0),
        FL2FXCONST_SGL(-0.30238837956299f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.26843291251234f / 8.0),
        FL2FXCONST_SGL(0.83115668004362f / 8.0)
    },
    {   FL2FXCONST_SGL(0.49072334613242f / 8.0),
        FL2FXCONST_SGL(-0.45359708737775f / 8.0)
    },
    {   FL2FXCONST_SGL(0.38975993093975f / 8.0),
        FL2FXCONST_SGL(0.95515358099121f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.97757125224150f / 8.0),
        FL2FXCONST_SGL(0.05305894580606f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.17325552859616f / 8.0),
        FL2FXCONST_SGL(-0.92770672250494f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99948035025744f / 8.0),
        FL2FXCONST_SGL(0.58285545563426f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.64946246527458f / 8.0),
        FL2FXCONST_SGL(0.68645507104960f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.12016920576437f / 8.0),
        FL2FXCONST_SGL(-0.57147322153312f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.58947456517751f / 8.0),
        FL2FXCONST_SGL(-0.34847132454388f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.41815140454465f / 8.0),
        FL2FXCONST_SGL(0.16276422358861f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99885650204884f / 8.0),
        FL2FXCONST_SGL(0.11136095490444f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.56649614128386f / 8.0),
        FL2FXCONST_SGL(-0.90494866361587f / 8.0)
    },
    {   FL2FXCONST_SGL(0.94138021032330f / 8.0),
        FL2FXCONST_SGL(0.35281916733018f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.75725076534641f / 8.0),
        FL2FXCONST_SGL(0.53650549640587f / 8.0)
    },
    {   FL2FXCONST_SGL(0.20541973692630f / 8.0),
        FL2FXCONST_SGL(-0.94435144369918f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99980371023351f / 8.0),
        FL2FXCONST_SGL(0.79835913565599f / 8.0)
    },
    {   FL2FXCONST_SGL(0.29078277605775f / 8.0),
        FL2FXCONST_SGL(0.35393777921520f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.62858772103030f / 8.0),
        FL2FXCONST_SGL(0.38765693387102f / 8.0)
    },
    {   FL2FXCONST_SGL(0.43440904467688f / 8.0),
        FL2FXCONST_SGL(-0.98546330463232f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.98298583762390f / 8.0),
        FL2FXCONST_SGL(0.21021524625209f / 8.0)
    },
    {   FL2FXCONST_SGL(0.19513029146934f / 8.0),
        FL2FXCONST_SGL(-0.94239832251867f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.95476662400101f / 8.0),
        FL2FXCONST_SGL(0.98364554179143f / 8.0)
    },
    {   FL2FXCONST_SGL(0.93379635304810f / 8.0),
        FL2FXCONST_SGL(-0.70881994583682f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.85235410573336f / 8.0),
        FL2FXCONST_SGL(-0.08342347966410f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.86425093011245f / 8.0),
        FL2FXCONST_SGL(-0.45795025029466f / 8.0)
    },
    {   FL2FXCONST_SGL(0.38879779059045f / 8.0),
        FL2FXCONST_SGL(0.97274429344593f / 8.0)
    },
    {   FL2FXCONST_SGL(0.92045124735495f / 8.0),
        FL2FXCONST_SGL(-0.62433652524220f / 8.0)
    },
    {   FL2FXCONST_SGL(0.89162532251878f / 8.0),
        FL2FXCONST_SGL(0.54950955570563f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.36834336949252f / 8.0),
        FL2FXCONST_SGL(0.96458298020975f / 8.0)
    },
    {   FL2FXCONST_SGL(0.93891760988045f / 8.0),
        FL2FXCONST_SGL(-0.89968353740388f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99267657565094f / 8.0),
        FL2FXCONST_SGL(-0.03757034316958f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.94063471614176f / 8.0),
        FL2FXCONST_SGL(0.41332338538963f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99740224117019f / 8.0),
        FL2FXCONST_SGL(-0.16830494996370f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.35899413170555f / 8.0),
        FL2FXCONST_SGL(-0.46633226649613f / 8.0)
    },
    {   FL2FXCONST_SGL(0.05237237274947f / 8.0),
        FL2FXCONST_SGL(-0.25640361602661f / 8.0)
    },
    {   FL2FXCONST_SGL(0.36703583957424f / 8.0),
        FL2FXCONST_SGL(-0.38653265641875f / 8.0)
    },
    {   FL2FXCONST_SGL(0.91653180367913f / 8.0),
        FL2FXCONST_SGL(-0.30587628726597f / 8.0)
    },
    {   FL2FXCONST_SGL(0.69000803499316f / 8.0),
        FL2FXCONST_SGL(0.90952171386132f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.38658751133527f / 8.0),
        FL2FXCONST_SGL(0.99501571208985f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.29250814029851f / 8.0),
        FL2FXCONST_SGL(0.37444994344615f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.60182204677608f / 8.0),
        FL2FXCONST_SGL(0.86779651036123f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.97418588163217f / 8.0),
        FL2FXCONST_SGL(0.96468523666475f / 8.0)
    },
    {   FL2FXCONST_SGL(0.88461574003963f / 8.0),
        FL2FXCONST_SGL(0.57508405276414f / 8.0)
    },
    {   FL2FXCONST_SGL(0.05198933055162f / 8.0),
        FL2FXCONST_SGL(0.21269661669964f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.53499621979720f / 8.0),
        FL2FXCONST_SGL(0.97241553731237f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.49429560226497f / 8.0),
        FL2FXCONST_SGL(0.98183865291903f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.98935142339139f / 8.0),
        FL2FXCONST_SGL(-0.40249159006933f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.98081380091130f / 8.0),
        FL2FXCONST_SGL(-0.72856895534041f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.27338148835532f / 8.0),
        FL2FXCONST_SGL(0.99950922447209f / 8.0)
    },
    {   FL2FXCONST_SGL(0.06310802338302f / 8.0),
        FL2FXCONST_SGL(-0.54539587529618f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.20461677199539f / 8.0),
        FL2FXCONST_SGL(-0.14209977628489f / 8.0)
    },
    {   FL2FXCONST_SGL(0.66223843141647f / 8.0),
        FL2FXCONST_SGL(0.72528579940326f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.84764345483665f / 8.0),
        FL2FXCONST_SGL(0.02372316801261f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.89039863483811f / 8.0),
        FL2FXCONST_SGL(0.88866581484602f / 8.0)
    },
    {   FL2FXCONST_SGL(0.95903308477986f / 8.0),
        FL2FXCONST_SGL(0.76744927173873f / 8.0)
    },
    {   FL2FXCONST_SGL(0.73504123909879f / 8.0),
        FL2FXCONST_SGL(-0.03747203173192f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.31744434966056f / 8.0),
        FL2FXCONST_SGL(-0.36834111883652f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.34110827591623f / 8.0),
        FL2FXCONST_SGL(0.40211222807691f / 8.0)
    },
    {   FL2FXCONST_SGL(0.47803883714199f / 8.0),
        FL2FXCONST_SGL(-0.39423219786288f / 8.0)
    },
    {   FL2FXCONST_SGL(0.98299195879514f / 8.0),
        FL2FXCONST_SGL(0.01989791390047f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.30963073129751f / 8.0),
        FL2FXCONST_SGL(-0.18076720599336f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99992588229018f / 8.0),
        FL2FXCONST_SGL(-0.26281872094289f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.93149731080767f / 8.0),
        FL2FXCONST_SGL(-0.98313162570490f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99923472302773f / 8.0),
        FL2FXCONST_SGL(-0.80142993767554f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.26024169633417f / 8.0),
        FL2FXCONST_SGL(-0.75999759855752f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.35712514743563f / 8.0),
        FL2FXCONST_SGL(0.19298963768574f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99899084509530f / 8.0),
        FL2FXCONST_SGL(0.74645156992493f / 8.0)
    },
    {   FL2FXCONST_SGL(0.86557171579452f / 8.0),
        FL2FXCONST_SGL(0.55593866696299f / 8.0)
    },
    {   FL2FXCONST_SGL(0.33408042438752f / 8.0),
        FL2FXCONST_SGL(0.86185953874709f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99010736374716f / 8.0),
        FL2FXCONST_SGL(0.04602397576623f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.66694269691195f / 8.0),
        FL2FXCONST_SGL(-0.91643611810148f / 8.0)
    },
    {   FL2FXCONST_SGL(0.64016792079480f / 8.0),
        FL2FXCONST_SGL(0.15649530836856f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99570534804836f / 8.0),
        FL2FXCONST_SGL(0.45844586038111f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.63431466947340f / 8.0),
        FL2FXCONST_SGL(0.21079116459234f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.07706847005931f / 8.0),
        FL2FXCONST_SGL(-0.89581437101329f / 8.0)
    },
    {   FL2FXCONST_SGL(0.98590090577724f / 8.0),
        FL2FXCONST_SGL(0.88241721133981f / 8.0)
    },
    {   FL2FXCONST_SGL(0.80099335254678f / 8.0),
        FL2FXCONST_SGL(-0.36851896710853f / 8.0)
    },
    {   FL2FXCONST_SGL(0.78368131392666f / 8.0),
        FL2FXCONST_SGL(0.45506999802597f / 8.0)
    },
    {   FL2FXCONST_SGL(0.08707806671691f / 8.0),
        FL2FXCONST_SGL(0.80938994918745f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.86811883080712f / 8.0),
        FL2FXCONST_SGL(0.39347308654705f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.39466529740375f / 8.0),
        FL2FXCONST_SGL(-0.66809432114456f / 8.0)
    },
    {   FL2FXCONST_SGL(0.97875325649683f / 8.0),
        FL2FXCONST_SGL(-0.72467840967746f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.95038560288864f / 8.0),
        FL2FXCONST_SGL(0.89563219587625f / 8.0)
    },
    {   FL2FXCONST_SGL(0.17005239424212f / 8.0),
        FL2FXCONST_SGL(0.54683053962658f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.76910792026848f / 8.0),
        FL2FXCONST_SGL(-0.96226617549298f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99743281016846f / 8.0),
        FL2FXCONST_SGL(0.42697157037567f / 8.0)
    },
    {   FL2FXCONST_SGL(0.95437383549973f / 8.0),
        FL2FXCONST_SGL(0.97002324109952f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99578905365569f / 8.0),
        FL2FXCONST_SGL(-0.54106826257356f / 8.0)
    },
    {   FL2FXCONST_SGL(0.28058259829990f / 8.0),
        FL2FXCONST_SGL(-0.85361420634036f / 8.0)
    },
    {   FL2FXCONST_SGL(0.85256524470573f / 8.0),
        FL2FXCONST_SGL(-0.64567607735589f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.50608540105128f / 8.0),
        FL2FXCONST_SGL(-0.65846015480300f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.97210735183243f / 8.0),
        FL2FXCONST_SGL(-0.23095213067791f / 8.0)
    },
    {   FL2FXCONST_SGL(0.95424048234441f / 8.0),
        FL2FXCONST_SGL(-0.99240147091219f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.96926570524023f / 8.0),
        FL2FXCONST_SGL(0.73775654896574f / 8.0)
    },
    {   FL2FXCONST_SGL(0.30872163214726f / 8.0),
        FL2FXCONST_SGL(0.41514960556126f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.24523839572639f / 8.0),
        FL2FXCONST_SGL(0.63206633394807f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.33813265086024f / 8.0),
        FL2FXCONST_SGL(-0.38661779441897f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.05826828420146f / 8.0),
        FL2FXCONST_SGL(-0.06940774188029f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.22898461455054f / 8.0),
        FL2FXCONST_SGL(0.97054853316316f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.18509915019881f / 8.0),
        FL2FXCONST_SGL(0.47565762892084f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.10488238045009f / 8.0),
        FL2FXCONST_SGL(-0.87769947402394f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.71886586182037f / 8.0),
        FL2FXCONST_SGL(0.78030982480538f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99793873738654f / 8.0),
        FL2FXCONST_SGL(0.90041310491497f / 8.0)
    },
    {   FL2FXCONST_SGL(0.57563307626120f / 8.0),
        FL2FXCONST_SGL(-0.91034337352097f / 8.0)
    },
    {   FL2FXCONST_SGL(0.28909646383717f / 8.0),
        FL2FXCONST_SGL(0.96307783970534f / 8.0)
    },
    {   FL2FXCONST_SGL(0.42188998312520f / 8.0),
        FL2FXCONST_SGL(0.48148651230437f / 8.0)
    },
    {   FL2FXCONST_SGL(0.93335049681047f / 8.0),
        FL2FXCONST_SGL(-0.43537023883588f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.97087374418267f / 8.0),
        FL2FXCONST_SGL(0.86636445711364f / 8.0)
    },
    {   FL2FXCONST_SGL(0.36722871286923f / 8.0),
        FL2FXCONST_SGL(0.65291654172961f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.81093025665696f / 8.0),
        FL2FXCONST_SGL(0.08778370229363f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.26240603062237f / 8.0),
        FL2FXCONST_SGL(-0.92774095379098f / 8.0)
    },
    {   FL2FXCONST_SGL(0.83996497984604f / 8.0),
        FL2FXCONST_SGL(0.55839849139647f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99909615720225f / 8.0),
        FL2FXCONST_SGL(-0.96024605713970f / 8.0)
    },
    {   FL2FXCONST_SGL(0.74649464155061f / 8.0),
        FL2FXCONST_SGL(0.12144893606462f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.74774595569805f / 8.0),
        FL2FXCONST_SGL(-0.26898062008959f / 8.0)
    },
    {   FL2FXCONST_SGL(0.95781667469567f / 8.0),
        FL2FXCONST_SGL(-0.79047927052628f / 8.0)
    },
    {   FL2FXCONST_SGL(0.95472308713099f / 8.0),
        FL2FXCONST_SGL(-0.08588776019550f / 8.0)
    },
    {   FL2FXCONST_SGL(0.48708332746299f / 8.0),
        FL2FXCONST_SGL(0.99999041579432f / 8.0)
    },
    {   FL2FXCONST_SGL(0.46332038247497f / 8.0),
        FL2FXCONST_SGL(0.10964126185063f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.76497004940162f / 8.0),
        FL2FXCONST_SGL(0.89210929242238f / 8.0)
    },
    {   FL2FXCONST_SGL(0.57397389364339f / 8.0),
        FL2FXCONST_SGL(0.35289703373760f / 8.0)
    },
    {   FL2FXCONST_SGL(0.75374316974495f / 8.0),
        FL2FXCONST_SGL(0.96705214651335f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.59174397685714f / 8.0),
        FL2FXCONST_SGL(-0.89405370422752f / 8.0)
    },
    {   FL2FXCONST_SGL(0.75087906691890f / 8.0),
        FL2FXCONST_SGL(-0.29612672982396f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.98607857336230f / 8.0),
        FL2FXCONST_SGL(0.25034911730023f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.40761056640505f / 8.0),
        FL2FXCONST_SGL(-0.90045573444695f / 8.0)
    },
    {   FL2FXCONST_SGL(0.66929266740477f / 8.0),
        FL2FXCONST_SGL(0.98629493401748f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.97463695257310f / 8.0),
        FL2FXCONST_SGL(-0.00190223301301f / 8.0)
    },
    {   FL2FXCONST_SGL(0.90145509409859f / 8.0),
        FL2FXCONST_SGL(0.99781390365446f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.87259289048043f / 8.0),
        FL2FXCONST_SGL(0.99233587353666f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.91529461447692f / 8.0),
        FL2FXCONST_SGL(-0.15698707534206f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.03305738840705f / 8.0),
        FL2FXCONST_SGL(-0.37205262859764f / 8.0)
    },
    {   FL2FXCONST_SGL(0.07223051368337f / 8.0),
        FL2FXCONST_SGL(-0.88805001733626f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99498012188353f / 8.0),
        FL2FXCONST_SGL(0.97094358113387f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.74904939500519f / 8.0),
        FL2FXCONST_SGL(0.99985483641521f / 8.0)
    },
    {   FL2FXCONST_SGL(0.04585228574211f / 8.0),
        FL2FXCONST_SGL(0.99812337444082f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.89054954257993f / 8.0),
        FL2FXCONST_SGL(-0.31791913188064f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.83782144651251f / 8.0),
        FL2FXCONST_SGL(0.97637632547466f / 8.0)
    },
    {   FL2FXCONST_SGL(0.33454804933804f / 8.0),
        FL2FXCONST_SGL(-0.86231516800408f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99707579362824f / 8.0),
        FL2FXCONST_SGL(0.93237990079441f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.22827527843994f / 8.0),
        FL2FXCONST_SGL(0.18874759397997f / 8.0)
    },
    {   FL2FXCONST_SGL(0.67248046289143f / 8.0),
        FL2FXCONST_SGL(-0.03646211390569f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.05146538187944f / 8.0),
        FL2FXCONST_SGL(-0.92599700120679f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99947295749905f / 8.0),
        FL2FXCONST_SGL(0.93625229707912f / 8.0)
    },
    {   FL2FXCONST_SGL(0.66951124390363f / 8.0),
        FL2FXCONST_SGL(0.98905825623893f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99602956559179f / 8.0),
        FL2FXCONST_SGL(-0.44654715757688f / 8.0)
    },
    {   FL2FXCONST_SGL(0.82104905483590f / 8.0),
        FL2FXCONST_SGL(0.99540741724928f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99186510988782f / 8.0),
        FL2FXCONST_SGL(0.72023001312947f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.65284592392918f / 8.0),
        FL2FXCONST_SGL(0.52186723253637f / 8.0)
    },
    {   FL2FXCONST_SGL(0.93885443798188f / 8.0),
        FL2FXCONST_SGL(-0.74895312615259f / 8.0)
    },
    {   FL2FXCONST_SGL(0.96735248738388f / 8.0),
        FL2FXCONST_SGL(0.90891816978629f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.22225968841114f / 8.0),
        FL2FXCONST_SGL(0.57124029781228f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.44132783753414f / 8.0),
        FL2FXCONST_SGL(-0.92688840659280f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.85694974219574f / 8.0),
        FL2FXCONST_SGL(0.88844532719844f / 8.0)
    },
    {   FL2FXCONST_SGL(0.91783042091762f / 8.0),
        FL2FXCONST_SGL(-0.46356892383970f / 8.0)
    },
    {   FL2FXCONST_SGL(0.72556974415690f / 8.0),
        FL2FXCONST_SGL(-0.99899555770747f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99711581834508f / 8.0),
        FL2FXCONST_SGL(0.58211560180426f / 8.0)
    },
    {   FL2FXCONST_SGL(0.77638976371966f / 8.0),
        FL2FXCONST_SGL(0.94321834873819f / 8.0)
    },
    {   FL2FXCONST_SGL(0.07717324253925f / 8.0),
        FL2FXCONST_SGL(0.58638399856595f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.56049829194163f / 8.0),
        FL2FXCONST_SGL(0.82522301569036f / 8.0)
    },
    {   FL2FXCONST_SGL(0.98398893639988f / 8.0),
        FL2FXCONST_SGL(0.39467440420569f / 8.0)
    },
    {   FL2FXCONST_SGL(0.47546946844938f / 8.0),
        FL2FXCONST_SGL(0.68613044836811f / 8.0)
    },
    {   FL2FXCONST_SGL(0.65675089314631f / 8.0),
        FL2FXCONST_SGL(0.18331637134880f / 8.0)
    },
    {   FL2FXCONST_SGL(0.03273375457980f / 8.0),
        FL2FXCONST_SGL(-0.74933109564108f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.38684144784738f / 8.0),
        FL2FXCONST_SGL(0.51337349030406f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.97346267944545f / 8.0),
        FL2FXCONST_SGL(-0.96549364384098f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.53282156061942f / 8.0),
        FL2FXCONST_SGL(-0.91423265091354f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99817310731176f / 8.0),
        FL2FXCONST_SGL(0.61133572482148f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.50254500772635f / 8.0),
        FL2FXCONST_SGL(-0.88829338134294f / 8.0)
    },
    {   FL2FXCONST_SGL(0.01995873238855f / 8.0),
        FL2FXCONST_SGL(0.85223515096765f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99930381973804f / 8.0),
        FL2FXCONST_SGL(0.94578896296649f / 8.0)
    },
    {   FL2FXCONST_SGL(0.82907767600783f / 8.0),
        FL2FXCONST_SGL(-0.06323442598128f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.58660709669728f / 8.0),
        FL2FXCONST_SGL(0.96840773806582f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.17573736667267f / 8.0),
        FL2FXCONST_SGL(-0.48166920859485f / 8.0)
    },
    {   FL2FXCONST_SGL(0.83434292401346f / 8.0),
        FL2FXCONST_SGL(-0.13023450646997f / 8.0)
    },
    {   FL2FXCONST_SGL(0.05946491307025f / 8.0),
        FL2FXCONST_SGL(0.20511047074866f / 8.0)
    },
    {   FL2FXCONST_SGL(0.81505484574602f / 8.0),
        FL2FXCONST_SGL(-0.94685947861369f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.44976380954860f / 8.0),
        FL2FXCONST_SGL(0.40894572671545f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.89746474625671f / 8.0),
        FL2FXCONST_SGL(0.99846578838537f / 8.0)
    },
    {   FL2FXCONST_SGL(0.39677256130792f / 8.0),
        FL2FXCONST_SGL(-0.74854668609359f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.07588948563079f / 8.0),
        FL2FXCONST_SGL(0.74096214084170f / 8.0)
    },
    {   FL2FXCONST_SGL(0.76343198951445f / 8.0),
        FL2FXCONST_SGL(0.41746629422634f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.74490104699626f / 8.0),
        FL2FXCONST_SGL(0.94725911744610f / 8.0)
    },
    {   FL2FXCONST_SGL(0.64880119792759f / 8.0),
        FL2FXCONST_SGL(0.41336660830571f / 8.0)
    },
    {   FL2FXCONST_SGL(0.62319537462542f / 8.0),
        FL2FXCONST_SGL(-0.93098313552599f / 8.0)
    },
    {   FL2FXCONST_SGL(0.42215817594807f / 8.0),
        FL2FXCONST_SGL(-0.07712787385208f / 8.0)
    },
    {   FL2FXCONST_SGL(0.02704554141885f / 8.0),
        FL2FXCONST_SGL(-0.05417518053666f / 8.0)
    },
    {   FL2FXCONST_SGL(0.80001773566818f / 8.0),
        FL2FXCONST_SGL(0.91542195141039f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.79351832348816f / 8.0),
        FL2FXCONST_SGL(-0.36208897989136f / 8.0)
    },
    {   FL2FXCONST_SGL(0.63872359151636f / 8.0),
        FL2FXCONST_SGL(0.08128252493444f / 8.0)
    },
    {   FL2FXCONST_SGL(0.52890520960295f / 8.0),
        FL2FXCONST_SGL(0.60048872455592f / 8.0)
    },
    {   FL2FXCONST_SGL(0.74238552914587f / 8.0),
        FL2FXCONST_SGL(0.04491915291044f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99096131449250f / 8.0),
        FL2FXCONST_SGL(-0.19451182854402f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.80412329643109f / 8.0),
        FL2FXCONST_SGL(-0.88513818199457f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.64612616129736f / 8.0),
        FL2FXCONST_SGL(0.72198674804544f / 8.0)
    },
    {   FL2FXCONST_SGL(0.11657770663191f / 8.0),
        FL2FXCONST_SGL(-0.83662833815041f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.95053182488101f / 8.0),
        FL2FXCONST_SGL(-0.96939905138082f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.62228872928622f / 8.0),
        FL2FXCONST_SGL(0.82767262846661f / 8.0)
    },
    {   FL2FXCONST_SGL(0.03004475787316f / 8.0),
        FL2FXCONST_SGL(-0.99738896333384f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.97987214341034f / 8.0),
        FL2FXCONST_SGL(0.36526129686425f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99986980746200f / 8.0),
        FL2FXCONST_SGL(-0.36021610299715f / 8.0)
    },
    {   FL2FXCONST_SGL(0.89110648599879f / 8.0),
        FL2FXCONST_SGL(-0.97894250343044f / 8.0)
    },
    {   FL2FXCONST_SGL(0.10407960510582f / 8.0),
        FL2FXCONST_SGL(0.77357793811619f / 8.0)
    },
    {   FL2FXCONST_SGL(0.95964737821728f / 8.0),
        FL2FXCONST_SGL(-0.35435818285502f / 8.0)
    },
    {   FL2FXCONST_SGL(0.50843233159162f / 8.0),
        FL2FXCONST_SGL(0.96107691266205f / 8.0)
    },
    {   FL2FXCONST_SGL(0.17006334670615f / 8.0),
        FL2FXCONST_SGL(-0.76854025314829f / 8.0)
    },
    {   FL2FXCONST_SGL(0.25872675063360f / 8.0),
        FL2FXCONST_SGL(0.99893303933816f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.01115998681937f / 8.0),
        FL2FXCONST_SGL(0.98496019742444f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.79598702973261f / 8.0),
        FL2FXCONST_SGL(0.97138411318894f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99264708948101f / 8.0),
        FL2FXCONST_SGL(-0.99542822402536f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99829663752818f / 8.0),
        FL2FXCONST_SGL(0.01877138824311f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.70801016548184f / 8.0),
        FL2FXCONST_SGL(0.33680685948117f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.70467057786826f / 8.0),
        FL2FXCONST_SGL(0.93272777501857f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99846021905254f / 8.0),
        FL2FXCONST_SGL(-0.98725746254433f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.63364968534650f / 8.0),
        FL2FXCONST_SGL(-0.16473594423746f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.16258217500792f / 8.0),
        FL2FXCONST_SGL(-0.95939125400802f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.43645594360633f / 8.0),
        FL2FXCONST_SGL(-0.94805030113284f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99848471702976f / 8.0),
        FL2FXCONST_SGL(0.96245166923809f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.16796458968998f / 8.0),
        FL2FXCONST_SGL(-0.98987511890470f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.87979225745213f / 8.0),
        FL2FXCONST_SGL(-0.71725725041680f / 8.0)
    },
    {   FL2FXCONST_SGL(0.44183099021786f / 8.0),
        FL2FXCONST_SGL(-0.93568974498761f / 8.0)
    },
    {   FL2FXCONST_SGL(0.93310180125532f / 8.0),
        FL2FXCONST_SGL(-0.99913308068246f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.93941931782002f / 8.0),
        FL2FXCONST_SGL(-0.56409379640356f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.88590003188677f / 8.0),
        FL2FXCONST_SGL(0.47624600491382f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99971463703691f / 8.0),
        FL2FXCONST_SGL(-0.83889954253462f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.75376385639978f / 8.0),
        FL2FXCONST_SGL(0.00814643438625f / 8.0)
    },
    {   FL2FXCONST_SGL(0.93887685615875f / 8.0),
        FL2FXCONST_SGL(-0.11284528204636f / 8.0)
    },
    {   FL2FXCONST_SGL(0.85126435782309f / 8.0),
        FL2FXCONST_SGL(0.52349251543547f / 8.0)
    },
    {   FL2FXCONST_SGL(0.39701421446381f / 8.0),
        FL2FXCONST_SGL(0.81779634174316f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.37024464187437f / 8.0),
        FL2FXCONST_SGL(-0.87071656222959f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.36024828242896f / 8.0),
        FL2FXCONST_SGL(0.34655735648287f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.93388812549209f / 8.0),
        FL2FXCONST_SGL(-0.84476541096429f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.65298804552119f / 8.0),
        FL2FXCONST_SGL(-0.18439575450921f / 8.0)
    },
    {   FL2FXCONST_SGL(0.11960319006843f / 8.0),
        FL2FXCONST_SGL(0.99899346780168f / 8.0)
    },
    {   FL2FXCONST_SGL(0.94292565553160f / 8.0),
        FL2FXCONST_SGL(0.83163906518293f / 8.0)
    },
    {   FL2FXCONST_SGL(0.75081145286948f / 8.0),
        FL2FXCONST_SGL(-0.35533223142265f / 8.0)
    },
    {   FL2FXCONST_SGL(0.56721979748394f / 8.0),
        FL2FXCONST_SGL(-0.24076836414499f / 8.0)
    },
    {   FL2FXCONST_SGL(0.46857766746029f / 8.0),
        FL2FXCONST_SGL(-0.30140233457198f / 8.0)
    },
    {   FL2FXCONST_SGL(0.97312313923635f / 8.0),
        FL2FXCONST_SGL(-0.99548191630031f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.38299976567017f / 8.0),
        FL2FXCONST_SGL(0.98516909715427f / 8.0)
    },
    {   FL2FXCONST_SGL(0.41025800019463f / 8.0),
        FL2FXCONST_SGL(0.02116736935734f / 8.0)
    },
    {   FL2FXCONST_SGL(0.09638062008048f / 8.0),
        FL2FXCONST_SGL(0.04411984381457f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.85283249275397f / 8.0),
        FL2FXCONST_SGL(0.91475563922421f / 8.0)
    },
    {   FL2FXCONST_SGL(0.88866808958124f / 8.0),
        FL2FXCONST_SGL(-0.99735267083226f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.48202429536989f / 8.0),
        FL2FXCONST_SGL(-0.96805608884164f / 8.0)
    },
    {   FL2FXCONST_SGL(0.27572582416567f / 8.0),
        FL2FXCONST_SGL(0.58634753335832f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.65889129659168f / 8.0),
        FL2FXCONST_SGL(0.58835634138583f / 8.0)
    },
    {   FL2FXCONST_SGL(0.98838086953732f / 8.0),
        FL2FXCONST_SGL(0.99994349600236f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.20651349620689f / 8.0),
        FL2FXCONST_SGL(0.54593044066355f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.62126416356920f / 8.0),
        FL2FXCONST_SGL(-0.59893681700392f / 8.0)
    },
    {   FL2FXCONST_SGL(0.20320105410437f / 8.0),
        FL2FXCONST_SGL(-0.86879180355289f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.97790548600584f / 8.0),
        FL2FXCONST_SGL(0.96290806999242f / 8.0)
    },
    {   FL2FXCONST_SGL(0.11112534735126f / 8.0),
        FL2FXCONST_SGL(0.21484763313301f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.41368337314182f / 8.0),
        FL2FXCONST_SGL(0.28216837680365f / 8.0)
    },
    {   FL2FXCONST_SGL(0.24133038992960f / 8.0),
        FL2FXCONST_SGL(0.51294362630238f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.66393410674885f / 8.0),
        FL2FXCONST_SGL(-0.08249679629081f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.53697829178752f / 8.0),
        FL2FXCONST_SGL(-0.97649903936228f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.97224737889348f / 8.0),
        FL2FXCONST_SGL(0.22081333579837f / 8.0)
    },
    {   FL2FXCONST_SGL(0.87392477144549f / 8.0),
        FL2FXCONST_SGL(-0.12796173740361f / 8.0)
    },
    {   FL2FXCONST_SGL(0.19050361015753f / 8.0),
        FL2FXCONST_SGL(0.01602615387195f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.46353441212724f / 8.0),
        FL2FXCONST_SGL(-0.95249041539006f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.07064096339021f / 8.0),
        FL2FXCONST_SGL(-0.94479803205886f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.92444085484466f / 8.0),
        FL2FXCONST_SGL(-0.10457590187436f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.83822593578728f / 8.0),
        FL2FXCONST_SGL(-0.01695043208885f / 8.0)
    },
    {   FL2FXCONST_SGL(0.75214681811150f / 8.0),
        FL2FXCONST_SGL(-0.99955681042665f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.42102998829339f / 8.0),
        FL2FXCONST_SGL(0.99720941999394f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.72094786237696f / 8.0),
        FL2FXCONST_SGL(-0.35008961934255f / 8.0)
    },
    {   FL2FXCONST_SGL(0.78843311019251f / 8.0),
        FL2FXCONST_SGL(0.52851398958271f / 8.0)
    },
    {   FL2FXCONST_SGL(0.97394027897442f / 8.0),
        FL2FXCONST_SGL(-0.26695944086561f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99206463477946f / 8.0),
        FL2FXCONST_SGL(-0.57010120849429f / 8.0)
    },
    {   FL2FXCONST_SGL(0.76789609461795f / 8.0),
        FL2FXCONST_SGL(-0.76519356730966f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.82002421836409f / 8.0),
        FL2FXCONST_SGL(-0.73530179553767f / 8.0)
    },
    {   FL2FXCONST_SGL(0.81924990025724f / 8.0),
        FL2FXCONST_SGL(0.99698425250579f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.26719850873357f / 8.0),
        FL2FXCONST_SGL(0.68903369776193f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.43311260380975f / 8.0),
        FL2FXCONST_SGL(0.85321815947490f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99194979673836f / 8.0),
        FL2FXCONST_SGL(0.91876249766422f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.80692001248487f / 8.0),
        FL2FXCONST_SGL(-0.32627540663214f / 8.0)
    },
    {   FL2FXCONST_SGL(0.43080003649976f / 8.0),
        FL2FXCONST_SGL(-0.21919095636638f / 8.0)
    },
    {   FL2FXCONST_SGL(0.67709491937357f / 8.0),
        FL2FXCONST_SGL(-0.95478075822906f / 8.0)
    },
    {   FL2FXCONST_SGL(0.56151770568316f / 8.0),
        FL2FXCONST_SGL(-0.70693811747778f / 8.0)
    },
    {   FL2FXCONST_SGL(0.10831862810749f / 8.0),
        FL2FXCONST_SGL(-0.08628837174592f / 8.0)
    },
    {   FL2FXCONST_SGL(0.91229417540436f / 8.0),
        FL2FXCONST_SGL(-0.65987351408410f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.48972893932274f / 8.0),
        FL2FXCONST_SGL(0.56289246362686f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.89033658689697f / 8.0),
        FL2FXCONST_SGL(-0.71656563987082f / 8.0)
    },
    {   FL2FXCONST_SGL(0.65269447475094f / 8.0),
        FL2FXCONST_SGL(0.65916004833932f / 8.0)
    },
    {   FL2FXCONST_SGL(0.67439478141121f / 8.0),
        FL2FXCONST_SGL(-0.81684380846796f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.47770832416973f / 8.0),
        FL2FXCONST_SGL(-0.16789556203025f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.99715979260878f / 8.0),
        FL2FXCONST_SGL(-0.93565784007648f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.90889593602546f / 8.0),
        FL2FXCONST_SGL(0.62034397054380f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.06618622548177f / 8.0),
        FL2FXCONST_SGL(-0.23812217221359f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99430266919728f / 8.0),
        FL2FXCONST_SGL(0.18812555317553f / 8.0)
    },
    {   FL2FXCONST_SGL(0.97686402381843f / 8.0),
        FL2FXCONST_SGL(-0.28664534366620f / 8.0)
    },
    {   FL2FXCONST_SGL(0.94813650221268f / 8.0),
        FL2FXCONST_SGL(-0.97506640027128f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.95434497492853f / 8.0),
        FL2FXCONST_SGL(-0.79607978501983f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.49104783137150f / 8.0),
        FL2FXCONST_SGL(0.32895214359663f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99881175120751f / 8.0),
        FL2FXCONST_SGL(0.88993983831354f / 8.0)
    },
    {   FL2FXCONST_SGL(0.50449166760303f / 8.0),
        FL2FXCONST_SGL(-0.85995072408434f / 8.0)
    },
    {   FL2FXCONST_SGL(0.47162891065108f / 8.0),
        FL2FXCONST_SGL(-0.18680204049569f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.62081581361840f / 8.0),
        FL2FXCONST_SGL(0.75000676218956f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.43867015250812f / 8.0),
        FL2FXCONST_SGL(0.99998069244322f / 8.0)
    },
    {   FL2FXCONST_SGL(0.98630563232075f / 8.0),
        FL2FXCONST_SGL(-0.53578899600662f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.61510362277374f / 8.0),
        FL2FXCONST_SGL(-0.89515019899997f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.03841517601843f / 8.0),
        FL2FXCONST_SGL(-0.69888815681179f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.30102157304644f / 8.0),
        FL2FXCONST_SGL(-0.07667808922205f / 8.0)
    },
    {   FL2FXCONST_SGL(0.41881284182683f / 8.0),
        FL2FXCONST_SGL(0.02188098922282f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.86135454941237f / 8.0),
        FL2FXCONST_SGL(0.98947480909359f / 8.0)
    },
    {   FL2FXCONST_SGL(0.67226861393788f / 8.0),
        FL2FXCONST_SGL(-0.13494389011014f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.70737398842068f / 8.0),
        FL2FXCONST_SGL(-0.76547349325992f / 8.0)
    },
    {   FL2FXCONST_SGL(0.94044946687963f / 8.0),
        FL2FXCONST_SGL(0.09026201157416f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.82386352534327f / 8.0),
        FL2FXCONST_SGL(0.08924768823676f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.32070666698656f / 8.0),
        FL2FXCONST_SGL(0.50143421908753f / 8.0)
    },
    {   FL2FXCONST_SGL(0.57593163224487f / 8.0),
        FL2FXCONST_SGL(-0.98966422921509f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.36326018419965f / 8.0),
        FL2FXCONST_SGL(0.07440243123228f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99979044674350f / 8.0),
        FL2FXCONST_SGL(-0.14130287347405f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.92366023326932f / 8.0),
        FL2FXCONST_SGL(-0.97979298068180f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.44607178518598f / 8.0),
        FL2FXCONST_SGL(-0.54233252016394f / 8.0)
    },
    {   FL2FXCONST_SGL(0.44226800932956f / 8.0),
        FL2FXCONST_SGL(0.71326756742752f / 8.0)
    },
    {   FL2FXCONST_SGL(0.03671907158312f / 8.0),
        FL2FXCONST_SGL(0.63606389366675f / 8.0)
    },
    {   FL2FXCONST_SGL(0.52175424682195f / 8.0),
        FL2FXCONST_SGL(-0.85396826735705f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.94701139690956f / 8.0),
        FL2FXCONST_SGL(-0.01826348194255f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.98759606946049f / 8.0),
        FL2FXCONST_SGL(0.82288714303073f / 8.0)
    },
    {   FL2FXCONST_SGL(0.87434794743625f / 8.0),
        FL2FXCONST_SGL(0.89399495655433f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.93412041758744f / 8.0),
        FL2FXCONST_SGL(0.41374052024363f / 8.0)
    },
    {   FL2FXCONST_SGL(0.96063943315511f / 8.0),
        FL2FXCONST_SGL(0.93116709541280f / 8.0)
    },
    {   FL2FXCONST_SGL(0.97534253457837f / 8.0),
        FL2FXCONST_SGL(0.86150930812689f / 8.0)
    },
    {   FL2FXCONST_SGL(0.99642466504163f / 8.0),
        FL2FXCONST_SGL(0.70190043427512f / 8.0)
    },
    {   FL2FXCONST_SGL(-0.94705089665984f / 8.0),
        FL2FXCONST_SGL(-0.29580042814306f / 8.0)
    },
    {   FL2FXCONST_SGL(0.91599807087376f / 8.0),
        FL2FXCONST_SGL(-0.98147830385781f / 8.0)
    }
};
//@}

/*
static const FIXP_SGL harmonicPhase [2][4] = {
  { 1.0, 0.0, -1.0,  0.0},
  { 0.0, 1.0,  0.0, -1.0}
};
*/

/* tables for SBR and AAC LD */
/* table for 8 time slot index */
const int FDK_sbrDecoder_envelopeTable_8[8][5] = {
    /* transientIndex  nEnv, tranIdx, shortEnv, border1, border2, ... */
    /* borders from left to right side; -1 = not in use */
    /*[|T-|------]*/ {2, 0, 0, 1, -1},
    /*[|-T-|-----]*/ {2, 0, 0, 2, -1},
    /*[--|T-|----]*/ {3, 1, 1, 2, 4},
    /*[---|T-|---]*/ {3, 1, 1, 3, 5},
    /*[----|T-|--]*/ {3, 1, 1, 4, 6},
    /*[-----|T--|]*/ {2, 1, 1, 5, -1},
    /*[------|T-|]*/ {2, 1, 1, 6, -1},
    /*[-------|T|]*/ {2, 1, 1, 7, -1},
};

/* table for 15 time slot index */
const int FDK_sbrDecoder_envelopeTable_15[15][6] = {
    /* transientIndex  nEnv, tranIdx, shortEnv, border1, border2, ... */
    /* length from left to right side; -1 = not in use */
    /*[|T---|------------]*/ {2, 0, 0, 4, -1, -1},
    /*[|-T---|-----------]*/ {2, 0, 0, 5, -1, -1},
    /*[|--|T---|---------]*/ {3, 1, 1, 2, 6, -1},
    /*[|---|T---|--------]*/ {3, 1, 1, 3, 7, -1},
    /*[|----|T---|-------]*/ {3, 1, 1, 4, 8, -1},
    /*[|-----|T---|------]*/ {3, 1, 1, 5, 9, -1},
    /*[|------|T---|-----]*/ {3, 1, 1, 6, 10, -1},
    /*[|-------|T---|----]*/ {3, 1, 1, 7, 11, -1},
    /*[|--------|T---|---]*/ {3, 1, 1, 8, 12, -1},
    /*[|---------|T---|--]*/ {3, 1, 1, 9, 13, -1},
    /*[|----------|T----|]*/ {2, 1, 1, 10, -1, -1},
    /*[|-----------|T---|]*/ {2, 1, 1, 11, -1, -1},
    /*[|------------|T--|]*/ {2, 1, 1, 12, -1, -1},
    /*[|-------------|T-|]*/ {2, 1, 1, 13, -1, -1},
    /*[|--------------|T|]*/ {2, 1, 1, 14, -1, -1},
};

/* table for 16 time slot index */
const int FDK_sbrDecoder_envelopeTable_16[16][6] = {
    /* transientIndex  nEnv, tranIdx, shortEnv, border1, border2, ... */
    /* length from left to right side; -1 = not in use */
    /*[|T---|------------|]*/ {2, 0, 0, 4, -1, -1},
    /*[|-T---|-----------|]*/ {2, 0, 0, 5, -1, -1},
    /*[|--|T---|----------]*/ {3, 1, 1, 2, 6, -1},
    /*[|---|T---|---------]*/ {3, 1, 1, 3, 7, -1},
    /*[|----|T---|--------]*/ {3, 1, 1, 4, 8, -1},
    /*[|-----|T---|-------]*/ {3, 1, 1, 5, 9, -1},
    /*[|------|T---|------]*/ {3, 1, 1, 6, 10, -1},
    /*[|-------|T---|-----]*/ {3, 1, 1, 7, 11, -1},
    /*[|--------|T---|----]*/ {3, 1, 1, 8, 12, -1},
    /*[|---------|T---|---]*/ {3, 1, 1, 9, 13, -1},
    /*[|----------|T---|--]*/ {3, 1, 1, 10, 14, -1},
    /*[|-----------|T----|]*/ {2, 1, 1, 11, -1, -1},
    /*[|------------|T---|]*/ {2, 1, 1, 12, -1, -1},
    /*[|-------------|T--|]*/ {2, 1, 1, 13, -1, -1},
    /*[|--------------|T-|]*/ {2, 1, 1, 14, -1, -1},
    /*[|---------------|T|]*/ {2, 1, 1, 15, -1, -1},
};

/*!
  \name FrameInfoDefaults

  Predefined envelope positions for the FIX-FIX case (static framing)
*/
//@{
const FRAME_INFO FDK_sbrDecoder_sbr_frame_info1_15 = {
    0, 1, {0, 15, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, -1, 1, {0, 15, 0}, {0, 0, 0},
    0, 0
};
const FRAME_INFO FDK_sbrDecoder_sbr_frame_info2_15 = {
    0, 2, {0, 8, 15, 0, 0, 0}, {1, 1, 0, 0, 0}, -1, 2, {0, 8, 15}, {0, 0, 0},
    0, 0
};
const FRAME_INFO FDK_sbrDecoder_sbr_frame_info4_15 = {
    0, 4, {0, 4, 8, 12, 15, 0}, {1, 1, 1, 1, 0}, -1, 2, {0, 8, 15}, {0, 0, 0},
    0, 0
};
#if (MAX_ENVELOPES >= 8)
const FRAME_INFO FDK_sbrDecoder_sbr_frame_info8_15 = {
    0,
    8,
    {0, 2, 4, 6, 8, 10, 12, 14, 15},
    {1, 1, 1, 1, 1, 1, 1, 1},
    -1,
    2,
    {0, 8, 15},
    {0, 0, 0},
    0,
    0
};
#endif

const FRAME_INFO FDK_sbrDecoder_sbr_frame_info1_16 = {
    0, 1, {0, 16, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, -1, 1, {0, 16, 0}, {0, 0, 0},
    0, 0
};
const FRAME_INFO FDK_sbrDecoder_sbr_frame_info2_16 = {
    0, 2, {0, 8, 16, 0, 0, 0}, {1, 1, 0, 0, 0}, -1, 2, {0, 8, 16}, {0, 0, 0},
    0, 0
};
const FRAME_INFO FDK_sbrDecoder_sbr_frame_info4_16 = {
    0, 4, {0, 4, 8, 12, 16, 0}, {1, 1, 1, 1, 0}, -1, 2, {0, 8, 16}, {0, 0, 0},
    0, 0
};

#if (MAX_ENVELOPES >= 8)
const FRAME_INFO FDK_sbrDecoder_sbr_frame_info8_16 = {
    0,
    8,
    {0, 2, 4, 6, 8, 10, 12, 14, 16},
    {1, 1, 1, 1, 1, 1, 1, 1},
    -1,
    2,
    {0, 8, 16},
    {0, 0, 0},
    0,
    0
};
#endif

//@}

/*!
  \name SBR_HuffmanTables

  SBR Huffman Table Overview:        \n
                                     \n
 o envelope level,   1.5 dB:         \n
    1)  sbr_huffBook_EnvLevel10T[120][2]   \n
    2)  sbr_huffBook_EnvLevel10F[120][2]   \n
                                     \n
 o envelope balance, 1.5 dB:         \n
    3)  sbr_huffBook_EnvBalance10T[48][2]  \n
    4)  sbr_huffBook_EnvBalance10F[48][2]  \n
                                     \n
 o envelope level,   3.0 dB:         \n
    5)  sbr_huffBook_EnvLevel11T[62][2]    \n
    6)  sbr_huffBook_EnvLevel11F[62][2]    \n
                                     \n
 o envelope balance, 3.0 dB:         \n
    7)  sbr_huffBook_EnvBalance11T[24][2]  \n
    8)  sbr_huffBook_EnvBalance11F[24][2]  \n
                                     \n
 o noise level,      3.0 dB:         \n
    9)  sbr_huffBook_NoiseLevel11T[62][2]  \n
    -) (sbr_huffBook_EnvLevel11F[62][2] is used for freq dir)\n
                                     \n
 o noise balance,    3.0 dB:         \n
   10)  sbr_huffBook_NoiseBalance11T[24][2]\n
    -) (sbr_huffBook_EnvBalance11F[24][2] is used for freq dir)\n
                                     \n
  (1.5 dB is never used for noise)

*/
//@{
const SCHAR FDK_sbrDecoder_sbr_huffBook_EnvLevel10T[120][2] = {
    {1, 2},       {-64, -65},   {3, 4},       {-63, -66},   {5, 6},
    {-62, -67},   {7, 8},       {-61, -68},   {9, 10},      {-60, -69},
    {11, 12},     {-59, -70},   {13, 14},     {-58, -71},   {15, 16},
    {-57, -72},   {17, 18},     {-73, -56},   {19, 21},     {-74, 20},
    {-55, -75},   {22, 26},     {23, 24},     {-54, -76},   {-77, 25},
    {-53, -78},   {27, 34},     {28, 29},     {-52, -79},   {30, 31},
    {-80, -51},   {32, 33},     {-83, -82},   {-81, -50},   {35, 57},
    {36, 40},     {37, 38},     {-88, -84},   {-48, 39},    {-90, -85},
    {41, 46},     {42, 43},     {-49, -87},   {44, 45},     {-89, -86},
    {-124, -123}, {47, 50},     {48, 49},     {-122, -121}, {-120, -119},
    {51, 54},     {52, 53},     {-118, -117}, {-116, -115}, {55, 56},
    {-114, -113}, {-112, -111}, {58, 89},     {59, 74},     {60, 67},
    {61, 64},     {62, 63},     {-110, -109}, {-108, -107}, {65, 66},
    {-106, -105}, {-104, -103}, {68, 71},     {69, 70},     {-102, -101},
    {-100, -99},  {72, 73},     {-98, -97},   {-96, -95},   {75, 82},
    {76, 79},     {77, 78},     {-94, -93},   {-92, -91},   {80, 81},
    {-47, -46},   {-45, -44},   {83, 86},     {84, 85},     {-43, -42},
    {-41, -40},   {87, 88},     {-39, -38},   {-37, -36},   {90, 105},
    {91, 98},     {92, 95},     {93, 94},     {-35, -34},   {-33, -32},
    {96, 97},     {-31, -30},   {-29, -28},   {99, 102},    {100, 101},
    {-27, -26},   {-25, -24},   {103, 104},   {-23, -22},   {-21, -20},
    {106, 113},   {107, 110},   {108, 109},   {-19, -18},   {-17, -16},
    {111, 112},   {-15, -14},   {-13, -12},   {114, 117},   {115, 116},
    {-11, -10},   {-9, -8},     {118, 119},   {-7, -6},     {-5, -4}
};

const SCHAR FDK_sbrDecoder_sbr_huffBook_EnvLevel10F[120][2] = {
    {1, 2},       {-64, -65},   {3, 4},       {-63, -66},   {5, 6},
    {-67, -62},   {7, 8},       {-68, -61},   {9, 10},      {-69, -60},
    {11, 13},     {-70, 12},    {-59, -71},   {14, 16},     {-58, 15},
    {-72, -57},   {17, 19},     {-73, 18},    {-56, -74},   {20, 23},
    {21, 22},     {-55, -75},   {-54, -53},   {24, 27},     {25, 26},
    {-76, -52},   {-77, -51},   {28, 31},     {29, 30},     {-50, -78},
    {-79, -49},   {32, 36},     {33, 34},     {-48, -47},   {-80, 35},
    {-81, -82},   {37, 47},     {38, 41},     {39, 40},     {-83, -46},
    {-45, -84},   {42, 44},     {-85, 43},    {-44, -43},   {45, 46},
    {-88, -87},   {-86, -90},   {48, 66},     {49, 56},     {50, 53},
    {51, 52},     {-92, -42},   {-41, -39},   {54, 55},     {-105, -89},
    {-38, -37},   {57, 60},     {58, 59},     {-94, -91},   {-40, -36},
    {61, 63},     {-20, 62},    {-115, -110}, {64, 65},     {-108, -107},
    {-101, -97},  {67, 89},     {68, 75},     {69, 72},     {70, 71},
    {-95, -93},   {-34, -27},   {73, 74},     {-22, -17},   {-16, -124},
    {76, 82},     {77, 79},     {-123, 78},   {-122, -121}, {80, 81},
    {-120, -119}, {-118, -117}, {83, 86},     {84, 85},     {-116, -114},
    {-113, -112}, {87, 88},     {-111, -109}, {-106, -104}, {90, 105},
    {91, 98},     {92, 95},     {93, 94},     {-103, -102}, {-100, -99},
    {96, 97},     {-98, -96},   {-35, -33},   {99, 102},    {100, 101},
    {-32, -31},   {-30, -29},   {103, 104},   {-28, -26},   {-25, -24},
    {106, 113},   {107, 110},   {108, 109},   {-23, -21},   {-19, -18},
    {111, 112},   {-15, -14},   {-13, -12},   {114, 117},   {115, 116},
    {-11, -10},   {-9, -8},     {118, 119},   {-7, -6},     {-5, -4}
};

const SCHAR FDK_sbrDecoder_sbr_huffBook_EnvBalance10T[48][2] = {
    {-64, 1},   {-63, 2},   {-65, 3},   {-62, 4},   {-66, 5},   {-61, 6},
    {-67, 7},   {-60, 8},   {-68, 9},   {10, 11},   {-69, -59}, {12, 13},
    {-70, -58}, {14, 28},   {15, 21},   {16, 18},   {-57, 17},  {-71, -56},
    {19, 20},   {-88, -87}, {-86, -85}, {22, 25},   {23, 24},   {-84, -83},
    {-82, -81}, {26, 27},   {-80, -79}, {-78, -77}, {29, 36},   {30, 33},
    {31, 32},   {-76, -75}, {-74, -73}, {34, 35},   {-72, -55}, {-54, -53},
    {37, 41},   {38, 39},   {-52, -51}, {-50, 40},  {-49, -48}, {42, 45},
    {43, 44},   {-47, -46}, {-45, -44}, {46, 47},   {-43, -42}, {-41, -40}
};

const SCHAR FDK_sbrDecoder_sbr_huffBook_EnvBalance10F[48][2] = {
    {-64, 1},   {-65, 2},   {-63, 3},   {-66, 4},   {-62, 5},   {-61, 6},
    {-67, 7},   {-68, 8},   {-60, 9},   {10, 11},   {-69, -59}, {-70, 12},
    {-58, 13},  {14, 17},   {-71, 15},  {-57, 16},  {-56, -73}, {18, 32},
    {19, 25},   {20, 22},   {-72, 21},  {-88, -87}, {23, 24},   {-86, -85},
    {-84, -83}, {26, 29},   {27, 28},   {-82, -81}, {-80, -79}, {30, 31},
    {-78, -77}, {-76, -75}, {33, 40},   {34, 37},   {35, 36},   {-74, -55},
    {-54, -53}, {38, 39},   {-52, -51}, {-50, -49}, {41, 44},   {42, 43},
    {-48, -47}, {-46, -45}, {45, 46},   {-44, -43}, {-42, 47},  {-41, -40}
};

const SCHAR FDK_sbrDecoder_sbr_huffBook_EnvLevel11T[62][2] = {
    {-64, 1},   {-65, 2},   {-63, 3},   {-66, 4},   {-62, 5},   {-67, 6},
    {-61, 7},   {-68, 8},   {-60, 9},   {10, 11},   {-69, -59}, {12, 14},
    {-70, 13},  {-71, -58}, {15, 18},   {16, 17},   {-72, -57}, {-73, -74},
    {19, 22},   {-56, 20},  {-55, 21},  {-54, -77}, {23, 31},   {24, 25},
    {-75, -76}, {26, 27},   {-78, -53}, {28, 29},   {-52, -95}, {-94, 30},
    {-93, -92}, {32, 47},   {33, 40},   {34, 37},   {35, 36},   {-91, -90},
    {-89, -88}, {38, 39},   {-87, -86}, {-85, -84}, {41, 44},   {42, 43},
    {-83, -82}, {-81, -80}, {45, 46},   {-79, -51}, {-50, -49}, {48, 55},
    {49, 52},   {50, 51},   {-48, -47}, {-46, -45}, {53, 54},   {-44, -43},
    {-42, -41}, {56, 59},   {57, 58},   {-40, -39}, {-38, -37}, {60, 61},
    {-36, -35}, {-34, -33}
};

const SCHAR FDK_sbrDecoder_sbr_huffBook_EnvLevel11F[62][2] = {
    {-64, 1},   {-65, 2},   {-63, 3},   {-66, 4},   {-62, 5},   {-67, 6},
    {7, 8},     {-61, -68}, {9, 10},    {-60, -69}, {11, 12},   {-59, -70},
    {13, 14},   {-58, -71}, {15, 16},   {-57, -72}, {17, 19},   {-56, 18},
    {-55, -73}, {20, 24},   {21, 22},   {-74, -54}, {-53, 23},  {-75, -76},
    {25, 30},   {26, 27},   {-52, -51}, {28, 29},   {-77, -79}, {-50, -49},
    {31, 39},   {32, 35},   {33, 34},   {-78, -46}, {-82, -88}, {36, 37},
    {-83, -48}, {-47, 38},  {-86, -85}, {40, 47},   {41, 44},   {42, 43},
    {-80, -44}, {-43, -42}, {45, 46},   {-39, -87}, {-84, -40}, {48, 55},
    {49, 52},   {50, 51},   {-95, -94}, {-93, -92}, {53, 54},   {-91, -90},
    {-89, -81}, {56, 59},   {57, 58},   {-45, -41}, {-38, -37}, {60, 61},
    {-36, -35}, {-34, -33}
};

const SCHAR FDK_sbrDecoder_sbr_huffBook_EnvBalance11T[24][2] = {
    {-64, 1},   {-63, 2},   {-65, 3},   {-66, 4},   {-62, 5},  {-61, 6},
    {-67, 7},   {-68, 8},   {-60, 9},   {10, 16},   {11, 13},  {-69, 12},
    {-76, -75}, {14, 15},   {-74, -73}, {-72, -71}, {17, 20},  {18, 19},
    {-70, -59}, {-58, -57}, {21, 22},   {-56, -55}, {-54, 23}, {-53, -52}
};

const SCHAR FDK_sbrDecoder_sbr_huffBook_EnvBalance11F[24][2] = {
    {-64, 1},   {-65, 2},   {-63, 3},   {-66, 4},   {-62, 5},   {-61, 6},
    {-67, 7},   {-68, 8},   {-60, 9},   {10, 13},   {-69, 11},  {-59, 12},
    {-58, -76}, {14, 17},   {15, 16},   {-75, -74}, {-73, -72}, {18, 21},
    {19, 20},   {-71, -70}, {-57, -56}, {22, 23},   {-55, -54}, {-53, -52}
};

const SCHAR FDK_sbrDecoder_sbr_huffBook_NoiseLevel11T[62][2] = {
    {-64, 1},   {-63, 2},   {-65, 3},   {-66, 4},   {-62, 5},   {-67, 6},
    {7, 8},     {-61, -68}, {9, 30},    {10, 15},   {-60, 11},  {-69, 12},
    {13, 14},   {-59, -53}, {-95, -94}, {16, 23},   {17, 20},   {18, 19},
    {-93, -92}, {-91, -90}, {21, 22},   {-89, -88}, {-87, -86}, {24, 27},
    {25, 26},   {-85, -84}, {-83, -82}, {28, 29},   {-81, -80}, {-79, -78},
    {31, 46},   {32, 39},   {33, 36},   {34, 35},   {-77, -76}, {-75, -74},
    {37, 38},   {-73, -72}, {-71, -70}, {40, 43},   {41, 42},   {-58, -57},
    {-56, -55}, {44, 45},   {-54, -52}, {-51, -50}, {47, 54},   {48, 51},
    {49, 50},   {-49, -48}, {-47, -46}, {52, 53},   {-45, -44}, {-43, -42},
    {55, 58},   {56, 57},   {-41, -40}, {-39, -38}, {59, 60},   {-37, -36},
    {-35, 61},  {-34, -33}
};

const SCHAR FDK_sbrDecoder_sbr_huffBook_NoiseBalance11T[24][2] = {
    {-64, 1},   {-65, 2},   {-63, 3},   {4, 9},     {-66, 5},   {-62, 6},
    {7, 8},     {-76, -75}, {-74, -73}, {10, 17},   {11, 14},   {12, 13},
    {-72, -71}, {-70, -69}, {15, 16},   {-68, -67}, {-61, -60}, {18, 21},
    {19, 20},   {-59, -58}, {-57, -56}, {22, 23},   {-55, -54}, {-53, -52}
};
//@}

/*!
  \name  parametric stereo
  \brief constants used by the parametric stereo part of the decoder

*/

/* constants used in psbitdec.cpp */

/* FIX_BORDER can have 0, 1, 2, 4 envelopes */
const UCHAR FDK_sbrDecoder_aFixNoEnvDecode[4] = {0, 1, 2, 4};

/* IID & ICC Huffman codebooks */
const SCHAR aBookPsIidTimeDecode[28][2] = {
    {-64, 1},   {-65, 2},   {-63, 3},   {-66, 4},  {-62, 5},   {-67, 6},
    {-61, 7},   {-68, 8},   {-60, 9},   {-69, 10}, {-59, 11},  {-70, 12},
    {-58, 13},  {-57, 14},  {-71, 15},  {16, 17},  {-56, -72}, {18, 21},
    {19, 20},   {-55, -78}, {-77, -76}, {22, 25},  {23, 24},   {-75, -74},
    {-73, -54}, {26, 27},   {-53, -52}, {-51, -50}
};

const SCHAR aBookPsIidFreqDecode[28][2] = {
    {-64, 1},   {2, 3},     {-63, -65}, {4, 5},    {-62, -66}, {6, 7},
    {-61, -67}, {8, 9},     {-68, -60}, {-59, 10}, {-69, 11},  {-58, 12},
    {-70, 13},  {-71, 14},  {-57, 15},  {16, 17},  {-56, -72}, {18, 19},
    {-55, -54}, {20, 21},   {-73, -53}, {22, 24},  {-74, 23},  {-75, -78},
    {25, 26},   {-77, -76}, {-52, 27},  {-51, -50}
};

const SCHAR aBookPsIccTimeDecode[14][2] = {
    {-64, 1}, {-63, 2}, {-65, 3},  {-62, 4},  {-66, 5},  {-61, 6},  {-67, 7},
    {-60, 8}, {-68, 9}, {-59, 10}, {-69, 11}, {-58, 12}, {-70, 13}, {-71, -57}
};

const SCHAR aBookPsIccFreqDecode[14][2] = {
    {-64, 1}, {-63, 2}, {-65, 3},  {-62, 4},  {-66, 5},  {-61, 6},  {-67, 7},
    {-60, 8}, {-59, 9}, {-68, 10}, {-58, 11}, {-69, 12}, {-57, 13}, {-70, -71}
};

/* IID-fine Huffman codebooks */

const SCHAR aBookPsIidFineTimeDecode[60][2] = {
    {1, -64},   {-63, 2},   {3, -65},   {4, 59},    {5, 7},     {6, -67},
    {-68, -60}, {-61, 8},   {9, 11},    {-59, 10},  {-70, -58}, {12, 41},
    {13, 20},   {14, -71},  {-55, 15},  {-53, 16},  {17, -77},  {18, 19},
    {-85, -84}, {-46, -45}, {-57, 21},  {22, 40},   {23, 29},   {-51, 24},
    {25, 26},   {-83, -82}, {27, 28},   {-90, -38}, {-92, -91}, {30, 37},
    {31, 34},   {32, 33},   {-35, -34}, {-37, -36}, {35, 36},   {-94, -93},
    {-89, -39}, {38, -79},  {39, -81},  {-88, -40}, {-74, -54}, {42, -69},
    {43, 44},   {-72, -56}, {45, 52},   {46, 50},   {47, -76},  {-49, 48},
    {-47, 49},  {-87, -41}, {-52, 51},  {-78, -50}, {53, -73},  {54, -75},
    {55, 57},   {56, -80},  {-86, -42}, {-48, 58},  {-44, -43}, {-66, -62}
};

const SCHAR aBookPsIidFineFreqDecode[60][2] = {
    {1, -64},   {2, 4},     {3, -65},   {-66, -62}, {-63, 5},   {6, 7},
    {-67, -61}, {8, 9},     {-68, -60}, {10, 11},   {-69, -59}, {12, 13},
    {-70, -58}, {14, 18},   {-57, 15},  {16, -72},  {-54, 17},  {-75, -53},
    {19, 37},   {-56, 20},  {21, -73},  {22, 29},   {23, -76},  {24, -78},
    {25, 28},   {26, 27},   {-85, -43}, {-83, -45}, {-81, -47}, {-52, 30},
    {-50, 31},  {32, -79},  {33, 34},   {-82, -46}, {35, 36},   {-90, -89},
    {-92, -91}, {38, -71},  {-55, 39},  {40, -74},  {41, 50},   {42, -77},
    {-49, 43},  {44, 47},   {45, 46},   {-86, -42}, {-88, -87}, {48, 49},
    {-39, -38}, {-41, -40}, {-51, 51},  {52, 59},   {53, 56},   {54, 55},
    {-35, -34}, {-37, -36}, {57, 58},   {-94, -93}, {-84, -44}, {-80, -48}
};

/* constants used in psdec.cpp */

/* the values of the following 3 tables are shiftet right by 1 ! */
const FIXP_DBL ScaleFactors[NO_IID_LEVELS] = {

    0x5a5ded00, 0x59cd0400, 0x58c29680, 0x564c2e80, 0x52a3d480,
    0x4c8be080, 0x46df3080, 0x40000000, 0x384ba5c0, 0x304c2980,
    0x24e9f640, 0x1b4a2940, 0x11b5c0a0, 0x0b4e2540, 0x0514ea90
};

const FIXP_DBL ScaleFactorsFine[NO_IID_LEVELS_FINE] = {

    0x5a825c00, 0x5a821c00, 0x5a815100, 0x5a7ed000, 0x5a76e600, 0x5a5ded00,
    0x5a39b880, 0x59f1fd00, 0x5964d680, 0x5852ca00, 0x564c2e80, 0x54174480,
    0x50ea7500, 0x4c8be080, 0x46df3080, 0x40000000, 0x384ba5c0, 0x304c2980,
    0x288dd240, 0x217a2900, 0x1b4a2940, 0x13c5ece0, 0x0e2b0090, 0x0a178ef0,
    0x072ab798, 0x0514ea90, 0x02dc5944, 0x019bf87c, 0x00e7b173, 0x00824b8b,
    0x00494568
};
const FIXP_DBL Alphas[NO_ICC_LEVELS] = {

    0x00000000, 0x0b6b5be0, 0x12485f80, 0x1da2fa40,
    0x2637ebc0, 0x3243f6c0, 0x466b7480, 0x6487ed80
};

const UCHAR bins2groupMap20[NO_IID_GROUPS] = {
    0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19
};

const UCHAR FDK_sbrDecoder_aNoIidBins[3] = {
    NO_LOW_RES_IID_BINS, NO_MID_RES_IID_BINS, NO_HI_RES_IID_BINS
};

const UCHAR FDK_sbrDecoder_aNoIccBins[3] = {
    NO_LOW_RES_ICC_BINS, NO_MID_RES_ICC_BINS, NO_HI_RES_ICC_BINS
};

/************************************************************************/
/*!
   \brief   Create lookup tables for some arithmetic functions

   The tables would normally be defined as const arrays,
   but initialization at run time allows to specify their accuracy.
*/
/************************************************************************/

/*   1/x-table:  (example for INV_TABLE_BITS 8)

     The table covers an input range from 0.5 to 1.0 with a step size of 1/512,
     starting at 0.5 + 1/512.
     Each table entry corresponds to an input interval starting 1/1024 below the
     exact value and ending 1/1024 above it.

     The table is actually a 0.5/x-table, so that the output range is again
     0.5...1.0 and the exponent of the result must be increased by 1.

     Input range           Index in table      result
     -------------------------------------------------------------------
     0.500000...0.500976          -            0.5 / 0.500000 = 1.000000
     0.500976...0.502930          0            0.5 / 0.501953 = 0.996109
     0.502930...0.500488          1            0.5 / 0.503906 = 0.992248
             ...
     0.999023...1.000000         255           0.5 / 1.000000 = 0.500000

       for (i=0; i<INV_TABLE_SIZE; i++) {
         d = 0.5f / ( 0.5f+(double)(i+1)/(INV_TABLE_SIZE*2) ) ;
         invTable[i] = FL2FX_SGL(d);
       }
*/
const FIXP_SGL FDK_sbrDecoder_invTable[INV_TABLE_SIZE] = {
    0x7f80, 0x7f01, 0x7e83, 0x7e07, 0x7d8b, 0x7d11, 0x7c97, 0x7c1e, 0x7ba6,
    0x7b2f, 0x7ab9, 0x7a44, 0x79cf, 0x795c, 0x78e9, 0x7878, 0x7807, 0x7796,
    0x7727, 0x76b9, 0x764b, 0x75de, 0x7572, 0x7506, 0x749c, 0x7432, 0x73c9,
    0x7360, 0x72f9, 0x7292, 0x722c, 0x71c6, 0x7161, 0x70fd, 0x709a, 0x7037,
    0x6fd5, 0x6f74, 0x6f13, 0x6eb3, 0x6e54, 0x6df5, 0x6d97, 0x6d39, 0x6cdc,
    0x6c80, 0x6c24, 0x6bc9, 0x6b6f, 0x6b15, 0x6abc, 0x6a63, 0x6a0b, 0x69b3,
    0x695c, 0x6906, 0x68b0, 0x685a, 0x6806, 0x67b1, 0x675e, 0x670a, 0x66b8,
    0x6666, 0x6614, 0x65c3, 0x6572, 0x6522, 0x64d2, 0x6483, 0x6434, 0x63e6,
    0x6399, 0x634b, 0x62fe, 0x62b2, 0x6266, 0x621b, 0x61d0, 0x6185, 0x613b,
    0x60f2, 0x60a8, 0x6060, 0x6017, 0x5fcf, 0x5f88, 0x5f41, 0x5efa, 0x5eb4,
    0x5e6e, 0x5e28, 0x5de3, 0x5d9f, 0x5d5a, 0x5d17, 0x5cd3, 0x5c90, 0x5c4d,
    0x5c0b, 0x5bc9, 0x5b87, 0x5b46, 0x5b05, 0x5ac4, 0x5a84, 0x5a44, 0x5a05,
    0x59c6, 0x5987, 0x5949, 0x590a, 0x58cd, 0x588f, 0x5852, 0x5815, 0x57d9,
    0x579d, 0x5761, 0x5725, 0x56ea, 0x56af, 0x5675, 0x563b, 0x5601, 0x55c7,
    0x558e, 0x5555, 0x551c, 0x54e3, 0x54ab, 0x5473, 0x543c, 0x5405, 0x53ce,
    0x5397, 0x5360, 0x532a, 0x52f4, 0x52bf, 0x5289, 0x5254, 0x521f, 0x51eb,
    0x51b7, 0x5183, 0x514f, 0x511b, 0x50e8, 0x50b5, 0x5082, 0x5050, 0x501d,
    0x4feb, 0x4fba, 0x4f88, 0x4f57, 0x4f26, 0x4ef5, 0x4ec4, 0x4e94, 0x4e64,
    0x4e34, 0x4e04, 0x4dd5, 0x4da6, 0x4d77, 0x4d48, 0x4d19, 0x4ceb, 0x4cbd,
    0x4c8f, 0x4c61, 0x4c34, 0x4c07, 0x4bd9, 0x4bad, 0x4b80, 0x4b54, 0x4b27,
    0x4afb, 0x4acf, 0x4aa4, 0x4a78, 0x4a4d, 0x4a22, 0x49f7, 0x49cd, 0x49a2,
    0x4978, 0x494e, 0x4924, 0x48fa, 0x48d1, 0x48a7, 0x487e, 0x4855, 0x482d,
    0x4804, 0x47dc, 0x47b3, 0x478b, 0x4763, 0x473c, 0x4714, 0x46ed, 0x46c5,
    0x469e, 0x4677, 0x4651, 0x462a, 0x4604, 0x45de, 0x45b8, 0x4592, 0x456c,
    0x4546, 0x4521, 0x44fc, 0x44d7, 0x44b2, 0x448d, 0x4468, 0x4444, 0x441f,
    0x43fb, 0x43d7, 0x43b3, 0x4390, 0x436c, 0x4349, 0x4325, 0x4302, 0x42df,
    0x42bc, 0x4299, 0x4277, 0x4254, 0x4232, 0x4210, 0x41ee, 0x41cc, 0x41aa,
    0x4189, 0x4167, 0x4146, 0x4125, 0x4104, 0x40e3, 0x40c2, 0x40a1, 0x4081,
    0x4060, 0x4040, 0x4020, 0x4000
};
