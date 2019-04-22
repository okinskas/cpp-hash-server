cmake_minimum_required(VERSION 3.14)
project(client)

set(CMAKE_CXX_STANDARD 14)

add_executable(client src/main.cpp src/HashClient.cpp src/TerminalUI.cpp src/TerminalUI.h)