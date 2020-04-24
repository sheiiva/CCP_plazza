/*
** EPITECH PROJECT, 2019
** INCLUDE // KITCHEN
** File description:
** Parser.hpp
*/

#ifndef PARSER_HPP
#define PARSER_HPP

#include <algorithm>
#include <queue>
#include <iostream>
#include <sstream>
#include <iterator>
#include <map>
#include <string>
#include "Pizza.hpp"

namespace Plazza
{
    #define PIZZANAME   0
    #define SIZE        1
    #define NUMBER      2

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
            int run(const std::string &input, std::queue<Pizza> _orders,
                    std::vector<std::string> stock, std::map<std::string, Pizza> menu) noexcept;

        private:
            void addIngredientToStock(std::string command, std::vector<std::string> stock);

            void addItem(std::string command, std::vector<std::string> stock,
                                            std::map<std::string, Pizza> menu);

            void addPizzaToMenu(std::string command, std::vector<std::string> stock,
                                                    std::map<std::string, Pizza> menu);

            void addPizzatoOrder(std::string command, std::queue<Pizza> orders,
                                                    std::map<std::string, Pizza> menu);

            int getIngredient(std::string ingredient, std::vector<std::string> stock) noexcept;

            bool isValidSize(const std::string &inputSize) noexcept;

            bool isValidName(const std::string &inputName, std::map<std::string, Pizza> menu) noexcept;

            size_t isValidNbr(const std::string &inputNbr) noexcept;

    };

}

#endif /* !PARSER_HPP */