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
    string name;
    string text;
    std::vector<HtmElement> elements;
    const size_t indent_size = 2;
    HtmlElement(){}
    HtmlElement() (const string & name, const string & text):name(name),text(text) {}
    // this is the code for pretty printing that is present in the github repo

    string str( int indent = 0 ) const
    {
        ostringstream oss;
        string i (indent_size* indent, ' ');
        os<<i<< "<"<<name << ">"<<std::endl;
        if(text.size() > 0)
            oss<<string(indent_size*(indent+1),' ') <<text<<std::endl;
        for(const auto & e :elements)
            oss<<e.str(indent+1);
        oss<<i << "</" <<name << ">" << std::endl;
        return oss.str();
    }
};


//fluent 
struct HtmlBuilder
{
    HtmlBuilder &add_child(string child_name, string child_text)
    {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(a);
        return *this; 
    }
    HtmlElement root;
int main()
{
    // let's say we want the list of two words 
    // hello and world 
    // and we want it to have it on a part of html string 

    string words[]= {"hello " , "world"};

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
