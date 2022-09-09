#ifndef SYMBOLPASSWORDVALIDATOR_H
#define SYMBOLPASSWORDVALIDATOR_H
#include "ipasswordvalidate.h"
#include "passwordvalidatordecorator.h"


class SymbolPasswordValidator final: public PasswordValidatorDecorator
{
public:
    SymbolPasswordValidator();
    explicit SymbolPasswordValidator(
            std::unique_ptr<password_validator> validator):
        PasswordValidatorDecorator(std::move(validator))
    {}
    virtual bool validate(std::string_view password) override ;
};

#endif // SYMBOLPASSWORDVALIDATOR_H
