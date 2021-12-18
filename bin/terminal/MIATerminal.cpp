/**
 * File: MIATerminal.cpp
 * Author: Antonius Torode
 * Creation Date: 03/01/2021
 * Description:A class for terminal specific features.
 */

#include "MIATerminal.hpp"
#include "TerminalTools.hpp"
#include "StringUtils.hpp"
#include "MathUtils.hpp"
#include "FileUtils.hpp"
#include "Error.hpp"

#include <iostream>
#include <utility>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined _WIN32 || defined _WIN64 || defined __CYGWIN__
#include "windows/WindowsUtilities.hpp"
#endif

using std::string;
using std::remove;
using std::stoi;
using std::ifstream;
using std::vector;
using std::cout;
using std::endl;
using std::getline;
using std::cin;
using std::tolower;
using std::to_string;

MIATerminal::MIATerminal(std::string terminalName) : SubProgram(std::move(terminalName))
{

}

void MIATerminal::printSplash()
{
    cout << "     ...................................................................." << endl;
    cout << "    ... //  ~~      |||      |||  ||||||||||      ||||     TM   ~~  \\\\ ..." << endl;
    cout << "   ... //  ~~       ||||    ||||      ||         ||  ||          ~~  \\\\ ..." << endl;
    cout << "  ... //  ~~        || ||  || ||      ||        ||||||||          ~~  \\\\ ..." << endl;
    cout << " ... //  ~~         ||  ||||  ||      ||       ||      ||          ~~  \\\\ ..." << endl;
    cout << "... //  ~~          ||   ||   ||  ||||||||||  ||        ||          ~~  \\\\ ..." << endl;
    cout << ".............................................................................." << endl;
    cout << "............................. TERMINAL INTERFACE ............................." << endl;
    cout << "............. Multiple Integrated Applications -- Version: " + config.getMIAVersion() + " ............." << endl;
    cout << "....................     Programmer: Antonius Torode      ...................." << endl;
    cout << "....................      Compiled on: " << __DATE__ << "        ...................." << endl;
    cout << ".............................................................................." << endl;
}

void MIATerminal::intro()
{
    MIATerminalTools::blankDots();
    cout << "... Greetings! I am MIA.                                                   ..." << endl;
}

void MIATerminal::standby(string defaultCommand){
    string input;

    if(!defaultCommand.empty()){
        cout << "... I've detected a default command entered: " << defaultCommand << endl;
        MIATerminalTools::blankLine();
        performMIACommand(defaultCommand);
        MIATerminalTools::blankLine();
    }

    helpMessage();
    while(true){
        getline(cin,input);
        MIATerminalTools::blankLine();
        if(StringUtils::toLower(input) == "exit" || StringUtils::toLower(input) == "quit")
        {
            break;
        }
        else
        {
            performMIACommand(input);
        }
        helpMessage();
    }
}

void MIATerminal::helpMessage()
{
    MIATerminalTools::blankDots();
    cout << "... You can type 'help' for a list of valid commands.                      ..." << endl;
    cout << "... Please enter a command.                                                ..." << endl;
    MIATerminalTools::blankDots();
    MIATerminalTools::blankLine();
}

bool MIATerminal::useExcuse()
{
    int random = MathUtils::randomInt(1,100, 0, true);
    string txt;

    if (random >= 20){
        MIATerminalTools::blankLine();
        cout << "...Sorry, I can't do that (Invalid command entered). " << endl;

        txt = FileUtils::getRandomLineOfFile(config.programFilePaths.excuseFilePath);
        cout << "..." << txt << endl;
        return true;
    }
    return false;
}


void MIATerminal::run(const string& defaultCommand)
{
    printSplash();
    intro();
    standby(defaultCommand);
}

void MIATerminal::printHelp()
{
    cout << "... A list of valid commands and a brief summary.                          ..." << endl;
    cout << "... Commands are NOT case sensitive.                                       ..." << endl;
    MIATerminalTools::blankDots();
    cout << "... help          | Displays a valid lists of commands." << endl;
    cout << "... add           | Adds two positive integers of any length. " << endl;
    cout << "... alarm -r      | Triggers a repeating alarm after the desired ms." << endl;
    cout << "... collatz       | Produces a collatz sequence based on a starting integer." << endl;
    cout << "... config        | Reloads the MIAConfig.txt file and prints the variables." << endl;
    cout << "... crypt -d0s1   | Encrypts a string using the d0s1 algorithm." << endl;
    cout << "... crypt -d0s2   | Encrypts a string using the d0s2 algorithm." << endl;
    cout << "... decrypt -d0s1 | De-crypts a string using the d0s1 algorithm." << endl;
    cout << "... decrypt -d0s2 | De-crypts a string using the d0s2 algorithm." << endl;
    cout << "... digitsum      | Returns the sum of the digits within an integer of any size." << endl;
    cout << "... error info    | Returns information regarding an error code." << endl;
    cout << "... error info -a | Returns information regarding all error codes." << endl;
    cout << "... factors       | Returns the number of factors within an integer." << endl;
    cout << "... lattice       | Returns lattice paths to the farthest corner of an NxM grid." << endl;
    cout << "... multiply      | Multiplies two integers of any length." << endl;
    cout << "... palindrome    | Determines if a positive integer is palindrome." << endl;
    cout << "... prime -help   | Displays help defaults for prime functions." << endl;
    cout << "... quadratic form| Calculates a solution to a*x^2+b*x+c=0." << endl;
    cout << "... randfromfile  | Prints a number of random lines from a text file." << endl;
    cout << "... subtract      | Finds the difference between two integers of any length." << endl;
    cout << "... triangle      | Determines if a number is a triangle number or not." << endl;
    cout << "... workout       | Generates a workout from the values defined in workouts.txt." << endl;
    cout << "... workout -w    | Generates a weekly workout and outputs it to a file." << endl;
    cout << "... exit          | Quits MIA. " << endl;
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined _WIN32 || defined _WIN64 || defined __CYGWIN__
    cout << "... button spam   | Spams a specified button (key press)." << endl;
    cout << "... button spam -t| Spams a specified button (key press) separated by tabs." << endl;
    cout << "... eyedropper    | Returns the RGB value of the pixel located at the cursor." << endl;
    cout << "... find mouse    | Finds/Returns the coordinates of the mouse after 5 seconds." << endl;
    cout << "... fishbot       | A working and configurable WoW fishbot." << endl;
    cout << "... mc dig        | Simulates key strokes for continuous Minecraft digging." << endl;
    cout << "... mc explore    | Explores a Minecraft map using the minecraft /tp command." << endl;
    cout << "... net -help     | Displays net functions available within MIA." << endl;
    cout << "... sequencer     | Runs a sequence from the sequences file." << endl;
    cout << "... sequencer -l  | Loops a sequence from the sequences file." << endl;
    cout << "... wow dup letter| Duplicates a letter in WoW a specified number of times." << endl;
    cout << "... wow unload    | Unloads a number of letters from the WoW inbox." << endl;
#endif
}

void MIATerminal::helpPrime()
{
    cout << "... A list of various valid commands and a brief summary.                  ..." << endl;
    cout << "... Commands are NOT case sensitive.                                       ..." << endl;
    MIATerminalTools::blankDots();
    cout << "... prime         | Determines if a positive integer is prime or not." << endl;
    cout << "... prime -f      | Determines all of the prime factors of a positive integer." << endl;
    cout << "... prime -n      | Calculates the n'th prime number up to a max of 2147483647." << endl;
    cout << "... prime -n -p   | Creates a file of prime #'s up to a max of 2147483647." << endl;
    cout << "... prime -n -c   | Clears the file created by 'prime -n -p'." << endl;
}

void MIATerminal::helpNet()
{
    cout << "... A list of various valid commands and a brief summary.                  ..." << endl;
    cout << "... Commands are NOT case sensitive.                                       ..." << endl;
    MIATerminalTools::blankDots();
    cout << "... net session   | Provides info about sessions established on a server." << endl;
    cout << "... net server -s | Lists all servers that are visible in a domain." << endl;
    cout << "... net server -w | Lists all workstations that are visible in a domain." << endl;
    //cout << "... net wkst      | Returns info about the configuration of a workstation." << endl;
    //cout << "... net remote    | Retrieves the optional features a remote system supports." << endl;
    //cout << "... net user      | Retrieves information about all user accounts on a server." << endl;
    //cout << "... net user -i   | Retrieves information about a user account on a server." << endl;
    //cout << "... net modals    | Retrieves global information for all users and global groups." << endl;
    //cout << "... net display   | Returns computer, or group account information." << endl;
}


void MIATerminal::performMIACommand(string& input)
{
    std::string cmdInput = StringUtils::toLower(input);
    Commands::MIAInput in = Commands::commandToInputEnum(cmdInput);

    switch( in ){
        case Commands::MIAInput::HELP:
            printHelp();
            break;
        case Commands::MIAInput::TEST:
            runTest();
            break;
        case Commands::MIAInput::CRYPT_D0S1:
            d0s1.d0s1CryptRunner();
            break;
        case Commands::MIAInput::DECRYPT_D0S1:
            d0s1.d0s1DeCryptRunner();
            break;
        case Commands::MIAInput::CRYPT_D0S2:
            d0s2.d0s2CryptRunner();
            break;
        case Commands::MIAInput::DECRYPT_D0S2:
            d0s2.d0s2DeCryptRunner();
            break;
        case Commands::MIAInput::COLLATZ:
            cmd.collatzRunner();
            break;
        case Commands::MIAInput::ADD:
            cmd.stringAdditionRunner();
            break;
        case Commands::MIAInput::MULTIPLY:
            cmd.stringMultiplyRunner();
            break;
        case Commands::MIAInput::SUBTRACT:
            cmd.stringSubtractionRunner();
            break;
        case Commands::MIAInput::PRIME:
            cmd.isPrimeRunner();
            break;
        case Commands::MIAInput::PALINDROME:
            cmd.isPalindromeRunner();
            break;
        case Commands::MIAInput::DIGITSUM:
            cmd.sumOfDigitsRunner();
            break;
        case Commands::MIAInput::PRIME_F:
            cmd.primeFactorsRunner();
            break;
        case Commands::MIAInput::FACTORS:
            cmd.numberOfFactorsRunner();
            break;
        case Commands::MIAInput::TRIANGLE:
            cmd.isTriangleNumberRunner();
            break;
        case Commands::MIAInput::LATTICE:
            cmd.latticePathsRunner();
            break;
        case Commands::MIAInput::PRIME_N:
            cmd.primeNRunner();
            break;
        case Commands::MIAInput::PRIME_N_P:
            cmd.primeNumberNpopulateRunner();
            break;
        case Commands::MIAInput::PRIME_N_C:
            cmd.primeNumberNeraseRunner();
            break;
        case Commands::MIAInput::MCDIG:
            cmd.minecraftDigRunner();
            break;
        case Commands::MIAInput::BUTTONSPAM:
            cmd.buttonSpamRunner(false);
            break;
        case Commands::MIAInput::MCEXPLORE:
            cmd.exploreMinecraft();
            break;
        case Commands::MIAInput::PRIME_HELP:
            helpPrime();
            break;
        case Commands::MIAInput::CRYPT_D0S3:
            cmd.d0s3CryptRunner();
            break;
        case Commands::MIAInput::DECRYPT_D0S3:
            cmd.d0s3DeCryptRunner();
            break;
        case Commands::MIAInput::BUTTONSPAM_T:
            cmd.buttonSpamRunner(true);
            break;
        case Commands::MIAInput::RANDFROMFILE:
            cmd.printRandomLinesFromFileRunner();
            break;
        case Commands::MIAInput::WOWDUPLETTER:
            cmd.duplicateLetterRunner();
            break;
        case Commands::MIAInput::QUADRATICFORM:
            cmd.solveQuadraticFormulaRunner();
            break;
        case Commands::MIAInput::PRANJAL:
            cmd.pranjal();
            break;
        case Commands::MIAInput::FINDMOUSE:
            cmd.findMouse();
            break;
        case Commands::MIAInput::EYEDROPPER:
            cmd.eyedropper();
            break;
        case Commands::MIAInput::CONFIG:
            config.initializeSettings(true);
            break;
        case Commands::MIAInput::FISHBOT:
            cmd.runFishbot();
            break;
        case Commands::MIAInput::WORKOUT:
            cmd.workoutRunner(false);
            break;
        case Commands::MIAInput::SPLASH:
            printSplash();
            break;
        case Commands::MIAInput::WORKOUT_W:
            cmd.workoutRunner(true);
            break;
        case Commands::MIAInput::NETHELP:
            helpNet();
            break;
        case Commands::MIAInput::NETSESSION:
            cmd.runNetSessionEnum();
            break;
        case Commands::MIAInput::NETSERVER_W:
            cmd.runNetServerEnum('w');
            break;
        case Commands::MIAInput::NETSERVER_S:
            cmd.runNetServerEnum('s');
            break;
        case Commands::MIAInput::WOWUNLOAD:
            cmd.unloadLetterRunner();
            break;
        case Commands::MIAInput::DATE:
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined _WIN32 || defined _WIN64 || defined __CYGWIN__
            WindowsUtilities::terminalCommand("DATE");
#else
            Error::returnError(Error::ErrorCode::Windows_Only_Feature);
#endif
            break;
        case Commands::MIAInput::DICEROLL:
            Commands::rollDice(input);
            break;
        case Commands::MIAInput::SEQUENCER:
            Commands::runSequencer();
            break;
        case Commands::MIAInput::SEQUENCER_L:
            Commands::loopSequencer();
            break;
        case Commands::MIAInput::ALARM_R:
            Commands::runRepeatingAlarm();
            break;
        case Commands::MIAInput::ERRORINFO:
            Error::errorInfoRun(false);
            break;
        case Commands::MIAInput::ERRORINFO_A:
            Error::errorInfoRun(true);
            break;


        case Commands::MIAInput::EXCUSE:
        default: //defaults to an unrecognized command.
            if(!useExcuse())
                cout << "... Invalid Command Entered.                                               ..." << endl;
            break;
    }
}





void MIATerminal::runTest(){
    cout << "...Starting test." << endl;

    Commands::runTest();

    cout << "...Finished test." << endl;
}


int main()
{
    MIATerminal terminal("MIA Terminal");
    terminal.run("");
    return 0;
}

