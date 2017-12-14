/**
 * Packet32 has no copyright assigned and is placed in the Public Domain.
 * No warranty is given; refer to the files LICENSE-WTFPL, COPYING.Npcap and
 * COPYING.WinPcap within this package.
 */

#include "stdafx.h"

#ifdef WIN32
#include "tme.h"
#include "functions.h"
#endif

#ifdef __FreeBSD__

#ifdef _KERNEL
#include <net/tme/tme.h>
#include <net/bpf.h>
#include <net/tme/functions.h>
#else
#include <tme/tme.h>
#include <bpf.h>
#include <tme/functions.h>
#endif

#endif

#ifdef WIN32

lut_fcn lut_fcn_mapper(uint32 index)
{
	switch (index)
	{
	case NORMAL_LUT_W_INSERT:
		return (lut_fcn)normal_lut_w_insert;

	case NORMAL_LUT_WO_INSERT:
		return (lut_fcn)normal_lut_wo_insert;

	case BUCKET_LOOKUP:
		return (lut_fcn)bucket_lookup;

	case BUCKET_LOOKUP_INSERT:
		return (lut_fcn)bucket_lookup_insert;

	default:
		return NULL;
	}
}

exec_fcn exec_fcn_mapper(uint32 index)
{
	switch (index)
	{
	case COUNT_PACKETS:
		return (exec_fcn)count_packets;

	case TCP_SESSION:
		return (exec_fcn)tcp_session;
	default:
		return NULL;
	}
}

#endif
