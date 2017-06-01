/*
 * D0sag3Help.cpp
 *
 *  Created on: Oct 10, 2014
 *      Author: antonius
 */
#include <iostream>
#include "D0sag3Help.h"

namespace std {

D0sag3Help::D0sag3Help() {
	// TODO Auto-generated constructor stub

}

void D0sag3Help::helpRunner(){
	cout << "~~ Valid commands are ~~" << endl;
	cout << "\t- add : Adds two positive integers of any length." << endl;
	cout << "\t- convert : Converts units to other units. (only mass conversions programmed so far)" << endl;
	cout << "\t- crypt : Encrypts any string." << endl;
	cout << "\t- deCrypt : Decrypts any string." << endl;
	cout << "\t- help extended : Gives the user a list of extended commands that are not as commonly used." << endl;
	cout << "\t- kinematics : Solves for unknowns using kinematic equations. (only 1 dimensional programmed)" << endl;
	cout << "\t- mutiply : Multiplies two positive or negative integers of any length." << endl;
	cout << "\t- subtract : subtracts two positive integers of any length. (Still buggy for some problems)" << endl;
	cout << "\t- exit : Terminates the program. " << endl;
}

void D0sag3Help::helpRunnerExtended(){
	cout << "~~ Extended valid extended commands are ~~" << endl;
	cout << "\t- collatz : Produces a collatz sequence based on a starting integer that hte user inputs." << endl;
	cout << "\t- consecutive digit product : Finds the largest product of x consecutive numbers in a positive integer of any length." << endl;
	cout << "\t- lattice paths : Determines the amount of lattice paths to the bottom right corner of a square grid of size s x s" << endl;
	cout << "\t- number of factors : Returns the number of factors within an integer." << endl;
	cout << "\t- palindrome : Determines if a positive integer is palindrome." << endl;
	cout << "\t- prime : Determines if a positive integer is prime or not." << endl;
	cout << "\t- prime n : Calculates the n'th prime number up to a maximum number of 2147483647." << endl;
	cout << "\t- prime n populate : Creates a file of all prime numbers up to a maximum number of 2147483647. Run this file to increase the efficiency of the 'prime n' function greatly." << endl;
	cout << "\t- prime n erase: Clears the file created by 'prime n populate'." << endl;
	cout << "\t- prime factors : Determines all of the prime factors of a positive integer." << endl;
	cout << "\t- sum of digits : Returns the sum of the digits within a number." << endl;
	cout << "\t- triangle number : Determines if a number is a triangle number or not." << endl;
}

D0sag3Help::~D0sag3Help() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
