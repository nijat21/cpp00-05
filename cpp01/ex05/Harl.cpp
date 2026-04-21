#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl() {}

void Harl::debug() {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup "
                 "burger. I really do!"
              << std::endl;
};

void Harl::info() {
    std::cout << "I cannot believe adding extra bacon costs more money.\n"
                 "You didn’t put enough bacon in my burger!\n"
                 "If you did, I wouldn’t be asking for more!"
              << std::endl;
};

void Harl::warning() {
    std::cout << "I think I deserve to have some extra bacon for free.\n"
                 "I’ve been coming for years, whereas you started working here just last month."
              << std::endl;
};

void Harl::error() {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
};

void Harl::complain(std::string level) {
    Pair table[4] = {{"DEBUG", &Harl::debug},
                     {"INFO", &Harl::info},
                     {"WARNING", &Harl::warning},
                     {"ERROR", &Harl::error}};

    for (int i = 0; i < 4; i++) {
        if (table[i].level == level) {
            std::cout << "[" << table[i].level << "]" << std::endl;
            (this->*table[i].func)();
            return;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
};

Harl::~Harl() {}
