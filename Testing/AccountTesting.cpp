#include<iostream>
#include<gtest/gtest.h>
#include "Account.h"

TEST(BankAccount, test1)
{
    BankAccount instance;
    instance.deposit(100);
    EXPECT_EQ(100,instance.balance);

}


int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc,argv);
    return  RUN_ALL_TESTS();
}

