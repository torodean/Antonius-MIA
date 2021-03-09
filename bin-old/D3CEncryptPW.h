//============================================================================
// Name        : D3CEncryptPW.h
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Created on  : October, 2014
// Description : The header file for use with D3CEncryptPW.cpp
//============================================================================

#ifndef D3CENCRYPTPW_H
#define D3CENCRYPTPW_H

#include <string>
#include <vector>

using std::string;

class D3CEncryptPW{
	public:
		D3CEncryptPW();
		~D3CEncryptPW();
		string EncryptPW(string message, string password);
		string DecryptPW(string message, string password);
		std::vector<int> stringToVector(string a);
		string PWRepeat(string PW, int PWR, int PWM);
		string PWmessageCombine(string message, string PW);
		string PWmessageUnCombine(string message, string PW);
		string invertString(string str);
};

#endif // D3CENCRYPTPW_H
