#include "replacer.hpp"

int main(int ac, char **av) {
    if (ac != 4) {
        std::cerr << "Arguments must be: ./sed <filename> <string1> <string2>" << std::endl;
        return 1;
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    if (filename.empty() || s1.empty()) {
        std::cerr << "Arguments must be valid strings" << std::endl;
        return 1;
    }
    if (replace_substr(filename, s1, s2))
        return 1;

    return 0;
}