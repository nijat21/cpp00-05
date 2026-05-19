#include "Ice.hpp"
#include <string>
#include <iostream>

Ice::Ice() : AMateria("ice")
{
	/* std::cout << "Ice constructor called" << std::endl; */
}

Ice::Ice(const Ice &src) : AMateria(src)
{
	/* std::cout << "Ice copy operator called" << std::endl; */
}

Ice &Ice::operator=(const Ice &rhs)
{
    if (this != &rhs)
    {
	    AMateria::operator=(rhs);
    }
    /* std::cout << "Ice assignment operator called" << std::endl; */
    return (*this);
}

Ice::~Ice()
{
	/* std::cout << "Ice destructor called" << std::endl; */
}

Ice* Ice::clone() const {
	/* std::cout << "Ice cloned" << std::endl; */
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() <<" *" << std::endl;
}

