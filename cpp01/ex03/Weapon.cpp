#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon() {}

Weapon::Weapon(std::string str) {
    type = str;
}

const std::string &Weapon::getType() const {
    return type;
}

void Weapon::setType(std::string str) {
    type = str;
}

Weapon::~Weapon() {
    std::cout << "Weapon destroyed" << std::endl;
}
