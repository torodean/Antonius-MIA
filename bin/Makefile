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

# Libraries to include
LDFLAGS=-lgdi32 -lNetapi32

# Multithreading support
TFLAGS=-lpthread

# make all - for compiling on Windows
all: MIA

# make the object files on a Windows machine
MIA: MIAMain.o MIAProgram.o MIACommands.o D3CEncrypt.o D3CEncryptPW.o D3CMath.o MIAEncrypt.o MIAMisc.o WinKeys.o LOLANetUse.o MIAMusic.o
	$(CC) MIAMain.o MIAProgram.o MIACommands.o D3CEncrypt.o D3CEncryptPW.o D3CMath.o MIAEncrypt.o MIAMisc.o WinKeys.o LOLANetUse.o MIAMusic.o -o MIA $(LDFLAGS)

# make the object files on a Linux machine.
linux: MIAMain.o MIAProgram.o MIACommands.o D3CEncrypt.o D3CEncryptPW.o D3CMath.o MIAEncrypt.o MIAMisc.o MIAMusic.o
	$(CC) MIAMain.o MIAProgram.o MIACommands.o D3CEncrypt.o D3CEncryptPW.o D3CMath.o MIAEncrypt.o MIAMisc.o MIAMusic.o -o MIA $(TFLAGS)
	
# make the object files for release.
release: MIAMain.o MIAProgram.o MIACommands.o D3CEncrypt.o D3CEncryptPW.o D3CMath.o MIAEncrypt.o MIAMisc.o WinKeys.o LOLANetUse.o MIAMusic.o
	$(CC) MIAMain.o MIAProgram.o MIACommands.o D3CEncrypt.o D3CEncryptPW.o D3CMath.o MIAEncrypt.o MIAMisc.o WinKeys.o LOLANetUse.o MIAMusic.o -o MIA $(LDFLAGS)
	rm -rfv ../Release/
	rm -rfv ../MIA\ R*
	mkdir ../Release/
	cp -rfv MIA.exe ../Release/
	cp -fv ../dlls/c* ../Release/
	cp -fv ../dlls/g* ../Release/
	cp -rfv Resources/ ../Release/Resources/
	cp -fv ../Documentation/MIAManual.pdf ../Release/MIAManual.pdf
	tar -czvf ../MIA\ Release.tar.gz ../Release/*

MIAMain.o: MIAMain.cpp MIAProgram.h
	$(CC) $(CFLAGS) MIAMain.cpp

MIAProgram.o: MIAProgram.cpp MIAProgram.h D3CEncrypt.h MIACommands.h MIAEncrypt.h
	$(CC) $(CFLAGS) MIAProgram.cpp

MIACommands.o: MIACommands.cpp MIAProgram.h D3CEncrypt.h D3CEncryptPW.h MIACommands.h D3CMath.h MIAEncrypt.h LOLANetUse.h MIAMusic.h
	$(CC) $(CFLAGS) MIACommands.cpp

D3CEncrypt.o: D3CEncrypt.cpp D3CEncrypt.h
	$(CC) $(CFLAGS) D3CEncrypt.cpp

D3CEncryptPW.o: D3CEncryptPW.cpp D3CEncrypt.h D3CEncryptPW.h
	$(CC) $(CFLAGS) D3CEncryptPW.cpp

D3CMath.o: D3CMath.cpp D3CMath.h
	$(CC) $(CFLAGS) D3CMath.cpp

MIAEncrypt.o: MIAEncrypt.cpp MIAEncrypt.h
	$(CC) $(CFLAGS) MIAEncrypt.cpp

WinKeys.o: WinKeys.cpp WinKeys.h MIAProgram.h
	$(CC) $(CFLAGS) WinKeys.cpp

MIAMisc.o: MIAMisc.cpp MIAMisc.h
	$(CC) $(CFLAGS) MIAMisc.cpp
	
MIAMusic.o: MIAMusic.cpp MIAMusic.h
	$(CC) $(CFLAGS) MIAMusic.cpp
	
LOLANetUse.o: LOLANetUse.cpp LOLANetUse.h
	$(CC) $(CFLAGS) LOLANetUse.cpp

#make clean - removes object files.
clean:
	rm -fv *o MIA.*

#make obj_clean - For removing only the object files but keeping the executable.
cleanup:
	rm -fv *o MIA.exe.*
