struct shape
{
    virtual string str() const = 0;
};

struct Circle:Shape
{
    float radius;

    Circle(float radius):radius(radius){}

    void resize(float factor)
    {
        radius * = factor;
    }

    string str() const override
    {
        ostringstream oss;
        oss<<"A Circle of radius " << radius;
        return oss.str();
    }
};

struct Square:Shape
{
    float side;
    Square(float side) : side(side) {}

    Square() {}


    string str() const override
    {
        ostringstream oss;
        oss<<"A circle of radius " << radius;
        return oss.str();
    }
};


struct ColoredShape:Shape
{
    Shape & shape;
    string color ;

    ColoredShape( Shape & shape, const string & color) : shape(shape),color(color){}
    string str() const override
    {
        ostringstream oss;
        os<<shape.str()<<" has the color " << color;
        return oss.str();
    }
};

int main()
{
    Square square{5};
    ColoredShaped red_square{square, "red"};
    std::cout<<square<<std::endl<<red_square<<std::endl;

    struct Square:Shape
    {
        float side;
        Square(float side) : side(side) {}

        Square() {{}


            string str() const override
            {
                ostringstream oss;
                oss<<"A circle of radius " << radius;
                return oss.str();
            }
        };


        struct ColoredShape:Shape
        {
            Shape & shape;
            string color ;

            ColoredShape( Shape & shape, const string & color) : shape(shape),color(color){}
            string str() const override
            {
                ostringstream oss;
                os<<shape.str()<<" has the color " << color;
                return oss.str();
            }
        };

        struct TransparentShape : Shape
        {
            Shape & shape;
            uint8_t transparency;
            TransparentShape( Shape & shape, uint8_t transparency) : shape(shape), 
            transparency(transparency) {}
            string str() const override
            {
                ostringstream oss;
                oss<<shape.str()<<"has"<<static_cast<float> (transparency)/255.f*100.f

                    <<"% transparency";
               return oss.str();
            }
        };


        int main()
        {
            Square square{5};
            ColoredShaped red_square{square, "red"};
            std::cout<<square.str()<<std::endl<<red_square.str()<<std::endl;
            
            TransparentShape my_square{req_square,51};
            std::cout<<my_square().str()<<std::endl;
            //instead of square we have a circle 
            //if we look at the definition of circle we have a member called resize
            //as soon as you decorate it you are restricted by the decorater it implements
            //dynamic decorator doesn't allow you to access the underlying api unless it is a 
            //prt of interface

        }
    

