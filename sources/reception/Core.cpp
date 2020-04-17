/*
** EPITECH PROJECT, 2019
** SOURCES // RECEPTION
** File description:
** Core.cpp
*/

#include "Core.hpp"

namespace Plazza
{
    Core::Core(int bakeTimeWeight, int maxCook, int stockRegen) noexcept:
        _bakeTimeWeight(bakeTimeWeight), _maxCook(maxCook), _stockRegen(stockRegen)
    {
        _stock = {"doe", "tomato", "gruyere", "ham",
                    "mushrooms", "steak", "eggplant"
                    "goat cheese", "chief love"};
        _menu["Margarita"] = {0, 1, 2};
        _menu["Regina"] = {0, 1, 2, 3, 4};
        _menu["Americana"] = {0, 1, 2, 5};
        _menu["Fantasia"] = {0, 1, 6, 7, 8};
        _bakeTime["Margarita"] = 1;
        _bakeTime["Regina"] = 2;
        _bakeTime["Americana"] = 2;
        _bakeTime["Fantasia"] = 4;
    }

    Kitchen& Core::getKitchen(int index) noexcept
    {
        return _kitchens.at(index);
    }
            // std::vector<Kitchen> getKitchen() noexcept;
            // int getStock(std::string) const noexcept;
            // std::map<std::string, int> getStock() noexcept;
            // int getPizza(std::string) const noexcept;
            // std::map<std::string, int> getPizza() noexcept;
            // //SETTERS
            // void setKitchen(Kitchen &kitchen) noexcept;
            // void setStock(const std::string &ingredient) noexcept;
            // void setPizza(Pizza &pizza) noexcept;
            // //METHODS
            // int run() noexcept;
            // std::string read_stdin(void) noexcept;
            // void parser(void) noexcept;
            // int assignOrder(void) noexcept;
            // int checkKitchen() noexcept;
            // bool status() noexcept;
}