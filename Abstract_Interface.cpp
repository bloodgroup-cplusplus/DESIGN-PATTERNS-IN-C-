#include<iostream>

class CurrencyConverter
{
    public:
        virtual ~CurrencyConverter() {}
        virtual long double getConversionFactor () const = 0;
};



class RealtimeCurrencyConversionService : public CurrencyConvertor
{
    virtual long double getConversionFacotr() const override
    {
        // ... write your code here 
        // 
    };


int main()
{
	return 0;
}

