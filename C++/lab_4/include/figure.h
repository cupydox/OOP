#pragma once
#include <iostream>
#include <memory>
#include <type_traits>

template <class T>
concept Scalar = std::is_arithmetic_v<T>;

template <class T>
class Figure {
public:
    virtual std::pair<T, T> Center() const = 0;  
    virtual operator double() const = 0;  

    virtual Figure<T>& operator=(const Figure<T>& other) {
        if (this != &other) {
        }
        return *this;
    }

    virtual Figure<T>& operator=(Figure<T>&& other) noexcept {
        if (this != &other) {
        }
        return *this;
    }
    virtual bool operator==(const Figure<T>& other) const = 0;

    virtual std::istream& operator>>(std::istream& is) = 0;
    virtual std::ostream& operator<<(std::ostream& os) const = 0;

    virtual ~Figure() = default;
};
