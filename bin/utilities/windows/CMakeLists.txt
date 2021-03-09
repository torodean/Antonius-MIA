
if(WIN32)
    set(Windows_SRC WindowsUtilities.cpp WinKeys.cpp LOLANetUse.cpp)
    set(Windows_INC WindowsUtilities.hpp WinKeys.hpp LOLANetUse.hpp)

    add_library(Windows_LIB ${Windows_SRC} ${Windows_INC})
endif(WIN32)