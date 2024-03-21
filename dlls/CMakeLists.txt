
if (WIN32 OR CYGWIN)
	SET(CMAKE_FIND_LIBRARY_PREFIXES "")
	SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib" ".dll")
	
	message("-- Linking netapi32")
	find_library(netapi32 ${CMAKE_CURRENT_BINARY_DIR})

	message("-- Linking gdi32")
	find_library(gdi32 ${CMAKE_CURRENT_BINARY_DIR})
elseif(UNIX)
	SET(CMAKE_FIND_LIBRARY_PREFIXES "lib")
	SET(CMAKE_FIND_LIBRARY_SUFFIXES ".so" ".a")
endif()

message("-- Linking mysqlcppconn")
find_library(mysqlcppconn ${CMAKE_CURRENT_BINARY_DIR})
#add_library(mysqlcppconn mysqlcppconn.dll)
#set_target_properties(mysqlcppconn PROPERTIES LINKER_LANGUAGE C)