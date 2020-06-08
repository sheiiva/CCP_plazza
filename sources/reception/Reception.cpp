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
        initStock();
        initMenu();
    }

    int Reception::getBakeTimeWeight(void) const noexcept
    {
        return (_bakeTimeWeight);
    }

    void Reception::setBakeTimeWeight(int value) noexcept
    {
        _bakeTimeWeight = value;
    }

    int Reception::getMaxCook(void) const noexcept
    {
        return (_maxCook);
    }

    void Reception::setMaxCook(int value) noexcept
    {
        _maxCook = value;
    }

    int Reception::getStockRegen(void) const noexcept
    {
        return (_stockRegen);
    }

    void Reception::setStockRegen(int value) noexcept
    {
        _stockRegen = value;
    } 

    void Reception::initStock(void) noexcept
    {
        _stock["doe"] = 0;
        _stock["tomato"] = 1;
        _stock["gruyere"] = 2;
        _stock["ham"] = 3;
        _stock["mushrooms"] = 4;
        _stock["steak"] = 5;
        _stock["eggplant"] = 6;
        _stock["cheese"] = 7;
        _stock["chief love"] = 8;
    }

    void Reception::initMenu(void) noexcept
    {
        std::vector<int> ingredients;
    
        ingredients.assign({_stock["doe"], _stock["tomato"], _stock["gruyere"]});
        _menu["Margarita"] = Pizza("Margarita", ingredients, (1 * _bakeTimeWeight));
        ingredients.assign({_stock["doe"], _stock["tomato"], _stock["gruyere"],_stock["ham"], _stock["mushrooms"]});
        _menu["Regina"] = Pizza("Regina", ingredients, (2 * _bakeTimeWeight));
        ingredients.assign({_stock["doe"], _stock["tomato"], _stock["gruyere"], _stock["steak"]});
        _menu["Americana"] = Pizza("Americana", ingredients, (2 * _bakeTimeWeight));
        ingredients.assign({_stock["doe"], _stock["tomato"], _stock["eggplant"], _stock["cheese"], _stock["chief love"]});
        _menu["Fantasia"] = Pizza("Fantasia", ingredients, (4 * _bakeTimeWeight));
    }


    // Kitchen& Reception::getKitchen(int index) noexcept
    // {
    //     return _kitchens.at(index);
    // }

//     int Reception::getStock(std::string const& ingredient) const noexcept
//     {
//         for (size_t i = 0; i < _stock.size(); i++) {
//             if (!_stock[i].compare(ingredient))
//                 return (i);
//         }
//         return (-1);
//     }

//     Pizza& Reception::getPizza(std::string const& pizzaName) noexcept
//     {
//         return _menu[pizzaName];
//     }

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
                }
            }
        }
    }

//     void Reception::checkKitchensActivity() noexcept
//     {
//         for (auto it = _kitchens.begin(); it != _kitchens.end(); it++) {
//             if (it->getInactiveTime() >= 5) {
//                 std::cout << "Inactive kitchen closed." << std::endl;
//                 close(it->getPid());
//                 it = _kitchens.erase(it);
//             }
//         }
//     }

    void Reception::status() const noexcept
    {
        size_t i = 0;

        if (_kitchens.size() == 0) {
            std::cout << "Everyone is sleeping..." << std::endl;
            return;
        }
        for (auto &kitchen : _kitchens) {
            std::cout << "Kitchen no. " << i++ <<  ":" << std::endl;
            kitchen.status();
            std::cout << std::endl;
        }
    }

    std::string Reception::read_stdin(void) noexcept
    {
        std::string input;

        getline(std::cin, input);
        return (input);
    }

    bool Reception::process(int action) noexcept
    {
        switch(action) {
            case HELP:
                Usage::show();
                break;
            case COMMAND:
                assignOrder();
                break;
            case STATUS:
                status();
                break;
            case QUIT:
                for (auto &kitchen : _kitchens)
                    kitchen.quit();
                return (false);
            default:
               break;
        }
        return (true);
    }

    int Reception::run() noexcept
    {
        Parser parser;
        std::string input;
        short action = NOACTION;

        while (process(action)) {
            input.assign(std::move(read_stdin()));
            action = parser.run(input, _orders, _menu);
        }
        return (SUCCESS);
    }

}