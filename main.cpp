#include <gtest/gtest.h>
#include "tests/tests.cpp"

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}