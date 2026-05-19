#include "MateriaSource.hpp"
#include "utils.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    invInit(learned, 4);
}

MateriaSource::MateriaSource(const MateriaSource &src) {
    invInit(learned, 4);
    copyInv(learned, src.learned, 4);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
    if (this != &rhs) {
        clearCopyInv(learned, rhs.learned, 4);
    }
    return (*this);
}

MateriaSource::~MateriaSource() {
    clearInv(learned, 4);
}

void MateriaSource::learnMateria(AMateria *m) {
    if (!m) {
        std::cerr << "Materia is invalid" << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!learned[i]) {
            learned[i] = m;
            std::cout << "Materia " << m->getType() << " is learned" << std::endl;
            return;
        }
    }
    delete m;
    std::cout << "No slot for Materia" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (learned[i] && (learned[i]->getType() == type))
            return learned[i]->clone();
    }
    std::cerr << "Invalid Materia type" << std::endl;
    return 0;
}
