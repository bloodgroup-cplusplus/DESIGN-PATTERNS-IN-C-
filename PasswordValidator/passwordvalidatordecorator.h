#ifndef PASSWORDVALIDATORDECORATOR_H
#define PASSWORDVALIDATORDECORATOR_H
#include "ipasswordvalidate.h"


class PasswordValidatorDecorator: public password_validator
{
public:
    explicit PasswordValidatorDecorator(std::unique_ptr<password_validator>validator):inner(std::move(validator))
    {}
    PasswordValidatorDecorator();
    virtual bool validate(std::string_view password) override;
private:
    std::unique_ptr<password_validator> inner;
};

#endif // PASSWORDVALIDATORDECORATOR_H
