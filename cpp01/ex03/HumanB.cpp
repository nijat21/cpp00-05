#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string str) : name(str) {}

void HumanB::setWeapon(Weapon &weapon) {
    wp = &weapon;
    std::cout << "Adress of club HumanB -> " << wp << std::endl;
}

void HumanB::attack() {
    std::cout << name << " attacks with their " << wp->getType() << std::endl;
}

HumanB::~HumanB() {
    std::cout << "HumanB destroyed" << std::endl;
}
