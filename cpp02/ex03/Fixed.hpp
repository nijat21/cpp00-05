#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
class Fixed {
  public:
    Fixed();
    Fixed(const Fixed &src);
    Fixed &operator=(const Fixed &rhs);
    ~Fixed();

    Fixed(const int num);
    Fixed(const float num);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;

    // comparison operators
    bool operator>(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;

    // arithmetic operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // prefix and postfix increment and decrement
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    // min and max
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

  private:
    int fixedPoint;
    static const int fraction = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif
