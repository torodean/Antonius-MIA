/**
 * File: WindowsUtilities.cpp
 * Author: Antonius Torode
 * Date: 03/07/2021
 * Description:
 */

#include <string>
#include "WindowsUtilities.hpp"
#include "../../program/Error.hpp"


void WindowsUtilities::terminalCommand(const std::string& command)
{
#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
    system(command.c_str());
	blankLine();
#else
    Error::returnError(Error::ErrorCode::WINDOWSONLYFUNCTIONALITY);
#endif
}