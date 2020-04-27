/*
** EPITECH PROJECT, 2020
** Kitchen.cpp
** File description:
** kitchen functions
*/

#include "Kitchen.hpp"

namespace Plazza {

    Kitchen::Kitchen(void) noexcept {}

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
        _inactiveTime = 0;
    }
    
    void Kitchen::setCook(Cook const &cook) noexcept
    {
        _cooks.push_back(cook);
    }
    
    void Kitchen::setIngredientsStock(const std::string &ingredient) noexcept
    {
        _ingredientsStock.emplace(ingredient, 5);
    }
    
    /*  bool Kitchen::checkCookStatus() noexcept
    {
        int i = 0;
    }
    
    Kitchen& Kitchen::operator<<(Pizza const &pizza) noexcept
    {
        _kitchen
        }   */
}
