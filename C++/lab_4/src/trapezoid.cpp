#include "../include/trapezoid.h"

template <class T>
Trapezoid<T>::Trapezoid(T b1, T b2, T h) : base1(b1), base2(b2), height(h) {}

template <class T>
std::pair<T, T> Trapezoid<T>::Center() const {
    return {(base1 + base2) / 2.0, height / 2.0};
}

template <class T>
Trapezoid<T>::operator double() const {
    return (base1 + base2) * height / 2.0;  
}

template <class T>
Figure<T>& Trapezoid<T>::operator=(const Figure<T>& other) {
    if (const Trapezoid<T>* trap = dynamic_cast<const Trapezoid<T>*>(&other)) {
        if (this != trap) {
            base1 = trap->base1;
            base2 = trap->base2;
            height = trap->height;
        }
    }
    return *this;
}

template <class T>
Figure<T>& Trapezoid<T>::operator=(Figure<T>&& other) noexcept {
    if (Trapezoid<T>* trap = dynamic_cast<Trapezoid<T>*>(&other)) {
        if (this != trap) {
            base1 = std::move(trap->base1);
            base2 = std::move(trap->base2);
            height = std::move(trap->height);
            trap->base1 = 0;
            trap->base2 = 0;
            trap->height = 0;
        }
    }
    return *this;
}

template <class T>
bool Trapezoid<T>::operator==(const Figure<T>& other) const {
    if (const Trapezoid<T>* otherTrapezoid = dynamic_cast<const Trapezoid<T>*>(&other)) {
        return base1 == otherTrapezoid->base1 && base2 == otherTrapezoid->base2 && height == otherTrapezoid->height;
    }
    return false;
}

template <class T>
std::istream& Trapezoid<T>::operator>>(std::istream& is) {
    is >> base1 >> base2 >> height;
    return is;
}

template <class T>
std::ostream& Trapezoid<T>::operator<<(std::ostream& os) const {
    os << "Trapezoid: base1 = " << base1 << ", base2 = " << base2 << ", height = " << height;
    return os;
}

template class Trapezoid<int>;
template class Trapezoid<double>;
