//============================================================================
// Name        : MIAprogram.h
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Description : MIA settings and functions related to the MIA program.
//============================================================================

#ifndef __CSHAPE_H__
#define __CSHAPE_H__

#include <string>

class Program{
	private:
		const std::string VERSION;
	public:
		Program();
		~Program();
		void terminal();
		void blankDots();
		void splash();
		void intro();
		void standby();
		void helpMessage();
		void blankLine();
		std::string getMIAVersion();
};
#endif