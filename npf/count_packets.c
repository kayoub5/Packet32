/**
 * Packet32 has no copyright assigned and is placed in the Public Domain.
 * No warranty is given; refer to the files LICENSE-WTFPL, COPYING.Npcap and
 * COPYING.WinPcap within this package.
 */

#include "stdafx.h"

#ifdef WIN32
#include "tme.h"
#include "count_packets.h"
#endif

#ifdef __FreeBSD__

#ifdef _KERNEL
#include <net/tme/tme.h>
#include <net/tme/count_packets.h>
#else
#include <tme/tme.h>
#include <tme/count_packets.h>
#endif

#endif

#ifndef UNUSED
#define UNUSED(_x) (_x)
#endif

#ifdef WIN32

uint32 count_packets(uint8* block, uint32 pkt_size, TME_DATA* data, MEM_TYPE* mem_ex, uint8* mem_data)
{
	c_p_data* counters;

	UNUSED(mem_data);
	UNUSED(mem_ex);

	counters = (c_p_data *)(block + data->key_len * 4);

	counters->bytes += pkt_size;
	counters->packets++;

	return TME_SUCCESS;
}

#endif
