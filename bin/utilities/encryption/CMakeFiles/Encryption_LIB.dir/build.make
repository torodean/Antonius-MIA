# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cygdrive/c/Users/awtorode/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/awtorode/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/s/projects/git/Antonius-MIA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/s/projects/git/Antonius-MIA

# Include any dependencies generated for this target.
include bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/depend.make

# Include the progress variables for this target.
include bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/progress.make

# Include the compile flags for this target's objects.
include bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/flags.make

bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/D3CEncrypt.cpp.o: bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/flags.make
bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/D3CEncrypt.cpp.o: bin/utilities/encryption/D3CEncrypt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/s/projects/git/Antonius-MIA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/D3CEncrypt.cpp.o"
	cd /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Encryption_LIB.dir/D3CEncrypt.cpp.o -c /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption/D3CEncrypt.cpp

bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/D3CEncrypt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Encryption_LIB.dir/D3CEncrypt.cpp.i"
	cd /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption/D3CEncrypt.cpp > CMakeFiles/Encryption_LIB.dir/D3CEncrypt.cpp.i

bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/D3CEncrypt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Encryption_LIB.dir/D3CEncrypt.cpp.s"
	cd /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption/D3CEncrypt.cpp -o CMakeFiles/Encryption_LIB.dir/D3CEncrypt.cpp.s

bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/D3CEncryptPW.cpp.o: bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/flags.make
bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/D3CEncryptPW.cpp.o: bin/utilities/encryption/D3CEncryptPW.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/s/projects/git/Antonius-MIA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/D3CEncryptPW.cpp.o"
	cd /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Encryption_LIB.dir/D3CEncryptPW.cpp.o -c /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption/D3CEncryptPW.cpp

bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/D3CEncryptPW.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Encryption_LIB.dir/D3CEncryptPW.cpp.i"
	cd /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption/D3CEncryptPW.cpp > CMakeFiles/Encryption_LIB.dir/D3CEncryptPW.cpp.i

bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/D3CEncryptPW.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Encryption_LIB.dir/D3CEncryptPW.cpp.s"
	cd /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption/D3CEncryptPW.cpp -o CMakeFiles/Encryption_LIB.dir/D3CEncryptPW.cpp.s

bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/MIAEncrypt.cpp.o: bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/flags.make
bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/MIAEncrypt.cpp.o: bin/utilities/encryption/MIAEncrypt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/s/projects/git/Antonius-MIA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/MIAEncrypt.cpp.o"
	cd /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Encryption_LIB.dir/MIAEncrypt.cpp.o -c /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption/MIAEncrypt.cpp

bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/MIAEncrypt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Encryption_LIB.dir/MIAEncrypt.cpp.i"
	cd /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption/MIAEncrypt.cpp > CMakeFiles/Encryption_LIB.dir/MIAEncrypt.cpp.i

bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/MIAEncrypt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Encryption_LIB.dir/MIAEncrypt.cpp.s"
	cd /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption/MIAEncrypt.cpp -o CMakeFiles/Encryption_LIB.dir/MIAEncrypt.cpp.s

# Object files for target Encryption_LIB
Encryption_LIB_OBJECTS = \
"CMakeFiles/Encryption_LIB.dir/D3CEncrypt.cpp.o" \
"CMakeFiles/Encryption_LIB.dir/D3CEncryptPW.cpp.o" \
"CMakeFiles/Encryption_LIB.dir/MIAEncrypt.cpp.o"

# External object files for target Encryption_LIB
Encryption_LIB_EXTERNAL_OBJECTS =

bin/utilities/encryption/libEncryption_LIB.a: bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/D3CEncrypt.cpp.o
bin/utilities/encryption/libEncryption_LIB.a: bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/D3CEncryptPW.cpp.o
bin/utilities/encryption/libEncryption_LIB.a: bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/MIAEncrypt.cpp.o
bin/utilities/encryption/libEncryption_LIB.a: bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/build.make
bin/utilities/encryption/libEncryption_LIB.a: bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/s/projects/git/Antonius-MIA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libEncryption_LIB.a"
	cd /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption && $(CMAKE_COMMAND) -P CMakeFiles/Encryption_LIB.dir/cmake_clean_target.cmake
	cd /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Encryption_LIB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/build: bin/utilities/encryption/libEncryption_LIB.a

.PHONY : bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/build

bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/clean:
	cd /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption && $(CMAKE_COMMAND) -P CMakeFiles/Encryption_LIB.dir/cmake_clean.cmake
.PHONY : bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/clean

bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/depend:
	cd /cygdrive/s/projects/git/Antonius-MIA && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/s/projects/git/Antonius-MIA /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption /cygdrive/s/projects/git/Antonius-MIA /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption /cygdrive/s/projects/git/Antonius-MIA/bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/utilities/encryption/CMakeFiles/Encryption_LIB.dir/depend

