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

#make all
all: MIA

#make the object files
MIA: MIAmain.o MIAprogram.o MIAcommands.o D3CEncrypt.o D3CEncryptPW.o D3CMath.o MIAEncrypt.o WinKeys.o
	$(CC) MIAmain.o MIAprogram.o MIAcommands.o D3CEncrypt.o D3CEncryptPW.o D3CMath.o MIAEncrypt.o WinKeys.o -o MIA
	
MIAmain.o: MIAmain.cpp MIAprogram.h
	$(CC) $(CFLAGS) MIAmain.cpp
	
MIAprogram.o: MIAprogram.cpp MIAprogram.h D3CEncrypt.h MIAcommands.h MIAEncrypt.h
	$(CC) $(CFLAGS) MIAprogram.cpp
	
MIAcommands.o: MIAcommands.cpp MIAprogram.h D3CEncrypt.h D3CEncryptPW.h MIAcommands.h D3CMath.h MIAEncrypt.h
	$(CC) $(CFLAGS) MIAcommands.cpp
	
D3CEncrypt.o: D3CEncrypt.cpp D3CEncrypt.h
	$(CC) $(CFLAGS) D3CEncrypt.cpp
	
D3CEncryptPW.o: D3CEncryptPW.cpp D3CEncrypt.h D3CEncryptPW.h
	$(CC) $(CFLAGS) D3CEncryptPW.cpp
	
D3CMath.o: D3CMath.cpp D3CMath.h
	$(CC) $(CFLAGS) D3CMath.cpp
	
MIAEncrypt.o: MIAEncrypt.cpp MIAEncrypt.h MIAprogram.h
	$(CC) $(CFLAGS) MIAEncrypt.cpp
	
WinKeys.o: WinKeys.cpp WinKeys.h
	$(CC) $(CFLAGS) WinKeys.cpp
	
#make clean - removes object files.
clean:
	rm -f *o MIA