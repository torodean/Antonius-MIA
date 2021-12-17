/**
 * File: SubProgram.cpp
 * Author: Antonius Torode
 * Creation Date: 03/01/2021
 * Description: This is the cpp code corresponsind to a MIA sub-program.
 */

#include "SubProgram.hpp"

#include <utility>

SubProgram::SubProgram(std::string programName) : subProgramName(std::move(programName))
{

}
