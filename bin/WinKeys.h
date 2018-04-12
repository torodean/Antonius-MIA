//============================================================================
// Name        : WinKeys.h
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Created on  : 2015 (Original) -- July 5, 2017 (MIA)
// Description : The header file corresponding to the WinKeys.cpp file.
//============================================================================

#ifndef WINKEYS_H
#define WINKEYS_H
#include <string>
#include "MIAProgram.h"

using std::string;

class WinKeys{
	private:
		int globalSleep = 50;
		INPUT ip;
	public:
		WinKeys();
		~WinKeys();
		
		Program prog;
		
		//Keys.
		void one();
		void two();
		void three();
		void four();
		void five();
		void six();
		void seven();
		void eight();
		void nine();
		void zero();
		void dash();
		void equal();
		void tab();
		void enter();
		void a();
		void b();
		void c();
		void d();
		void e();
		void f();
		void g();
		void h();
		void i();
		void j();
		void k();
		void l();
		void m();
		void n();
		void o();
		void p();
		void q();
		void r();
		void s();
		void t();
		void u();
		void v();
		void w();
		void x();
		void y();
		void z();
		void space();
		void alt0248();
		void alt136();
		void shift(char character);
		void press(string character);
		void type(string word);
		void paste();
		void backslash();
		void slash();
		void leftclick();
		
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
		void waitTime(int input);
		void findMouseCoords(int waitTime);
		void getPixelColor();
		void getPixelColorAtMouse();
};

#endif // WINKEYS_H
