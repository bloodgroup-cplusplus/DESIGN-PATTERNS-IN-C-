/* Let's say you are making websites you are making and your manager asks you to filter those
 * products 
 * so let's suppose that each of the products has certain traits
 *
 * we are going to define them as enum 
 */


#include<iostream>
#include<string>
#include<vector>



enum class Color {red,green,blue};

enum class Size {small, medium ,large};
//specification filter 
template<typename T> struct Specification
{
    virtual bool is_satisfied( T *item ) = 0;
    AndSpecification <T> operator &&(Specification<T> && other)
    {
        return AndSpecification<T>(*this, other);
    }

};

//type filter 
template<typename T> struct Filter
// filter is going to define the interface which is implemented by any items
{
    // specify by filter 
    virtual std::vector<T*> filter(std::vector<T*> items,
            Specification<T> & spec) = 0;
};

template<typename T> struct AndSpecification:Specification <T>
{
    Specification<T> & fist;
    Specification<T> & second;
    AndSpecification(Specification<T> & first, Specification<T> & second) :first(first),second(second){}
    bool is_satisfied(T * item) override{
        return first.is_satisfied && second.is_satisfied;
    }
};

// let's build filter of products 
struct BetterFilter:Filter<Product>
{
    std::vector<Product *> filter (std::vector<Product *> items, Specification <Product> &spec)
        override {

            vector<Product *> result;

            for(auto & item : items)
            {
                if (spec.is_satisfied(item))
                    result.push_back(item);


            }


        return result ;
        }
};

    
        


struct Product
{
    std::string name;
    Color color;
    Size size;
};


// if we simply define a filter 
//
struct ProductFilter 
{
    // we can perform filtering on particular criteria 
    // if we are asked to filter by colors 
    // we do something like this 

    std::vector<Product *> by_color(std::vector<Product*> items, Color color)
    {
        std::vector<Product *> result;

        for(auto & i: items)
        {
            // check if it fits the color)
            if(i->color == color)
                result.push_back(i);
        }
        return result;
    }
};

struct ColorSpecification :Specification <Product>
{
    Color color;
    ColorSpecification (Color color) :color(color) {}
    bool is_specified(Product *item) override
    {
        return item->color == color;
    }
};
int main()
{
    //Let's make a simple product 
    //and run our Product Filter 

    Product apple {"Apple", Color::green, Size::small};
    Product tree {"Tree", Color::green, Size::large};
    Product house {"House",Color::blue,Size::large};

    //let's create the products 
    std::vector<Product *> items{ &apple,&tree, &house};
    ProductFilter pf;
    auto green_things = pf.by_color(items, Color::green);
    for(auto & item: green_things)
        std::cout<<item->name<<"is green\n";
    // the above method works perfectly when there are only a few criteria(s) but 
    // the above class was for filtering by colors but what if the manager comes to you and says
    // filter by size as well 
    // Then inside the ProductFilter you would have to create another method 
    // Making the entire task tiring 
    //
    // let's suppose we need to filter by name by color by size by date and many other 
    // criterion 
    // so in that case the above method would be hectic instead we would use the open
    // close principle
    //what if boss comes and says filter by size and color 
    //you would have to make changes in the shipped code as well
    //this is once again it is a problematic
    //we would have 2**criteria functions
    // your system should be open for extension and  and closed for modification 
    //
    //let's do this using templates 
    //open for extension and closed for modification 
    BetterFilter bf;
    ColorSpecification green(Color::green);


    for(auto & item :bf.filter(items, green))
        std::cout<<item->name <<"is green\n";

    SizeSpecification large(Size::large);
    AndSpecification<Product> green_and_large(green,large);

    auto spec = ColorSpecification(Color::green) && SizeSpecification(Size::large);

    for(auto & item : bf.filter(items, green_and_large))
        std::cout<<item->name <<"is green and large"<<std::endl;
    return 0;
}

