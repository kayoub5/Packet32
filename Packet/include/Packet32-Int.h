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
