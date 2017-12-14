/**
 * Packet32 has no copyright assigned and is placed in the Public Domain.
 * No warranty is given; refer to the files LICENSE-WTFPL, COPYING.Npcap and
 * COPYING.WinPcap within this package.
 */

#ifndef __count_packets
#define __count_packets

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

typedef struct __c_p_data
{
	struct timeval timestamp;
	uint64 packets;
	uint64 bytes;
}
c_p_data;

#define COUNT_PACKETS					0x00000000
uint32 count_packets(uint8* block, uint32 pkt_size, TME_DATA* data, MEM_TYPE* mem_ex, uint8* mem_data);

#endif

