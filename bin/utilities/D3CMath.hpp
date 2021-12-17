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

using std::string;
using std::vector;

class D3CMath
{
private:
    string primeNlocation;
public:
    D3CMath();
    string returnPrimeNlocation();
    long sumOfDigits(string number);
    int numberOfFactors(long x);
    bool isTriangleNumber(long x);
    int numOfDigitsString(const string& x);
    void primeFactors(long x);
    long primeNumberN(long n);
    void primeNumberNpopulate(); // populates all prime numbers, this can be used to populate a list of all primes to increase the efficiency of primeNumberN();
    void primeNumberNerase();
    int numOfDigitsInt(int x);
    int setLargerInt(int One, int Two);
    string zeroString(int length);
    vector<int> stringToVector(string a);
    string vectorToString(vector<int> a);
    string resizeString(const string& a, string b);
    string addTwoStrings(string stringOne, string stringTwo);
    string addNegativeSign(string Total);
    string subtractTwoStrings(string stringOne, string stringTwo);
    string multiplyTwoStrings(string stringOne, string stringTwo);
    long largestProductOfXConsecutiveNumbers(string string, long x);
    string productCollatzSequence(long n);
    static long latticePathsOfSquare(long x, long y);
    static string solveQuadraticFormula(double a, double b, double c);

    //std::string intToBinaryStr(int input, int bits);
    //unsigned long binaryStrToInt(std::string input, int bits);
    ~D3CMath();

    /**
    * Determines if a number is prime or not.
    * @tparam numberType - the type of parameter to use (int, long, short, etc)
    * @param number[numberType] - The value to check for primeness.
    * @return returns true if the number is prime.
    */
    template<class numberType>
    bool isPrime(numberType number);

    /**
     * etermines if a long number is a palindrome.
     * @param number[long] - number to check for palindromeness
     * @return returns true if the input is a palindrome.
     * Old function from 2011-ish
     */
    static bool isPalindrome(long number);
};
