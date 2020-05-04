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

    int Reception::getBakeTimeWeight(void) const noexcept
    {
        return _bakeTimeWeight;
    }

    int Reception::getMaxCook(void) const noexcept
    {
        return _maxCook;
    }

    int Reception::getStockRegen(void) const noexcept
    {
        return _stockRegen;
    }

    Kitchen& Reception::getKitchen(int index) noexcept
    {
        return _kitchens.at(index);
    }

    int Reception::getStock(std::string const& ingredient) const noexcept
    {
        for (size_t i = 0; i < _stock.size(); i++) {
            if (!_stock[i].compare(ingredient))
                return (i);
        }
        return (-1);
    }

    Pizza& Reception::getPizza(std::string const& pizzaName) noexcept
    {
        return _menu[pizzaName];
    }

    void Reception::createNewKitchen(void) noexcept
    {
        Kitchen newKitchen(_menu, _stock, _maxCook);

        std::cout << "New kitchen created!" << std::endl;
        _kitchens.push_back(newKitchen);
    }

    bool Reception::assignToKitchen(int importance) noexcept
    {
        for (auto &kitchen : _kitchens) {
            if (kitchen.assignOrder(_orders.front(), importance) == true) {
                _orders.pop();
                return (true);
            }
        }
        return (false);
    }

    void Reception::assignOrder(void) noexcept
    {
        while (_orders.empty() == false) {
            if (assignToKitchen(1) == false) {
                if (assignToKitchen(2) == false) {
                    createNewKitchen();
                    assignToKitchen(1);
                }
            }
        }
    }

    void Reception::checkKitchensActivity() noexcept
    {
        for (auto it = _kitchens.begin(); it != _kitchens.end(); it++) {
            if (it->getInactiveTime() >= 5) {
                std::cout << "Inactive kitchen closed." << std::endl;
                close(it->getPid());
                it = _kitchens.erase(it);
            }
        }
    }

    bool Reception::status() noexcept
    {
        // TO DO
        return (true);
    }

    std::string Reception::read_stdin(void) noexcept
    {
        std::string input;

        getline(std::cin, input);
        return (input);
    }

    bool Reception::doAction(int action) noexcept
    {
        switch(action) {
            case HELP:
                Usage::show();
                break;
            case COMMAND:
                assignOrder();
                break;
            case QUIT:
                for (auto &kitchen : _kitchens)
                    kitchen.quit();
                return (false);
            default:
                return (true);
        }
        return (true);
    }

    int Reception::run() noexcept
    {
        Parser parser;
        std::string input;
        short action = NOACTION;

        while (doAction(action)) {
            input.assign(read_stdin());
            action = parser.run(input, _orders, _menu);
        }
        return (0);
    }

}