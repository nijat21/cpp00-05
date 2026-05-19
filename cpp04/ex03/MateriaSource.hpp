#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include <string>

class IMateriaSource {
  public:
    virtual ~IMateriaSource() {};
    virtual void learnMateria(AMateria *m) = 0;
    virtual AMateria *createMateria(std::string const &type) = 0;
};

class MateriaSource : public IMateriaSource {
  public:
    MateriaSource();
    MateriaSource(const MateriaSource &src);
    MateriaSource &operator=(const MateriaSource &rhs);
    ~MateriaSource();

    virtual void learnMateria(AMateria *m);
    virtual AMateria *createMateria(std::string const &type);

  private:
    AMateria *learned[4];
};

#endif
