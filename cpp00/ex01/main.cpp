#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

static std::string consume_spaces(std::string str) {
    std::string res;
    for (size_t i = 0; i < str.size(); i++) {
        if (std::isspace(static_cast<unsigned char>(str[i])))
            continue;
        res += str[i];
    }
    return res;
}

static bool ask_field(const std::string &label, std::string &out) {
    std::cout << std::left << std::setw(16) << label << ": ";
    if (!std::getline(std::cin, out) || out.empty())
        return false;
    return true;
}

static ContactInput *fill_in(ContactInput *inp) {
    bool succ = true;
    if (!ask_field("First name", inp->first_name))
        succ = false;
    if (!ask_field("Last name", inp->last_name))
        succ = false;
    if (!ask_field("Nickname", inp->nickname))
        succ = false;
    if (!ask_field("Phone number", inp->phone_number))
        succ = false;
    inp->phone_number = consume_spaces(inp->phone_number);
    if (!is_phone_number(inp->phone_number))
        succ = false;
    if (!ask_field("Darkest secret", inp->darkest_secret))
        succ = false;
    if (!succ)
        return NULL;
    return inp;
}

static void handle_add(PhoneBook *book) {
    ContactInput input;

    if (!fill_in(&input))
        return;
    Contact new_con(input);
    (*book).add(new_con);
}

static bool handle_search(PhoneBook *book) {
    (*book).print_contacts();
    std::string line;
    std::cout << "INDEX: " << std::flush;
    if (!std::getline(std::cin, line)) { //|| line.empty() || !is_number(line)) {
        if (!is_number(line))
            std::cerr << "Index isn't a valid number" << std::endl;
        else
            std::cerr << "Getline error" << std::endl;
        return false;
    }
    int temp_num = std::atoi(line.c_str());
    if (temp_num < 0) {
        std::cerr << "Index can't be negative" << std::endl;
        return false;
    }
    size_t num = temp_num;
    if (num >= (*book).get_count()) {
        std::cerr << "Index larger than phonebook size" << std::endl;
        return false;
    }
    (*book).print_search_results(num);
    return true;
}

int main(int ac, char **av) {
    PhoneBook book;
    if (ac != 1)
        return 1;
    (void)av;
    std::string line;
    while (1) {
        std::cout << "PROMPT (ADD, SEARCH, EXIT): " << std::flush;
        if (!std::getline(std::cin, line))
            return 0;
        if (line.empty())
            continue;
        line = concat_spaces(line);
        if (line.empty())
            continue;
        if (to_lower(line) == "add") {
            handle_add(&book);
            std::cout << std::endl;
        } else if (to_lower(line) == "search") {
            handle_search(&book);
            std::cout << std::endl;
        } else if (to_lower(line) == "exit")
            return 0;
        else
            continue;
    }
}
