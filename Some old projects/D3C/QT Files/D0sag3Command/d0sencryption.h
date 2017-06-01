#ifndef D0SENCRYPTION_H
#define D0SENCRYPTION_H
#include <vector>
#include <string>

using namespace std;

class d0sEncryption{
private:
    int stringLength, vectorSize, digit, powerofDigit, powerofTen, devise, random7bitNum, random7bitbinary, encodedVec;
public:
    d0sEncryption();
    vector<int> stringToVector(string a);
    vector<int> binaryVector(vector<int> inputVector);
    int random7bit();
    int numberToBinary(int num);
    string a11b12(int x);
    string stringVectorToString(vector<string> a);
    string cryptChars(vector<int> inputVector);
    string cryptCharsNoRand(vector<int> inputVector);
    string Crypt(string input);
    string CryptNoRand(string input);
    vector<string> cryptedStringToVector(string a);
    vector<string> seperateRandom(vector<string> input);
    vector<int> vectorStringToInt(vector<string> a);
    vector<int> seperateBinary(vector<string> input);
    int a11b12toReg(string a11b12);
    vector<int> converta11b12vecToReg(vector<string> a);
    vector<int> numberVectorToBinaryVector(vector<int> a);
    vector<int> DeCryptChars(vector<int> a, vector<int> b);
    vector<int> binaryVectorToASCII(vector<int> a);
    string intVectorToString(vector<int> a);
    string DeCrypt(string input);
    ~d0sEncryption();
};

#endif // D0SENCRYPTION_H
