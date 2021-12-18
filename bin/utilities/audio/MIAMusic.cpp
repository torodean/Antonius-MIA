//============================================================================
// Name        : MIAMusic.cpp
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Created on  : December 15, 2019
// Description : This file is for the music integration within MIA.
//============================================================================


#include "MIAMusic.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

void Music::playSong(string fileName)
{
	cout << "Welcome to VLC launcher program!" << endl;
    string comm = "vlc \"";
    comm += fileName + "\"";
    system(comm.c_str()); //call VLC with the file "filename"
}