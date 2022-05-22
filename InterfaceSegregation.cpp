// the idea is to get to not create interface that are too large 



#include<iostream>
#include<vector>
#include<boost>
struct Document; 



// let's define a inteface for scanning printing and faxing 
// you could be tempted to put all that in a single interface 


struct IMachine
{
    virtual void print(Document & doc) = 0;
    virtual void scan(Document & doc ) = 0;
    virtual void fax( Document & doc) = 0;

}


struct MFP :IMachine
{


    void print(Document & doc) override
    {

    }

    void scan (Document & doc) override
    {
    }


    void fax( Document & doc) override
    {
    }


};

// the above way of doing it is ok but what we want to do is to make an inteface that only 
// either scans or prints or faxes 
// what do i put inside print and fax 
// how about we throw not implemnted exception
// just empty bodies
// either way we are doing is sending a client a wrong message
// the interface that is defined is just to big
// we need to segregate the interface
// no client is required to print scan and fax
// let's build a differnt interface 
//
//
struct IPrinter
{
    virtual void print( Document & doc) =0;
};


struct IScanner
{
    virtual void scan( Document & doc ) = 0;
};

struct IFax
{
    virtual void fax( Document & doc ) = 0;
};

struct Printer: IPrinter
{
    void print(Document &doc) override
    {
    }
};


// for both activities

struct IMachine : IPrinter, IScanner{};

// you can use a decorator 

struct Machine : IMachine 
{
};



