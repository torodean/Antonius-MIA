cmake_minimum_required(VERSION 3.17)

project(MIA VERSION 0.300)

add_definitions ( -DMIAVERSION=\"${VERSION}\" )

set(CMAKE_CXX_STANDARD 20)
set(MIA_PROJECT_DIR "${CMAKE_CURRENT_BINARY_DIR}")

add_subdirectory(bin)
add_subdirectory(documentation)
include_directories("${CMAKE_CURRENT_BINARY_DIR}/dlls")
add_subdirectory(dlls)