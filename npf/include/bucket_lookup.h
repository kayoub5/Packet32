/**
 * Packet32 has no copyright assigned and is placed in the Public Domain.
 * No warranty is given; refer to the files LICENSE-WTFPL, COPYING.Npcap and
 * COPYING.WinPcap within this package.
 */

#ifndef __bucket_lookup
#define __bucket_lookup
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

#define BUCKET_LOOKUP_INSERT	0x00000011
uint32 bucket_lookup_insert(uint8* key, TME_DATA* data, MEM_TYPE* mem_ex, struct time_conv* time_ref);
#define BUCKET_LOOKUP			0x00000010
uint32 bucket_lookup(uint8* key, TME_DATA* data, MEM_TYPE* mem_ex, struct time_conv* time_ref);

#endif
