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
#include <iostream>
#include <vector>

//Main constructor for the MIAEncrypt algorithm.
MIAEncrypt::MIAEncrypt(int cSize): cubeSize(cSize), cube(cubeSize, std::vector<std::vector<int>>(cubeSize, std::vector<int>(cubeSize, 0) ) ), combination(16, "default"){
	//When Chuck Norris's code fails to compile, the computer apologizes.
}

//Main de-onstructor for the MIAEncrypt algorithm.
MIAEncrypt::~MIAEncrypt(){
	//Chuck Norris can stop an infinite loop just by thinking about it.
}

//===================================
//===== Combinatorial rotations =====
//===================================

void MIAEncrypt::test(){
	std::vector< std::vector< std::vector<int>>> testCube = cube;
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
	
	std::cout << "Finished... " << std::endl;
}

//Rotates part of a cube (side length n) while keeping one side constant in either a clockwize or counterclockwise direction.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::rotation(std::vector< std::vector< std::vector<int>>> cube, char side, int index, bool CW){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;

	if (side == 'x'){ //keep the x coordinate the same.
		if(CW){ //clockwise.
			for(int j=0; j<cubeSize; j++){
				for(int k=0; k<cubeSize; k++){
					cubeNew[index][j][k] = cube[index][cubeSize-1-k][j];
				}
			}
		} else { //counter-clockwise.
			for(int j=0; j<cubeSize; j++){
				for(int k=0; k<cubeSize; k++){
					cubeNew[index][j][k] = cube[index][k][cubeSize-1-j];
				}
			}
		}		
	} else if (side == 'y'){ //keep the y coordinate the same.
		if(CW){ //clockwise.
			for(int i=0; i<cubeSize; i++){
				for(int k=0; k<cubeSize; k++){
					cubeNew[i][index][k] = cube[k][index][cubeSize-1-i];
				}
			}
		} else { //counter-clockwise.
			for(int i=0; i<cubeSize; i++){
				for(int k=0; k<cubeSize; k++){
					cubeNew[i][index][k] = cube[cubeSize-1-k][index][i];
				}
			}
		}
	} else if (side == 'z'){ //keep the z coordinate the same.
		if(CW){ //clockwise.
			for(int i=0; i<cubeSize; i++){
				for(int j=0; j<cubeSize; j++){
					cubeNew[i][j][index] = cube[cubeSize-1-j][i][index];
				}
			}
		} else { //counter-clockwise.
			for(int i=0; i<cubeSize; i++){
				for(int j=0; j<cubeSize; j++){
					cubeNew[i][j][index] = cube[j][cubeSize-1-i][index];
				}
			}
		}
	}
	
	return cubeNew;
}

//Prints the components of a cube in a format assuming each element has the same length.
void MIAEncrypt::printCube(std::vector< std::vector< std::vector<int>>> cube){	
	for(int k=cubeSize-1; k>=0; k--){
		for(int j=cubeSize-1; j>=0; j--){
			for(int s=0; s<k; s++){ //s determines the number of spacing between each cube.
				std::cout << "   ";
			}
			for(int i=0; i<cubeSize; i++){
				std::cout << " " << cube[i][j][k] << " ";
			}
			std::cout << std::endl;
		}
	}
}
