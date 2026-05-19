#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "iostream"

int main() {
    std::cout << "-----------------------------------------------------------------------"
              << std::endl;
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "-----------------------------------------------------------------------\n"
              << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice()); // -> will return error message as there's no slot

    std::cout << "-----------------------------------------------------------------------\n"
              << std::endl;
    Character *super = new Character("super");

    super->equip(src->createMateria("ice"));
    super->equip(src->createMateria("cure"));
    super->equip(src->createMateria("ice"));
    super->equip(src->createMateria("cure"));
    super->equip(src->createMateria("ice")); // -> will return error superssage as there's no slot

    std::cout << "-----------------------------------------------------------------------\n"
              << std::endl;
    super->showInv();

    std::cout << "-----------------------------------------------------------------------\n"
              << std::endl;
    super->unequip(0);
    super->unequip(0); // -> error as it's already unequipped
    super->unequip(1);
    super->unequip(2);
    super->unequip(3);
    super->unequip(4); // -> error doesn't exist

    std::cout << "-----------------------------------------------------------------------\n"
              << std::endl;
    super->showInv();

    delete bob;
    delete me;
    delete src;
    delete super;

    // Delete unequipped buffer

    return 0;
}
