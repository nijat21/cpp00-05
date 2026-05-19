#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int Cat::count = 0;

Cat::Cat() : Animal() {
    type = "Cat";
    count++;
    id = count;
    brain = new Brain(type, id);
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src), id(src.id) {
    std::cout << "Cat copy constructor called" << std::endl;
    type = src.type;
    brain = new Brain(*src.brain);
}

Cat &Cat::operator=(const Cat &rhs) {
    if (this != &rhs) {
        Animal::operator=(rhs);
        id = rhs.id;
        delete brain;
        brain = new Brain(*rhs.brain);
    }
    return (*this);
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const {
    std::cout << "MEOW MEOW" << std::endl;
}

std::string Cat::getType() const {
    return "Cat";
}

void Cat::showIdeas() const {
    for (int i = 0; i < 100; i++)
        std::cout << brain->ideas[i] << std::endl;
}

int Cat::getId() const {
    return id;
}
