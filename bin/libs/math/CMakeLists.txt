

set(Math_SRC MathUtils.cpp D3CMath.cpp)
set(Math_INC MathUtils.hpp D3CMath.hpp)

add_library(Math_LIB ${Math_SRC} ${Math_INC})
