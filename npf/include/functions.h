/**
 * Packet32 has no copyright assigned and is placed in the Public Domain.
 * No warranty is given; refer to the files LICENSE-WTFPL, COPYING.Npcap and
 * COPYING.WinPcap within this package.
 */

#ifndef __FUNCTIONS
#define __FUNCTIONS

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
/*function mappers */

lut_fcn lut_fcn_mapper(uint32 index);
exec_fcn exec_fcn_mapper(uint32 index);

/* lookup functions */

#ifdef WIN32
#include "bucket_lookup.h"
#include "normal_lookup.h"
#endif

#ifdef __FreeBSD__
#include <net/tme/bucket_lookup.h>
#include <net/tme/normal_lookup.h>
#endif

/* execution functions */

#ifdef WIN32
#include "count_packets.h"
#include "tcp_session.h"
#endif

#ifdef __FreeBSD__
#include <net/tme/count_packets.h>
#include <ne/tme/tcp_session.h>
#endif

#endif
