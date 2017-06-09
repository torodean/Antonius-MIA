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
	//Chuck Norris can take a screenshot of his blue screen.
}

//Main program deconstructor.
Program::~Program(){
	//When Chuck Norris throws exceptions, it's across the room.
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
		default: //defaults to an unrecognized command.
			std::cout << "... Invalid Command Entered.                                               ..." << std::endl;
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
	std::cout << "... collatz       | Produces a collatz sequence based on a specified starting integer." << std::endl;
	std::cout << "... crypt -d0s1   | Encrypts a string using the d0s1 algorithm." << std::endl;
	std::cout << "... crypt -d0s2   | Encrypts a string using the d0s2 algorithm." << std::endl;
	std::cout << "... decrypt -d0s1 | De-crypts a string using the d0s1 algorithm." << std::endl;
	std::cout << "... decrypt -d0s2 | De-crypts a string using the d0s2 algorithm." << std::endl;
	std::cout << "... digitsum      | Returns the sum of the digits within an integer of any size." << std::endl;
	std::cout << "... factors       | Returns the number of factors within an integer." << std::endl;
	std::cout << "... lattice       | Returns total lattice paths to the bottom right corner of an n x m grid." << std::endl;
	std::cout << "... multiply      | Multiplies two integers of any length." << std::endl;
	std::cout << "... palindrome    | Determines if a positive integer is palindrome." << std::endl;
	std::cout << "... prime         | Determines if a positive integer is prime or not." << std::endl;
	std::cout << "... prime -f      | Determines all of the prime factors of a positive integer." << std::endl;
	std::cout << "... prime -n      | Calculates the n'th prime number up to a maximum number of 2147483647." << std::endl;
	std::cout << "... prime -n -p   | Creates a file of all prime numbers up to a maximum number of 2147483647." << std::endl;
	std::cout << "... prime -n -c   | Clears the file created by 'prime -n -p'." << std::endl;
	std::cout << "... subtract      | Finds the difference between two integers of any length." << std::endl;
	std::cout << "... triangle      | Determines if a number is a triangle number or not." << std::endl;
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



