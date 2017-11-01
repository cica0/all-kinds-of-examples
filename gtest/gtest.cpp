#include <iostream>
#include <assert.h>
#include <gtest/gtest.h>
#include "unit.h"

TEST(Gtest, TestSum)
{
    EXPECT_EQ(2, 1+1);

}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    testing::GTEST_FLAG(output) = "xml:";     
    return RUN_ALL_TESTS();
}

