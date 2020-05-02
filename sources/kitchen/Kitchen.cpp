/*
** EPITECH PROJECT, 2020
** Kitchen.cpp
** File description:
** kitchen functions
*/

#include "Kitchen.hpp"

namespace Plazza {

    Kitchen::Kitchen(std::vector<std::string> stock, int maxCook) noexcept :
        _inactiveTime(time(NULL)), _maxCook(maxCook)
    {
        // std::queue<Pizza> orders;

        // _cooks.push_back(cook);
        for (auto &ingredient : stock)
            _ingredientsStock[ingredient] = 5;
    }

    Kitchen::Kitchen(Kitchen const& b) noexcept :
        _inactiveTime(b._inactiveTime),
        _maxCook(b._maxCook),
        _cooks(b._cooks),
        _ingredientsStock(b._ingredientsStock)
    {
    }

    Kitchen::Kitchen(Kitchen&& b) noexcept :
        _inactiveTime(b._inactiveTime),
        _maxCook(b._maxCook),
        _cooks(std::move(b._cooks)),
        _ingredientsStock(std::move(b._ingredientsStock))
    {
    }
    
    Kitchen &Kitchen::operator=(Kitchen const& rhs) noexcept
    {
        _inactiveTime = rhs._inactiveTime;
        _maxCook = rhs._maxCook,
        _cooks = rhs._cooks;
        _ingredientsStock = rhs._ingredientsStock;
        return (*this);
    }

    Kitchen &Kitchen::operator=(Kitchen&& rhs) noexcept
    {
        _inactiveTime = rhs._inactiveTime;
        _maxCook = rhs._maxCook,
        _cooks.swap(rhs._cooks);
        _ingredientsStock.swap(rhs._ingredientsStock);
        return (*this);
    }

    long int Kitchen::getInactiveTime(void) const noexcept
    {
        return (_inactiveTime);
    }
    
    Cook Kitchen::getCook(int index) const noexcept
    {
        return (_cooks[index]);
    }
    
    int Kitchen::getIngredientStock(const std::string &ingredient) const noexcept
    {
        return (_ingredientsStock.find(ingredient)->second);
    }

    void Kitchen::setInactiveTime(long int time) noexcept
    {
        _inactiveTime = time;
    }
    
    void Kitchen::setIngredientToStock(const std::string &ingredient) noexcept
    {
        _ingredientsStock.emplace(ingredient, 5);
    }

    void Kitchen::updateTime(bool reset) noexcept
    {
        static long int initialTime = time(NULL);

        if (reset)
            initialTime = time(NULL);
        _inactiveTime = time(NULL) - initialTime;
    }

    bool Kitchen::isKitchenActive() noexcept
    {
        if (_cooks.size() != 0) {
            updateTime(true);
            return (true);
        } else {
            updateTime(false);
            return (false);
        }
    }

    void Kitchen::contractCook(Pizza const &pizza) noexcept
    {
        Cook newCook(pizza);

        _cooks.push_back(newCook);
        std::cout << "CONTRACT NEW COOK!" << std::endl;
    }
    
    bool Kitchen::assignOrder(Pizza const &pizza, int importance) noexcept
    {
        std::cout << " There are " << _cooks.size() << " cookers" << std::endl;
        std::cout << "Can accept "<< _maxCook << "cookers" << std::endl;
        if (_cooks.size() < (size_t)_maxCook) {
            contractCook(pizza);
            return (true);
        }
        for (auto& i : _cooks) {
            if (i.getStatus() < importance) {
                i.setStatus(i.getStatus() + 1);
                i.assignOrder(pizza);
                return (true);
            }
        }
        return (false);
    }

    bool Kitchen::isInStock(std::string ingredient)
    {
        for (auto &i : _ingredientsStock) {
            if (i.first == ingredient)
                return (true);
        }
        return (false);
    }

    void Kitchen::updateIngredientsStock(std::vector<std::string> stock) noexcept
    {
        for (auto &ingredient : stock) {
            if (isInStock(ingredient) == false) {
                setIngredientToStock(ingredient);
            }
        }
    }

}
