#include "../include/rhombus.h"
#include <cmath>

Rhombus::Rhombus(double d1, double d2) : diagonal1(d1), diagonal2(d2) {}

std::pair<double, double> Rhombus::Center() const {
    return { diagonal1 / 2.0, diagonal2 / 2.0 };
}

Rhombus::operator double() const {
    return (diagonal1 * diagonal2) / 2.0;
}

Figure& Rhombus::operator=(const Figure& other) {
    if (const Rhombus* rhombus = dynamic_cast<const Rhombus*>(&other)) {
        if (this != rhombus) {
            diagonal1 = rhombus->diagonal1;
            diagonal2 = rhombus->diagonal2;
        }
    }
    return *this;
}

Figure& Rhombus::operator=(Figure&& other) noexcept {
    if (Rhombus* rhombus = dynamic_cast<Rhombus*>(&other)) {
        if (this != rhombus) {
            diagonal1 = std::move(rhombus->diagonal1);
            diagonal2 = std::move(rhombus->diagonal2);
            rhombus->diagonal1 = 0; 
            rhombus->diagonal2 = 0;
        }
    }
    return *this;
}

bool Rhombus::operator==(const Figure& other) const {
    if (const Rhombus* otherRhombus = dynamic_cast<const Rhombus*>(&other)) {
        return std::fabs(diagonal1 - otherRhombus->diagonal1) < 1e-6 &&
               std::fabs(diagonal2 - otherRhombus->diagonal2) < 1e-6;
    }
    return false;
}

std::istream& Rhombus::operator>>(std::istream& is) {
    is >> diagonal1 >> diagonal2;
    return is;
}

std::ostream& Rhombus::operator<<(std::ostream& os) const {
    os << "Rhombus: diagonal1 = " << diagonal1 << ", diagonal2 = " << diagonal2;
    return os;
}