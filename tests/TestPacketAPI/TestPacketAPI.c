/**
 * Packet32 has no copyright assigned and is placed in the Public Domain.
 * No warranty is given; refer to the files LICENSE-WTFPL, COPYING.Npcap and
 * COPYING.WinPcap within this package.
 */

#include <stdio.h>
#include <Packet32.h>

// cl -nologo -Wall -I"C:\Users\Ali\projects\Packet32\Common" -Fe./TestPacketAPI.exe TestPacketAPI.c -link /LIBPATH:"C:\Users\Ali\projects\Packet32\x64\Debug" libPacket.lib

// gcc -Wall -Wextra -pedantic -Wno-unused-parameter -I/c/Users/Ali/projects/Packet32/Common -o TestPacketAPI-MinGW.exe TestPacketAPI.c -lpacket

// XXX - add wpcapnames/config.h stuff here too

int main (int argc, char **argv)
{
  printf("Packet API test application. Packet API version:%s\n\n", PacketGetVersion());
  // printf("PacketLibraryVersion(): %s\n", PacketLibraryVersion());
  printf("PacketGetVersion(): %s\n", PacketGetVersion());
  printf("PacketGetDriverVersion(): %s\n", PacketGetDriverVersion());
  printf("PacketGetDriverName(): %s\n", PacketGetDriverName());
  return 0;
}