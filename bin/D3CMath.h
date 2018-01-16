//============================================================================
// Name        : D3CMath.h
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Created on  : October 5, 2014
// Description : The header file for use with D3CMath.cpp
//============================================================================

#include <vector>
#include <string>

#ifndef D3CMath_H_
#define D3CMath_H_

namespace std {

class D3CMath {
	private:
		string primeNlocation;
	public:
		D3CMath();
		string returnPrimeNlocation();
		bool isPrime(long number);
		bool isPalindrome(long number);
		long sumOfDigits(string number);
		int numberOfFactors(long x);
		bool isTriangleNumber(long x);
		int numOfDigitsString(string x);
		void primeFactors(long x);
		long primeNumberN(long n);
		void primeNumberNpopulate(); // populates all prime numbers, this can be used to populate a list of all primes to increase the efficiency of primeNumberN();
		void primeNumberNerase();
		int numOfDigitsInt(int x);
		int setLargerInt(int One, int Two);
		string zeroString(int length);
		vector<int> stringToVector(string a);
		string vectorToString(vector<int> a);
		string resizeString(string a, string b);
		string addTwoStrings(string stringOne, string stringTwo);
		string addNegativeSign(string Total);
		string subtractTwoStrings(string stringOne, string stringTwo);
		string multiplyTwoStrings(string stringOne, string stringTwo);
		long largestProductOfXConsecutiveNumbers(string string, long x);
		string productCollatzSequence(long n);
		long latticePathsOfSquare(long x, long y);
		string solveQuadraticFormula(double a, double b, double c);
		
		//std::string intToBinaryStr(int input, int bits);
		//unsigned long binaryStrToInt(std::string input, int bits);
		virtual ~D3CMath();
};

} /* namespace std */

#endif /* D3CMath_H_ */
