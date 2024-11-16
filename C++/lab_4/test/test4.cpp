#include <gtest/gtest.h>
#include "../include/rectangle.h"
#include "../include/rhombus.h"
#include "../include/trapezoid.h"

TEST(RectangleTest, AreaCalculation) {
    Rectangle<int> rect(4, 3);
    EXPECT_DOUBLE_EQ(static_cast<double>(rect), 12.0); 
}

TEST(RhombusTest, AreaCalculation) {
    Rhombus<int> rhomb(6, 8);
    EXPECT_DOUBLE_EQ(static_cast<double>(rhomb), 24.0); 
}

TEST(TrapezoidTest, AreaCalculation) {
    Trapezoid<int> trap(4, 6, 4);
    EXPECT_DOUBLE_EQ(static_cast<double>(trap), 20.0); 
}

TEST(TrapezoidTest, EqualityOperator) {
    Trapezoid<int> trap1(4, 6, 4);
    Trapezoid<int> trap2(4, 6, 4);
    EXPECT_TRUE(trap1 == trap2);  

    Trapezoid<int> trap3(5, 7, 5);
    EXPECT_FALSE(trap1 == trap3);  
}

TEST(TrapezoidTest, CopyAssignmentOperator) {
    Trapezoid<int> trap1(4, 6, 4);
    Trapezoid<int> trap2;
    trap2 = trap1;  
    EXPECT_DOUBLE_EQ(static_cast<double>(trap2), 20.0); 
    EXPECT_DOUBLE_EQ(static_cast<double>(trap1), 20.0); 
}

TEST(TrapezoidTest, MoveAssignmentOperator) {
    Trapezoid<int> trap1(4, 6, 4);
    Trapezoid<int> trap2;
    trap2 = std::move(trap1); 
    EXPECT_DOUBLE_EQ(static_cast<double>(trap2), 20.0); 
}

TEST(RhombusTest, EqualityOperator) {
    Rhombus<int> rhombus1(4);
    Rhombus<int> rhombus2(4);
    EXPECT_TRUE(rhombus1 == rhombus2);

    Rhombus<int> rhombus3(5);
    EXPECT_FALSE(rhombus1 == rhombus3); 
}
