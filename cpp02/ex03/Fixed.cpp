#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <limits>

Fixed::Fixed() {
    // std::cout << "Default contructor called" << std::endl;
    fixedPoint = 0;
}

Fixed::Fixed(const Fixed &src) {
    // std::cout << "Copy contructor called" << std::endl;
    this->fixedPoint = src.fixedPoint;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->fixedPoint = rhs.fixedPoint;
    }
    return (*this);
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

// raw value of fixedPoint
int Fixed::getRawBits(void) const {
    std::cout << "getRawBite member function called" << std::endl;
    return fixedPoint;
};

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBite member function called" << std::endl;
    fixedPoint = raw;
};

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
    // std::cout << "Int contructor called" << std::endl;
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
    // std::cout << "Float contructor called" << std::endl;
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

// << overload
std::ostream &operator<<(std::ostream &out, const Fixed &obj) {
    return out << obj.toFloat();
}

// • The 6 comparison operators: >, <, >=, <=, ==, and !=.
bool Fixed::operator==(const Fixed &other) const {
    return fixedPoint == other.fixedPoint;
}
bool Fixed::operator<(const Fixed &other) const {
    return fixedPoint < other.fixedPoint;
}
bool Fixed::operator!=(const Fixed &other) const {
    return !(*this == other);
}
bool Fixed::operator>(const Fixed &other) const {
    return other < *this;
}
bool Fixed::operator>=(const Fixed &other) const {
    return !(*this < other);
}
bool Fixed::operator<=(const Fixed &other) const {
    return !(*this > other);
}

// • The 4 arithmetic operators: +, -, *, and /.
Fixed Fixed::operator+(const Fixed &other) const {
    Fixed temp = *this;
    temp.fixedPoint += other.fixedPoint;
    return temp;
}
Fixed Fixed::operator-(const Fixed &other) const {
    Fixed temp = *this;
    temp.fixedPoint -= other.fixedPoint;
    return temp;
}
/*
    WHY TO INT?
    - when converting to fixed-point -> intA*(1 << 8) * floatB*(1 << 8) -> intA*256 * intB*256
    - when we multiply two objs fixed-points, now we have -> intA*IntB*(256^2)
    - we are saving new value to *this obj, it can't have double scaling *(256^2) but *256 only
    - and that will be comverted to float when printing
*/
Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result.fixedPoint =
        static_cast<int>(static_cast<double>(fixedPoint) * other.fixedPoint / (1 << 8));
    return result;
}
Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    result.fixedPoint =
        static_cast<int>(static_cast<double>(fixedPoint) / other.fixedPoint * (1 << 8));
    return result;
}

/*
    • The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
    post-decrement) operators, which will increase or decrease the fixed-point value by
    the smallest representable ϵ, such that 1 + ϵ > 1.

    e = 1/2^8 => 0,00390625
*/
Fixed &Fixed::operator++() {
    fixedPoint += 1;
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed old = *this;
    operator++();
    return old;
}
Fixed &Fixed::operator--() {
    fixedPoint -= 1;
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed old = *this;
    operator--();
    return old;
}

/*  • A static member function min that takes two references to fixed-point numbers as
parameters, and returns a reference to the smallest one. */
/*
    IN NON-CONST VERSIONS, ASSIGNMENT BY REFERENCE POSSIBLE
        Game: two players, whoever has less HP takes damage
        Fixed::min(player1.hp, player2.hp) -= damage;
*/
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return a.fixedPoint < b.fixedPoint ? a : b;
}
/* • A static member function min that takes two references to constant fixed-point
numbers as parameters, and returns a reference to the smallest one. */
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return a.fixedPoint < b.fixedPoint ? a : b;
}
/* • A static member function max that takes two references to fixed-point numbers as
parameters, and returns a reference to the greatest one. */
Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return a.fixedPoint > b.fixedPoint ? a : b;
}
/* • A static member function max that takes two references to constant fixed-point
numbers as parameters, and returns a reference to the greatest one. */
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return a.fixedPoint > b.fixedPoint ? a : b;
}
