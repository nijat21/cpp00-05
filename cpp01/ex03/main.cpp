#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

#include <iostream>

int main() {
    {
        Weapon club = Weapon("crude spiked club");
        std::cout << "Adress of club before A -> " << &club << std::endl;
        HumanA bob("Bob", club);
        std::cout << "--------------------------------------------------------" << std::endl;
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
        std::cout << "--------------------------------------------------------" << std::endl;
    }
    {
        std::cout << "--------------------------------------------------------" << std::endl;
        Weapon club = Weapon("crude spiked club");
        std::cout << "Adress of club before B -> " << &club << std::endl;
        HumanB jim("Jim");
        jim.setWeapon(club);
        std::cout << "--------------------------------------------------------" << std::endl;
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
        std::cout << "--------------------------------------------------------" << std::endl;
    }
    return 0;
}
