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

class Misc {
	private:
	public:
		Misc();
		~Misc();
		
		Program prog;
		
		//Functions relating to workout creation.
		void generateWorkout(double difficulty, bool weekly);
		std::string getBeforeEqualSign(std::string line);
		std::string getBetweenEqualAndSemiColon(std::string line);
		std::string getAfterSemiColon(std::string line);
		double convertWorkoutWeight(std::string line);
		
		//Misc functions.
		void printRandomLinesFromFile(bool useFefaultPath, int numberOfLines);
		std::string shuffleString(std::string input);
};
#endif