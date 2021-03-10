/**
 * File: Error.cpp
 * Author: Antonius Torode
 * Date: 03/01/2021
 * Description:
 */

#ifndef MIA2_ERROR_HPP
#define MIA2_ERROR_HPP

/**
 * This class is for error handling and error code information.
 */
class Error
{
public:

    /// A list of error codes that can be returned.
    enum ErrorCode
    {
        ERROR_SUCCESS = 0,
        ERROR_ACCESS_DENIED = 5,
        ERROR_GEN_FAILURE = 31,
        ERROR_BAD_NETPATH = 53,
        ERROR_INVALID_PARAMETER = 87,
        ERROR_INVALID_LEVEL = 124,
        FILENOTFOUND = 404,
        ERROR_LOGON_FAILURE = 1326,
        RPC_S_SERVER_UNAVAILABLE = 1722,
        NERR_USERNOTFOUND = 2221,
        ERROR_NO_BROWSER_SERVERS_FOUND = 6118,
        MIACONFIGFILENOTFOUND = 31403,
        FATALFILENOTFOUND = 31404,
        FUNCTIONINDEV = 31415,
        WINDOWSONLYFUNCTIONALITY = 31416,
        INVALIDMIACONFIGOPTION = 31417,
        NOTHINGSETFORTESTING = 31418,
        ISSUESETTINGMIAVARIABLE = 31419,
        ISSUEWITHSEQUENCEFILE = 31420,
        MIASEQUENCEFILENOTFOUND = 31421,
        INVALIDSEQUENCEOPTION = 31422,
        CANTFINDMAPPEDVALUE = 31423,
        INVALIDCHARACTERINPUT = 31424,
        LINUXONLYFUNCTIONALITY = 31425,
        CATASTROPHICFAILURE = 9001
    };

    /**
     * Returns an error code witha a brief descriptive message.
     * @param errorCode[int] - The integer error code to return.
     * @param details[std::string&] - A string with optional descriptive error info (default = "").
     */
    static int returnError(int errorCode, const std::string& details = "");

    /**
     * Returns information about a specified known error or all of the known errors.
     * @param error[int] - The error to return information about.
     */
    static void errorInfo(int error);

    /**
     * Inquires for an error code to gather info about.
     * @param all[bool] - option to print all error info (default = false).
     */
    static void errorInfoRun(bool all = false);

protected:

private:



};

#endif //MIA2_ERROR_HPP
