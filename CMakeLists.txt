cmake_minimum_required(VERSION 3.17)

set(MIA_VERSION_VAL "0.300")

project(MIA VERSION ${MIA_VERSION_VAL})

add_definitions ( -DMIAVERSION=\"${MIA_VERSION_VAL}\" )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall")
set(MIA_PROJECT_DIR "${CMAKE_CURRENT_BINARY_DIR}")

if(WIN32 OR CYGWIN)
    message(STATUS "Creating Windows only variables.")
elseif(UNIX)
    message(STATUS "Creating Linux only variables.")
    set(USE_Database_LIB ON)
    message(STATUS "Set USE_Database_LIB: ${USE_Database_LIB}")
    add_definitions ( -DUSE_Database_LIB="true" )
endif()

add_subdirectory(bin)
add_subdirectory(documentation)
include_directories("${CMAKE_CURRENT_BINARY_DIR}/dlls")
add_subdirectory(dlls)