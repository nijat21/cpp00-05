#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Point &src) {
    *this = src;
}

Point &Point::operator=(const Point &rhs) {
    if (this != &rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
    }
    return (*this);
}

Point::~Point() {}

Point::Point(const float x, const float y) {
    this->x = Fixed(x);
    this->y = Fixed(y);
}

// Get float values
float Point::getFloatX() const {
    return x.toFloat();
}
float Point::getFloatY() const {
    return y.toFloat();
}
