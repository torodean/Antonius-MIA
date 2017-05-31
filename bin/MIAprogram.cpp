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

//Displays an introductory greeting to the user.
void intro(){
	
}

//Displays the Standy screen that informs the user of the help feature.
coid standby(){
	
}

//Main user interface for MIA.
void Program::terminal(){
	splash();
	
}

std::string Program::getMIAVersion(){
	return VERSION;
}