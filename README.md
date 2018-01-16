 
|||      |||  ||||||||||      ||||     TM
||||    ||||      ||         ||  ||
|| ||  || ||      ||        ||||||||
||  ||||  ||      ||       ||      ||
||   ||   ||  ||||||||||  ||        ||


MIA (Multiple Integrated Applications) is a program where I can store useful coding functions I've created in one place for easy accessibility.

For a list of commands see the MIA manual.


 ~~~~~~~~~~~~ Compiling Instructions on Linux ~~~~~~~~~~~~

1) via terminal:  cd ../Antonius-MIA/bin

2) compile using 

make clean && make

3) Run using 
	
	./MIA


 ~~~~~~~~~~~~ Compiling Instructions with Cygwin on Windows ~~~~~~~~~~~~

1) Install Cygwin using the tutorial here: 
http://preshing.com/20141108/how-to-install-the-latest-gcc-on-windows/

2) Place the MIA directory in 
	
	Cygwin64/home/username/Antonius-MIA

3) via cygwin terminal:  cd ../Antonius-MIA/bin

4) compile an exe using 

	make clean && make

5) run using ./MIA.exe while in the bin directory.

6) git works from within the Cygwin terminal so once you are in the 
	
	/Antonius-MIA directory all of the same git functions can be used.

7) To see what dll's are required by the program for making it portable, execute objdump -p MIA.exe | grep "DLL Name" while in the 
	
	../Antonius-MIA/bin and then copy those dll's to the folder with the .exe

8) With the correct cygwin dll's in the exe folder, the program can be ran as standalone by clicking the executable file.

 ~~~~~~~~~~~~ Compiling Instructions on Mac OS ~~~~~~~~~~~~

1) Install Linux (I don't own a mac to test this on)

2) See instructions for Linux.

 ~~~~~~~~~~~~ Cleanup Instructions ~~~~~~~~~~~~

1) If you don't like all of the objective files (.o), you can cleanup the bin directory using

make cleanup