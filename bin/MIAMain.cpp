/**
 * File: MIAMain.cpp
 * Author: Antonius Torode
 * Date: 03/01/2021
 * Description:
 */


#include <iostream>
#include "terminal/MIATerminal.hpp"

int main() {
    std::cout << "Starting MIA program!" << std::endl;

    MIATerminal terminal("MIA Terminal");
    terminal.run();

    std::cout << "Finished MIA program!" << std::endl;
    return 0;
}
