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
        _kitchens.push_back(kitchen);
    }

    int Reception::run() noexcept
    {
        std::string input;

        while (1) {
            input.assign(read_stdin());
            parser(input);
        }
        return (0);
    }

    std::string Reception::read_stdin(void) noexcept
    {
        std::string input;

        getline(std::cin, input);
        return input;
    }

    bool Reception::isValidSize(const std::string &inputSize)
    {
        static std::string sizes[5] = {"S", "M", "L", "XL", "XXL"};

        for (auto &size : sizes) {
            if (!inputSize.compare(size))
                return true;
        }
        return false;
    }

    bool Reception::isValidName(const std::string &inputName)
    {
        for (auto &name : _menu) {
            if (!inputName.compare(name.first))
                return true;
        }
        return false;
    }

    size_t Reception::isValidNbr(const std::string &inputNbr)
    {
        if (inputNbr[0] != 'x')
            return (0);
        else if (!atoi(inputNbr.c_str() + 1))
            return (0);
        return atoi(inputNbr.c_str() + 1);
    }

    void Reception::parser(const std::string &input) noexcept
    {
        size_t nbr = 0;
        std::string command(input);
        size_t sep = std::count(command.begin(), command.end(), ';');
        std::replace(command.begin(), command.end(), ';', ' ');
        std::istringstream iss(command);
        std::vector<std::string> splitString(std::istream_iterator<std::string>{iss},
                                        std::istream_iterator<std::string>());
        
        if (!input.compare("HELP")) {
            //SHOW USAGE
            return;
        } else if (!input.compare("ADD")) {
            return;
        }
        if ((splitString.size() % 3) != 0 || (((splitString.size() / 3) - 1) != sep)) {
            std::cerr << "Wrong input :: number of arguments." << std::endl;
            return;
        }
        for (size_t i = 0; i < splitString.size(); i += 3) {
            if (isValidName(splitString[PIZZANAME + i]) == false)
                std::cerr << "Wrong input :: name of pizza." << std::endl;
            else if (isValidSize(splitString[SIZE + i]) == false)
                std::cerr << "Wrong input :: size of pizza." << std::endl;
            else if (!(nbr = isValidNbr(splitString[NUMBER + i])))
                std::cerr << "Wrong input :: number of pizza." << std::endl;
            else {
                for(size_t index = 0; index < nbr; index++)
                    _orders.push(Pizza(_menu[splitString[PIZZANAME + i]]));
                //WHAT ABOUT THE SIZE ? HAVE TO STOCK IT IN THE PIZZA
            }
        }
        while (_orders.size() != 0) {
            std::cout << _orders.front().getRecipe().getPizzaName() << std::endl;
            _orders.pop();
        }
    }

    int Reception::assignOrder(void) noexcept
    {
        // TO DO
        return (0);
    }

    int Reception::checkKitchen() noexcept
    {
        // TO DO
        return (0);
    }

    bool Reception::status() noexcept
    {
        // TO DO
        return (true);
    }

    bool Reception::addToStock(const std::string &ingredient) noexcept
    {
        for (auto &i: _stock) {
            if (i.compare(ingredient)) {
                std::cout << ingredient << " already in stock!" << std::endl;
                return (false);
            }
        }
        _stock.push_back(ingredient);
        return (true);
    }

    bool Reception::addToMenu(Pizza &pizza) noexcept
    {
        std::string pizzaName = pizza.getRecipe().getPizzaName();

        for (auto &i: _menu) {
            if (i.second.getRecipe().getPizzaName() == pizzaName) {
                std::cout << pizzaName << " already in the menu!" << std::endl;
                return (false);
            }
        }
        _menu[pizzaName] = pizza;
        return (true);
    }
}