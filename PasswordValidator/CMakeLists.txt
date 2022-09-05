cmake_minimum_required(VERSION 3.5)

project(PasswordValidator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PasswordValidator
        main.cpp
        ipasswordvalidate.h
        lengthvalidator.cpp
        lengthvalidator.h
        passwordvalidatordecorator.cpp
        passwordvalidatordecorator.h
        digitpasswordvalidator.cpp
        digitpasswordvalidator.h

)

install(TARGETS PasswordValidator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
