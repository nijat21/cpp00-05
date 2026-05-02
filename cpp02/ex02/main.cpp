#include "Fixed.hpp"
#include <iostream>

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    return 0;
}

/*
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
*/

// int main(void) {
//     Fixed a;
//     Fixed const b(Fixed(5.05f) * Fixed(2));
//     Fixed c;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "++a: " << ++a << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "a++: " << a++ << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "b: " << b << std::endl;
//     std::cout << "c: " << c << std::endl;
//     std::cout << "--c: " << --c << std::endl;
//     std::cout << "c: " << c << std::endl;
//     std::cout << "c--: " << c-- << std::endl;
//     std::cout << "c: " << c << std::endl;
//     std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
//     std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
//     std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;
//     std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
//     std::cout << std::endl;

//     a = Fixed(20);
//     c = Fixed(40);
//     std::cout << "a and c play betting game!" << std::endl;
//     std::cout << "Whoever guessed larger number wins" << std::endl;
//     std::cout << "a's guess: " << a << std::endl;
//     std::cout << "c's guess: " << c << std::endl;
//     Fixed::min(a, c) = Fixed::min(a, c) - 10;
//     Fixed::max(a, c) = Fixed::max(a, c) + 10;
//     std::cout << "game: a lost!" << std::endl;
//     std::cout << "a's balance: " << a << std::endl;
//     std::cout << "c's balance: " << c << std::endl;
//     std::cout << std::endl;

//     a = Fixed(10);
//     c = Fixed(20);
//     std::cout << "If they guessed a number not larger than 20, they win 10" << std::endl;
//     std::cout << "a's guess: " << a << std::endl;
//     std::cout << "c's guess: " << c << std::endl;
//     if (a <= 20 && c <= 20) {
//         a = a + 10;
//         c = c + 10;
//     }
//     std::cout << "game: both won!" << std::endl;
//     std::cout << "a's balance: " << a << std::endl;
//     std::cout << "c's balance: " << c << std::endl;
//     std::cout << std::endl;

//     std::cout << "If they guessed different numbers, they win 10" << std::endl;
//     std::cout << "a's guess: " << a << std::endl;
//     std::cout << "c's guess: " << c << std::endl;
//     if (a != c) {
//         a = a + 10;
//         c = c + 10;
//     }
//     std::cout << "game: both won!" << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "c: " << c << std::endl;
//     std::cout << std::endl;

//     std::cout << "If they guess the same number, they win 10" << std::endl;
//     std::cout << "a's guess: " << a << std::endl;
//     std::cout << "c's guess: " << c << std::endl;
//     if (a == c) {
//         a = a + 10;
//         c = c + 10;
//     } else {
//         a = a - 10;
//         c = c - 10;
//     }
//     std::cout << "game: both lost!" << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "c: " << c << std::endl;
//     std::cout << std::endl;

//     return 0;
// }