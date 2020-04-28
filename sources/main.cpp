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
    int status = Plazza::ArgumentsHandler::check(ac, av);
    
    if (status != 0)
        return ((status == 84) ? 84 : 0);
    Plazza::Reception reception(strtof(av[1], NULL), atoi(av[2]), atoi(av[3]));

    return (reception.run());
}