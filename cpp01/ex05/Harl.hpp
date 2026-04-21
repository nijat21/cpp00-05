#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
  public:
    Harl();
    ~Harl();

    void complain(std::string level);

  private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    /*
        void (Harl::*func)(); -> Harl::*func tells compiler three things:
            1. Function pointer belongs to class Harl
            2. Needs an instance of Harl class to be called outside of class
            3. Needs an object <this> to be called inside class
    */
    struct Pair {
        std::string level;
        void (Harl::*func)();
    };
};

#endif
