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
                std::vector< std::vector< std::vector<int> > > cube;
		std::vector<std::string> combination;
		int CUBE_SIZE;
		
	public:
		MIAEncrypt(int CUBE_SIZE);
		~MIAEncrypt();
	
		//Miscellaneous Actions.
		std::ofstream encryptFile(std::ofstream file);
		std::string encryptString(std::string text);
		std::vector<std::string> passphraseToCombination(std::string passphrase);
		void setCombination();
		void setCube();
		void printCube(std::vector< std::vector< std::vector<int>>> cube);
		void test();
		
		//Get Private Variables.
		std::vector< std::vector< std::vector<int>>> getCube();
		std::vector<std::string> getCombination();
		
		//Scramble and Unscramble algorithms.
		std::vector< std::vector< std::vector<int>>> scrambledCube(std::vector< std::vector< std::vector<int>>> cube, std::vector<std::string> combination);
		std::vector< std::vector< std::vector<int>>> unscrambledCube(std::vector< std::vector< std::vector<int>>> cube, std::vector<std::string> combination);
		
		//Combinatorial rotations.		
		std::vector< std::vector< std::vector<int>>> z_CW(std::vector< std::vector< std::vector<int>>> cube, int index);
		std::vector< std::vector< std::vector<int>>> z_CCW(std::vector< std::vector< std::vector<int>>> cube, int index);	
		
		std::vector< std::vector< std::vector<int>>> y_CW(std::vector< std::vector< std::vector<int>>> cube, int index);
		std::vector< std::vector< std::vector<int>>> y_CCW(std::vector< std::vector< std::vector<int>>> cube, int index);
		
		std::vector< std::vector< std::vector<int>>> x_CW(std::vector< std::vector< std::vector<int>>> cube, int index);
		std::vector< std::vector< std::vector<int>>> x_CCW(std::vector< std::vector< std::vector<int>>> cube, int index);
		
		//All of them in one function.
		std::vector< std::vector< std::vector<int>>> rotate(std::vector< std::vector< std::vector<int>>> cube, char side, int position, bool CW);
};

#endif // MIAENCRYPT_H
