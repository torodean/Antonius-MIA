#============================================================================
# Name        : Makefile
# Author      : Antonius Torode
# Copyright   : This file can be used under the conditions of Antonius' 
#				 General Purpose License (AGPL).
# Description : Makefile for the MIA program
#============================================================================

# the compiler to use.
CC=g++

# options I'll pass to the compiler.
CFLAGS=-c -Wall -std=c++14

#Libraries to include
LDFLAGS=-lgdi32

#make all - for compiling on Windows
all: MIA

#make the object files on a Windows machine
MIA: MIAMain.o MIAProgram.o MIACommands.o D3CEncrypt.o D3CEncryptPW.o D3CMath.o MIAEncrypt.o MIAMisc.o WinKeys.o
	$(CC) MIAMain.o MIAProgram.o MIACommands.o D3CEncrypt.o D3CEncryptPW.o D3CMath.o MIAEncrypt.o MIAMisc.o WinKeys.o -o MIA $(LDFLAGS)

#make the object files on a Linux machine.
linux: MIAMain.o MIAProgram.o MIACommands.o D3CEncrypt.o D3CEncryptPW.o D3CMath.o MIAEncrypt.o MIAMisc.o
	$(CC) MIAMain.o MIAProgram.o MIACommands.o D3CEncrypt.o D3CEncryptPW.o D3CMath.o MIAEncrypt.o MIAMisc.o -o MIA

MIAMain.o: MIAMain.cpp MIAProgram.h
	$(CC) $(CFLAGS) MIAMain.cpp

MIAProgram.o: MIAProgram.cpp MIAProgram.h D3CEncrypt.h MIACommands.h MIAEncrypt.h
	$(CC) $(CFLAGS) MIAProgram.cpp

MIACommands.o: MIACommands.cpp MIAProgram.h D3CEncrypt.h D3CEncryptPW.h MIACommands.h D3CMath.h MIAEncrypt.h
	$(CC) $(CFLAGS) MIACommands.cpp

D3CEncrypt.o: D3CEncrypt.cpp D3CEncrypt.h
	$(CC) $(CFLAGS) D3CEncrypt.cpp

D3CEncryptPW.o: D3CEncryptPW.cpp D3CEncrypt.h D3CEncryptPW.h
	$(CC) $(CFLAGS) D3CEncryptPW.cpp

D3CMath.o: D3CMath.cpp D3CMath.h
	$(CC) $(CFLAGS) D3CMath.cpp

MIAEncrypt.o: MIAEncrypt.cpp MIAEncrypt.h MIAProgram.h
	$(CC) $(CFLAGS) MIAEncrypt.cpp

WinKeys.o: WinKeys.cpp WinKeys.h MIAProgram.h
	$(CC) $(CFLAGS) WinKeys.cpp

MIAMisc.o: MIAMisc.cpp MIAMisc.h
	$(CC) $(CFLAGS) MIAMisc.cpp

#make clean - removes object files.
clean:
	rm -f *o MIA.*

#make obj_clean - For removing only the object files but keeping the executable.
cleanup:
	rm -f *o MIA.exe.*
