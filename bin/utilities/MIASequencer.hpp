/**
 * File: MIASequencer.hpp
 * Author: Antonius Torode
 * Date: 12/26/2019
 * Description: MIA sequencer for processing the MIASequences file.
 */

#include <string>
#include <vector>
#include <map>

#include "VirtualKeyStrokes.hpp"

using std::string;
using std::vector;
using std::map;

class [[maybe_unused]] Sequencer
{
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

		VirtualKeyStrokes keys;

	public: 
		//Functions for initializing the sequencer and loading in variables from file.
		Sequencer();
		~Sequencer() = default;
		void setSequenceVariables(string variable, string value);
		void initializeSequences();
		
		//Functions for handling sequencer data.
		int getSequenceSize(const string& sequence);
		vector<int> getSequenceXCoords(const string& sequence);
		vector<int> getSequenceYCoords(const string& sequence);
		vector<string> getSequenceActions(const string& sequence);
		vector<string> getSequenceNames(){ return sequenceNames; };
		
		//Functions for using the sequencer.
		void activateSequence(const string& sequence);
};
