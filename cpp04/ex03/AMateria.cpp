#include "AMateria.hpp"
#include <iostream>
#include <string>

AMateria::AMateria(std::string const &type) : type(type) {
    /* std::cout << "Materia constructed for " << type << std::endl; */
}

AMateria::AMateria(const AMateria &src) : type(src.type) {
    /* std::cout << "Materia copied" << std::endl; */
}

AMateria &AMateria::operator=(const AMateria &rhs) {
    /* std::cout << "Materia assigned" << std::endl; */
    (void)rhs;
    return (*this);
}

AMateria::~AMateria() {
    /* std::cout << "Materia destructed for " << type << std::endl; */
}

std::string const &AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter &target) {
    /* std::cout << "AMateria " << type << " targetting: " << target.getName() << std::endl; */
    (void)target;
}
