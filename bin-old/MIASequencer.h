//============================================================================
// Name        : MIASequencer.h
// Author      : Antonius Torode
// Date        : 12/26/2019
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Description : MIA sequencer for processing the MIASequences file.
//============================================================================

#ifndef __MIASEQUENCER_H__
#define __MIASEQUENCER_H__

#include "MIAProgram.h"
#include "Winkeys.h"

#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

class Sequencer : public Program {
	private:
		//Variables for loading the sequence file.
		int lastSequenceIndex = 0;
		int sequenceSize = 0;
		vector<string> sequenceNames;
		vector<int> sequenceXCoordLine;
		vector<int> sequenceYCoordLine;
		vector<string> sequenceActionLine;
		
		//Maps for storing sequencer data.
		map<string, int> sequenceTimings;
		map<string, int> sequenceHoverTimes;
		map<string, int> sequenceSizes;
		map<string, vector<int>> sequenceXCoords;
		map<string, vector<int>> sequenceYCoords;
		map<string, vector<string>> sequenceActions;
		
		WinKeys keys;
		
	public: 
		//Functions for initializing the sequencer and loading in variables from file.
		Sequencer();
		~Sequencer();
		void setSequenceVariables(string variable, string value);
		void initializeSequences();
		
		//Functions for handling sequencer data.
		int getSequenceIndex(string sequence);
		int getSequenceSize(string sequence);
		vector<int> getSequenceXCoords(string sequence);
		vector<int> getSequenceYCoords(string sequence);
		vector<string> getSequenceActions(string sequence);
		vector<string> getSequenceNames(){ return sequenceNames; };
		
		//Functions for using the sequencer.
		void activateSequence(string sequence);
};
#endif