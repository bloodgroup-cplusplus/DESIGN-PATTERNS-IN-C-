#include "digitpasswordvalidator.h"

DigitPasswordValidator::DigitPasswordValidator()
{

}

bool DigitPasswordValidator::validate(std::string_view password)
{
    if(!PasswordValidatorDecorator::validate(password))
    {
        return false;

    }

    return password.find_first_of("0123456789")!= std::string::npos;

}
