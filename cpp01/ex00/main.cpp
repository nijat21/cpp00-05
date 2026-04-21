#include "Zombie.hpp"
#include <iostream>
#include <string>

int main() {
    Zombie *heap_zombie = newZombie("Heap");
    heap_zombie->announce();
    randomChump("Stack");
    delete (heap_zombie);
}