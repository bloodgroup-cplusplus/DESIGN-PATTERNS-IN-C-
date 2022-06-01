#include<vector>
#include<iostream>

#include<string>


int main()
{
    std::vector<int> vi { 1,2,3,4,5,6,7,8,9,10};

    auto rng = vi | filter ([] (int i) {
            return i%2 == 0;
            });

            | transform([] (int i ) 
            {
                return std::to_string(i);
            });


    std::cout<<rng<<std::endl;


    return 0;
}


            
