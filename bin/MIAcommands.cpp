//============================================================================
// Name        : MIAcommands.cpp
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Description : MIA commands and their respective runners.
//============================================================================

#include <iostream>
#include <string>
#include "MIAprogram.h"
#include "D3CEncrypt.h"
#include "D3CEncryptPW.h"
#include "MIAcommands.h"

//Main commands constructor.
Commands::Commands(){
	
}

//Main commands deconstructor.
Commands::~Commands(){
	
}

//Main UI runner for the D3CEncrypt (d0s1) program feature. Encryption
void Commands::d0s1CryptRunner(){
	Program prog;
	std::D3CEncrypt crypt;
	
	prog.blankDots();
	std::cout << "...Please enter a string to encrypt: " << std::endl;
	prog.blankLine();
	
	std::string input, output;
	getline(std::cin,input);
	output = crypt.Crypt(input);
	
	prog.blankLine();
	std::cout << "...The encrypted output is: " << std::endl;
	prog.blankLine();
	std::cout << output << std::endl;
}

//Main UI runner for the D3CEncrypt (d0s1) program feature. DeCryption
void Commands::d0s1DeCryptRunner(){
	Program prog;
	std::D3CEncrypt crypt;
	
	prog.blankDots();
	std::cout << "...Please enter a string to de-crypt: " << std::endl;
	prog.blankLine();
	
	std::string input, output;
	getline(std::cin,input);
	output = crypt.DeCrypt(input);
	
	prog.blankLine();
	std::cout << "...The de-crypted output is: " << std::endl;
	prog.blankLine();
	std::cout << output << std::endl;
}

//Main UI runner for the D3CEncryptPW (d0s2) program feature. Encryption
void Commands::d0s2CryptRunner(){
	Program prog;
	D3CEncryptPW crypt;
	
	prog.blankDots();
	std::cout << "...Please enter a string to encrypt: " << std::endl;
	prog.blankLine();
	
	std::string input, password, output;
	getline(std::cin,input);
	
	prog.blankDots();
	std::cout << "...Please enter the password to encrypt: " << std::endl;
	prog.blankLine();
	
	getline(std::cin,password);
	output = crypt.EncryptPW(input, password);
	
	prog.blankLine();
	std::cout << "...The encrypted output is: " << std::endl;
	prog.blankLine();
	std::cout << output << std::endl;
}

//Main UI runner for the D3CEncryptPW (d0s2) program feature. DeCryption
void Commands::d0s2DeCryptRunner(){
	Program prog;
	D3CEncryptPW crypt;
	
	prog.blankDots();
	std::cout << "...Please enter a string to de-crypt: " << std::endl;
	prog.blankLine();
	
	std::string input, password, output;
	getline(std::cin,input);
	
	prog.blankDots();
	std::cout << "...Please enter the password to de-crypt: " << std::endl;
	prog.blankLine();
	
	getline(std::cin,password);
	output = crypt.DecryptPW(input, password);
	
	prog.blankLine();
	std::cout << "...The de-crypted output is: " << std::endl;
	prog.blankLine();
	std::cout << output << std::endl;
}