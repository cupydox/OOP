#include "../include/rectangle.h"
#include <cmath>

Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

std::pair<double, double> Rectangle::Center() const {
    return {width / 2.0, height / 2.0};
}

Rectangle::operator double() const {
    return width * height;
}

Figure& Rectangle::operator=(const Figure& other) {
    if (const Rectangle* rect = dynamic_cast<const Rectangle*>(&other)) {
        if (this != rect) { 
            width = rect->width;
            height = rect->height;
        }
    }
    return *this;
}

Figure& Rectangle::operator=(Figure&& other) noexcept {
    if (Rectangle* rect = dynamic_cast<Rectangle*>(&other)) {
        if (this != rect) {
            width = std::move(rect->width);
            height = std::move(rect->height);
            rect->width = 0;
            rect->height = 0;
        }
    }
    return *this;
}

bool Rectangle::operator==(const Figure& other) const {
    if (const Rectangle* otherRectangle = dynamic_cast<const Rectangle*>(&other)) {
        return std::fabs(width - otherRectangle->width) < 1e-6 &&
               std::fabs(height - otherRectangle->height) < 1e-6;
    }
    return false;
}


std::istream& Rectangle::operator>>(std::istream& is) {
    is >> width >> height;
    return is;
}

std::ostream& Rectangle::operator<<(std::ostream& os) const {
    os << "Rectangle: width = " << width << ", height = " << height;
    return os; 
}