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
'''
#define ASPECT 1.653
'''

**Instead replace it with code like**

'''
const double Aspect = 1.653;
'''


