/**
 * File: MathUtils.cpp
 * Author: Antonius Torode
 * Date: 03/01/2021
 * Description:
 */

#include <iostream>
#include <cmath>
#include <limits>
#include "MathUtils.hpp"
#include "../program/Configurator.hpp"
#include "StringUtils.hpp"
#include "../terminal/MIATerminal.hpp"

using std::cout;
using std::endl;

int MathUtils::randomInt(int min, int max, int seed, bool useTime)
{
    if(max < min){
        if(Configurator::getVerboseMode())
            cout << "...Max value smaller than min, adjusting appropriately by returning min." << endl;
        return min;
    }
    if(Configurator::getVerboseMode())
        cout << "...Calculating random value between " << min << " and " << max << "." << endl;
    if(seed == 0){
        srand((unsigned)time(nullptr));
    } else if (useTime){
        srand((unsigned)time(nullptr) + seed);
    } else {
        srand(seed);
    }
    int random = min + (rand() % (max - min + 1));
    if(Configurator::getVerboseMode())
        cout << "...random value is " << random << "." << endl;
    return random;
}


int MathUtils::roll(const std::string& input)
{
    int numOfDice = stoi(StringUtils::getBeforeChar(input, 'd'));
    int sizeOfDice = stoi(StringUtils::getAfterChar(input, 'd'));
    int totalRolled = 0;

    MIATerminalTools::blankLine();
    for(int i=0; i<numOfDice; i++){
        int randCounter = numOfDice;
        totalRolled += rolldXX(sizeOfDice, randCounter);
    }
    cout << "Total Rolled: " << totalRolled << endl;
    MIATerminalTools::blankLine();
    return totalRolled;
}


int MathUtils::rolldXX(int xx, int seed)
{
    int rand = randomInt(1,xx,seed,true);
    cout << "1d" << xx << ": " << rand << endl;
    return rand;
}