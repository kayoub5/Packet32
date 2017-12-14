/**
 * Packet32 has no copyright assigned and is placed in the Public Domain.
 * No warranty is given; refer to the files LICENSE-WTFPL, COPYING.Npcap and
 * COPYING.WinPcap within this package.
 */

/*
* Lo_send.h
*
* Abstract:
* This file declares common data types and function prototypes used
* throughout loopback packets sending.
*
* This code is based on Microsoft Winsock Kernel echosrv sample and
* Google Code wskudp sample.
*/

#ifndef __LO_SEND
#define __LO_SEND

#ifdef HAVE_WFP_LOOPBACK_SUPPORT

#pragma warning(push)
#pragma warning(disable:4201) // nameless struct/union
#pragma warning(disable:4214) // bit field types other than int

#pragma once
#include <ntddk.h>
#include <wsk.h>
#include <ndis.h>

#pragma warning(pop)

#define SOCKET_ERROR -1

NTSTATUS
NTAPI
NPF_WSKInitSockets(
	);

VOID
NTAPI
NPF_WSKFreeSockets(
	);

NTSTATUS
NTAPI
NPF_WSKStartup(
	);

VOID
NTAPI
NPF_WSKCleanup(
	);

// NTSTATUS
// NTAPI
// NPF_WSKSendPacket(
// 	IN PCHAR PacketBuff,
// 	IN ULONG BuffSize
// 	);
// 
// NTSTATUS
// NTAPI
// WSKSendPacketInternal(
// 	IN BOOLEAN bIPv4,
// 	IN PCHAR PacketBuff,
// 	IN ULONG BuffSize
// 	);

NTSTATUS
NTAPI
NPF_WSKSendPacket_NBL(
	IN PNET_BUFFER_LIST NetBufferList
	);

NTSTATUS
NTAPI
WSKSendPacketInternal_NBL(
	IN BOOLEAN bIPv4,
	IN PNET_BUFFER_LIST NetBufferList,
	IN ULONG Offset
	);

PWSK_SOCKET
NTAPI
WSKCreateSocket(
	IN ADDRESS_FAMILY AddressFamily,
	IN USHORT SocketType,
	IN ULONG Protocol,
	IN ULONG Flags
	);

NTSTATUS
NTAPI
WSKCloseSocket(
	IN PWSK_SOCKET WskSocket
	);

// LONG
// NTAPI
// WSKSend(
// 	IN PWSK_SOCKET WskSocket,
// 	IN PVOID Buffer,
// 	IN ULONG BufferSize,
// 	IN ULONG Flags
// 	);
// 
// LONG
// NTAPI
// WSKSendTo(
// 	IN PWSK_SOCKET WskSocket,
// 	IN PVOID Buffer,
// 	IN ULONG BufferSize,
// 	__in_opt PSOCKADDR RemoteAddress
// 	);

LONG
NTAPI
WSKSendTo_NBL(
	IN PWSK_SOCKET WskSocket,
	IN PNET_BUFFER_LIST NetBufferList,
	IN ULONG BufferOffset,
	__in_opt PSOCKADDR RemoteAddress
	);

NTSTATUS
NTAPI
WSKBind(
	IN PWSK_SOCKET WskSocket,
	IN PSOCKADDR LocalAddress
	);

#endif // HAVE_WFP_LOOPBACK_SUPPORT

#endif // __LO_SEND
