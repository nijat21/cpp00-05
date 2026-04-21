#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(std::string str) {
    name = str;
}

Zombie::~Zombie() {
    std::cout << name << " destroyed" << std::endl;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
