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
MIAEncrypt::MIAEncrypt(int CUBE_SIZE): cube(CUBE_SIZE, std::vector<std::vector<int>>(CUBE_SIZE, std::vector<int>(CUBE_SIZE, 0) ) ), combination(16, "default"){
	//When Chuck Norris's code fails to compile, the computer apologizes.
}

//Main de-onstructor for the MIAEncrypt algorithm.
MIAEncrypt::~MIAEncrypt(){
	//Chuck Norris can stop an infinite loop just by thinking about it.
}



//===================================
//===== Combinatorial rotations =====
//===================================

std::vector< std::vector< std::vector<int> > > MIAEncrypt::rotate(std::vector< std::vector< std::vector<int>>> cube, char side, int  position, bool CW){
	std::vector< std::vector< std::vector<int> > > newCube = cube;
	return newCube;
}

void MIAEncrypt::test(){
	std::vector< std::vector< std::vector<int>>> testCube = cube;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			  for(int k=0;k<4;k++){
					testCube[i][j][k]=100*(i+1)+10*(j+1)+(k+1);
			  }      
		}    
	}
	printCube(testCube);

	std::string input = "";
	std::cout << "Enter a rotation (format == x0_CW): ";
	
	getline(std::cin, input);
	while(input != "exit"){
		if(input == "z0_CW"){
			testCube = z_CW(testCube, 0);
		} else if (input == "z0_CCW"){
			testCube = z_CCW(testCube, 0);
		} else if (input == "z3_CW"){
			testCube = z_CW(testCube, 3);
		} else if (input == "z3_CCW"){
			testCube = z_CCW(testCube, 3);
		} else if(input == "x0_CW"){
			testCube = x_CW(testCube, 0);
		} else if (input == "x0_CCW"){
			testCube = x_CCW(testCube, 0);
		} else if (input == "x3_CW"){
			testCube = x_CW(testCube, 3);
		} else if (input == "x3_CCW"){
			testCube = x_CCW(testCube, 3);
		} else if(input == "y0_CW"){
			testCube = y_CW(testCube, 0);
		} else if (input == "y0_CCW"){
			testCube = y_CCW(testCube, 0);
		} else if (input == "y3_CW"){
			testCube = y_CW(testCube, 3);
		} else if (input == "y3_CCW"){
			testCube = y_CCW(testCube, 3);
		}
		
		std::cout << "Enter a rotation (format == x0_CW): ";
		getline(std::cin, input);
	}
	
	std::cout << "Finished... " << std::endl;
  
	printCube(testCube);
}

//Rotates the front of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::z_CW(std::vector< std::vector< std::vector<int>>> cube, int index){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cubeNew[i][j][index] = cube[CUBE_SIZE-1-j][i][index];
		}
	}
	
	return cubeNew;
}

//Rotates the front of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::z_CCW(std::vector< std::vector< std::vector<int>>> cube, int index){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cubeNew[i][j][index] = cube[j][CUBE_SIZE-1-i][index];
		}
	}
	
	return cubeNew;
}

//Rotates the top of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::y_CW(std::vector< std::vector< std::vector<int>>> cube, int index){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;

	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int k=0; k<4; k++){
			cubeNew[i][index][k] = cube[i][index][CUBE_SIZE-1-k];
		}
	}
	
	return cubeNew;
}

//Rotates the top of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::y_CCW(std::vector< std::vector< std::vector<int>>> cube, int index){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int k=0; k<4; k++){
			cubeNew[i][index][k] = cube[CUBE_SIZE-1-i][index][k];
		}
	}
	
	return cubeNew;
}

//Rotates the left of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::x_CW(std::vector< std::vector< std::vector<int>>> cube, int index){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int j=0; j<4; j++){
		for(int k=0; k<4; k++){
			cubeNew[index][j][k] = cube[index][j][CUBE_SIZE-1-k];
		}
	}

	return cubeNew;
}

//Rotates the left of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::x_CCW(std::vector< std::vector< std::vector<int>>> cube, int index){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int j=0; j<4; j++){
		for(int k=0; k<4; k++){
			cubeNew[index][j][k] = cube[index][CUBE_SIZE-1-j][k];
		}
	}

	return cubeNew;
}

//Prints the components of a cube in a format assuming each element has the same length.
void MIAEncrypt::printCube(std::vector< std::vector< std::vector<int>>> cube){
        std::cout << "            /------------------/" << std::endl;
	std::cout << "           /" << cube[0][3][3] << " " << cube[1][3][3] << " " << cube[2][3][3] << " " << cube[3][3][3] << "   /" << std::endl;
	std::cout << "          / " << cube[0][2][3] << " " << cube[1][2][3] << " " << cube[2][2][3] << " " << cube[3][2][3] << "  /" << std::endl;
	std::cout << "         /  " << cube[0][1][3] << " " << cube[1][1][3] << " " << cube[2][1][3] << " " << cube[3][1][3] << " /" << std::endl;
	std::cout << "        /   " << cube[0][0][3] << " " << cube[1][0][3] << " " << cube[2][0][3] << " " << cube[3][0][3] << "/" << std::endl;
	
	std::cout << "       /" << cube[0][3][2] << " " << cube[1][3][2] << " " << cube[2][3][2] << " " << cube[3][3][2] << "   /" << std::endl;
	std::cout << "      / " << cube[0][2][2] << " " << cube[1][2][2] << " " << cube[2][2][2] << " " << cube[3][2][2] << "  /" << std::endl;
	std::cout << "     /  " << cube[0][1][2] << " " << cube[1][1][2] << " " << cube[2][1][2] << " " << cube[3][1][2] << " /" << std::endl;
	std::cout << "    /   " << cube[0][0][2] << " " << cube[1][0][2] << " " << cube[2][0][2] << " " << cube[3][0][2] << "/" << std::endl;
	
	std::cout << "   /" << cube[0][3][1] << " " << cube[1][3][1] << " " << cube[2][3][1] << " " << cube[3][3][1] << "   /" << std::endl;
	std::cout << "  / " << cube[0][2][1] << " " << cube[1][2][1] << " " << cube[2][2][1] << " " << cube[3][2][1] << "  /" << std::endl;
	std::cout << " /  " << cube[0][1][1] << " " << cube[1][1][1] << " " << cube[2][1][1] << " " << cube[3][1][1] << " /" << std::endl;
	std::cout << "/   " << cube[0][0][1] << " " << cube[1][0][1] << " " << cube[2][0][1] << " " << cube[3][0][1] << "/" << std::endl;
	
	std::cout << cube[0][3][0] << " " << cube[1][3][0] << " " << cube[2][3][0] << " " << cube[3][3][0] << "   /" << std::endl;
	std::cout << cube[0][2][0] << " " << cube[1][2][0] << " " << cube[2][2][0] << " " << cube[3][2][0] << "  /" << std::endl;
	std::cout << cube[0][1][0] << " " << cube[1][1][0] << " " << cube[2][1][0] << " " << cube[3][1][0] << " /" << std::endl;
	std::cout << cube[0][0][0] << " " << cube[1][0][0] << " " << cube[2][0][0] << " " << cube[3][0][0] << "/" << std::endl;
	std::cout << "--------------/" << std::endl;
}
