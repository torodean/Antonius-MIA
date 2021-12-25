

include_directories(../utilities)
include_directories(../program)
include_directories(../libs/math)

set(Terminal_SRC MIATerminal.cpp TerminalTools.cpp Commands.cpp)
set(Terminal_INC MIATerminal.hpp TerminalTools.hpp Commands.hpp)

add_library(Terminal_LIB ${Terminal_SRC} ${Terminal_INC})

if(WIN32 OR CYGWIN)
    target_link_libraries(Terminal_LIB Program_LIB Utilities_LIB Encryption_LIB Audio_LIB Windows_LIB)
elseif(UNIX)
    target_link_libraries(Terminal_LIB Program_LIB Utilities_LIB Encryption_LIB Audio_LIB xdo Database_LIB)
endif()

add_executable(MIATerminal MIATerminal.cpp)
target_link_libraries(MIATerminal Terminal_LIB)

# @TODO - Setup install so config file is properly found.
#install(TARGETS MIATerminal DESTINATION ${INSTALL_DIRECTORY})