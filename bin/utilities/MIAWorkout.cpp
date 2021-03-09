/**
 * File: MIAWorkout.cpp
 * Author: Antonius Torode
 * Date: 03/07/2021
 * Description:
 */

#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "MIAWorkout.hpp"
#include "../terminal/MIATerminal.hpp"
#include "StringUtils.hpp"
#include "MathUtils.hpp"
#include "../program/Error.hpp"

using std::string;
using std::cout;
using std::endl;
using std::vector;

double MIAWorkout::convertWorkoutWeight(const string& line)
{
    return stod(line);
}


double MIAWorkout::maxNumModifier(double min, double max, double difficulty)
{
    return (max/(10.0*pow(10.0,(1.0/3.0))) - min/(10.0*pow(10.0,(1.0/3.0))))*pow(difficulty,(2.0/3.0))+min;
}

double MIAWorkout::minNumModifier(double min, double max, double difficulty)
{

    //adjusts the min compared to max.
    //Set such that new curves are similar to old workout generation functions.
    double minModifier = 1.9;

    return (-((-max + min*minModifier)/(10.0*pow(10.0,(1.0/3.0))*minModifier)))*pow(difficulty,(2.0/3.0)) + min;
}

void MIAWorkout::generateWorkout(double difficulty, bool weekly) const
{
    //Int to keep track of whether we need to generate a weekly workout or not.
    int timesToGenerate = 1;
    std::ofstream out;

    if(weekly)
    {
        string outputFile = config.programFilePaths.workoutOutputFilePath;
        outputFile.erase(outputFile.end()-4,outputFile.end());
        outputFile += " ";
        outputFile += __DATE__;
        outputFile += ".txt";

        cout << "...Weekly workout generation loaded. " << endl;
        cout << "...Workout will be output to '" << outputFile << "'" << endl;
        MIATerminalTools::blankDots();

        string outputFileText = "//============================================================================\n"
                                "// Name        : workout.txt                                                  \n"
                                "// Author      : MIA                                                          \n"
                                "// Created on  : " + StringUtils::today() + "                                         \n"
                                "// Description : A daily generated workout via the MIA program (for one week).\n"
                                "// Difficulty  : " + std::to_string(difficulty) + "                           \n"
                                "//============================================================================\n\n";

        timesToGenerate = 7; //generate 7 workouts
        out.open(outputFile);
        out << outputFileText;
    }

    MIATerminalTools::blankDots();
    cout << "...Loading MIA workout generation. " << endl;
    MIATerminalTools::blankDots();

    //grabs the workouts file.
    string fileName = config.programFilePaths.workoutsFilePath;
    std::ifstream file(fileName,std::ifstream::in);

    //Checks if the file exists and gathers the variables.
    if (file.good())
    {
        string line;
        vector<string> lines;

        //If true, print the workouts file.
        if (Configurator::getVerboseMode())
        {
            cout << endl << "...Workouts file output: " << endl;
        }
        while(getline(file,line))
        {
            if (line[0] != '#' && !line.empty() && line.size()>2)
            {
                if(Configurator::getVerboseMode()){
                    cout << line << endl;
                }

                //remove spaces from each line for processing
                line.erase(remove(line.begin(), line.end(), ' '), line.end());
                //removes end of line characters from variable name and value. Fixes a bug.
                line.erase(remove(line.begin(), line.end(), '\r'), line.end());
                line.erase(remove(line.begin(), line.end(), '\n'), line.end());

                lines.push_back(line);
            }
        }
        if(Configurator::getVerboseMode())
        {
            cout << endl;
        }
        if(Configurator::getVerboseMode())
            cout << "...Finished reading in workouts file. " << endl;

        //Creates and stores workouts file/program variables.
        vector<string> workoutName;
        vector<double> workoutWeight;
        vector<string> workoutUnit;
        int size = lines.size();
        double toughness = 0.1;
        double minNumOfExercises = 3.0;
        double maxNumOfExercises = (double)size-5.0; //Minus 5 because there are 5 non-workout variables.
        double minNumOfSets = 1.0;
        double maxNumOfSets = 10.0;

        //For keeping track of how many variables are in the workouts file.
        int numOfVariables = 5, variableCount = 0;
        bool foundVar = false;

        string variable;
        int equalSignLocation;

        //Read the workouts input file and grab the variables.
        for(int i=0; i<numOfVariables; i++)
        {
            //Finds what the variable input is if one exists.
            variable = StringUtils::getBeforeChar(lines[i], '=');

            //Sets the toughness variable.
            if(variable == "toughness"){
                if(Configurator::getVerboseMode())
                    cout << "...toughness variable discovered. " << endl;

                equalSignLocation = StringUtils::findCharInString(lines[i], '=');
                toughness = stod(lines[i].substr(equalSignLocation+1,lines[i].size()-1));

                if(Configurator::getVerboseMode())
                    cout << "...toughness: " << toughness << endl;
                foundVar = true;
                //Sets the minNumOfExercises if one exists.
            }
            else if(variable  == "minNumOfExercises")
            {
                if(Configurator::getVerboseMode())
                    cout << "...minNumOfExercises variable discovered. " << endl;

                equalSignLocation = StringUtils::findCharInString(lines[i], '=');
                minNumOfExercises = stod(lines[i].substr(equalSignLocation+1,lines[i].size()-1));

                if(Configurator::getVerboseMode())
                    cout << "...minNumOfExercises: " << (int)minNumOfExercises << endl;
                foundVar = true;
                //Sets the maxNumOfExercises if one exists.
            }
            else if(variable  == "maxNumOfExercises")
            {
                if(Configurator::getVerboseMode())
                    cout << "...maxNumOfExercises variable discovered. " << endl;

                equalSignLocation = StringUtils::findCharInString(lines[i], '=');
                if(lines[i].substr(equalSignLocation+1,lines[i].size()-1) != "inf"){
                    maxNumOfExercises = stod(lines[i].substr(equalSignLocation+1,lines[i].size()-1));
                }

                if(Configurator::getVerboseMode())
                    cout << "...maxNumOfExercises: " << (int)maxNumOfExercises << endl;
                foundVar = true;
                //Sets the minNumOfSets if one exists.
            }
            else if(variable  == "minNumOfSets")
            {
                if(Configurator::getVerboseMode())
                    cout << "...minNumOfSets variable discovered. " << endl;

                equalSignLocation = StringUtils::findCharInString(lines[i], '=');
                minNumOfSets = stod(lines[i].substr(equalSignLocation+1,lines[i].size()-1));

                if(Configurator::getVerboseMode())
                    cout << "...minNumOfSets: " << (int)minNumOfSets << endl;
                foundVar = true;
                //Sets the maxNumOfSets variable if one was found.
            }
            else if(variable  == "maxNumOfSets")
            {
                if(Configurator::getVerboseMode())
                    cout << "...maxNumOfSets variable discovered. " << endl;

                equalSignLocation = StringUtils::findCharInString(lines[i], '=');
                if(lines[i].substr(equalSignLocation+1,lines[i].size()-1) != "inf")
                {
                    maxNumOfSets = stod(lines[i].substr(equalSignLocation+1,lines[i].size()-1));
                }

                if(Configurator::getVerboseMode())
                    cout << "...maxNumOfSets: " << (int)maxNumOfSets << endl;
                foundVar = true;
            }

            //Counter to see if variable wasn't found in workouts file.
            if (!foundVar)
                variableCount++;
            else
                foundVar = true;
        }

        //Accounts for variables not found in workouts file.
        numOfVariables = numOfVariables - variableCount;
        lines.erase(lines.begin(), lines.begin()+numOfVariables);

        //Sets the workout file variables and the weighted value.
        for(int i=0; i < size-numOfVariables; i++)
        {
            workoutName.push_back( StringUtils::getBeforeChar(lines[i], '=') );
            workoutWeight.push_back( convertWorkoutWeight( StringUtils::getBetweenEqualAndSemiColon(lines[i]) ) );
            workoutUnit.push_back( StringUtils::getAfterChar(lines[i], ';') );

            if(Configurator::getVerboseMode())
            {
                cout << "...Printing values set. " << endl;
                cout << workoutName[i] << ": ";
                cout << workoutWeight[i] << " ";
                cout << workoutUnit[i] << endl;
            }
        }

        cout << "...Running workout generation. " << endl;

        int counter = 1; //For changing random integers between calls.

        //Loops over the generation code however many times needed.
        while(timesToGenerate > 0)
        {

            if(!weekly){
                MIATerminalTools::blankLine();
            } else if(timesToGenerate == 7){
                out << "##############\n"
                       "### SUNDAY ###\n"
                       "##############" << endl << endl;
            } else if(timesToGenerate == 6){
                out << "##############\n"
                       "### MONDAY ###\n"
                       "##############" << endl << endl;
            } else if(timesToGenerate == 5){
                out << "###############\n"
                       "### TUESDAY ###\n"
                       "###############" << endl << endl;
            } else if(timesToGenerate == 4){
                out << "#################\n"
                       "### WEDNESDAY ###\n"
                       "#################" << endl << endl;
            } else if(timesToGenerate == 3){
                out << "################\n"
                       "### THURSDAY ###\n"
                       "################" << endl << endl;
            } else if(timesToGenerate == 2){
                out << "##############\n"
                       "### FRIDAY ###\n"
                       "##############" << endl << endl;
            } else if(timesToGenerate == 1){
                out << "################\n"
                       "### SATURDAY ###\n"
                       "################" << endl << endl;
            }

            //Calculates workout routine

            /* Old functions for workout calculations.
            double maxNumOfExercisesModifier = (maxNumOfExercises-minNumOfExercises)/100.0 * difficulty + minNumOfExercises;
            double minNumOfExercisesModifier = (maxNumOfExercises-minNumOfExercises)/200.0 * difficulty + minNumOfExercises;
            double maxNumOfSetsModifier = (maxNumOfSets-minNumOfSets)/100.0 * difficulty + minNumOfSets;
            double minNumOfSetsModifier = (maxNumOfSets-minNumOfSets)/200.0 * difficulty + minNumOfSets;
            */

            // Improved functions for workout calculations
            double maxNumOfExercisesModifier = maxNumModifier(minNumOfExercises, maxNumOfExercises, difficulty);
            double minNumOfExercisesModifier = minNumModifier(minNumOfExercises, maxNumOfExercises, difficulty);
            double maxNumOfSetsModifier = maxNumModifier(minNumOfSets, maxNumOfSets, difficulty);
            double minNumOfSetsModifier = minNumModifier(minNumOfSets, maxNumOfSets, difficulty);


            int numOfWorkouts;
            counter++;
            int numOfSets = MathUtils::randomInt((int)minNumOfSetsModifier,(int)maxNumOfSetsModifier,counter, true);

            if(Configurator::getVerboseMode())
            {
                cout << "...numOfSets: " << numOfSets << endl;
            }
            if(weekly)
            {
                out << "...Number of sets: " << numOfSets << endl << endl;
            } else {
                cout << "...Number of sets: " << numOfSets << endl;
                MIATerminalTools::blankLine();
            }

            //declares some needed variables.
            vector<bool> workoutChosen;
            workoutChosen.reserve(size-numOfVariables);
            for(int i=0; i<size-numOfVariables; i++)
            {
                workoutChosen.push_back(false);
            }
            counter++;
            int randNum = MathUtils::randomInt(0,size-numOfVariables,counter, true);
            int set = 1;
            double repsMin, repsMax, repsModifier;

            //Loops over the stuff and creates a random workout for each set.
            while (numOfSets > 0)
            {
                counter++;
                if(weekly){ //prints results.
                    out << "...Workout for set " << set << "." << endl << endl;
                } else {
                    cout << "...Workout for set " << set << "." << endl;
                    MIATerminalTools::blankLine();
                }


                for (int i=0; i < size-numOfVariables; i++){
                    workoutChosen[i] = false;
                }

                //randomizes the number of workouts per set.
                int randCounter = randNum;
                numOfWorkouts = MathUtils::randomInt((int)minNumOfExercisesModifier, (int)maxNumOfExercisesModifier, randCounter, true);

                //determines which workouts to use.
                for(int i=0;i<numOfWorkouts; i++){
                    randNum = MathUtils::randomInt(0,size-numOfVariables,randCounter, true);
                    while(workoutChosen[randNum]){
                        randNum = MathUtils::randomInt(0,size-numOfVariables,randCounter, true);
                        randCounter++;
                    }
                    workoutChosen[randNum] = true;
                }

                //Determines values for each workout and prints the results.
                for (int i=0; i<size-numOfVariables; i++)
                {
                    randCounter++;
                    if(workoutChosen[i]){
                        repsMin = (toughness*difficulty*workoutWeight[i]-workoutWeight[i])/2+workoutWeight[i];
                        repsMax = toughness*difficulty*workoutWeight[i];
                        if(workoutName[i] != "running"){
                            repsModifier = MathUtils::randomInt((int)repsMin, (int)repsMax, randCounter, true);
                            if(weekly){ //prints results.
                                out << workoutName[i] << ": " << (int)repsModifier+1 << " " << workoutUnit[i] << endl;
                            } else {
                                cout << workoutName[i] << ": " << (int)repsModifier+1 << " " << workoutUnit[i] << endl;
                            }
                        } else {
                            repsModifier = MathUtils::randomInt((int)(repsMin*100.0), (int)(repsMax*100.0), randCounter, true);
                            repsModifier /= 100;
                            if(weekly){ //prints results.
                                out << workoutName[i] << ": " << repsModifier << " " << workoutUnit[i] << endl;
                            } else {
                                cout << workoutName[i] << ": " << repsModifier << " " << workoutUnit[i] << endl;
                            }
                        }
                    }
                }
                set++;
                numOfSets--;
                if(weekly) //prints results.
                    out << endl;
                else
                    MIATerminalTools::blankLine();
            }
            if(difficulty == 0.0)
            {
                if(weekly){ //prints results.
                    out << "rest: 45 minutes" << endl;
                } else {
                    cout << "rest: 45 minutes" << endl;
                }
            }
            if (weekly) //prints results.
                out << endl;
            else
                MIATerminalTools::blankLine();
            timesToGenerate--;
        }
        cout << "...Workout generation completed." << endl;
    } else {
        if (Configurator::getVerboseMode())
            Error::returnError(31404, fileName);
    }
}
