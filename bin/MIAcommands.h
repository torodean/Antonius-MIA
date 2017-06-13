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
		
		//Functions adapted to work from the old D3C Program.
		void d0s1CryptRunner();
		void d0s1DeCryptRunner();
		void d0s2CryptRunner();
		void d0s2DeCryptRunner();
		void collatzRunner();
		void stringAdditionRunner();
		void stringMultiplyRunner();
		void stringSubtractionRunner();
		void isPrimeRunner();
		void isPalindromeRunner();
		void sumOfDigitsRunner();
		void primeFactorsRunner();
		void numberOfFactorsRunner();
		void isTriangleNumberRunner();
		void latticePathsRunner();
		void primeNRunner();
		void primeNumberNpopulateRunner();
		void primeNumberNeraseRunner();
		
		//Functions adapted to work from the LOLA Program.
};
#endif