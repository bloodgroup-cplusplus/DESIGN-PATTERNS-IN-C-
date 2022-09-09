// the liskov substitution_principle
// the goal is to specify that subtypes should be substiutiable for base types
// how the liskov can be broken 
//


class Rectangle 
{
    protected:
        int width, height; 

    public:
        Rectangle(int width, int height) :width( width), height(height) {}


        int getWidth() const 
        {
            return width;
        }


        virtual void setWidth(int width)
        {
            Rectangle::width = width;
        }

        int getHeight() const 
        {
            return height;
        }


        virtual void setHeight(int height)
        {
            Rectangle::height = height;
        }

        int area() const { return width * height;}


};
// let's form a square and let's customize it let's have a class square that inherits the properties of a rectangle 

class Square : public Rectangle 
{
    //let's suppose we have a constructor 

    //we initialize the rectangle with size being on both size and square 

    Square(int size) : Rectangle (size, size) {}
    void setWidth(int width) override
    {
        this->width = this->height = width ;
    }

    void setHeight(int height) override
    {
        this->width = this->height = height; 


    }

void process (Rectangle & r)
{
    int w = r.getWidth();
    r.setHeight(10);
    std::cout<<"expected area = "<< (w*10)
        <<" got is "<< r.area() << std::endl;
}
int main()
    
{

    Rectangle r(3,4);
    process(r);
    Square sq(10);
    process(sq);
    return 0;
}


