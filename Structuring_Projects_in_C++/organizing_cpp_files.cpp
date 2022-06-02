/* The project files are always placed before the header files and the reason 
 * for doing this is we want to make sure that every header files is self sufficient 
 * If you have too many includes your compilation time is going to go down 
 * Instaed of doing so practice forward declarations 
 */

#ifndef SERVER_H
#define SERVER_H
// we need include gard cause if the same files is getting used twice thrice
// we avoid the reincluding of the files 
// one more thing about include gard is use can use 
#pragma once
// however this is not the standard way

namespace boost::asio
{
    class io_context;
}

/* doing forward declartion is 
 *
 *
 * Always #include the necessary minimum but not more
 * Every heder must be self-sufficient 
 * Include class header first, then other project includes 
 * #include<libraries> should be included last
 * Prefer forward declartions when possible
 * Avoid monolitihic structure 
 * Also structure is a form of documentation 
 * Everything related to daytime
 *
 * Put header files according to the usecase
 * according to namespaces 
 *
