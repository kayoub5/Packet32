/**
 * Packet32 has no copyright assigned and is placed in the Public Domain.
 * No warranty is given; refer to the files LICENSE-WTFPL, COPYING.Npcap and
 * COPYING.WinPcap within this package.
 */

#ifndef __FILTER_INIT
#define __FILTER_INIT

#include "tme.h"

#define INIT_OK		1
#define INIT_ERROR	0

#ifdef __cplusplus
extern "C"
{
#endif
	uint32 bpf_filter_init(register struct bpf_insn* pc, MEM_TYPE* mem_ex, TME_CORE* tme, struct time_conv* time_ref);
#ifdef __cplusplus
}
#endif

#endif
