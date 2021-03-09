
add_subdirectory(encryption)

if(WIN32)
    add_subdirectory(windows)
endif(WIN32)

set(Utilities_SRC StringUtils.cpp MathUtils.cpp FileUtils.cpp MIASequencer.cpp D3CMath.cpp MIAWorkout.cpp)
set(Utilities_INC StringUtils.hpp MathUtils.hpp FileUtils.hpp MIASequencer.hpp D3CMath.hpp MIAWorkout.hpp)

add_library(Utilities_LIB ${Utilities_SRC} ${Utilities_INC})