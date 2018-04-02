//============================================================================
// Name        : MIAMisc.h
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Created on  : January 8, 2018
// Description : This header file corresponding to the MIAmisc.cpp file.
//============================================================================

#include <string>
#ifndef __MIAMISC_H__
#define __MIAMISC_H__
#include "MIAProgram.h"

using std::string;

class Misc {
	private:
	public:
		Misc();
		~Misc();
		
		Program prog;
		
		//Functions relating to workout creation.
		void generateWorkout(double difficulty, bool weekly);
		string getBeforeEqualSign(string line);
		string getBetweenEqualAndSemiColon(string line);
		string getAfterSemiColon(string line);
		double convertWorkoutWeight(string line);
		double maxNumModifier(double min, double max, double difficulty);
		double minNumModifier(double min, double max, double difficulty);
		
		//Misc functions.
		void printRandomLinesFromFile(bool useFefaultPath, int numberOfLines);
		string shuffleString(string input);
};
#endif