/**
 * File: VirtualKeyStrokes.hpp
 * Author: Antonius Torode
 * Date: 03/01/2021
 * Description:
 */

#ifndef MIA2_VIRTUALKEYSTROKES_HPP
#define MIA2_VIRTUALKEYSTROKES_HPP

#include <string>
#include <thread>
#include <chrono>
#include <iostream>
#include <cstdio>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <windows.h>
#elif __linux__
extern "C" {
#include <xdo.h>
}
#endif

/**
 * This class is for sending virtual key strokes and simulating user input.
 * IT is designed to replace the WinKeys.hpp code which was designed for Windows only.
 * This class is cross platform.
 */
class VirtualKeyStrokes
{
public:

    /**
     * Main default constructor for the VirtualKeyStrokes class.
     */
    VirtualKeyStrokes();

    /**
     * Main destructor for the VirtualKeyStrokes object.
     */
    ~VirtualKeyStrokes();

    /**
     * This will simulate a key press.
     * @param character[const char&] - the key to press.
     * @param holdTime [int] - A time to gold after the keypress in ms (default = 0)
     */
    void press(const char& character, int holdTime = 0);

    /**
     * This will simulate the key presses for a string.
     * @param character[const std::string&] - the string to simulate key presses for.
     */
    void type(std::string word);

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)

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
    void alt0248();
    void alt136();
    void shift(char character);
    void paste();
    void backslash();
    void slash();
    void leftclick();
    void rightclick();

    //functions relating to Minecraft.
    void minecraftDig(int time);

    //functions relating to World of Warcraft
    void duplicateLetter(int copies, string recipient);
    void unloadLetters(int copies);
    void WoWFishBot(string fishButton, string lureButton);

    //Other useful functions.
    void findMouseCoords(int waitTime);
    void getPixelColor();
    void getPixelColorAtMouse();
    void moveMouseTo(int x, int y);

#endif

    void minus();       ///< Simulates press of the minus key.
    void equal();       ///< Simulates press of the equal key.
    void space();       ///< Simulates press of the space key.
    void tab();         ///< Simulates press of the tab key.

    /// Sleeps for the default globalSleep time used by the VirtuakKeyStrokes class..
    void defaultSleep();

    /**
     * This will spam a key press a certain number of times with a pause between each press.
     * @param button[char button] - the character to press.
     * @param amount[int] - The number of times to press the key.
     * @param pause[int] - The time to pause between key presses in ms.
     */
    void buttonSpam(const std::string& button, int amount, int pause);

    /**
     * This will spam a key press a certain number of times with a pause between each press and a tab after.
     * @param button[char button] - the character to press.
     * @param amount[int] - The number of times to press the key.
     * @param pause[int] - The time to pause between key presses in ms.
     */
    void buttonSpamTab(const std::string& button, int amount, int pause);

protected:

private:

    /// Global time to sleep between each key press (in ms).
    int globalSleep = 50;

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    INPUT ip;

    void fishBotIntro();
    void getRGB(COLORREF& color, int& r, int& g, int& b);
#elif __linux__
    xdo_t *xdo;
#endif

};

#endif //MIA2_VIRTUALKEYSTROKES_HPP
