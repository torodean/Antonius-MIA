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
	
}

void MIAEncrypt::test(){
  std::vector< std::vector< std::vector<int>>> testCube = cube;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      for(int k=0;k<4;k++){
	testCube[i][j][k]=100*i+10*j+k;
      }      
    }    
  }
  printCube(testCube);

  std::string input;
  std::cout << "Enter a rotation: ";
  getline(std::cin, input);

  if(input == "front_CW"){
    testCube = front_CW(testCube);
  } else if (input == "front_CCW"){
    testCube = front_CCW(testCube);
  }
  
  printCube(testCube);
}

//Rotates the front of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::front_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cubeNew[i][j][0] = cube[3-j][i][0];
		}
	}
	
	return cubeNew;
}

//Rotates the front of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::front_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cubeNew[i][j][0] = cube[j][3-i][0];
		}
	}
	
	return cubeNew;
}

//Rotates the back of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::back_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cubeNew[i][j][3] = cube[3-j][i][3];
		}
	}
	
	return cubeNew;
}

//Rotates the back of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::back_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cubeNew[i][j][3] = cube[j][3-i][3];
		}
	}
	
	return cubeNew;
}

//Rotates the top of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::top_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;

	//Performs the moves.
	for(int j=0; j<4; j++){
		for(int k=0; k<4; k++){
			cubeNew[3][j][k] = cube[3][j][3-k];
		}
	}
	
	return cubeNew;
}

//Rotates the top of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::top_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int j=0; j<4; j++){
		for(int k=0; k<4; k++){
			cubeNew[3][j][k] = cube[3][3-j][k];
		}
	}
	
	return cubeNew;
}

//Rotates the bottom of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::bottom_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int j=0; j<4; j++){
		for(int k=0; k<4; k++){
			cubeNew[0][j][k] = cube[0][3-j][k];
		}
	}

	return cubeNew;
}

//Rotates the bottom of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::bottom_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int j=0; j<4; j++){
		for(int k=0; k<4; k++){
			cubeNew[0][j][k] = cube[0][j][3-k];
		}
	}

	return cubeNew;
}

//Rotates the left of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::left_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int k=0; k<4; k++){
			cubeNew[i][0][k] = cube[i][0][3-k];
		}
	}

	return cubeNew;
}

//Rotates the left of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::left_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int k=0; k<4; k++){
			cubeNew[i][0][k] = cube[3-i][0][k];
		}
	}

	return cubeNew;
}

//Rotates the right of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::right_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;

	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int k=0; k<4; k++){
			cubeNew[i][3][k] = cube[i][3][3-k];
		}
	}
	
	return cubeNew;
}

//Rotates the right of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::right_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int k=0; k<4; k++){
			cubeNew[i][3][k] = cube[3-i][3][k];
		}
	}

	return cubeNew;
}

//Rotates the front middle of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_front_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cubeNew[i][j][1] = cube[3-j][i][1];
		}
	}
	
	return cubeNew;
}

//Rotates the front middle of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_front_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cubeNew[i][j][1] = cube[j][3-i][1];
		}
	}
	
	return cubeNew;
}

//Rotates the back middle of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_back_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cubeNew[i][j][2] = cube[3-j][i][2];
		}
	}
	
	return cubeNew;
}

//Rotates the back middle of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_back_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cubeNew[i][j][2] = cube[j][3-i][2];
		}
	}
	
	return cubeNew;
}

//Rotates the top middle of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_top_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int j=0; j<4; j++){
		for(int k=0; k<4; k++){
			cubeNew[2][j][k] = cube[2][3-j][k];
		}
	}

	return cubeNew;
}

//Rotates the top middle of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_top_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int j=0; j<4; j++){
		for(int k=0; k<4; k++){
			cubeNew[2][j][k] = cube[2][j][3-k];
		}
	}

	return cubeNew;
}

//Rotates the bottom middle of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_bottom_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int j=0; j<4; j++){
		for(int k=0; k<4; k++){
			cubeNew[1][j][k] = cube[1][3-j][k];
		}
	}

	return cubeNew;
}

//Rotates the bottom middle of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_bottom_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;

	//Performs the moves.
	for(int j=0; j<4; j++){
		for(int k=0; k<4; k++){
			cubeNew[1][j][k] = cube[1][j][3-k];
		}
	}
	
	return cubeNew;
}

//Rotates the left middle of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_left_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;

	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int k=0; k<4; k++){
			cubeNew[i][1][k] = cube[i][1][3-k];
		}
	}
	
	return cubeNew;
}

//Rotates the left middle of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_left_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int k=0; k<4; k++){
			cubeNew[i][1][k] = cube[3-i][1][k];
		}
	}

	return cubeNew;
}

//Rotates the right middle of the cube in a CW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_right_CW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;

	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int k=0; k<4; k++){
			cubeNew[i][2][k] = cube[i][2][3-k];
		}
	}	
	
	return cubeNew;
}

//Rotates the right middle of the cube in a CCW direction and re-orients all of the pieces.
std::vector< std::vector< std::vector<int>>> MIAEncrypt::middle_right_CCW(std::vector< std::vector< std::vector<int>>> cube){
	std::vector< std::vector< std::vector<int>>> cubeNew = cube;
	
	//Performs the moves.
	for(int i=0; i<4; i++){
		for(int k=0; k<4; k++){
			cubeNew[i][2][k] = cube[3-i][2][k];
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
