
#include<iostream>
#include<daytime>

int main(int argc, char *argv[])
{
    auto client = daytime::client();
    std::cout<<client.get_value()<<std::endl;
    auto helper = daytime::helper();
    return 0;
}


// when something is exported it is visible 
// When it is exported it is available 
// Reachability is a subset fo visibility 
// Semantics is available
// Size and type id is visible to us 
//
