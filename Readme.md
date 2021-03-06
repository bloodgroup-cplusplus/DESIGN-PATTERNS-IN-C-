# UNDERSTANDING PROJECT STRUCTURE IN C++
**Read this article here [C/C++ Project Structure] (https://dev.to/narasimha1997/understanding-c-c-build-system-by-building-a-simple-project-part-1-4fff)**

**Project structrue has to be easily understandble and should isolate different functionalites as much as possible**

**No one will ever stop us from using our own project, but most of the open source projects built with C/ C++ use this structure**.

project root
  - include
  - src
      - module-1
      - module-2
      - module-n
      - main.c/main.cc (depends on the project)
  - Makefile
  - README
  - LICENSE
  - misc files

**Let's have a look at each and every file/directory means**

**1 include - THis is the place where all our header files live**

**2 src - The direcotry that contains all our source code. We can have multiple sub-directories/modules inside src. Also we can have a main function file insider src**.

**3 makefile - Makefiles are used by make command , we wil be using make to build our project** 

**We have a project called memlogger above here the project structre used here is given below**

memlogger
   - bin  - will explain the need for this
   - include
       - free_memory_api.h
       - file_writer.h
   - src
       - free_memory_api
          - free_memory_api.c
       - file_writer
          - file_writer.c
       - main.c
   - Makefile
# What are header files?
   
   **Header files are blueprints of our actual C code. For every C module we write, it is a good practice to export the header-file. 
   These header files are used by the compiler to understand what all functions are exported by a module. Once compilation is done, 
   header files are not used anywhere. The actual use of header files comes into picture when our project/module is used as a module in
   some other project, other programmers can simply include our header file to use the function declrations we exported.**

**The project can be built in a single command, We have divided this into three phases**.

**1.File_writer : This make rule generate file_writer.o object file under ./bin**

**2.Free_memory_api: This rule generates free_memory_api.o under ./bin.**

**3.Project:This builds the entire project, it generates main.o and links main.o with other two objects files to create a standalone executable called memlogger**

**Excecute these commands with make**

**Step-1 . File_writer. o**

**make file_writer** 

**Step-2.free_memory_api.o**

**step-3 final binary**
**make project**

# What happened under the hood?

**It is important to understand the build process we used here. To understand that, we need to know the concept of object files**.

#What we did in the makefile??

**We defined three rules, each rule builds a module, the third rule goes ahead by one step and links all the three modules**

**We used gcc compiler, (g++ for C++ projects). Options used:**

**

# COMMON C++ CONVENTIONS AND DESIGN PATTERNS 

**These are important statements derived directly from the book [Effective C++] (https://www.amazon.com/Effective-Specific-Addison-Wesley-Professional-Computing-ebook/dp/B004V4420U/ref=sr_1_2?crid=B7OBYHH2NS3F&keywords=effective+c%2B%2B&qid=1651293361&sprefix=effective+c%2B%2B%2Caps%2C541&sr=8-2)**

**The easiest way to view C++ not as a single language but a federation of related languages.**

**To make sense of C++ you have to recognize its primary sub languages. There are four of them.**


## C. 
**Deep down C++ is still based on C. blocks, statements, preprocessor, built-in datatypes, arrays, pointers etc.
all come from C but when you find yourself working with the C part of C++. the rules for effective programming 
reflect C's more limited scope. no templates, no exceptions, no overloading. etc.** 


## Object-Oriented C++ .
**This part of C++ is what C with Classes was all about: classes (including constructors and destructors) encapsulation
inheritence polymorphism. virtual functions(dynamic binding), etc. This is the part of C++ to which the class rules 
for object-oriented mostly directly apply.** 


## Template C++.
**This is the generic programming part of C++. the one that most programmers have the least experience with.Template
considerations pervade C++. and it's not uncommon for rules for good programming to include special template-only 
Templates are so powerful they give rise to completely new programming paradigm, template metaprogramming (TMP)**.


## The STL.
**The STL is a template libray but it's a very special template library. Its conventions regarding containers,iterators
algorithms, and function objects mesh beautifully, but templates and libraries can be built around other ideas too. 
The STL has particular ways of doing things, and when you're working with the STL, you need to follow the conventions**.


# GUIDELINES AND RULES TO BE FOLLOWED 


## Prefer consts, enums and inline to #defines 

**Avoid using code like**
```C++

#define ASPECT 1.653
```

**Instead replace it with code like**

``` C++
const double Aspect = 1.653;
```


**Use standard string library from C++ rather than using const char**
```C++
const char*constauthorName = "ScottMeyers";
```
**Instead of using the above line consider replacing it with line given below**
```C++
const std::string authorName("Scott Meyers");
```

**The second special case concerns class-specific constants.to limit the scope of a constant to a class,
you must make it a member, and to ensure there's at most one copy of the constant, you must make it a 
static member**
```C++
class GamePlayer
{
    private:
        static const int NumTurns = 5;
        int scores[NumTurns];
};
```

**Older compilers may not accept the syntax above, because it used to be illegal to provide an initial
value for a static class member at its point of declaration. Furthermore , in -class initialization is allowed
only for integral types and only for constants, In cases where the above syntax can't be used
you put the initital value at the point of definition.**

```C++
class CostEstimate
{
    private:
        static const double FudgeFactor; //declration of static class 
        //constant;goes in header file (.h or .hpp file)
};

const double CostEstimator::FudgeFactor = 1.35; // definition of static class constant goes in implementation file (.cpp file)

```
**Regarding the keyword const if the word const appears to the left of the asterisk , what's pointed to is constant.
if the word const appears to the right of the asterisk, the pointer itself is constant; if const appears on both sides,
both are constant.**

**The purpose of const on member functions is to identify which member functions may be invoked on const objects. 
Such member functions are important as they make the interface of a class easier to understand . It's important 
to know which functions may modify an object and which may not. They make it possible to work with const objects**

```C++
class TextBlock
{
    public:
    const char &operator[] (std::size_t position ) const //operator[] for const objects
    {
        return text[position];}
    char & operator [] (std::size_t position) //operator [] for non-const objects
    {
        return text[position];}

    private:
    std::string text;
};

TextBlock's operator[]s can be used like this
TextBlock tb("Hello")
std::cout<<tb[0]; // calls non-const  //TextBlock::operator[]
```

##Things to remember while using const 
**Declaring something const helps compilers detect usage errors, const can be applied to objects at any scope, to function parameters
and return types, and to member functions as a whole**

**Compilers enforce bitwise constness, but you should program using logical constness**

**When const and non-const member functions have essentially identical implementations, code duplication can be avoided by having the non-const version call the const version.**


