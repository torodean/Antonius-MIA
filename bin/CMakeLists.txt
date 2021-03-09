
add_subdirectory(libs)
add_subdirectory(program)
add_subdirectory(resources)
add_subdirectory(terminal)
add_subdirectory(utilities)

add_executable(MIA MIAMain.cpp)
target_link_libraries(MIA Terminal_LIB)

install(TARGETS MIA DESTINATION /usr/bin/)

