//============================================================================
// Name        : MIAprogram.cpp
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Description : MIA settings and functions related to the MIA program.
//============================================================================

#include <iostream>
#include <string>
#include <cctype>
#include "MIAprogram.h"
#include "D3CEncrypt.h"
#include "MIAcommands.h"

//Main program constructor.
Program::Program() : VERSION("0.023"){
	
}

//Main program deconstructor.
Program::~Program(){
	
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
	} else if (input == ""){
		output = 9;
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
		case 0: //corresponds to the help command
			help();
			break;	
		case 1:	//corresponds to the crypt -d0s1 command
			cmd.d0s1CryptRunner();
			break;
		case 2:	//corresponds to the decrypt -d0s1 command
			cmd.d0s1DeCryptRunner();
			break;
		case 3:	//corresponds to the crypt -d0s2 command
			cmd.d0s2CryptRunner();
			break;
		case 4:	//corresponds to the decrypt -d0s2 command
			cmd.d0s2DeCryptRunner();
			break;
		case 5:	//corresponds to the collatz command
			cmd.collatzRunner();
			break;
		case 6:	//corresponds to the add command
			cmd.stringAdditionRunner();
			break;
		case 7:	//corresponds to the multiply command
			cmd.stringMultiplyRunner();
			break;
		case 8:	//corresponds to the subtract command
			cmd.stringSubtractionRunner();
		default: //defaults to an unrecognized command
			std::cout << "... Invalid Command Entered.                                               ..." << std::endl;
			break;
	}
}

//Displays a list of valid commands and what they do to the user.
void Program::help(){
	std::cout << "... A list of valid commands and a brief summary.                          ..." << std::endl;
	std::cout << "... Commands are NOT case sensitive.                                       ..." << std::endl;
	blankDots();
	std::cout << "... help          | Displays a valid lists of commands. " << std::endl;
	std::cout << "... add           | Adds two positive integers of any length. " << std::endl;
	std::cout << "... crypt -d0s1   | Encrypts a string using the d0s1 algorithm. " << std::endl;
	std::cout << "... crypt -d0s2   | Encrypts a string using the d0s2 algorithm. " << std::endl;
	std::cout << "... decrypt -d0s1 | De-crypts a string using the d0s1 algorithm. " << std::endl;
	std::cout << "... decrypt -d0s2 | De-crypts a string using the d0s2 algorithm. " << std::endl;
	std::cout << "... collatz       | Produces a collatz sequence based on a specified starting integer." << std::endl;
	std::cout << "... multiply      | Multiplies two integers of any length." << std::endl;
	std::cout << "... subtract      | Finds the difference between two integers of any length." << std::endl;
	std::cout << "... exit          | Quits MIA. " << std::endl;
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
	splash();
	intro();
	standby();
}

//Returns the Version number of MIA.
std::string Program::getMIAVersion(){
	return VERSION;
}

//Writes a string of data to a file.
void Program::writeToFile(std::string data, std::string folder, std::string filename){
	
}



