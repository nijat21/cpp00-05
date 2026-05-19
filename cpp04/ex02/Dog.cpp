#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

int Dog::count = 0;

Dog::Dog() : Animal() {
    type = "Dog";
    count++;
    id = count;
    brain = new Brain(type, id);
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src), id(src.id) {
    std::cout << "Dog copy constructor called" << std::endl;
    type = src.type;
    brain = new Brain(*src.brain);
}

Dog &Dog::operator=(const Dog &rhs) {
    if (this != &rhs) {
        Animal::operator=(rhs);
        id = rhs.id;
        delete brain;
        brain = new Brain(*rhs.brain);
    }
    return (*this);
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const {
    std::cout << "WOOF WOOF" << std::endl;
}

std::string Dog::getType() const {
    return "Dog";
}

void Dog::showIdeas() const {
    for (int i = 0; i < 100; i++)
        std::cout << brain->ideas[i] << std::endl;
}

int Dog::getId() const {
    return id;
}
