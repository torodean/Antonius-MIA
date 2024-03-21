/**
 * File: MIATerminalTools.cpp
 * Author: Antonius Torode
 * Creation Date: 12/17/2021
 * Description: A class for tools used by terminal specific features.
 */

#include "TerminalTools.hpp"
#include <iostream>

using std::cout;
using std::endl;


void MIATerminalTools::blankDots()
{
    cout << "...                                                                        ..." << endl;
}

void MIATerminalTools::blankLine()
{
    cout << endl;
}


