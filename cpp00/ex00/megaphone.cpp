/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nismayil <nismayil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 02:29:27 by nismayil          #+#    #+#             */
/*   Updated: 2026/04/01 02:50:00 by nismayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.hpp"
#include <iostream>

/*
    $>./megaphone "shhhhh... I think the students are asleep..."
    SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
    $>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
    DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
    $>./megaphone
    * LOUD AND UNBEARABLE FEEDBACK NOISE *
    $>
*/

Megaphone::Megaphone() {
    msg = "*LOUD AND UNBEARABLE FEEDBACK NOISE *";
}

Megaphone::Megaphone(std::string str) {
    msg = str;
}

Megaphone::~Megaphone() {};

// Const prevents modification of member variables like msg
void Megaphone::showMsg() const {
    std::cout << msg << "\n";
};

std::string capitalize(std::string str) {
    if (!str.size())
        return str;
    for (size_t i = 0; i < str.size(); i++)
        str[i] = std::toupper(str[i]);
    return str;
}

std::string parse_input(int ac, char **av) {
    std::string str;
    if (ac == 1)
        str = "*LOUD AND UNBEARABLE FEEDBACK NOISE *";
    int i = 0;
    while (++i < ac)
        str += capitalize(av[i]);
    return str;
}

int main(int ac, char **av) {
    Megaphone a(parse_input(ac, av));

    a.showMsg();
    return 0;
}