#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    int n = 6;
    const Animal *meta[20];

    for (int i = 0; i < n; i++) {
        std::cout << "---------------------------------------------------------" << std::endl;
        if (i < n / 2)
            meta[i] = new Dog;
        else
            meta[i] = new Cat;
    }

    for (int i = 0; i < n; i++) {
        std::cout << "---------------------------------------------------------" << std::endl;
        std::cout << meta[i]->getType() << " " << std::endl;
        meta[i]->makeSound();
        meta[i]->showIdeas();
    }

    for (int i = 0; i < n; i++) {
        std::cout << "---------------------------------------------------------" << std::endl;
        delete meta[i];
    }

    std::cout << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Deep copy test" << std::endl;

    std::cout << "---------------------------------------------------------" << std::endl;
    const Dog *d = new Dog;
    const Cat *c = new Cat;

    std::cout << "---------------------------------------------------------" << std::endl;
    const Animal *dcp = new Dog(*d);
    const Animal *ccp = new Cat(*c);

    std::cout << "---------------------------------------------------------" << std::endl;
    delete d;
    delete c;

    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << dcp->getType() << " id: " << dcp->getId() << std::endl;
    dcp->makeSound();
    dcp->showIdeas();

    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << ccp->getType() << " id: " << ccp->getId() << std::endl;
    ccp->makeSound();
    ccp->showIdeas();

    std::cout << "---------------------------------------------------------" << std::endl;
    delete dcp;
    delete ccp;

    std::cout << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Abstract Animal creation test" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    const Animal a;

    return 0;
}
