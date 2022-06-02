
#ifndef Customer_h
#define Customer_h



#include<string>


class Order
{
    private:
        std::string m_name;

    public:
        Customer(std::string name) : m_name(name)
        {

        }



        std::string name()
        {
            return m_name;
        }


};


#endif /*Customer_h*/


