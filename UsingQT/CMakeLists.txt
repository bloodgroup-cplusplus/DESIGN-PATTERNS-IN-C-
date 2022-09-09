cmake_minimum_required(VERSION 3.5)

project(UsingQT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(UsingQT main.cpp)

install(TARGETS UsingQT
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
