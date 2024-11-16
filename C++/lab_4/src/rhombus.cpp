#include "../include/rhombus.h"

template <class T>
Rhombus<T>::Rhombus(T d1, T d2) : diagonal1(d1), diagonal2(d2) {}

template <class T>
std::pair<T, T> Rhombus<T>::Center() const {
    return {diagonal1 / 2.0, diagonal2 / 2.0};
}

template <class T>
Rhombus<T>::operator double() const {
    return (diagonal1 * diagonal2) / 2.0;  
}

template <class T>
Figure<T>& Rhombus<T>::operator=(const Figure<T>& other) {
    if (const Rhombus<T>* rhomb = dynamic_cast<const Rhombus<T>*>(&other)) {
        if (this != rhomb) {
            diagonal1 = rhomb->diagonal1;
            diagonal2 = rhomb->diagonal2;
        }
    }
    return *this;
}

template <class T>
Figure<T>& Rhombus<T>::operator=(Figure<T>&& other) noexcept {
    if (Rhombus<T>* rhomb = dynamic_cast<Rhombus<T>*>(&other)) {
        if (this != rhomb) {
            diagonal1 = std::move(rhomb->diagonal1);
            diagonal2 = std::move(rhomb->diagonal2);
            rhomb->diagonal1 = 0;
            rhomb->diagonal2 = 0;
        }
    }
    return *this;
}

template <class T>
bool Rhombus<T>::operator==(const Figure<T>& other) const {
    if (const Rhombus<T>* otherRhombus = dynamic_cast<const Rhombus<T>*>(&other)) {
        return diagonal1 == otherRhombus->diagonal1 && diagonal2 == otherRhombus->diagonal2;
    }
    return false;
}

template <class T>
std::istream& Rhombus<T>::operator>>(std::istream& is) {
    is >> diagonal1 >> diagonal2;
    return is;
}

template <class T>
std::ostream& Rhombus<T>::operator<<(std::ostream& os) const {
    os << "Rhombus: diagonal1 = " << diagonal1 << ", diagonal2 = " << diagonal2;
    return os;
}

template class Rhombus<int>;
template class Rhombus<double>;
