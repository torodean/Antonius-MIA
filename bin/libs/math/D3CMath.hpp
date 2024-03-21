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

/**
 * This class contains old math methods that were copied from old programs.
 * @ TODO - comment and organize this class.
 */
class D3CMath
{
private:
    string primeNlocation;
public:
    D3CMath();
    string returnPrimeNlocation();
    static long sumOfDigits(string number);
    static int numberOfFactors(long x);
    static bool isTriangleNumber(long x);
    static int numOfDigitsString(const string& x);
    void primeFactors(long x);
    long primeNumberN(long n);
    void primeNumberNpopulate(); // populates all prime numbers, this can be used to populate a list of all primes to increase the efficiency of primeNumberN();
    void primeNumberNerase();
    static int numOfDigitsInt(int x);
    static int setLargerInt(int One, int Two);
    static string zeroString(int length);
    static vector<int> stringToVector(string a);
    static string vectorToString(vector<int> a);
    static string resizeString(const string& a, string b);
    static string addTwoStrings(string stringOne, string stringTwo);
    static string addNegativeSign(string Total);
    static string subtractTwoStrings(string stringOne, string stringTwo);
    static string multiplyTwoStrings(string stringOne, string stringTwo);
    static long largestProductOfXConsecutiveNumbers(string string, long x);
    static string productCollatzSequence(long n);
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

