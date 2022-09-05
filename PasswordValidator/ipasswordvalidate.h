#ifndef IPASSWORDVALIDATE_H
#define IPASSWORDVALIDATE_H
#include<iostream>



class password_validator
{
public:
    virtual bool validate(std::string_view password) = 0;
    virtual ~password_validator() {}
};

#endif // IPASSWORDVALIDATE_H
