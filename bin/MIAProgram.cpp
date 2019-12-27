//============================================================================
// Name        : MIAProgram.cpp
// Author      : Antonius Torode
// Date        : 2017
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Description : MIA settings and functions related to the MIA program.
//============================================================================

#include "MIAProgram.h"
#include "D3CEncrypt.h"
#include "D3CMath.h"
#include "MIACommands.h"
#include "MIAEncrypt.h"
#include "MIASequencer.h"

#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include <time.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using std::string;
using std::remove;
using std::stoi;
using std::ifstream;
using std::vector;
using std::cout;
using std::endl;
using std::getline;
using std::cin;
using std::tolower;
using std::to_string;

//Main program constructor.
Program::Program(){
	//Chuck Norris can take a screen shot of his blue screen.
	initializeSettings(verboseMode);
}

//Main program deconstructor.
Program::~Program(){
	//When Chuck Norris throws exceptions, it's across the room.
}

//sets verboseMode.
void Program::setVerboseMode(string value){
	value = removeCharInString(value, ' ');
	if (value == "true" || value == "1"){
		verboseMode = true;
	} else {
		verboseMode = false;
	}
}

//Returns verboseMode.
bool Program::getVerboseMode(){
	return verboseMode;
}

//sets MIATerminalMode.
void Program::setMIATerminalMode(string value){
	value = removeCharInString(value, ' ');
	if (value == "true" || value == "1"){
		MIATerminalMode = true;
	} else {
		MIATerminalMode = false;
	}
}

//Returns MIATerminalMode.
bool Program::getMIATerminalMode(){
	return MIATerminalMode;
}

//Removes a specific character from a string.
string Program::removeCharInString(string str, char c){
	str.erase(remove(str.begin(), str.end(), c), str.end());
	return str;
}

//Finds the index of the first occurrence of a char in a string.
int Program::findCharInString(string input, char c){
	int length = input.size();
	for (int i=0;i<length;i++){
		if(input[i] == c){
			return i;
		}
	}
	return 0;
}

//Determines if a character is contained within a string.
bool Program::stringContainsChar(string input, char c){
	if(findCharInString(input, c) == 0)
		return false;
	return true;
}

//Separates a string into components via a delimiter.
vector<string> Program::delimiterString(string input, string delimiter){
	if(verboseMode)
		cout << "input string: " << input << endl;
	vector<string> output;
	size_t pos = 0;
	std::string item;
	while ((pos = input.find(delimiter)) != string::npos) {
		item = input.substr(0, pos);
		output.push_back(item);
		if(verboseMode)
			cout << "delimiter item: " << item << endl;
		input.erase(0, pos + delimiter.length());
	}
	output.push_back(input);
	if(verboseMode)
		cout << "delimiter item: " << input << endl;
	int outputSize = output.size();
	if(verboseMode){
		cout << "Contents of output: ";
		for(int i=0;i<outputSize;i++){
			cout << output[i];
			if(i != outputSize-1)
				cout << delimiter;
		}
		cout << endl;
	}
	return output;
}

//function for determining if all characters in a string are digits/ints. Taken from StackOverflow.
bool Program::is_digits(const string &str){
    if(str.find_first_not_of("0123456789") == string::npos){
		return true;
	} else {
		return false;
	}
}

//DEPRECATED. Replaced by getFilePath(string filePath) in version 0.146.
//Returns defaultInputFilePath.
string Program::getInputFilePath(){
	return inputFilePath;
}

//DEPRECATED. Replaced by getFilePath(string filePath) in version 0.146.
//Returns defaultCryptFilePath.
string Program::getCryptFilePath(){
	return cryptFilePath;
}

//DEPRECATED. Replaced by getFilePath(string filePath) in version 0.146.
//Returns defaultDecryptFilePath.
string Program::getDecryptFilePath(){
	return decryptFilePath;
}

//DEPRECATED. Replaced by setFilePath(string filePath, string input) in version 0.146.
//Changes and returns the private variables.
void Program::setWorkoutOutputFilePath(string input){
	workoutOutputFilePath = input;
}
//DEPRECATED. Replaced by getFilePath(string filePath) in version 0.146.
string Program::getWorkoutOutputFilePath(){
	return workoutOutputFilePath;
}
//DEPRECATED. Replaced by setFilePath(string filePath, string input) in version 0.146.
void Program::setExcuseFilePath(string input){
	excuseFilePath = input;
}
//DEPRECATED. Replaced by getFilePath(string filePath) in version 0.146.
string Program::getExcuseFilePath(){
	return excuseFilePath;
}
//DEPRECATED. Replaced by setFilePath(string filePath, string input) in version 0.146.
void Program::setInputFilePath(string input){
	inputFilePath = input;
}
//DEPRECATED. Replaced by setFilePath(string filePath, string input) in version 0.146.
void Program::setCryptFilePath(string input){
	cryptFilePath = input;
}
//DEPRECATED. Replaced by setFilePath(string filePath, string input) in version 0.146.
void Program::setDecryptFilePath(string input){
	decryptFilePath = input;
}
//DEPRECATED. Replaced by setFilePath(string filePath, string input) in version 0.146.
void Program::setWorkoutsFilePath(string input){
	workoutsFilePath = input;
}

//Sets the appropriate variables for file paths.
void Program::setFilePath(string filePath, string input){
	if(filePath == "excuseFilePath"){
		excuseFilePath = input;
	} else if(filePath == "inputFilePath"){
		inputFilePath = input;
	} else if(filePath == "cryptFilePath"){
		cryptFilePath = input;
	} else if(filePath == "decryptFilePath"){
		decryptFilePath = input;
	} else if(filePath == "workoutsFilePath"){
		workoutsFilePath = input;
	} else if(filePath == "sequencesFilePath"){
		sequencesFilePath = input;
	} else if(filePath == "workoutOutputFilePath"){
		workoutOutputFilePath = input;
	} else {
		string configLine = filePath + ": " + input;
		returnError(31419, configLine);
	}
}
//Returns the appropriate variables for file paths.
string Program::getFilePath(string filePath){
	if(filePath == "excuseFilePath"){
		return excuseFilePath;
	} else if(filePath == "inputFilePath"){
		return inputFilePath;
	} else if(filePath == "cryptFilePath"){
		return cryptFilePath;
	} else if(filePath == "decryptFilePath"){
		return decryptFilePath;
	} else if(filePath == "workoutsFilePath"){
		return workoutsFilePath;
	} else if(filePath == "sequencesFilePath"){
		return sequencesFilePath;
	} else {
		returnError(31419, filePath);
		return "";
	}
}
//DEPRECATED. Replaced by getFilePath(string filePath) in version 0.146.
string Program::getWorkoutsFilePath(){
	return workoutsFilePath;
}
void Program::setDefaultButtonCombination(string input){
	defaultButtonCombination = input;
}
string Program::getDefaultButtonCombination(){
	return defaultButtonCombination;
}
void Program::setWoWMailboxSendLetterLocation(char coord, string value){
	if (is_digits(value)){
		if(coord == 'x'){
			WoWMailboxSendLetterLocationX = stoi(value);
		} else if (coord == 'y'){
			WoWMailboxSendLetterLocationY = stoi(value);
		}
	} else {
		if(verboseMode)
			returnError(31417);
	}
}
int Program::getWoWMailboxSendLetterLocation(char coord){
	if(coord == 'x'){
		return WoWMailboxSendLetterLocationX;
	} else if (coord == 'y'){
		return WoWMailboxSendLetterLocationY;
	} else {
		return 0;
	}
}
void Program::setWoWMailboxFirstLetterLocation(char coord, string value){
	if (is_digits(value)){
		if(coord == 'x'){
			WoWMailboxFirstLetterLocationX = stoi(value);
		} else if (coord == 'y'){
			WoWMailboxFirstLetterLocationY = stoi(value);
		}
	} else {
		if(verboseMode)
			returnError(31417);
	}
}
int Program::getWoWMailboxFirstLetterLocation(char coord){
	if(coord == 'x'){
		return WoWMailboxFirstLetterLocationX;
	} else if (coord == 'y'){
		return WoWMailboxFirstLetterLocationY;
	} else {
		return 0;
	}
}
void Program::setWoWMailboxLootLetterLocation(char coord, string value){
	if (is_digits(value)){
		if(coord == 'x'){
			WoWMailboxLootLetterLocationX = stoi(value);
		} else if (coord == 'y'){
			WoWMailboxLootLetterLocationY = stoi(value);
		}
	} else {
		if(verboseMode)
			returnError(31417);
	}
}
int Program::getWoWMailboxLootLetterLocation(char coord){
	if(coord == 'x'){
		return WoWMailboxLootLetterLocationX;
	} else if (coord == 'y'){
		return WoWMailboxLootLetterLocationY;
	} else {
		return 0;
	}
}
void Program::setWoWMailboxDeleteLetterLocation(char coord, string value){
	if (is_digits(value)){
		if(coord == 'x'){
			WoWMailboxDeleteLetterLocationX = stoi(value);
		} else if (coord == 'y'){
			WoWMailboxDeleteLetterLocationY = stoi(value);
		}
	} else {
		if(verboseMode)
			returnError(31417);
	}
}
int Program::getWoWMailboxDeleteLetterLocation(char coord){
	if(coord == 'x'){
		return WoWMailboxDeleteLetterLocationX;
	} else if (coord == 'y'){
		return WoWMailboxDeleteLetterLocationY;
	} else {
		return 0;
	}
}

//Sets values relating to the WoWFishBotSpace.
void Program::setWoWFishBotSpace(string data, string value){
	if (is_digits(value)){
		if(data == "startX"){
			WoWFishBotStartX = stoi(value);
		} else if (data == "startY"){
			WoWFishBotStartY = stoi(value);
		} else if (data == "endX"){
			WoWFishBotEndX = stoi(value);
		} else if (data == "endY"){
			WoWFishBotEndY = stoi(value);
		} else if (data == "increment"){
			WoWFishBotIncrement = stoi(value);
		}  else if (data == "casts"){
			WoWFishBotNumOfCasts = stoi(value);
		}  else if (data == "delay"){
			WoWFishBotDelay = stoi(value);
		}
	} else {
		if(verboseMode)
			returnError(31417);
	}
}

//Returns values relating to the WoWFishBotSpace.
int Program::getWoWFishBotSpace(string data){
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
	} else if (data == "delay"){
		return WoWFishBotDelay;
	} else {
		return 0;
	}
}

//Returns true if a string is a reference to a valid filepath.
bool Program::variableIsFilePath(string variable){
	if (variable == "inputFilePath"
		|| variable == "cryptFilePath"
		|| variable == "decryptFilePath"
		|| variable == "workoutsFilePath"
		|| variable == "sequencesFilePath"
		|| variable == "workoutOutputFilePath"
		|| variable == "excuseFilePath"){
		return true;
	} 
	return false;
}

//Set's the variable to a value.
void Program::setMIAVariables(string variable, string value){
	//Sets the appropriate variable values.
	if (variableIsFilePath(variable)){
		setFilePath(variable, value);
	} else if (variable == "WoWMailboxSendLetterLocationX"){
		setWoWMailboxSendLetterLocation('x',value);
	} else if (variable == "WoWMailboxSendLetterLocationY"){
		setWoWMailboxSendLetterLocation('y',value);
	} else if (variable == "WoWMailboxFirstLetterLocationX"){
		setWoWMailboxFirstLetterLocation('x',value);
	} else if (variable == "WoWMailboxFirstLetterLocationY"){
		setWoWMailboxFirstLetterLocation('y',value);
	} else if (variable == "WoWFishBotStartX"){
		setWoWFishBotSpace("startX", value);
	} else if (variable == "WoWFishBotStartY"){
		setWoWFishBotSpace("startY", value);
	} else if (variable == "WoWFishBotEndX"){
		setWoWFishBotSpace("endX", value);
	} else if (variable == "WoWFishBotEndY"){
		setWoWFishBotSpace("endY", value);
	} else if (variable == "WoWFishBotIncrement"){
		setWoWFishBotSpace("increment", value);
	} else if (variable == "WoWFishBotNumOfCasts"){
		setWoWFishBotSpace("casts", value);
	} else if (variable == "WoWFishBotDelay"){
		setWoWFishBotSpace("delay", value);
	} else if (variable == "WoWMailboxLootLetterLocationX"){
		setWoWMailboxLootLetterLocation('x',value);
	} else if (variable == "WoWMailboxLootLetterLocationY"){
		setWoWMailboxLootLetterLocation('y',value);
	} else if (variable == "WoWMailboxDeleteLetterLocationX"){
		setWoWMailboxDeleteLetterLocation('x',value);
	} else if (variable == "WoWMailboxDeleteLetterLocationY"){
		setWoWMailboxDeleteLetterLocation('y',value);
	} else if (variable == "verboseMode"){
		setVerboseMode(value);
	}  else if (variable == "MIATerminalMode"){
		setMIATerminalMode(value);
	} else if (variable == "defaultButtonCombination"){
		setDefaultButtonCombination(value);
	} else {
		if(verboseMode){
			returnError(31417, variable);
		}
	}
}

//This function is for loading in the config file. Still in Development.
void Program::initializeSettings(bool printSettings){
	//grabs the MIAConfig file.
	ifstream file(MIAConfigFile,ifstream::in);
	
	//Checks if the file exists and runs the code.
	if (file.good()){
		string line;
		vector<string> lines;

		//If true, print the configuration file settings.
		if (verboseMode){
			cout << endl << "...Config file output: " << endl;
		}
		while(getline(file,line)){
			if (line[0] != '#' && line != "" && !line.empty() && line.size()>2){
				if(verboseMode){
					cout << line << endl;
				}
				lines.push_back(line);
			}	
		}
		if(verboseMode){
			cout << endl;
		}
		int size = lines.size();
		int equalSignLocation=0;
		string variable, value;
		for (int i=0; i<size;i++){
			equalSignLocation = findCharInString(lines[i], '=');
			variable = lines[i].substr(0, equalSignLocation);
			value = lines[i].substr(equalSignLocation+1,lines[i].size()-1);
			
			//removes end of line characters from variable name and value. Fixes a bug.
			variable.erase(remove(variable.begin(), variable.end(), '\r'), variable.end()); 
			value.erase(remove(value.begin(), value.end(), '\r'), value.end());			
			
			if(printSettings){
				cout << "...Setting variable: " << variable << " to '" << value << "'" << endl;
			}
			setMIAVariables(variable, value);
		}
	} else {
		if (printSettings){
			returnError(31403);
			returnError(31404);
		}
	}
}

//Displays the MIA splash screen.
void Program::printSplash(){
	cout << "     ...................................................................." << endl;
	cout << "    ... //  ~~      |||      |||  ||||||||||      ||||     TM   ~~  \\\\ ..." << endl;
	cout << "   ... //  ~~       ||||    ||||      ||         ||  ||          ~~  \\\\ ..." << endl;
	cout << "  ... //  ~~        || ||  || ||      ||        ||||||||          ~~  \\\\ ..." << endl;
	cout << " ... //  ~~         ||  ||||  ||      ||       ||      ||          ~~  \\\\ ..." << endl;
	cout << "... //  ~~          ||   ||   ||  ||||||||||  ||        ||          ~~  \\\\ ..." << endl;
	cout << ".............................................................................." << endl;
	cout << "............................. TERMINAL INTERFACE ............................." << endl;
	cout << "............. Multiple Integrated Applications -- Version: " + VERSION + " ............." << endl;
	cout << "....................     Programmer: Antonius Torode      ...................." << endl;
	cout << "....................      Compiled on: " << __DATE__ << "        ...................." << endl;
	cout << ".............................................................................." << endl;
}

//Displays a blank line surrounded by dots - used for formatting.
void Program::blankDots(){
	cout << "...                                                                        ..." << endl;
}

//Displays an introductory greeting to the user.
void Program::intro(){
	blankDots();
	cout << "... Greetings! I am MIA.                                                   ..." << endl;
}

//The standby screen while waiting for a user input.
void Program::standby(string defaultCommand){
	string input = "";
	bool exit = false;
	
	if(defaultCommand != ""){
		cout << "... I've detected a default command entered: " << defaultCommand << endl;
		blankLine();	
		performMIACommand(defaultCommand);
		blankLine();	
	}
	
	helpMessage();
	while(exit == false){
		getline(cin,input);
		blankLine();
		if(input == "exit" || input == "quit" || input == "EXIT" || input == "QUIT"){
			exit = true;
			break;
		} else{
			performMIACommand(input);
		}
		helpMessage();
	}
}

//DEPRECATED in version 0.145. Replaced by Program::inputEnum(string input).
//Takes the user input as a string and converts it to a corresponding integer to be used in the switch case.
int Program::commandToInputVar(string input){
	int output=3141592;
	
	if(input == "help"){
		output = 0;
	} else if (input == "crypt -d0s1"){
		output = 1;
	} else if (input == "decrypt -d0s1"){
		output = 2;
	} else if (input == "crypt -d0s2"){
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
	} else if (input == "eyedropper"){
		output = 31;	
	} else if (input == "config"){
		output = 32;	
	} else if (input == "fishbot"){
		output = 33;
	} else if (input == "workout"){
		output = 34;
	} else if (input == "splash"){
		output = 35;
	} else if (input == "workout -w"){
		output = 36;
	} else if (input == "net session"){
		output = 37;
	} else if (input == "net server -w"){
		output = 38;
	} else if (input == "net server -s"){
		output = 39;
	} else if (input == "wow unload"){
		output = 40;
	} else if (input == "date"){
		output = 41;
	} else if (inputRoll(input)){
		output = 999996;
	} else if (input == "error info"){
		output = 999997;
	} else if (input == "error info -a"){
		output = 999998;
	} else if (input == "test"){
		output = 999999;
	}
	return output;
}

//Determines if a string is of the format for a dice roll. i.e 1d20 or 3d8.
bool Program::inputRoll(string input){
	if(input.size() <= 5 && input.find('d') != string::npos && input.find_first_not_of("1234567890d") == string::npos){
		return true;
	}
	return false;
}

//Replaced Program::commandToInputVar(string input) in versin 0.145.
//Takes the user input as a string and converts it to a corresponding value of Program::MIAInput enum to be used in the switch case. 
Program::MIAInput Program::commandToInputEnum(string input){
	Program::MIAInput output = MIAInput::excuse;
	
	if(input == "help"){
		output = MIAInput::help;
	} else if (input == "crypt -d0s1"){
		output = MIAInput::crypt_d0s1;
	} else if (input == "decrypt -d0s1"){
		output = MIAInput::decrypt_d0s1;
	} else if (input == "crypt -d0s2"){
		output = MIAInput::crypt_d0s2;
	} else if (input == "decrypt -d0s2"){
		output = MIAInput::decrypt_d0s2;
	} else if (input == "collatz"){
		output = MIAInput::collatz;
	} else if (input == "add"){
		output = MIAInput::add;
	} else if (input == "multiply"){
		output = MIAInput::multiply;
	} else if (input == "subtract"){
		output = MIAInput::subtract;
	} else if (input == "prime"){
		output = MIAInput::prime;
	} else if (input == "palindrome"){
		output = MIAInput::palindrome;
	} else if (input == "digitsum"){
		output = MIAInput::digitsum;
	} else if (input == "prime -f"){
		output = MIAInput::prime_f;
	} else if (input == "factors"){
		output = MIAInput::factors;
	} else if (input == "triangle"){
		output = MIAInput::triangle;
	} else if (input == "lattice"){
		output = MIAInput::lattice;
	} else if (input == "prime -n"){
		output = MIAInput::prime_n;
	} else if (input == "prime -n -p" || input == "prime -p -n"){
		output = MIAInput::prime_n_p;
	} else if (input == "prime -n -c" || input == "prime -c -n"){
		output = MIAInput::prime_n_c;
	} else if (input == "mc dig"){
		output = MIAInput::mcdig;
	} else if (input == "button spam"){
		output = MIAInput::buttonspam;
	} else if (input == "mc explore"){
		output = MIAInput::mcexplore;
	} else if (input == "prime -help" || input == "prime --help"){
		output = MIAInput::prime_help;
	} else if (input == "crypt -d0s3"){
		output = MIAInput::crypt_d0s3;
	} else if (input == "decrypt -d0s3"){
		output = MIAInput::decrypt_d0s3;
	} else if (input == "button spam -t"){
		output = MIAInput::buttonspam_t;
	} else if (input == "randfromfile"){
		output = MIAInput::randfromfile;
	} else if (input == "wow dup letter"){
		output = MIAInput::wowdupletter;
	} else if (input == "quadratic form"){
		output = MIAInput::quadraticform;
	} else if (input == "pranjal"){
		output = MIAInput::pranjal;
	} else if (input == "find mouse"){
		output = MIAInput::findmouse;	
	} else if (input == "eyedropper"){
		output = MIAInput::eyedropper;
	} else if (input == "config"){
		output = MIAInput::config;		
	} else if (input == "fishbot"){
		output = MIAInput::fishbot;
	} else if (input == "workout"){
		output = MIAInput::workout;
	} else if (input == "splash"){
		output = MIAInput::splash;
	} else if (input == "workout -w"){
		output = MIAInput::workout_w;
	} else if (input == "net session"){
		output = MIAInput::netsession;
	} else if (input == "net server -w"){
		output = MIAInput::netserver_w;
	} else if (input == "net server -s"){
		output = MIAInput::netserver_s;
	} else if (input == "wow unload"){
		output = MIAInput::wowunload;
	} else if (input == "date"){
		output = MIAInput::date;
	} else if (input == "sequencer"){
		output = MIAInput::sequencer;
	} else if (inputRoll(input)){
		output = MIAInput::diceroll;
	} else if (input == "error info"){
		output = MIAInput::errorinfo;
	} else if (input == "error info -a"){
		output = MIAInput::errorinfo_a;
	} else if (input == "test"){
		output = MIAInput::test;
	}
	return output;
}

//Replaced Program::performCommand(string input) in versin 0.145.
//Takes the input command by the user and runs the corresponding feature.
void Program::performMIACommand(string input){
	for(int i=0; input[i]; i++){
		input[i] = tolower(input[i]);
	}
	Program::MIAInput in = commandToInputEnum(input);
	
	//Loads in the commands class which contains all of the individual command runners.
	Commands cmd;
	
	switch( in ){
		case MIAInput::help: //corresponds to the help command.
			printHelp();
			break;	
		case MIAInput::crypt_d0s1:	//corresponds to the crypt -d0s1 command.
			cmd.d0s1CryptRunner();
			break;
		case MIAInput::decrypt_d0s1:	//corresponds to the decrypt -d0s1 command.
			cmd.d0s1DeCryptRunner();
			break;
		case MIAInput::crypt_d0s2:	//corresponds to the crypt -d0s2 command.
			cmd.d0s2CryptRunner();
			break;
		case MIAInput::decrypt_d0s2:	//corresponds to the decrypt -d0s2 command.
			cmd.d0s2DeCryptRunner();
			break;	
		case MIAInput::collatz:	//corresponds to the collatz command.
			cmd.collatzRunner();
			break;
		case MIAInput::add:	//corresponds to the add command.
			cmd.stringAdditionRunner();
			break;
		case MIAInput::multiply:	//corresponds to the multiply command.
			cmd.stringMultiplyRunner();
			break;
		case MIAInput::subtract:	//corresponds to the subtract command.
			cmd.stringSubtractionRunner();
			break;
		case MIAInput::prime:	//corresponds to the prime command.
			cmd.isPrimeRunner();
			break;
		case MIAInput::palindrome: //corresponds to the palindrome command.
			cmd.isPalindromeRunner();
			break;
		case MIAInput::digitsum: //corresponds to the digitsum command.
			cmd.sumOfDigitsRunner();
			break;
		case MIAInput::prime_f: //corresponds to the prime -f command.
			cmd.primeFactorsRunner();
			break;
		case MIAInput::factors: //corresponds to the factors command.
			cmd.numberOfFactorsRunner();
			break;
		case MIAInput::triangle: //corresponds to the triangle command.
			cmd.isTriangleNumberRunner();
			break;
		case MIAInput::lattice: //corresponds to the lattice command.
			cmd.latticePathsRunner();
			break;
		case MIAInput::prime_n: //corresponds to the prime -n command.
			cmd.primeNRunner();
			break;
		case MIAInput::prime_n_p: //corresponds to the prime -n -p command.
			cmd.primeNumberNpopulateRunner();
			break;
		case MIAInput::prime_n_c: //corresponds to the prime -n -c command.
			cmd.primeNumberNeraseRunner();
			break;
		case MIAInput::mcdig: //corresponds to the mc dig command.
			cmd.minecraftDigRunner(); 
			break;
		case MIAInput::buttonspam: //corresponds to the button spam command.
			cmd.buttonSpamRunner(false);
			break;
		case MIAInput::mcexplore: //corresponds to the mc explore command.
			cmd.exploreMinecraft();
			break;
		case MIAInput::prime_help: //corresponds to the prime -help command.
			helpPrime();
			break;
		case MIAInput::crypt_d0s3: //corresponds to the crypt -d0s3 command.
			cmd.d0s3CryptRunner();
			break;
		case MIAInput::decrypt_d0s3: //corresponds to the decrypt -d0s3 command.
			cmd.d0s3DeCryptRunner();
			break;
		case MIAInput::buttonspam_t: //corresponds to the button spam -t command.
			cmd.buttonSpamRunner(true);
			break;
		case MIAInput::randfromfile: //corresponds to the randfromfile command.
			cmd.printRandomLinesFromFileRunner();
			break;
		case MIAInput::wowdupletter: //corresponds to the wow dup letter command.
			cmd.duplicateLetterRunner();
			break;
		case MIAInput::quadraticform: //corresponds to the quadratic form command.
			cmd.solveQuadraticFormulaRunner();
			break;
		case MIAInput::pranjal: //corresponds to the pranjal command.
			cmd.pranjal();
			break;
		case MIAInput::findmouse: //Corresponds to the find mouse command.
			cmd.findMouse();
			break;
		case MIAInput::eyedropper: //Corresponds to the eyedropper command.
			cmd.eyedropper();
			break;
		case MIAInput::config: //Corresponds to the config command.
			initializeSettings(true);
			break;
		case MIAInput::fishbot: //Corresponds to the fishbot command.
			cmd.runFishbot();
			break;
		case MIAInput::workout: //Corresponds to the workout command.
			cmd.workoutRunner(false);
			break;
		case MIAInput::splash: //Corresponds to the splash command.
			printSplash();
			break;
		case MIAInput::workout_w: //Corresponds to the workout -w command.
			cmd.workoutRunner(true);
			break;
		case MIAInput::netsession: //Corresponds to the net session command.
			cmd.runNetSessionEnum();
			break;
		case MIAInput::netserver_w: //Corresponds to the net server -w command.
			cmd.runNetServerEnum('w');
			break;
		case MIAInput::netserver_s: //Corresponds to the net server -s command.
			cmd.runNetServerEnum('s');
			break;
		case MIAInput::wowunload: //Corresponds to the wow unload command.
			cmd.unloadLetterRunner();
			break;
		case MIAInput::date: //Corresponds to the date command.
			terminalCommand("DATE");
			break;
		case MIAInput::diceroll: //Corresponds to the roll dice functions.
			cmd.rollDice(input);
			break;
		case MIAInput::sequencer: //Corresponds to the sequencer functions.
			cmd.runSequencer();
			break;
		case MIAInput::errorinfo: //Corresponds to the error info command.
			errorInfoRun(false);
			break;
		case MIAInput::errorinfo_a: //Corresponds to the error info -a command.
			errorInfoRun(true);
			break;
		case MIAInput::test: //Corresponds to the test command.
			runTest();			
			break;	
		
		case MIAInput::excuse:
		default: //defaults to an unrecognized command.
			if(useExcuse()){
			} else{
				cout << "... Invalid Command Entered.                                               ..." << endl;
			}
			break;
	}
}

//DEPRECATED in version 0.145. Replaced by performMIACommand
//Takes the input command by the user and runs the corresponding feature.
void Program::performCommand(string input){
	for(int i=0; input[i]; i++){
		input[i] = tolower(input[i]);
	}
	int in = commandToInputVar(input);
	
	//Loads in the commands class which contains all of the individual command runners.
	Commands cmd;
	
	switch( in ){
		case 0: //corresponds to the help command.
			printHelp();
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
		case 23: //corresponds to the crypt -d0s3 command.
			cmd.d0s3CryptRunner();
			break;
		case 24: //corresponds to the decrypt -d0s3 command.
			cmd.d0s3DeCryptRunner();
			break;
		case 25: //corresponds to the button spam -t command.
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
		case 34: //Corresponds to the workout command.
			cmd.workoutRunner(false);
			break;
		case 35: //Corresponds to the splash command.
			printSplash();
			break;
		case 36: //Corresponds to the splash command.
			cmd.workoutRunner(true);
			break;
		case 37: //Corresponds to the net session command.
			cmd.runNetSessionEnum();
			break;
		case 38: //Corresponds to the net server -w command.
			cmd.runNetServerEnum('w');
			break;
		case 39: //Corresponds to the net server -s command.
			cmd.runNetServerEnum('s');
			break;
		case 40: //Corresponds to the wow unload command.
			cmd.unloadLetterRunner();
			break;
		case 41: //Corresponds to the wow unload command.
			terminalCommand("DATE");
			break;
		case 999996: //Corresponds to the roll dice functions.
			cmd.rollDice(input);
			break;
		case 999997: //Corresponds to the error info command.
			errorInfoRun(false);
			break;
		case 999998: //Corresponds to the error info -a command.
			errorInfoRun(true);
			break;
		case 999999:
			runTest();			
			break;			
			
		default: //defaults to an unrecognized command.
			if(useExcuse()){
			} else{
				cout << "... Invalid Command Entered.                                               ..." << endl;
			}
			break;
	}
}

//Displays a list of valid commands and what they do to the user.
void Program::printHelp(){
	cout << "... A list of valid commands and a brief summary.                          ..." << endl;
	cout << "... Commands are NOT case sensitive.                                       ..." << endl;
	blankDots();
	cout << "... help          | Displays a valid lists of commands." << endl;
	cout << "... add           | Adds two positive integers of any length. " << endl;
	cout << "... button spam   | Spams a specified button (key press)." << endl;
	cout << "... button spam -t| Spams a specified button (key press) separated by tabs." << endl;
	cout << "... collatz       | Produces a collatz sequence based on a starting integer." << endl;
	cout << "... config        | Reloads the MIAConfig.txt file and prints the variables." << endl;
	cout << "... crypt -d0s1   | Encrypts a string using the d0s1 algorithm." << endl;
	cout << "... crypt -d0s2   | Encrypts a string using the d0s2 algorithm." << endl;
	cout << "... decrypt -d0s1 | De-crypts a string using the d0s1 algorithm." << endl;
	cout << "... decrypt -d0s2 | De-crypts a string using the d0s2 algorithm." << endl;
	cout << "... digitsum      | Returns the sum of the digits within an integer of any size." << endl;
	cout << "... error info    | Returns information regarding an error code." << endl;
	cout << "... error info -a | Returns information regarding all error codes." << endl;
	cout << "... eyedropper    | Returns the RGB value of the pixel located at the cursor." << endl;
	cout << "... factors       | Returns the number of factors within an integer." << endl;
	cout << "... find mouse    | Finds/Returns the coordinates of the mouse after 5 seconds." << endl;
	cout << "... fishbot       | A working and configurable WoW fishbot." << endl;
	cout << "... lattice       | Returns lattice paths to the farthest corner of an NxM grid." << endl;
	cout << "... mc dig        | Simulates key strokes for continuous Minecraft digging." << endl;
	cout << "... mc explore    | Explores a Minecraft map using the minecraft /tp command." << endl;
	cout << "... multiply      | Multiplies two integers of any length." << endl;
	cout << "... net -help     | Displays net functions available within MIA." << endl;
	cout << "... palindrome    | Determines if a positive integer is palindrome." << endl;
	cout << "... prime -help   | Displays help defaults for prime functions." << endl;
	cout << "... quadratic form| Calculates a solution to a*x^2+b*x+c=0." << endl;
	cout << "... randfromfile  | Prints a number of random lines from a text file." << endl;
	cout << "... subtract      | Finds the difference between two integers of any length." << endl;
	cout << "... triangle      | Determines if a number is a triangle number or not." << endl;
	cout << "... workout       | Generates a workout from the values defined in workouts.txt." << endl;
	cout << "... workout -w    | Generates a weekly workout and outputs it to a file." << endl;
	cout << "... wow dup letter| Duplicates a letter in WoW a specified number of times." << endl;
	cout << "... wow unload    | Unloads a number of letters from the WoW inbox." << endl;
	cout << "... exit          | Quits MIA. " << endl;
}

//Provides information regarding the prime number functions
void Program::helpPrime(){
	cout << "... A list of various valid commands and a brief summary.                  ..." << endl;
	cout << "... Commands are NOT case sensitive.                                       ..." << endl;
	blankDots();
	cout << "... prime         | Determines if a positive integer is prime or not." << endl;
	cout << "... prime -f      | Determines all of the prime factors of a positive integer." << endl;
	cout << "... prime -n      | Calculates the n'th prime number up to a max of 2147483647." << endl;
	cout << "... prime -n -p   | Creates a file of prime #'s up to a max of 2147483647." << endl;
	cout << "... prime -n -c   | Clears the file created by 'prime -n -p'." << endl;
}

void Program::helpNet(){
	cout << "... A list of various valid commands and a brief summary.                  ..." << endl;
	cout << "... Commands are NOT case sensitive.                                       ..." << endl;
	blankDots();
	cout << "... net session   | Provides info about sessions established on a server." << endl;
	cout << "... net server -s | Lists all servers that are visible in a domain." << endl;
	cout << "... net server -w | Lists all workstations that are visible in a domain." << endl;
	//cout << "... net wkst      | Returns info about the configuration of a workstation." << endl;
	//cout << "... net remote    | Retrieves the optional features a remote system supports." << endl;
	//cout << "... net user      | Retrieves information about all user accounts on a server." << endl;
	//cout << "... net user -i   | Retrieves information about a user account on a server." << endl;
	//cout << "... net modals    | Retrieves global information for all users and global groups." << endl;
	//cout << "... net display   | Returns computer, or group account information." << endl;
}

//Prints a random excuse some percentage of the time.
bool Program::useExcuse(){
	int random = randomInt(1,100, 0, true);
	string txt;
	
	if (random >= 20){	
		blankLine();
		cout << "...Sorry, I can't do that (Invalid command entered). " << endl;
		
		txt = getRandomLineOfFile(excuseFilePath);
		cout << "..." << txt << endl;
		return true;		
	}
	return false;
}

//Returns the random line of a specified text file.
string Program::getRandomLineOfFile(string fileName){
	int counter = 0;
	string output;
	ifstream file(fileName);
	
	while (getline(file, output)){
		counter++;			
	}
	file.close();
	
	ifstream file2(fileName);
	int random = randomInt(1,counter, 0, true);
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
	cout << "... You can type 'help' for a list of valid commands.                      ..." << endl;
	cout << "... Please enter a command.                                                ..." << endl;
	blankDots();
	blankLine();
}

//Prints a blank line.
void Program::blankLine(){
	cout << endl;
}

//Main user interface for MIA.
void Program::terminal(string defaultCommand){
	initializeSettings(verboseMode);
	printSplash();
	intro();
	if (defaultCommand == ""){
		standby("");
	} else {
		standby(defaultCommand);
	}
}

//Returns the Version number of MIA.
string Program::getMIAVersion(){
	return VERSION;
}

//Returns a random integer between min and max.
int Program::randomInt(int min, int max, int seed, bool useTime){
	if(max < min){
		if(verboseMode)
			cout << "...Max value smaller than min, adjusting appropriately by returning min." << endl;
		return min;
	}
	if(verboseMode)
		cout << "...Calculating random value between " << min << " and " << max << "." << endl;
	if(seed == 0){
		srand((unsigned)time(0)); 
	} else if (useTime){
		srand((unsigned)time(0) + seed); 
	} else {
		srand(seed);
	}
	int random = min + (rand() % static_cast<int>(max - min + 1));
	if(verboseMode)
		cout << "...random value is " << random << "." << endl;
	return random;
}

//A function used to determine if an answer is equivalent to yes.
bool Program::formOfYes(string input){
	if (input == "y" || input == "Y" || input == "yes" || input == "Yes" || input == "YES" || input == "sure" || input == "Sure"){
		return true;
	} else {
		return false;
	}
}

//Function used for displaying error information.
void Program::returnError(int errorCode, string details){
	switch(errorCode){
		case 404: 
			cout << "...ERROR 404: File not found." << endl;
			break;
		case 31403:
			cout << "...ERROR 31403: MIAConfig.MIA file not found." << endl;
			break;
		case 31404:
			cout << "...ERROR 31404: FATAL: File not found." << endl;
			break;
		case 31415:
			cout << "...ERROR 31415: Function still in Development." << endl;
			break;
		case 31416:
			cout << "...ERROR 31416: This feature is currently only programmed for Windows." << endl;
			break;
		case 31417:
			cout << "...ERROR 31417: Invalid Option in MIAConfig: " << details << ".  Using default value." << endl;
			break;
		case 31418:
			cout << "...ERROR 31418: Nothing set for testing." << endl;
			break;
		case 31419:
			cout << "...ERROR 31419: Issue setting MIA variable: " << details << endl;
			break;
		case 31420:
			cout << "...ERROR 31420: Issue with MIASequenceFile. " << endl;
			break;
		case 31421:
			cout << "...ERROR 31421: MIASequences File not found! " << endl;
			break;
		case 31422:
			cout << "...ERROR 31422: Invalid Option in MIASequences: " << details << endl;
			break;
		case 31423:
			cout << "...ERROR 31423: Error finding mapped value: " << details << endl;
			break;
		case 31424:
			cout << "...ERROR 31424: Invalid Character input: " << details << endl;
			break;
		default:
			cout << "...ERROR: A catastrophic Failure Occurred." << endl;
			break;
	}
}

//Inquires for an error code to gather info about.
void Program::errorInfoRun(bool all){
	blankDots();
	int error = 0;
	if(all){
		errorInfo(-1);
	} else {
		cout << "...Please enter an error code: ";
		cin >> error;
		cin.ignore();
		errorInfo(error);
	}
}

//Returns information about a specified known error or all of the known errors.
void Program::errorInfo(int error){
	blankDots();
	switch(error){
		case 0:
			cout << "...0: ERROR_SUCCESS - The operation completed successfully." << endl;
			break;
		case 5:
			cout << "...5: ERROR_ACCESS_DENIED" << endl;
			break;
		case 31:
			cout << "...31: ERROR_GEN_FAILURE - A device attached to the system is not functioning." << endl;
			break;
		case 53:
			cout << "...53: ERROR_BAD_NETPATH - The network path was not found." << endl;
			break;
		case 87:
			cout << "...87: ERROR_INVALID_PARAMETER - The parameter is incorrect." << endl;
			break;
		case 124:
			cout << "...124: ERROR_INVALID_LEVEL - The system call level is not correct." << endl;
			break;
		case 404: 
			cout << "...404: File not found." << endl;
			break;
		case 1326:
			cout << "...1326: ERROR_LOGON_FAILURE - The user name or password is incorrect." << endl;
			break;
		case 1722:
			cout << "...1722: RPC_S_SERVER_UNAVAILABLE - The RPC server is unavailable." << endl;
			break;
		case 2221:
			cout << "...2221: NERR_UserNotFound - The user name could not be found." << endl;
			break;
		case 6118:
			cout << "...6118: ERROR_NO_BROWSER_SERVERS_FOUND" << endl;
			cout << "...    - The list of servers for this workgroup is not currently available." << endl;
			break;
		case 31403:
			cout << "...31403: MIAsettings file not found." << endl;
			break;
		case 31404:
			cout << "...31404: FATAL: File not found." << endl;
			break;
		case 31415:
			cout << "...31415: Function still in Development." << endl;
			break;
		case 31416:
			cout << "...31416: This feature is currently only programmed for Windows." << endl;
			break;
		case 31417:
			cout << "...31417: Invalid Option in MIAConfig: invalidVariable. Using default value." << endl;
			break;
		case 31418:
			cout << "...31418: Nothing set for testing." << endl;
			break;
		case 31419:
			cout << "...ERROR 31419: Issue setting MIA variable. " << endl;
			break;
		case 31420:
			cout << "...ERROR 31420: Issue with MIASequenceFile. " << endl;
			break;
		case 31421:
			cout << "...ERROR 31421: MIASequences File not found! " << endl;
			break;
		case 31422:
			cout << "...ERROR 31422: Invalid Option in MIASequences. " << endl;
			break;
		case 31423:
			cout << "...ERROR 31423: Error finding mapped value. " << endl;
			break;
		case 31424:
			cout << "...ERROR 31424: Invalid Character input. " << endl;
			break;
		default:
			cout << "...Invalid or unknown error code entered." << endl;
			cout << "...Full List of programmed error codes follow." << endl;
			blankDots();
			cout << "...UNKNOWN: A catastrophic Failure Occurred." << endl;
			cout << "...0: ERROR_SUCCESS - The operation completed successfully." << endl;
			cout << "...5: ERROR_ACCESS_DENIED" << endl;
			cout << "...31: ERROR_GEN_FAILURE - A device attached to the system is not functioning." << endl;
			cout << "...53: ERROR_BAD_NETPATH - The network path was not found." << endl;
			cout << "...87: ERROR_INVALID_PARAMETER - The parameter is incorrect." << endl;
			cout << "...124: ERROR_INVALID_LEVEL - The system call level is not correct." << endl;
			cout << "...404: File not found." << endl;
			cout << "...1326: ERROR_LOGON_FAILURE - The user name or password is incorrect." << endl;
			cout << "...1722: RPC_S_SERVER_UNAVAILABLE - The RPC server is unavailable." << endl;
			cout << "...2221: NERR_UserNotFound - The user name could not be found." << endl;
			cout << "...6118: ERROR_NO_BROWSER_SERVERS_FOUND" << endl;
			cout << "...    - The list of servers for this workgroup is not currently available." << endl;
			cout << "...31403: MIAsettings file not found." << endl;
			cout << "...31404: FATAL: File not found." << endl;
			cout << "...31415: Function still in Development." << endl;
			cout << "...31416: This feature is currently only programmed for Windows." << endl;
			cout << "...31417: Invalid Option in MIAConfig. Using default value." << endl;
			cout << "...31418: Nothing set for testing." << endl;
			break;
	}
}

//Returns the date for today.
string Program::today(){
	std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
	string month = to_string(now->tm_mon + 1);
	string day = to_string(now->tm_mday);
	string year = to_string(now->tm_year + 1900);
    string todaysDate =  month + "-" + day + "-" + year;
	return todaysDate;
}

//Runs a terminal command.
void Program::terminalCommand(string command){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	
	system(command.c_str());
	blankLine();

	#else
	returnError(31416);
	#endif
}



//A function used for testing.
//This should be placed at the end of the file for easy accessibility. 
void Program::runTest(){
    cout << "...Starting test." << endl;
	
	Commands cmd;
	cmd.runTest();

	
	/*
    MIAencrypt crypt(4);
    crypt.runTest();
	crypt.encryptFile("C:\\Users\\torodean\\test.txt", "OutputFile");
	//cout << "...No test function set. " << endl;
    */
    cout << "...Finished test." << endl;
}





