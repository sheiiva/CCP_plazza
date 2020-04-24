/*
** EPITECH PROJECT, 2019
** SOURCES
** File description:
** main.cpp
*/

#include "Reception.hpp"

int main(/*int ac, char **av*/)
{
    // size_t args[3];

    // if (ArgumentHandler::checkArgs(&args) == HELP)
    //     return Usage::showUsage();
    // Plazza::Reception reception(args[0], args[1], args[2]);
    Plazza::Reception reception(0, 0, 0);

    return (reception.run());
}