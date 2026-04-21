#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av) {
    if (ac != 2)
        return 1;
    std::string level = av[1];
    Harl a;
    a.complain(level);
}

// int main() {
//     Harl a;
//     a.complain("DEBUG");
//     a.complain("INFO");
//     a.complain("WARNING");
//     a.complain("ERROR");
//     std::cout << std::endl;
//     a.complain("invalid");
//     a.complain("INVALID");
// }