#include<iostream>
#include<cstdio>
#include<boost/lexical_cast.hpp>
#include<string>
#include<vector>
#include<fstream>

// A class should have a primary responsibility and they should not take other responsibility
// Primary responsibility of a class 
//
//
// let's say we have a journal class 
//

struct Journal 
{
    string title;
    std::vector<string> entries;

    Journal ( const string & title) : title(title){}

    void add_entry(const string & entry)
    {
        static int count = 1;
        entries.push_back(boost::lexical_cast<string>(count++) + ":" + entry);
    }
    /*suppose we want to save the journal in the file 
     * the wrong way to go is to add a function inside the journal class itself
     * A function that takes the filename and takes the function output stream
     * the problem with this approach is persistence
     * save we have other domain objects
     * a function called save or load 
     * when we want to change the persistence 
     * we want to persist things so for that we need a seperate class a seperate component etc.
     * 
    void save(const string & filenmae)
    {
        std::ofstream ofs(filename);
        for( auto & e:entries)
            ofs<<e<<endl;
    }*/

};

struct PersistenceManager
{
    static void save(const Journal & j, const string & filename)
    {
        std::ofstream ofs(filename);
        for(auto & e: j.entries)
            ofs<<e<<endl;
    }
};
// when we make entries 
// when it comes to persistence we must use "seperation of concerns "
// we can use this component when we want to save something 


int main()
{
    Journal journal {"Dear Diary"};
    journal.add_entry("I ate a bug");
    journal.add_entry("I cried today");
    journal.add_entry("I creied today");

    //Journal.save("diary.txt")
    PersistenceManager pm;
    pm.save(journal,"diary.txt");
    getchar();
    return 0;
}



