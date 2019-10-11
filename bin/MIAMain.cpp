//============================================================================
// Name        : MIAMain.cpp
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Description : MIA main Program Interface and Runner.
//============================================================================

#include "MIAProgram.h"

//Runs the main MIA program.
int main(){
	Program program;
	
	//Give this function a string parameter for a default command to be run upon execution.
	program.terminal("test");
	return 0;
}