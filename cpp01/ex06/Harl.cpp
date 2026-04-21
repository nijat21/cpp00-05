#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl() {}

void Harl::debug() {

    std::cout << "[ DEBUG ]\n"
                 "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup "
                 "burger. I really do!\n"
              << std::endl;
};

void Harl::info() {
    std::cout << "[ INFO ]\n"
                 "I cannot believe adding extra bacon costs more money.\n"
                 "You didn’t put enough bacon in my burger!\n"
                 "If you did, I wouldn’t be asking for more!\n"
              << std::endl;
};

void Harl::warning() {
    std::cout << "[ WARNING ]\n"
                 "I think I deserve to have some extra bacon for free.\n"
                 "I’ve been coming for years, whereas you started working here just last month.\n"
              << std::endl;
};

void Harl::error() {
    std::cout << "[ ERROR ]\n"
                 "This is unacceptable! I want to speak to the manager now.\n"
              << std::endl;
};

void Harl::complain(std::string level) {
    Level lvl = INVALID;
    switch (level[0]) {
    case 'D':
        if (level == "DEBUG")
            lvl = DEBUG;
        break;
    case 'I':
        if (level == "INFO")
            lvl = INFO;
        break;
    case 'W':
        if (level == "WARNING")
            lvl = WARNING;
        break;
    case 'E':
        if (level == "ERROR")
            lvl = ERROR;
        break;
    }

    switch (lvl) {
    case DEBUG:
        (this->*(&Harl::debug))();
        lvl = INFO;
    case INFO:
        (this->*(&Harl::info))();
        lvl = WARNING;
    case WARNING:
        (this->*(&Harl::warning))();
        lvl = ERROR;
    case ERROR:
        (this->*(&Harl::error))();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
};

Harl::~Harl() {}
