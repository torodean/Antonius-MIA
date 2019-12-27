//============================================================================
// Name        : MIASequencer.h
// Author      : Antonius Torode
// Date        : 12/26/2019
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Description : MIA sequencer for processing the MIASequences file.
//============================================================================

#include "MIASequencer.h"
#include "MIAProgram.h"
#include "Winkeys.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>

using std::string;
using std::remove;
using std::ifstream;
using std::stoi;
using std::vector;
using std::cout;
using std::endl;
using std::pair;

//Main sequencer constructor.
Sequencer::Sequencer(){ 
	//Creates a test case.
	sequenceNames.push_back("defaultSequence");
	sequenceTimings.insert(pair<string, int>("defaultSequence", 3141));
	sequenceHoverTimes.insert(pair<string, int>("defaultSequence", 1413));
	sequenceSizes.insert(pair<string, int>("defaultSequence", 2));
	sequenceXCoords.insert(pair<string, vector<int>>("defaultSequence", {806,545}));
	sequenceYCoords.insert(pair<string, vector<int>>("defaultSequence", {545, 0}));
	sequenceActions.insert(pair<string, vector<string>>("defaultSequence", {"LEFTCLICK", "1234"}));
	initializeSequences();
};

//Main sequencer deconstructor.
Sequencer::~Sequencer(){
	
};

//Set's the variable to a value.
void Sequencer::setSequenceVariables(string variable, string value){
	//Sets the appropriate variable values.
	int commaLocation=0;
	string coordx, coordy;
	
	//Sets the input variable for a new sequence name.
	if (variable == "SEQUENCENAME"){
		if (getVerboseMode()){
			cout << "...Setting Sequence SEQUENCENAME: " << value << endl;
		}
		sequenceNames.push_back(value);
		lastSequenceIndex++;
		sequenceSize = 0;
		
	//Sets the input variable for a timing value.
	} else if(variable == "TIMING"){
		if (getVerboseMode()){
			cout << "...Setting Sequence TIMING: " << value << endl;
		}
		sequenceTimings.insert(pair<string, int>(sequenceNames[lastSequenceIndex], stoi(value)));
		
	//Sets the input variable for hover times.
	} else if(variable == "HOVERTIME"){
		if (getVerboseMode()){
			cout << "...Setting Sequence HOVERTIME: " << value << endl;
		}
		sequenceHoverTimes.insert(pair<string, int>(sequenceNames[lastSequenceIndex], stoi(value)));
		
	//Sets the variables for typing.
	} else if(variable == "TYPE"){
		if(getVerboseMode()){
			cout << "...Found sequence of type: " << variable << endl;
			cout << "...Setting coordx: " << 0 << endl;
			cout << "...Setting coordy: " << 0 << endl;
			cout << "...Setting pair with action: " << value << endl;
		}
		sequenceXCoordLine.push_back(0);
		sequenceYCoordLine.push_back(0);
		sequenceActionLine.push_back(value);
		sequenceSize++;
		
	//Sets the variables when a coordinate is entered.
	} else if(stringContainsChar(variable, ',')){
		//removes end of line characters from variable name and value. Fixes a bug.
		variable.erase(remove(variable.begin(), variable.end(), '\r'), variable.end()); 
		
		commaLocation = findCharInString(variable, ',');
		
		coordx = variable.substr(0, commaLocation);
		coordy = variable.substr(commaLocation+1,variable.size()-1);
		if(getVerboseMode()){
			cout << "...Found coordx: " << coordx << endl;
			cout << "...Found coordy: " << coordy << endl;
			cout << "...Setting pair with action: " << value << endl;
		}
		
		sequenceXCoordLine.push_back(stoi(coordx));
		sequenceYCoordLine.push_back(stoi(coordy));
		
		for(int i=0;i<sequenceYCoordLine.size();i++){
			cout << sequenceXCoordLine[i];
		}
		cout << endl;
		//Changes the input values to match WinKeys characters for mouse clicks.
		if (value == "LEFTCLICK"){
			value = "L";
		} else if (value == "RIGHTCLICK"){
			value = "R";
		}
		sequenceActionLine.push_back(value);
		sequenceSize++;
		
	//Finds the end of sequence and prepares for a new sequence.
	} else if (variable == "ENDOFSEQUENCE"){
		sequenceActions.insert(pair<string, vector<string>>(sequenceNames[lastSequenceIndex], sequenceActionLine));
		sequenceXCoords.insert(pair<string, vector<int>>(sequenceNames[lastSequenceIndex], sequenceXCoordLine));
		sequenceYCoords.insert(pair<string, vector<int>>(sequenceNames[lastSequenceIndex], sequenceYCoordLine));
		sequenceSizes.insert(pair<string, int>(sequenceNames[lastSequenceIndex], sequenceSize));
		if(getVerboseMode()){
			cout << "...Creating size map: " << sequenceNames[lastSequenceIndex] << " -> " << sequenceSize << endl;
			cout << "...Found ENDOFSEQUENCE." << endl;
		}
		
		//Clear the sequence specific values.
		sequenceXCoordLine.clear();
		sequenceYCoordLine.clear();
		sequenceActionLine.clear();
	} else {
		if(getVerboseMode()){
			returnError(31422, variable);
		}
	}
}

//Set's all the variables from the MIA Sequences file.
void Sequencer::initializeSequences(){
	//grabs the MIASequences file.
	ifstream file(getFilePath("sequencesFilePath"),ifstream::in);
	
	//Checks if the file exists and runs the code.
	if (file.good()){
		string line;
		vector<string> lines;

		//If true, print the configuration file settings.
		if (getVerboseMode()){
			cout << endl << "...Sequence file output: " << endl;
		}
		while(getline(file,line)){
			if (line[0] != '#' && line != "" && !line.empty() && line.size()>2){
				if(getVerboseMode()){
					cout << line << endl;
				}
				lines.push_back(line);
			}	
		}
		if(getVerboseMode()){
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
			
			if (value == "NDOFSEQUENCE"){
				variable = "ENDOFSEQUENCE";
			}
			
			if(getVerboseMode() && variable != "ENDOFSEQUENCE"){
				cout << "...Sequence variable: " << variable << " with action " << value << "'" << endl;
			}
			setSequenceVariables(variable, value);
		}
	} else {
		returnError(31421);
	}
}

//Extracts the size from a sequence name.
int Sequencer::getSequenceSize(string sequence){
	if(getVerboseMode()){
		cout << "...Finding size for sequence " << sequence << " as " << sequenceSizes.find(sequence)->second << endl;
	}
	return sequenceSizes.find(sequence)->second;
}

//Extracts the x coordinates from a sequence name.
vector<int> Sequencer::getSequenceXCoords(string sequence){
	if(getVerboseMode()){
		cout << "...Finding X Coordinates for sequence " << sequence 
		//<< " as " << sequenceXCoords2.find(sequence)->second 
		<< endl;
	}
	return sequenceXCoords.find(sequence)->second;
}

//Extracts the Y coordinates from a sequence name.
vector<int> Sequencer::getSequenceYCoords(string sequence){
	if(getVerboseMode()){
		cout << "...Finding Y Coordinates for sequence " << sequence 
		//<< " as " << sequenceYCoords2.find(sequence)->second 
		<< endl;
	}
	return sequenceYCoords.find(sequence)->second;
}

//Extracts the actions from a sequence name.
vector<string> Sequencer::getSequenceActions(string sequence){
	if(getVerboseMode()){
		cout << "...Finding Actions for sequence " << sequence
		//<< " as " << sequenceActions2.find(sequence)->second 
		<< endl;
	}
	return sequenceActions.find(sequence)->second;
}

//Activates and performs a sequence.
void Sequencer::activateSequence(string sequence){
	cout << "...Activating Sequence: " << sequence << endl;
	int timing = sequenceTimings.find(sequence)->second;
	int hover = sequenceHoverTimes.find(sequence)->second;
	int size = getSequenceSize(sequence);
	vector<int> XCoords = getSequenceXCoords(sequence);
	vector<int> YCoords = getSequenceYCoords(sequence);
	vector<string> actions = getSequenceActions(sequence);
	
	for(int i=0;i<size;i++){
		keys.sleep(timing);
		if(XCoords[i] == 0 && YCoords[i] == 0){
			if(getVerboseMode()){
				cout << "...Coordinates both zero, typing " << actions[i] << endl;
			}
			keys.type(actions[i]);
		} else {
			if(getVerboseMode()){
				cout << "...Coordinates not both zero, moving mouse to " << XCoords[i] << "," << YCoords[i] << "." << endl;
			}
			keys.moveMouseTo(XCoords[i], YCoords[i]);
			if(actions[i] == "HOVER"){				
				if(getVerboseMode()){
					cout << "...Coordinates both zero, Hovering for " << hover << " seconds." << endl;
				}
				keys.sleep(hover);
			} else {
				if(getVerboseMode()){
					cout << "...Coordinates not zero, performing action: " << actions[i] << endl;
				}
				keys.type(actions[i]);
			}
		}
	}
}

