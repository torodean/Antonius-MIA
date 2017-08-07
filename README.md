 
|||      |||  ||||||||||      ||||     TM
||||    ||||      ||         ||  ||
|| ||  || ||      ||        ||||||||
||  ||||  ||      ||       ||      ||
||   ||   ||  ||||||||||  ||        ||


MIA (Multiple Integrated Applications) is a program where I can store 
useful coding functions I've created in one place for easy accessibility.

For a list of commands see the MIA manual.


 ~~~~~~~~~~~~ Compiling Instructions with Cygwin on Linux ~~~~~~~~~~~~

1) via terminal:  cd ../Antonius-MIA/bin

**NOTE** There are currently some features of MIA that work on Windows ONLY. Therefore these will have to be commented out to compile on linux.

2) compile using 
g++ -Wall -std=c++14 MIAmain.cpp MIAprogram.cpp MIAcommands.cpp D3CEncrypt.cpp D3CEncryptPW.cpp D3CMath.cpp MIAEncrypt.cpp -o MIA

2.5) In some situations the above command may throw exceptions depending on the GCC std versions and locations that exist. You can remedy this by changing the -std=c++14 version to a prior version, perhaps -std=c++1y.

3) Run using ./MIA


 ~~~~~~~~~~~~ Compiling Instructions with Cygwin on Windows ~~~~~~~~~~~~

1) Install Cygwin using the tutorial here: 
http://preshing.com/20141108/how-to-install-the-latest-gcc-on-windows/

2) Place the MIA directory in Cygwin64/home/username/Antonius-MIA

3) cd ../Antonius-MIA/bin

4) compile an exe using 
g++ -Wall -std=c++14 MIAmain.cpp MIAprogram.cpp MIAcommands.cpp D3CEncrypt.cpp D3CEncryptPW.cpp D3CMath.cpp MIAEncrypt.cpp WinKeys.cpp -o MIA

5) run using ./MIA.exe while in the bin directory.

6) git works from within the Cygwin terminal so once you are in the 
/Antonius-MIA directory all of the same git functions can be used.

7) To see what dll's are required by the program for making it portable,
execute objdump -p hello.exe | grep "DLL Name" while in the 
../Antonius-MIA/bin and then copy those dll's to the folder with the .exe

8) With the correct cygwin dll's in the exe folder, the program can be ran as standalone.

 ~~~~~~~~~~~~ Compiling Instructions with Cygwin on Mac OS ~~~~~~~~~~~~

1) Install Linux

2) See instructions for Linux.
