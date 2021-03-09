/**
 * File: Error.cpp
 * Author: Antonius Torode
 * Date: 03/01/2021
 * Description:
 */

#include <iostream>
#include <string>
#include "Error.hpp"
#include "../terminal/MIATerminal.hpp"

using std::cout;
using std::endl;
using std::string;


int Error::returnError(int errorCode, const string& details)
{
    switch(errorCode){
        case MIACONFIGFILENOTFOUND:
            cout << "...ERROR 31403: MIAConfig.MIA file not found." << endl;
            break;
        case FATALFILENOTFOUND:
            cout << "...ERROR 31404: FATAL: File not found. " << details << endl;
            break;
        case FUNCTIONINDEV:
            cout << "...ERROR 31415: Function still in Development." << endl;
            break;
        case WINDOWSONLYFUNCTIONALITY:
            cout << "...ERROR 31416: This feature is currently only programmed for Windows." << endl;
            break;
        case INVALIDMIACONFIGOPTION:
            cout << "...ERROR 31417: Invalid Option in MIAConfig: " << details << ".  Using default value." << endl;
            break;
        case NOTHINGSETFORTESTING:
            cout << "...ERROR 31418: Nothing set for testing." << endl;
            break;
        case ISSUESETTINGMIAVARIABLE:
            cout << "...ERROR 31419: Issue setting MIA variable: " << details << endl;
            break;
        case ISSUEWITHSEQUENCEFILE:
            cout << "...ERROR 31420: Issue with MIASequenceFile. " << endl;
            break;
        case MIASEQUENCEFILENOTFOUND:
            cout << "...ERROR 31421: MIASequences File not found! " << endl;
            break;
        case INVALIDSEQUENCEOPTION:
            cout << "...ERROR 31422: Invalid Option in MIASequences: " << details << endl;
            break;
        case CANTFINDMAPPEDVALUE:
            cout << "...ERROR 31423: Error finding mapped value: " << details << endl;
            break;
        case INVALIDCHARACTERINPUT:
            cout << "...ERROR 31424: Invalid Character input: " << details << endl;
            break;
        default:
            cout << "...ERROR: A catastrophic Failure Occurred." << endl;
            break;
    }
    return errorCode;
}

void Error::errorInfoRun(bool all)
{
    MIATerminalTools::blankDots();
    int error = 0;
    if(all){
        errorInfo(-1);
    } else {
        cout << "...Please enter an error code: ";
        std::cin >> error;
        std::cin.ignore();
        errorInfo(error);
    }
}

void Error::errorInfo(int error)
{
    MIATerminalTools::blankDots();
    switch(error){
        case ERROR_SUCCESS:
            cout << "...0: ERROR_SUCCESS - The operation completed successfully." << endl;
            break;
        case ERROR_ACCESS_DENIED:
            cout << "...5: ERROR_ACCESS_DENIED" << endl;
            break;
        case ERROR_GEN_FAILURE:
            cout << "...31: ERROR_GEN_FAILURE - A device attached to the system is not functioning." << endl;
            break;
        case ERROR_BAD_NETPATH:
            cout << "...53: ERROR_BAD_NETPATH - The network path was not found." << endl;
            break;
        case ERROR_INVALID_PARAMETER:
            cout << "...87: ERROR_INVALID_PARAMETER - The parameter is incorrect." << endl;
            break;
        case ERROR_INVALID_LEVEL:
            cout << "...124: ERROR_INVALID_LEVEL - The system call level is not correct." << endl;
            break;
        case FILENOTFOUND:
            cout << "...404: FILENOTFOUND - File not found." << endl;
            break;
        case ERROR_LOGON_FAILURE:
            cout << "...1326: ERROR_LOGON_FAILURE - The user name or password is incorrect." << endl;
            break;
        case RPC_S_SERVER_UNAVAILABLE:
            cout << "...1722: RPC_S_SERVER_UNAVAILABLE - The RPC server is unavailable." << endl;
            break;
        case NERR_USERNOTFOUND:
            cout << "...2221: NERR_UserNotFound - The user name could not be found." << endl;
            break;
        case ERROR_NO_BROWSER_SERVERS_FOUND:
            cout << "...6118: ERROR_NO_BROWSER_SERVERS_FOUND" << endl;
            cout << "...    - The list of servers for this workgroup is not currently available." << endl;
            break;
        case MIACONFIGFILENOTFOUND:
            cout << "...31403: MIAsettings file not found." << endl;
            break;
        case FATALFILENOTFOUND:
            cout << "...31404: FATAL: File not found." << endl;
            break;
        case FUNCTIONINDEV:
            cout << "...31415: Function still in Development." << endl;
            break;
        case WINDOWSONLYFUNCTIONALITY:
            cout << "...31416: This feature is currently only programmed for Windows." << endl;
            break;
        case INVALIDMIACONFIGOPTION:
            cout << "...31417: Invalid Option in MIAConfig: invalidVariable. Using default value." << endl;
            break;
        case NOTHINGSETFORTESTING:
            cout << "...31418: Nothing set for testing." << endl;
            break;
        case ISSUESETTINGMIAVARIABLE:
            cout << "...ERROR 31419: Issue setting MIA variable. " << endl;
            break;
        case ISSUEWITHSEQUENCEFILE:
            cout << "...ERROR 31420: Issue with MIASequenceFile. " << endl;
            break;
        case MIASEQUENCEFILENOTFOUND:
            cout << "...ERROR 31421: MIASequences File not found! " << endl;
            break;
        case INVALIDSEQUENCEOPTION:
            cout << "...ERROR 31422: Invalid Option in MIASequences. " << endl;
            break;
        case CANTFINDMAPPEDVALUE:
            cout << "...ERROR 31423: Error finding mapped value. " << endl;
            break;
        case INVALIDCHARACTERINPUT:
            cout << "...ERROR 31424: Invalid Character input. " << endl;
            break;
        default:
            cout << "...Invalid or unknown error code entered." << endl;
            cout << "...Full List of programmed error codes follow." << endl;
            MIATerminalTools::blankDots();
            cout << "...UNKNOWN: A catastrophic Failure Occurred." << endl;
            cout << "...0: ERROR_SUCCESS - The operation completed successfully." << endl;
            cout << "...5: ERROR_ACCESS_DENIED" << endl;
            cout << "...31: ERROR_GEN_FAILURE - A device attached to the system is not functioning." << endl;
            cout << "...53: ERROR_BAD_NETPATH - The network path was not found." << endl;
            cout << "...87: ERROR_INVALID_PARAMETER - The parameter is incorrect." << endl;
            cout << "...124: ERROR_INVALID_LEVEL - The system call level is not correct." << endl;
            cout << "...404: File not found." << endl;
            cout << "...1326: ERROR_LOGON_FAILURE - The user name or password is incorrect." << endl;
            cout << "...1722: RPC_S_SERVER_UNAVAILABLE - The RPC server is unavailable." << endl;
            cout << "...2221: NERR_UserNotFound - The user name could not be found." << endl;
            cout << "...6118: ERROR_NO_BROWSER_SERVERS_FOUND" << endl;
            cout << "...    - The list of servers for this workgroup is not currently available." << endl;
            cout << "...31403: MIAsettings file not found." << endl;
            cout << "...31404: FATAL: File not found." << endl;
            cout << "...31415: Function still in Development." << endl;
            cout << "...31416: This feature is currently only programmed for Windows." << endl;
            cout << "...31417: Invalid Option in MIAConfig. Using default value." << endl;
            cout << "...31418: Nothing set for testing." << endl;
            cout << "...31419: Issue setting MIA variable. " << endl;
            cout << "...31420: Issue with MIASequenceFile. " << endl;
            cout << "...31421: MIASequences File not found! " << endl;
            cout << "...31422: Invalid Option in MIASequences. " << endl;
            cout << "...31423: Error finding mapped value. " << endl;
            cout << "...31424: Invalid Character input. " << endl;
            break;
    }
}