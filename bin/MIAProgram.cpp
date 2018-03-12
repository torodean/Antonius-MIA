//============================================================================
// Name        : MIAProgram.cpp
// Author      : Antonius Torode
// Date        : 2017
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Description : MIA settings and functions related to the MIA program.
//============================================================================

#include <iostream>
#include <string>
#include <cctype>
#include <time.h>
#include <fstream>
#include "MIAProgram.h"
#include "D3CEncrypt.h"
#include "D3CMath.h"
#include "MIACommands.h"
#include "MIAEncrypt.h"
#include <vector>
#include <algorithm>

//Main program constructor.
Program::Program(){
	//Chuck Norris can take a screen shot of his blue screen.
	initializeSettings(false);	
}

//Main program deconstructor.
Program::~Program(){
	//When Chuck Norris throws exceptions, it's across the room.
}

//Finds the index of the first "=" sign in a string.
int Program::findEqualInString(std::string input){
	int length = input.size();
	for (int i=0;i<length;i++){
		if(input[i]=='='){
			return i;
		}
	}
	return 0;
}

//function for determining if all characters in a string are digits/ints. Taken from StackOverflow.
bool Program::is_digits(const std::string &str){
    if(str.find_first_not_of("0123456789") == std::string::npos){
		return true;
	} else {
		return false;
	}
}

//Changes and returns the private variables.
void Program::setDefaultInputFilePath(std::string input){
	defaultInputFilePath = input;
}
void Program::setDefaultCryptFilePath(std::string input){
	defaultCryptFilePath = input;
}
void Program::setWoWMailboxSendLocation(char coord, std::string value){
	if (is_digits(value)){
		if(coord == 'x'){
			WoWMailboxSendLocationX = std::stoi(value);
		} else if (coord == 'y'){
			WoWMailboxSendLocationY = std::stoi(value);
		}
	} else {
		if(printConfigErrors)
			returnError(31417);
	}
}
int Program::getWoWMailboxSendLocation(char coord){
	if(coord == 'x'){
		return WoWMailboxSendLocationX;
	} else if (coord == 'y'){
		return WoWMailboxSendLocationY;
	} else {
		return 0;
	}
}
void Program::setWoWMailboxFirstLetterLocation(char coord, std::string value){
	if (is_digits(value)){
		if(coord == 'x'){
			WoWMailboxFirstLetterLocationX = std::stoi(value);
		} else if (coord == 'y'){
			WoWMailboxFirstLetterLocationY = std::stoi(value);
		}
	} else {
		if(printConfigErrors)
			returnError(31417);
	}
}

//Sets values relating to the WoWFishBotSpace.
void Program::setWoWFishBotSpace(std::string data, std::string value){
	if (is_digits(value)){
		if(data == "startX"){
			WoWFishBotStartX = std::stoi(value);
		} else if (data == "startY"){
			WoWFishBotStartY = std::stoi(value);
		} else if (data == "endX"){
			WoWFishBotEndX = std::stoi(value);
		} else if (data == "endY"){
			WoWFishBotEndY = std::stoi(value);
		} else if (data == "increment"){
			WoWFishBotIncrement = std::stoi(value);
		}  else if (data == "casts"){
			WoWFishBotNumOfCasts = std::stoi(value);
		}
	} else {
		if(printConfigErrors)
			returnError(31417);
	}
}

//Returns values relating to the WoWFishBotSpace.
int Program::getWoWFishBotSpace(std::string data){
	if(data == "startX"){
		return WoWFishBotStartX;
	} else if (data == "startY"){
		return WoWFishBotStartY;
	} else if (data == "endX"){
		return WoWFishBotEndX;
	} else if (data == "endY"){
		return WoWFishBotEndY;
	} else if (data == "increment"){
		return WoWFishBotIncrement;
	} else if (data == "casts"){
		return WoWFishBotNumOfCasts;
	}else {
		return 0;
	}
}

//Set's the variable to a value
void Program::setMIAVariable(std::string variable, std::string value){
	//Sets the variable for use in the switch statement.
	int switchVar =0;
	if (variable == "defaultInputFilePath"){
		switchVar = 1;
	} else if (variable == "defaultCryptFilePath"){
		switchVar = 2;
	} else if (variable == "WoWMailboxSendLocationX"){
		switchVar = 3;
	} else if (variable == "WoWMailboxSendLocationY"){
		switchVar = 4;
	} else if (variable == "WoWMailboxFirstLetterLocationX"){
		switchVar = 5;
	} else if (variable == "WoWMailboxFirstLetterLocationY"){
		switchVar = 6;
	} else if (variable == "WoWFishBotStartX"){
		switchVar = 7;
	} else if (variable == "WoWFishBotStartY"){
		switchVar = 8;
	} else if (variable == "WoWFishBotEndX"){
		switchVar = 9;
	} else if (variable == "WoWFishBotEndY"){
		switchVar = 10;
	} else if (variable == "WoWFishBotIncrement"){
		switchVar = 11;
	}  else if (variable == "WoWFishBotNumOfCasts"){
		switchVar = 12;
	}
	
	//Determines which variables to set.
	switch( switchVar ){
		case 1:
			setDefaultInputFilePath(value);
			break;
		case 2:
			setDefaultCryptFilePath(value);
			break;
		case 3:
			setWoWMailboxSendLocation('x',value);
			break;
		case 4:
			setWoWMailboxSendLocation('y',value);
			break;
		case 5:
			setWoWMailboxFirstLetterLocation('x',value);
			break;
		case 6:
			setWoWMailboxFirstLetterLocation('y',value);
			break;
		case 7:
			setWoWFishBotSpace("startX", value);
			break;
		case 8:
			setWoWFishBotSpace("startY", value);
			break;
		case 9:
			setWoWFishBotSpace("endX", value);
			break;
		case 10:
			setWoWFishBotSpace("endY", value);
			break;
		case 11:
			setWoWFishBotSpace("increment", value);
			break;
		case 12:
			setWoWFishBotSpace("casts", value);
			break;
		default:
			returnError(31417);
			break;
	}
}

//This function is for loading in the config file. Still in Development.
void Program::initializeSettings(bool printSettings){
	//grabs the MIAConfig file.
	std::string fileName = "../bin/Resources/MIAConfig.txt";
	std::ifstream file(fileName,std::ifstream::in);
	
	//Checks if the file exists and runs the code.
	if (file.good()){
		std::string line;
		std::vector<std::string> lines;

		//If true, print the configuration file settings.
		if (printSettings){
			std::cout << std::endl << "...Config file output: " << std::endl;
		}
		while(std::getline(file,line)){
			if (line[0] != '#' && line != "" && !line.empty() && line.size()>2){
				if(printSettings){
					std::cout << line << std::endl;
				}
				lines.push_back(line);
			}	
		}
		if(printSettings){
			std::cout << std::endl;
		}
		int size = lines.size();
		int equalSignLocation=0;
		std::string variable, value;
		for (int i=0; i<size;i++){
			equalSignLocation = findEqualInString(lines[i]);
			variable = lines[i].substr(0, equalSignLocation);
			value = lines[i].substr(equalSignLocation+1,lines[i].size()-1);
			
			//removes end of line characters from variable name and value. Fixes a bug.
			variable.erase(std::remove(variable.begin(), variable.end(), '\r'), variable.end()); 
			value.erase(std::remove(value.begin(), value.end(), '\r'), value.end());			
			
			if(printSettings){
				std::cout << "...Setting variable: " << variable << " to value '" << value << "'" << std::endl;
				printConfigErrors = true;
			}
			setMIAVariable(variable, value);
		}
	} else {
		returnError(31404);
	}
}

//Displays the MIA splash screen.
void Program::splash(){
	std::cout << "     ...................................................................." << std::endl;
	std::cout << "    ... //  ~~      |||      |||  ||||||||||      ||||     TM   ~~  \\\\ ..." << std::endl;
	std::cout << "   ... //  ~~       ||||    ||||      ||         ||  ||          ~~  \\\\ ..." << std::endl;
	std::cout << "  ... //  ~~        || ||  || ||      ||        ||||||||          ~~  \\\\ ..." << std::endl;
	std::cout << " ... //  ~~         ||  ||||  ||      ||       ||      ||          ~~  \\\\ ..." << std::endl;
	std::cout << "... //  ~~          ||   ||   ||  ||||||||||  ||        ||          ~~  \\\\ ..." << std::endl;
	std::cout << ".............................................................................." << std::endl;
	std::cout << "............................. TERMINAL INTERFACE ............................." << std::endl;
	std::cout << "............. Multiple Integrated Applications -- Version: " + VERSION + " ............." << std::endl;
	std::cout << "....................     Programmer: Antonius Torode      ...................." << std::endl;
	std::cout << ".............................................................................." << std::endl;
}

//Displays a blank line surrounded by dots - used for formatting.
void Program::blankDots(){
	std::cout << "...                                                                        ..." << std::endl;
}

//Displays an introductory greeting to the user.
void Program::intro(){
	blankDots();
	std::cout << "... Greetings! I am MIA.                                                   ..." << std::endl;
}

//The standby screen while waiting for a user input.
void Program::standby(){
	std::string input = "";
	bool exit = false;
	helpMessage();
	while(exit == false){
		getline(std::cin,input);
		blankLine();
		if(input == "exit"){
			exit = true;
		} else{
			performCommand(input);
		}
		helpMessage();
	} 
}

//Takes the user input as a string and converts it to a corresponding integer to be used in the switch case.
int Program::commandToInputVar(std::string input){
	int output=3141592;
	
	if(input == "help"){
		output = 0;
	} else if (input == "crypt -d0s1"){
		output = 1;
	} else if (input == "decrypt -d0s1"){
		output = 2;
	}else if (input == "crypt -d0s2"){
		output = 3;
	} else if (input == "decrypt -d0s2"){
		output = 4;
	} else if (input == "collatz"){
		output = 5;
	} else if (input == "add"){
		output = 6;
	} else if (input == "multiply"){
		output = 7;
	} else if (input == "subtract"){
		output = 8;
	} else if (input == "prime"){
		output = 9;
	} else if (input == "palindrome"){
		output = 10;
	} else if (input == "digitsum"){
		output = 11;
	} else if (input == "prime -f"){
		output = 12;
	} else if (input == "factors"){
		output = 13;
	} else if (input == "triangle"){
		output = 14;
	} else if (input == "lattice"){
		output = 15;
	} else if (input == "prime -n"){
		output = 16;
	} else if (input == "prime -n -p"){
		output = 17;
	} else if (input == "prime -n -c"){
		output = 18;
	} else if (input == "mc dig"){
		output = 19;
	} else if (input == "button spam"){
		output = 20;
	} else if (input == "mc explore"){
		output = 21;
	} else if (input == "prime -help" || input == "prime --help"){
		output = 22;
	} else if (input == "crypt -d0s3"){
		output = 23;
	} else if (input == "decrypt -d0s3"){
		output = 24;
	} else if (input == "button spam -t"){
		output = 25;
	} else if (input == "randfromfile"){
		output = 26;
	} else if (input == "wow dup letter"){
		output = 27;
	} else if (input == "quadratic form"){
		output = 28;
	} else if (input == "pranjal"){
		output = 29;
	} else if (input == "find mouse"){
		output = 30;	
	}  else if (input == "eyedropper"){
		output = 31;	
	} else if (input == "config"){
		output = 32;	
	} else if (input == "fishbot"){
		output = 33;
	} else if (input == "test"){
		output = 999999;
	}
	return output;
}

//Takes the input command by the user and runs the corresponding feature.
void Program::performCommand(std::string input){
	for(int i=0; input[i]; i++){
		input[i] = std::tolower(input[i]);
	}
	int in = commandToInputVar(input);
	
	//Loads in the commands class which contains all of the individual command runners.
	Commands cmd;
	
	switch( in ){
		case 0: //corresponds to the help command.
			help();
			break;	
		case 1:	//corresponds to the crypt -d0s1 command.
			cmd.d0s1CryptRunner();
			break;
		case 2:	//corresponds to the decrypt -d0s1 command.
			cmd.d0s1DeCryptRunner();
			break;
		case 3:	//corresponds to the crypt -d0s2 command.
			cmd.d0s2CryptRunner();
			break;
		case 4:	//corresponds to the decrypt -d0s2 command.
			cmd.d0s2DeCryptRunner();
			break;
		case 5:	//corresponds to the collatz command.
			cmd.collatzRunner();
			break;
		case 6:	//corresponds to the add command.
			cmd.stringAdditionRunner();
			break;
		case 7:	//corresponds to the multiply command.
			cmd.stringMultiplyRunner();
			break;
		case 8:	//corresponds to the subtract command.
			cmd.stringSubtractionRunner();
			break;
		case 9:	//corresponds to the prime command.
			cmd.isPrimeRunner();
			break;
		case 10: //corresponds to the palindrome command.
			cmd.isPalindromeRunner();
			break;
		case 11: //corresponds to the digitsum command.
			cmd.sumOfDigitsRunner();
			break;
		case 12: //corresponds to the prime -f command.
			cmd.primeFactorsRunner();
			break;
		case 13: //corresponds to the factors command.
			cmd.numberOfFactorsRunner();
			break;
		case 14: //corresponds to the triangle command.
			cmd.isTriangleNumberRunner();
			break;
		case 15: //corresponds to the lattice command.
			cmd.latticePathsRunner();
			break;
		case 16: //corresponds to the prime -n command.
			cmd.primeNRunner();
			break;
		case 17: //corresponds to the prime -n -p command.
			cmd.primeNumberNpopulateRunner();
			break;
		case 18: //corresponds to the prime -n -c command.
			cmd.primeNumberNeraseRunner();
			break;
		case 19: //corresponds to the mc dig command.
			cmd.minecraftDigRunner(); 
			break;
		case 20: //corresponds to the button spam command.
			cmd.buttonSpamRunner(false);
			break;
		case 21: //corresponds to the mc explore command.
			cmd.exploreMinecraft();
			break;
		case 22: //corresponds to the prime -help command.
			helpPrime();
			break;
		case 23:	//corresponds to the crypt -d0s3 command.
			cmd.d0s3CryptRunner();
			break;
		case 24:	//corresponds to the decrypt -d0s3 command.
			cmd.d0s3DeCryptRunner();
			break;
		case 25:	//corresponds to the button spam -t command.
			cmd.buttonSpamRunner(true);
			break;
		case 26: //corresponds to the randfromfile command.
			cmd.printRandomLinesFromFileRunner();
			break;
		case 27: //corresponds to the wow dup letter command.
			cmd.duplicateLetterRunner();
			break;
		case 28: //corresponds to the wow dup letter command.
			cmd.solveQuadraticFormulaRunner();
			break;
		case 29: //corresponds to the pranjal command.
			cmd.pranjal();
			break;
		case 30: //Corresponds to the find mouse command.
			cmd.findMouse();
			break;
		case 31: //Corresponds to the eyedropper command.
			cmd.eyedropper();
			break;
		case 32: //Corresponds to the config command.
			initializeSettings(true);
			break;
		case 33: //Corresponds to the fishbot command.
			cmd.runFishbot();
			break;
		case 999999:
			test();			
			break;			
			
		default: //defaults to an unrecognized command.
			if(excuse()){
			} else{
				std::cout << "... Invalid Command Entered.                                               ..." << std::endl;
			}
			break;
	}
}

//Displays a list of valid commands and what they do to the user.
void Program::help(){
	std::cout << "... A list of valid commands and a brief summary.                          ..." << std::endl;
	std::cout << "... Commands are NOT case sensitive.                                       ..." << std::endl;
	blankDots();
	std::cout << "... help          | Displays a valid lists of commands." << std::endl;
	std::cout << "... add           | Adds two positive integers of any length. " << std::endl;
	std::cout << "... button spam   | Spams a specified button (key press)." << std::endl;
	std::cout << "... button spam -t| Spams a specified button (key press) separated by tabs." << std::endl;
	std::cout << "... collatz       | Produces a collatz sequence based on a starting integer." << std::endl;
	std::cout << "... config        | Reloads the MIAConfig.txt file and prints the variables." << std::endl;
	std::cout << "... crypt -d0s1   | Encrypts a string using the d0s1 algorithm." << std::endl;
	std::cout << "... crypt -d0s2   | Encrypts a string using the d0s2 algorithm." << std::endl;
	std::cout << "... decrypt -d0s1 | De-crypts a string using the d0s1 algorithm." << std::endl;
	std::cout << "... decrypt -d0s2 | De-crypts a string using the d0s2 algorithm." << std::endl;
	std::cout << "... digitsum      | Returns the sum of the digits within an integer of any size." << std::endl;
	std::cout << "... eyedropper    | Returns the RGB value of the pixel located at the cursor." << std::endl;
	std::cout << "... factors       | Returns the number of factors within an integer." << std::endl;
	std::cout << "... find mouse    | Finds/Returns the coordinates of the mouse after 5 seconds." << std::endl;
	std::cout << "... lattice       | Returns lattice paths to the farthest corner of an NxM grid." << std::endl;
	std::cout << "... mc dig        | Simulates key strokes for continuous Minecraft diggigg." << std::endl;
	std::cout << "... mc explore    | Explores a Minecraft map using /tp" << std::endl;
	std::cout << "... multiply      | Multiplies two integers of any length." << std::endl;
	std::cout << "... palindrome    | Determines if a positive integer is palindrome." << std::endl;
	std::cout << "... prime -help   | Displays help defaults for prime functions." << std::endl;
	std::cout << "... quadratic form| Calculates a solution to a*x^2+b*x+c=0." << std::endl;
	std::cout << "... randfromfile  | Prints a number of random lines from a text file." << std::endl;
	std::cout << "... subtract      | Finds the difference between two integers of any length." << std::endl;
	std::cout << "... triangle      | Determines if a number is a triangle number or not." << std::endl;
	std::cout << "... wow dup letter| Duplicates a letter in WoW a specified number of times." << std::endl;
	std::cout << "... exit          | Quits MIA. " << std::endl;
}

void Program::helpPrime(){
	std::cout << "... A list of valid commands and a brief summary.                          ..." << std::endl;
	std::cout << "... Commands are NOT case sensitive.                                       ..." << std::endl;
	blankDots();
	std::cout << "... prime         | Determines if a positive integer is prime or not." << std::endl;
	std::cout << "... prime -f      | Determines all of the prime factors of a positive integer." << std::endl;
	std::cout << "... prime -n      | Calculates the n'th prime number up to a max of 2147483647." << std::endl;
	std::cout << "... prime -n -p   | Creates a file of prime #'s up to a max of 2147483647." << std::endl;
	std::cout << "... prime -n -c   | Clears the file created by 'prime -n -p'." << std::endl;
}

//Prints a random excuse some percentage of the time.
bool Program::excuse(){
	int random = randomInt(1,100, 0);
	std::string txt;
	
	if (random >= 20){	
		blankLine();
		std::cout << "...Sorry, I can't do that (Invalid command entered). " << std::endl;
		
		txt = getRandomLineOfFile("../bin/Resources/Excuses.txt");
		std::cout << "..." << txt << std::endl;
		return true;		
	}
	return false;
}

//Returns the random line of a specified text file.
std::string Program::getRandomLineOfFile(std::string fileName){
	int counter = 0;
	std::string output;
	std::ifstream file(fileName);
	
	while (getline(file, output)){
		counter++;			
	}
	file.close();
	
	std::ifstream file2(fileName);
	int random = randomInt(1,counter, 0);
	counter = 0;
	
	while (getline(file2, output)){
		counter++;
		if(counter == random){		
			return output;
		}
	}
	return "ERROR";
}

//Informs the user of the help feature and asks for a command.
void Program::helpMessage(){
	blankDots();
	std::cout << "... You can type 'help' for a list of valid commands.                      ..." << std::endl;
	std::cout << "... Please enter a command.                                                ..." << std::endl;
	blankDots();
	blankLine();
}

//Prints a blank line.
void Program::blankLine(){
	std::cout << std::endl;
}

//Main user interface for MIA.
void Program::terminal(){
	initializeSettings(false);
	splash();
	intro();
	standby();
}

//Returns the Version number of MIA.
std::string Program::getMIAVersion(){
	return VERSION;
}

//Returns a random integer between min and max.
int Program::randomInt(int min, int max, int seed){
	if(seed == 0){
		srand((unsigned)time(0)); 
	} else {
		srand(seed);
	}
	int random = min + (rand() % static_cast<int>(max - min + 1));
	return random;
}

//A function used for testing.
void Program::test(){
    std::cout << "...Starting test." << std::endl;
	
	Commands cmd;
	cmd.test();
	
	/* Testing the quadratic formula function.
	std::D3CMath math;
	std::string ans = math.solveQuadraticFormula(3,4,1);
	std::cout << ans << std::endl;
	*/
	/*
    MIAencrypt crypt(4);
    crypt.test();
	crypt.encryptFile("C:\\Users\\torodean\\test.txt", "OutputFile");
	//std::cout << "...No test function set. " << std:: endl;
    */
    std::cout << "...Finished test." << std::endl;
}

//A function used to determine if an answer is equivalent to yes.
bool Program::formOfYes(std::string input){
	if (input == "y" || input == "Y" || input == "yes" || input == "Yes" || input == "YES"){
		return true;
	} else {
		return false;
	}
}

//Returns defaultInputFilePath.
std::string Program::getDefaultInputFilePath(){
	return defaultInputFilePath;
}

//Returns defaultCryptFilePath.
std::string Program::getDefaultCryptFilePath(){
	return defaultCryptFilePath;
}

//Function used for displaying error information.
void Program::returnError(int errorCode){
	switch(errorCode){
		case 404: 
			std::cout << "...ERROR 404: File not found." << std::endl;
			break;
		case 31404:
			std::cout << "...ERROR 31404: MIAsettings file not found." << std::endl;
			break;
		case 31415:
			std::cout << "...ERROR 31415: Function still in Development." << std::endl;
			break;
		case 31416:
			std::cout << "...ERROR 31416: This feature is currently only programmed for Windows." << std::endl;
			break;
		case 31417:
			std::cout << "...ERROR 31417: Invalid Option in MIAConfig." << std::endl;
			break;
		default:
			std::cout << "...ERROR: A catastrophic Failure Occurred." << std::endl;
			break;
	}
}




