#include<iostream>
class JarJar
{
    public:
        //constructor
        JarJar()
        {
            std::cout<<"Constructing Jar Jar at " << this <<std::endl;
        }

        //destructor
        
        ~JarJar()
        {
            std::cout<<"Deleting JarJar at" <<this<<std::endl;
        }


        //copy constructor 

        JarJar (const JarJar & old)
        {
            std::cout<<"Copy constructing JarJar" <<std::endl;
        }

        //Copy Assignment Operator 

        JarJar& operator = (const JarJar& old)
        {
            std::cout<<"copy assignment of JarJar"<<std::endl;
            return *this;
        }


        //Move constructor

        JarJar(JarJar &&old)
        {
            std::cout<<"Move constructingJarJar "<<std::endl;
        }

        void talk()
        {
            std::cout<<"Chad"<<std::endl;
        }


};
