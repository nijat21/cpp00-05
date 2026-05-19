#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include <string>

class AMateria;

class ICharacter {
  public:
    virtual ~ICharacter() {}
    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria *m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter &target) = 0;
};

class Character : public ICharacter {
  public:
    Character(std::string name);
    Character(const Character &src);
    Character &operator=(const Character &rhs);
    ~Character();

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

    void showInv() const;

  private:
    std::string name;
    int uneqCount;
    AMateria *inv[4];
    AMateria *uneqInv[100];
};

#endif
