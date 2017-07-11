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
#include <vector>

//Main constructor for the MIAEncrypt algorithm.
MIAEncrypt::MIAEncrypt(): cube(4, std::vector<int>(4,std::vector<int>(4,0))), combination(16, "default"){
	//When Chuck Norris's code fails to compile, the computer apologizes.
}

//Main de-onstructor for the MIAEncrypt algorithm.
MIAEncrypt::~MIAEncrypt(){
	//Chuck Norris can stop an infinite loop just by thinking about it.
}

//Rotates the front of the cube in a CC direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>>> MIAEncrypt::front_CC(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	/* Moves that will be performed.
	cubeNew[0][0][0] = cube[0][3][0];
	cubeNew[0][1][0] = cube[1][3][0];
	cubeNew[0][2][0] = cube[2][3][0];
	cubeNew[0][3][0] = cube[3][3][0];
	cubeNew[1][0][0] = cube[0][2][0];
	cubeNew[1][1][0] = cube[1][2][0];
	cubeNew[1][2][0] = cube[2][2][0];
	cubeNew[1][3][0] = cube[3][2][0];
	cubeNew[2][0][0] = cube[0][1][0];
	cubeNew[2][1][0] = cube[1][1][0];
	cubeNew[2][2][0] = cube[2][1][0];
	cubeNew[2][3][0] = cube[3][1][0];
	cubeNew[3][0][0] = cube[0][0][0];
	cubeNew[3][1][0] = cube[1][0][0];
	cubeNew[3][2][0] = cube[2][0][0];
	cubeNew[3][3][0] = cube[3][0][0];
	*/
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cubeNew[i][j][0] = cube[j][3-i][0];
		}
	}
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>>> MIAEncrypt::front_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>>> MIAEncrypt::back_CC(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>>> MIAEncrypt::back_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>>> MIAEncrypt::top_CC(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>>> MIAEncrypt::top_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>>> MIAEncrypt::bottom_CC(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>>> MIAEncrypt::bottom_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>>> MIAEncrypt::left_CC(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>>> MIAEncrypt::left_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>>> MIAEncrypt::right_CC(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>>> MIAEncrypt::right_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}