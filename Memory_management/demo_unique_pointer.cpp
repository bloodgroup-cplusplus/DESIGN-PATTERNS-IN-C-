#include<iostream>
#include<memory>
#include "JarJar.h"


int main( int argc, char * argv[])
{
    // auto j= std::make_unique<JarJar>();

    std::unique_ptr<JarJar> j;

    std::cout<<j.get()<<std::endl;

    j.reset(new JarJar());

    std::cout<<j.get()<<std::endl;





    return 0;
}


