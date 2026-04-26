#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
  public:
    Fixed();
    Fixed(const Fixed &src);
    Fixed &operator=(const Fixed &rhs);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

  private:
    int fixedPoint;
    static const int fraction = 8;
};

#endif
