#include "utils.hpp"
#include "AMateria.hpp"

void invInit(AMateria **m, int n) {
    for (int i = 0; i < n; i++)
        m[i] = NULL;
}

void clearInv(AMateria *const *m, int n) {
    for (int i = 0; i < n; i++)
        delete m[i];
}

void copyInv(AMateria **dst, AMateria *const *src, int n) {
    for (int i = 0; i < n; i++) {
        if (src[i])
            dst[i] = src[i]->clone();
    }
}

void clearCopyInv(AMateria **dst, AMateria *const *src, int n) {
    clearInv(dst, n);
    invInit(dst, n);
    copyInv(dst, src, n);
}
