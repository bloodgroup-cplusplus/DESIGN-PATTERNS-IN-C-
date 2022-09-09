#include "../libs/googletest/googletest/include/gtest/gtest.h"
#include "../include/inc.h"

using lib::abs;

TEST( AbsFunction, Functionality)
{
    ASSERT_EQ(abs(50), 50);
    ASSERT_EQ(abs(-50),50);
    ASSERT_EQ(abs(0),0);
}
