#pragma once
#include "figure.h"

template <class T>
class Trapezoid : public Figure<T> {
private:
    T base1, base2, height;

public:
    Trapezoid(T b1 = 0, T b2 = 0, T h = 0);
    std::pair<T, T> Center() const override;
    operator double() const override;
    Figure<T>& operator=(const Figure<T>& other) override;
    Figure<T>& operator=(Figure<T>&& other) noexcept override;
    bool operator==(const Figure<T>& other) const override;

    std::istream& operator>>(std::istream& is) override;
    std::ostream& operator<<(std::ostream& os) const override;
};
