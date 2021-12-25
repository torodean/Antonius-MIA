
set(Database_SRC MIADatabase.cpp)
set(Database_INC MIADatabase.hpp Credentials.hpp)


add_library(mysqlcppconn SHARED IMPORTED)
set_target_properties(
        mysqlcppconn
        PROPERTIES LINKER_LANGUAGE CXX
        IMPORTED_LOCATION "../../../dlls/mysqlcppconn8-2-vs14"
        IMPORTED_IMPLIB "../../../dlls/mysqlcppconn8.lib")
link_directories("../../../dlls")

add_library(Database_LIB ${Database_SRC} ${Database_INC})
target_link_libraries(Database_LIB mysqlcppconn)