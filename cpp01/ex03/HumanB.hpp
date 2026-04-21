#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
  public:
    HumanB(std::string str);
    ~HumanB();

    void setWeapon(Weapon &wp);
    void attack();

  private:
    std::string name;
    const Weapon *wp;
};

#endif
