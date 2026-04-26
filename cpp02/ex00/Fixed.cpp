#include "Fixed.hpp"
#include <iostream>

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

int Fixed::getRawBits(void) const {
    std::cout << "getRawBite member function called" << std::endl;
    return fixedPoint;
};

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBite member function called" << std::endl;
    fixedPoint = raw;
};
