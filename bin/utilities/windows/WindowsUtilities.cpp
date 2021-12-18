/**
 * File: WindowsUtilities.cpp
 * Author: Antonius Torode
 * Date: 03/07/2021
 * Description:
 */

#include <string>
#include "WindowsUtilities.hpp"
#include "Error.hpp"
#include "TerminalTools.hpp"


void WindowsUtilities::terminalCommand(const std::string& command)
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined _WIN32 || defined _WIN64 || defined __CYGWIN__
    system(command.c_str());
	MIATerminalTools::blankLine();
#else
    Error::returnError(Error::ErrorCode::WINDOWSONLYFUNCTIONALITY);
#endif
}