#ifndef LENGTHVALIDATOR_H
#define LENGTHVALIDATOR_H
#include "ipasswordvalidate.h"


class LengthValidator final: public password_validator
{
public:
    LengthValidator();
    LengthValidator(unsigned int min_length):length(min_length){}
    virtual bool validate(std::string view_password) override;

private:
    unsigned int length;
};

#endif // LENGTHVALIDATOR_H
