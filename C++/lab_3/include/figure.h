#pragma once 
#include <iostream>

class Figure {
public:
    virtual std::pair<double, double> Center() const = 0;
    virtual operator double() const = 0;

    virtual Figure& operator=(const Figure& other) = 0;
    virtual Figure& operator=(Figure&& other) noexcept = 0;
    virtual bool operator==(const Figure& other) const = 0;

    virtual std::istream& operator>>(std::istream& is) = 0;
    virtual std::ostream& operator<<(std::ostream& os) const = 0;

    virtual ~Figure() = default;
};