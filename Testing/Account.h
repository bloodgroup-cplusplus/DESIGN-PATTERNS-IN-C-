#include<iostream>
class BankAccount
{
    public:
        int balance = 0;
        void deposit ( int amount)
        {
            balance+= amount;
        }

        void deduction (int amount)
        {
            balance-= amount;
        }
};



