#include <gtest/gtest.h>
#include "../include/rectangle.h"
#include "../include/rhombus.h"
#include "../include/trapezoid.h"

TEST(RectangleTest, Equality) {
    Rectangle rect1(3.0, 4.0);
    Rectangle rect2(3.0, 4.0);
    EXPECT_TRUE(rect1 == rect2);
}

TEST(RhombusTest, Equality) {
    Rhombus rhombus1(5.0, 5.0);
    Rhombus rhombus2(5.0, 5.0);
    EXPECT_TRUE(rhombus1 == rhombus2);
}

TEST(TrapezoidTest, Equality) {
    Trapezoid trapezoid1(5.0, 7.0, 4.0);
    Trapezoid trapezoid2(5.0, 7.0, 4.0);
    EXPECT_TRUE(trapezoid1 == trapezoid2);
}

// Тесты на площадь
TEST(RectangleTest, Area) {
    Rectangle rect(3.0, 4.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(rect), 12.0);
}

TEST(RhombusTest, Area) {
    Rhombus rhombus(5.0, 5.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(rhombus), 12.5); 
}

TEST(TrapezoidTest, Area) {
    Trapezoid trapezoid(5.0, 7.0, 4.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(trapezoid), 24.0); 
}


TEST(RectangleTest, CopyAssignment) {
    Rectangle rect1(3.0, 4.0);
    Rectangle rect2;
    rect2 = rect1; 
    EXPECT_TRUE(rect1 == rect2);
}

TEST(RhombusTest, CopyAssignment) {
    Rhombus rhombus1(5.0, 5.0);
    Rhombus rhombus2;
    rhombus2 = rhombus1; 
    EXPECT_TRUE(rhombus1 == rhombus2);
}

TEST(TrapezoidTest, CopyAssignment) {
    Trapezoid trapezoid1(5.0, 7.0, 4.0);
    Trapezoid trapezoid2;
    trapezoid2 = trapezoid1;
    EXPECT_TRUE(trapezoid1 == trapezoid2);
}

