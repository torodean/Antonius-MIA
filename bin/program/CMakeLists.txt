
set(Program_SRC SubProgram.cpp Configurator.cpp Error.cpp)
set(Program_INC SubProgram.hpp Configurator.hpp Error.hpp)

add_library(Program_LIB ${Program_SRC} ${Program_INC})