/* In C and C++ the words declaration and definition are precies terms with very specific
 * meanings. 
 * A declartion simply introduces a name, and its type , to the compiler without allocation any mmoery
 * for it. 
 * In contrast, a definition provides details of a type's structre or allocates memory in the case of variables
 * The statements below are all declartions
 */

extern int i; 

class MyClass;

void MyFunc(int value);



// In contrast, the following are all definitions;
//

int i = 0;

class MyClass
{
    public:
        float x,y,z;
};


voidMyFunc(int value)
{
    printf("In myFunc(%d).."..value);
}


//In terms of classes and methods, the following code introduces a class definition with a single method declaration

class MyClass
{
    public:
        voidMyMethod();
};


//The implementation(body) of  a method is provided in its definition 
//
void MyClass::MyMethod()
{
    printf("In MyMethod() of MyClass.\n");

}


//Generally speaking, you provide declarations in your .h files and associated definitions in your .cpp files
//However it's also possible to provide a definition for a method at the point where you 
//declare it in a .h file for esxample

class MyClass
{
    public:
        voidMyMethod()
        {
            printf("In mymethod() of my class. \n");
        }
};



// physical hiding means storing internal detaisl in a seperate file(.cpp) form the 
// public interface(.h)
//
//
//
