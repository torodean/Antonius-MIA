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
	
	prog.blankDots();
	std::cout << "...Loading MIA workout generation. " << std::endl;
	prog.blankDots();

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
		
		//Creates and stores workouts file/program variables.
		std::vector<std::string> workoutName;
		std::vector<double> workoutWeight;
		std::vector<std::string> workoutUnit;
		int size = lines.size();
		double toughness = 1.0;
		double minNumOfWorkouts = 3.0;
		double maxNumOfWorkouts = (double)size-5.0; //Minus 5 because there are 5 non-workout variables.
		double minNumOfSets = 1.0;
		double maxNumOfSets = 10.0;
		
		//For keeping track of how many variables are in the workouts file.
		int numOfVariables = 5, variableCount = 0;
		bool foundVar = false;
		
		std::string variable;
		int equalSignLocation;
		
		//Read the workouts input file and grab the variables.
		for(int i=0; i<numOfVariables; i++){
			//Finds what the variable input is if one exists.
			variable = getBeforeEqualSign(lines[i]);
			
			//Sets the toughness variable.
			if(variable == "toughness"){
				if(prog.getVerboseMode())
					std::cout << "...toughness variable discovered. " << std::endl;
				
				equalSignLocation = prog.findEqualInString(lines[i]);
				toughness = stod(lines[i].substr(equalSignLocation+1,lines[i].size()-1));
			
				if(prog.getVerboseMode())
					std::cout << "...toughness: " << toughness << std::endl;
				foundVar = true;
			//Sets the minNumOfWorkouts if one exists.
			} else if(variable  == "minNumOfWorkouts"){
				if(prog.getVerboseMode())
					std::cout << "...minNumOfWorkouts variable discovered. " << std::endl;
				
				equalSignLocation = prog.findEqualInString(lines[i]);
				minNumOfWorkouts = stod(lines[i].substr(equalSignLocation+1,lines[i].size()-1));
			
				if(prog.getVerboseMode())
					std::cout << "...minNumOfWorkouts: " << (int)minNumOfWorkouts << std::endl;
				foundVar = true;
			//Sets the maxNumOfWorkouts if one exists.
			} else if(variable  == "maxNumOfWorkouts"){
				if(prog.getVerboseMode())
					std::cout << "...maxNumOfWorkouts variable discovered. " << std::endl;
				
				equalSignLocation = prog.findEqualInString(lines[i]);
				if(lines[i].substr(equalSignLocation+1,lines[i].size()-1) != "inf"){
					maxNumOfWorkouts = stod(lines[i].substr(equalSignLocation+1,lines[i].size()-1));
				}
			
				if(prog.getVerboseMode())
					std::cout << "...maxNumOfWorkouts: " << (int)maxNumOfWorkouts << std::endl;
				foundVar = true;
			//Sets the minNumOfSets if one exists.
			} else if(variable  == "minNumOfSets"){
				if(prog.getVerboseMode())
					std::cout << "...minNumOfSets variable discovered. " << std::endl;
				
				equalSignLocation = prog.findEqualInString(lines[i]);
				minNumOfSets = stod(lines[i].substr(equalSignLocation+1,lines[i].size()-1));
			
				if(prog.getVerboseMode())
					std::cout << "...minNumOfSets: " << (int)minNumOfSets << std::endl;
				foundVar = true;
			//Sets the maxNumOfSets variable if one was found.
			} else if(variable  == "maxNumOfSets"){
				if(prog.getVerboseMode())
					std::cout << "...maxNumOfSets variable discovered. " << std::endl;
				
				equalSignLocation = prog.findEqualInString(lines[i]);
				if(lines[i].substr(equalSignLocation+1,lines[i].size()-1) != "inf"){
					maxNumOfSets = stod(lines[i].substr(equalSignLocation+1,lines[i].size()-1));
				}
			
				if(prog.getVerboseMode())
					std::cout << "...maxNumOfSets: " << (int)maxNumOfSets << std::endl;
				foundVar = true;
			}
			
			//Counter to see if variable wasn't found in workouts file.
			if (!foundVar){
				variableCount++;
			} else {
				foundVar = true;
			}
		}
		
		//Accounts for variables not found in workouts file.
		numOfVariables = numOfVariables - variableCount;
		lines.erase(lines.begin(), lines.begin()+numOfVariables);
		
		//Sets the workout file variables and the weighted value.
		for(int i=0; i < size-numOfVariables; i++){
			if(prog.getVerboseMode())			
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
		
		std::cout << "...Running workout generation. " << std::endl;
		prog.blankDots();
		
		//Calculates workout routine
		double maxNumOfWorkoutsModifier = (maxNumOfWorkouts-minNumOfWorkouts)/100.0 * difficulty + minNumOfWorkouts;
		double minNumOfWorkoutsModifier = (maxNumOfWorkouts-minNumOfWorkouts)/200.0 * difficulty + minNumOfWorkouts;
		int numOfWorkouts = prog.randomInt((int)minNumOfWorkoutsModifier,(int)maxNumOfWorkoutsModifier,0);
		double maxNumOfSetsModifier = (maxNumOfSets-minNumOfSets)/100.0 * difficulty + minNumOfSets;
		double minNumOfSetsModifier = (maxNumOfSets-minNumOfSets)/200.0 * difficulty + minNumOfSets;
		int numOfSets = prog.randomInt((int)minNumOfSetsModifier,(int)maxNumOfSetsModifier,0);
		
		if(prog.getVerboseMode()){
			std::cout << "...numOfWorkouts: " << numOfWorkouts << std::endl;
			std::cout << "...numOfSets: " << numOfSets << std::endl;
		}
		
		std::vector<bool> workoutChosen;
		for(int i=0; i<size-numOfVariables; i++){
			workoutChosen.push_back(false);
		}
		
		//determines which workouts to use.
		int randNum = prog.randomInt(0,size-numOfVariables,0);
		for(int i=0;i<numOfWorkouts; i++){
			randNum = prog.randomInt(0,size-numOfVariables,0);
			while(workoutChosen[randNum]){
				randNum = prog.randomInt(0,size-numOfVariables,0);
			}
			workoutChosen[randNum] = true;
		}
		
		std::cout << "...Number of workouts: " << numOfWorkouts << std::endl;
		std::cout << "...Number of sets: " << numOfSets << std::endl;
		
		//Determines values for each workout and prints the results.
		for (int i=0; i<size-numOfVariables; i ++){
			//TODO
		}
		
	} else {
		if (prog.getVerboseMode())
			prog.returnError(31404);
	}
}