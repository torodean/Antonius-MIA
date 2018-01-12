//============================================================================
// Name        : MIAmisc.cpp
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Created on  : January 8, 2018
// Description : This file is for miscellaneous functions in hte MIA program that don't belong elsewhere.
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MIAmisc.h"
#include "MIAprogram.h"


//Main constructor for the Misc class.
Misc::Misc(){
	//Chuck Norris can read all encrypted data, because nothing can hide from Chuck Norris.
}

//Main deconstructor for the Misc class.
Misc::~Misc(){
	//Chuck Norris can write to ROM.
}

//Takes a file as an input and prints an input number of random lines from it. 
void Misc::printRandomLinesFromFile(bool useDefaultPath, int numberOfLines){
	Program prog;
	
	std::string fileName;
	std::string fullPath;
	
	//Checks the user for where the file is located.
	if (useDefaultPath){
		std::cout << "...Please enter an input file: ";
		getline(std::cin, fileName);
		fullPath = prog.getDefaultInputFilePath() + fileName;
		prog.blankLine();
	} else {
		std::cout << "...Please enter an input file (full path included): ";
		getline(std::cin, fileName);
		fullPath = fileName;
		prog.blankLine();
	}
	
	//grabs the file.
	std::ifstream file(fullPath,std::ifstream::in);
	
	//Checks if the file exists and runs the code.
	if (file.good()){
		std::string line;
		std::vector<std::string> lines;

		while(std::getline(file,line)){
			//std::cout << line << std::endl;
			lines.push_back(line);
		}
		
		int listSize = lines.size();
		srand(time(NULL));
		int randomNum = 0;
		
		for(int i=0; i<numberOfLines; i++){
			randomNum = rand() % listSize;
			std::cout << lines[randomNum] << std::endl;
		}
	} else {
		std::cout << "ERROR 404: File not found." << std::endl;
	}
}