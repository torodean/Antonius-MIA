//============================================================================
// Name        : MIAprogram.h
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Description : MIA settings and functions related to the MIA program.
//============================================================================

#ifndef __MIAPROGRAM_H__
#define __MIAPROGRAM_H__

#include <string>

class Program{
	private:
		const std::string VERSION;
	public:
		Program();
		~Program();
		void terminal();
		void blankDots();
		void splash();
		void intro();
		void standby();
		void helpMessage();
		void blankLine();
		std::string getMIAVersion();
		void performCommand(std::string input);
		int commandToInputVar(std::string input);
		void help();
		void helpPrime();
		bool excuse();
		int randomInt(int start, int end, int seed);
		std::string getRandomLineOfFile(std::string fileName);
		void test();
};
#endif