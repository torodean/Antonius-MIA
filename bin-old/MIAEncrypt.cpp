//============================================================================
// Name        : MIAEncrypt.cpp
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Created on  : July 7, 2017 (MIA)
// Description : This is a d0s3 (the final version of the d0sag3 encryption version)
//				 encryption algorithm. It Is made to encrypt any file.
//============================================================================

#include "MIAEncrypt.h"
#include "MIAProgram.h"
#include "../bin/utilities/encryption/MIAEncrypt.hpp"

#include <iostream>
#include <vector>
#include <fstream>

using std::vector;
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::copy;
using std::istreambuf_iterator;
using std::ostreambuf_iterator;

MIACrypt::MIACrypt(){

}

MIACrypt::~MIACrypt(){

}















// DEPRECATED in newer design - MIACrypt.
//Main constructor for the MIAEncrypt algorithm.
MIAEncrypt::MIAEncrypt(int cSize): cubeSize(cSize), intCube(cubeSize, vector<vector<int>>(cubeSize, vector<int>(cubeSize, 0) ) ), 
		tesseract(8, intCube), totalRotations(3*2*cubeSize), combination(totalRotations, 0){
	//When Chuck Norris's code fails to compile, the computer apologizes.
}

// DEPRECATED in newer design - MIACrypt.
//Main de-constructor for the MIAEncrypt algorithm.
MIAEncrypt::~MIAEncrypt(){
	//Chuck Norris can stop an infinite loop just by thinking about it.
}

//==================================================
//===== N*N*N Cuboidal Combinatorial rotations =====
//==================================================

// DEPRECATED in newer design - MIACrypt.
void MIAEncrypt::runTest(){
	vector< vector< vector<int>>> testCube = intCube;
	for(int i=0;i<cubeSize;i++){
		for(int j=0;j<cubeSize;j++){
			  for(int k=0;k<cubeSize;k++){
					testCube[i][j][k]=100*(i+1)+10*(j+1)+(k+1);
			  }      
		}    
	}
	printCube(testCube);
		
	// /* Tests the rotations. //All work!
	cout << "Testing rotation process." << endl;
	
	cout << "Creating test cube with values equal to coordinates." << endl;
	//vector< vector< vector<int>>> testCube = intCube;
	for(int i=0;i<cubeSize;i++){
		for(int j=0;j<cubeSize;j++){
			  for(int k=0;k<cubeSize;k++){
					testCube[i][j][k]=100*(i+1)+10*(j+1)+(k+1);
			  }      
		}    
	}
	printCube(testCube);
	
	string input = "";
	cout << "Enter a rotation (format == side(char) index(int) CW(bool)): ";
	cout << "Type 'stop' to stop" << endl;
	
	getline(cin, input);
	while(input != "stop"){
		if(input == "z 0 1"){
			testCube = rotation(testCube, 'z', 0, 1);
		} else if (input == "z 0 0"){
			testCube = rotation(testCube, 'z', 0, 0);
		} else if (input == "z 3 1"){
			testCube = rotation(testCube, 'z', 3, 1);
		} else if (input == "z 3 0"){
			testCube = rotation(testCube, 'z', 3, 0);
		} else if(input == "x 0 1"){
			testCube = rotation(testCube, 'x', 0, 1);
		} else if (input == "x 0 0"){
			testCube = rotation(testCube, 'x', 0, 0);
		} else if (input == "x 3 1"){
			testCube = rotation(testCube, 'x', 3, 1);
		} else if (input == "x 3 0"){
			testCube = rotation(testCube, 'x', 3, 0);
		} else if(input == "y 0 1"){
			testCube = rotation(testCube, 'y', 0, 1);
		} else if (input == "y 0 0"){
			testCube = rotation(testCube, 'y', 0, 0);
		} else if (input == "y 3 1"){
			testCube = rotation(testCube, 'y', 3, 1);
		} else if (input == "y 3 0"){
			testCube = rotation(testCube, 'y', 3, 0);
		}
		printCube(testCube);
		
		cout << endl << "Enter a rotation (format == side(char) index(int) CW(bool)): ";
		getline(cin, input);
	}
	
	//*/ //All work!
	
	// Tests the combination -> integer process. //All works!
	cout << "Testing combination to integer process." << endl;
	cout  << "totalRotations: " << totalRotations << endl;
	for(int n=0; n<totalRotations; n++){
		combination[n] = n;
		cout << combination[n] << endl;
	}
	
	int rotations = combination.size();
	cout  << rotations << endl;

	
	//initializes and sets the defauly rotation values. 	
	char side = 'x';
	bool CW = 1;
	int index = 0;
	int temp = 0; //temp variable for below calculation.
	
	for(int n=0; n<rotations; n++){		
		//determines the side of the intCube to rotate.
		if(combination[n] >= 2*totalRotations/3){
			side = 'z';
		} else if(combination[n] >= totalRotations/3){
			side = 'y';
		} else {
			side = 'x';
		}
		
		//determines the direction of the intCube to rotate.
		if (combination[n]%2 == 0){
			CW = true;
		} else {
			CW = false;
		}
		
		//determines the index.
		if (cubeSize%2 == 0){
			if(combination[n]%(2*cubeSize) > combination[n]%cubeSize){
				temp = (combination[n]%(2*cubeSize))-cubeSize;
				index = (combination[n]%(2*cubeSize))-2*temp-1;
			} else {
				index = combination[n]%cubeSize;
			}
		} else {
			index = combination[n]%cubeSize;
		}
		
		cout << combination[n] << "   " << CW << "   " << side << "   " << index << endl;
	}
	// */ //All works!
	
	// /* Tests the passphrase -> combination -> scramble -> unscramble process. //All works!
	cout << "Testing the passphrase to combination then scramble and unscramble process." << endl;
	
	cout << "Comverting passphrase to combination." << endl;
	passphraseToCombination("Hello World!");
	
	cout << "Scrambling cube with combination" << endl;
	testCube = scrambleCube(testCube, combination);
	
	printCube(testCube);
	
	cout << "Unscrambling cube with combination" << endl;
	testCube = unscrambleCube(testCube, combination);

	printCube(testCube);
	// */ //All works!
	
	cout << "Starting test... " << endl;
	
	vector<char> charTest = fileToCharVec("input.txt");
	vector<int> intTest = charVecToIntVec(charTest);
	
	cout << "Finished... " << endl;
}

// DEPRECATED in newer design - MIACrypt.
//Rotates part of a intCube (side length n) while keeping one side constant in either a clockwize or counterclockwise direction.
vector< vector< vector<int>>> MIAEncrypt::rotation(vector< vector< vector<int>>> inputCube, char side, int index, bool CW){
	vector< vector< vector<int>>> cubeNew = inputCube;

	if (side == 'x'){ //keep the x coordinate the same.
		if(CW){ //clockwise.
			for(int j=0; j<cubeSize; j++){
				for(int k=0; k<cubeSize; k++){
					cubeNew[index][j][k] = inputCube[index][cubeSize-1-k][j];
				}
			}
		} else { //counter-clockwise.
			for(int j=0; j<cubeSize; j++){
				for(int k=0; k<cubeSize; k++){
					cubeNew[index][j][k] = inputCube[index][k][cubeSize-1-j];
				}
			}
		}		
	} else if (side == 'y'){ //keep the y coordinate the same.
		if(CW){ //clockwise.
			for(int i=0; i<cubeSize; i++){
				for(int k=0; k<cubeSize; k++){
					cubeNew[i][index][k] = inputCube[k][index][cubeSize-1-i];
				}
			}
		} else { //counter-clockwise.
			for(int i=0; i<cubeSize; i++){
				for(int k=0; k<cubeSize; k++){
					cubeNew[i][index][k] = inputCube[cubeSize-1-k][index][i];
				}
			}
		}
	} else if (side == 'z'){ //keep the z coordinate the same.
		if(CW){ //clockwise.
			for(int i=0; i<cubeSize; i++){
				for(int j=0; j<cubeSize; j++){
					cubeNew[i][j][index] = inputCube[cubeSize-1-j][i][index];
				}
			}
		} else { //counter-clockwise.
			for(int i=0; i<cubeSize; i++){
				for(int j=0; j<cubeSize; j++){
					cubeNew[i][j][index] = inputCube[j][cubeSize-1-i][index];
				}
			}
		}
	}
	
	return cubeNew;
}

// DEPRECATED in newer design - MIACrypt.
//Prints the components of a intCube in a format assuming each element has the same length.
void MIAEncrypt::printCube(vector< vector< vector<int>>> inputCube){
	cout << endl;
	for(int k=cubeSize-1; k>=0; k--){
		for(int j=cubeSize-1; j>=0; j--){
			for(int s=0; s<k; s++){ //s determines the number of spacing between each intCube.
				cout << "   ";
			}
			for(int i=0; i<cubeSize; i++){
				cout << " " << inputCube[i][j][k] << " ";
			}
			cout << endl;
		}
	}
	cout << endl;
}

// DEPRECATED in newer design - MIACrypt.
//Scrambles a intCube According to the combination integer entered.
vector< vector< vector<int>>> MIAEncrypt::scrambleCube(vector< vector< vector<int>>> inputCube, vector<int> com){	
	//initializes and sets the defauly rotation values. 	
	char side = 'x';
	bool CW = 1;
	int index = 0;
	int temp = 0;
	
	vector< vector< vector<int>>> cubeNew = inputCube;

	for(int n=0; n<totalRotations; n++){		
		//determines the side of the intCube to rotate.
		if(com[n] >= 2*totalRotations/3){
			side = 'z';
		} else if(com[n] >= totalRotations/3){
			side = 'y';
		} else {
			side = 'x';
		}
		
		//determines the direction of the intCube to rotate.
		if (com[n]%2 == 0){
			CW = true;
		} else {
			CW = false;
		}
		
		//determines the index.
		if (cubeSize%2 == 0){
			if(com[n]%(2*cubeSize) > com[n]%cubeSize){
				temp = (combination[n]%(2*cubeSize))-cubeSize;
				index = (combination[n]%(2*cubeSize))-2*temp-1;
			} else {
				index = combination[n]%cubeSize;
			}
		} else {
			index = com[n]%cubeSize;
		}
		
		cubeNew = rotation(cubeNew, side, index, CW);
	}
	
	return cubeNew;
}

// DEPRECATED in newer design - MIACrypt.
//Un-crambles a intCube According to the combination entered.
vector< vector< vector<int>>> MIAEncrypt::unscrambleCube(vector< vector< vector<int>>> inputCube, vector<int> com){
	//initializes and sets the defauly rotation values. 	
	char side = 'x';
	bool CW = 1;
	int index = 0;
	int temp = 0;
	
	vector< vector< vector<int>>> cubeNew = inputCube;
	
	for(int n=totalRotations-1; n>=0; n--){		
		//determines the side of the intCube to rotate.
		if(com[n] >= 2*totalRotations/3){
			side = 'z';
		} else if(com[n] >= totalRotations/3){
			side = 'y';
		} else {
			side = 'x';
		}
		
		//determines the direction of the intCube to rotate.
		if (com[n]%2 != 0){
			CW = true;
		} else {
			CW = false;
		}
		
		//determines the index.
		if (cubeSize%2 == 0){
			if(com[n]%(2*cubeSize) > com[n]%cubeSize){
				temp = (combination[n]%(2*cubeSize))-cubeSize;
				index = (combination[n]%(2*cubeSize))-2*temp-1;
			} else {
				index = combination[n]%cubeSize;
			}
		} else {
			index = com[n]%cubeSize;
		}
		
		cubeNew = rotation(cubeNew, side, index, CW);
	}
	
	return cubeNew;
}

// DEPRECATED in newer design - MIACrypt.
//Converts a string passphrase to a vector of integers.
void MIAEncrypt::passphraseToCombination(string passphrase){
	long total = 0;
	int size = passphrase.size();
	Program prog;
	
	//sets the value of total.
	for(int n=0; n<size; n++){
		total += int(passphrase[n]);
		//cout << int(passphrase[n]) << endl;
	}
	//cout << total << endl;

	//for larger passphrases, increase the rotations.
	if(size > totalRotations){
		totalRotations = size;
	}
	
	//set's the first few moves to that of the passphrase.
	for(int n=0; n<size; n++){
		combination[n] = (int(passphrase[n])+total) % totalRotations;
		cout << combination[n] << endl;
	}
	
	//set's the remaining combination slots.
	int randomInt=0;
	for(int n=size;n<totalRotations; n++){
		total += int(passphrase[n % size]);
		randomInt = prog.randomInt(0, 1000000, total*total-n, false);
		cout << randomInt << endl;
		combination[n] = randomInt % totalRotations;
		cout << combination[n] << endl;
	}
}

// DEPRECATED in newer design - MIACrypt.
//Encrypts a file. NOT YET WORKING/FINISED.
void MIAEncrypt::encryptFile(string file, string fileName){
	Program prog;
	string outputFile = prog.getFilePath("decryptFilePath") + fileName + ".d0s3";
	
	ifstream input( prog.getFilePath("decryptFilePath")  + file, ios::binary );
	ofstream output( outputFile, ios::binary );
	
	/* Copy's a file to the output file - same file but different name.
	copy(istreambuf_iterator<char>(input), 
			  istreambuf_iterator<char>( ),
			  ostreambuf_iterator<char>(output));
	*/	
		
	vector<char> buffer((istreambuf_iterator<char>(input)), 
				 (istreambuf_iterator<char>()));
	int size = buffer.size();
	
	/* Prints the data from the file. */
	for(int i = 0; i < size; i++){
		cout << buffer[i];
	}
	cout << endl;
	
	string bufferString = "";
	for(int i=0; i<size; i++){
		bufferString += buffer[i];
	}
	//cout << bufferString << endl;
}

// DEPRECATED in newer design - MIACrypt.
//Converts a text file to a vector of characters.
vector<char> MIAEncrypt::fileToCharVec(string file){
	Program prog;
	
	ifstream input( prog.getFilePath("decryptFilePath")  + file, ios::binary );
	
	vector<char> charVec((istreambuf_iterator<char>(input)), (istreambuf_iterator<char>()));
	
	int size = charVec.size();
	/* Prints the data from the file. */
	for(int i = 0; i < size; i++){
		cout << charVec[i];
	}
	cout << endl;
	
	return charVec;
}

// DEPRECATED in newer design - MIACrypt.
//Converts a vector of characters to a vector of integers.
vector<int> MIAEncrypt::charVecToIntVec(vector<char> charVec){
	vector<int> intVec;
	int charVecSize = charVec.size();
	intVec.reserve(charVecSize);
	for(int i=0; i<charVecSize; i++){
		intVec.push_back( (int)charVec[i] );
	}
	
	/* Prints the data from the array. */
	int intVecSize = intVec.size();
	for(int i = 0; i < intVecSize; i++){
		cout << intVec[i];
	}
	cout << endl;
	
	return intVec;
}

// DEPRECATED in newer design - MIACrypt.
//In development. 
vector<bool> MIAEncrypt::intVecToBoolVec(vector<int> intVec){
	vector<bool> boolVec;
	
	int intVecSize = intVec.size();
	for(int i=0; i<intVecSize; i++){
		
	}
	
	return boolVec;
}

// DEPRECATED in newer design - MIACrypt.
//In development. 
vector< vector< vector<bool> > > MIAEncrypt::boolVecToBoolCube([[maybe_unused]] vector<bool> boolVec){
	vector< vector< vector<bool> > > boolCube;
	return boolCube;
}