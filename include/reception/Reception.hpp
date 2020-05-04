/*
** EPITECH PROJECT, 2019
** INCLUDE // RECEPTION
** File description:
** Reception.hpp
*/

#ifndef RECEPTION_HPP
#define RECEPTION_HPP

#include <map>
#include <queue>
#include <string>
#include <vector>
#include "Kitchen.hpp"
#include "Parser.hpp"
#include "Pizza.hpp"
#include "Usage.hpp"

namespace Plazza
{
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

            int run() noexcept;
        
        private:
            //GETTERS
            int getBakeTimeWeight(void) const noexcept;
            int getMaxCook(void) const noexcept;
            int getStockRegen(void) const noexcept;
            Kitchen& getKitchen(int index) noexcept;
            int getStock(const std::string &ingredient) const noexcept;
            Pizza& getPizza(std::string const& pizzaName) noexcept;
            //SETTERS
            //METHODS
            void createNewKitchen(void) noexcept;
            bool assignToKitchen(int importance) noexcept;
            void assignOrder(void) noexcept;
            void checkKitchensActivity() noexcept;
            bool status() noexcept;
            std::string read_stdin(void) noexcept;
            bool doAction(int action) noexcept;

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