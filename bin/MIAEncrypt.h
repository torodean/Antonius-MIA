//============================================================================
// Name        : MIAEncrypt.h
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Created on  : July 7, 2017 (MIA)
// Description : The header file corresponding to the MIAEncrypt.cpp file.
//============================================================================

#ifndef MIAENCRYPT_H
#define MIAENCRYPT_H
#include <string>
#include <vector>
#include <fstream>

class MIAEncrypt{
	private:
		std::vector< std::vector<int>> cube;
		std::vector<std::string> combination;
		int CUBE_SIZE = 4;
		
	public:
		MIAEncrypt();
		~MIAEncrypt();
	
		//Miscellaneous Actions.
		std::ofstream encryptFile(std::ofstream file);
		std::string encryptString(std::string text);
		std::vector<std::string> passphraseToCombination(std::string passphrase);
		void setCombination();
		void setCube();
		void printCube(std::vector< std::vector< std::vector<int>>> cube);
		
		//Get Private Variables.
		std::vector< std::vector< std::vector<int>>> getCube();
		std::vector<std::string> getCombination();
		
		//Scramble and Unscramble algorithms.
		std::vector< std::vector< std::vector<int>>> scrambledCube(std::vector< std::vector< std::vector<int>>> cube, std::vector<std::string> combination);
		std::vector< std::vector< std::vector<int>>> unscrambledCube(std::vector< std::vector< std::vector<int>>> cube, std::vector<std::string> combination);
		
		//Combinatorial rotations.		
		std::vector< std::vector< std::vector<int>>> front_CW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> front_CCW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> back_CW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> back_CCW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> top_CW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> top_CCW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> bottom_CW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> bottom_CCW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> left_CW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> left_CCW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> right_CW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> right_CCW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> middle_left_CW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> middle_left_CCW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> middle_right_CW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> middle_right_CCW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> middle_front_CW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> middle_front_CCW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> middle_back_CW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> middle_back_CCW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> middle_top_CW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> middle_top_CCW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> middle_bottom_CW(std::vector< std::vector< std::vector<int>>> cube);
		std::vector< std::vector< std::vector<int>>> middle_bottom_CCW(std::vector< std::vector< std::vector<int>>> cube);
		
		//All of them in one function.
		std::vector< std::vector< std::vector<int>>>> rotate(std::vector< std::vector< std::vector<int>>> cube, char side, int position, bool CW);
};

#endif // MIAENCRYPT_H