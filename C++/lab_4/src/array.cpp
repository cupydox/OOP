#include "../include/array.h"
#include "../include/figure.h"

template <class T>
Array<T>::Array(size_t size) : size(size), data(std::make_shared<T[]>(size)) {}

template <class T>
T& Array<T>::operator[](size_t index) {
    return data[index];
}

template <class T>
const T& Array<T>::operator[](size_t index) const {
    return data[index];
}

template <class T>
size_t Array<T>::Size() const {
    return size;
}

template class Array<Figure<int>*>;
template class Array<Figure<double>*>;
