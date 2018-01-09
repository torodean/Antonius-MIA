//============================================================================
// Name        : MIAmisc.h
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Created on  : January 8, 2018
// Description : This header file corresponding to the MIAmisc.cpp file.
//============================================================================

#ifndef __MIAMISC_H__
#define __MIAMISC_H__

class Misc {
	private:
	public:
		Misc();
		~Misc();
		void printRandomLinesFromFile(std::string file, int numberOfLines);
};
#endif