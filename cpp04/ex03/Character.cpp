#include "Character.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>

Character::Character(std::string name) : name(name), uneqCount(0) {
    // std::cout << "Caracter constructed" << std::endl;
    invInit(inv, 4);
    invInit(uneqInv, 100);
}

Character::Character(const Character &src) : name(src.name), uneqCount(src.uneqCount) {
    // std::cout << "Caracter copy constructed" << std::endl;
    clearCopyInv(inv, src.inv, 4); // src.inv -> AMateria* const* inv
    clearCopyInv(uneqInv, src.uneqInv, 100);
}

Character &Character::operator=(const Character &rhs) {
    // std::cout << "Caracter copy assigned" << std::endl;
    if (this != &rhs) {
        clearCopyInv(inv, rhs.inv, 4);
        clearCopyInv(uneqInv, rhs.uneqInv, 100);
        uneqCount = rhs.uneqCount;
        name = rhs.name;
    }
    return (*this);
}

Character::~Character() {
    // std::cout << "Caracter destructed" << std::endl;
    clearInv(inv, 4);
    clearInv(uneqInv, 100);
}

std::string const &Character::getName() const {
    return name;
}

void Character::equip(AMateria *m) {
    if (!m) {
        std::cerr << "Materia is invalid" << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!inv[i]) {
            inv[i] = m;
            std::cout << "Materia: " << i << " equipped" << std::endl;
            return;
        }
    }
    delete m;
    std::cout << "No slot for Materia" << std::endl;
}

void Character::unequip(int idx) {
    if (idx < 0 || !inv[idx]) {
        std::cerr << "No such inventory" << std::endl;
        return;
    } else {
        std::cout << "Materia: " << idx << " unequipped" << std::endl;
        uneqInv[uneqCount] = inv[idx];
        uneqCount++;
        inv[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target) {
    std::cout << name << " " << std::flush;
    inv[idx]->use(target);
}

void Character::showInv() const {
    int i = -1;

    std::cout << "Inventory: " << std::endl;
    while (inv[++i])
        std::cout << inv[i]->getType() << std::endl;
    std::cout << "Unequipped Inventory: " << std::endl;
    while (uneqInv[++i])
        std::cout << uneqInv[i]->getType() << std::endl;
}
