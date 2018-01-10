//============================================================================
// Name        : MIAencrypt.cpp
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Created on  : July 7, 2017 (MIA)
// Description : This is a d0s3 (the final version of the d0sag3 encryption version)
//				 encryption algorithm. It Is made to encrypt any file.
//============================================================================

#include "MIAencrypt.h"
#include "MIAprogram.h"
#include <iostream>
#include <vector>
#include <fstream>

//Main constructor for the MIAencrypt algorithm.
MIAencrypt::MIAencrypt(int cSize): cubeSize(cSize), intCube(cubeSize, std::vector<std::vector<int>>(cubeSize, std::vector<int>(cubeSize, 0) ) ), 
		tesseract(8, intCube), totalRotations(3*2*cubeSize), combination(totalRotations, 0){
	//When Chuck Norris's code fails to compile, the computer apologizes.
}

//Main de-onstructor for the MIAencrypt algorithm.
MIAencrypt::~MIAencrypt(){
	//Chuck Norris can stop an infinite loop just by thinking about it.
}

//==================================================
//===== N*N*N Cuboidal Combinatorial rotations =====
//==================================================

void MIAencrypt::test(){
	std::vector< std::vector< std::vector<int>>> testCube = intCube;
	for(int i=0;i<cubeSize;i++){
		for(int j=0;j<cubeSize;j++){
			  for(int k=0;k<cubeSize;k++){
					testCube[i][j][k]=100*(i+1)+10*(j+1)+(k+1);
			  }      
		}    
	}
	printCube(testCube);
		
	/* Tests the rotations. //All work!
	
	std::vector< std::vector< std::vector<int>>> testCube = intCube;
	for(int i=0;i<cubeSize;i++){
		for(int j=0;j<cubeSize;j++){
			  for(int k=0;k<cubeSize;k++){
					testCube[i][j][k]=100*(i+1)+10*(j+1)+(k+1);
			  }      
		}    
	}
	printCube(testCube);
	
	std::string input = "";
	std::cout << "Enter a rotation (format == side(char) index(int) CW(bool)): ";
	
	getline(std::cin, input);
	while(input != "exit"){
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
		
		std::cout << std::endl << "Enter a rotation (format == side(char) index(int) CW(bool)): ";
		getline(std::cin, input);
	}
	
	*/ //All work!
	
	/* Tests the combination -> integer process. //All works!
	std::cout  << totalRotations << std::endl;
	for(int n=0; n<totalRotations; n++){
		combination[n] = n;
		std::cout << combination[n] << std::endl;
	}
	
	int rotations = combination.size();
	std::cout  << rotations << std::endl;

	
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
		
		std::cout << combination[n] << "   " << CW << "   " << side << "   " << index << std::endl;
	}
	*/ //All works!
	
	/* Tests the passphrase -> combination -> scramble -> unscramble process. //All works!
	passphraseToCombination("Hello World!");
	
	testCube = scrambleCube(testCube, combination);
	
	printCube(testCube);
	
	testCube = unscrambleCube(testCube, combination);

	printCube(testCube);
	*/ //All works!
	
	std::cout << "Starting test... " << std::endl;
	
	std::vector<char> charTest = fileToCharVec("input.txt");
	std::vector<int> intTest = charVecToIntVec(charTest);

	
	
	std::cout << "Finished... " << std::endl;
}

//Rotates part of a intCube (side length n) while keeping one side constant in either a clockwize or counterclockwise direction.
std::vector< std::vector< std::vector<int>>> MIAencrypt::rotation(std::vector< std::vector< std::vector<int>>> inputCube, char side, int index, bool CW){
	std::vector< std::vector< std::vector<int>>> cubeNew = inputCube;

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

//Prints the components of a intCube in a format assuming each element has the same length.
void MIAencrypt::printCube(std::vector< std::vector< std::vector<int>>> inputCube){	
	std::cout << std::endl;
	for(int k=cubeSize-1; k>=0; k--){
		for(int j=cubeSize-1; j>=0; j--){
			for(int s=0; s<k; s++){ //s determines the number of spacing between each intCube.
				std::cout << "   ";
			}
			for(int i=0; i<cubeSize; i++){
				std::cout << " " << inputCube[i][j][k] << " ";
			}
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

//Scrambles a intCube According to the combination integer entered.
std::vector< std::vector< std::vector<int>>> MIAencrypt::scrambleCube(std::vector< std::vector< std::vector<int>>> inputCube, std::vector<int> combination){	
	//initializes and sets the defauly rotation values. 	
	char side = 'x';
	bool CW = 1;
	int index = 0;
	int temp = 0;
	
	std::vector< std::vector< std::vector<int>>> cubeNew = inputCube;

	for(int n=0; n<totalRotations; n++){		
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
		
		cubeNew = rotation(cubeNew, side, index, CW);
	}
	
	return cubeNew;
}

//Un-crambles a intCube According to the combination entered.
std::vector< std::vector< std::vector<int>>> MIAencrypt::unscrambleCube(std::vector< std::vector< std::vector<int>>> inputCube, std::vector<int> combination){
	//initializes and sets the defauly rotation values. 	
	char side = 'x';
	bool CW = 1;
	int index = 0;
	int temp = 0;
	
	std::vector< std::vector< std::vector<int>>> cubeNew = inputCube;
	
	for(int n=totalRotations-1; n>=0; n--){		
		//determines the side of the intCube to rotate.
		if(combination[n] >= 2*totalRotations/3){
			side = 'z';
		} else if(combination[n] >= totalRotations/3){
			side = 'y';
		} else {
			side = 'x';
		}
		
		//determines the direction of the intCube to rotate.
		if (combination[n]%2 != 0){
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
		
		cubeNew = rotation(cubeNew, side, index, CW);
	}
	
	return cubeNew;
}

//Converts a string passphrase to a vector of integers.
void MIAencrypt::passphraseToCombination(std::string passphrase){
	long total = 0;
	int size = passphrase.size();
	Program prog;
	
	//sets the value of total.
	for(int n=0; n<size; n++){
		total += int(passphrase[n]);
		//std::cout << int(passphrase[n]) << std::endl;
	}
	//std::cout << total << std::endl;

	//for larger passphrases, increase the rotations.
	if(size > totalRotations){
		totalRotations = size;
	}
	
	//set's the first few moves to that of the passphrase.
	for(int n=0; n<size; n++){
		combination[n] = (int(passphrase[n])+total) % totalRotations;
		std::cout << combination[n] << std::endl;
	}
	
	//set's the remaining combination slots.
	int randomInt=0;
	for(int n=size;n<totalRotations; n++){
		total += int(passphrase[n % size]);
		randomInt = prog.randomInt(0, 1000000, total*total-n);
		std::cout << randomInt << std::endl;
		combination[n] = randomInt % totalRotations;
		std::cout << combination[n] << std::endl;
	}
}

//Encrypts a file. NOT YET WORKING/FINISED.
void MIAencrypt::encryptFile(std::string file, std::string fileName){
	std::string outputFile = cryptPath + fileName + ".d0s3";
	
	std::ifstream input( cryptPath  + file, std::ios::binary );
	std::ofstream output( outputFile, std::ios::binary );
	
	/* Copy's a file to the output file - same file but different name.
	std::copy(std::istreambuf_iterator<char>(input), 
			  std::istreambuf_iterator<char>( ),
			  std::ostreambuf_iterator<char>(output));
	*/	
		
	std::vector<char> buffer((std::istreambuf_iterator<char>(input)), 
				 (std::istreambuf_iterator<char>()));
	int size = buffer.size();
	
	/* Prints the data from the file. */
	for(int i = 0; i < size; i++){
		std::cout << buffer[i];
	}
	std::cout << std::endl;
	
	std::string bufferString = "";
	for(int i=0; i<size; i++){
		bufferString += buffer[i];
	}
	//std::cout << bufferString << std::endl;
}

//Converts a text file to a vector of characters.
std::vector<char> MIAencrypt::fileToCharVec(std::string file){
	std::ifstream input( cryptPath  + file, std::ios::binary );
	
	std::vector<char> charVec((std::istreambuf_iterator<char>(input)), (std::istreambuf_iterator<char>()));
	
	int size = charVec.size();
	/* Prints the data from the file. */
	for(int i = 0; i < size; i++){
		std::cout << charVec[i];
	}
	std::cout << std::endl;
	
	return charVec;
}

//Converts a vector of characters to a vector of integers.
std::vector<int> MIAencrypt::charVecToIntVec(std::vector<char> charVec){
	std::vector<int> intVec;
	int charVecSize = charVec.size();
	intVec.reserve(charVecSize);
	for(int i=0; i<charVecSize; i++){
		intVec.push_back( (int)charVec[i] );
	}
	
	/* Prints the data from the array. */
	int intVecSize = intVec.size();
	for(int i = 0; i < intVecSize; i++){
		std::cout << intVec[i];
	}
	std::cout << std::endl;
	
	return intVec;
}

//In development. 
std::vector<bool> MIAencrypt::intVecToBoolVec(std::vector<int> intVec){
	std::vector<bool> boolVec;
	
	int intVecSize = intVec.size();
	for(int i=0; i<intVecSize; i++){
		
	}
	
	
	return boolVec;
}

//In development. 
std::vector< std::vector< std::vector<bool> > >	MIAencrypt::boolVecToBoolCube(std::vector<bool> boolVec){
	std::vector< std::vector< std::vector<bool> > > boolCube;
	return boolCube;
}













