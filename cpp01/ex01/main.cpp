#include "Zombie.hpp"
#include <cstdlib>
#include <iostream>

int main(int ac, char **av) {
    int N;
    std::string name;

    if (ac != 3) {
        std::cerr << "Arguments must be: ./horde <number> <name>" << std::endl;
        return 1;
    }
    N = std::atoi(av[1]);
    if (N <= 0) {
        std::cerr << "Invalid number" << std::endl;
        return 1;
    }
    name = av[2];
    if (name.empty()) {
        std::cerr << "Invalid name" << std::endl;
        return 1;
    }

    Zombie *zombies = zombieHorde(N, name);
    for (int i = 0; i < N; i++) {
        zombies[i].announce();
    }
    Zombie::showSummary();
    delete[] zombies;
}