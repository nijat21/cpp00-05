#include "replacer.hpp"

int update_line(std::string &line, const std::string &s1, const std::string &s2, bool &found) {
    if (s1.empty())
        return 1;
    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos) {
        line =
            line.substr(0, pos) + s2 + line.substr(pos + s1.size()); // maybe erase, check for leaks
        pos += s2.size();
        found = true;
    }
    return 0;
}

int replace_substr(const std::string &filename, const std::string &s1, const std::string &s2) {
    std::ifstream input(filename);
    if (!input) {
        std::cerr << "File couldn't be opened" << std::endl;
        return 1;
    }
    std::ofstream output(filename + ".replace");
    if (!output) {
        std::cerr << "File couldn't be created/opened" << std::endl;
        return 1;
    }
    std::string line;
    bool found = false;
    while (std::getline(input, line)) {
        if (update_line(line, s1, s2, found)) {
            std::cerr << "Replacement failed" << std::endl;
            return 1;
        }
        output << line << std::endl;
    }
    if (!found)
        std::cout << "No such string in file" << std::endl;
    return 0;
}