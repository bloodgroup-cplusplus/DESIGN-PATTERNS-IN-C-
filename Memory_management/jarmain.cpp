#include "JarJar.h"
#include<iostream>

void simple_function()
{
    throw std::exception();
}

int main(int argc, const char * argv[])

{
    try
    {

        JarJar *  j = new JarJar();

         j->talk();
    //finding these types of memory leaks is very very difficult
    // since the object is not deleted
        simple_function();
        //lines after simple function is going to be skipped 
        //inluding the delete since it goes to catch block 
        //
        delete j;
    /*int errorCode = 2;

    if(errorCode ==0)
    {
        //ok
        delete j;
    }
    else
    {
        // we have an error
        // error management 
        std::cout<<"lol error"<<std::endl;
    }*/

    }

    catch (std::exception &e)
    {
        //error message 
        //
    }

    return 0;
}

