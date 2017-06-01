#ifndef MATHEMATICS_H
#define MATHEMATICS_H
#include <vector>
#include <string>

using namespace std;

class Mathematics{
private:

public:
    Mathematics();
    bool isPrime(long number);
    bool isPalindrome(long number);
    long sumOfDigits(string number);
    int numberOfFactors(long x);
    bool isTriangleNumber(long x);
    int numOfDigitsString(string x);
    void primeFactors(long x);
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
    ~Mathematics();
};

#endif // MATHEMATICS_H
