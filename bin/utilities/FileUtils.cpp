/**
 * File: FileUtils.cpp
 * Author: Antonius Torode
 * Date: 03/07/2021
 * Description:
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "FileUtils.hpp"
#include "MathUtils.hpp"
#include "../program/Configurator.hpp"
#include "../terminal/MIATerminal.hpp"
#include "../program/Error.hpp"

using std::string;
using std::cout;
using std::endl;

string FileUtils::getRandomLineOfFile(string& fileName){
    int counter = 0;
    string output;
    std::ifstream file(fileName);

    while (getline(file, output)){
        counter++;
    }
    file.close();

    std::ifstream file2(fileName);
    int random = MathUtils::randomInt(1,counter, 0, true);
    counter = 0;

    while (getline(file2, output)){
        counter++;
        if(counter == random){
            return output;
        }
    }
    return "ERROR";
}

void FileUtils::printRandomLinesFromFile(bool useDefaultPath, int numberOfLines)
{
    Configurator config;
    string fileName;
    string fullPath;

    //Checks the user for where the file is located.
    if (useDefaultPath){
        cout << "...Please enter an input file: ";
        getline(std::cin, fileName);
        fullPath = config.getFilePath("inputFilePath") + fileName;
        MIATerminalTools::blankLine();
    } else {
        cout << "...Please enter an input file (full path included): ";
        getline(std::cin, fileName);
        fullPath = fileName;
        MIATerminalTools::blankLine();
    }

    //grabs the file.
    std::ifstream file(fullPath,std::ifstream::in);

    //Checks if the file exists and runs the code.
    if (file.good()){
        string line;
        std::vector<string> lines;

        while(getline(file,line)){
            //cout << line << endl;
            lines.push_back(line);
        }

        int listSize = lines.size();
        srand(time(nullptr));
        int randomNum;

        for(int i=0; i<numberOfLines; i++){
            randomNum = rand() % listSize;
            cout << lines[randomNum] << endl;
        }
    } else {
        Error::returnError(41404);
    }
}