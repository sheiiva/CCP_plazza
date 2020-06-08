/*
** EPITECH PROJECT, 2019
** INCLUDE // KITCHEN
** File description:
** Parser.hpp
*/

#ifndef PARSER_HPP
    #define PARSER_HPP

    #include <algorithm>
    #include <iostream>
    #include <iterator>
    #include <queue>
    #include <map>
    #include <sstream>
    #include <string>

    #include "ArgumentsHandler.hpp"
    #include "Pizza.hpp"

    namespace Plazza
    {
        enum PIZZA_ORDER_FORMAT {
            PIZZANAME,
            SIZE,
            NUMBER,
        };

        enum ACTION {
            NOACTION,
            HELP,
            COMMAND,
            STATUS ,
            QUIT
        };

        class Parser
        {
            public:
                Parser() noexcept = default;
                Parser(Parser const& b) noexcept = default;
                Parser(Parser&& b) noexcept = default;
                ~Parser() noexcept = default;

                Parser &operator=(Parser const& rhs) noexcept = default;
                Parser &operator=(Parser&& rhs) noexcept = default;

            public:
                int run(std::string const& input, std::queue<Pizza>& _orders, std::map<std::string, Pizza>& menu);
                std::vector<std::string> splitInput(std::string const& string, size_t *sep);
                bool isValidPizzaSize(std::string const& inputSize) const noexcept;
                bool isValidPizzaName(std::string const& inputName, std::map<std::string, Pizza> menu) const noexcept;
                size_t isValidNbrFormat(std::string const& inputNbr) const noexcept;
                bool addPizzatoOrder(std::vector<std::string> parsedInput, size_t sep, 
                                    std::queue<Pizza>& orders, std::map<std::string, Pizza> menu);
        };

    }

#endif /* !PARSER_HPP */