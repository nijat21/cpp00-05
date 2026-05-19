#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
  public:
    Cat();
    Cat(const Cat &src);
    Cat &operator=(const Cat &rhs);
    ~Cat();

    std::string getType() const;
    void makeSound() const;
    void showIdeas() const;
    int getId() const;

  private:
    static int count;
    int id;
    Brain *brain;
};

#endif
