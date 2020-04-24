/*
** EPITECH PROJECT, 2019
** SOURCES
** File description:
** main.cpp
*/

#include "Reception.hpp"
#include "ArgumentsHandler.hpp"

int main(int ac, char **av)
{
    if (Plazza::ArgumentsHandler::check(ac, av) == 84)
        return (84);
    Plazza::Reception reception(atof(av[1]), atoi(av[2]), atoi(av[3]));

    return (reception.run());
}