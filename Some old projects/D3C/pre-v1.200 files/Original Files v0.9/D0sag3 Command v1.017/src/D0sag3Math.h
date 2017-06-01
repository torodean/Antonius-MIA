/*
 * D0sag3Math.h
 *
 *  Created on: Oct 5, 2014
 *      Author: Antonius Torode
 */

#include <vector>
#include <string>

#ifndef D0SAG3MATH_H_
#define D0SAG3MATH_H_

namespace std {

class D0sag3Math {
public:
	D0sag3Math();
	bool isPrime(long number);
	bool isPalindrome(long number);
	long sumOfDigits(string number);
	int numberOfFactors(long x);
	bool isTriangleNumber(long x);
	int numOfDigitsString(string x);
	void primeFactors(long x);
	void primeNumberN(long n);
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
	void largestProductOfXConsecutiveNumbers(string string, long x);
	void productCollatzSequence(long n);
	void latticePathsOfSquare(long x, long y);
	virtual ~D0sag3Math();
};

} /* namespace std */

#endif /* D0SAG3MATH_H_ */
