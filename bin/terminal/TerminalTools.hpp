/**
 * File: MIATerminalTools.hpp
 * Author: Antonius Torode
 * Creation Date: 12/17/2021
 * Description: A class for tools used by terminal specific features.
 */


/**
 * These are tools used by the terminal class that also need called outside of the terminal class.
 */
class MIATerminalTools
{
public:

    MIATerminalTools() = default;

    ~MIATerminalTools() = default;

    /**
     * Prints a blank line.
     */
    static void blankLine();

    /**
     * Displays a blank line surrounded by dots - used for formatting.
     */
    static void blankDots();
};