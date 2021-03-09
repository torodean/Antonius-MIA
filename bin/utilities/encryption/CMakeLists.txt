
set(Encryption_SRC D3CEncrypt.cpp D3CEncryptPW.cpp)
set(Encryption_INC D3CEncrypt.hpp D3CEncryptPW.hpp)

add_library(Encryption_LIB ${Encryption_SRC} ${Encryption_INC})