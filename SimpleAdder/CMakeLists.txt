cmake_minimum_required(VERSION 3.13)

project(googletest_sample)

#get googletest
include(FetchContent)
FetchContent_Declare(googletest)
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG release-1.12.1

FetchContent_GetProperties(googletest)
#googletest_POPULATED
#googletest
add_library(sumLibrary STATIC LibraryCode.cpp)

add_executable(mainApp main.cpp)
target_link_libraries(mainApp sumLibrary)


add_executable(testRunner test.cpp)
target_link_libraries(testRunner sumLibrary)
