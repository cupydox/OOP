#pragma once
#include <iostream>
#include <memory>
#include <type_traits>

template <class T>
concept Scalar = std::is_arithmetic_v<T>; 

template <class T>
class Point {
public:
    T x, y;

    Point(T x = T(), T y = T());
    Point& operator=(const Point& other);
    Point& operator=(Point&& other) noexcept;
};
