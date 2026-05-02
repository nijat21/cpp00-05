#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

/*
Input: A = (0, 0), B = (10, 30), C = (20, 0)
Triangle:
              B(10,30)
                / \
               /   \
              /     \
             /   P   \      P'
            /         \
     A(0,0) ----------- C(20,0)
Point: P(10, 15) -> inside
Point: P(30, 15) -> outside
Point: P(20, 0) -> vertex
Point: P(11, 27) -> on edge (slope is -3 so 11, 27 is right on the edge)

*/

int main(void) {
    Point A(0.0f, 0.0f);
    Point B(10.0f, 30.0f);
    Point C(20.0f, 0.0f);

    Point inside(10.0f, 15.0f);
    Point outside(30.0f, 15.0f);
    Point vertex(20.0f, 0.0f);
    Point edge(11.0f, 27.0f);
    std::cout << (bsp(A, B, C, inside) ? "true" : "false") << std::endl;
    std::cout << (bsp(A, B, C, outside) ? "true" : "false") << std::endl;
    std::cout << (bsp(A, B, C, vertex) ? "true" : "false") << std::endl;
    std::cout << (bsp(A, B, C, edge) ? "true" : "false") << std::endl;
    return 0;
}
