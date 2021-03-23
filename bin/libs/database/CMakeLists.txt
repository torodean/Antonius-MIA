
set(Database_SRC MIADatabase.cpp)
set(Database_INC MIADatabase.hpp)

add_library(Database_LIB ${Database_SRC} ${Database_INC})
target_link_libraries(Database_LIB mysqlcppconn)