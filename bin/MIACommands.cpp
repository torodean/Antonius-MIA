//============================================================================
// Name        : MIACommands.cpp
// Author      : Antonius Torode
// Date        : 2017
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Description : MIA commands and their respective runners.
//============================================================================

#include <iostream>
#include <string>
#include "MIAProgram.h"
#include "D3CEncrypt.h"
#include "D3CEncryptPW.h"
#include "MIACommands.h"
#include "D3CMath.h"
#include "MIAEncrypt.h"
#include "MIAMisc.h"

// CURRENTLY ONLY WORKS ON WINDOWS
#if  defined _WIN32 || defined _WIN64 || defined __CYGWIN__
#include <windows.h>
#include "WinKeys.h"
#include "LOLANetUse.h"
#endif



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
	
	std::cout << "...collatz: " << output << std::endl;
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

	std::cout << "...Integer sum: " << output << std::endl;
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

	std::cout << "...Integer product: " << output << std::endl;
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

	std::cout << "...Integer difference: " << output << std::endl;
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
	
	std::cout << "...Sum of Digits: " << output << std::endl;        
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

//Spams a button a specific number of times.
void Commands::buttonSpamRunner(bool enableTab){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	Program prog;
	WinKeys key;
	
	std::string button;

	std::cout << "...Enter a button you would like spammed: ";
	getline(std::cin, button);
	prog.blankLine();
	
	std::string amountStr;

	std::cout << "...How many times would you like it spammed? ";
	getline(std::cin, amountStr);
	prog.blankLine();
	
	int pause;
	
	std::cout << "...How long between each key press (in ms)? ";
	std::cin >> pause;
	prog.blankLine();
	
	int amount = std::atoi(amountStr.c_str());
	
	std::cout << "...Preparing to spam " << button << " " << amountStr << " times." << std::endl;
	std::cout << "...Beginning in 5 seconds." << std::endl;
	prog.blankLine();

	if (enableTab){
		key.buttonSpamTab(button, amount, pause);
	} else {
		key.buttonSpam(button, amount, pause);
	}
	
	#else
	Program prog;
	prog.returnError(31416);
	#endif
}

//performs a sequence to perpetually dig as you would in minecraft.
void Commands::minecraftDigRunner(){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	Program prog;
	WinKeys key;
	
	std::string input;

	std::cout << "...How long would you like to dig for (in seconds)? ";
	getline(std::cin, input);
	prog.blankLine();
	
	int time = std::atoi(input.c_str());
	
	std::cout << "...Beginning in 5 seconds." << std::endl;
	key.minecraftDig(time);
	
	#else
	Program prog;
	prog.returnError(31416);
	#endif
}

//used to explore a minecraft map given that the user is gamemode=1.
void Commands::exploreMinecraft(){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	Program prog;
	WinKeys key;
	
	int stepSize = 125, delayStartTime = 5000;
	double percentComplete = 0.0,  counter = 0.0;
	int breakTime;
	
	int startx, startz, stopx, stopz;
	
	std::cout << "...Please enter the lower numbers as the starting values." << std::endl;
	prog.blankLine();
	
	std::cout << "...Enter a starting X coordinate (integer): ";
	std::cin >> startx;
	prog.blankLine();
	
	std::cout << "...Enter an ending X coordinate (integer): ";
	std::cin >> stopx;
	prog.blankLine();
	
	std::cout << "...Enter a starting Z coordinate (integer): ";
	std::cin >> startz;
	prog.blankLine();
	
	std::cout << "...Enter an ending Z coordinate (integer): ";
	std::cin >> stopz;
	prog.blankLine();
	
	std::cout << "...Enter the intermidiate time between steps in milliseconds (integer): ";
	std::cin >> breakTime;
	prog.blankLine();
	
	double totalSteps = ((stopx-startx)*1.0/(stepSize*1.0)+1)*((stopz-startz)*1.0/(stepSize*1.0)+1);
	std::cout << "...totalSteps: " << totalSteps << std::endl;
	
	std::cout << "...Beginning in " << delayStartTime << " milliseconds." << std::endl;
	prog.blankLine();
	
	key.waitTime(delayStartTime);
	
	std::cout << "...Sleeping between each loop for " << breakTime << " milliseconds." << std::endl;

	
	for(int x=startx; x <= stopx; x++){
		for(int z=startz; z <= stopz; z++){
			
			key.type("t");
			key.waitTime(100);
			
			key.slash();
			key.type("tp");
			key.space();
			
			key.type(std::to_string(x));
			key.space();
			
			key.type("90");
			key.space();
			
			key.type(std::to_string(z));
			key.space();

			key.enter();
			
			counter += 1.0;
			percentComplete = counter*100.0/totalSteps;
			std::cout << "...Percentage Complete: " << percentComplete << " %" << std::endl;
			key.waitTime(breakTime);
			
			z+=stepSize-1;
		}		
		x+=stepSize-1;
	}
	
	#else
	Program prog;
	prog.returnError(31416);
	#endif
}

//Runs the duplicate letter function which is useful for World of Warcraft.
void Commands::duplicateLetterRunner(){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	Program prog;
	WinKeys keys;
	
	std::cout << "...INSTRUCTIONS: Please have the contents of the letter copied to your clipboard." << std::endl;
	std::cout << "...INSTRUCTIONS: After entering final parameters, move mouse curser to the WoW 'send' button." << std::endl;

	prog.blankLine();
	
	int copies;
	std::cout << "...Please enter the number of letters you want duplicated: ";
	std::cin >> copies;
	std::cin.ignore();
	prog.blankLine();
	
	std::string recipient;
	std::cout << "...Please enter the recipient you want the letters sent to: ";
	std::getline(std::cin, recipient);
	prog.blankLine();
	
	std::cout << "...Beginning in 5000 milliseconds (5s)." << std::endl;
	prog.blankLine();
	keys.duplicateLetter(copies, recipient);
	
	std::cout << "...Finished duplicating letters." << std::endl;
	
	#else
	Program prog;
	prog.returnError(31416);
	#endif
}

//Runs d0s3 encryption
void Commands::d0s3CryptRunner(){
	Program prog;
	MIAEncrypt crypt(3);
	
	std::string inputFile;
	
	prog.returnError(31415);

	std::cout << "...Please enter a file (using default file path) to be encrypted: " << std::endl;
	prog.blankLine();
	getline(std::cin, inputFile);
	
	crypt.encryptFile(inputFile, "OutputFile");
}
	
//runs d0s3 decryption.	
void Commands::d0s3DeCryptRunner(){
	Program prog;
	prog.returnError(31415);
}

//Prints a number of random lines from a text file. The user specifies the file and number of lines.
void Commands::printRandomLinesFromFileRunner(){	
	Program prog;
	Misc misc;
	
	int lines;
	std::cout << "...How many random lines would you like to print from a file? ";
	std::cin >> lines;
	std::cin.ignore();
	prog.blankLine();

	std::string answer;
	std::cout << "...Would you like to use default input file path? (y/n): ";
	getline(std::cin, answer);
	prog.blankLine();
	
	if(prog.formOfYes(answer)){
		misc.printRandomLinesFromFile(true, lines);
	} else {
		misc.printRandomLinesFromFile(false, lines);
	}
}

//Runner for the solveQuadraticFormula function.
void Commands::solveQuadraticFormulaRunner(){
	Program prog;
	std::D3CMath math;
	
	double a,b,c;
	std::cout << "...This is a solver for equations of the form a*x^2+b*x+c=0." << std::endl;
	std::cout << "...Please Enter a: ";
	std::cin >> a;
	std::cout << "...Please Enter b: ";
	std::cin >> b;
	std::cout << "...Please Enter c: ";
	std::cin >> c;	
	std::cin.ignore();
	prog.blankLine();
	
	std::string ans = math.solveQuadraticFormula(a,b,c);
	prog.blankLine();
	std::cout << "...The solution is: " << ans << std::endl;
}

//A joke function I created to rearrange the letters in a friends name. For unspecified reasons.
void Commands::pranjal(){
	Misc misc;
	std::string output = misc.shuffleString("pranjal");
	std::cout << "...Did you mean " << output << "?" << std::endl;
}

//Finds and returns the coordinates of the mouse pointer after 5 seconds.
void Commands::findMouse(){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	Program prog;
	WinKeys keys;
	
	std::cout << "...Locating mouse in 2 seconds." << std::endl;
	
	keys.findMouseCoords(2000);
	
	#else
	Program prog;
	prog.returnError(31416);
	#endif
}

//Function made for testing.
void Commands::test(){
	Program prog;
	prog.returnError(31418); //Returns nothing set for testing.
	
	///* Uncomment this for testing things for Windows only.
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__


	#else

	prog.returnError(31416);
	#endif
	//*/
}

//runs the eyedropper command which determines the color of the pixel at the mouse location.
void Commands::eyedropper(){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	Program prog;
	WinKeys keys;
	
	keys.getPixelColorAtMouse();
	
	#else
	Program prog;
	prog.returnError(31416);
	#endif
}

//Runs a fishbot for World of Warcraft.
void Commands::runFishbot(){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	Program prog;
	WinKeys keys;
	
	//Default values.
	std::string fishButton = "3", lureButton = "8";
	
	std::cout << "...CAUTION! This fishbot was made for educational purposes." << std::endl;
	std::cout << "...WARNING! Use the fishbot at your own risk!" << std::endl;
	std::cout << "...DANGER! Using this fishbot may have negative consequences." << std::endl;
	std::cout << "...ALERT! This fishbot may get you banned." << std::endl;
	prog.blankDots();
	std::cout << "...In order for the fishbot to work, please enter in game settings and DISABLE" << std::endl << "... hardware cursor." << std::endl;
	std::cout << "...To use default values (3 for cast and 8 for lure) leave the following options" << std::endl << "... blank." << std::endl;
	std::cout << "...Press CTRL-C to stop the fishbot early once started." << std::endl;
	std::cout << "...Press ENTER to continue." << std::endl;
	std::cin.ignore();

	prog.blankDots();
	std::cout << "...Please enter which button you have set to cast: ";
	std::getline(std::cin, fishButton);
	prog.blankLine();
	std::cout << "...If you are not using a lure please enter NONE ";
	std::cout << "...Please enter which button you have set to apply a lure: ";
	std::getline(std::cin, lureButton);
	prog.blankLine();
	
	//Arbitrary default values based on my preferred setup.
	if(fishButton == "" || fishButton == "\n" || fishButton == "\r"){
		fishButton = "3";
	}
	if(lureButton == "" || lureButton == "\n" || lureButton == "\r"){
		lureButton = "8";
	}
	
	keys.WoWFishBot(fishButton, lureButton);
	
	#else
	Program prog;
	prog.returnError(31416);
	#endif
}

