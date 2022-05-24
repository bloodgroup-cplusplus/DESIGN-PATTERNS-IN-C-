// Windows API ( often referred as the Win32 API) is a collection of C Function, data types and constants that enable programmers to write applications that run on the windows platform. 
/* This includes functions for file handling, process and thread management
 * Creating graphical user interfaces, taking to networks and so on.
 * A good example of a specific C++ API is the stl 
 * STL contains container classes, iterators for navigating over the 
 * elements in those containers, and algorithms that act on those containers
 * API is a logical interface to a software component that hides the internal
 * details required to implement it 
 *
 * WHAT IS DIFFERENT ABOUT API DESIGN 
 *  Interfaces are the most important code that a developer writes. 
 *  Process of developing shared APIs demands more attention than standard GUIs
 *  API is an interface designed for developers, similar to GUI for users
 *  A well designed API is company's biggest asset 
 *  A poor API can lead to nightmare 
 *  Multiple APPs can share same API
 *  STRIVE for BACKWARD COMPATIBILITY when you change an API
 *  If you make an incompatible change to your interface
 *  your client's code may fail to compile, or worse their code could compile but behave differently
 *  Imagine we had differnt printf() function for different operating systems 
 *  Our hello world program would look like this 
 */


#include<stdio.h>
#ifdef __WIN32
#include<windows.h>
#endif
#ifdef __cplusplus
#include<iostream>
#endif

int main( int,char * argv[])
{
#if __STRICT_ANSI__
    printf("Hello world\n");
#elif defined (_WIN32)
    PrintWithFormat("HelloWorld\n");

#elif defined (__PRINTF_DEPRECATED__)
    fprintf(stdout, "HelloWorld\n");

#elif defined (__PRINTF_VECTOR__)
    const char * lines[2] = {"Hello world", NULL};
    printf(lines);

#elif defined (__cplusplus)
    std::cout<<"Hello World"<<std::endl;

#else
#error No terminal output API found
#endif 
    return 0;
}

/* Due to backward compatibility requirement, it is critical to have a change 
 * control process in place. 
 * During the normal development process, many developers may fix bugs or add new 
 * features in an API
 * Someo fo these develoeprs may be junior entineers who do not
 * fullyt understand all of the aspects of good API design. 
 * The need for good cocumentation is paramount when writing an API, particularly if you do not provide the source code for you implementation . 
 * Users can look at your header fils to glean how to use it, 
 * Well written, consistenet, and extensive documentation is therefore any imperative for any good API
 * The need for automated testing is similarly very high. 
 * Of course, you should always test your code, but when you're writing an API you may have hunders of other developers, and thousands of their users, 
 * Depending on the correctness of your code. 
 * If you are making major changes to the implementation of your API, 
 * You can be more confident that you will not break your clients programs if you have a thorough suite 
 * of regression tests to verify that the desired API behaviour has not changed.
 *


