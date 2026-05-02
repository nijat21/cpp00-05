#include "Fixed.hpp"
#include "Point.hpp"

/*
    Area aT = [ x1(y2 - y3) + x2(y3 - y1) + x3(y1-y2)]/2
    - Calculate are of triangle abc -> areaT
    2. pab + pac + pbc != areaT -> OUTSIDE
    3. pab + pac + pbc == areaT AND pab/pac/pbc == 0 -> ON EDGE
    3. pab + pac + pbc == areaT AND two of pab/pac/pbc == 0 -> POINT IS VERTEX
*/
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    double areaT = static_cast<double>(a.getFloatX()) * (b.getFloatY() - c.getFloatY()) +
                   b.getFloatX() * (c.getFloatY() - a.getFloatY()) +
                   c.getFloatX() * (a.getFloatY() - b.getFloatY());
    areaT = areaT < 0 ? areaT * (-1) : areaT; // abs() doesn't seem to be authorized

    double pab = static_cast<double>(a.getFloatX()) * (b.getFloatY() - point.getFloatY()) +
                 b.getFloatX() * (point.getFloatY() - a.getFloatY()) +
                 point.getFloatX() * (a.getFloatY() - b.getFloatY());
    pab = pab < 0 ? pab * (-1) : pab;

    double pac = static_cast<double>(a.getFloatX()) * (point.getFloatY() - c.getFloatY()) +
                 point.getFloatX() * (c.getFloatY() - a.getFloatY()) +
                 c.getFloatX() * (a.getFloatY() - point.getFloatY());
    pac = pac < 0 ? pac * (-1) : pac;

    double pbc = static_cast<double>(point.getFloatX()) * (b.getFloatY() - c.getFloatY()) +
                 b.getFloatX() * (c.getFloatY() - point.getFloatY()) +
                 c.getFloatX() * (point.getFloatY() - b.getFloatY());
    pbc = pbc < 0 ? pbc * (-1) : pbc;

    if (((pab + pac + pbc) == areaT)) {
        if (pab == 0 || pac == 0 || pbc == 0) {
            // if ((!pab && !pac) || (!pab && !pbc) || (!pac && !pbc))
            //     std::cout << "VERTEX" << std::endl;
            // else
            //     std::cout << "ON EDGE" << std::endl;
            return false;
        }
        return true;
    }
    return false;
}