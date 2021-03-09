/**
 * File: FileUtils.cpp
 * Author: Antonius Torode
 * Date: 03/07/2021
 * Description:
 */

#ifndef MIA2_FILEUTILS_HPP
#define MIA2_FILEUTILS_HPP

class FileUtils
{
public:

    /**
     * Main default constructor for file utilities.
     */
    FileUtils() = default;

    /**
     * Main destructor of file utilities.
     */
    ~FileUtils() = default;

    /**
     * Returns the random line of a specified text file.
     * @param fileName[std::string] Input file to parse.
     * @return [std::string] Returns a random line of the file.
     */
    static std::string getRandomLineOfFile(std::string& fileName);

    /**
     * Takes a file as an input and prints an input number of random lines from it.
     * @param useDefaultPath[bool] - true if using the default MIA inputFilePath from the MIAConfig.MIA file.
     * @param numberOfLines[int] - The number of lines to return
     */
    static void printRandomLinesFromFile(bool useDefaultPath, int numberOfLines);

protected:

};

#endif //MIA2_FILEUTILS_HPP
