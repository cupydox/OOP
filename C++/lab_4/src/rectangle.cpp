#include "../include/rectangle.h"

template <class T>
Rectangle<T>::Rectangle(T w, T h) : width(w), height(h) {}

template <class T>
std::pair<T, T> Rectangle<T>::Center() const {
    return {width / 2.0, height / 2.0};
}

template <class T>
Rectangle<T>::operator double() const {
    return width * height;
}

template <class T>
Figure<T>& Rectangle<T>::operator=(const Figure<T>& other) {
    if (const Rectangle<T>* rect = dynamic_cast<const Rectangle<T>*>(&other)) {
        if (this != rect) {
            width = rect->width;
            height = rect->height;
        }
    }
    return *this;
}

template <class T>
Figure<T>& Rectangle<T>::operator=(Figure<T>&& other) noexcept {
    if (Rectangle<T>* rect = dynamic_cast<Rectangle<T>*>(&other)) {
        if (this != rect) {
            width = std::move(rect->width);
            height = std::move(rect->height);
            rect->width = 0;
            rect->height = 0;
        }
    }
    return *this;
}

template <class T>
bool Rectangle<T>::operator==(const Figure<T>& other) const {
    if (const Rectangle<T>* otherRectangle = dynamic_cast<const Rectangle<T>*>(&other)) {
        return width == otherRectangle->width && height == otherRectangle->height;
    }
    return false;
}

template <class T>
std::istream& Rectangle<T>::operator>>(std::istream& is) {
    is >> width >> height;
    return is;
}

template <class T>
std::ostream& Rectangle<T>::operator<<(std::ostream& os) const {
    os << "Rectangle: width = " << width << ", height = " << height;
    return os;
}

template class Rectangle<int>;
template class Rectangle<double>;
