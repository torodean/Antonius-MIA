//============================================================================
// Name        : MIAEncrypt.h
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

using std::vector;
using std::string;

class MIACrypt{
	public:
		MIACrypt();
		~MIACrypt();
	protected:
	
	private:
		vector<vector<vector<unsigned char>>> binaryData;
		string passphrase;
}; //MIACrypt.









// DEPRECATED in newer design - MIACrypt.
class MIAEncrypt{
	private:
		int cubeSize;
		
        vector< vector< vector<int> > > intCube;
		vector< vector< vector< vector<int> > > > tesseract;
		int totalRotations;
		vector<int> combination;
		
	public:
		MIAEncrypt(int cSize);
		~MIAEncrypt();
	
		//Miscellaneous Actions.
		void encryptFile(string file, string fileName);
		string encryptString(string text);
		void passphraseToCombination(string passphrase);
		void printCube(vector< vector< vector<int>>> intCube);
		void runTest();
		
		//bool cube.
		vector<char> fileToCharVec(string filename);
		vector<int> charVecToIntVec(vector<char> charVec);
		vector<bool> intVecToBoolVec(vector<int> intVec);
		vector< vector< vector<bool> > >	boolVecToBoolCube(vector<bool> boolVec);	
		
		
		//Get Private Variables.
		vector< vector< vector<int>>> getCube();
		vector<string> getCombination();
		
		//Scramble and Unscramble algorithms.
		vector< vector< vector<int>>> scrambleCube(vector< vector< vector<int>>> intCube, vector<int> combination);
		vector< vector< vector<int>>> unscrambleCube(vector< vector< vector<int>>> intCube, vector<int> combination);
		
		//N*N*N cuboidal Combinatorial rotations.	
		vector< vector< vector<int>>> rotation(vector< vector< vector<int>>> intCube,char side, int index, bool CW);
};

#endif // MIAENCRYPT_H
