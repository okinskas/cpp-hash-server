cmake_minimum_required(VERSION 3.14)
project(cpp_hash_server)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenSSL REQUIRED)
#include_directories(lib/cryptoPP SHARED IMPORTED)
#target_link_libraries(ProjectName "/usr/lib/x86_64-linux-gnu/libSDL.so")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
add_executable(cpp_hash_server src/main.cpp src/HashServer.cpp src/HashServer.h src/Socket.cpp src/Socket.h src/gateway/Hasher.h src/SocketReader.cpp src/SocketReader.h src/external/SHA_Hasher.cpp src/external/SHA_Hasher.h)

target_link_libraries(cpp_hash_server OpenSSL::SSL)