/*
** EPITECH PROJECT, 2020
** Kitchen.cpp
** File description:
** kitchen functions
*/

#include "Kitchen.hpp"

namespace Plazza {

    Kitchen::Kitchen(std::vector<std::string> stock) noexcept
    {
        std::queue<Pizza> orders;
        // Cook cook(*this);
        
        _inactiveTime = time(NULL);
        // _cooks.push_back(cook);
        for (auto &ingredient : stock)
            _ingredientsStock[ingredient] = 5;
    }

    Kitchen::Kitchen(Kitchen const& b) noexcept
    {
        _inactiveTime = b._inactiveTime;
        _cooks = b._cooks;
        _ingredientsStock = b._ingredientsStock;
    }

    Kitchen::Kitchen(Kitchen&& b) noexcept
    {
        _inactiveTime = b._inactiveTime;
        _cooks = b._cooks;
        _ingredientsStock = b._ingredientsStock;
        b._inactiveTime = 0;
        b._cooks.clear();
        b._ingredientsStock.clear();
    }
    
    Kitchen &Kitchen::operator=(Kitchen const& rhs) noexcept
    {
        _inactiveTime = rhs._inactiveTime;
        _cooks = rhs._cooks;
        _ingredientsStock = rhs._ingredientsStock;
        return (*this);
    }

    Kitchen &Kitchen::operator=(Kitchen&& rhs) noexcept
    {
         if (this != &rhs) {
            _inactiveTime = rhs._inactiveTime;
            _cooks = rhs._cooks;
            _ingredientsStock = rhs._ingredientsStock;
            rhs._inactiveTime = 0;
            rhs._cooks.clear();
            rhs._ingredientsStock.clear();
        }
         return (*this);
    }

    Kitchen::~Kitchen() {}
    
    int Kitchen::getInactiveTime(void) const noexcept
    {
        return (_inactiveTime);
    }
    
    Cook Kitchen::getCook(int index) const noexcept
    {
        return (_cooks[index]);
    }
    
    std::vector<Cook> Kitchen::getCooks() const noexcept
    {
        return (_cooks);
    }
    
    int Kitchen::getIngredientsStock(const std::string &ingredient) const noexcept
    {
        return (_ingredientsStock.find(ingredient)->second);
    }

    std::map<std::string, int> Kitchen::getIngredientsStock() const noexcept
    {
        return (_ingredientsStock);
    }
    
    void Kitchen::setInactiveTime(int time) noexcept
    {
        _inactiveTime = time;
    }
    
    void Kitchen::setCook(Cook const &cook) noexcept
    {
        _cooks.push_back(cook);
    }
    
    void Kitchen::setIngredientsStock(const std::string &ingredient) noexcept
    {
        _ingredientsStock.emplace(ingredient, 5);
    }

    void Kitchen::updateTime(bool reset) noexcept
    {
        static long int initialTime = time(NULL);

        if (reset) {
            initialTime = time(NULL);
            setInactiveTime(time(NULL));
        } else
            _inactiveTime = initialTime - time(NULL);
    }

    bool Kitchen::isKitchenActive() noexcept
    {
        for (auto& cook : _cooks) {
            if (cook.getStatus() == STATUS::ACTIVE) {
                updateTime(true);
                return (true);
            }
        }
        updateTime(false);
        return (false);
    }
    
    Kitchen& Kitchen::operator<<(Pizza const &pizza) noexcept
    {
        for (auto& i : _cooks) {
            if (i.getStatus() == 0) {
                i.setStatus(1);
                i.setOrder(pizza);
            }
        }
        return (*this);
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
                _ingredientsStock[ingredient] = 5;
            }
        }
    }

}
