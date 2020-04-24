/*
** EPITECH PROJECT, 2019
** INCLUDE // RECEPTION
** File description:
** ArgumentsHandler.cpp
*/

#include "ArgumentsHandler.hpp"

namespace Plazza
{

    int ArgumentsHandler::run(int ac, char **av) noexcept
    {
        int i = 0;
        float f = 0;

        if (ac != 4) {
            std::cerr << "Wrong number of arguments" << std::endl;
            return (84);
        }
        if (!isType(f, av[1]) || !isType(i, av[2]) || !isType(i, av[3])) {
            std::cerr << "Wrong type - Arguments might integers" << std::endl;
            return (84);
        }
        return (0);
    }

}