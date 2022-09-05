#include <iostream>
#include "digitpasswordvalidator.h"
#include "lengthvalidator.h"


int main()
{
    auto validator1 = std::make_unique<DigitPasswordValidator>(
                std::make_unique<LengthValidator>(8));
    assert(validator1->validate("abc123!@#"));
    assert(!validator1->validate("abcde!@#"));
    std::cout << "Hello World!" << std::endl;
    return 0;
}
