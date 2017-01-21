# The WinPcap packet capture library


**Short Intro:**

WinPcap is unmaintained. The [WinPcap Developer's Pack](http://www.winpcap.org/devel.htm) (aka WpdPack) is not only behind WinPcap (WinPcap is version is 4.1.3, Developer's Pack is 4.1.2) it also only offers 32 bit gcc-compatible libraries.
Namely `libpacket.a` and `libwpcap.a`.
So if you're developing with MinGW or Cygwin, you're basically screwed. At least if you care about x64.


Anyways I created this port to come after this. Mainly for myself, but, whatever. Feel free to use it for your own projects as well.


**TL;DR build instructions:**

1. Clone the repo

2. Open file `winpcap\install\release procedures.txt` and follow steps 18. - 22.

3. Done

**Note: The linker flag --high-entropy-va I added in both GNUmakefiles is for x64 only! Remove them when you're building for x86!**