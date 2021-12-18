/**
 * File: StringUtils.cpp
 * Author: Antonius Torode
 * Date: 03/01/2021
 * Description:
 */

#include <iostream>
#include <random>
#include <utility>
#include <vector>
#include <ctime>
#include "StringUtils.hpp"
#include "Configurator.hpp"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::to_string;

std::string StringUtils::toLower(std::string &input)
{
    std::string output = input;
    for(int i=0; input[i]; i++)
    {
        output[i] = std::tolower(input[i]);
    }
    return output;
}

std::string StringUtils::removeCharInString(string str, char c)
{
    str.erase(remove(str.begin(), str.end(), c), str.end());
    return str;
}

int StringUtils::findCharInString(string& input, char c)
{
    int length = input.size();
    for (int i=0; i<length; i++)
    {
        if(input[i] == c)
        {
            return i;
        }
    }
    return 0;
}

bool StringUtils::stringContainsChar(string& input, char c)
{
    if(findCharInString(input, c) == 0)
        return false;
    return true;
}

vector<string> StringUtils::delimiterString(string& input, const string& delimiter, bool verboseMode)
{
    if(verboseMode)
        cout << "input string: " << input << endl;
    vector<string> output;
    size_t pos;
    std::string item;
    while ((pos = input.find(delimiter)) != string::npos)
    {
        item = input.substr(0, pos);
        output.push_back(item);
        if(verboseMode)
            cout << "delimiter item: " << item << endl;
        input.erase(0, pos + delimiter.length());
    }
    output.push_back(input);
    if(verboseMode)
        cout << "delimiter item: " << input << endl;
    int outputSize = output.size();
    if(verboseMode)
    {
        cout << "Contents of output: ";
        for(int i=0; i<outputSize; i++)
        {
            cout << output[i];
            if(i != outputSize - 1)
                cout << delimiter;
        }
        cout << endl;
    }
    return output;
}

bool StringUtils::is_digits(const string& input)
{
    if(input.find_first_not_of("0123456789") == string::npos)
        return true;
    return false;
}

bool StringUtils::inputRoll(string& input)
{
    if(input.size() <= 6 && input.find('d') != string::npos &&
       input.find_first_not_of("1234567890d") == string::npos &&
       delimiterString(input, "d", false).size() == 2)
    {
        return true;
    }
    return false;
}

bool StringUtils::formOfYes(string& input)
{
    if (toLower(input) == "y" ||
        toLower(input) == "yes" ||
        toLower(input) == "sure" ||
        toLower(input) == "indeed" ||
        toLower(input) == "ok" ||
        toLower(input) == "okay")
    {
        return true;
    } else {
        return false;
    }
}

string StringUtils::today()
{
    std::time_t t = std::time(nullptr);   // get time now
    std::tm* now = std::localtime(&t);
    string month = to_string(now->tm_mon + 1);
    string day = to_string(now->tm_mday);
    string year = to_string(now->tm_year + 1900);
    string todaysDate =  month + "-" + day + "-" + year;
    return todaysDate;
}

string StringUtils::shuffleString(string input)
{
    string output = std::move(input);
    shuffle(output.begin(), output.end(), std::mt19937(std::random_device()()));
    return output;
}


string StringUtils::getBeforeChar(string line, char c){
    int equalSignLocation = findCharInString(line, c);

    if(Configurator::getVerboseMode())
        cout << "...stringBeforeEqual: " << line.substr(0, equalSignLocation) << endl;

    return line.substr(0, equalSignLocation);
}

string StringUtils::getBetweenEqualAndSemiColon(string line){
    int equalSignLocation = findCharInString(line, '=');
    int semiColonLocation = findCharInString(line, ';');

    //First remove everything after the semi colon sign. Then keep everything after the equal sign.
    line = line.substr(0,semiColonLocation);
    line = line.substr(equalSignLocation+1,line.size()-1);

    if(Configurator::getVerboseMode())
        cout << "...stringBetweenEqualAndSemiColon: " << line << endl;

    return line;
}

string StringUtils::getAfterChar(string line, char c){
    int semiColonLocation = findCharInString(line, c);

    if(Configurator::getVerboseMode())
        cout << "...stringAfterSemiColon: " << line.substr(semiColonLocation+1,line.size()-1) << endl;

    return line.substr(semiColonLocation+1,line.size()-1);
}
