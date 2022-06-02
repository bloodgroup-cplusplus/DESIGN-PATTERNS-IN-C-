#ifndef Order_h
#define Order_h

#include "Customer.h"


class Order
{
    private:
        Customer m_customer;
        // each order is related with one customer 
        // we can create a solid object of customer inside ordere
        // the lifetime of customer object 
        // by placing the customer as a solid object inside
        // order class 
        // makes the customer the true part of the order
        // solid objects as members
        // Advantages
        //  Goes out of scope with the object
        //  Simpler memory management
        //  Drawbacks
        //  Increases size of owning object
        //  Cannot be optional
        //  No polymorphism
        //

    public:
        Order(Customer customer) :m_customer(customer)
    {
    }


        std::string print_summary()
        {
            return "Order by:"+m_customer.name();
        }
};


#endif /*Order_h*/

