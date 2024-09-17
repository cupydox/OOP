#include <gtest/gtest.h>
#include "../include/turkish.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(turkish_number(1)=="bir");
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(turkish_number(13)=="on üç");
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(turkish_number(27)=="yirmi yedi");
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(turkish_number(77)=="yetmiş yedi");
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(turkish_number(94)=="doksan dört");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}