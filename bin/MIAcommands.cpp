//============================================================================
// Name        : MIAcommands.cpp
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Description : MIA commands and their respective runners.
//============================================================================

//#include <windows.h>
#include <iostream>
#include <string>
#include "MIAprogram.h"
#include "D3CEncrypt.h"
#include "D3CEncryptPW.h"
#include "MIAcommands.h"
#include "D3CMath.h"
/* CURRENTLY ONLY WORKS ON WINDOWS
#include "Keys.h"
*/

//Main commands constructor.
Commands::Commands(){
	//Chuck Norris writes code that optimizes itself. Be like chuck Norris.
}

//Main commands deconstructor.
Commands::~Commands(){
	//Chuck Norris can write infinite recursion functions... and have them return.
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
	output = crypt.Crypt(input, true);
	
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
	output = crypt.DeCrypt(input, true);
	
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

	std::cout << "...Enter a positive Integer of any length: " << std::endl;
	prog.blankLine();
	getline(std::cin, input);
	prog.blankLine();
	
	long output = math.sumOfDigits(input);
	
	std::cout << "Sum of Digits: " << output << std::endl;        
	prog.blankLine();
}

//Main UI runner for the D3CMath primeFactors() function.
void Commands::primeFactorsRunner(){
	Program prog;
	std::D3CMath math;
	std::string input;

	std::cout << "...Enter a positive Integer: " << std::endl;
	prog.blankLine();
	getline(std::cin, input);
	prog.blankLine();
	
	long longInput = std::atol(input.c_str());

	std::cout << "...The prime factors are: ";
	for (long i = 1; i <= (longInput + 1) / 2; i++) {
		if (math.isPrime(i) == true && longInput % i == 0){
			std::cout << i << " ";
		}
	}
	prog.blankLine();
}

//Main UI runner for the D3CMath numberOfFactors() function.
void Commands::numberOfFactorsRunner(){
	Program prog;
	std::D3CMath math;
	std::string input;

	std::cout << "...Enter a positive Integer: " << std::endl;
	prog.blankLine();
	getline(std::cin, input);
	prog.blankLine();
	
	long longInput = std::atol(input.c_str());
	
	int factors = math.numberOfFactors(longInput);

	std::cout << "...The number of factors are: " << factors << std::endl;
	prog.blankLine();
}

//Main UI runner for the D3CMath isTriangleNumber() function.
void Commands::isTriangleNumberRunner(){
	Program prog;
	std::D3CMath math;
	std::string input;

	std::cout << "...Enter a positive Integer: " << std::endl;
	prog.blankLine();
	getline(std::cin, input);
	prog.blankLine();
	
	long longInput = std::atol(input.c_str());
	
	if(math.isTriangleNumber(longInput)){
		std::cout << "...The number you entered is a triangle number." << std::endl;
	}else{
		std::cout << "...The number you entered is NOT a triangle number." << std::endl;
	}
	prog.blankLine();
}

//Main UI runner for the D3CMath latticePaths() function.
void Commands::latticePathsRunner(){
	Program prog;
	std::D3CMath math;
	std::string n, m;
	
	prog.blankLine();
	std::cout << "...IMPORTANT: This feature depends on the c++ long. " << std::endl;
	std::cout << "...Therefore if the lattice paths exceed 2147483647,  " << std::endl;
	std::cout << "...the answers will no longer be reliable. " << std::endl;
	prog.blankLine();
	
	std::cout << "...Enter grid size in horizontal direction: : " << std::endl;
	prog.blankLine();
	getline(std::cin, n);
	prog.blankLine();
	std::cout << "...Enter grid size in vertical direction: : " << std::endl;
	prog.blankLine();
	getline(std::cin, m);
	prog.blankLine();
	
	long intOne = std::atol(n.c_str());
	long intTwo = std::atol(m.c_str());
    long output = math.latticePathsOfSquare(intOne, intTwo);
	
	std::cout << "...The total lattice paths are: " << output << std::endl;
	prog.blankLine();
}

//Main UI runner for the D3CMath primeN() function.
void Commands::primeNRunner(){
	Program prog;
	std::D3CMath math;
	std::string input;

	std::cout << "...Enter a positive integer: " << std::endl;
	prog.blankLine();
	getline(std::cin, input);
	prog.blankLine();
	
	long longInput = std::atol(input.c_str());
    long output = math.primeNumberN(longInput);
	
	std::cout << "...Prime number " << input << ": " << output << std::endl;
	prog.blankLine();
}

//Main UI runner for the D3CMath primeNPopulate() function.
void Commands::primeNumberNpopulateRunner(){
	Program prog;
	std::D3CMath math;
	
	prog.blankLine();
	std::cout << "...PrimeNumberList.txt now being written to: " << math.returnPrimeNlocation() << std::endl;
	std::cout << "...This file will increase the efficiency of the 'prime -n' command." << std::endl;
	std::cout << "...This may take some time..." << std::endl;
	prog.blankLine();
	
	math.primeNumberNpopulate();
}

//Main UI runner for the D3CMath primeNerase() function.
void Commands::primeNumberNeraseRunner(){
	std::D3CMath math;
	math.primeNumberNerase();
}

/* CURRENTLY ONLY WORKS ON WINDOWS

//Spams a button a specific number of times.
void Commands::buttonSpamRunner(){
	Program prog;
	Keys key;
	
	std::string button;

	std::cout << "...Enter a button you would like spammed: ";
	getline(std::cin, button);
	prog.blankLine();
	
	std::string amountStr;

	std::cout << "...How many times would you like it spammed? ";
	getline(std::cin, amountStr);
	prog.blankLine();
	
	int amount = std::atoi(amountStr.c_str());
	
	std::cout << "...Preparing to spam " << button << " " << amountStr << " times." << std::endl;
	std::cout << "...Beginning in 5 seconds." << std::endl;
	prog.blankLine();

	key.buttonSpam(button, amount);
}

//performs a sequence to perpetually dig as you would in minecraft.
void Commands::minecraftDigRunner(){
	Program prog;
	Keys key;
	
	std::string input;

	std::cout << "...How long would you like to dig for (in seconds)? ";
	getline(std::cin, input);
	prog.blankLine();
	
	int time = std::atoi(input.c_str());
	
	std::cout << "...Beginning in 5 seconds." << std::endl;
	key.minecraftDig(time);
}

*/ 






