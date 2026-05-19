#include "Cure.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

Cure::Cure() : AMateria("cure")
{
	/* std::cout << "Cure constructed" << std::endl; */
}

Cure::Cure(const Cure &src) : AMateria(src) {
	/* std::cout << "Cure copied" << std::endl; */
}

Cure &Cure::operator=(const Cure &rhs)
{
    if (this != &rhs)
    {
	    AMateria::operator=(rhs);
    }
    /* std::cout << "Cure assigned" << std::endl; */
    return (*this);
}

Cure::~Cure()
{
	/* std::cout << "Cure destructed" << std::endl; */
}

Cure* Cure::clone() const {
	/* std::cout << "Cure cloned" << std::endl; */
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() <<"'s wounds *" << std::endl;
}
