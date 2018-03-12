//============================================================================
// Name        : MIAProgram.h
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
		const std::string VERSION = "0.034";
		bool printConfigErrors = false;
		std::string defaultInputFilePath = "../bin/Resources/InputFiles/";
		std::string defaultCryptFilePath = "../bin/Resources/EncryptedFiles/";
		int WoWMailboxSendLocationX = 270;
		int WoWMailboxSendLocationY = 650;
		int WoWMailboxFirstLetterLocationX = 0;
		int WoWMailboxFirstLetterLocationY = 0;
		int WoWFishBotStartX = 0;
		int WoWFishBotStartY = 0;
		int WoWFishBotEndX = 0;
		int WoWFishBotEndY = 0;
		int WoWFishBotIncrement = 0;
		int WoWFishBotNumOfCasts = 1000;
		
	public:
		Program();
		~Program();
		
		//Initializes and returns private variables.
		std::string getDefaultInputFilePath();
		void setDefaultInputFilePath(std::string input);
		std::string getDefaultCryptFilePath();
		void setDefaultCryptFilePath(std::string input);
		void initializeSettings(bool printSettings);
		void setMIAVariable(std::string variable, std::string value);
		void setWoWMailboxSendLocation(char coord, std::string value);
		int getWoWMailboxSendLocation(char coord);
		void setWoWMailboxFirstLetterLocation(char coord, std::string value);
		void setWoWFishBotSpace(std::string data, std::string value);
		int getWoWFishBotSpace(std::string data);

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
		
		//Misc functions.
		int findEqualInString(std::string input);
		bool is_digits(const std::string &str);
};
#endif