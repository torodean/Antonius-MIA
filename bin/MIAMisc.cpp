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
#include <math.h> 
#include "MIAMisc.h"

using std::string;
using std::cin;
using std::ifstream;
using std::cout;
using std::vector;
using std::getline;
using std::endl;
using std::random_shuffle;
using std::ofstream;
using std::to_string;
using std::remove;

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
	string fileName;
	string fullPath;
	
	//Checks the user for where the file is located.
	if (useDefaultPath){
		cout << "...Please enter an input file: ";
		getline(cin, fileName);
		fullPath = prog.getDefaultInputFilePath() + fileName;
		prog.blankLine();
	} else {
		cout << "...Please enter an input file (full path included): ";
		getline(cin, fileName);
		fullPath = fileName;
		prog.blankLine();
	}
	
	//grabs the file.
	ifstream file(fullPath,ifstream::in);
	
	//Checks if the file exists and runs the code.
	if (file.good()){
		string line;
		vector<string> lines;

		while(getline(file,line)){
			//cout << line << endl;
			lines.push_back(line);
		}
		
		int listSize = lines.size();
		srand(time(NULL));
		int randomNum = 0;
		
		for(int i=0; i<numberOfLines; i++){
			randomNum = rand() % listSize;
			cout << lines[randomNum] << endl;
		}
	} else {
		prog.returnError(41404);
	}
}

//Returns a shuffled string.
string Misc::shuffleString(string input){
	string output = input;
	random_shuffle(output.begin(), output.end());
	return output;
}

//Manages input file lines.
string Misc::getBeforeEqualSign(string line){
	int equalSignLocation = prog.findEqualInString(line);
	
	if(prog.getVerboseMode())
		cout << "...stringBeforeEqual: " << line.substr(0, equalSignLocation) << endl;
	
	return line.substr(0, equalSignLocation);
}
string Misc::getBetweenEqualAndSemiColon(string line){
	int equalSignLocation = prog.findEqualInString(line);
	int semiColonLocation = prog.findSemiColonInString(line);
	
	//First remove everything after the semi colon sign. Then keep everything after the equal sign.
	line = line.substr(0,semiColonLocation);
	line = line.substr(equalSignLocation+1,line.size()-1);
	
	if(prog.getVerboseMode())
		cout << "...stringBetweenEqualAndSemiColon: " << line << endl;
	
	return line;
}
string Misc::getAfterSemiColon(string line){
	int semiColonLocation = prog.findSemiColonInString(line);
	
	if(prog.getVerboseMode())
		cout << "...stringAfterSemiColon: " << line.substr(semiColonLocation+1,line.size()-1) << endl;
	
	return line.substr(semiColonLocation+1,line.size()-1);
}

//convert input file line to proper format (doubles.
double Misc::convertWorkoutWeight(string line){
	return stod(line);
}

//Returns the maximumNumberOfXXX based on a difficulty.
//Custom formula chosen for desired workout curves.
double Misc::maxNumModifier(double min, double max, double difficulty){
	return (max/(10.0*pow(10.0,(1.0/3.0))) - min/(10.0*pow(10.0,(1.0/3.0))))*pow(difficulty,(2.0/3.0))+min;
}

//Returns the manimumNumberOfXXX based on a difficulty.
//Custom formula chosen for desired workout curves.
double Misc::minNumModifier(double min, double max, double difficulty){
	
	//adjusts the min compared to max.
	//Set such that new curves are similar to old workout generation functions.
	double minModifier = 1.9; 
	
	return (-((-max + min*minModifier)/(10.0*pow(10.0,(1.0/3.0))*minModifier)))*pow(difficulty,(2.0/3.0)) + min;
}

//Returns a workout generated based on a difficulty.
void Misc::generateWorkout(double difficulty, bool weekly){
	
	//Int to keep track of whether we need to generate a weekly workout or not.
	int timesToGenerate = 1;
	ofstream out;
	
	
	if(weekly){
		string outputFile = prog.getWorkoutOutputFilePath();
		outputFile.erase(outputFile.end()-4,outputFile.end());
		outputFile += " ";
		outputFile += __DATE__;
		outputFile += ".txt";
		
		cout << "...Weekly workout generation loaded. " << endl;
		cout << "...Workout will be output to '" << outputFile << "'" << endl;
		prog.blankDots();
		
		string outputFileText = "//============================================================================\n"
		"// Name        : workout.txt                                                  \n"
		"// Author      : MIA                                                          \n"
		"// Created on  : " + prog.today() + "                                         \n"
		"// Description : A daily generated workout via the MIA program (for one week).\n"
		"// Difficulty  : " + to_string(difficulty) + "                           \n"
		"//============================================================================\n\n";
		
		timesToGenerate = 7; //generate 7 workouts
		out.open(outputFile);
		out << outputFileText;
	}
	
	prog.blankDots();
	cout << "...Loading MIA workout generation. " << endl;
	prog.blankDots();

	//grabs the workouts file.
	string fileName = prog.getWorkoutsFilePath();
	ifstream file(fileName,ifstream::in);
	
	//Checks if the file exists and gathers the variables.
	if (file.good()){
		string line;
		vector<string> lines;

		//If true, print the workouts file.
		if (prog.getVerboseMode()){
			cout << endl << "...Workouts file output: " << endl;
		}
		while(getline(file,line)){
			if (line[0] != '#' && line != "" && !line.empty() && line.size()>2){
				if(prog.getVerboseMode()){
					cout << line << endl;
				}
				
				//remove spaces from each line for processing
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				//removes end of line characters from variable name and value. Fixes a bug.
				line.erase(remove(line.begin(), line.end(), '\r'), line.end()); 
				line.erase(remove(line.begin(), line.end(), '\n'), line.end()); 
				
				lines.push_back(line);
			}	
		}
		if(prog.getVerboseMode()){
			cout << endl;
		}
		if(prog.getVerboseMode())
			cout << "...Finished reading in workouts file. " << endl;
		
		//Creates and stores workouts file/program variables.
		vector<string> workoutName;
		vector<double> workoutWeight;
		vector<string> workoutUnit;
		int size = lines.size();
		double toughness = 0.1;
		double minNumOfExercises = 3.0;
		double maxNumOfExercises = (double)size-5.0; //Minus 5 because there are 5 non-workout variables.
		double minNumOfSets = 1.0;
		double maxNumOfSets = 10.0;
		
		//For keeping track of how many variables are in the workouts file.
		int numOfVariables = 5, variableCount = 0;
		bool foundVar = false;
		
		string variable;
		int equalSignLocation;
		
		//Read the workouts input file and grab the variables.
		for(int i=0; i<numOfVariables; i++){
			//Finds what the variable input is if one exists.
			variable = getBeforeEqualSign(lines[i]);
			
			//Sets the toughness variable.
			if(variable == "toughness"){
				if(prog.getVerboseMode())
					cout << "...toughness variable discovered. " << endl;
				
				equalSignLocation = prog.findEqualInString(lines[i]);
				toughness = stod(lines[i].substr(equalSignLocation+1,lines[i].size()-1));
			
				if(prog.getVerboseMode())
					cout << "...toughness: " << toughness << endl;
				foundVar = true;
			//Sets the minNumOfExercises if one exists.
			} else if(variable  == "minNumOfExercises"){
				if(prog.getVerboseMode())
					cout << "...minNumOfExercises variable discovered. " << endl;
				
				equalSignLocation = prog.findEqualInString(lines[i]);
				minNumOfExercises = stod(lines[i].substr(equalSignLocation+1,lines[i].size()-1));
			
				if(prog.getVerboseMode())
					cout << "...minNumOfExercises: " << (int)minNumOfExercises << endl;
				foundVar = true;
			//Sets the maxNumOfExercises if one exists.
			} else if(variable  == "maxNumOfExercises"){
				if(prog.getVerboseMode())
					cout << "...maxNumOfExercises variable discovered. " << endl;
				
				equalSignLocation = prog.findEqualInString(lines[i]);
				if(lines[i].substr(equalSignLocation+1,lines[i].size()-1) != "inf"){
					maxNumOfExercises = stod(lines[i].substr(equalSignLocation+1,lines[i].size()-1));
				}
			
				if(prog.getVerboseMode())
					cout << "...maxNumOfExercises: " << (int)maxNumOfExercises << endl;
				foundVar = true;
			//Sets the minNumOfSets if one exists.
			} else if(variable  == "minNumOfSets"){
				if(prog.getVerboseMode())
					cout << "...minNumOfSets variable discovered. " << endl;
				
				equalSignLocation = prog.findEqualInString(lines[i]);
				minNumOfSets = stod(lines[i].substr(equalSignLocation+1,lines[i].size()-1));
			
				if(prog.getVerboseMode())
					cout << "...minNumOfSets: " << (int)minNumOfSets << endl;
				foundVar = true;
			//Sets the maxNumOfSets variable if one was found.
			} else if(variable  == "maxNumOfSets"){
				if(prog.getVerboseMode())
					cout << "...maxNumOfSets variable discovered. " << endl;
				
				equalSignLocation = prog.findEqualInString(lines[i]);
				if(lines[i].substr(equalSignLocation+1,lines[i].size()-1) != "inf"){
					maxNumOfSets = stod(lines[i].substr(equalSignLocation+1,lines[i].size()-1));
				}
			
				if(prog.getVerboseMode())
					cout << "...maxNumOfSets: " << (int)maxNumOfSets << endl;
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
			workoutName.push_back( getBeforeEqualSign(lines[i]) );
			workoutWeight.push_back( convertWorkoutWeight( getBetweenEqualAndSemiColon(lines[i]) ) );
			workoutUnit.push_back( getAfterSemiColon(lines[i]) );
			
			if(prog.getVerboseMode()){
				cout << "...Printing values set. " << endl;
				cout << workoutName[i] << ": ";
				cout << workoutWeight[i] << " ";
				cout << workoutUnit[i] << endl;
			}
		}
		
		cout << "...Running workout generation. " << endl;
		
		int randCounter = 1; //For changing random integers between calls.
		
		//Loops over the generation code however many times needed.
		while(timesToGenerate > 0){
			
			if(!weekly){
				prog.blankLine();
			} else if(timesToGenerate == 7){
				out << "##############\n"
						"### SUNDAY ###\n"
						"##############" << endl << endl;
			} else if(timesToGenerate == 6){
				out << "##############\n"
						"### MONDAY ###\n"
						"##############" << endl << endl;
			} else if(timesToGenerate == 5){
				out << "###############\n"
						"### TUESDAY ###\n"
						"###############" << endl << endl;
			} else if(timesToGenerate == 4){
				out << "#################\n"
						"### WEDNESDAY ###\n"
						"#################" << endl << endl;
			} else if(timesToGenerate == 3){
				out << "################\n"
						"### THURSDAY ###\n"
						"################" << endl << endl;
			} else if(timesToGenerate == 2){
				out << "##############\n"
						"### FRIDAY ###\n"
						"##############" << endl << endl;
			} else if(timesToGenerate == 1){
				out << "################\n"
						"### SATURDAY ###\n"
						"################" << endl << endl;
			}
			
			//Calculates workout routine
			
			/* Old functions for workout calculations.
			double maxNumOfExercisesModifier = (maxNumOfExercises-minNumOfExercises)/100.0 * difficulty + minNumOfExercises;
			double minNumOfExercisesModifier = (maxNumOfExercises-minNumOfExercises)/200.0 * difficulty + minNumOfExercises;
			double maxNumOfSetsModifier = (maxNumOfSets-minNumOfSets)/100.0 * difficulty + minNumOfSets;
			double minNumOfSetsModifier = (maxNumOfSets-minNumOfSets)/200.0 * difficulty + minNumOfSets;
			*/
			
			// Improved functions for workout calculations
			double maxNumOfExercisesModifier = maxNumModifier(minNumOfExercises, maxNumOfExercises, difficulty);
			double minNumOfExercisesModifier = minNumModifier(minNumOfExercises, maxNumOfExercises, difficulty);
			double maxNumOfSetsModifier = maxNumModifier(minNumOfSets, maxNumOfSets, difficulty);
			double minNumOfSetsModifier = minNumModifier(minNumOfSets, maxNumOfSets, difficulty);
			
			
			int numOfWorkouts;
			randCounter++;
			int numOfSets = prog.randomInt((int)minNumOfSetsModifier,(int)maxNumOfSetsModifier,randCounter, true);
			
			if(prog.getVerboseMode()){
				cout << "...numOfSets: " << numOfSets << endl;
			}
			if(weekly){
				out << "...Number of sets: " << numOfSets << endl << endl;
			} else {
				cout << "...Number of sets: " << numOfSets << endl;
				prog.blankLine();
			}
			
			//declares some needed variables.
			vector<bool> workoutChosen;
			for(int i=0; i<size-numOfVariables; i++){
				workoutChosen.push_back(false);
			}
			randCounter++;
			int randNum = prog.randomInt(0,size-numOfVariables,randCounter, true);
			int set = 1;
			double repsMin, repsMax, repsModifier;		
			
			//Loops over the stuff and creates a random workout for each set.
			while (numOfSets > 0){
				randCounter++;
				if(weekly){ //prints results.
					out << "...Workout for set " << set << "." << endl << endl;
				} else {
					cout << "...Workout for set " << set << "." << endl;
					prog.blankLine();
				}

				
				for (int i=0; i < size-numOfVariables; i++){
					workoutChosen[i] = false;
				}			
				
				//randomizes the number of workouts per set.
				numOfWorkouts = prog.randomInt((int)minNumOfExercisesModifier,(int)maxNumOfExercisesModifier,randCounter, true);
				
				//determines which workouts to use.
				for(int i=0;i<numOfWorkouts; i++){
					randNum = prog.randomInt(0,size-numOfVariables,randCounter, true);
					while(workoutChosen[randNum]){
						randNum = prog.randomInt(0,size-numOfVariables,randCounter, true);
						randCounter++;
					}
					workoutChosen[randNum] = true;
				}
				
				//Determines values for each workout and prints the results.
				for (int i=0; i<size-numOfVariables; i++){
					randCounter++;
					if(workoutChosen[i]){
						repsMin = (toughness*difficulty*workoutWeight[i]-workoutWeight[i])/2+workoutWeight[i];
						repsMax = toughness*difficulty*workoutWeight[i];
						if(workoutName[i] != "running"){
							repsModifier = prog.randomInt((int)repsMin, (int)repsMax, randCounter, true);
							if(weekly){ //prints results.
								out << workoutName[i] << ": " << (int)repsModifier+1 << " " << workoutUnit[i] << endl;
							} else {
								cout << workoutName[i] << ": " << (int)repsModifier+1 << " " << workoutUnit[i] << endl;
							}
						} else {
							repsModifier = prog.randomInt((int)(repsMin*100.0), (int)(repsMax*100.0), randCounter, true);
							repsModifier /= 100;
							if(weekly){ //prints results.
								out << workoutName[i] << ": " << repsModifier << " " << workoutUnit[i] << endl;
							} else {
								cout << workoutName[i] << ": " << repsModifier << " " << workoutUnit[i] << endl;
							}
						}
					}
				}		
				set++;
				numOfSets--;
				if(weekly){ //prints results.
					out << endl;
				} else {
					prog.blankLine();
				}
			}
			if(difficulty == 0.0){
				if(weekly){ //prints results.
					out << "rest: 45 minutes" << endl;
				} else {
					cout << "rest: 45 minutes" << endl;
				}
			}
			if (weekly){ //prints results.
				out << endl;
			} else {
				prog.blankLine();
			}
			timesToGenerate--;
		}
		cout << "...Workout generation completed." << endl;
	} else {
		if (prog.getVerboseMode())
			prog.returnError(31404);
	}
}