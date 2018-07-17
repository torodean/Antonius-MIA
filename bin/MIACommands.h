//============================================================================
// Name        : MIAcommands.h
// Author      : Antonius Torode
// Date        : 2017
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Description : Header file for MIAcommands.cpp
//============================================================================

#ifndef __COMMANDS_H__
#define __COMMANDS_H__
#include "MIAProgram.h"

class Commands{
	private:
	public:
		Commands();
		~Commands();
		
		Program prog;
		
		//Functions adapted to work from the old D3C Program.
		void d0s1CryptRunner();
		void d0s1DeCryptRunner();
		void d0s2CryptRunner();
		void d0s2DeCryptRunner();
		void d0s3CryptRunner();
		void d0s3DeCryptRunner();
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
		void printRandomLinesFromFileRunner();
		void solveQuadraticFormulaRunner();
		
		//Functions adapted to work from the LOLA Program.
		void runNetSessionEnum();
		void runNetServerEnum(char mode);
		void runNetWkstaGetInfo();
		void runNetRemoteComputerSupports();
		void runNetUserEnum();
		void runNetUserGetInfo();
		void runNetUserModalsGet();
		void runNetQueryDisplayInformation();
		
		//Functions adapted to work from the old VKK program.
		//Currently only useful on Windows.
		void minecraftDigRunner();
		void buttonSpamRunner(bool enableTab);
		void exploreMinecraft();
		void duplicateLetterRunner();
		void unloadLetterRunner();
		void findMouse();
		void eyedropper();
		//void runFishbot();
		
		//Misc functions
		void pranjal();
		void test();
		void workoutRunner(bool weekly);
		int rollDice(string input);
};
#endif