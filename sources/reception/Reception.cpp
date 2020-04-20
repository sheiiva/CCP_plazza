/*
** EPITECH PROJECT, 2019
** SOURCES // RECEPTION
** File description:
** Core.cpp
*/

#include "Reception.hpp"

namespace Plazza
{
    Core::Core(int bakeTimeWeight, int maxCook, int stockRegen) noexcept:
        _bakeTimeWeight(bakeTimeWeight), _maxCook(maxCook), _stockRegen(stockRegen)
    {
        std::vector<int> ingredients;

        _stock = {"doe", "tomato", "gruyere", "ham", "mushrooms",
                    "steak","eggplant", "goat cheese", "chief love"};
        ingredients.assign({0, 1, 2});
        _menu["Margarita"] = Pizza("Margarita", ingredients, (1 * _bakeTimeWeight));
        ingredients.assign({0, 1, 2, 3, 4});
        _menu["Regina"] = Pizza("Regina", ingredients, (2 * _bakeTimeWeight));
        ingredients.assign({0, 1, 2, 5});
        _menu["Americana"] = Pizza("Americana", ingredients, (2 * _bakeTimeWeight));
        ingredients.assign({0, 1, 6, 7, 8});
        _menu["Fantasia"] = Pizza("Fantasia", ingredients, (4 * _bakeTimeWeight));
    }

    Kitchen& Core::getKitchen(int index) noexcept
    {
        return _kitchens.at(index);
    }

    int Core::getStock(const std::string &ingredient) const noexcept
    {
        for (int i = 0; i < _stock.size(); i++) {
            if (!_stock[i].compare(ingredient))
                return (i);
        }
        return (-1);
    }

    Pizza& Core::getPizza(const std::string &pizzaName) noexcept
    {
        return _menu[pizzaName];
    }

    int Core::run() noexcept
    {
        //MAIN LOOP
        return (0);
    }

    std::string read_stdin(void) noexcept
    {
        std::string input;

        getline(std::cin, input);
        return input;
    }

    void Core::parser(void) noexcept
    {

    }


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

    void Core::addToStock(const std::string &ingredient) noexcept
    {
        for (auto &i: _stock) {
            if (i.compare(ingredient)) {
                std::cout << ingredient << " already in stock!" << std::endl;
                return;
            }
        }
        _stock.push_back(ingredient);
    }

    void Core::addToMenu(Pizza &pizza) noexcept
    {
        std::string pizzaName = pizza.getRecipe().getPizzaName();

        for (auto &i: _menu) {
            if (i.second.getRecipe().getPizzaName() == pizzaName) {
                std::cout << pizzaName << " already in the menu!" << std::endl;
                return;
            }
        }
        // _menu[pizzaName] = pizza; WHAT?? VERIFY THE COPY CONSTRUCTOR
    }
}