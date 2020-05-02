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

    void Reception::updateKitchensStock() noexcept
    {
        for (auto &kitchen : _kitchens)
            kitchen.updateIngredientsStock(_stock);
    }

    void Reception::doAction(int action, bool *state) noexcept
    {
        switch(action) {
            case HELP:
                Usage::show();
                break;
            case ADDINGREDIENT:
                updateKitchensStock();
                break;
            case COMMAND:
                assignOrder();
                break;
            case QUIT:
                *state = 0;
                break;
            default:
                return;
        }
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
            doAction(action, &state);
        }
        return (0);
    }

    std::string Reception::read_stdin(void) noexcept
    {
        std::string input;

        getline(std::cin, input);
        return input;
    }

    bool Reception::assignToKitchen(int importance) noexcept
    {
        for (auto &kitchen : _kitchens) {
            if (kitchen.assignOrder(_orders.front(), importance) == true) {
                std::cout << _orders.front().getRecipe().getPizzaName()
                            << ": assigned to a cooker!" << std::endl;
                _orders.pop();
                return (true);
            }
        }
        return (false);
    }

    int Reception::assignOrder(void) noexcept
    {
        Kitchen newKitchen(_stock, _maxCook);

        int importance = 1;

        while (_orders.empty() == false) {
            if (_kitchens.empty()) {
                setKitchen(newKitchen);
                assignToKitchen(1);
                continue;
            }
            while (importance <= 2) {
                if (assignToKitchen(importance) == false) {
                    importance += 1;
                    if (importance == 3) {
                        setKitchen(newKitchen);
                        assignToKitchen(1);
                    }
                } else
                    break;
            }
            importance = 1;
        }
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