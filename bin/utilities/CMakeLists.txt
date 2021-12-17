
add_subdirectory(audio)
add_subdirectory(encryption)

if(WIN32 OR CYGWIN)
    add_subdirectory(windows)
endif()

set(Utilities_SRC StringUtils.cpp MathUtils.cpp FileUtils.cpp MIASequencer.cpp D3CMath.cpp MIAWorkout.cpp SystemUtils.cpp VirtualKeyStrokes.cpp)
set(Utilities_INC StringUtils.hpp MathUtils.hpp FileUtils.hpp MIASequencer.hpp D3CMath.hpp MIAWorkout.hpp SystemUtils.hpp VirtualKeyStrokes.hpp)

add_library(Utilities_LIB ${Utilities_SRC} ${Utilities_INC})
if (WIN32 OR CYGWIN)
	target_link_libraries(Utilities_LIB gdi32)
endif()