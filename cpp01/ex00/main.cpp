#include <iostream>
#include <string>
#include "Zombie.hpp"

int main() {
    Zombie *heap_zombie = newZombie("Heap");
    heap_zombie->announce();
    randomChump("Stack");
    delete (heap_zombie);
}
