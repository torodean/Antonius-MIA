//============================================================================
// Name        : D3CEncrypt.cpp
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Created on  : September 24, 2014
// Description : A old encryption program (d0s1) re-adapted for use with MIA.
//============================================================================

#include <vector>
#include <sstream>
#include <cstdlib>
#include <math.h>
#include "D3CEncrypt.h"

namespace std {

//Constructor for the D3CEncrypt class.
D3CEncrypt::D3CEncrypt() : stringLength (0), vectorSize (0), digit (0), powerofDigit (0), 
		powerofTen (0), devise (0), random7bitNum (0), random7bitbinary (0), encodedVec (0){
    // TODO Auto-generated constructor stub
}

//Converts a string to a vector.
vector<int> D3CEncrypt::stringToVector(string a) { 
    stringLength = a.size();
    vector<int> vector(stringLength);
	
	//converts string one into an array of integers.
    for (int i = 0; i < stringLength; i++) { 
        vector[i] = a[i];
    }
    return vector;
}

//Converts each term in the vector array to a binary representation of that term.
vector<int> D3CEncrypt::binaryVector(vector<int> inputVector){ 
    vectorSize = inputVector.size();
    for(int i=0;i<vectorSize;i++){
        digit = inputVector[i];
        inputVector[i]=0;
        for(int x=6;x>=0;x--){
            powerofDigit = pow(2,x);
            powerofTen = pow(10, x);
            devise=digit/powerofDigit;
            if(devise == 1){
                inputVector[i]+=powerofTen;
                digit-=powerofDigit;
            }
        }
    }

    return inputVector;
}

//Creates a random number between 0-127.
int D3CEncrypt::random7bit(){ 
    random7bitNum = rand()% 128;
    return random7bitNum;
}

//Changes a number from base 10 format to a binary look but still in base 
//10 so that addition in base ten can be used on the binary number.
int D3CEncrypt::numberToBinary(int num) { 
    random7bitbinary=0;
    for (int x = 6; x >= 0; x--) {
        powerofDigit = pow(2, x);
        powerofTen = pow(10, x);
        devise = num / powerofDigit;
        if (devise == 1) {
            random7bitbinary += powerofTen;
            num -= powerofDigit;
        }
    }
    return random7bitbinary;
}

//Converts an integer to a custom a11b12 formatted number. 
//the first digit is in base 11 and the second in base 12.
string D3CEncrypt::a11b12(int x){ 
    int remaind, num;
    string ones, tens, a11b12string;
    ostringstream convertA, convertB;
    if(x<9){
        a11b12string.replace(0,1,"0");
        num = x;
        convertA << num;
        ones = convertA.str();
        a11b12string.replace(1,1,ones);
        goto ending;
    }
    if(x/12<=9){
        num = (x/12);
        convertA << num;
        tens = convertA.str();
        //tens = (x/12);
    }else if(x/12 == 10){
        tens = "A";
    }else if(x/12 == 11){
        tens = "B";
    }
    remaind = (x-(x/12)*12)%12;
    if(remaind <= 9){
        num = remaind;
        convertB << num;
        ones = convertB.str();
    }else if(remaind == 10){
        ones = "A";
    }else if(remaind == 11){
        ones = "B";
    }
    a11b12string.replace(0,1,tens);
    a11b12string.replace(1,1,ones);
    ending:
    return a11b12string;
}

//Converts a vector<string> (each position holding a string of length 9) to one combined string.
string D3CEncrypt::stringVectorToString(vector<string> a){ 

	//sets the integet of size to the size of the inputted vector.
    int size = a.size(); 
	
	//creates a variable called factor that is of type long. 
	//It is long because it is possible for large inputs that 9 times the size of the vector 
	//(the length of the output vector) maye be larger than the maximum int size.
    long factor; 
	
	//Creates a string of total to put the final return into.
    string total; 
	
	//resizes the total string to 9 times the length of the original input because each 
	//character will be represented by 9 digits after being crypted.
    total.resize(9*size); 
	
	//Creates a temporary string to be used later.
    string tempText; 
	
	//resizes the tempText string to 9 because it will be used to hold a single character as it's encrypted value.
    tempText.resize(9); 

    for(int i=0;i<size;i++){
		
		//Sets the tempText variable to the first part of the vector a.
        tempText=a[i]; 
		
		//Sets the long factor to 9 times i to determine which digit of the vector we are working on.
        factor = 9*i; 
        for(int x=0;x<9;x++){
			//sets the total string created earlier to the appropriate corresponding value of the vector a.
            total[factor+x] = tempText[x]; 
        }
    }
    return total; //Returns the total string.
}

//Encrypts the characters of a vector array with a random number.
string D3CEncrypt::cryptCharsNoRand(vector<int> inputVector){ 
    bool fix=false;
	
	//sets the Int of vectorSize to the size of the input.
    vectorSize = inputVector.size(); 
	
	//Creates a vector of type strings named encoded. 
	//It is set to the vectorSize and will be used to store the encoded vectors once they are combined with the random numbers.
    vector<string> encoded (vectorSize); 
    vector<int> randomVector;
    int randomNum;
	
	//reserves enought space within randomVector to place all of the 
	//random valiues to be combined with the string vector encoded later.
    randomVector.reserve(vectorSize); 

    for(int i=0;i<vectorSize; i++){
		//in this variation, the random number is instead set to just 49.
        randomNum = 49; 

		//stores the random number that was generated earlier within a vector randomVector 
		//that will contain all of the random numbers in the order that they are generated.
        randomVector[i] = randomNum; 

		//converts the random number generated to a binary form but keeps it in base 
		//10 so it can be added to the character for part of the crypt process.
        random7bitbinary = numberToBinary(randomNum); 

		//adds the random number in binary form to the original character in binary form, giving a base 3 number.
        inputVector[i]+=random7bitbinary; 
    }
    string encodedPart, encode = "000000000";
    encodedPart.reserve(2);
    encoded.reserve(vectorSize+2);
    for(int i=0;i<vectorSize; i++){
        encodedPart = a11b12(randomVector[i]);

        encodedVec = inputVector[i];

        if(encodedVec < 1000000){
            fix = true;
        }

        stringstream ss;
        ss << encodedVec;
        encode = ss.str();

        encode.resize(9);

        //In some cases, the anscii code generates a binary vector without the proper length 
		//of 6 (100000) which causes errors when trying to set the 7'th and 8th position. 
		//The below code will fix that by setting the first digit in the string to 0.
        if(fix == true){
            for(int y=6;y>0;y--){
                encode[y]=encode[y-1];
            }
            encode[0]='0';
            fix=false;
        }

		//set's the last 2 digits in encode equal to the a11b12 form of the random number generated for the specific character being coded.
        for(int x=7;x<9;x++){ 
            encode[x] = encodedPart[x-7];
        }

        encoded[i]=encode;
    }
    string finalEncode, outputVector;
    finalEncode = stringVectorToString(encoded);
    outputVector = finalEncode;
    return outputVector;
}

//Encrypts the characters of a vector array with a random number.
string D3CEncrypt::cryptChars(vector<int> inputVector){ 
    bool fix=false;
	
	//sets the Int of vectorSize to the size of the input.
    vectorSize = inputVector.size(); 
	
	//Creates a vector of type strings named encoded. 
	//It is set to the vectorSize and will be used to store the encoded vectors once they are combined with the random numbers.
    vector<string> encoded (vectorSize); 
    vector<int> randomVector;
    int randomNum;
	
	//reserves enought space within randomVector to place all of the
	//random valiues to be combined with the string vector encoded later.
    randomVector.reserve(vectorSize); 

    for(int i=0;i<vectorSize; i++){
		//creates a random number from 0-127 and stores it in the variable randomNum;
        randomNum=random7bit(); 
		
		//stores the random number that was generated earlier within a vector randomVector 
		//that will contain all of the random numbers in the order that they are generated.
        randomVector[i] = randomNum; 
		
		//converts the random number generated to a binary form but keeps it in base 
		//10 so it can be added to the character for part of the crypt process.
        random7bitbinary = numberToBinary(randomNum); 
		
		//adds the random number in binary form to the original 
		//character in binary form, giving a base 3 number.
        inputVector[i]+=random7bitbinary; 
    }
    string encodedPart, encode = "000000000";
    encodedPart.reserve(2);
    encoded.reserve(vectorSize+2);
    for(int i=0;i<vectorSize; i++){
        encodedPart = a11b12(randomVector[i]);

        encodedVec = inputVector[i];

        if(encodedVec < 1000000){
            fix = true;
        }

        stringstream ss;
        ss << encodedVec;
        encode = ss.str();

        encode.resize(9);

        //In some cases, the anscii code generates a binary vector without the proper length 
		//of 6 (100000) which causes errors when trying to set the 7'th and 8th position. 
		//The below code will fix that by setting the first digit in the string to 0.
        if(fix == true){
            for(int y=6;y>0;y--){
                encode[y]=encode[y-1];
            }
            encode[0]='0';
            fix=false;
        }

		//set's the last 2 digits in encode equal to the a11b12 form of the random number generated for the specific character being coded.
        for(int x=7;x<9;x++){ 
            encode[x] = encodedPart[x-7];
        }

        encoded[i]=encode;
    }
    string finalEncode, outputVector;
    finalEncode = stringVectorToString(encoded);
    outputVector = finalEncode;
    return outputVector;
}

//Encrypts a string.
string D3CEncrypt::CryptNoRand(string input){ 
    string cryptedVector;
    vector<int> baseTwoVector, inputVector;

    inputVector = stringToVector(input);
    baseTwoVector = binaryVector(inputVector);
    cryptedVector = cryptCharsNoRand(baseTwoVector);

    return cryptedVector;
}

//Encrypts a string.
string D3CEncrypt::Crypt(string input){ 
    string cryptedVector;
    vector<int> baseTwoVector, inputVector;
    inputVector = stringToVector(input);
    baseTwoVector = binaryVector(inputVector);
    cryptedVector = cryptChars(baseTwoVector);

    return cryptedVector;
}

//Converts a string after being encrypted using crypt() to a vector seperating each character into it's own position.
vector<string> D3CEncrypt::cryptedStringToVector(string a) { 
    stringLength = a.size()/9;
    long fact;
    string temp;
    temp.resize(9);
    vector<string> vector(stringLength);
    for(int i=0;i<stringLength;i++){
        fact = i*9;
        for(int x=0;x<9;x++){
            temp[x] = a[x+fact];
        }
        vector[i] = temp;
    }
    return vector;
}

vector<string> D3CEncrypt::seperateRandom(vector<string> input){
    vector<string> seperatedRandoms;
    vectorSize = input.size();
    string temp="00", temp2, tempchar1, tempchar2;
    temp.resize(2);
    temp2.resize(9);
    seperatedRandoms.resize(vectorSize);

    for(int i=0;i<vectorSize;i++){
        temp2=input[i];
        tempchar1 = temp2[7];
        tempchar2 = temp2[8];
        temp.replace(0,1,tempchar1);
        temp.replace(1,1,tempchar2);
        seperatedRandoms[i] = temp;
    }
    return seperatedRandoms;
}

vector<int> D3CEncrypt::vectorStringToInt(vector<string> a){
    vectorSize = a.size();
    vector<int> intVec (vectorSize);
    int tempInt;
    string tempString;

    for(int i=0;i<vectorSize;i++){
        tempString = a[i];
        for(int x=0;x<7;x++){
            tempInt = atoi(tempString.c_str());
        }
        intVec[i] = tempInt;
    }
    return intVec;
}

vector<int> D3CEncrypt::seperateBinary(vector<string> input){
    vectorSize = input.size();
    vector<string> trimmed (vectorSize);
    vector<int> seperatedChars (vectorSize);
    string temp;

    for(int i=0;i<vectorSize;i++){
        temp=input[i];
        temp.resize(7);
        trimmed[i] = temp;
    }

    seperatedChars = vectorStringToInt(trimmed);
    return seperatedChars;
}

int D3CEncrypt::a11b12toReg(string a11b12){
    string charOne, charTwo;
    int intOne, intTwo, reg=0;

    charOne = a11b12[0];
    charTwo = a11b12[1];

    if(charOne == "A"){
        reg+=120;
    } else {
        intOne = atoi(charOne.c_str());
        reg+=12*intOne;
    }
    if(charTwo == "A"){
        reg+=10;
    }else if(charTwo == "B"){
        reg+=11;
    }else{
        intTwo = atoi(charTwo.c_str());
        reg+=intTwo;
    }

    return reg;
}

vector<int> D3CEncrypt::converta11b12vecToReg(vector<string> a){
    vectorSize = a.size();
    vector<int> randomVector (vectorSize);
    string temp;
    int randomNum;

    for(int i=0;i<vectorSize;i++){
        temp = a[i];
        randomNum = a11b12toReg(temp);
        randomVector[i] = randomNum;
    }
    return randomVector;
}

vector<int> D3CEncrypt::numberVectorToBinaryVector(vector<int> a){
    vectorSize=a.size();
    vector<int> binaryRandomVector (vectorSize);
    int temp;

    for(int i=0;i<vectorSize;i++){
        temp = a[i];
        binaryRandomVector[i] = numberToBinary(temp);
    }
    return binaryRandomVector;
}

vector<int> D3CEncrypt::DeCryptChars(vector<int> a, vector<int> b){
    vectorSize = a.size();
    vector<int> deCryptedBinaryVector (vectorSize);

    for(int i=0;i<vectorSize;i++){
        deCryptedBinaryVector[i] = a[i] - b[i];
    }
    return deCryptedBinaryVector;
}

vector<int> D3CEncrypt::binaryVectorToASCII(vector<int> a){
    vectorSize = a.size();
    vector<int> deCryptedIntVector (vectorSize);
    int digit, character, power, twoPower;
    for(int i=0;i<vectorSize;i++){
        character = 0;
        digit = a[i];
        for(int x=6;x>=0;x--){
            power = pow(10,x);
            twoPower = pow(2, x);
            character += ((digit/power)%10)*(twoPower);
        }
        deCryptedIntVector[i] = character;
    }
    return deCryptedIntVector;
}

string D3CEncrypt::intVectorToString(vector<int> a){
    vectorSize = a.size();
    string deCryptedVector;
    deCryptedVector.resize(vectorSize);
    int character;
    for(int i=0;i<vectorSize;i++){
        character = a[i];
        deCryptedVector[i] = character;
    }
    return deCryptedVector;
}

//Decrypts a string encrypted with D3Crypt.
string D3CEncrypt::DeCrypt(string input){
    string deCryptedVector;
    vector<string> inputVector, seperatedRandomVector;
    vector<int> seperatedcharacterVector, baseTenRandomVector, randomVector, randomBinaryVector,deCryptedBinaryVector, deCryptedIntVector;
    inputVector = cryptedStringToVector(input);
    seperatedRandomVector = seperateRandom(inputVector);
    seperatedcharacterVector = seperateBinary(inputVector);
    randomVector = converta11b12vecToReg(seperatedRandomVector);
    randomBinaryVector = numberVectorToBinaryVector(randomVector);
    deCryptedBinaryVector = DeCryptChars(seperatedcharacterVector,randomBinaryVector);

    deCryptedIntVector = binaryVectorToASCII(deCryptedBinaryVector);
    deCryptedVector = intVectorToString(deCryptedIntVector);

    return deCryptedVector;
}

//Deconstructor for D3CEncrypt class.
D3CEncrypt::~D3CEncrypt() {
    // TODO Auto-generated destructor stub
}

}/* namespace std */

