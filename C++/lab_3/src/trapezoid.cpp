#include "../include/trapezoid.h"
#include <cmath>

Trapezoid::Trapezoid(double b1, double b2, double h) : base1(b1), base2(b2), height(h) {}

std::pair<double, double> Trapezoid::Center() const {
    return {base1 / 2.0, height / 2.0};
}

Trapezoid::operator double() const {
    return (base1 + base2) * height / 2.0;
}

Figure& Trapezoid::operator=(const Figure& other) {
    if (const Trapezoid* trapezoid = dynamic_cast<const Trapezoid*>(&other)) {
        if (this != trapezoid) {
            base1 = trapezoid->base1;
            base2 = trapezoid->base2;
            height = trapezoid->height;
        }
    }
    return *this;
}

Figure& Trapezoid::operator=(Figure&& other) noexcept {
    if (Trapezoid* trapezoid = dynamic_cast<Trapezoid*>(&other)) {
        if (this != trapezoid) {
            base1 = std::move(trapezoid->base1);
            base2 = std::move(trapezoid->base2);
            height = std::move(trapezoid->height);
            trapezoid->base1 = 0;
            trapezoid->base2 = 0;
            trapezoid->height = 0;
        }
    }
    return *this;
}

bool Trapezoid::operator==(const Figure& other) const {
    if (const Trapezoid* otherTrapezoid = dynamic_cast<const Trapezoid*>(&other)) {
        return std::fabs(base1 - otherTrapezoid->base1) < 1e-6 &&
               std::fabs(base2 - otherTrapezoid->base2) < 1e-6 &&
               std::fabs(height - otherTrapezoid->height) < 1e-6;
    }
    return false; 
}

std::istream& Trapezoid::operator>>(std::istream& is) {
    is >> base1 >> base2 >> height;
    return is;
}

std::ostream& Trapezoid::operator<<(std::ostream& os) const {
    os << "Trapezoid: base1 = " << base1 << ", base2 = " << base2 << ", height = " << height;
    return os;
}