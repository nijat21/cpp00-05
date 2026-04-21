#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string str, Weapon &weapon) : name(str), wp(weapon) {
    std::cout << "Adress of club HumanA -> " << &wp << std::endl;
}

void HumanA::attack() {
    std::cout << name << " attacks with their " << wp.getType() << std::endl;
}

HumanA::~HumanA() {
    std::cout << "HumanA destroyed" << std::endl;
}
