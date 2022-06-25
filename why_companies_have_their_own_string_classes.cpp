#include<csignal>
#include<string>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<memory>


#include<boost/algorithm/string.hpp>
#include<sstream>
// this is an example of an adapter design pattern 
// this is the reason why we end up builidng these things
// default apis of std::string is somewhat lacking that is 
// the reason why we end up using boost
//
class String
{
    std::string s;
    public:
        String (const std::string &s) : s(s) {}
        String to_lower_copy() const
        {
            return {boost::to_lower_copy(s)};
        }
        std::vector<std::string> split(const string & delimeter = " ") const 
        {
            std::vector<std::string> parts;
            boost::split(parts, s, boost::is_any_of(delimeter), boost::token_compress_on);
            return std::vector<std::string>(parts.begin(), parts.end());
            // we have taken global functions to these adapters
        }
        //std::string has a size() and length() 
        // In the process of adapting an adapter we can have our own name 

        size_t get_length() const {return s.length();}
};
int main()
{
    String s { "Hello  World " };

    // to lowercase and split we atleast need boost 

 //   string tl = boost::to_lower_copy(s);
  //  std::vector<string> parts;
   // boost::split(parts,sl, boost::is_any_of(' '),boost::token_compress_on);
    // unless you know there is a function 
    // you are not going to find out these operations exist
    // you expect string classes to have these
    // this is the reason why you build adapters 
    // an adapter is simply the interface you built instead of the 
    // interface you are given 
    // the string class above does that 
    for(auto & w: s.to_lower_copy().split())
        std::cout<<w.get_length() <<std::endl;
    //non-intrunsive desing
    //you will not break the open close principle
    //you end up adding globals 
    //

    //for (auto & p : parts) 
     //   std::cout<<p.length() <<std::endl;
    
    return 0;
}
