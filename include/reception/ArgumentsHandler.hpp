/*
** EPITECH PROJECT, 2019
** INCLUDE // RECEPTION
** File description:
** ArgumentsHandler.hpp
*/

#ifndef ARGUMENTSHANDLER_HPP
    #define ARGUMENTSHANDLER_HPP

    #include <string.h>
    #include <stdlib.h>
    #include <iostream>
    #include <string>
    #include <sstream>

    #include "Usage.hpp"

    namespace Plazza
    {

        class ArgumentsHandler
        {
            private:
                ArgumentsHandler() noexcept = default;
                ArgumentsHandler(ArgumentsHandler const& b) noexcept = default;
                ArgumentsHandler(ArgumentsHandler&& b) noexcept = default;
                ~ArgumentsHandler() noexcept = default;
        
                ArgumentsHandler &operator=(ArgumentsHandler const& rhs) noexcept = default;
                ArgumentsHandler &operator=(ArgumentsHandler&& rhs) noexcept = default;
        
            private:
                int run(int ac, char **av) noexcept;

            public:
                template <typename Type>
                static bool isType(Type ret, std::string const& nb)
                {
                    std::istringstream iss(nb);

                    iss >> ret;
                    return (iss.eof() && !iss.fail());   
                }

                static int check(int ac, char **av) noexcept
                {
                    ArgumentsHandler argumentsHandler;

                    return (argumentsHandler.run(ac, av));
                }
        };

    }

#endif /* !ARGUMENTSHANDLER_HPP */