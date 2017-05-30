// MIA main Program Interface and Runner.
#include <iostream>
#include <string>
	
void splash();
	
//Sets the current version number of MIA.
const std::string VERSION = "0.001";

//Runs the main MIA program.
int main(){
	splash();
	return 0;
}

//Displays the MIA splash screen.
void splash(){
	std::cout << "" << std::endl;
	std::cout << ".........................................................." << std::endl;
	std::cout << "...       |||      |||  ||||||||||      ||||     TM    ..." << std::endl;
	std::cout << "...       ||||    ||||      ||         ||  ||          ..." << std::endl;
	std::cout << "...       || ||  || ||      ||        ||||||||         ..." << std::endl;
	std::cout << "...       ||  ||||  ||      ||       ||      ||        ..." << std::endl;
	std::cout << "...       ||   ||   ||  ||||||||||  ||        ||       ..." << std::endl;
	std::cout << ".........................................................." << std::endl;
	std::cout << "................... TERMINAL INTERFACE ..................." << std::endl;
	std::cout << ".........................................................." << std::endl;
	std::cout << "... Multiple Integrated Applications -- Version: " + VERSION + " ..." << std::endl;
	std::cout << "..........     Programmer: Antonius Torode      .........." << std::endl;
	std::cout << ".........................................................." << std::endl;
}