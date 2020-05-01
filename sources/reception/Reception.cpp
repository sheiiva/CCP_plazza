/*
** EPITECH PROJECT, 2019
** SOURCES // RECEPTION
** File description:
** Reception.cpp
*/

#include "Reception.hpp"

namespace Plazza
{
    Reception::Reception(int bakeTimeWeight, int maxCook, int stockRegen) noexcept:
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

    Kitchen& Reception::getKitchen(int index) noexcept
    {
        return _kitchens.at(index);
    }

    int Reception::getStock(const std::string &ingredient) const noexcept
    {
        for (size_t i = 0; i < _stock.size(); i++) {
            if (!_stock[i].compare(ingredient))
                return (i);
        }
        return (-1);
    }

    Pizza& Reception::getPizza(const std::string &pizzaName) noexcept
    {
        return _menu[pizzaName];
    }

    int Reception::getBakeTimeWeight(void) noexcept
    {
        return _bakeTimeWeight;
    }

    int Reception::getMaxCook(void) noexcept
    {
        return _maxCook;
    }

    int Reception::getStockRegen(void) noexcept
    {
        return _stockRegen;
    }

    void Reception::setKitchen(Kitchen &kitchen) noexcept
    {
        std::cout << "New kitchen created!" << std::endl;
        _kitchens.push_back(kitchen);
    }

    int Reception::run() noexcept
    {
        Parser parser;
        std::string input;
        short action = 0;
        bool state = 1;

        while (state) {
            input.assign(read_stdin());
            action = parser.run(input, _orders, _stock, _menu);
            if (action == HELP) {
                Usage::show();
            } else if (action == QUIT)
                state = 0;
        }
        return (0);
    }

    std::string Reception::read_stdin(void) noexcept
    {
        std::string input;

        getline(std::cin, input);
        return input;
    }

    int Reception::assignOrder(void) noexcept
    {
        // TO DO
        return (0);
    }

    void Reception::checkKitchensActivity() noexcept
    {
        for (auto it = _kitchens.begin(); it != _kitchens.end(); it++) {
            if (it->getInactiveTime() >= 5) {
                std::cout << "Inactive kitchen closed." << std::endl;
                it = _kitchens.erase(it);
            }
        }
    }

    bool Reception::status() noexcept
    {
        // TO DO
        return (true);
    }

}