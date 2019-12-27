//============================================================================
// Name        : WinKeys.cpp
// Author      : Antonius Torode
// Copyright   : This file can be used under the conditions of Antonius' 
//				 General Purpose License (AGPL).
// Created on  : 2015 (Original) -- July 5, 2017 (MIA)
// Description : The WinKeys Functions from the VKK program adapted for use with MIA.
//				 The key presses in this file were originally designed to work with Windows.
//               Also contains other windows functions.
//============================================================================

#define WINVER 0x0500

#include "WinKeys.h"

#include <windows.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include <stdio.h>

using std::cout;
using std::endl;
using std::string;

WinKeys::WinKeys(){
	// Chuck Norris can make a CPU run at 300% efficiency.
    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
}

WinKeys::~WinKeys(){
	// When Chuck Norris catches errors, he catches them with chopsticks.
}

//Simulates a pause/sleep for some number of milliseconds.
void WinKeys::sleep(int ms){
	if(prog.getVerboseMode()){
		cout << "...Sleeping for " << ms << " milliseconds." << endl;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

//DEPRECATED in version 0.147. sleep() function performs same action.
//Tells the program to sleep for some time in milliseconds.
void WinKeys::waitTime(int input){
	std::this_thread::sleep_for(std::chrono::milliseconds(input));
}

void WinKeys::defaultSleep(){
	sleep(globalSleep);
}

void WinKeys::space(){
    // Press the "space" key
    ip.ki.wVk = VK_SPACE; // virtual-key code for the "space" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

	if(prog.getVerboseMode())
		cout << "space" << endl;
	
    // Release the "space" key
    ip.ki.wVk = VK_SPACE; // virtual-key code for the "space" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    defaultSleep();
}

void WinKeys::one(int holdTime){
    // Press the "1" key
    ip.ki.wVk = 0x31; // virtual-key code for the "1" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);
	if(prog.getVerboseMode())
		cout << "1" << endl;

    // Release the "1" key
    ip.ki.wVk = 0x31; // virtual-key code for the "1" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    defaultSleep();
}

void WinKeys::two(int holdTime){
    // Press the "2" key
    ip.ki.wVk = 0x32; // virtual-key code for the "2" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);
	if(prog.getVerboseMode())
		cout << "2" << endl;

    // Release the "2" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    defaultSleep();
}

void WinKeys::three(int holdTime){
    // Press the "3" key
    ip.ki.wVk = 0x33; // virtual-key code for the "3" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);
	if(prog.getVerboseMode())
		cout << "3" << endl;

    // Release the "3" key
    ip.ki.wVk = 0x33; // virtual-key code for the "3" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    defaultSleep();
}

void WinKeys::four(int holdTime){
    // Press the "4" key
    ip.ki.wVk = 0x34; // virtual-key code for the "4" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);
	if(prog.getVerboseMode())
		cout << "4" << endl;

    // Release the "4" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    defaultSleep();
}

void WinKeys::five(int holdTime){
    // Press the "5" key
    ip.ki.wVk = 0x35; // virtual-key code for the "5" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);
	if(prog.getVerboseMode())
		cout << "5" << endl;

    // Release the "5" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    defaultSleep();
}

void WinKeys::six(int holdTime){
    // Press the "6" key
    ip.ki.wVk = 0x36; // virtual-key code for the "6" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);
	if(prog.getVerboseMode())
		cout << "6" << endl;

    // Release the "6" key
    ip.ki.wVk = 0x36; // virtual-key code for the "6" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    defaultSleep();
}

void WinKeys::seven(int holdTime){
    // Press the "7" key
    ip.ki.wVk = 0x37; // virtual-key code for the "7" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);
	if(prog.getVerboseMode())
		cout << "7" << endl;

    // Release the "7" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    defaultSleep();
}

void WinKeys::eight(int holdTime){
    // Press the "8" key
    ip.ki.wVk = 0x38; // virtual-key code for the "8" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);
	if(prog.getVerboseMode())
		cout << "8" << endl;

    // Release the "8" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    defaultSleep();
}

void WinKeys::nine(int holdTime){
    // Press the "9" key
    ip.ki.wVk = 0x39; // virtual-key code for the "9" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);
	if(prog.getVerboseMode())
		cout << "9" << endl;

    // Release the "9" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    defaultSleep();
}

void WinKeys::zero(int holdTime){
    // Press the "0" key
    ip.ki.wVk = 0x30; // virtual-key code for the "0" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);
	if(prog.getVerboseMode())
		cout << "0" << endl;

    // Release the "0" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    defaultSleep();
}

void WinKeys::dash(){
    // Press the "-" key
    ip.ki.wVk = VK_OEM_MINUS; // virtual-key code for the "-" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "-" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    defaultSleep();
}

void WinKeys::equal(){
    // Press the "=" key
    ip.ki.wVk = VK_OEM_PLUS; // virtual-key code for the "=" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "=" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    defaultSleep();
}

void WinKeys::tab(){
    // Press the "tab" key
    ip.ki.wVk = VK_TAB; // virtual-key code for the "tab" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	if(prog.getVerboseMode())
		cout << "TAB" << endl;

    // Release the "tab" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    defaultSleep();
}

void WinKeys::a(int holdTime){
    // Press the "a" key
    ip.ki.wVk = 0x41; // virtual-key code for the "a" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "a" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::b(int holdTime){
    // Press the "b" key
    ip.ki.wVk = 0x42; // virtual-key code for the "b" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "b" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::c(int holdTime){
    // Press the "c" key
    ip.ki.wVk = 0x43; // virtual-key code for the "c" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "c" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::d(int holdTime){
    // Press the "d" key
    ip.ki.wVk = 0x44; // virtual-key code for the "d" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "d" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::e(int holdTime){
    // Press the "e" key
    ip.ki.wVk = 0x45; // virtual-key code for the "e" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "e" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::f(int holdTime){
    // Press the "f" key
    ip.ki.wVk = 0x46; // virtual-key code for the "f" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "f" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::g(int holdTime){
    // Press the "g" key
    ip.ki.wVk = 0x47; // virtual-key code for the "g" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "g" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::h(int holdTime){
    // Press the "h" key
    ip.ki.wVk = 0x48; // virtual-key code for the "h" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "h" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::i(int holdTime){
    // Press the "i" key
    ip.ki.wVk = 0x49; // virtual-key code for the "i" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "i" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::j(int holdTime){
    // Press the "j" key
    ip.ki.wVk = 0x4A; // virtual-key code for the "j" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "j" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::k(int holdTime){
    // Press the "k" key
    ip.ki.wVk = 0x4B; // virtual-key code for the "k" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "k" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::l(int holdTime){
    // Press the "l" key
    ip.ki.wVk = 0x4C; // virtual-key code for the "l" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "l" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::m(int holdTime){
    // Press the "m" key
    ip.ki.wVk = 0x4D; // virtual-key code for the "m" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "m" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::n(int holdTime){
    // Press the "n" key
    ip.ki.wVk = 0x4E; // virtual-key code for the "n" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "n" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::o(int holdTime){
    // Press the "o" key
    ip.ki.wVk = 0x4F; // virtual-key code for the "o" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "o" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::p(int holdTime){
    // Press the "p" key
    ip.ki.wVk = 0x50; // virtual-key code for the "p" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "p" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::q(int holdTime){
    // Press the "q" key
    ip.ki.wVk = 0x51; // virtual-key code for the "q" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "q" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::r(int holdTime){
    // Press the "r" key
    ip.ki.wVk = 0x52; // virtual-key code for the "r" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "r" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::s(int holdTime){
    // Press the "s" key
    ip.ki.wVk = 0x53; // virtual-key code for the "s" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "s" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::t(int holdTime){
    // Press the "t" key
    ip.ki.wVk = 0x54; // virtual-key code for the "t" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "t" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::u(int holdTime){
    // Press the "u" key
    ip.ki.wVk = 0x55; // virtual-key code for the "u" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "u" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::v(int holdTime){
    // Press the "v" key
    ip.ki.wVk = 0x56; // virtual-key code for the "v" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "v" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::w(int holdTime){
    // Press the "w" key
    ip.ki.wVk = 0x57; // virtual-key code for the "w" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "w" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::x(int holdTime){
    // Press the "x" key
    ip.ki.wVk = 0x58; // virtual-key code for the "x" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "x" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::y(int holdTime){
    // Press the "y" key
    ip.ki.wVk = 0x59; // virtual-key code for the "y" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "y" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::z(int holdTime){
    // Press the "z" key
    ip.ki.wVk = 0x5A; // virtual-key code for the "z" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	
	sleep(holdTime);

    // Release the "z" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

//In dev.
void WinKeys::alt0248(){
    // Press the "alt" key
    ip.ki.wVk = VK_LMENU; // virtual-key code for the "alt" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    zero();
    two();
    four();
    eight();

    // Release the "alt" key
    ip.ki.wVk = VK_MENU; // virtual-key code for the "alt" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

//In dev.
void WinKeys::alt136(){
    // Press the "alt" key
    ip.ki.wVk = VK_MENU; // virtual-key code for the "alt" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    one();
    three();
    six();

    // Release the "alt" key
    ip.ki.wVk = VK_MENU;
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}


//Simulates a key press.
void WinKeys::press(string character, int holdTime){
    if(character == "1"){
        one(holdTime);
    } else if(character == "2"){
        two(holdTime);
    } else if(character == "3"){
        three(holdTime);
    } else if(character == "4"){
        four(holdTime);
    } else if(character == "5"){
        five(holdTime);
    } else if(character == "6"){
        six(holdTime);
    } else if(character == "7"){
        seven(holdTime);
    } else if(character == "8"){
        eight(holdTime);
    } else if(character == "9"){
        nine(holdTime);
    } else if(character == "0"){
        zero(holdTime);
    } else if(character == "a"){
        a(holdTime);
    } else if(character == "b"){
        b(holdTime);
    } else if(character == "c"){
        c(holdTime);
    } else if(character == "d"){
        d(holdTime);
    } else if(character == "e"){
        e(holdTime);
    } else if(character == "f"){
        f(holdTime);
    } else if(character == "g"){
        g(holdTime);
    } else if(character == "h"){
        h(holdTime);
    } else if(character == "i"){
        i(holdTime);
    } else if(character == "j"){
        j(holdTime);
    } else if(character == "k"){
        k(holdTime);
    } else if(character == "l"){
        l(holdTime);
    } else if(character == "m"){
        m(holdTime);
    } else if(character == "n"){
        n(holdTime);
    } else if(character == "o"){
        o(holdTime);
    } else if(character == "p"){
        p(holdTime);
    } else if(character == "q"){
        q(holdTime);
    } else if(character == "r"){
        r(holdTime);
    } else if(character == "s"){
        s(holdTime);
    } else if(character == "t"){
        t(holdTime);
    } else if(character == "u"){
        u(holdTime);
    } else if(character == "v"){
        v(holdTime);
    } else if(character == "w"){
        w(holdTime);
    } else if(character == "x"){
        x(holdTime);
    } else if(character == "y"){
        y(holdTime);
    } else if(character == "z"){
        z(holdTime);
    } else if(character == " "){
        space();
    } else if(character == "-"){
        dash();
    }  else if(character == "="){
        equal();
    } else if(character == "L"){
        leftclick();
    } else if(character == "R"){
        rightclick();
    } else if (character == "\\"){
		backslash();
	} else if (character == "/"){
		slash();
	} else if (character == "E"){
		enter();
	} else if (character == "T"){
		tab();
	} else if (character == "N"){
		numlock();
	} else{
		prog.returnError(31424, character);
	}
}

//Simulates key presses for a word.
void WinKeys::type(string word){
    int size = word.size();
    for(int i=0;i<size;i++){
        string letter(1,  word[i]);
        press(letter);
		defaultSleep();
    }
}

void WinKeys::paste(){
    // Press the "ctrl" key
    ip.ki.wVk = VK_CONTROL; // virtual-key code for the "ctrl" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    v();

    // Release the "ctrl" key
    ip.ki.wVk = VK_CONTROL; // virtual-key code for the "ctrl" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::leftclick(){
	INPUT    Input={0};
	// left down
	Input.type      = INPUT_MOUSE;
	Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
	SendInput(1,&Input,sizeof(INPUT));

	if(prog.getVerboseMode())
		cout << "LEFT CLICK" << endl;

	// left up
	ZeroMemory(&Input,sizeof(INPUT));
	Input.type      = INPUT_MOUSE;
	Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
	SendInput(1,&Input,sizeof(INPUT));
	std::this_thread::sleep_for(std::chrono::milliseconds(2*globalSleep));
}

void WinKeys::numlock(){
    // Press the "y" key
    ip.ki.wVk = 0x90; // virtual-key code for the "y" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "y" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

void WinKeys::rightclick(){
	INPUT    Input={0};
	// right down
	Input.type      = INPUT_MOUSE;
	Input.mi.dwFlags  = MOUSEEVENTF_RIGHTDOWN;
	SendInput(1,&Input,sizeof(INPUT));

	if(prog.getVerboseMode())
		cout << "RIGHT CLICK" << endl;
	
	// right up
	ZeroMemory(&Input,sizeof(INPUT));
	Input.type      = INPUT_MOUSE;
	Input.mi.dwFlags  = MOUSEEVENTF_RIGHTUP;
	SendInput(1,&Input,sizeof(INPUT));
	std::this_thread::sleep_for(std::chrono::milliseconds(2*globalSleep));
}

//Spams a button a specific number of times.
void WinKeys::buttonSpam(string button, int amount, int pause){
	std::this_thread::sleep_for(std::chrono::milliseconds(5000)); //Waits 5 seconds before beginning.
	
	for (int i=0;i<amount;i++){
		type(button);
		std::this_thread::sleep_for(std::chrono::milliseconds(pause));
	}
}

//Spams a button a specific number of times.
void WinKeys::buttonSpamTab(string button, int amount, int pause){
	std::this_thread::sleep_for(std::chrono::milliseconds(5000)); //Waits 5 seconds before beginning.
	
	for (int i=0;i<amount;i++){
		type(button);
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		tab();
		std::this_thread::sleep_for(std::chrono::milliseconds(pause));
	}
}

//performs a sequence to perpetually dig as you would in minecraft.
void WinKeys::minecraftDig(int time){
	std::this_thread::sleep_for(std::chrono::milliseconds(5000)); //Waits 5 seconds before beginning.
	
    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    ip.ki.wVk = 0x57; // virtual-key code for the "w" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    INPUT ip2={0};
    ip2.type = INPUT_MOUSE;
    ip2.mi.dwFlags = MOUSEEVENTF_LEFTDOWN; // left down
    SendInput(1,&ip2,sizeof(INPUT));
	
    std::this_thread::sleep_for(std::chrono::milliseconds(time*1000));
    
	// left up
    ZeroMemory(&ip2,sizeof(INPUT));
    ip2.type = INPUT_MOUSE;
    ip2.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1,&ip2,sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
	
    // Release the "w" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
}

// Press the "ENTER" key
void WinKeys::enter(){
	// Press the "ENTER" key
    ip.ki.wVk = 0x0D; // virtual-key code for the "ENTER" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "ENTER" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

// Press the "\" key
void WinKeys::backslash(){
	// Press the "\" key
    ip.ki.wVk = 0xE2; // virtual-key code for the "\" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "/" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

// Press the "/" key
void WinKeys::slash(){
	// Press the "/" key
    ip.ki.wVk = 0x6F; // virtual-key code for the "/" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "/" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    defaultSleep();
}

//Used for duplicating a letter in WoW. Useful for creating RP events.
void WinKeys::duplicateLetter(int copies, string recipient){
	Program progz;
	int x = prog.getWoWMailboxSendLetterLocation('x');
	int y = prog.getWoWMailboxSendLetterLocation('y');
	
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    for(int i=0;i<copies;i++){
        type(recipient);
        Sleep(200);
        tab();
        Sleep(200);
        type("subject");
        Sleep(200);
        tab();
        Sleep(200);
        paste();
        Sleep(400);
        SetCursorPos(x, y);
        Sleep(300);
        leftclick();
        Sleep(2500);
    }
}

//Used for unloading letters from the mailbox in WoW. Useful for creating RP events.
//Coordinates may need adapted based on screen resolutions, UI scales, etc..
void WinKeys::unloadLetters(int copies){
	int x0 = prog.getWoWMailboxFirstLetterLocation('x');
	int y0 = prog.getWoWMailboxFirstLetterLocation('y');
	int x1 = prog.getWoWMailboxLootLetterLocation('x');
	int y1 = prog.getWoWMailboxLootLetterLocation('y');
	int x2 = prog.getWoWMailboxDeleteLetterLocation('x');
	int y2 = prog.getWoWMailboxDeleteLetterLocation('y');
	
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    for(int i=0;i<copies;i++){
        SetCursorPos(x0, y0);
        Sleep(300);
        leftclick();
        Sleep(300);
        SetCursorPos(x1, y1);
        Sleep(300);
        leftclick();
        Sleep(300);
        SetCursorPos(x2, y2);
        Sleep(300);
        leftclick();
        Sleep(300);
    }
}

//Prints the current location of the mouse curser after some wait time.
void WinKeys::findMouseCoords(int wait){
	
	POINT cursor;
	
	sleep(wait);
	GetCursorPos(&cursor);
	
	prog.blankDots();
	int x = cursor.x, y = cursor.y;
	cout << "The mouse curse is at: " << x << ", " << y << endl;
	prog.blankDots();
}

//Prints the pixel color at a scan of ranges in a 100 x 100 grid from the mouse location.
void WinKeys::getPixelColor(){
	POINT cursor;
	GetCursorPos(&cursor);
	
	HDC dc = GetDC(NULL);
	COLORREF color;
	int red=0,green=0,blue=0;

	cout << "...Scanning." << endl;
	
	for (int i=cursor.x;i<cursor.x+100;i+=4){
		for (int j=cursor.y+2;j<cursor.y+100;j+=4){			
			color = GetPixel(dc, i, j);
			
			red = GetRValue(color);
			green = GetGValue(color);
			blue = GetBValue(color);
			
			cout << "(x,y): " << "(" << i << "," << j << ")" << endl;
			cout << "Red: " << red << "  --  " << "Green: " << green << "  --  " << "Blue: " << blue << endl;
		}
	}
	ReleaseDC(NULL,dc);
	
	cout << "...Finished." << endl;
}

//Prints the pixel color at the cursor location.
void WinKeys::getPixelColorAtMouse(){
	POINT cursor;
	GetCursorPos(&cursor);
	
	HDC dc = GetDC(NULL);

	cout << "...Scanning." << endl;
		
	COLORREF color = GetPixel(dc, cursor.x, cursor.y);
	
	int red = GetRValue(color);
	int green = GetGValue(color);
	int blue = GetBValue(color);
	
	cout << "(x,y): " << "(" << cursor.x << "," << cursor.y << ")" << endl;
	cout << "Red: " << red << "  --  " << "Green: " << green << "  --  " << "Blue: " << blue << endl;

	ReleaseDC(NULL,dc);
	
	cout << "...Finished." << endl;
}

void WinKeys::moveMouseTo(int x, int y){
	SetCursorPos(x,y);
	sleep(40);
}

//A fish bot made for WoW -- Not yet polished.
void WinKeys::WoWFishBot(string fishButton, string lureButton){
	int drama = 400;
	//Some gibberish for dramatic effect.
	//Also serves as a brief load time before bot starts.
	cout << "...Loading Fishbot Modules." << endl;
	sleep(drama);
	cout << "...Calculating response functions." << endl;
	sleep(drama);
	cout << "...Detecting saved crypto-keys." << endl;
	sleep(2*drama);
	cout << "...Saved keys found!" << endl;
	cout << "...Decrypting password hash values." << endl;
	sleep(drama);
	cout << "...Success!." << endl;
	cout << "...Sending security information to host." << endl;
	sleep(2*drama);
	cout << "...Success!." << endl;
	cout << "...Disabling daemon ninja process." << endl;
	sleep(drama);
	prog.blankDots();
	cout << "...Number of casts set to: " << prog.getWoWFishBotSpace("casts") << endl;
	sleep(drama);
	cout << "...Starting fishbot!" << endl;
	sleep(drama);
	prog.blankDots();
	
	//Begin useful variable initialization.
	HDC dc = GetDC(NULL);
	COLORREF color;
	int counter = 0;
	int red=1,green=1,blue=1;
	int increment = prog.getWoWFishBotSpace("increment");
	if(prog.getVerboseMode())
		cout << "increment: " << increment << endl;
	int startX = prog.getWoWFishBotSpace("startX") + increment/2, startY = prog.getWoWFishBotSpace("startY");
	if(prog.getVerboseMode()){
		cout << "startX: " << startX << endl;
		cout << "startY: " << startY << endl;
	}
	int endX = prog.getWoWFishBotSpace("endX"), endY = prog.getWoWFishBotSpace("endY");
	if(prog.getVerboseMode()){
		cout << "endX: " << endX << endl;
		cout << "endY: " << endY << endl;
	}
	bool bobberFound = false;
	bool useLure = true;
	int catchDelay = prog.getWoWFishBotSpace("delay");
	if(prog.getVerboseMode())
		cout << "catchDelay: " << catchDelay << endl;
	
	//Determines whether a lure is being used based on input.
	if (lureButton == "NONE" || lureButton == "None" || lureButton == "none"){
		useLure = false;
	}
	
	//Creates a clock for timing how long the bot has ran for.
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point end;
	long elapsed_time = 0;
	
	//Run the fishbot for some number of casts - determined by the config file variable WoWFishBotNumOfCasts.
	while(counter < prog.getWoWFishBotSpace("casts")){
		
		//Applies lure.
		if (useLure && counter % 100 == 0){
			cout << "...Applying lure." << endl;
			press(lureButton);
			sleep(3000);
		}
		
		//Casts.
		cout << "...Casting." << endl;
		press(fishButton);
		cout << "...Scanning." << endl;
		
		//Finds bobber.
		for (int j=startY;j<endY;j+=increment){	
			for (int i=startX;i<endX;i+=increment){	
				SetCursorPos(i,j);
				sleep(40);
				color = GetPixel(dc, i, j);
				//color = GetPixel(dc, cursor.x, cursor.y);
				
				red = GetRValue(color);
				green = GetGValue(color);
				blue = GetBValue(color);

				//Troubleshooting printouts for color of pixels detected.
				//cout << "(x,y): " << "(" << i << "," << j << ")" << endl;
				//cout << "Red: " << red << "  --  " << "Green: " << green << "  --  " << "Blue: " << blue << endl;
				
				if(red > green + 15 || red > blue + 15){
					cout << "...The bobber has been found!! ...I think." << endl;
					bobberFound=true;
					break;
				}
			}
			if(bobberFound){
				break;
			}
		}
		if(!bobberFound){
			end = std::chrono::steady_clock::now();
			cout << "...I was unable to find the bobber!" << endl;
			cout << "...To make it look like we're not cheating of course." << endl;
		}
		
		//Waits a delay time and then clocks the bobber if it was found.
		if(bobberFound){
			sleep(catchDelay);
			leftclick();
		}
		sleep(1000);
		
		//Determines elapsed time and progress information.
		end = std::chrono::steady_clock::now();
		elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
		counter++;
		bobberFound = false;
		cout << "...Elapsed time: " << elapsed_time << " milliseconds." << endl;
		cout << "...Number of casts: " << counter << endl;
		elapsed_time = 0;
	}

	ReleaseDC(NULL,dc);
}

