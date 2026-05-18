#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(const std::string str) : name(str) {
	std::cout << name << " created" << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << " destroyed" << std::endl;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
