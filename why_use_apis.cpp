/* The question of why you should care about APIs in your own software projects
 * can be interpreted in two differnt ways 
 * 1) why should you design and write your own apis or 
 * 2) why sould you use apis from other providers in your applications?
 * Both of these perspectives are tacked in the following sections 
 *
 *
 * MORE ROBUST CODE
    * If you are writing amodule to be used by other developers, either for fellow engineers within your
    * organization or for external customers of your library, then it would be a wise investment to create
    * an API for them to access your functionality. Doing so will offer you the following  benefits 
    *   Hides Implementation : By hiding the implementation details fo your models, you gain the 
    *   flexibility to change the implementation at a future data without causing upheaval for your users
    *   Without dong so you will restrict yourself in terms of the updates you can make to your code
    *   or force your users to rewrite their code in order to adopt new versions 
    *   of your livrary 
    *
    *   Increases Longevity : over time, systems that expose their implementation details tend to 
    *   devolve into spaghetti code where every part of the system depends on the 
    *   internal details of other parts of the system. 
    *   As a result the system becomes fragile, rigid, immobile, and viscous
    *
    *
    *
    *   Promotes modularizaton . An API is normally devised to address a specific taks or use case. 
    *   As such, APIs tend to deine a modular grouping of functionality with a coherent focus. 
    *   Developing an application on top of a collection of APIs promotes loosely
    *   couple and modular architectures wherer the behavior of one module is not dependent on the 
    *   internal details of another module. 
    *
    *
    *
    *   Reduces code duplication. Code duplication is one of the cardinal sins of software engineering 
    *   and should be stanmped out whenever possible. By keeping all of your code's logic behind 
    *   a strict interfact athat all clients must use, 
    *
    *   Easier to change the implementation 
    *   Easier to optimize
    *   Code Reuse 
    *   
    *   In fact, Facebook developed a product called HipHop to convert their PHP code into C++ to improve the performance of their social networking site. C++ API design therefore does have a role to play in scalable Web service development. Additionally, if you develop your core APIs in C++, not only can they form a high-performance Web service, but your code can also be reused to deliver your product in other forms, such as desktop or mobile phone versions.
    */

// let's imagine a scenario if you are writing in-house softare, your fellow engineers will very likely need to write code
// that uses your code. If you use good API design techniques, you can simplify their lives and, 
// by extension you own this becomes more important if multiple developers are working in parallel
// on code that depends upon each other. 
// let's say that you are working on a string encrypting algorithm that another developer
// wants to use to write data out to a configuratoin file. 
// One approach would be to have the other develper wait until you are finished with your work and then 
// he can use it in his file writer module. 
// However, a far more efficient uswe of time would be for the two fo you to meet
// early on and afree upon an appropriate API. 
// the you can put atha API in place with placeholder functionality that your 
// colleague can start calling immediately, such as 



#include<string.h>

#include<iostream>

class StringEncryptor
{
	public:
        ///set the key to use for the Encrypt() and Decrypt() calls


        void SetKey( const std::string & key);


        /// encrypt an input string based upon the current key

        std::string Encrypt( const std::string & str) const ;

        /// decrypt a string using the current key calling
        // Decrypt() on a string returned by Encrypt() will
        // return the original stirng for the same key.

        std::string Decrypt( const std::string & str) const;
};


// you can then provide a simple implementation fo these functions so that at least
// the module will compile and link. 
// for example, the associated .cpp file might look like
//
//
void StringEncryptor::SetKey(const std::string & key)
{

}
std::string StringEncryptor::Encrypt(const std::string & str)
{
    return str;
}


std::string StringEncryptor::Decrypt(const std::string & str)
{
    return str;
}


/* in this way, your colleague can use this API and proceed with his work 
 * without being held up by your progress.
 * for the time being, your APi will not actually encrypto any strings, but that's just
 * a minor implementaton detail !
 *

