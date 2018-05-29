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
#include <algorithm>
#include "D3CEncrypt.h"
#include "D3CEncryptPW.h"
#include "MIACommands.h"
#include "D3CMath.h"
#include "MIAEncrypt.h"
#include "MIAMisc.h"

// Includes for a windows only compile.
#if  defined _WIN32 || defined _WIN64 || defined __CYGWIN__
#include <windows.h>
#include "WinKeys.h"
#include "LOLANetUse.h"
#endif

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::atol;
using std::atoi;
using std::to_string;
using std::getline;
using std::transform;

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
	
	D3CEncrypt crypt;
	
	prog.blankDots();
	cout << "...Please enter a string to encrypt: " << endl;
	prog.blankLine();
	
	string input, output;
	getline(cin,input);
	output = crypt.Crypt(input, true);
	
	prog.blankLine();
	cout << "...The encrypted output is: " << endl;
	prog.blankLine();
	cout << output << endl;
}

//Main UI runner for the D3CEncrypt (d0s1) program feature. DeCryption
void Commands::d0s1DeCryptRunner(){
	
	D3CEncrypt crypt;
	
	prog.blankDots();
	cout << "...Please enter a string to de-crypt: " << endl;
	prog.blankLine();
	
	string input, output;
	getline(cin,input);
	output = crypt.DeCrypt(input, true);
	
	prog.blankLine();
	cout << "...The de-crypted output is: " << endl;
	prog.blankLine();
	cout << output << endl;
}

//Main UI runner for the D3CEncryptPW (d0s2) program feature. Encryption
void Commands::d0s2CryptRunner(){
	
	D3CEncryptPW crypt;
	
	prog.blankDots();
	cout << "...Please enter a string to encrypt: " << endl;
	prog.blankLine();
	
	string input, password, output;
	getline(cin,input);
	
	prog.blankDots();
	cout << "...Please enter the password to encrypt: " << endl;
	prog.blankLine();
	
	getline(cin,password);
	output = crypt.EncryptPW(input, password);
	
	prog.blankLine();
	cout << "...The encrypted output is: " << endl;
	prog.blankLine();
	cout << output << endl;
}

//Main UI runner for the D3CEncryptPW (d0s2) program feature. DeCryption
void Commands::d0s2DeCryptRunner(){
	
	D3CEncryptPW crypt;
	
	prog.blankDots();
	cout << "...Please enter a string to de-crypt: " << endl;
	prog.blankLine();
	
	string input, password, output;
	getline(cin,input);
	
	prog.blankDots();
	cout << "...Please enter the password to de-crypt: " << endl;
	prog.blankLine();
	
	getline(cin,password);
	output = crypt.DecryptPW(input, password);
	
	prog.blankLine();
	cout << "...The de-crypted output is: " << endl;
	prog.blankLine();
	cout << output << endl;
}

//Main UI runner for the D3CMath productCollatzSequence() function.
void Commands::collatzRunner(){
	
	D3CMath math;
	string input, output;
	
	cout << "...Enter a starting number (positive integer): " << endl;
	prog.blankLine();
	getline(cin,input);
	prog.blankLine();
	
    long longInput = atol(input.c_str());
	
	output = math.productCollatzSequence(longInput);
	
	cout << "...collatz: " << output << endl;
	prog.blankLine();
	cout << "...Collatz sequence complete." << endl;
	prog.blankLine();
}

//Main UI runner for the D3CMath addTwoStrings() function.
void Commands::stringAdditionRunner(){
	
	D3CMath math;
	string intOne, intTwo, output;
	
	cout << "...Addition of two integers of any size." << endl << "...Enter first integer to add: " << endl;
	prog.blankLine();
	getline(cin, intOne);
	prog.blankLine();

	cout << "...Enter second integer to add: " << endl;
	prog.blankLine();
	getline(cin, intTwo);
	prog.blankLine();

	output = math.addTwoStrings(intOne, intTwo);

	cout << "...Integer sum: " << output << endl;
	prog.blankLine();
}

//Main UI runner for the D3CMath multiplyTwoStrings() function.
void Commands::stringMultiplyRunner(){
	
	D3CMath math;
	string intOne, intTwo, output;
	
	cout << "...Multiplication of two integers of any size." << endl << "...Enter first integer to multiply: " << endl;
	prog.blankLine();
	getline(cin, intOne);
	prog.blankLine();

	cout << "...Enter second integer to multiply: " << endl;
	prog.blankLine();
	getline(cin, intTwo);
	prog.blankLine();

	output = math.multiplyTwoStrings(intOne, intTwo);

	cout << "...Integer product: " << output << endl;
	prog.blankLine();	
}

//Main UI runner for the D3CMath subtractTwoStrings() function.
void Commands::stringSubtractionRunner(){
	
	D3CMath math;
	string intOne, intTwo, output;
	
	cout << "...Subtraction of two integers of any size." << endl << "...Enter first integer: " << endl;
	prog.blankLine();
	getline(cin, intOne);
	prog.blankLine();

	cout << "...Enter second integer to subtract: " << endl;
	prog.blankLine();
	getline(cin, intTwo);
	prog.blankLine();

	output = math.subtractTwoStrings(intOne, intTwo);

	cout << "...Integer difference: " << output << endl;
	prog.blankLine();
}

//Main UI runner for the D3CMath isPrime() function.
void Commands::isPrimeRunner(){
	
	D3CMath math;
	string input;

	cout << "...Enter a positive Integer: " << endl;
	prog.blankLine();
	getline(cin, input);
	prog.blankLine();
	
	long longInput = atol(input.c_str());
	
	if(math.isPrime(longInput)){
		cout << "...The number you entered is prime. " << endl;
	}else{
		cout << "...The number you entered is NOT prime. " << endl;
	}
	prog.blankLine();
}

//Main UI runner for the D3CMath isPalindrome() function.
void Commands::isPalindromeRunner(){
	
	D3CMath math;
	string input;

	cout << "...Enter a positive Integer: " << endl;
	prog.blankLine();
	getline(cin, input);
	prog.blankLine();
	
	long longInput = atol(input.c_str());
	
	if(math.isPalindrome(longInput)){
		cout << "...The number you entered is a palindrome. " << endl;
	}else{
		cout << "...The number you entered is NOT a palindrome. " << endl;
	}
	prog.blankLine();
}

//Main UI runner for the D3CMath sumOfDigits() function.
void Commands::sumOfDigitsRunner(){
	
	D3CMath math;
	string input;

	cout << "...Enter a positive Integer of any length: " << endl;
	prog.blankLine();
	getline(cin, input);
	prog.blankLine();
	
	long output = math.sumOfDigits(input);
	
	cout << "...Sum of Digits: " << output << endl;        
	prog.blankLine();
}

//Main UI runner for the D3CMath primeFactors() function.
void Commands::primeFactorsRunner(){
	
	D3CMath math;
	string input;

	cout << "...Enter a positive Integer: " << endl;
	prog.blankLine();
	getline(cin, input);
	prog.blankLine();
	
	long longInput = atol(input.c_str());

	cout << "...The prime factors are: ";
	for (long i = 1; i <= (longInput + 1) / 2; i++) {
		if (math.isPrime(i) == true && longInput % i == 0){
			cout << i << " ";
		}
	}
	prog.blankLine();
}

//Main UI runner for the D3CMath numberOfFactors() function.
void Commands::numberOfFactorsRunner(){
	
	D3CMath math;
	string input;

	cout << "...Enter a positive Integer: " << endl;
	prog.blankLine();
	getline(cin, input);
	prog.blankLine();
	
	long longInput = atol(input.c_str());
	
	int factors = math.numberOfFactors(longInput);

	cout << "...The number of factors are: " << factors << endl;
	prog.blankLine();
}

//Main UI runner for the D3CMath isTriangleNumber() function.
void Commands::isTriangleNumberRunner(){
	
	D3CMath math;
	string input;

	cout << "...Enter a positive Integer: " << endl;
	prog.blankLine();
	getline(cin, input);
	prog.blankLine();
	
	long longInput = atol(input.c_str());
	
	if(math.isTriangleNumber(longInput)){
		cout << "...The number you entered is a triangle number." << endl;
	}else{
		cout << "...The number you entered is NOT a triangle number." << endl;
	}
	prog.blankLine();
}

//Main UI runner for the D3CMath latticePaths() function.
void Commands::latticePathsRunner(){
	
	D3CMath math;
	string n, m;
	
	prog.blankLine();
	cout << "...IMPORTANT: This feature depends on the c++ long. " << endl;
	cout << "...Therefore if the lattice paths exceed 2147483647,  " << endl;
	cout << "...the answers will no longer be reliable. " << endl;
	prog.blankLine();
	
	cout << "...Enter grid size in horizontal direction: : " << endl;
	prog.blankLine();
	getline(cin, n);
	prog.blankLine();
	cout << "...Enter grid size in vertical direction: : " << endl;
	prog.blankLine();
	getline(cin, m);
	prog.blankLine();
	
	long intOne = atol(n.c_str());
	long intTwo = atol(m.c_str());
    long output = math.latticePathsOfSquare(intOne, intTwo);
	
	cout << "...The total lattice paths are: " << output << endl;
	prog.blankLine();
}

//Main UI runner for the D3CMath primeN() function.
void Commands::primeNRunner(){
	
	D3CMath math;
	string input;

	cout << "...Enter a positive integer: " << endl;
	prog.blankLine();
	getline(cin, input);
	prog.blankLine();
	
	long longInput = atol(input.c_str());
    long output = math.primeNumberN(longInput);
	
	cout << "...Prime number " << input << ": " << output << endl;
	prog.blankLine();
}

//Main UI runner for the D3CMath primeNPopulate() function.
void Commands::primeNumberNpopulateRunner(){
	
	D3CMath math;
	
	prog.blankLine();
	cout << "...PrimeNumberList.txt now being written to: " << math.returnPrimeNlocation() << endl;
	cout << "...This file will increase the efficiency of the 'prime -n' command." << endl;
	cout << "...This may take some time..." << endl;
	prog.blankLine();
	
	math.primeNumberNpopulate();
}

//Main UI runner for the D3CMath primeNerase() function.
void Commands::primeNumberNeraseRunner(){
	D3CMath math;
	math.primeNumberNerase();
}

//Spams a button a specific number of times.
void Commands::buttonSpamRunner(bool enableTab){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	
	WinKeys key;
	
	string button;

	cout << "...Enter a button you would like spammed: ";
	getline(cin, button);
	prog.blankLine();
	
	string amountStr;

	cout << "...How many times would you like it spammed? ";
	getline(cin, amountStr);
	prog.blankLine();
	
	int pause;
	
	cout << "...How long between each key press (in ms)? ";
	cin >> pause;
	prog.blankLine();
	
	int amount = atoi(amountStr.c_str());
	
	cout << "...Preparing to spam " << button << " " << amountStr << " times." << endl;
	cout << "...Beginning in 5 seconds." << endl;
	prog.blankLine();

	if (enableTab){
		key.buttonSpamTab(button, amount, pause);
	} else {
		key.buttonSpam(button, amount, pause);
	}
	
	#else
	
	prog.returnError(31416);
	#endif
}

//performs a sequence to perpetually dig as you would in minecraft.
void Commands::minecraftDigRunner(){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	
	WinKeys key;
	
	string input;

	cout << "...How long would you like to dig for (in seconds)? ";
	getline(cin, input);
	prog.blankLine();
	
	int time = atoi(input.c_str());
	
	cout << "...Beginning in 5 seconds." << endl;
	key.minecraftDig(time);
	
	#else
	
	prog.returnError(31416);
	#endif
}

//used to explore a minecraft map given that the user is gamemode=1.
void Commands::exploreMinecraft(){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	
	WinKeys key;
	
	int stepSize = 125, delayStartTime = 5000;
	double percentComplete = 0.0,  counter = 0.0;
	int breakTime;
	
	int startx, startz, stopx, stopz;
	
	cout << "...Please enter the lower numbers as the starting values." << endl;
	prog.blankLine();
	
	cout << "...Enter a starting X coordinate (integer): ";
	cin >> startx;
	prog.blankLine();
	
	cout << "...Enter an ending X coordinate (integer): ";
	cin >> stopx;
	prog.blankLine();
	
	cout << "...Enter a starting Z coordinate (integer): ";
	cin >> startz;
	prog.blankLine();
	
	cout << "...Enter an ending Z coordinate (integer): ";
	cin >> stopz;
	prog.blankLine();
	
	cout << "...Enter the intermidiate time between steps in milliseconds (integer): ";
	cin >> breakTime;
	prog.blankLine();
	
	double totalSteps = ((stopx-startx)*1.0/(stepSize*1.0)+1)*((stopz-startz)*1.0/(stepSize*1.0)+1);
	cout << "...totalSteps: " << totalSteps << endl;
	
	cout << "...Beginning in " << delayStartTime << " milliseconds." << endl;
	prog.blankLine();
	
	key.waitTime(delayStartTime);
	
	cout << "...Sleeping between each loop for " << breakTime << " milliseconds." << endl;

	
	for(int x=startx; x <= stopx; x++){
		for(int z=startz; z <= stopz; z++){
			
			key.type("t");
			key.waitTime(100);
			
			key.slash();
			key.type("tp");
			key.space();
			
			key.type(to_string(x));
			key.space();
			
			key.type("90");
			key.space();
			
			key.type(to_string(z));
			key.space();

			key.enter();
			
			counter += 1.0;
			percentComplete = counter*100.0/totalSteps;
			cout << "...Percentage Complete: " << percentComplete << " %" << endl;
			key.waitTime(breakTime);
			
			z+=stepSize-1;
		}		
		x+=stepSize-1;
	}
	
	#else
	
	prog.returnError(31416);
	#endif
}

//Runs the duplicate letter function which is useful for World of Warcraft.
void Commands::duplicateLetterRunner(){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	
	WinKeys keys;
	
	cout << "...INSTRUCTIONS: Please have the contents of the letter copied to your clipboard." << endl;
	cout << "...INSTRUCTIONS: After entering final parameters, move mouse curser to the WoW 'send' button." << endl;

	prog.blankLine();
	
	int copies;
	cout << "...Please enter the number of letters you want duplicated: ";
	cin >> copies;
	cin.ignore();
	prog.blankLine();
	
	string recipient;
	cout << "...Please enter the recipient you want the letters sent to: ";
	getline(cin, recipient);
	prog.blankLine();
	
	cout << "...Beginning in 5000 milliseconds (5s)." << endl;
	prog.blankLine();
	keys.duplicateLetter(copies, recipient);
	
	cout << "...Finished duplicating letters." << endl;
	
	#else
	
	prog.returnError(31416);
	#endif
}

//Runs the duplicate letter function which is useful for World of Warcraft.
void Commands::unloadLetterRunner(){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	
	WinKeys keys;
	
	cout << "...INSTRUCTIONS: Please have your WoW inbox open." << endl;
	cout << "...INSTRUCTIONS: Please set MIAConfig variables appropriately (see manual)." << endl;

	prog.blankLine();
	
	int copies;
	cout << "...Please enter the number of letters you want unloaded: ";
	cin >> copies;
	cin.ignore();
	prog.blankLine();
	
	cout << "...Beginning in 5000 milliseconds (5s)." << endl;
	prog.blankLine();
	keys.unloadLetters(copies);
	
	cout << "...Finished unloading letters." << endl;
	
	#else
	prog.returnError(31416);
	#endif
}

//Runs d0s3 encryption
void Commands::d0s3CryptRunner(){
	
	MIAEncrypt crypt(3);
	
	string inputFile;
	
	prog.returnError(31415);

	cout << "...Please enter a file (using default file path) to be encrypted: " << endl;
	prog.blankLine();
	getline(cin, inputFile);
	
	crypt.encryptFile(inputFile, "OutputFile");
}
	
//runs d0s3 decryption.	
void Commands::d0s3DeCryptRunner(){
	
	prog.returnError(31415);
}

//Prints a number of random lines from a text file. The user specifies the file and number of lines.
void Commands::printRandomLinesFromFileRunner(){	
	
	Misc misc;
	
	int lines;
	cout << "...How many random lines would you like to print from a file? ";
	cin >> lines;
	cin.ignore();
	prog.blankLine();

	string answer;
	cout << "...Would you like to use default input file path? (y/n): ";
	getline(cin, answer);
	prog.blankLine();
	
	if(prog.formOfYes(answer)){
		misc.printRandomLinesFromFile(true, lines);
	} else {
		misc.printRandomLinesFromFile(false, lines);
	}
}

//Runner for the solveQuadraticFormula function.
void Commands::solveQuadraticFormulaRunner(){
	
	D3CMath math;
	
	double a,b,c;
	cout << "...This is a solver for equations of the form a*x^2+b*x+c=0." << endl;
	cout << "...Please Enter a: ";
	cin >> a;
	cout << "...Please Enter b: ";
	cin >> b;
	cout << "...Please Enter c: ";
	cin >> c;	
	cin.ignore();
	prog.blankLine();
	
	string ans = math.solveQuadraticFormula(a,b,c);
	prog.blankLine();
	cout << "...The solution is: " << ans << endl;
}

//A joke function I created to rearrange the letters in a friends name. For unspecified reasons.
void Commands::pranjal(){
	Misc misc;
	string output = misc.shuffleString("pranjal");
	cout << "...Did you mean " << output << "?" << endl;
}

//Finds and returns the coordinates of the mouse pointer after 5 seconds.
void Commands::findMouse(){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	
	WinKeys keys;
	
	cout << "...Locating mouse in 2 seconds." << endl;
	
	keys.findMouseCoords(2000);
	
	#else
	
	prog.returnError(31416);
	#endif
}

//Function made for generating a workout via the Misc class.
void Commands::workoutRunner(bool weekly){
	Misc misc;
	string input; 
	cout << "...Loading MIA workout generator. " << endl;
	prog.blankDots();
	cout << "...Assuming default values, difficulties range from 0-100." << endl;
	cout << "...1-10 (VERY EASY), 11-24 (EASY), 25-39 (NORMAL)" << endl;
	cout << "...39-54 (HARD), 54-74 (VERY HARD), 75+ (INSANE)" << endl;
	cout << "...Please enter a difficulty: ";
	getline(cin,input);
	
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	double difficulty;
	
	//The pranjal input for a difficulty is a joke reference to a friend.
	if(input == "pranjal"){
		difficulty = 0.0;
	} else {
		difficulty = stod(input);
	}
	if (weekly){
		misc.generateWorkout(difficulty, true);
	} else {
		misc.generateWorkout(difficulty, false);
	}
}

//runs the eyedropper command which determines the color of the pixel at the mouse location.
void Commands::eyedropper(){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	
	WinKeys keys;
	
	keys.getPixelColorAtMouse();
	
	#else
	
	prog.returnError(31416);
	#endif
}

//Runs a fishbot for World of Warcraft.
void Commands::runFishbot(){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	
	WinKeys keys;
	
	//Default values.
	string fishButton = "3", lureButton = "8";
	
	cout << "...CAUTION! This fishbot was made for educational purposes." << endl;
	cout << "...WARNING! Use the fishbot at your own risk!" << endl;
	cout << "...DANGER! Using this fishbot may have negative consequences." << endl;
	cout << "...ALERT! This fishbot may get you banned." << endl;
	prog.blankDots();
	cout << "...In order for the fishbot to work, please enter in game settings and DISABLE" << endl << "... hardware cursor. See the manual for more details." << endl;
	cout << "...To use default values (3 for cast and 8 for lure) leave the following options" << endl << "... blank." << endl;
	cout << "...Press CTRL-C to stop the fishbot early once started." << endl;
	cout << "...Press ENTER to continue." << endl;
	cin.ignore();

	prog.blankDots();
	cout << "...Please enter which button you have set to cast: ";
	getline(cin, fishButton);
	prog.blankLine();
	cout << "...If you are not using a lure please enter 'NONE' " << endl;
	cout << "...Please enter which button you have set to apply a lure: ";
	getline(cin, lureButton);
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
	
	prog.returnError(31416);
	#endif
}

//Runs the NetSessionEnumRunner from the LOLANetUse.cpp file
void Commands::runNetSessionEnum(){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	
	prog.returnError(31415);
	LOLANetUse lola;
	string server;
	int argc = 4;  //set to 4 indicating that all fields [0] -> [3] of argv are filled.
	
	cout << "...Please enter a server address for me to gather information about." << endl;
	prog.blankLine();
	getline(cin, server);
	prog.blankLine();
	
	const size_t len = server.length() + 1;
	if(prog.getVerboseMode())
		cout << "len: " << len << endl;
    wchar_t w_server[len];

    swprintf(w_server, len, L"%s", server.c_str());
	
	cout << "...Loading NetSessionEnumRunner." << endl;
	if(prog.getVerboseMode()){
		cout << "...w_server: " << w_server << endl;
		cout << "...*w_server: " << *w_server << endl;
		cout << "...&w_server: " << &w_server << endl;
		cout << "...server.c_str(): " << server.c_str() << endl;
	}
	
	wchar_t *argv[] = {NULL, w_server, NULL, NULL};
	lola.NetSessionEnumRunner(argc, argv);
	
	prog.blankDots();
	cout << "...NetSessionEnumRunner Finished." << endl;
	
	#else
	prog.returnError(31416);
	#endif
}

//Runs the NetServerEnumRunner_WKST from the LOLANetUse.cpp file
//Valid modes are 'w' for workstation or 's' for server
void Commands::runNetServerEnum(char mode){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	
	prog.returnError(31415);
	LOLANetUse lola;
	string domain;
	int argc = 2;  //set to 2 indicating that all fields [0] -> [1] of argv are filled.
	
	cout << "...Please enter a domain for me to gather information about." << endl;
	prog.blankLine();
	getline(cin, domain);
	prog.blankLine();
	
	const size_t len = domain.length() + 1;
    wchar_t w_domain[len];

    swprintf(w_domain, len, L"...%s", domain.c_str());

	wchar_t *argv[] = {NULL, w_domain};
	cout << "...Loading NetServerEnum." << endl;
	if(prog.getVerboseMode()){
		cout << "...w_domain: " << w_domain << endl;
		cout << "...*w_domain: " << *w_domain << endl;
		cout << "...&w_domain: " << &w_domain << endl;
		cout << "...domain.c_str(): " << domain.c_str() << endl;
	}
	
	if(mode == 'w'){
		lola.NetServerEnumRunner_WKST(argc, argv);
	} else if(mode == 's'){
		lola.NetServerEnumRunner_SERV(argc, argv);
	}
	
	prog.blankDots();
	cout << "...NetServerEnum Finished!." << endl;
	
	#else
	prog.returnError(31416);
	#endif
}

//Runs the NetWkstaGetInfoRunner from the LOLANetUse.cpp file
void Commands::runNetWkstaGetInfo(){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
		
	prog.returnError(31415);
	LOLANetUse lola;
	string wkst;
	int argc = 2;  //set to 4 indicating that all fields [0] -> [1] of argv are filled.
	
	cout << "...Please enter a workstation address for me to gather information about." << endl;
	prog.blankLine();
	getline(cin, wkst);
	prog.blankLine();
	
	const size_t len = wkst.length() + 1;
    wchar_t w_wkst[len];

    swprintf(w_wkst, len, L"...%s", wkst.c_str());
	
	cout << "...Loading NetWkstaGetInfo." << endl;
	if(prog.getVerboseMode()){
		cout << "...w_wkst: " << w_wkst << endl;
		cout << "...*w_wkst: " << *w_wkst << endl;
		cout << "...&w_wkst: " << &w_wkst << endl;
		cout << "...wkst.c_str(): " << wkst.c_str() << endl;
	}
	
	wchar_t *argv[] = {NULL, w_wkst};
	lola.NetWkstaGetInfoRunner(argc, argv);
	
	prog.blankDots();
	cout << "...NetSessionEnum Finished." << endl;
	
	#else
	prog.returnError(31416);
	#endif
}

//Runs the NetRemoteComputerSupportsRunner from the LOLANetUse.cpp file
void Commands::runNetRemoteComputerSupports(){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
		
	prog.returnError(31415);
	LOLANetUse lola;
	string wkst;
	int argc = 2;  //set to 4 indicating that all fields [0] -> [1] of argv are filled.
	
	cout << "...Please enter a workstation address for me to gather information about." << endl;
	prog.blankLine();
	getline(cin, wkst);
	prog.blankLine();
	
	const size_t len = wkst.length() + 1;
    wchar_t w_wkst[len];

    swprintf(w_wkst, len, L"...%s", wkst.c_str());
	
	cout << "...Loading NetRemoteComputerSupports." << endl;
	if(prog.getVerboseMode()){
		cout << "...w_wkst: " << w_wkst << endl;
		cout << "...*w_wkst: " << *w_wkst << endl;
		cout << "...&w_wkst: " << &w_wkst << endl;
		cout << "...wkst.c_str(): " << wkst.c_str() << endl;
	}
	
	wchar_t *argv[] = {NULL, w_wkst};
	lola.NetRemoteComputerSupportsRunner(argc, argv);
	
	prog.blankDots();
	cout << "...NetRemoteComputerSupports Finished." << endl;
	
	#else
	prog.returnError(31416);
	#endif
}

//Runs the NetUserEnumRunner from the LOLANetUse.cpp file
void Commands::runNetUserEnum(){
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
		
	prog.returnError(31415);
	LOLANetUse lola;
	string wkst;
	int argc = 2;  //set to 4 indicating that all fields [0] -> [1] of argv are filled.
	
	cout << "...Please enter a server for me to gather information about." << endl;
	prog.blankLine();
	getline(cin, wkst);
	prog.blankLine();
	
	const size_t len = wkst.length() + 1;
    wchar_t w_wkst[len];

    swprintf(w_wkst, len, L"...%s", wkst.c_str());
	
	cout << "...Loading NetUserEnum." << endl;
	if(prog.getVerboseMode()){
		cout << "...w_wkst: " << w_wkst << endl;
		cout << "...*w_wkst: " << *w_wkst << endl;
		cout << "...&w_wkst: " << &w_wkst << endl;
		cout << "...wkst.c_str(): " << wkst.c_str() << endl;
	}
	
	wchar_t *argv[] = {NULL, w_wkst};
	lola.NetUserEnumRunner(argc, argv);
	
	prog.blankDots();
	cout << "...NetUserEnum Finished." << endl;
	
	#else
	prog.returnError(31416);
	#endif
}

//Rolls a dice using commands programmed in misc class.
void Commands::rollDice(string input){
	Misc misc;
	int dr = misc.roll(input);
}





//Function made for testing.
//This should be placed at the end of the file for easy accessibility. 
void Commands::test(){
	//prog.returnError(31418); //Returns nothing set for testing.
	
	///* Uncomment this for testing things for Windows only.
	#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	//runNetUserEnum();
	
	Misc misc;
	bool yes = false;
	int dr = 0;
	for (int i=0;i<1000;i++){
		dr = misc.roll("15d6");
		if (dr < 40)
			yes = true;
	}
	if (yes)
		cout << "YEA BOI!!!!!" << endl;

	#else
	prog.returnError(31416);
	#endif
	//*/
}

