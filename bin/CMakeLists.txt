
# Add the sub-directories for the program files.
add_subdirectory(libs)
add_subdirectory(program)
add_subdirectory(resources)
add_subdirectory(terminal)
add_subdirectory(utilities)

# Add the main MIA executable
add_executable(MIA MIAMain.cpp)

# @TODO - Setup install so config file is properly found.
if(WIN32 OR CYGWIN)
	set(INSTALL_DIRECTORY "C:/Program\ Files\ \(x86\)/MIA/")
	set(APPDATA_DIRECTORY "C:/Users/$ENV{USERNAME}/AppData/Roaming/MIA/")
elseif(UNIX)
	set(INSTALL_DIRECTORY "/usr/bin/")
	set(APPDATA_DIRECTORY "/etc/MIA/")
endif(WIN32 OR CYGWIN)

message(STATUS "INSTALL_DIRECTORY set -> ${INSTALL_DIRECTORY}")
message(STATUS "APPDATA_DIRECTORY set -> ${APPDATA_DIRECTORY}")

install(TARGETS MIA DESTINATION ${INSTALL_DIRECTORY})