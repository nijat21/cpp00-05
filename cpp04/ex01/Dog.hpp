#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
  public:
    Dog();
    Dog(const Dog &src);
    Dog &operator=(const Dog &rhs);
    ~Dog();

    void makeSound() const;
    std::string getType() const;
    void showIdeas() const;
    int getId() const;

  private:
    static int count;
    int id;
    Brain *brain;
};

#endif
