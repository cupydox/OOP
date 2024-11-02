#pragma once 
#include "figure.h"

class Rhombus : public Figure {
private:
    double diagonal1, diagonal2;

public:
    Rhombus(double d1 = 0, double d2 = 0);

    std::pair<double, double> Center() const override;
    operator double() const override;

    Figure& operator=(const Figure& other) override;
    Figure& operator=(Figure&& other) noexcept override;
    bool operator==(const Figure& other) const override;

    std::istream& operator>>(std::istream& is) override;
    std::ostream& operator<<(std::ostream& os) const override;
};