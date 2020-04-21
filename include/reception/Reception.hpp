/*
** EPITECH PROJECT, 2019
** INCLUDE // RECEPTION
** File description:
** Reception.hpp
*/

#ifndef RECEPTION_HPP
#define RECEPTION_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include "Kitchen.hpp"
#include "Pizza.hpp"

namespace Plazza
{
    #define PIZZANAME   0
    #define SIZE        1
    #define NUMBER      2
    class Reception
    {
        public:
            Reception() noexcept = delete;
            Reception(int bakeTimeWeight, int maxCook, int stockRegen) noexcept;
            Reception(Reception const& b) noexcept = delete;
            Reception(Reception&& b) noexcept = delete;
            ~Reception() noexcept = default;
            Reception& operator=(Reception const& rhs) noexcept = delete;
            Reception& operator=(Reception&& rhs) noexcept = delete;

            //GETTERS
            Kitchen& getKitchen(int index) noexcept;
            int getStock(const std::string &ingredient) const noexcept;
            Pizza& getPizza(const std::string &pizzaName) noexcept;
            int getBakeTimeWeight(void) noexcept;
            int getMaxCook(void) noexcept;
            int getStockRegen(void) noexcept;
            //SETTERS
            void setKitchen(Kitchen &kitchen) noexcept;
            //METHODS
            int run() noexcept;
            std::string read_stdin(void) noexcept;
            void parser(const std::string &input) noexcept;
            int assignOrder(void) noexcept;
            int checkKitchen() noexcept;
            bool status() noexcept;
            bool addToStock(const std::string &ingredient) noexcept;
            bool addToMenu(Pizza &pizza) noexcept;
            // Reception& operator<<(Pizza const &pizza) noexcept; // 
            // Reception& operator>>(Reception&& rhs) noexcept;
            bool isValidName(const std::string &inputName);
            size_t isValidNbr(const std::string &inputNbr);
            bool isValidSize(const std::string &inputSize);

        private:
            int _bakeTimeWeight;
            int _maxCook;
            int _stockRegen;
            std::string _input;
            std::queue<Pizza> _orders;
            std::vector<Kitchen> _kitchens;
            std::vector<std::string> _stock;
            std::map<std::string, Pizza> _menu;
    };
}

#endif /* !RECEPTION_HPP */