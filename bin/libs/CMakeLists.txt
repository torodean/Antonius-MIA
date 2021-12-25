

if(UNIX)
    # The database features are currently working on linux.
    # They require the libmysqlcppconn-dev package to be installed.
    add_subdirectory(database)
endif()
add_subdirectory(math)