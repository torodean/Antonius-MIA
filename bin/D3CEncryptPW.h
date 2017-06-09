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

class D3CEncryptPW{
	public:
		D3CEncryptPW();
		~D3CEncryptPW();
		std::string EncryptPW(std::string message, std::string password);
		std::string DecryptPW(std::string message, std::string password);
		std::vector<int> stringToVector(std::string a);
		std::string PWRepeat(std::string PW, int PWR, int PWM);
		std::string PWmessageCombine(std::string message, std::string PW);
		std::string PWmessageUnCombine(std::string message, std::string PW);
		std::string invertString(std::string str);
};

#endif // D3CENCRYPTPW_H
