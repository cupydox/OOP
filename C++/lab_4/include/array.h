#pragma once
#include <memory>

template <class T>
class Array {
private:
    std::shared_ptr<T[]> data;
    size_t size;

public:
    Array(size_t size);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t Size() const;
};
