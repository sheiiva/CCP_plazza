/*
** EPITECH PROJECT, 2019
** INCLUDE // RECEPTION
** File description:
** Core.hpp
*/

#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include "Kitchen.hpp"
#include "Pizza.hpp"

namespace Plazza
{

    class Core
    {
        public:
            Core() noexcept = delete;
            Core(int bakeTimeWeight, int maxCook, int stockRegen) noexcept;
            Core(Core const& b) noexcept = delete;
            Core(Core&& b) noexcept = delete;
            ~Core() noexcept = default;
            Core& operator=(Core const& rhs) noexcept = delete;
            Core& operator=(Core&& rhs) noexcept = delete;

            //GETTERS
            Kitchen& getKitchen(int index) noexcept;
            int getStock(const std::string &ingredient) const noexcept;
            Pizza& getPizza(const std::string &pizzaName) noexcept;
            //SETTERS
            void setKitchen(Kitchen &kitchen) noexcept;
            //METHODS
            int run() noexcept;
            std::string read_stdin(void) noexcept;
            void parser(void) noexcept;
            int assignOrder(void) noexcept;
            int checkKitchen() noexcept;
            bool status() noexcept;
            void addToStock(const std::string &ingredient) noexcept;
            void addToMenu(Pizza &pizza) noexcept;
            // Core& operator<<(Pizza const &pizza) noexcept; // 
            // Core& operator>>(Core&& rhs) noexcept;

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

#endif /* !CORE_HPP */