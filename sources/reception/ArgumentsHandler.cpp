/*
** EPITECH PROJECT, 2019
** INCLUDE // RECEPTION
** File description:
** ArgumentsHandler.cpp
*/

#include "ArgumentsHandler.hpp"

namespace Plazza
{

    bool ArgumentsHandler::isFloat(const std::string &nb)
    {
        float ret = 0;
        std::istringstream iss(nb);

        iss >> ret;
        return iss.eof() && !iss.fail();         
    }

    bool ArgumentsHandler::isInt(const std::string &nb)
    {
        int ret = 0;
        std::istringstream iss(nb);

        iss >> ret;
        return iss.eof() && !iss.fail();            
    }

    int ArgumentsHandler::run(int ac, char **av) noexcept
    {
        if (ac != 4) {
            std::cerr << "Wrong number of arguments" << std::endl;
            return (84);
        }
        if (!isFloat(av[1]) || !isInt(av[2]) || !isInt(av[3])) {
            std::cerr << "Wrong type - Arguments might integers" << std::endl;
            return (84);
        }
        return (0);
    }

}