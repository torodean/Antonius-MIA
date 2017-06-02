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

//Main program constructor.
Program::Program() : VERSION("0.002"){
	
}

//Main program deconstructor.
Program::~Program(){
	
}

//Displays the MIA splash screen.
void Program::splash(){
	std::cout << "" << std::endl;
	std::cout << ".........................................................." << std::endl;
	std::cout << "...       |||      |||  ||||||||||      ||||     TM    ..." << std::endl;
	std::cout << "...       ||||    ||||      ||         ||  ||          ..." << std::endl;
	std::cout << "...       || ||  || ||      ||        ||||||||         ..." << std::endl;
	std::cout << "...       ||  ||||  ||      ||       ||      ||        ..." << std::endl;
	std::cout << "...       ||   ||   ||  ||||||||||  ||        ||       ..." << std::endl;
	std::cout << ".........................................................." << std::endl;
	std::cout << "................... TERMINAL INTERFACE ..................." << std::endl;
	std::cout << "... Multiple Integrated Applications -- Version: " + VERSION + " ..." << std::endl;
	std::cout << "..........     Programmer: Antonius Torode      .........." << std::endl;
	std::cout << ".........................................................." << std::endl;
}

//Displays a blank line surrounded by dots - used for formatting.
void Program::blankDots(){
	std::cout << "...                                                    ..." << std::endl;
}

//Displays an introductory greeting to the user.
void Program::intro(){
	blankDots();
	std::cout << "... Greetings! I am MIA.                               ..." << std::endl;
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
	int output=31415;
	
	if(input == "help"){
		output = 0;
	} 
	return output;
}

//Displays a list of valid commands and what they do to the user.
void Program::help(){
	std::cout << "... A list of valid commands and a brief summary.      ..." << std::endl;
}

//Takes the input command by the user and runs the corresponding feature.
void Program::performCommand(std::string input){
	for(int i=0; input[i]; i++){
		input[i] = std::tolower(input[i]);
	}
	int in = commandToInputVar(input);
	
	switch( in ){
		case 0: //corresponds to the help command
			help();
			break;		
		default:
			std::cout << "... Invalid Command Entered.                           ..." << std::endl;
			break;
	}
}

//Informs the user of the help feature and asks for a command.
void Program::helpMessage(){
	blankDots();
	std::cout << "... You can type 'help' for a list of valid commands.  ..." << std::endl;
	std::cout << "... Please enter a command.                            ..." << std::endl;
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