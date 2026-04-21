#include "Zombie.hpp"
#include <string>

void randomChump(std::string name) {
    Zombie a(name);
    a.announce();
}