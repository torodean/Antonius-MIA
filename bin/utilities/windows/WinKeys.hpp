//============================================================================
// Name        : WinKeys.h
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Created on  : 2015 (Original) -- July 5, 2017 (MIA)
// Description : The header file corresponding to the WinKeys.cpp file.
//============================================================================

#ifndef WINKEYS_HPP
#define WINKEYS_HPP

#include "MIAProgram.h"

#include <windows.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include <stdio.h>

using std::string;

class WinKeys : public Program {
	private:
		int globalSleep = 50;
		INPUT ip;
		
		void fishBotIntro();
	protected:
		void getRGB(COLORREF& color, int& r, int& g, int& b);
	public:
		WinKeys();
		~WinKeys();
		
		//Keys.
		void one(int holdTime = 0);
		void two(int holdTime = 0);
		void three(int holdTime = 0);
		void four(int holdTime = 0);
		void five(int holdTime = 0);
		void six(int holdTime = 0);
		void seven(int holdTime = 0);
		void eight(int holdTime = 0);
		void nine(int holdTime = 0);
		void zero(int holdTime = 0);
		void dash();
		void equal();
		void tab();
		void enter();
		void a(int holdTime = 0);
		void b(int holdTime = 0);
		void c(int holdTime = 0);
		void d(int holdTime = 0);
		void e(int holdTime = 0);
		void f(int holdTime = 0);
		void g(int holdTime = 0);
		void h(int holdTime = 0);
		void i(int holdTime = 0);
		void j(int holdTime = 0);
		void k(int holdTime = 0);
		void l(int holdTime = 0);
		void m(int holdTime = 0);
		void n(int holdTime = 0);
		void o(int holdTime = 0);
		void p(int holdTime = 0);
		void q(int holdTime = 0);
		void r(int holdTime = 0);
		void s(int holdTime = 0);
		void t(int holdTime = 0);
		void u(int holdTime = 0);
		void v(int holdTime = 0);
		void w(int holdTime = 0);
		void x(int holdTime = 0);
		void y(int holdTime = 0);
		void z(int holdTime = 0);
		void numlock();
		void space();
		void alt0248();
		void alt136();
		void shift(char character);
		void press(string character, int holdTime = 0);
		void type(string word);
		void paste();
		void backslash();
		void slash();
		void leftclick();
		void rightclick();
		
		//Functions using the key presses.
		void buttonSpam(string button, int amount, int pause);
		void buttonSpamTab(string button, int amount, int pause);
		
		//functions relating to Minecraft.
		void minecraftDig(int time);
		
		//functions relating to World of Warcraft
		void duplicateLetter(int copies, string recipient);
		void unloadLetters(int copies);
		void WoWFishBot(string fishButton, string lureButton);
		
		//Other useful functions.
		void sleep(int ms = 500);
		void defaultSleep();
		void waitTime(int input); //DEPRECATED.
		void findMouseCoords(int waitTime);
		void getPixelColor();
		void getPixelColorAtMouse();
		void moveMouseTo(int x, int y);
};

#endif // WINKEYS_HPP
