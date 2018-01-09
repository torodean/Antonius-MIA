//============================================================================
// Name        : MIAencrypt.h
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Created on  : July 7, 2017 (MIA)
// Description : The header file corresponding to the MIAencrypt.cpp file.
//============================================================================

#ifndef MIAENCRYPT_H
#define MIAENCRYPT_H
#include <string>
#include <vector>

class MIAencrypt{
	private:
		int cubeSize;
        std::vector< std::vector< std::vector<int> > > intCube;
		std::vector< std::vector< std::vector< std::vector<int> > > > tesseract;
		std::string cryptPath = "../bin/Resources/EncryptedFiles/";
		int totalRotations;
		std::vector<int> combination;
		
	public:
		MIAencrypt(int cSize);
		~MIAencrypt();
	
		//Miscellaneous Actions.
		void encryptFile(std::string file, std::string fileName);
		std::string encryptString(std::string text);
		void passphraseToCombination(std::string passphrase);
		void printCube(std::vector< std::vector< std::vector<int>>> intCube);
		void test();
		
		//bool cube.
		std::vector<char> fileToCharVec(std::string filename);
		std::vector<int> charVecToIntVec(std::vector<char> charVec);
		std::vector<bool> intVecToBoolVec(std::vector<int> intVec);
		std::vector< std::vector< std::vector<bool> > >	boolVecToBoolCube(std::vector<bool> boolVec);	
		
		
		
		//Get Private Variables.
		std::vector< std::vector< std::vector<int>>> getCube();
		std::vector<std::string> getCombination();
		
		//Scramble and Unscramble algorithms.
		std::vector< std::vector< std::vector<int>>> scrambleCube(std::vector< std::vector< std::vector<int>>> intCube, std::vector<int> combination);
		std::vector< std::vector< std::vector<int>>> unscrambleCube(std::vector< std::vector< std::vector<int>>> intCube, std::vector<int> combination);
		
		//N*N*N cuboidal Combinatorial rotations.	
		std::vector< std::vector< std::vector<int>>> rotation(std::vector< std::vector< std::vector<int>>> intCube,char side, int index, bool CW);
};

#endif // MIAENCRYPT_H
