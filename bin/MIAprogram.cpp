//============================================================================
// Name        : MIAprogram.cpp
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Description : MIA settings and functions related to the MIA program.
//============================================================================

#include <iostream>
#include <string>
#include "MIAprogram.h"

Program::Program() : VERSION("0.002"){
	
}

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
	while(exit == false){
		helpMessage();
		getline(std::cin,input);
		std::cout << "You entered: " << input << " ...gg!" << std::endl;
		if(input == "exit"){
			exit = true;
		}
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