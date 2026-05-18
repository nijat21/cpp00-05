#include "Contact.hpp"
#include "utils.hpp"
#include <iomanip>
#include <iostream>
#include <string>

Contact::Contact() {
    first_name = "";
    last_name = "";
    nickname = "";
    phone_number = "";
    darkest_secret = "";
}

Contact::Contact(ContactInput c) {
    if (!(c.first_name.size() && c.last_name.size() && c.nickname.size() && c.phone_number.size() &&
          c.darkest_secret.size()))
        return;
    first_name = c.first_name;
    last_name = c.last_name;
    nickname = c.nickname;
    phone_number = c.phone_number;
    darkest_secret = c.darkest_secret;
}

Contact::~Contact() {}

void Contact::print_contact(size_t i) {
    std::cout << "|" << std::right << std::setw(10) << i << "|" << std::right << std::setw(10)
              << concat_longer(first_name) << "|" << std::right << std::setw(10)
              << concat_longer(last_name) << "|" << std::right << std::setw(10)
              << concat_longer(nickname) << "|" << std::endl;
}
