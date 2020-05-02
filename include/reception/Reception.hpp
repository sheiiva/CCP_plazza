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
            void checkKitchensActivity() noexcept;
            bool status() noexcept;
            bool addToStock(const std::string &ingredient) noexcept;
            bool addToMenu(Pizza &pizza) noexcept;
            // Reception& operator<<(Pizza const &pizza) noexcept; // 
            // Reception& operator>>(Reception&& rhs) noexcept;

        private:
            void updateKitchensStock() noexcept;
            int assignOrder(void) noexcept;
            void doAction(int action, bool *state) noexcept;
            bool assignToKitchen(int importance) noexcept;

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