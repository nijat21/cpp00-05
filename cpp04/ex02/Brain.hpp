#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
  public:
    Brain();
    Brain(const std::string &type, const int id);
    Brain(const Brain &src);
    Brain &operator=(const Brain &rhs);
    ~Brain();

    std::string ideas[100];

  private:
    std::string ownerType;
};

#endif
