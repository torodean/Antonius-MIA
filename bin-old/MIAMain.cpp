//============================================================================
// Name        : MIAMain.cpp
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Description : MIA main Program Interface and Runner.
//============================================================================

#include "MIAProgram.h"
#include <iostream>
#include <thread>

using std::thread;

//Runs the main MIA terminal sub-program.
void terminalMIA(){
	Program program;
	
	//Give this function a string parameter for a default command to be run upon execution.
	program.terminal();
}

//Runs the main MIA program.
int main(){
	Program program;
	
	if(program.getMIATerminalMode()){
		thread threadObj( terminalMIA );
		threadObj.join();
	} else {
		std::cout << "...MIATerminalMode is set to false." << std::endl;
	}
	return 0;
}