#include "casepasswordvalidator.h"

CasePasswordValidator::CasePasswordValidator()
{

}

bool CasePasswordValidator::validate(std::string_view password)
{
    if(!PasswordValidatorDecorator::validate(password))
    {


    }

}
