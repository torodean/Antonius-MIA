/**
 * File: Configurator.cpp
 * Author: Antonius Torode
 * Date: 03/01/2021
 * Description:
 */

#include <iostream>
#include <fstream>
#include <vector>
#include "Configurator.hpp"
#include "../utilities/StringUtils.hpp"
#include "Error.hpp"

using std::string;
using std::cout;
using std::endl;

bool Configurator::ProgramVariables::verboseMode = false;

Configurator::Configurator() : VERSION("0.200")
{
    initialize();
    initializeSettings(false);
}

void Configurator::initialize()
{

}

void Configurator::setVerboseMode(string value)
{
    value = StringUtils::removeCharInString(value, ' ');
    if (value == "true" || value == "1")
        ProgramVariables::verboseMode = true;
    else
        ProgramVariables::verboseMode  = false;
}

void Configurator::setVerboseMode(bool value)
{
    if (value)
        ProgramVariables::verboseMode  = true;
    else
        ProgramVariables::verboseMode  = false;
}

bool Configurator::getVerboseMode()
{
    return ProgramVariables::verboseMode ;
}


void Configurator::initializeSettings(bool printSettings)
{
    //grabs the MIAConfig file.
    std::ifstream file(programFilePaths.MIAConfigFile, std::ifstream::in);

    //Checks if the file exists and runs the code.
    if (file.good())
    {
        string line;
        std::vector<string> lines;

        //If true, print the configuration file settings.
        if (getVerboseMode())
        {
            cout << endl << "...Config file output: " << endl;
        }
        while(getline(file,line))
        {
            if (line[0] != '#' && !line.empty() && line.size()>2)
            {
                if(getVerboseMode())
                {
                    cout << line << endl;
                }
                lines.push_back(line);
            }
        }
        if(getVerboseMode())
        {
            cout << endl;
        }
        int size = lines.size();
        int equalSignLocation;
        string variable, value;
        for (int i=0; i<size;i++)
        {
            equalSignLocation = StringUtils::findCharInString(lines[i], '=');
            variable = lines[i].substr(0, equalSignLocation);
            value = lines[i].substr(equalSignLocation+1,lines[i].size()-1);

            //removes end of line characters from variable name and value. Fixes a bug.
            variable.erase(remove(variable.begin(), variable.end(), '\r'), variable.end());
            value.erase(remove(value.begin(), value.end(), '\r'), value.end());

            if(printSettings)
            {
                cout << "...Setting variable: " << variable << " to '" << value << "'" << endl;
            }
            setMIAVariables(variable, value);
        }
    } else {
        if (printSettings)
        {
            Error::returnError(31403);
            Error::returnError(31404);
        }
    }
}


void Configurator::setMIAVariables(const string& variable, const string& value)
{
    //Sets the appropriate variable values.
    if (variableIsFilePath(variable)){
        setFilePath(variable, value);
    } else if (variable == "WoWMailboxSendLetterLocationX"){
        setWoWMailboxSendLetterLocation('x',value);
    } else if (variable == "WoWMailboxSendLetterLocationY"){
        setWoWMailboxSendLetterLocation('y',value);
    } else if (variable == "WoWMailboxFirstLetterLocationX"){
        setWoWMailboxFirstLetterLocation('x',value);
    } else if (variable == "WoWMailboxFirstLetterLocationY"){
        setWoWMailboxFirstLetterLocation('y',value);
    } else if (variable == "WoWFishBotStartX"){
        setWoWFishBotSpace("startX", value);
    } else if (variable == "WoWFishBotStartY"){
        setWoWFishBotSpace("startY", value);
    } else if (variable == "WoWFishBotEndX"){
        setWoWFishBotSpace("endX", value);
    } else if (variable == "WoWFishBotEndY"){
        setWoWFishBotSpace("endY", value);
    } else if (variable == "WoWFishBotIncrement"){
        setWoWFishBotSpace("increment", value);
    } else if (variable == "WoWFishBotNumOfCasts"){
        setWoWFishBotSpace("casts", value);
    } else if (variable == "WoWFishBotDelay"){
        setWoWFishBotSpace("delay", value);
    } else if (variable == "WoWMailboxLootLetterLocationX"){
        setWoWMailboxLootLetterLocation('x',value);
    } else if (variable == "WoWMailboxLootLetterLocationY"){
        setWoWMailboxLootLetterLocation('y',value);
    } else if (variable == "WoWMailboxDeleteLetterLocationX"){
        setWoWMailboxDeleteLetterLocation('x',value);
    } else if (variable == "WoWMailboxDeleteLetterLocationY"){
        setWoWMailboxDeleteLetterLocation('y',value);
    } else if (variable == "verboseMode"){
        setVerboseMode(value);
    } else if (variable == "defaultButtonCombination"){
        setDefaultButtonCombination(value);
    } else {
        Error::returnError(31417, variable);
    }
}


Configurator::ProgramFilePaths::filePathType Configurator::stringFilePathToEnumFilePath(const std::string& filePath)
{
    if(filePath == "MIAConfigFilePath")
        return ProgramFilePaths::filePathType::MIACONFIGFILEPATH;
    if (filePath == "inputFilePath")
        return ProgramFilePaths::filePathType::INPUTFILEPATH;
    if( filePath == "cryptFilePath")
        return ProgramFilePaths::filePathType::CRYPTFILEPATH;
    if (filePath == "decryptFilePath")
        return ProgramFilePaths::filePathType::DECRYPTFILEPATH;
    if (filePath == "workoutsFilePath")
        return ProgramFilePaths::filePathType::WORKOUTSFILEPATH;
    if (filePath == "sequencesFilePath")
        return ProgramFilePaths::filePathType::SEQUENCESFILEPATH;
    if (filePath == "workoutOutputFilePath")
        return ProgramFilePaths::filePathType::WORKOUTOUTPUTFILEPATH;
    if (filePath == "excuseFilePath")
        return ProgramFilePaths::filePathType::EXCUSEFILEPATH;

    return ProgramFilePaths::filePathType::UNKNOWNFILEPATH;
}

std::string Configurator::enumFilePathToStringFilePath(Configurator::ProgramFilePaths::filePathType filePath)
{
    switch (filePath)
    {
        case ProgramFilePaths::MIACONFIGFILEPATH: return "MIAConfigFilePath";
        case ProgramFilePaths::EXCUSEFILEPATH: return "excuseFilePath";
        case ProgramFilePaths::INPUTFILEPATH: return "inputFilePath";
        case ProgramFilePaths::WORKOUTSFILEPATH: return "workoutsFilePath";
        case ProgramFilePaths::WORKOUTOUTPUTFILEPATH: return "workoutOutputFilePath";
        case ProgramFilePaths::CRYPTFILEPATH: return "cryptFilePath";
        case ProgramFilePaths::DECRYPTFILEPATH: return "decryptFilePath";
        case ProgramFilePaths::SEQUENCESFILEPATH: return "sequencesFilePath";

        case ProgramFilePaths::UNKNOWNFILEPATH:
        default:
            return "unknownFilePath";
    }
}

bool Configurator::variableIsFilePath(const string& variable)
{
    if (variable == "inputFilePath"
        || variable == "cryptFilePath"
        || variable == "decryptFilePath"
        || variable == "workoutsFilePath"
        || variable == "sequencesFilePath"
        || variable == "workoutOutputFilePath"
        || variable == "excuseFilePath")
    {
        return true;
    }
    return false;
}

bool Configurator::variableIsFilePath(ProgramFilePaths::filePathType variable)
{
    switch (variable)
    {
        case ProgramFilePaths::filePathType::MIACONFIGFILEPATH:
        case ProgramFilePaths::EXCUSEFILEPATH:
        case ProgramFilePaths::INPUTFILEPATH:
        case ProgramFilePaths::WORKOUTSFILEPATH:
        case ProgramFilePaths::WORKOUTOUTPUTFILEPATH:
        case ProgramFilePaths::CRYPTFILEPATH:
        case ProgramFilePaths::DECRYPTFILEPATH:
        case ProgramFilePaths::SEQUENCESFILEPATH:
            return true;
        case ProgramFilePaths::UNKNOWNFILEPATH:
        default:
            return false;
    }
}


void Configurator::setFilePath(const string& filePath, const string& input)
{
    if(filePath == "MIAConfigFile")
        programFilePaths.MIAConfigFile = input;
    else if(filePath == "excuseFilePath")
        programFilePaths.excuseFilePath = input;
    else if(filePath == "inputFilePath")
        programFilePaths.inputFilePath = input;
    else if(filePath == "cryptFilePath")
        programFilePaths.cryptFilePath = input;
    else if(filePath == "decryptFilePath")
        programFilePaths.decryptFilePath = input;
    else if(filePath == "workoutsFilePath")
        programFilePaths.workoutsFilePath = input;
    else if(filePath == "sequencesFilePath")
        programFilePaths.sequencesFilePath = input;
    else if(filePath == "workoutOutputFilePath")
        programFilePaths.workoutOutputFilePath = input;
    else
    {
        string configLine = filePath + ": " + input;
        Error::returnError(31419, configLine);
    }
}

void Configurator::setFilePath(ProgramFilePaths::filePathType filePath, const string &input)
{
    switch (filePath)
    {
        case ProgramFilePaths::MIACONFIGFILEPATH:
            programFilePaths.MIAConfigFile = input;
            break;
        case ProgramFilePaths::EXCUSEFILEPATH:
            programFilePaths.excuseFilePath = input;
            break;
        case ProgramFilePaths::INPUTFILEPATH:
            programFilePaths.inputFilePath = input;
            break;
        case ProgramFilePaths::WORKOUTSFILEPATH:
            programFilePaths.workoutsFilePath = input;
            break;
        case ProgramFilePaths::WORKOUTOUTPUTFILEPATH:
            programFilePaths.workoutOutputFilePath = input;
            break;
        case ProgramFilePaths::CRYPTFILEPATH:
            programFilePaths.cryptFilePath = input;
            break;
        case ProgramFilePaths::DECRYPTFILEPATH:
            programFilePaths.decryptFilePath = input;
            break;
        case ProgramFilePaths::SEQUENCESFILEPATH:
            programFilePaths.sequencesFilePath = input;
            break;
        case ProgramFilePaths::UNKNOWNFILEPATH:
        default:
            string configLine = filePath + ": " + input;
            Error::returnError(31419, configLine);
            break;
    }
}


string Configurator::getFilePath(const string& filePath)
{
    if(filePath == "MIAConfigFile")
        return programFilePaths.MIAConfigFile;
    if(filePath == "excuseFilePath")
        return programFilePaths.excuseFilePath;
    if(filePath == "inputFilePath")
        return programFilePaths.inputFilePath;
    if(filePath == "cryptFilePath")
        return programFilePaths.cryptFilePath;
    if(filePath == "decryptFilePath")
        return programFilePaths.decryptFilePath;
    if(filePath == "workoutsFilePath")
        return programFilePaths.workoutsFilePath;
    if(filePath == "workoutOutputFilePath")
        return programFilePaths.workoutOutputFilePath;
    if(filePath == "sequencesFilePath")
        return programFilePaths.sequencesFilePath;
    else
    {
        Error::returnError(31419, filePath);
        return "";
    }
}

std::string Configurator::getFilePath(Configurator::ProgramFilePaths::filePathType filePath)
{
    switch (filePath)
    {
        case ProgramFilePaths::MIACONFIGFILEPATH: return programFilePaths.MIAConfigFile;
        case ProgramFilePaths::EXCUSEFILEPATH: return programFilePaths.excuseFilePath;
        case ProgramFilePaths::INPUTFILEPATH: return programFilePaths.inputFilePath;
        case ProgramFilePaths::WORKOUTSFILEPATH: return programFilePaths.workoutsFilePath;
        case ProgramFilePaths::WORKOUTOUTPUTFILEPATH: return programFilePaths.workoutOutputFilePath;
        case ProgramFilePaths::CRYPTFILEPATH: return programFilePaths.cryptFilePath;
        case ProgramFilePaths::DECRYPTFILEPATH: return programFilePaths.decryptFilePath;
        case ProgramFilePaths::SEQUENCESFILEPATH: return programFilePaths.sequencesFilePath;
        case ProgramFilePaths::UNKNOWNFILEPATH:
        default:
            Error::returnError(31419, Configurator::enumFilePathToStringFilePath(filePath));
            return "unknownFilePath";
    }
}

void Configurator::setWoWMailboxSendLetterLocation(char coord, const string& value)
{
    if (StringUtils::is_digits(value))
    {
        if(coord == 'x')
            wowProgramVariables.WoWMailboxSendLetterLocationX = stoi(value);
        else if (coord == 'y')
            wowProgramVariables.WoWMailboxSendLetterLocationY = stoi(value);
    }
    else
    {
        if(Configurator::getVerboseMode())
            Error::returnError(31417);
    }
}
int Configurator::getWoWMailboxSendLetterLocation(char coord)
{
    if(coord == 'x')
        return wowProgramVariables.WoWMailboxSendLetterLocationX;
    if (coord == 'y')
        return wowProgramVariables.WoWMailboxSendLetterLocationY;
    return 0;
}
void Configurator::setWoWMailboxFirstLetterLocation(char coord, const string& value)
{
    if (StringUtils::is_digits(value)){
        if(coord == 'x'){
            wowProgramVariables.WoWMailboxFirstLetterLocationX = stoi(value);
        } else if (coord == 'y'){
            wowProgramVariables.WoWMailboxFirstLetterLocationY = stoi(value);
        }
    } else {
        if(Configurator::getVerboseMode())
            Error::returnError(31417);
    }
}
int Configurator::getWoWMailboxFirstLetterLocation(char coord)
{
    if(coord == 'x')
        return wowProgramVariables.WoWMailboxFirstLetterLocationX;
    if (coord == 'y')
        return wowProgramVariables.WoWMailboxFirstLetterLocationY;
    return 0;
}
void Configurator::setWoWMailboxLootLetterLocation(char coord, const string& value)
{
    if (StringUtils::is_digits(value))
    {
        if(coord == 'x')
            wowProgramVariables.WoWMailboxLootLetterLocationX = stoi(value);
        else if (coord == 'y')
            wowProgramVariables.WoWMailboxLootLetterLocationY = stoi(value);
    }
    else
    {
        if(Configurator::getVerboseMode())
            Error::returnError(31417);
    }
}
int Configurator::getWoWMailboxLootLetterLocation(char coord)
{
    if(coord == 'x')
        return wowProgramVariables.WoWMailboxLootLetterLocationX;
    if (coord == 'y')
        return wowProgramVariables.WoWMailboxLootLetterLocationY;
    return 0;
}

void Configurator::setWoWMailboxDeleteLetterLocation(char coord, const string& value)
{
    if (StringUtils::is_digits(value))
    {
        if(coord == 'x')
            wowProgramVariables.WoWMailboxDeleteLetterLocationX = stoi(value);
        else if (coord == 'y')
            wowProgramVariables.WoWMailboxDeleteLetterLocationY = stoi(value);
    }
    else
    {
        if(Configurator::getVerboseMode())
            Error::returnError(31417);
    }
}

int Configurator::getWoWMailboxDeleteLetterLocation(char coord)
{
    if(coord == 'x')
        return wowProgramVariables.WoWMailboxDeleteLetterLocationX;
    if (coord == 'y')
        return wowProgramVariables.WoWMailboxDeleteLetterLocationY;
    return 0;
}

void Configurator::setWoWFishBotSpace(const string& data, const string& value)
{
    if (StringUtils::is_digits(value))
    {
        if(data == "startX")
            wowProgramVariables.WoWFishBotStartX = stoi(value);
        else if (data == "startY")
            wowProgramVariables.WoWFishBotStartY = stoi(value);
        else if (data == "endX")
            wowProgramVariables.WoWFishBotEndX = stoi(value);
        else if (data == "endY")
            wowProgramVariables.WoWFishBotEndY = stoi(value);
        else if (data == "increment")
            wowProgramVariables.WoWFishBotIncrement = stoi(value);
        else if (data == "casts")
            wowProgramVariables.WoWFishBotNumOfCasts = stoi(value);
        else if (data == "delay")
            wowProgramVariables.WoWFishBotDelay = stoi(value);
    }
    else
    {
        if(Configurator::getVerboseMode())
            Error::returnError(31417);
    }
}


int Configurator::getWoWFishBotSpace(const string& data)
{
    if(data == "startX")
        return wowProgramVariables.WoWFishBotStartX;
    if (data == "startY")
        return wowProgramVariables.WoWFishBotStartY;
    if (data == "endX")
        return wowProgramVariables.WoWFishBotEndX;
    if (data == "endY")
        return wowProgramVariables.WoWFishBotEndY;
    if (data == "increment")
        return wowProgramVariables.WoWFishBotIncrement;
    if (data == "casts")
        return wowProgramVariables.WoWFishBotNumOfCasts;
    if (data == "delay")
        return wowProgramVariables.WoWFishBotDelay;
    else
        return 0;
}

void Configurator::setDefaultButtonCombination(const string& input)
{
    sequencerVariables.defaultButtonCombination = input;
}
string Configurator::getDefaultButtonCombination() const
{
    return sequencerVariables.defaultButtonCombination;
}

//Returns the Version number of MIA.
string Configurator::getMIAVersion(){
    return VERSION;
}