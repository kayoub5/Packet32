/**
 * Packet32 has no copyright assigned and is placed in the Public Domain.
 * No warranty is given; refer to the files LICENSE-WTFPL, COPYING.Npcap and
 * COPYING.WinPcap within this package.
 */

#ifndef __WPCAPNAMES_H_EED6D131C6DB4dd696757D219977A7E5
#define __WPCAPNAMES_H_EED6D131C6DB4dd696757D219977A7E5


//
// Original names
//
//  NOTE: 
//  - please do not use prefix names longer than 70 chars. 
//  - the following characters are surely accepted in the prefixes:  "[A-Z][a-z][0-9]_-',"   
//
#ifdef NPF_NPCAP_RUN_IN_WINPCAP_MODE
	#define NPF_DRIVER_NAME							"NPF"												///< (HHH) Packet.dll
	#define NPF_DRIVER_NAME_WIDECHAR				L"NPF"												///< (HHH) Packet.dll
	#define NPF_DRIVER_NAME_SMALL					"npf"												///< (HHH) Packet.dll
	#define NPF_DRIVER_NAME_SMALL_WIDECHAR			L"npf"												///< (HHH) Packet.dll
#else
	#define NPF_DRIVER_NAME							"NPCAP"												///< (HHH) Packet.dll
	#define NPF_DRIVER_NAME_WIDECHAR				L"NPCAP"											///< (HHH) Packet.dll
	#define NPF_DRIVER_NAME_SMALL					"npcap"												///< (HHH) Packet.dll
	#define NPF_DRIVER_NAME_SMALL_WIDECHAR			L"npcap"											///< (HHH) Packet.dll
#endif

#define NPF_DRIVER_NAME_SMALL_WIFI				NPF_DRIVER_NAME_SMALL "_wifi"
#define NPF_DRIVER_NAME_SMALL_WIDECHAR_WIFI		NPF_DRIVER_NAME_SMALL_WIDECHAR L"_wifi"

// Used as a logo string in NPFInstall
#define NPF_DRIVER_NAME_NORMAL					"Npcap"												///< (HHH) Packet.dll
#define NPF_DRIVER_NAME_NORMAL_WIDECHAR			L"Npcap"											///< (HHH) Packet.dll

// Used as the registry software key name
#define NPF_SOFT_REGISTRY_NAME					"NPCAP"												///< (HHH) Packet.dll
#define NPF_SOFT_REGISTRY_NAME_WIDECHAR			L"NPCAP"											///< (HHH) Packet.dll

#define NPF_ORGAN_NAME							"INSECURE"											///< (HHH) Packet.dll
#define NPF_ORGAN_NAME_WIDECHAR					L"INSECURE"											///< (HHH) Packet.dll

//
// Derived strings
//

// Used in packetWin7\Dll and the driver
#define NPF_DEVICE_NAMES_PREFIX					NPF_DRIVER_NAME "_"     								///< (AAA) packet.dll
#define NPF_DEVICE_NAMES_PREFIX_WIDECHAR		NPF_DRIVER_NAME_WIDECHAR L"_"     						///< (AAA) used by the NPF driver, that does not accept the TEXT(a) macro correctly.
#define NPF_DEVICE_NAMES_PREFIX_WIFI			NPF_DEVICE_NAMES_PREFIX "WIFI_"
#define NPF_DEVICE_NAMES_PREFIX_WIDECHAR_WIFI	NPF_DEVICE_NAMES_PREFIX_WIDECHAR L"WIFI_"

// Used in packetWin7\Dll
#define FAKE_NDISWAN_ADAPTER_NAME				"\\Device\\" NPF_DRIVER_NAME "_GenericDialupAdapter"	///< (CCC) Name of a fake ndiswan adapter that is always available on 2000/XP/2003, used to capture NCP/LCP packets
#define FAKE_NDISWAN_ADAPTER_DESCRIPTION		"Adapter for generic dialup and VPN capture"			///< (DDD) Description of a fake ndiswan adapter that is always available on 2000/XP/2003, used to capture NCP/LCP packets

// Used in packetWin7\Dll, NPFInstall and the driver
#define NPF_SERVICE_DESC						NPF_DRIVER_NAME_NORMAL " Packet Driver (" NPF_DRIVER_NAME ")"						///< (FFF) packet.dll
#define NPF_SERVICE_DESC_WIDECHAR				NPF_DRIVER_NAME_NORMAL_WIDECHAR L" Packet Driver (" NPF_DRIVER_NAME_WIDECHAR L")"	///< (FFF) packet.dll
#define NPF_SERVICE_DESC_TCHAR					_T(NPF_DRIVER_NAME_NORMAL) _T(" Packet Driver (") _T(NPF_DRIVER_NAME) _T(")")		///< (FFF) packet.dll
#define NPF_SERVICE_DESC_WIFI					NPF_SERVICE_DESC " (WiFi version)"
#define NPF_SERVICE_DESC_WIDECHAR_WIFI			NPF_SERVICE_DESC_WIDECHAR L" (WiFi version)"
#define NPF_SERVICE_DESC_TCHAR_WIFI				NPF_SERVICE_DESC_TCHAR _T(" (WiFi version)")

// Used in packetWin7\Dll
#define NPF_DRIVER_COMPLETE_DEVICE_PREFIX		"\\Device\\" NPF_DEVICE_NAMES_PREFIX					///< (III) packet.dll
// Used in packetWin7\Dll
#define NPF_DRIVER_COMPLETE_PATH				"system32\\drivers\\" NPF_DRIVER_NAME ".sys"			///< (LLL) packet.dll


//
// WinPcap Global Registry Key
//
#define WINPCAP_GLOBAL_KEY						"SOFTWARE\\CaceTech\\WinPcapOem"
#define WINPCAP_GLOBAL_KEY_WIDECHAR				L"SOFTWARE\\CaceTech\\WinPcapOem"
#define WINPCAP_INSTANCE_KEY					WINPCAP_GLOBAL_KEY "\\" NPF_DRIVER_NAME
#define WINPCAP_INSTANCE_KEY_WIDECHAR			WINPCAP_GLOBAL_KEY_WIDECHAR	L"\\" NPF_DRIVER_NAME_WIDECHAR
#define MAX_WINPCAP_KEY_CHARS					512

//
// Subkeys names
//
#define NPF_DEVICES_PREFIX_REG_KEY				"NpfDeviceNamesPrefix"		///< (AAA) 
#define NPF_DEVICES_PREFIX_REG_KEY_WC			L"NpfDeviceNamesPrefix"		///< (AAA) used by the NPF driver, that does not accept the TEXT(a) macro correctly.
#define NPF_FAKE_NDISWAN_ADAPTER_NAME_REG_KEY	"NdiswanAdapterName"		///< (CCC) packet.dll
#define NPF_FAKE_NDISWAN_ADAPTER_DESC_REG_KEY	"NdiswanAdapterDescription"	///< (DDD) packet.dll
#define NPF_SERVICE_DESC_REG_KEY				"NpfServiceDescription"		///< (FFF) packet.dll
#define NPF_DRIVER_NAME_REG_KEY					"NpfDriverName"				///< (HHH) packet.dll
#define NPF_DRIVER_COMPLETE_DEVICE_PREFIX_REG_KEY "NpfCompleteDriverPrefix"	///< (III) packet.dll
#define NPF_DRIVER_COMPLETE_PATH_REG_KEY		"NpfDriverCompletePath"		///< (LLL) 

#endif //__WPCAPNAMES_H_EED6D131C6DB4dd696757D219977A7E5

