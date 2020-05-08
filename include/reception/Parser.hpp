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
#include <map>
#include <queue>
#include <sstream>
#include <string>

#include "ArgumentsHandler.hpp"
#include "Pizza.hpp"

namespace Plazza
{
    enum INPUT {
        PIZZANAME   = 0,
        SIZE        = 1,
        NUMBER      = 2
    };

    enum OUTPUT {
        NOACTION        = 0,
        HELP            = 1,
        COMMAND         = 2,
        STATUS          = 3,
        QUIT            = 4
    };

    class Parser
    {
        public:
            Parser() noexcept = default;
            Parser(const Parser &b) noexcept = default;
            Parser(Parser &&b) noexcept = default;
            ~Parser() noexcept = default;

            Parser &operator=(const Parser &rhs) noexcept = delete;
            Parser &operator=(Parser &&rhs) noexcept = delete;

        public:
            int run(const std::string &input,
                    std::queue<Pizza> &_orders,
                    std::map<std::string, Pizza> &menu);

        private:
            bool isValidSize(std::string const& inputSize) const noexcept;
            bool isValidName(std::string const& inputName, std::map<std::string, Pizza> menu) const noexcept;
            size_t isValidNbr(const std::string &inputNbr) const noexcept;
            bool addPizzatoOrder(std::vector<std::string> parsedInput, size_t sep,
                                        std::queue<Pizza> &orders, 
                                        std::map<std::string, Pizza> menu);

            int getIngredient(std::string ingredient, std::vector<std::string> stock) noexcept;
    };

}

#endif /* !PARSER_HPP */