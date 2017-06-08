//============================================================================
// Name        : MIAcommands.h
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Description : Header file for MIAcommands.cpp
//============================================================================

#ifndef __COMMANDS_H__
#define __COMMANDS_H__

class Commands{
	private:
	public:
		Commands();
		~Commands();
		void d0s1CryptRunner();
		void d0s1DeCryptRunner();
		void d0s2CryptRunner();
		void d0s2DeCryptRunner();
		void collatzRunner();
		void stringAdditionRunner();
		void stringMultiplyRunner();
		void stringSubtractionRunner();
};
#endif