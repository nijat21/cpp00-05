#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <limits>

Fixed::Fixed() {
    std::cout << "Default contructor called" << std::endl;
    fixedPoint = 0;
}

Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy contructor called" << std::endl;
    this->fixedPoint = src.fixedPoint;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->fixedPoint = rhs.fixedPoint;
    }
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

/*
    Convert to fixed-point:
        - int -> 4 bytes -> 32 bits
        - fraction -> 8 bits
        - decimal -> 24 bits
        - this changes limits of INT_MAX / INT_MIN

    num = 5
        - int -> 00000000000000000000000000000101 -> val = 5
        - int << nFracDigs -> 00000000000000000000010100000000 -> val = 2^8 + 2^10 = 2180 -> 2180 *
   2^-8 = 5
        - should  -> 000000000000000000000101.00000000
*/
Fixed::Fixed(const int num) {
    std::cout << "Int contructor called" << std::endl;
    long long temp = static_cast<long long>(num) * (1LL << fraction);
    if (temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min()) {
        std::cerr << "Overflow: fixedPoint resetted to 0" << std::endl;
        fixedPoint = 0;
        return;
    }
    fixedPoint = static_cast<int>(temp);
}

/*
    For float type, overflow for intermediate steps will cause it to be +/-infinity
 */
Fixed::Fixed(const float num) {
    std::cout << "Float contructor called" << std::endl;
    float temp = std::roundf(num * (1 << fraction));
    if (temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min()) {
        std::cerr << "Overflow: fixedPoint resetted to 0" << std::endl;
        fixedPoint = 0;
        return;
    }
    fixedPoint = static_cast<int>(temp);
}

int Fixed::toInt() const {
    return static_cast<int>(fixedPoint) / (1 << fraction);
};

float Fixed::toFloat() const {
    return static_cast<float>(fixedPoint) / (1 << fraction);
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj) {
    return out << obj.toFloat();
}
