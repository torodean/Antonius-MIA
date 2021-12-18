 
|||      |||  ||||||||||      ||||     TM
||||    ||||      ||         ||  ||
|| ||  || ||      ||        ||||||||
||  ||||  ||      ||       ||      ||
||   ||   ||  ||||||||||  ||        ||


MIA (Multiple Integrated Applications) is a program where I can store useful coding functions and apps I've created in one place for easy accessibility.

For a list of commands and features see the MIA manual.


 ~~~~~~~~~~~~ Compiling Instructions on Linux ~~~~~~~~~~~~

1) via terminal:  ./build.sh

3) Run using 
	
	./build/MIA
	./build/terminal/MIATerminal


 ~~~~~~~~~~~~ Compiling Instructions with Cygwin on Windows ~~~~~~~~~~~~

1) Install dependencies

	- Install git: https://git-scm.com/book/en/v2/Getting-Started-Installing-Git
	- Clone MIA code: git clone https://github.com/torodean/Antonius-MIA.git
	- Install Cygwin using the tutorial here: http://preshing.com/20141108/how-to-install-the-latest-gcc-on-windows/
	- Install CMake 17 or later

3) via cygwin terminal, build the code:  
	
	cd path/to/Antonius-MIA/
	./build.sh

5) update the release files within the MIA directory

	cd path/to/Antonius-MIA/
	./updateRelease.sh

6) Navigate to the release folder and run the MIA program(s).
	
	cd path/to/Antonius-MIA/release
	./MIA
	./MIATerminal

Potentially useful notes from old install instructions:

To see what dll's are required by the program for making it portable, execute objdump -p MIA.exe | grep "DLL Name" while in the 
	
	../Antonius-MIA/bin and then copy those dll's to the folder with the .exe

With the correct cygwin dll's in the exe folder, the program can be ran as standalone by clicking the executable file.

 ~~~~~~~~~~~~ Compiling Instructions on Mac OS ~~~~~~~~~~~~

1) See instructions for Linux. 
2) Figure rest out.