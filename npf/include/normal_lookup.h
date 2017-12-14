/**
 * Packet32 has no copyright assigned and is placed in the Public Domain.
 * No warranty is given; refer to the files LICENSE-WTFPL, COPYING.Npcap and
 * COPYING.WinPcap within this package.
 */

#ifndef __normal_lookup
#define __normal_lookup

#ifdef WIN32
#include "tme.h"
#endif

#ifdef __FreeBSD__

#ifdef _KERNEL
#include <net/tme/tme.h>
#else
#include <tme/tme.h>
#endif

#endif

#define NORMAL_LUT_W_INSERT				0x00000000
uint32 normal_lut_w_insert(uint8* key, TME_DATA* data, MEM_TYPE* mem_ex, struct time_conv* time_ref);   
#define NORMAL_LUT_WO_INSERT			0x00000001
uint32 normal_lut_wo_insert(uint8* key, TME_DATA* data, MEM_TYPE* mem_ex, struct time_conv* time_ref); 
#define DUMMY_INSERT					1234

#endif
