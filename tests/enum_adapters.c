/*
 * Simple program to enumerate the adapters found by Win10Pcap.
 *
 * Ref: https://github.com/SoftEtherVPN/Win10Pcap
 *
 * Put this file in directory of "<Win10Pcap-root>/Packet_dll"
 * and do:
 *
 *  cl -nologo -W3 -Zi -Ot -DWIN32 -DWIN32COM_CPP -MTd -GF -GS -EHsc -RTCs -RTCu -RTCc
 *     -Fe./enum_adapters.exe enum_adapters.c -link
 *     -nologo -debug Packet.lib user32.lib ws2_32.lib version.lib
 *     winmm.lib iphlpapi.lib advapi32.lib
 *
 *  (yes, all on one line).
 *
 * G. Vanem <gvanem@yahoo.no> 2015.
 */
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "Packet32.c"

static void print_sl_adapter_info_list (const char *indent, const struct SL_ADAPTER_INFO_LIST *sl);
static void print_sl_adapter_info (const char *indent, const struct SL_ADAPTER_INFO *info);

int main (int argc, char **argv)
{
  SU      *su;
  SE_LIST *o;
  UINT     i;

  DllMain (NULL, DLL_PROCESS_ATTACH, NULL);

  printf ("PacketLibraryVersion(): %s\n", PacketLibraryVersion());
  printf ("PacketGetDriverVersion(): %s\n", PacketGetDriverVersion());

  su = OpenSuBasicAdapter();

  if (!su)
     return (1);

  print_sl_adapter_info_list ("  ", &su->AdapterInfoList);

  o = SuGetAdapterList (su);

  for (i = 0; i < SE_LIST_NUM(o); i++)
  {
    SU_ADAPTER_LIST *d = SE_LIST_DATA (o, i);

    printf ("Adapter: %d\n", i);
    printf ("  Name:          '%.*s'\n", sizeof(d->Name)-1, d->Name);
    printf ("  Name_Replaced: '%.*s'\n", sizeof(d->Name_Replaced)-1, d->Name_Replaced);
    printf ("  SortKey:       '%.*s'\n", sizeof(d->SortKey)-1, d->SortKey);
    printf ("  Guid:          '%.*s'\n", sizeof(d->Guid)-1, d->Guid);
    print_sl_adapter_info ("    ", &d->Info);
  }
  SuFree (su);
  return (0);
}

static void print_sl_adapter_info_list (const char *indent, const struct SL_ADAPTER_INFO_LIST *sl)
{
  printf (indent);
  printf ("Signature:     0x%08X\n", sl->Signature);

  printf (indent);
  printf ("SeLowVersion:  0x%04X\n", sl->SeLowVersion);

  printf (indent);
  printf ("EnumCompleted: %u\n", sl->EnumCompleted);

  printf (indent);
  printf ("NumAdapters:   %u\n", sl->NumAdapters);
}

static void print_sl_adapter_info (const char *indent, const struct SL_ADAPTER_INFO *info)
{
  printf (indent);
  printf ("AdapterId:     '%.*ws'\n",
          sizeof(info->AdapterId)/sizeof(info->AdapterId[0])-1, info->AdapterId);

  printf (indent);
  printf ("MacAddress:    %02X:%02X:%02X:%02X:%02X:%02X\n",
          info->MacAddress[0], info->MacAddress[1], info->MacAddress[2],
          info->MacAddress[3], info->MacAddress[4], info->MacAddress[5]);

  printf (indent);
  printf ("MtuSize:       %u\n", info->MtuSize);

  printf (indent);
  printf ("FriendlyName:  '%.*s'\n", sizeof(info->FriendlyName)-1, info->FriendlyName);

  printf (indent);
  printf ("SupportsVLanHw: %d\n", info->SupportsVLanHw);
}

