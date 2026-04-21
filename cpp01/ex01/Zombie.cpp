#include "Zombie.hpp"
#include <iostream>
#include <string>

int Zombie::created = 0;
int Zombie::named = 0;
int Zombie::announced = 0;

Zombie::Zombie() {
    zIndex = created;
    created++;
    std::cout << "allocating zombie: " << zIndex << std::endl;
};

void Zombie::setName(std::string str) {
    named++;
    std::cout << "naming zombie: " << zIndex << std::endl;
    name = str;
}

void Zombie::showSummary() {
    std::cout << "SUMMARY =============== allocated: " << created << "; named:" << named
              << "; announced: " << announced << "; ===============" << std::endl;
}

void Zombie::announce() {
    announced++;
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << " destroyed" << std::endl;
}
