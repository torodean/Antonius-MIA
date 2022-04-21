/**
 * File: StringUtils.cpp
 * Author: Antonius Torode
 * Date: 03/01/2021
 * Description:
 */

#include <string>
#include <vector>

/**
 * This is a class for any string manipulation and related functions.
 */
class StringUtils
{
public:

    StringUtils() = default;

    ~StringUtils() = default;

    /**
     * Converts a string to lower case.
     * @param input[std::string&] - Reference to the string to convert.
     * @return [std::string] - Lower case string.
     */
    static std::string toLower(std::string& input);

    /**
     * Removes a specific character from a string.
     * @param str[std::string] - the input string to parse.
     * @param c[char] - the character to remove.
     * @return [std::string] The string without hte character.
     */
    static std::string removeCharInString(std::string str, char c);

    /**
     * Finds the index of the first occurrence of a char in a string.
     * @param input[std::string] - reference to the input string to parse.
     * @param c[char] - the character to find.
     * @return [int] location of the character in the string.
     */
    static int findCharInString(std::string& input, char c);

    /**
     * Determines if a character is contained within a string.
     * @param input[std::string] - reference to the input string to parse.
     * @param c[char] - the character to find.
     * @return [bool] Returns true if the character is in the string.
     */
    static bool stringContainsChar(std::string& input, char c);

    /**
     * Separates a string into components via a delimiter.
     * @param input[std::string] - reference to the input string to parse.
     * @param delimiter[std::string] - Delimiter to use when parsing.
     * @param verboseMode[bool] - enables verboseMode output (default = false)
     * @return
     */
    static std::vector<std::string> delimiterString(std::string& input, const std::string &delimiter, bool verboseMode = false);

    /**
     * Function for determining if all characters in a string are digits/integers.
     * @param input[std::string] - reference to the input string to parse.
     * @return returns true if all characters are integers.
     */
    static bool is_digits(const std::string& input);

    /**
     * Determines if a string is of the format for a dice roll. i.e 1d20 or 3d8.
     * @param input[std::string] - reference to the input string to parse.
     * @return [bool] True if the string is a dice roll.
     */
    static bool inputRoll(std::string &input);

    /**
     * A function used to determine if an answer is equivalent to yes.
     * @param input[std::string] - reference to the input string to parse.
     * @return returns true if answer is a form of yes.
     */
    static bool formOfYes(std::string &input);

    /**
     * Returns the date for today.
     * @return[std::string] A string representing the current date.
     */
    static std::string today();

    /**
     * Returns a shuffled string.
     * @param input the string to shuffle.
     * @return std::string that has been shuffled.
     */
    static std::string shuffleString(std::string input);

    /**
     *
     * @param line
     * @param c
     * @return
     */
    static std::string getBeforeChar(std::string line, char c);

    /**
     *
     * @param line
     * @param c
     * @return
     */
    static std::string getAfterChar(std::string line, char c);

    /**
     *
     * @param line
     * @return
     */
    static std::string getBetweenEqualAndSemiColon(std::string line);

    /**
     * This will create two strings of 'entangled' text. The first string contains every other character
     * of the input string and the second string contains the opposite characters. Spaces are added
     * in place of the characters not shown in each output string so that they can be easily matched.
     * @param input the input string to entangle.
     * @return std::vector<std::string>, the first element is the first half,
     *                                   and second element the second half.
     */
    static std::vector<std::string> entangleText(const std::string& input);

};
