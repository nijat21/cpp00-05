#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

struct ContactInput {
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
};

class Contact {
  public:
    Contact();
    Contact(ContactInput c);
    ~Contact();
    void print_contact(size_t i);

  private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
};

#endif
