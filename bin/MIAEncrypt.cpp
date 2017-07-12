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



//===================================
//===== Combinatorial rotations =====
//===================================

//Rotates the front of the cube in a CW direction and re-orients all of the pieces.
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

//Rotates the front of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>>> MIAEncrypt::front_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	/* Moves that will be performed.
	cubeNew[0][0][0] = cube[3][0][0];
	cubeNew[0][1][0] = cube[3][1][0];
	cubeNew[0][2][0] = cube[3][2][0];
	cubeNew[0][3][0] = cube[3][3][0];
	cubeNew[1][0][0] = cube[2][0][0];
	cubeNew[1][1][0] = cube[2][1][0];
	cubeNew[1][2][0] = cube[2][2][0];
	cubeNew[1][3][0] = cube[2][3][0];
	cubeNew[2][0][0] = cube[1][0][0];
	cubeNew[2][1][0] = cube[1][1][0];
	cubeNew[2][2][0] = cube[1][2][0];
	cubeNew[2][3][0] = cube[1][3][0];
	cubeNew[3][0][0] = cube[0][0][0];
	cubeNew[3][1][0] = cube[0][1][0];
	cubeNew[3][2][0] = cube[0][2][0];
	cubeNew[3][3][0] = cube[0][3][0];
	*/
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cubeNew[i][j][0] = cube[3-i][j][0];
		}
	}
	
	return cube_New;
}

//Rotates the back of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>>> MIAEncrypt::back_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cubeNew[i][j][3] = cube[j][3-i][3];
		}
	}
	
	return cube_New;
}

//Rotates the back of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>>> MIAEncrypt::back_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cubeNew[i][j][3] = cube[3-j][i][3];
		}
	}
	
	return cube_New;
}

//Rotates the top of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>>> MIAEncrypt::top_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	/* Moves that will be performed.
	cubeNew[3][0][0] = cube[3][0][0];
	cubeNew[3][0][1] = cube[3][0][0];
	cubeNew[3][0][2] = cube[3][0][0];
	cubeNew[3][0][3] = cube[3][0][0];
	cubeNew[3][1][0] = cube[3][0][0];
	cubeNew[3][1][1] = cube[3][0][0];
	cubeNew[3][1][2] = cube[3][0][0];
	cubeNew[3][1][3] = cube[3][0][0];
	cubeNew[3][2][0] = cube[3][0][0];
	cubeNew[3][2][1] = cube[3][0][0];
	cubeNew[3][2][2] = cube[3][0][0];
	cubeNew[3][2][3] = cube[3][0][0];
	cubeNew[3][3][0] = cube[3][0][0];
	cubeNew[3][3][1] = cube[3][0][0];
	cubeNew[3][3][2] = cube[3][0][0];
	cubeNew[3][3][3] = cube[3][0][0];
	*/
	
	//Performs the moves.
	for(int j=0; j<4; j++){
		for(int k=0; k<4; k++){
			cubeNew[3][j][k] = cube[3][j][3-k];
		}
	}
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>>> MIAEncrypt::top_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	//Performs the moves.
	for(int j=0; j<4; j++){
		for(int k=0; k<4; k++){
			cubeNew[3][j][k] = cube[3][3-j][k];
		}
	}
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>>> MIAEncrypt::bottom_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>>> MIAEncrypt::bottom_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>>> MIAEncrypt::left_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>>> MIAEncrypt::left_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>>> MIAEncrypt::right_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>>> MIAEncrypt::right_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

//Rotates the front middle of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_front_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cubeNew[i][j][1] = cube[j][3-i][1];
		}
	}
	
	return cube_New;
}

//Rotates the front middle of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_front_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cubeNew[i][j][1] = cube[3-i][j][1];
		}
	}
	
	return cube_New;
}

//Rotates the back middle of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_back_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cubeNew[i][j][2] = cube[j][3-i][2];
		}
	}
	
	return cube_New;
}

//Rotates the back middle of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_back_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cubeNew[i][j][2] = cube[3-j][i][2];
		}
	}
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_top_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_top_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_bottom_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_bottom_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_left_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_left_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_right_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}

std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_right_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cube_New = cube;
	
	return cube_New;
}