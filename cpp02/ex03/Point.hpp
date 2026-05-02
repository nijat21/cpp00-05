#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
  public:
    Point();
    Point(const Point &src);
    Point &operator=(const Point &rhs);
    ~Point();

    Point(const float x, const float y);

    // get float value
    float getFloatX(void) const;
    float getFloatY(void) const;

  private:
    Fixed x;
    Fixed y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
