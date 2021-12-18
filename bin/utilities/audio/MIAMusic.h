//============================================================================
// Name        : MIAMusic.h
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Created on  : December 15, 2019
// Description : This file is for the music integration within MIA.
//============================================================================


#include<string>

using std::string;

class Music{
	private:
		bool songIsPlaying = false;
	public:
		Music(){};
		~Music(){};
		void playSong(string fileName);
};