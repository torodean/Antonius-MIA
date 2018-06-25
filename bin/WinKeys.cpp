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
#include <windows.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include "WinKeys.h"
#include <stdio.h>

using std::cout;
using std::endl;
using std::string;

WinKeys::WinKeys(){
    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
}

WinKeys::~WinKeys(){

}

void WinKeys::space(){
    // Press the "space" key
    ip.ki.wVk = VK_SPACE; // virtual-key code for the "space" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "space" key
    ip.ki.wVk = VK_SPACE; // virtual-key code for the "space" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::one(){
    // Press the "1" key
    ip.ki.wVk = 0x31; // virtual-key code for the "1" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "1" key
    ip.ki.wVk = 0x31; // virtual-key code for the "1" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::two(){
    // Press the "2" key
    ip.ki.wVk = 0x32; // virtual-key code for the "2" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "2" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::three(){
    // Press the "3" key
    ip.ki.wVk = 0x33; // virtual-key code for the "3" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "3" key
    ip.ki.wVk = 0x33; // virtual-key code for the "3" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::four(){
    // Press the "4" key
    ip.ki.wVk = 0x34; // virtual-key code for the "4" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "4" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::five(){
    // Press the "5" key
    ip.ki.wVk = 0x35; // virtual-key code for the "5" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "5" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::six(){
    // Press the "6" key
    ip.ki.wVk = 0x36; // virtual-key code for the "6" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "6" key
    ip.ki.wVk = 0x36; // virtual-key code for the "6" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::seven(){
    // Press the "7" key
    ip.ki.wVk = 0x37; // virtual-key code for the "7" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "7" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::eight(){
    // Press the "8" key
    ip.ki.wVk = 0x38; // virtual-key code for the "8" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "8" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::nine(){
    // Press the "9" key
    ip.ki.wVk = 0x39; // virtual-key code for the "9" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "9" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::zero(){
    // Press the "0" key
    ip.ki.wVk = 0x30; // virtual-key code for the "0" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "0" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::dash(){
    // Press the "-" key
    ip.ki.wVk = VK_OEM_MINUS; // virtual-key code for the "-" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "-" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::equal(){
    // Press the "=" key
    ip.ki.wVk = VK_OEM_PLUS; // virtual-key code for the "=" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "=" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::tab(){
    // Press the "tab" key
    ip.ki.wVk = VK_TAB; // virtual-key code for the "tab" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "tab" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::a(){
    // Press the "a" key
    ip.ki.wVk = 0x41; // virtual-key code for the "a" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "a" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::b(){
    // Press the "b" key
    ip.ki.wVk = 0x42; // virtual-key code for the "b" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "b" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::c(){
    // Press the "c" key
    ip.ki.wVk = 0x43; // virtual-key code for the "c" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "c" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::d(){
    // Press the "d" key
    ip.ki.wVk = 0x44; // virtual-key code for the "d" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "d" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::e(){
    // Press the "e" key
    ip.ki.wVk = 0x45; // virtual-key code for the "e" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "e" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::f(){
    // Press the "f" key
    ip.ki.wVk = 0x46; // virtual-key code for the "f" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "f" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::g(){
    // Press the "g" key
    ip.ki.wVk = 0x47; // virtual-key code for the "g" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "g" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::h(){
    // Press the "h" key
    ip.ki.wVk = 0x48; // virtual-key code for the "h" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "h" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::i(){
    // Press the "i" key
    ip.ki.wVk = 0x49; // virtual-key code for the "i" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "i" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::j(){
    // Press the "j" key
    ip.ki.wVk = 0x4A; // virtual-key code for the "j" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "j" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::k(){
    // Press the "k" key
    ip.ki.wVk = 0x4B; // virtual-key code for the "k" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "k" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::l(){
    // Press the "l" key
    ip.ki.wVk = 0x4C; // virtual-key code for the "l" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "l" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::m(){
    // Press the "m" key
    ip.ki.wVk = 0x4D; // virtual-key code for the "m" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "m" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::n(){
    // Press the "n" key
    ip.ki.wVk = 0x4E; // virtual-key code for the "n" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "n" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::o(){
    // Press the "o" key
    ip.ki.wVk = 0x4F; // virtual-key code for the "o" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "o" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::p(){
    // Press the "p" key
    ip.ki.wVk = 0x50; // virtual-key code for the "p" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "p" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::q(){
    // Press the "q" key
    ip.ki.wVk = 0x51; // virtual-key code for the "q" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "q" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::r(){
    // Press the "r" key
    ip.ki.wVk = 0x52; // virtual-key code for the "r" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "r" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::s(){
    // Press the "s" key
    ip.ki.wVk = 0x53; // virtual-key code for the "s" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "s" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::t(){
    // Press the "t" key
    ip.ki.wVk = 0x54; // virtual-key code for the "t" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "t" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::u(){
    // Press the "u" key
    ip.ki.wVk = 0x55; // virtual-key code for the "u" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "u" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::v(){
    // Press the "v" key
    ip.ki.wVk = 0x56; // virtual-key code for the "v" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "v" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::w(){
    // Press the "w" key
    ip.ki.wVk = 0x57; // virtual-key code for the "w" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "w" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::x(){
    // Press the "x" key
    ip.ki.wVk = 0x58; // virtual-key code for the "x" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "x" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::y(){
    // Press the "y" key
    ip.ki.wVk = 0x59; // virtual-key code for the "y" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "y" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

void WinKeys::z(){
    // Press the "z" key
    ip.ki.wVk = 0x5A; // virtual-key code for the "z" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "z" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
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

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
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

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
}

//Simulates a key press.
void WinKeys::press(string character){
    if(character == "1"){
        one();
    } else if(character == "2"){
        two();
    } else if(character == "3"){
        three();
    } else if(character == "4"){
        four();
    } else if(character == "5"){
        five();
    } else if(character == "6"){
        six();
    } else if(character == "7"){
        seven();
    } else if(character == "8"){
        eight();
    } else if(character == "9"){
        nine();
    } else if(character == "0"){
        zero();
    } else if(character == "a"){
        a();
    } else if(character == "b"){
        b();
    } else if(character == "c"){
        c();
    } else if(character == "d"){
        d();
    } else if(character == "e"){
        e();
    } else if(character == "f"){
        f();
    } else if(character == "g"){
        g();
    } else if(character == "h"){
        h();
    } else if(character == "i"){
        i();
    } else if(character == "j"){
        j();
    } else if(character == "k"){
        k();
    } else if(character == "l"){
        l();
    } else if(character == "m"){
        m();
    } else if(character == "n"){
        n();
    } else if(character == "o"){
        o();
    } else if(character == "p"){
        p();
    } else if(character == "q"){
        q();
    } else if(character == "r"){
        r();
    } else if(character == "s"){
        s();
    } else if(character == "t"){
        t();
    } else if(character == "u"){
        u();
    } else if(character == "v"){
        v();
    } else if(character == "w"){
        w();
    } else if(character == "x"){
        x();
    } else if(character == "y"){
        y();
    } else if(character == "z"){
        z();
    } else if(character == " "){
        space();
    } else if(character == "-"){
        dash();
    }  else if(character == "="){
        dash();
    } else if(character == "LC"){
        leftclick();
    } else if (character == "\\"){
		backslash();
	} else if (character == "/"){
		slash();
	} else if (character == "ENTER"){
		enter();
	}
}

//Simulates key presses for a word.
void WinKeys::type(string word){
    int size = word.size();
    for(int i=0;i<size;i++){
        string letter(1,  word[i]);
        press(letter);
		std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
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

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));

}

void WinKeys::leftclick(){
  INPUT    Input={0};
  // left down
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
  SendInput(1,&Input,sizeof(INPUT));

  // left up
  ZeroMemory(&Input,sizeof(INPUT));
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
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

//Tells the program to sleep for some time in milliseconds.
void WinKeys::waitTime(int input){
	    std::this_thread::sleep_for(std::chrono::milliseconds(input));
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

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
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

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
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

    std::this_thread::sleep_for(std::chrono::milliseconds(globalSleep));
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
        Sleep(1500);
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
	
	waitTime(wait);
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

//A fish bot made for WoW -- Not yet finished.
void WinKeys::WoWFishBot(string fishButton, string lureButton){
	int drama = 400;
	//Some gibberish for dramatic effect.
	//Also serves as a brief load time before bot starts.
	cout << "...Loading Fishbot Modules." << endl;
	waitTime(drama);
	cout << "...Calculating response functions." << endl;
	waitTime(drama);
	cout << "...Detecting saved crypto-keys." << endl;
	waitTime(2*drama);
	cout << "...Saved keys found!" << endl;
	cout << "...Decrypting password hash values." << endl;
	waitTime(drama);
	cout << "...Success!." << endl;
	cout << "...Sending security information to host." << endl;
	waitTime(2*drama);
	cout << "...Success!." << endl;
	cout << "...Disabling daemon ninja process." << endl;
	waitTime(drama);
	prog.blankDots();
	cout << "...Number of casts set to: " << prog.getWoWFishBotSpace("casts") << endl;
	waitTime(drama);
	cout << "...Starting fishbot!" << endl;
	waitTime(drama);
	prog.blankDots();
	
	//Begin useful variable initialization.
	HDC dc = GetDC(NULL);
	COLORREF color;
	int counter = 0;
	int red=1,green=1,blue=1;
	int increment = prog.getWoWFishBotSpace("increment");
	int startX = prog.getWoWFishBotSpace("startX") + increment/2, startY = prog.getWoWFishBotSpace("startY");
	int endX = prog.getWoWFishBotSpace("endX"), endY = prog.getWoWFishBotSpace("endY");
	bool bobberFound = false;
	bool useLure = true;
	int catchDelay = prog.getWoWFishBotSpace("delay");
	
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
			waitTime(3000);
		}
		
		//Casts.
		cout << "...Casting." << endl;
		press(fishButton);
		cout << "...Scanning." << endl;
		
		//Finds bobber.
		for (int j=startY;j<endY;j+=increment){	
			for (int i=startX;i<endX;i+=increment){	
				SetCursorPos(i,j);
				waitTime(40);
				color = GetPixel(dc, i, j);
				//color = GetPixel(dc, cursor.x, cursor.y);
				
				red = GetRValue(color);
				green = GetGValue(color);
				blue = GetBValue(color);

				//Troubleshooting printouts for color of pixels detected.
				//cout << "(x,y): " << "(" << i << "," << j << ")" << endl;
				//cout << "Red: " << red << "  --  " << "Green: " << green << "  --  " << "Blue: " << blue << endl;
				
				if(red == 0 && green == 0 && blue == 0){
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
			waitTime(catchDelay);
			leftclick();
		}
		waitTime(1000);
		
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

