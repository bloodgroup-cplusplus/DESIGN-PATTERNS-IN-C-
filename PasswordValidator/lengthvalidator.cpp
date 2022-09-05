#include "lengthvalidator.h"

LengthValidator::LengthValidator()
{

}



bool LengthValidator::validate(std::string_view password)
{
    return  password.length() >= length;

}
