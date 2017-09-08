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

class MIAEncrypt{
	private:
		int cubeSize;
        std::vector< std::vector< std::vector<int> > > cube;
		std::vector< std::vector< std::vector< std::vector<int> > > > tesseract;
		int totalRotations;
		std::vector<int> combination;
		
	public:
		MIAEncrypt(int cSize);
		~MIAEncrypt();
	
		//Miscellaneous Actions.
		void encryptFile(std::string file, std::string fileName);
		std::string encryptString(std::string text);
		void passphraseToCombination(std::string passphrase);
		void printCube(std::vector< std::vector< std::vector<int>>> cube);
		void test();
		
		//Get Private Variables.
		std::vector< std::vector< std::vector<int>>> getCube();
		std::vector<std::string> getCombination();
		
		//Scramble and Unscramble algorithms.
		std::vector< std::vector< std::vector<int>>> scrambleCube(std::vector< std::vector< std::vector<int>>> cube, std::vector<int> combination);
		std::vector< std::vector< std::vector<int>>> unscrambleCube(std::vector< std::vector< std::vector<int>>> cube, std::vector<int> combination);
		
		//N*N*N cuboidal Combinatorial rotations.	
		std::vector< std::vector< std::vector<int>>> rotation(std::vector< std::vector< std::vector<int>>> cube,char side, int index, bool CW);
};

#endif // MIAENCRYPT_H
