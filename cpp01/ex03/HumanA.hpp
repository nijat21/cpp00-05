#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
  public:
    HumanA(const std::string str, Weapon &weapon);
    ~HumanA();

    void attack();

  private:
    std::string name;
    const Weapon &wp;
};

#endif
