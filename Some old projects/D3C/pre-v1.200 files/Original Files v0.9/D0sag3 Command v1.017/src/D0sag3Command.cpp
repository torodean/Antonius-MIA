//============================================================================
// Name        : D0sag3.cpp
// Author      : Antonius Torode
// Version     : 1.005
// Copyright   : Copywrite Antonius Torode 2014
// Description : D0sag3 Command in C++, Ansi-style
//============================================================================

#include <iostream>
#include "D0sag3Crypt.h"
#include "D0sag3Math.h"
#include "D0sag3Kinematics.h"
#include "D0sag3Help.h"
#include "D0sag3Convert.h"
#include "unistd.h"
#include "D0sag3Convert.h"
#include "D0sag3Conversation.h"
using namespace std;

int variable;
string function, input, output, intOne, intTwo;
long longInput, longInput2;

D0sag3Crypt d0sag3Crypt;
D0sag3Math d0sag3Math;
D0sag3Help d0sag3Help;
D0sag3Kinematics d0sag3Kinematics;
D0sag3Convert d0sag3Convert;
D0sag3Conversation d0sag3Conversation;

int main() {
	cout << "DDDDDD     000000    SSSSSS   AAAAAA    GGGGGGG  333333" << endl;
	cout << "DD   DD   00    00  SS       AA    AA  GG             33" << endl;
	cout << "DD    DD  00    00  SS       AA    AA  GG             33" << endl;
	cout << "DD     D  00    00   SSSSS   AAAAAAAA  GG   GG     3333" << endl;
	cout << "DD    DD  00    00       SS  AA    AA  GG    GG       33" << endl;
	cout << "DD   DD   00    00       SS  AA    AA  GG    GG       33" << endl;
	cout << "DDDDDD     000000   SSSSSS   AA    AA   GGGGGG   333333" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~ d0sag3 Command Initialized ~~~~~~~~~~~~~~" << endl; // prints d0sag3 Command initialization:
	cout << "~~~~~~~~~~~~~~~~~~~~ Version: 1.017 ~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~ Type 'help' for a list of commands ~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	begin:

	variable=0;
	cout << endl;
	if(variable==0){
		cout << "Enter Command: ";
		getline(cin,function);
	}

	if(function == "crypt" || function =="Crypt"){
		variable = 1;
	}else if(function == "decrypt" || function == "Decrypt" || function == "DeCrypt"){
		variable = 2;
	}else if(function == "multiply" || function == "Multiply"){
		variable = 3;
	}else if(function == "add" || function == "Add"){
		variable = 4;
	}else if(function == "exit" || function == "Exit"){
		variable = 5;
	}else if(function == "help" || function == "Help"){
		variable = 6;
	}else if(function == "kinematics" || function == "Kinematics"){
		variable = 7;
	}else if(function == "convert" || function == "Convert"){
		variable = 8;
	}else if(function == "subtract" || function == "Subtract" || function == "sub"){
		variable = 9;
	}else if(function == "prime" || function == "Prime"){
		variable = 10;
	}else if(function == "help extended" || function == "Help extended"){
		variable = 11;
	}else if(function == "palindrome" || function == "Palindrome"){
		variable = 12;
	}else if(function == "sum of digits" || function == "Sum of digits"){
		variable = 13;
	}else if(function == "number of factors" || function == "Number of factors"){
		variable = 14;
	}else if(function == "triangle number" || function == "Triangle number"){
		variable = 15;
	}else if(function == "prime n" || function == "Prime n"){
		variable = 16;
	}else if(function == "prime n populate" || function == "Prime n populate"){
		variable = 17;
	}else if(function == "prime n erase" || function == "Prime n erase"){
		variable = 18;
	}else if(function == "prime factors" || function == "Prime factors"){
		variable = 19;
	}else if(function == "consecutive digit product" || function == "Consecutive digit product"){
		variable = 20;
	}else if(function == "collatz" || function == "Collatz"){
		variable = 21;
	}else if(function == "lattice paths" || function == "Lattice paths"){
		variable = 22;
	}

	switch( variable ){
	case 1:
		cout << "Enter message to Crypt: ";
		getline(cin, input);
		output = d0sag3Crypt.Crypt(input);
		cout << "d0sag3 Crypt: " << output << endl;
		goto begin;
	case 2:
		cout << "Enter message to Decrypt: ";
		getline(cin, input);
		output = d0sag3Crypt.DeCrypt(input);
		cout << "message: " << output << endl;
		goto begin;
	case 3:
		cout << "--Multiplication of Integers of any size--" << endl;
		cout << "Enter first Int to multiply: ";
		getline(cin, intOne);
		cout << "Enter second Int to multiply: ";
		getline(cin, intTwo);
		output = d0sag3Math.multiplyTwoStrings(intOne, intTwo);
		cout << "Integer Product: " << output << endl;
		goto begin;
	case 4:
		cout << "--Addition of Integers of any size--" << endl;
		cout << "Enter first Int to add: ";
		getline(cin, intOne);
		cout << "Enter second Int to add: ";
		getline(cin, intTwo);
		output = d0sag3Math.addTwoStrings(intOne, intTwo);
		cout << "Integer Sum: " << output << endl;
		goto begin;
	case 5:
		break;
	case 6:
		d0sag3Help.helpRunner();
		goto begin;
	case 7:
		d0sag3Kinematics.kinematicsRunner();
		goto begin;
	case 8:
		cout << "This feature is not yet finished" << endl;
		d0sag3Convert.convertRunner();
		goto begin;
	case 9:
		cout << "--Subtraction of Integers of any size--" << endl;
		cout << "Enter first Integer: ";
		getline(cin, intOne);
		cout << "Enter second Integer to subtract from first: ";
		getline(cin, intTwo);
		output = d0sag3Math.subtractTwoStrings(intOne, intTwo);
		cout << "Integer Difference: " << output << endl;
		goto begin;
	case 10:
		cout << "Enter a positive Integer: ";
		cin >> longInput;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		if(d0sag3Math.isPrime(longInput)){
			cout << "The number you entered is prime." << endl;
		}else{
			cout << "The number you entered is not prime." << endl;
		}
		goto begin;
	case 11:
		d0sag3Help.helpRunnerExtended();
		goto begin;
	case 12:
		cout << "Enter a positive Integer: ";
		cin >> longInput;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		if(d0sag3Math.isPalindrome(longInput)){
			cout << "The number you entered is palindrome." << endl;
		}else{
			cout << "The number you entered is not palindrome." << endl;
		}
		goto begin;
	case 13:
		cout << "Enter a positive Integer of any length: ";
		getline(cin, input);
		cout << "Digit sum: " << d0sag3Math.sumOfDigits(input) << endl;
		goto begin;
	case 14:
		cout << "Enter a positive Integer: ";
		cin >> longInput;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		cout << "Number of factors: " << d0sag3Math.numberOfFactors(longInput) << endl;
		goto begin;
	case 15:
		cout << "Enter a positive Integer: ";
		cin >> longInput;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		if(d0sag3Math.isTriangleNumber(longInput)){
			cout << "The number you entered is a triangle number." << endl;
		}else{
			cout << "The number you entered is not a triangle number." << endl;
		}
		goto begin;
	case 16:
		cout << "Enter a positive Integer: ";
		cin >> longInput;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		d0sag3Math.primeNumberN(longInput);
		goto begin;
	case 17:
		d0sag3Math.primeNumberNpopulate();
		goto begin;
	case 18:
		d0sag3Math.primeNumberNerase();
		goto begin;
	case 19:
		cout << "Enter a positive integer: ";
		cin >> longInput;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		d0sag3Math.primeFactors(longInput);
		goto begin;
	case 20:
		cout << "Enter a positive integer of any size: ";
		getline(cin, input);
		cout << "Enter the number of consecutive numbers you would like to find the largest sum of: ";
		cin >> longInput;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		d0sag3Math.largestProductOfXConsecutiveNumbers(input, longInput);
		goto begin;
	case 21:
		cout << "Enter a starting number (positive integer): ";
		cin >> longInput;
		d0sag3Math.productCollatzSequence(longInput);
		goto begin;
	case 22:
		cout << "Enter grid size in horizontal direction: ";
		cin >> longInput;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		cout << "Enter grid size in virtical direction: ";
		cin >> longInput2;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		d0sag3Math.latticePathsOfSquare(longInput, longInput2);
		goto begin;
	default:
		if(d0sag3Conversation.isTerm(function)){
			d0sag3Conversation.reply(function);
		}else{
			cout << "You entered an invalid command: " << function << endl;
		}
		goto begin;
	}

	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~ © Antonius Torode 2014 ~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~ Program Terminated ~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	return 0;
}
