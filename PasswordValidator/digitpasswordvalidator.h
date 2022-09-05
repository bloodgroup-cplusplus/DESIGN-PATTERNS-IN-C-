#ifndef DIGITPASSWORDVALIDATOR_H
#define DIGITPASSWORDVALIDATOR_H
#include "passwordvalidatordecorator.h"


class DigitPasswordValidator final:public PasswordValidatorDecorator
{
public:
    DigitPasswordValidator();
    explicit DigitPasswordValidator(
            std::unique_ptr<password_validator> validator):
        PasswordValidatorDecorator(std::move(validator)){}
    virtual bool validate(std::string_view password) override;
};

#endif // DIGITPASSWORDVALIDATOR_H
