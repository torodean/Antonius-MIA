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
#include "D3CMath.h"

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

//Main UI runner for the D3CMath productCollatzSequence() function.
void Commands::collatzRunner(){
	Program prog;
	std::D3CMath math;
	std::string input, output;
	
	std::cout << "...Enter a starting number (positive integer): " << std::endl;
	prog.blankLine();
	getline(std::cin,input);
	prog.blankLine();
	
    long longInput = std::atol(input.c_str());
	
	output = math.productCollatzSequence(longInput);
	
	std::cout << "collatz: " << output << std::endl;
	prog.blankLine();
	std::cout << "...Collatz sequence complete." << std::endl;
	prog.blankLine();
}

//Main UI runner for the D3CMath addTwoStrings() function.
void Commands::stringAdditionRunner(){
	Program prog;
	std::D3CMath math;
	std::string intOne, intTwo, output;
	
	std::cout << "...Addition of two integers of any size." << std::endl << "...Enter first integer to add: " << std::endl;
	prog.blankLine();
	getline(std::cin, intOne);
	prog.blankLine();

	std::cout << "...Enter second integer to add: " << std::endl;
	prog.blankLine();
	getline(std::cin, intTwo);
	prog.blankLine();

	output = math.addTwoStrings(intOne, intTwo);

	std::cout << "Integer sum: " << output << std::endl;
	prog.blankLine();
}

//Main UI runner for the D3CMath multiplyTwoStrings() function.
void Commands::stringMultiplyRunner(){
	Program prog;
	std::D3CMath math;
	std::string intOne, intTwo, output;
	
	std::cout << "...Multiplication of two integers of any size." << std::endl << "...Enter first integer to multiply: " << std::endl;
	prog.blankLine();
	getline(std::cin, intOne);
	prog.blankLine();

	std::cout << "...Enter second integer to multiply: " << std::endl;
	prog.blankLine();
	getline(std::cin, intTwo);
	prog.blankLine();

	output = math.multiplyTwoStrings(intOne, intTwo);

	std::cout << "Integer product: " << output << std::endl;
	prog.blankLine();	
}

//Main UI runner for the D3CMath subtractTwoStrings() function.
void Commands::stringSubtractionRunner(){
	Program prog;
	std::D3CMath math;
	std::string intOne, intTwo, output;
	
	std::cout << "...Subtraction of two integers of any size." << std::endl << "...Enter first integer: " << std::endl;
	prog.blankLine();
	getline(std::cin, intOne);
	prog.blankLine();

	std::cout << "...Enter second integer to subtract: " << std::endl;
	prog.blankLine();
	getline(std::cin, intTwo);
	prog.blankLine();

	output = math.subtractTwoStrings(intOne, intTwo);

	std::cout << "Integer difference: " << output << std::endl;
	prog.blankLine();
}

//Main UI runner for the D3CMath isPrime() function.
void Commands::isPrimeRunner(){
	Program prog;
	std::D3CMath math;
	std::string input;

	std::cout << "...Enter a positive Integer: " << std::endl;
	prog.blankLine();
	getline(std::cin, input);
	prog.blankLine();
	
	long longInput = std::atol(input.c_str());
	
	if(math.isPrime(longInput)){
		std::cout << "...The number you entered is prime. " << std::endl;
	}else{
		std::cout << "...The number you entered is NOT prime. " << std::endl;
	}
	prog.blankLine();
}

//Main UI runner for the D3CMath isPalindrome() function.
void Commands::isPalindromeRunner(){
	Program prog;
	std::D3CMath math;
	std::string input;

	std::cout << "...Enter a positive Integer: " << std::endl;
	prog.blankLine();
	getline(std::cin, input);
	prog.blankLine();
	
	long longInput = std::atol(input.c_str());
	
	if(math.isPalindrome(longInput)){
		std::cout << "...The number you entered is a palindrome. " << std::endl;
	}else{
		std::cout << "...The number you entered is NOT a palindrome. " << std::endl;
	}
	prog.blankLine();
}

//Main UI runner for the D3CMath sumOfDigits() function.
void Commands::sumOfDigitsRunner(){
	Program prog;
	std::D3CMath math;
	std::string input;

	std::cout << "...Enter a positive Integer of any length " << std::endl;
	prog.blankLine();
	getline(std::cin, input);
	prog.blankLine();
	
	long output = math.sumOfDigits(input);
	
	std::cout << "Sum of Digits: " << output << std::endl;        
	prog.blankLine();
}
