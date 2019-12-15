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
#include <vector>

using std::string;
using std::vector;

class Program{
	private:
		const string VERSION = "0.144";
		
		//Variables that can be set in the MIAConfig file.
		bool verboseMode = false;
		bool MIATerminalMode = true;
		string defaultInputFilePath = "Resources/InputFiles/";
		string defaultCryptFilePath = "Resources/EncryptedFiles/";
		string defaultDecryptFilePath = "Resources/DecryptedFiles/";
		string excuseFilePath = "Resources/Excuses.txt";
		string workoutsFilePath = "Resources/InputFiles/workouts.txt";
		string workoutOutputFilePath = "Resources/OutputFiles/workout.txt";
		string defaultButtonCombination = "1234567T";
		vector<int> buttonCombinationCoordsX = {};
		vector<int> buttonCombinationCoordsY = {};
		int WoWMailboxSendLetterLocationX = 270;
		int WoWMailboxSendLetterLocationY = 650;
		int WoWMailboxFirstLetterLocationX = 55;
		int WoWMailboxFirstLetterLocationY = 265;
		int WoWMailboxLootLetterLocationX = 675;
		int WoWMailboxLootLetterLocationY = 600;
		int WoWMailboxDeleteLetterLocationX = 700;
		int WoWMailboxDeleteLetterLocationY = 650;
		int WoWFishBotStartX = 725;
		int WoWFishBotStartY = 360;
		int WoWFishBotEndX = 1230;
		int WoWFishBotEndY = 495;
		int WoWFishBotIncrement = 40;
		int WoWFishBotNumOfCasts = 10000;
		int WoWFishBotDelay = 10000;
		int CenterHairPixelX = 927;
		int CenterHairPixelY = 476;
		int CenterHairColorR = 182;
		int CenterHairColorG = 172;
		int CenterHairColorB = 169;
		
	public:
		Program();
		~Program();
		
		//Initializes and returns private program variables.
		string getDefaultInputFilePath();
		void setDefaultInputFilePath(string input);
		string getDefaultCryptFilePath();
		void setDefaultCryptFilePath(string input);
		string getDefaultDecryptFilePath();
		void setDefaultDecryptFilePath(string input);
		string getWorkoutsFilePath();
		void setExcuseFilePath(string input);
		string getExcuseFilePath();
		void setWorkoutsFilePath(string input);
		void initializeSettings(bool printSettings);
		void setVerboseMode(string value);
		bool getVerboseMode();
		void setMIATerminalMode(string value);
		bool getMIATerminalMode();
		void setWorkoutOutputFilePath(string input);
		string getWorkoutOutputFilePath();
		void setDefaultButtonCombination(string input);
		string getDefaultButtonCombination();

		//Initializes and returns private WoW variables.
		void setMIAVariable(string variable, string value);
		void setWoWMailboxSendLetterLocation(char coord, string value);
		void setWoWMailboxLootLetterLocation(char coord, string value);
		void setWoWMailboxDeleteLetterLocation(char coord, string value);
		void setWoWMailboxFirstLetterLocation(char coord, string value);
		int getWoWMailboxSendLetterLocation(char coord);
		int getWoWMailboxLootLetterLocation(char coord);
		int getWoWMailboxDeleteLetterLocation(char coord);
		int getWoWMailboxFirstLetterLocation(char coord);
		void setWoWFishBotSpace(string data, string value);
		int getWoWFishBotSpace(string data);
		
		//Initializes and returns private PokeMMO variables.
		void setCenterHairPixelLocation(char coord, string value);
		void setCenterHairColor(char color, string value);
		int getCenterHairPixelLocation(char coord);
		int getCenterHairColor(char color);

		//Program related functions.
		void terminal(string defaultCommand = "");
		bool formOfYes(string input);
		void blankDots();
		void splash();
		void intro();
		void standby(string defaultCommand);
		void helpMessage();
		void blankLine();
		string getMIAVersion();
		void performCommand(string input);
		int commandToInputVar(string input);
		void help();
		void helpPrime();
		void helpNet();
		bool excuse();
		int randomInt(int start, int end, int seed, bool useTime);
		string getRandomLineOfFile(string fileName);
		void test();
		
		//Error related functions
		void returnError(int errorCode, string details = "");
		void errorInfo(int error);
		void errorInfoRun(bool all);
		
		//Misc functions.
		int findCharInString(string input, char c);
		bool is_digits(const string &str);
		string removeCharInString(string str, char c);
		string today();
		void terminalCommand(string command);
		bool inputRoll(string input);
		vector<string> delimiterString(string input, string delimiter);
};
#endif