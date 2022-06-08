cmake_minimum_required(VERSION 3.21)
project(lang)

set(CMAKE_CXX_STANDARD 20)

add_executable(lang src/main.cpp headers/lexer.h headers/token.h src/lexer.cpp src/token.cpp src/util.cpp headers/util.h headers/functions.h src/functions.cpp)
