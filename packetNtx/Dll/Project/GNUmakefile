# Makefile for cygwin gcc
# Nate Lawson <nate@rootlabs.com>

# OPTFLAGS = -g -DDBG 
OPTFLAGS = -O -mwin32
# I am suspicious of -O2 since it hosed wpcap.dll. To be safe, use -O only


CFLAGS = -Wall -DWIN32_LEAN_AND_MEAN -I ../../../common -shared ${OPTFLAGS} -I..
LDFLAGS = -Wl,--high-entropy-va -Wl,--out-implib,libpacket.a
OBJS = ../Packet32.o ../AdInfo.o
LIBS = -lws2_32 -lversion

Packet.dll: ${OBJS}
	${CC} ${CFLAGS} ${LDFLAGS} -o Packet.dll ../Packet.def ${OBJS} ${LIBS}

.c.o:
	${CC} ${CFLAGS} -o $*.o -c $<

clean:
	${RM} ${OBJS} libpacket.a Packet.dll

install: Packet.dll
	cp Packet.dll c:/winnt/system32
