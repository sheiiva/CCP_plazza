/*
** EPITECH PROJECT, 2019
** SOURCES
** File description:
** main.cpp
*/

#include "Reception.hpp"
#include "ArgumentsHandler.hpp"

using namespace Plazza;

int main(int ac, char **av)
{
    int status = ArgumentsHandler::check(ac, av);
    
    if (status != SUCCESS)
        return ((status == FAILURE) ? FAILURE : SUCCESS);
    return (Reception::start(strtof(av[1], NULL), atoi(av[2]), atoi(av[3])));
}