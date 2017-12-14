/**
 * Packet32 has no copyright assigned and is placed in the Public Domain.
 * No warranty is given; refer to the files LICENSE-WTFPL, COPYING.Npcap and
 * COPYING.WinPcap within this package.
 */

//
// Internal constants
//

// The following is used to check the adapter name in PacketOpenAdapterNPF and prevent 
// opening of firewire adapters 
#define FIREWIRE_SUBSTR L"1394"

#ifdef HAVE_NPFIM_API
#include "NpfImExt.h"
#endif //HAVE_NPFIM_API

#ifdef __MINGW32__
#ifdef __MINGW64__
#include <ntddndis.h>
#else /*__MINGW64__*/
#include <ddk/ntddndis.h>
#endif /*__MINGW64__*/
#else /*__MINGW32__*/
#pragma warning( push )
#pragma warning( disable : 4201 )
#include <ntddndis.h>
#pragma warning( pop )
#endif /*__MINGW32__*/

/*!
  \brief Linked list item containing one of the IP addresses associated with an adapter.
*/
typedef struct _NPF_IF_ADDRESS_ITEM
{
	npf_if_addr Addr;			///< IP address
	struct _NPF_IF_ADDRESS_ITEM *Next; ///< Pointer to the next item in the linked list.
}
	NPF_IF_ADDRESS_ITEM, *PNPF_IF_ADDRESS_ITEM;

/*!
  \brief Contains comprehensive information about a network adapter.

  This structure is filled with all the accessory information that the user can need about an adapter installed
  on his system.
*/
typedef struct _ADAPTER_INFO  
{
	struct _ADAPTER_INFO *Next;				///< Pointer to the next adapter in the list.
	CHAR Name[ADAPTER_NAME_LENGTH + 1];		///< Name of the device representing the adapter.
	CHAR Description[ADAPTER_DESC_LENGTH + 1];	///< Human understandable description of the adapter
	UINT MacAddressLen;						///< Length of the link layer address.
	UCHAR MacAddress[MAX_MAC_ADDR_LENGTH];	///< Link layer address.
	NetType LinkLayer;						///< Physical characteristics of this adapter. This NetType structure contains the link type and the speed of the adapter.
	PNPF_IF_ADDRESS_ITEM pNetworkAddresses;///< Pointer to a linked list of IP addresses, each of which specifies a network address of this adapter.
	UINT Flags;								///< Adapter's flags. Tell if this adapter must be treated in a different way, using the Netmon API or the dagc API.
}
ADAPTER_INFO, *PADAPTER_INFO;


//
// Internal functions
//
VOID PacketLoadLibrariesDynamically();
void PacketPopulateAdaptersInfoList();
BOOL PacketGetFileVersion(LPTSTR FileName, PCHAR VersionBuff, UINT VersionBuffLen);
PADAPTER_INFO PacketFindAdInfo(PCHAR AdapterName);
BOOLEAN PacketUpdateAdInfo(PCHAR AdapterName);
BOOLEAN IsFireWire(TCHAR *AdapterDesc);
LPADAPTER PacketOpenAdapterNPF(PCHAR AdapterName);

#ifdef __cplusplus
extern "C" {
#endif
HMODULE LoadLibrarySafe(LPCTSTR lpFileName);
#ifdef __cplusplus
}
#endif

// 
// Definitions and functions specific to the CACETech airpcap API
//
#ifdef HAVE_AIRPCAP_API
typedef PCHAR (*AirpcapGetLastErrorHandler)(PAirpcapHandle Handle);
typedef BOOL (*AirpcapGetDeviceListHandler)(AirpcapDeviceDescription **AllDevsP, PCHAR Ebuf);		///< prototype used to dynamically load the dag dll
typedef VOID (*AirpcapFreeDeviceListHandler)(AirpcapDeviceDescription *AllDevsP);					///< prototype used to dynamically load the dag dll
typedef PAirpcapHandle (*AirpcapOpenHandler)(PCHAR DeviceName, PCHAR Ebuf);							///< prototype used to dynamically load the dag dll	
typedef VOID (*AirpcapCloseHandler)(PAirpcapHandle Handle);											///< prototype used to dynamically load the dag dll
typedef BOOL (*AirpcapGetLinkTypeHandler)(PAirpcapHandle Handle, AirpcapLinkType* LinkLayer);		///< prototype used to dynamically load the dag dll
typedef BOOL (*AirpcapSetKernelBufferHandler)(PAirpcapHandle Handle, ULONG Size);					///< prototype used to dynamically load the dag dll
typedef BOOL (*AirpcapSetFilterHandler)(PAirpcapHandle Handle, void *Instructions, UINT Len);		///< prototype used to dynamically load the dag dll
typedef BOOL (*AirpcapGetMacAddressHandler)(PAirpcapHandle Handle, CHAR **MacAddress);				///< prototype used to dynamically load the dag dll
typedef BOOL (*AirpcapSetMinToCopyHandler)(PAirpcapHandle Handle, ULONG Bytes);						///< prototype used to dynamically load the dag dll
typedef BOOL (*AirpcapGetReadEventHandler)(PAirpcapHandle Handle, HANDLE* PReadEvent);				///< prototype used to dynamically load the dag dll
typedef BOOL (*AirpcapReadHandler)(PAirpcapHandle Handle, PUCHAR BufferToFill, ULONG BufSize, PULONG ReceievedBytes);	///< prototype used to dynamically load the dag dll
typedef BOOL (*AirpcapGetStatsHandler)(PAirpcapHandle Handle, AirpcapStats *Stats);					///< prototype used to dynamically load the dag dll
typedef BOOL (*AirpcapWriteHandler)(PAirpcapHandle Handle, PCHAR TxPacket, ULONG PacketLen);		///< prototype used to dynamically load the dag dll

#endif // HAVE_AIRPCAP_API
