#ifndef CASEPASSWORDVALIDATOR_H
#define CASEPASSWORDVALIDATOR_H
#include "passwordvalidatordecorator.h"


class CasePasswordValidator final: public PasswordValidatorDecorator
{
public:
    CasePasswordValidator();
};

#endif // CASEPASSWORDVALIDATOR_H
