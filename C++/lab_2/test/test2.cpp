#include <gtest/gtest.h>
#include "../include/three.h"

TEST(ThreeTest, DefaultConstructor) {
    Three s;
    EXPECT_TRUE(s == Three("0"));
}


TEST(ThreeTest, ParametrConstructor) {
    Three s(5, '1');
    EXPECT_TRUE(s == Three("11111"));
}


TEST(ThreeTest, StringConstructor) {
    Three s("222");
    EXPECT_TRUE(s == Three(3, '2'));
}


TEST(ThreeTest, InitConstructor) {
    Three s({'0', '1', '2'});
    EXPECT_TRUE(s == Three("012"));
}


TEST(ThreeTest, CopyConstructor) {
    Three s1("121");
    Three s2(s1);
    EXPECT_TRUE(s2 == s1); 
}


TEST(ThreeTest, AddOperator) {
    Three s1("112");
    Three s2("111");
    Three result = s1 + s2;
    EXPECT_TRUE(result == Three("2201"));
}


TEST(ThreeTest, SubOperator) {
    Three s1("221");
    Three s2("111");
    Three result = s1 - s2;
    EXPECT_TRUE(result == Three("110"));
}


TEST(ThreeTest, MoreOperator) {
    Three s1("221");
    Three s2("120");
    EXPECT_TRUE(s1 > s2);
}


TEST(ThreeTest, LessThanOperator) {
    Three s1("011");
    Three s2("111");
    EXPECT_TRUE(s1 < s2);
}


TEST(ThreeTest, EqualOperator) {
    Three s1("221");
    Three s2("221");
    EXPECT_TRUE(s1 == s2); 
}


TEST(ThreeTest, AssignmentOperator) {
    Three s1("112");
    Three s2 = s1;
    EXPECT_TRUE(s2 == s1); 
}


TEST(ThreeTest, AddAssignOperator) {
    Three s1("111");
    Three s2("101");
    s1 += s2;
    EXPECT_TRUE(s1 == Three("212"));
}


TEST(ThreeTest, SubAssignOperator) {
    Three s1("221");
    Three s2("111");
    s1 -= s2;
    EXPECT_TRUE(s1 == Three("110"));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
