


if(WIN32 OR CYGWIN)
    set(Windows_SRC WindowsUtilities.cpp LOLANetUse.cpp)
    set(Windows_INC WindowsUtilities.hpp LOLANetUse.hpp)

    add_library(Windows_LIB ${Windows_SRC} ${Windows_INC})
	target_link_libraries(Windows_LIB netapi32)
endif(WIN32 OR CYGWIN)