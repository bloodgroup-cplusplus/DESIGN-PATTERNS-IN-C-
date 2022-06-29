#include<csignal>
#include<string>
#include<cmath>
#include<tuple>
#include<cstdio>
#include<iostream>
#include<memory>


#include<boost/algorithm/string.hpp>
#include<sstream>


struct HtmlElement
{
    std::string name;
    std::string text;
    std::vector<HtmElement> elements;
    const size_t indent_size = 2;
    HtmlElement(){}
    HtmlElement() (const std::string & name, const std::string & text):name(name),text(text) {}
    // this is the code for pretty printing that is present in the github repo

    std::string str( int indent = 0 ) const
    {
        std::ostringstream oss;
        std::string i (indent_size* indent, ' ');
        oss<<i<< "<"<<name << ">"<<std::endl;
        if(text.size() > 0)
            oss<<std::string(indent_size*(indent+1),' ') <<text<<std::endl;
        for(const auto & e :elements)
            oss<<e.str(indent+1);
        oss<<i << "</" <<name << ">" << std::endl;
        return oss.str();
    }
};


//fluent builder instead of a builder 
struct HtmlBuilder
{
    HtmlBuilder &add_child(std::string child_name, std::string child_text)
    {
        HtmlElement e {child_name, child_text};
        root.elements.emplace_back(e);
        return *this; 
    }
    HtmlElement root;
int main()
{
    // let's say we want the list of two words 
    // hello and world 
    // and we want it to have it on a part of html string 

    std::string words[]= {"hello " , "world"};

 //   ostringstream oss;
  //  oss << "<ul>\n";
    ///for(auto & w:words)
   //     oss<< "  <li> " << w<< " </li> "<<;

    // this is the real example of how web-browsers renders your html 
    // this is done using c++ builderr
    // complex html are rendered using the html renderer
    //
    HtmlBuilder builder{"ul"};

    builder.add_child("li","hello");
    builder.add_child("li","world");
    std::cout<<builder.root.str()<<std::endl;
    HtmlElement ul {"ul", ""};
    for(auto & w:words)
        ul.elements.push_back(Htmlelement{"li", w});
    std::cout<<ul.str()<<std::endl;
    return 0;
    // we could have a dedicated component for building these lists 
