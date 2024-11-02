#include "../include/figure.h"

Figure& Figure::operator=(const Figure& other) {
    return *this;
}

Figure& Figure::operator=(Figure&& other) noexcept {
    return *this;
}

bool Figure::operator==(const Figure& other) const {
    return false; 
}