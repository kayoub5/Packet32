/**
 * Packet32 has no copyright assigned and is placed in the Public Domain.
 * No warranty is given; refer to the files LICENSE-WTFPL, COPYING.Npcap and
 * COPYING.WinPcap within this package.
 */

#ifndef __DEBUG_INCLUDE
#define __DEBUG_INCLUDE


#if defined (DBG) && !defined (_WINDLL) && !defined (_WINLIB)

#define IF_PACKETDEBUG(f) if (PacketDebugFlag & (f))
extern ULONG PacketDebugFlag;

#define PACKET_DEBUG_LOUD   			0x00000001  // debugging info
#define PACKET_DEBUG_VERY_LOUD  		0x00000002  // excessive debugging info

#define PACKET_DEBUG_INIT   			0x00000100  // init debugging info

//
// unfortunately, NT4 does not have the __FUNCTION__ macro, so we define it as null
//
#ifndef __FUNCTION__
#define __FUNCTION__
#endif

//
// Macro for deciding whether to dump lots of debugging information.
//

#define IF_LOUD(A) IF_PACKETDEBUG( PACKET_DEBUG_LOUD ) { A }
#define IF_VERY_LOUD(A) IF_PACKETDEBUG( PACKET_DEBUG_VERY_LOUD ) { A }
#define IF_INIT_LOUD(A) IF_PACKETDEBUG( PACKET_DEBUG_INIT ) { A }

#define TRACE_ENTER() DbgPrint("--> " __FUNCTION__ "\n")
#define TRACE_EXIT() DbgPrint("<-- " __FUNCTION__ "\n")
#define TRACE_MESSAGE(__level__, __message__) do{ if (PacketDebugFlag & (__level__)) DbgPrint("    " __FUNCTION__ ": " __message__ "\n");} while(FALSE)

#define TRACE_MESSAGE1(__level__, __message__, __p1__) do			\
	{																\
		if (PacketDebugFlag & (__level__))							\
			DbgPrint("    " __FUNCTION__ ": " __message__ "\n", __p1__);	\
	} while(FALSE)

#define TRACE_MESSAGE2(__level__, __message__, __p1__, __p2__) do			\
	{																		\
		if (PacketDebugFlag & (__level__))									\
			DbgPrint("    " __FUNCTION__ ": " __message__ "\n", __p1__, __p2__);	\
	} while(FALSE)

#define TRACE_MESSAGE3(__level__, __message__, __p1__, __p2__, __p3__) do	\
	{																		\
		if (PacketDebugFlag & (__level__))									\
			DbgPrint("    " __FUNCTION__ ": " __message__ "\n", __p1__, __p2__, __p3__);	\
	} while(FALSE)

#define TRACE_MESSAGE4(__level__, __message__, __p1__, __p2__, __p3__, __p4__) do	\
	{																		\
		if (PacketDebugFlag & (__level__))									\
			DbgPrint("    " __FUNCTION__ ": " __message__ "\n", __p1__, __p2__, __p3__, __p4__ );	\
	} while(FALSE)


#else //DBG

#define IF_LOUD(A)
#define IF_VERY_LOUD(A)
#define IF_INIT_LOUD(A)

#define TRACE_ENTER()
#define TRACE_EXIT()
#define TRACE_MESSAGE(__level__, __message__)
#define TRACE_MESSAGE1(__level__, __message__, __p1__)
#define TRACE_MESSAGE2(__level__, __message__, __p1__, __p2__)
#define TRACE_MESSAGE3(__level__, __message__, __p1__, __p2__, __p3__)
#define TRACE_MESSAGE4(__level__, __message__, __p1__, __p2__, __p3__, __p4__)

#endif

#endif /*#define __DEBUG_INCLUDE*/
