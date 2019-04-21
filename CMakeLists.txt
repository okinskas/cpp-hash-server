cmake_minimum_required(VERSION 3.14)
project(cpp_hash_server)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenSSL REQUIRED)
#include_directories(lib/cryptoPP SHARED IMPORTED)
#target_link_libraries(ProjectName "/usr/lib/x86_64-linux-gnu/libSDL.so")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
add_executable(cpp_hash_server src/server/main.cpp src/server/HashServer.cpp src/server/HashServer.h src/server/Socket.cpp src/server/Socket.h src/server/gateway/Hasher.h src/server/SocketReader.cpp src/server/SocketReader.h src/server/external/SHA_Hasher.cpp src/server/external/SHA_Hasher.h src/client/HashClient.cpp src/client/HashClient.h)

target_link_libraries(cpp_hash_server OpenSSL::SSL)