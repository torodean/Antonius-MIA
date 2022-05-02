include_directories(../../)

if (${USE_Database_LIB})
    message(STATUS "Including Database building")
    # The database features are currently working on linux.
    # They require the libmysqlcppconn-dev package to be installed.
    add_subdirectory(database)
else()
    message(STATUS "Skipping Database building")
endif()

add_subdirectory(math)
add_subdirectory(language)