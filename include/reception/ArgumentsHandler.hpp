/*
** EPITECH PROJECT, 2019
** INCLUDE // RECEPTION
** File description:
** ArgumentsHandler.hpp
*/

#ifndef ARGUMENTSHANDLER_HPP
#define ARGUMENTSHANDLER_HPP

#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

namespace Plazza
{

    class ArgumentsHandler
    {
        private:
            ArgumentsHandler() noexcept = default;
            ArgumentsHandler(const ArgumentsHandler &b) noexcept = default;
            ArgumentsHandler(ArgumentsHandler &&b) noexcept = default;
            ~ArgumentsHandler() noexcept = default;
    
            ArgumentsHandler &operator=(const ArgumentsHandler &rhs) noexcept = default;
            ArgumentsHandler &operator=(ArgumentsHandler &&rhs) noexcept = default;
    
        private:

            bool isFloat(const std::string &nb);

            bool isInt(const std::string &nb);

            int run(int ac, char **av) noexcept;

        public:

            static int check(int ac, char **av) noexcept
            {
                ArgumentsHandler argumentsHandler;

                return argumentsHandler.run(ac, av);
            }
    };

}

#endif /* !ARGUMENTSHANDLER_HPP */