/* Interface Segregation Principle
 * Suppose you decide to define a multifunction printer. A device that 
 * can print, scan, and also fax documents. So you define it like so:
 */

#include<iostream>
#include<vector>



struct MyFavouritePrinter
{
    void print(std::vector<Document*> docs) override;
    void fax(std::vector<Document*> docs) override;
    void scan(std::vector<Document*> docs) override;

};

/* suppose you decide to define an interface that needs to be implemented 
 * by everyone who also plans to make a multifunction printer. 
 * You could use the Extract interface function in your favourite IDE
 * and you'd get something like this
 */



struct IMachine2
{
    virtual void print(std::vector<Document*> docs) = 0;
    virtual void fax(std::vector<Document*> docs) = 0;
    virtual void scan(std::vector<Document*> docs) = 0;
};


// this is a problem the reason is a problem is that some implementor of
/* this interface might not ndeed scanning or faxing, just printing.
 * And yet, you are forcing them to implement those extra features,
 * sure , they can all be no-op but why bother with this?
 * So what the Interface Segregatin Principle suggests is that you 
 * split up interfaces so that implmentors can pick and choose depending
 * on their needs. Since printing and scanning are different operations(for example,
 * a scanner cannot print), we define seperate Interfaces for these;
 */

struct Iprinter2
{
    virtual void print(std::vector<Document*> docs) = 0;
    virtual void fax(std::vector<Document *> docs) =0;
    virtual void scan(std::vector<Document*> docs) = 0;
};


/* Then, a printer or a scanner can just implement the required functionality:
 */
struct Printer:IPrinter2
{
    void  print(std::vector<Document*> docs) override;
};

struct Scanner: IScanner2
{
   void scan(std::vector<Document*> docs) override;
};


