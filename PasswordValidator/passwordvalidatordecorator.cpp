#include "passwordvalidatordecorator.h"

PasswordValidatorDecorator::PasswordValidatorDecorator()
{

}

bool PasswordValidatorDecorator::validate(std::string_view password)
{

    return inner->validate(password);
}
