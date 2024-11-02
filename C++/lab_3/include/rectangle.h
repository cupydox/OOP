#pragma once 
#include "figure.h"

class Rectangle: public Figure {
    private:
        double width, height;
    
    public:
        Rectangle(double w = 0, double h = 0);
        
        std::pair<double, double> Center() const override;
        operator double() const override;

        Figure& operator=(const Figure& other) override;
        Figure& operator=(Figure&& other) noexcept override;
        bool operator==(const Figure& other) const override;

        std::istream& operator>>(std::istream& is) override;
        std::ostream& operator<<(std::ostream& os) const override;
};