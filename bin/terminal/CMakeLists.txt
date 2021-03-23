
set(Terminal_SRC MIATerminal.cpp Commands.cpp)
set(Terminal_INC MIATerminal.hpp Commands.hpp)

add_library(Terminal_LIB ${Terminal_SRC} ${Terminal_INC})

if(WIN32)
    target_link_libraries(Terminal_LIB Program_LIB Utilities_LIB Windows_LIB Encryption_LIB Audio_LIB Database_LIB)
elseif(UNIX)
    target_link_libraries(Terminal_LIB Program_LIB Utilities_LIB Encryption_LIB Audio_LIB xdo Database_LIB)
endif(WIN32)

add_executable(MIATerminal MIATerminal.cpp)
target_link_libraries(MIATerminal Terminal_LIB)
install(TARGETS MIATerminal DESTINATION /usr/bin/)