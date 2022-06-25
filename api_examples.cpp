/* APIs Examples 
 * APIs ar everywhere. Even if you have only been programming for a short amount of time, 
 * chances are that you have written code to use an API or two an maybe
 * you've also written one yourself. 
 *
 *
 * LAYERS OF APIs
 *  An API can be any size, from a single function to a large collection of classes. 
 *  It can also provide access to functionality to any architrectural level, 
 *  From low-level operating system calls all the way up to GUI toolkits. 
 *  The following list presents various common APIs, many of which you've
 *  probably heard of already, to give you an appreciation for how prevalent API development is 
 *
 *      Operating System (OS) APIs : Every OS must provide a set of standard APIs to allow programs to access OS-level services. 
 *      For example, the POSIX API defines functions such as fork() getpid()
 *      and kill() for managing UNIX-style processes. Microsoft's Win32 API
 *      includes functions such as CreateProcess(), GetCurrentProcess(), and 
 *      TerminateProcess() for managing Windows processes. 
 *      Theser are stable low-level APIS that should never change, 
 *
 *
 *
 *
 *      Language APIs  The C language provides a standard API implmented as the libc library
 *      and supporting man pages, which includes familiar functions such as 
 *      printf(), scanf(), and fopen(). The C++ language also offers the STandard Template Libarary(STL) which provides
 *      an API for various container classses( e.g., std::string, std::vector, std::set, and std::map)
 *      iterators(e.g., std::vector<double> ::iterator) and generic algoritms
 *      (e.g., std::sort, std::for_each and std::set_union) 
 */



#include<iostream>
#include<vector>


void PrintVector( const std::vector<float> & vec)
{

    std::vector<float>::const_iterator *it;
    for(*it = vec.begin(); *it!= vec.end();++it)
    {
        std::cout<<*it<<std::endl;
        std::co
    }
}



/* Image APIs. Gone are the days when develoeps needed to write their own image reading and 
 * writing routines. There is now a wide range of open fsource packages out ther for you to download
 * and use in your own programs. For example, there's the popular libjpeg library
 * that provides an implementation fo a JPEG/JFIF decoder and encoder. 
 * There's the extensive ligtiff library for reading and writing various flavours of TIFF files. 
 * And there's the libpng library for handling PNG format images. 
 * Alol of these libraries deinfe API thaat let you write code to read and write the image formats wihout having to know anyhting about the underlying file
 * formats themselves. 
 *
 

 */


TIFF *tif = TIFFOpen( "image.tiff", "r");
if(tif)
{
    uint32 w,h;
    TIFFGetField( tif, TIFFTAG_IMAGEWIDTH, &w);
    TIFFGetField( tif, TIFFTAG_IMAGELENGTH, &h);
    printf("Imagesize = %d x %d pixels\n ", w,h);
    TIFFClose(tif);
}

/* 3d Graphics API . The two clasic real-time, 3d graphics, APIs are OpenGL and Direct X 
 * These let you define 3d objects in therms of small primitives, such as triangles or polygons;
 * specify the surface properties of those primitives, such as color, normal, 
 * and texture; and define the environment conditions, such as lights, fog, and clipping panes. 
 * Thanks to standard APIs such as these, game develoeprs can write 3d games that will work 
 * on graphics cards old and new, from many different manufacturers. Thath's because each graphics 
 * card manufactureer distributes drivers that provide the implementation details behind the 
 * OpenGL or DIrextX API. Before the widespread use of these APIs, a developer had to write a work on 
 * another machine with differnt graphics hardware, these APIs also enable a host of higher -lvelv scenen graph APIs, 
 * such as OpenSceneGraph, OPenSG and OGRE. THe following
 * code segment shows the classic example of rendering a traingle, wih a different color for each vertex, 
 * suing the OPenGL API:
 *
 *
 */


glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,1.0); /*blue*/
    glVertex2i(0,0);
    glColor3f(0.0,1.0,0.0); /*green*/
    glVertex2i(200,200);
    glColor3f(1.0,0.0,0.0);/* red */
    glVertex2i(20,200);
glEnd();
glFlush();


/* Graphical User Interface APIs : any application that wants to open its own window needs to use a GUI toolkit. 
 * This  is an API that provides the ability to create windoes, buttons, text field, dialogs, icons, menus, and so on. 
 * The API will normally also provide an event model to allow the capturing of mouse and keyboard events. 
 * Some popular C/c++ GUI APIs include the wxWidgets library, NOkia's Qt API, GTK+ and X/Motif. It used to be the case that if a company
 * wanted to release an application on more than one platform, such as Windows and Mac, 
 * they would have to rewrite the user interface code using a differnt GUI API for each platform or they would
 * have to rewrite the user interface code using a differnt GUI API for each platform 
 * As a sample of a modern cross-platform GUI API, the following complete program shows a bare minimum QT program 
 * that pops up a window with a Hello World button 
 *
 */


#include<QApplication>
#include<QPushButton>
int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    QPushButtonhello("HelloWorld");
    hello.resize(100,30);
    hello.show();
    return app.exec();
}





