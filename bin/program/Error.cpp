/**
 * File: Error.cpp
 * Author: Antonius Torode
 * Creation Date: 03/01/2021
 * Description: This file contains the Error class code.
 */

#include <iostream>
#include <string>
#include "Error.hpp"
#include "../terminal/TerminalTools.hpp"

using std::cout;
using std::endl;
using std::string;


int Error::returnError(int errorCode, const string& details)
{
    switch(errorCode)
	{
        case MIAConfig_File_Not_Found:
            cout << "...ERROR 31403: MIAConfig.MIA file not found." << endl;
            break;
        case FATAL_File_Not_Found:
            cout << "...ERROR 31404: FATAL: File not found. " << details << endl;
            break;
        case Feature_In_Dev:
            cout << "...ERROR 31415: Feature still in Development." << endl;
            break;
        case Windows_Only_Feature:
            cout << "...ERROR 31416: This feature is currently only programmed for Windows." << endl;
            break;
        case Invalid_MIAConfig_Option:
            cout << "...ERROR 31417: Invalid Option in MIAConfig: " << details << ".  Using default value." << endl;
            break;
        case Nothing_set_For_Testing:
            cout << "...ERROR 31418: Nothing set for testing." << endl;
            break;
        case Issue_Setting_MIA_Variable:
            cout << "...ERROR 31419: Issue setting MIA variable: " << details << endl;
            break;
        case Issue_With_Sequence_File:
            cout << "...ERROR 31420: Issue with MIASequenceFile. " << endl;
            break;
        case MIA_Sequence_File_Not_Found:
            cout << "...ERROR 31421: MIASequences File not found! " << endl;
            break;
        case Invalid_Sequence_Option:
            cout << "...ERROR 31422: Invalid Option in MIASequences: " << details << endl;
            break;
        case Cannot_Find_Mapped_Value:
            cout << "...ERROR 31423: Error finding mapped value: " << details << endl;
            break;
        case Invalid_Character_Input:
            cout << "...ERROR 31424: Invalid Character input: " << details << endl;
            break;
        case Linux_Only_Feature:
            cout << "..Error 31425: This feature is currently only programmed for Linux. " << details << endl;
            break;
	    case Catastrophic_Failure:
            cout << "..Error 9001: A catastrophic failure occurred. " << details << endl;
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
        case MIA_Success:
            cout << "...0: MIA_Success - The operation completed successfully." << endl;
            break;
        case Access_denied:
            cout << "...5: Access_denied" << endl;
            break;
        case Gen_Failure:
            cout << "...31: Gen_Failure - A device attached to the system is not functioning." << endl;
            break;
        case Bad_Net_Path:
            cout << "...53: Bad_Net_Path - The network path was not found." << endl;
            break;
        case Invalid_Parameter:
            cout << "...87: Invalid_Parameter - The parameter is incorrect." << endl;
            break;
        case Invalid_Level:
            cout << "...124: Invalid_Level - The system call level is not correct." << endl;
            break;
        case File_Not_Found:
            cout << "...404: File_Not_Found - File not found." << endl;
            break;
        case Logon_Failure:
            cout << "...1326: Logon_Failure - The user name or password is incorrect." << endl;
            break;
        case RPC_S_Server_Unavailable:
            cout << "...1722: RPC_S_Server_Unavailable - The RPC server is unavailable." << endl;
            break;
        case NErr_User_Not_Found:
            cout << "...2221: NErr_User_Not_Found - The user name could not be found." << endl;
            break;
        case No_Browser_Servers_Found:
            cout << "...6118: No_Browser_Servers_Found" << endl;
            cout << "...    - The list of servers for this workgroup is not currently available." << endl;
            break;
        case MIAConfig_File_Not_Found:
            cout << "...31403: MIAsettings file not found." << endl;
            break;
        case FATAL_File_Not_Found:
            cout << "...31404: FATAL: File not found." << endl;
            break;
        case Feature_In_Dev:
            cout << "...31415: Feature still in Development." << endl;
            break;
        case Windows_Only_Feature:
            cout << "...31416: This feature is currently only programmed for Windows." << endl;
            break;
        case Invalid_MIAConfig_Option:
            cout << "...31417: Invalid Option in MIAConfig: invalidVariable. Using default value." << endl;
            break;
        case Nothing_set_For_Testing:
            cout << "...31418: Nothing set for testing." << endl;
            break;
        case Issue_Setting_MIA_Variable:
            cout << "...ERROR 31419: Issue setting MIA variable. " << endl;
            break;
        case Issue_With_Sequence_File:
            cout << "...ERROR 31420: Issue with MIASequenceFile. " << endl;
            break;
        case MIA_Sequence_File_Not_Found:
            cout << "...ERROR 31421: MIASequences File not found! " << endl;
            break;
        case Invalid_Sequence_Option:
            cout << "...ERROR 31422: Invalid Option in MIASequences. " << endl;
            break;
        case Cannot_Find_Mapped_Value:
            cout << "...ERROR 31423: Error finding mapped value. " << endl;
            break;
        case Invalid_Character_Input:
            cout << "...ERROR 31424: Invalid Character input. " << endl;
            break;
        case Linux_Only_Feature:
            cout << "..Error 31425: This feature is currently only programmed for Linux. " << endl;
            break;
        default:
            cout << "...Invalid or unknown error code entered." << endl;
            cout << "...Full List of programmed error codes follow." << endl;
            MIATerminalTools::blankDots();
            cout << "...UNKNOWN: A catastrophic Failure Occurred." << endl;
            cout << "...0: MIA_Success - The operation completed Successfully." << endl;
            cout << "...5: Access_denied" << endl;
            cout << "...31: Gen_Failure - A device attached to the system is not functioning." << endl;
            cout << "...53: Bad_Net_Path - The network path was not found." << endl;
            cout << "...87: Invalid_Parameter - The parameter is incorrect." << endl;
            cout << "...124: Invalid_Level - The system call level is not correct." << endl;
            cout << "...404: File not found." << endl;
            cout << "...1326: Logon_Failure - The user name or password is incorrect." << endl;
            cout << "...1722: RPC_S_Server_Unavailable - The RPC server is unavailable." << endl;
            cout << "...2221: NErr_User_Not_Found - The user name could not be found." << endl;
            cout << "...6118: No_Browser_Servers_Found" << endl;
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
            cout << "..Error 31425: This feature is currently only programmed for Linux. " << endl;
            break;
    }
}