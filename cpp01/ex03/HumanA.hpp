#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
  public:
    HumanA(std::string str, Weapon &weapon);
    ~HumanA();

    void attack();

  private:
    std::string name;
    const Weapon &wp;
};

#endif
