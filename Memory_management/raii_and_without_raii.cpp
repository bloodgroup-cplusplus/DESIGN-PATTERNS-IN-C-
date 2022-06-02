#include<iostream>
#include<fstream>

void old_way()
{
    FILE * f = fopen("FileName.txt", "w");
    if(f != nullptr)
    {
        // write on file 

        fclose(f);
    }

}


void raii_way()
{
    std::ofstream f( "FileName.txt", std::ios::out);

    f<< "Hello world"<<std::endl;
}

int main(int argc, const char * argv[])
{
    return 0;
}


