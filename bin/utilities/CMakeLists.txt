
add_subdirectory(audio)
add_subdirectory(encryption)

include_directories(../terminal)
include_directories(../program)
include_directories(../libs/math)

if(WIN32 OR CYGWIN)
    add_subdirectory(windows)
endif()

set(Utilities_SRC Shengli.cpp FileUtils.cpp MIASequencer.cpp MIAWorkout.cpp SystemUtils.cpp VirtualKeyStrokes.cpp)
set(Utilities_INC StringUtils.hpp FileUtils.hpp MIASequencer.hpp MIAWorkout.hpp SystemUtils.hpp VirtualKeyStrokes.hpp)

add_library(Utilities_LIB ${Utilities_SRC} ${Utilities_INC})
target_link_libraries(Utilities_LIB Math_LIB)
if (WIN32 OR CYGWIN)
	target_link_libraries(Utilities_LIB gdi32)
endif()