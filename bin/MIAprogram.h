//============================================================================
// Name        : MIAprogram.h
// Author      : Antonius Torode
// Date        : 2017
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Description : MIA settings and functions related to the MIA program.
//============================================================================

#include <string>
#ifndef __MIAPROGRAM_H__
#define __MIAPROGRAM_H__

#include <string>

class Program{
	private:
		const std::string VERSION = "0.030";
		std::string defaultInputFilePath = "../bin/Resources/InputFiles/";
		std::string defaultCryptFilePath = "../bin/Resources/EncryptedFiles/";
	public:
		Program();
		~Program();
		
		//Initializes and returns private variables.
		std::string getDefaultInputFilePath();
		std::string getDefaultCryptFilePath();
		void initializeSettings(bool printSettings);

		//Program related functions.
		void terminal();
		bool formOfYes(std::string input);
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
		
		//Error related functions
		void returnError(int errorCode);
};
#endif