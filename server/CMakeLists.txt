cmake_minimum_required(VERSION 3.10)
project(server)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenSSL REQUIRED)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
add_executable(server src/main.cpp src/HashServer.cpp src/HashServer.h src/Socket.cpp src/Socket.h src/SocketReader.cpp src/SocketReader.h src/external/SHA_Hasher.cpp src/external/SHA_Hasher.h)

target_link_libraries(server OpenSSL::SSL)
