#include "Zombie.hpp"
#include <string>

void randomChump(const std::string name) {
    Zombie a(name);
    a.announce();
}
