#pragma once
#include "figure.h"

template <class T>
class Rhombus : public Figure<T> {
private:
    T diagonal1, diagonal2;

public:
    Rhombus(T d1 = 0, T d2 = 0);
    std::pair<T, T> Center() const override;
    operator double() const override;
    Figure<T>& operator=(const Figure<T>& other) override;
    Figure<T>& operator=(Figure<T>&& other) noexcept override;
    bool operator==(const Figure<T>& other) const override;

    std::istream& operator>>(std::istream& is) override;
    std::ostream& operator<<(std::ostream& os) const override;
};
