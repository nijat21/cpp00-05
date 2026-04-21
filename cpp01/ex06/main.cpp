#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Progam must run as -> ./harlFilter <LEVEL>" << std::endl;
        return 1;
    }
    std::string level = av[1];
    Harl a;
    a.complain(level);
}

// int main() {
//     Harl a;
//     std::cout << "--------------------------------------------------" << std::endl;
//     std::cout << "1. TEST ERROR" << std::endl;
//     std::cout << "--------------------------------------------------" << std::endl;
//     a.complain("ERROR");

//     std::cout << "--------------------------------------------------" << std::endl;
//     std::cout << "2. TEST WARNING" << std::endl;
//     std::cout << "--------------------------------------------------" << std::endl;
//     a.complain("WARNING");

//     std::cout << "--------------------------------------------------" << std::endl;
//     std::cout << "3. TEST INFO" << std::endl;
//     std::cout << "--------------------------------------------------" << std::endl;
//     a.complain("INFO");

//     std::cout << "--------------------------------------------------" << std::endl;
//     std::cout << "4. TEST DEBUG" << std::endl;
//     std::cout << "--------------------------------------------------" << std::endl;
//     a.complain("DEBUG");

//     std::cout << "--------------------------------------------------" << std::endl;
//     std::cout << "5. TEST INVALID" << std::endl;
//     std::cout << "--------------------------------------------------" << std::endl;
//     a.complain("invalid");
//     a.complain("INVALID");
// }