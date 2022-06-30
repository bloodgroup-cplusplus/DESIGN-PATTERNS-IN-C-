#include<gtest/gtest.h>
#include "LibraryCode.hpp"

TEST(TestSuiteSample, TestSample)

{
    int sum = sum(2,4);
    ASSERT_EQ(6,sum);
}


int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
