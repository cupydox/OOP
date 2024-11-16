#include "../include/point.h"

template <class T>
Point<T>::Point(T x, T y) : x(x), y(y) {}

template <class T>
Point<T>& Point<T>::operator=(const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

template <class T>
Point<T>& Point<T>::operator=(Point&& other) noexcept {
    if (this != &other) {
        x = std::move(other.x);
        y = std::move(other.y);
    }
    return *this;
}

template class Point<int>;
template class Point<double>;
