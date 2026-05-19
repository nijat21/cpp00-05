#include "Brain.hpp"
#include "utils.hpp"
#include <iostream>

Brain::Brain() : ownerType("default") {
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const std::string &type, const int id) : ownerType(type) {
    std::string thought = "";
    std::string idStr = int_to_string(id);
    if (ownerType == "Dog")
        thought = type + idStr + " wants to go for a walk";
    else if (ownerType == "Cat")
        thought = type + idStr + " wants to sleep all day";
    for (int i = 0; i < 100; i++)
        ideas[i] = thought;
    std::cout << "Brain created for " << ownerType << std::endl;
}

Brain::Brain(const Brain &src) {
    *this = src;
}

Brain &Brain::operator=(const Brain &rhs) {
    if (this != &rhs) {
        ownerType = rhs.ownerType;
        for (int i = 0; i < 100; ++i)
            ideas[i] = rhs.ideas[i];
    }
    return (*this);
}

Brain::~Brain() {
    std::cout << "Brain removed from " << ownerType << std::endl;
}
