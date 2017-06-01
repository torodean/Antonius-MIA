/*
 * D0sag3Crypt.h
 *
 *  Created on: Sep 24, 2014
 *      Author: Antonius Torode
 */

#include <vector>

#ifndef D0SAG3CRYPT_H_
#define D0SAG3CRYPT_H_

namespace std {

class D0sag3Crypt {
private:
	int stringLength, vectorSize, digit, powerofDigit, powerofTen, devise, random7bitNum, random7bitbinary, encodedVec;
public:
	D0sag3Crypt();
	vector<int> stringToVector(string a);
	vector<int> binaryVector(vector<int> inputVector);
	int random7bit();
	int numberToBinary(int num);
	string a11b12(int x);
	string stringVectorToString(vector<string> a);
	string cryptChars(vector<int> inputVector);
	string Crypt(string input);
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
	virtual ~D0sag3Crypt();
};

}/* namespace std */

#endif /* D0SAG3CRYPT_H_ */
