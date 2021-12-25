
if (WIN32 OR CYGWIN)
    message("-- Skipping Database building")
elseif(UNIX)
    add_definitions ( -DUSING_DB=1 )
    # The database features are currently working on linux.
    # They require the libmysqlcppconn-dev package to be installed.
    add_subdirectory(database)
endif()

add_subdirectory(math)