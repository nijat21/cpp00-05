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

    float toFloat(void) const;
    int toInt(void) const;

  private:
    int fixedPoint;
    static const int fraction = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif
