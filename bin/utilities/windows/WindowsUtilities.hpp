/**
 * File: WindowsUtilities.hpp
 * Author: Antonius Torode
 * Date: 03/07/2021
 * Description:
 */


/**
 * This class is for utility features related to Windows.
 */
class WindowsUtilities
{
public:

    WindowsUtilities() = default;

    ~WindowsUtilities() = default;

protected:

private:

    /**
     * Runs a cmd terminal command.
     * @param command[std::string&] - A reference to the command to run.
     */
    static void terminalCommand(const std::string& command);
};
