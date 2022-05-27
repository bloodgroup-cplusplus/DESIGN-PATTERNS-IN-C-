/* THe object-oriented concept of encapsulation provides a mechansim for mimiting access
 * to memebers of an object. 
 * In C++ this is implemented using the following access contraol keywords for classes and
 * structs 
 * Public : Members are accessible outside of the class/struct. This is the default access level for 
 * structs.
 *
 * Protected : Members are accessible within the specific class and any defived clases only
 * Private: Members are accesible only within the speicific class they are defiened within
 * Package-private in Java means that a member can be accessed only by classes within the same package. This is the default visibility in Java. Package-private is a great way to allow other classes in a JAR file to access internal members without exposing them globally to your clients. For example, it’s particularly useful for unit tests that need to verify the behavior of private methods.
C++ does not have the concept of package-private visibility. Instead, it uses the more permissive notion of friendship to allow named classes and functions to access protected and private members of a class. Friendship can be used to enhance encapsulation, but it can also overexpose internal details to your clients if used carelessly.*/


/* Encapsulation is the proces of seperating the public interface of an API from its underlying
 * implementation 
 * Logical hiding means using the C++ language features of protected and private to restrict
 * access to internal detaisl . 
 *
 *
 * Hide Member variables :
 *  The term encapsulation is also often used to describe the bundling of data with the methods that 
 *  operate on those data. This is implemented in C++ by having classes that can contain both variables
 *  and methods. However, in terms of Good API design, you should never make member variables
 *  public. If data members form part of the logical interface of the API, the you should instread
 *  provide getter and/or setter methods, that provide indirect access to the member variables
 *  avoid writing
 */



class Vector3
{
    public:
        double x,y,z;
};;

//Instead prefer

class Vector3
{
    public:
        double GetX() const;
        double GetY() const;
        double GetZ() const;
        void SetX(double val);
        void SetY(double val);
        void SetZ(double val);

    private:
        double mX,mY,mZ;
};


//The latter syntax is obviously more verbose and involves more typing on your part as the programmer, 
//but the extra few minutes spent doing this could save you hours, or even days, further
//down the line should you decide to change the interface. Some of the additional uses of 
//getter/setter routines, rather than exposing member variables directly, include the following

/* Validation : You can perform validation on the values to ensure that the internal state of the class is alwys valid and consistent. 
 * if you have a method that lets clients set a new RGB color, you could check that each of the supllied red, green, and blue values are within the valid range,
 * Lazy evalution. Calcuating the value of a variables
 *
 *
 */


class IntegerStack
{
    public:
        static const int MAX_SIZE = 100;
        void push( int val);
        int Pop();
        bool IsEmpty() const;
        int mStack[MAX_SIZE];
        int mCurSize;
};


/* clearly the above one is a really bad API cause it exposes the way that the stack has been implemented as fixed arry of integers
 * and it exposes the interal state of the stack the via the mCurSize variable
 * If at some future dat you decide to imporvet eh implemtation fo this class, 
 * by using a std::vector or std::list you may find this difficult. 
 * Cause mySTack and mCursize variables are exosed 
 * client code could be relying on the ability to access these variable directily
 * by changein your impolemtnyaion you could break client's code 
 */


class IntegerStack
{
    public:
        void Push(int val);
        int pop();
        bool IsEmpty() const;
    private:
        static const int MAX_SIZE = 100;
        int mStack[MAX_SIZE];
        int mCurSize;
};
//data members of a class should always be delcard private, newver public or protected 
//
