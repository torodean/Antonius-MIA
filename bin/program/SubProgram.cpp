/**
 * File: SubProgram.cpp
 * Author: Antonius Torode
 * Date: 03/01/2021
 * Description:
 */

#include "SubProgram.hpp"

#include <utility>

SubProgram::SubProgram(std::string programName) : subProgramName(std::move(programName))
{

}
