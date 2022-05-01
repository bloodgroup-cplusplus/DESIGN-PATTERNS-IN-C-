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


