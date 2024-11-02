#pragma once 
#include "figure.h"

class Trapezoid : public Figure {
private:
    double base1, base2, height;

public:
    Trapezoid(double b1 = 0, double b2 = 0, double h = 0);

    std::pair<double, double> Center() const override;
    operator double() const override;

    Figure& operator=(const Figure& other) override;
    Figure& operator=(Figure&& other) noexcept override;
    bool operator==(const Figure& other) const override;

    std::istream& operator>>(std::istream& is) override;
    std::ostream& operator<<(std::ostream& os) const override;
};
