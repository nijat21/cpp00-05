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

Zombie::Zombie(const std::string str) : name(str) {
	std::cout << name << " created" << std::endl;
}

void Zombie::setName(const std::string str){
	std::cout << "naming zombie: " << zIndex << std::endl;
	name = str;
    	named++;
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
