#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
  public:
    Zombie();
    ~Zombie();

    static int created;
    static int named;
    static int announced;

    void announce();
    void setName(std::string str);

    static void showSummary();

  private:
    int zIndex;
    std::string name;
};

Zombie *zombieHorde(int N, std::string name);

#endif
