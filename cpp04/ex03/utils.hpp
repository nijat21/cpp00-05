#ifndef UTILS_HPP
#define UTILS_HPP

#include "AMateria.hpp"

void invInit(AMateria **m, int n);
void clearInv(AMateria *const *m, int n);
void copyInv(AMateria **dst, AMateria *const *src, int n);
void clearCopyInv(AMateria **dst, AMateria *const *src, int n);

#endif
