#include "Fixed.hpp"
#include <iostream>

int main(void) {
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);
    Fixed const f(9000000);
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "f is " << f << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    std::cout << "f is " << f.toInt() << " as integer" << std::endl;
    return 0;
}

// int main() {
//     /*
//         Our fixed-point  -> decimal range   [-8,388,608 , 8,388,607]
//                         -> fraction range  [0, 0.99609375]

//     */
//     Fixed const a(9000000);
//     Fixed const b(-9000000);
//     Fixed const c(0.1f);
//     Fixed const d(0.001f);
//     Fixed const e(42.42f);
//     std::cout << "a is " << a << std::endl;
//     std::cout << "b is " << b << std::endl;
//     std::cout << "c is " << c << std::endl;
//     std::cout << "d is " << d << std::endl;
//     std::cout << "e is " << e << std::endl;
//     std::cout << "a is " << a.toInt() << " as integer" << std::endl;
//     std::cout << "b is " << b.toInt() << " as integer" << std::endl;
//     std::cout << "c is " << c.toInt() << " as integer" << std::endl;
//     std::cout << "d is " << d.toInt() << " as integer" << std::endl;
//     std::cout << "e is " << e.toInt() << " as integer" << std::endl;
// }
