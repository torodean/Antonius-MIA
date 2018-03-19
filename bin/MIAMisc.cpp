//============================================================================
// Name        : MIAmisc.cpp
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Created on  : January 8, 2018
// Description : This file is for miscellaneous functions in hte MIA program that don't belong elsewhere.
//============================================================================

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MIAMisc.h"


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
		prog.returnError(41404);
	}
}

//Returns a shuffled string.
std::string Misc::shuffleString(std::string input){
	std::string output = input;
	std::random_shuffle(output.begin(), output.end());
	return output;
}

//Manages input file lines.
std::string Misc::getBeforeEqualSign(std::string line){
	int equalSignLocation = prog.findEqualInString(line);
	
	if(prog.getVerboseMode())
		std::cout << "...stringBeforeEqual: " << line.substr(0, equalSignLocation) << std::endl;
	
	return line.substr(0, equalSignLocation);
}
std::string Misc::getBetweenEqualAndSemiColon(std::string line){
	int equalSignLocation = prog.findEqualInString(line);
	int semiColonLocation = prog.findSemiColonInString(line);
	
	//First remove everything after the semi colon sign. Then keep everything after the equal sign.
	line = line.substr(0,semiColonLocation);
	line = line.substr(equalSignLocation+1,line.size()-1);
	
	if(prog.getVerboseMode())
		std::cout << "...stringBetweenEqualAndSemiColon: " << line << std::endl;
	
	return line;
}
std::string Misc::getAfterSemiColon(std::string line){
	int semiColonLocation = prog.findSemiColonInString(line);
	
	if(prog.getVerboseMode())
		std::cout << "...stringAfterSemiColon: " << line.substr(semiColonLocation+1,line.size()-1) << std::endl;
	
	return line.substr(semiColonLocation+1,line.size()-1);
}

//convert input file line to proper format (doubles.
double Misc::convertWorkoutWeight(std::string line){
	return stod(line);
}

//Returns a workout generated based on a difficulty.
void Misc::generateWorkout(double difficulty){
	//grabs the workouts file.
	std::string fileName = prog.getWorkoutsFilePath();
	std::ifstream file(fileName,std::ifstream::in);
	
	//Checks if the file exists and gathers the variables.
	if (file.good()){
		std::string line;
		std::vector<std::string> lines;

		//If true, print the workouts file.
		if (prog.getVerboseMode()){
			std::cout << std::endl << "...Workouts file output: " << std::endl;
		}
		while(std::getline(file,line)){
			if (line[0] != '#' && line != "" && !line.empty() && line.size()>2){
				if(prog.getVerboseMode()){
					std::cout << line << std::endl;
				}
				
				//remove spaces from each line for processing
				line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
				//removes end of line characters from variable name and value. Fixes a bug.
				line.erase(std::remove(line.begin(), line.end(), '\r'), line.end()); 
				line.erase(std::remove(line.begin(), line.end(), '\n'), line.end()); 
				
				lines.push_back(line);
			}	
		}
		if(prog.getVerboseMode()){
			std::cout << std::endl;
		}
		if(prog.getVerboseMode())
			std::cout << "...Finished reading in workouts file. " << std::endl;
		
		//Creates and stores workouts file variables.
		std::vector<std::string> workoutName;
		std::vector<double> workoutWeight;
		std::vector<std::string> workoutUnit;
		int weight = 1;
		int size = lines.size();
		
		if(prog.getVerboseMode())
			std::cout << "...Variables created. " << std::endl;
		
		if(getBeforeEqualSign(lines[0]) == "weight"){
			if(prog.getVerboseMode())
				std::cout << "...weight variable discovered. " << std::endl;
			
			int equalSignLocation = prog.findEqualInString(lines[0]);
			weight = stod(lines[0].substr(equalSignLocation+1,lines[0].size()-1));
			
			if(prog.getVerboseMode())
				std::cout << "...Printing values set. " << std::endl;
			
			std::cout << "...weight: " << weight << std::endl;
			
			lines.erase(lines.begin());
		}
		
		//Sets the workout file variables and the weight value.
		for(int i=0; i < size-1; i++){
			if(prog.getVerboseMode())
				std::cout << "...Beginning to assign variable values. " << std::endl;
			
			if(prog.getVerboseMode())
				std::cout << "...processing line: " << lines[i] << std::endl;
			
			workoutName.push_back( getBeforeEqualSign(lines[i]) );
			workoutWeight.push_back( convertWorkoutWeight( getBetweenEqualAndSemiColon(lines[i]) ) );
			workoutUnit.push_back( getAfterSemiColon(lines[i]) );
			
			if(prog.getVerboseMode()){
				std::cout << "...Printing values set. " << std::endl;
				std::cout << workoutName[i] << ": ";
				std::cout << workoutWeight[i] << " ";
				std::cout << workoutUnit[i] << std::endl;
			}
		}
		
	} else {
		if (prog.getVerboseMode())
			prog.returnError(31404);
	}
}