
add_subdirectory(libs)
add_subdirectory(program)
add_subdirectory(resources)
add_subdirectory(terminal)
add_subdirectory(utilities)

add_executable(MIA MIAMain.cpp)
install(TARGETS MIA DESTINATION /usr/bin/)