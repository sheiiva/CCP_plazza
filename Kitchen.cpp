/*
** EPITECH PROJECT, 2020
** Kitchen.cpp
** File description:
** kitchen functions
*/

#include "Kitchen.hpp"

namespace Plazza {

    Kitchen(Kitchen const& b) noexcept
    {
        inactiveTime = getInactiveTime();
        _cooks = getCooks();
        _ingredientsStock = getIngredientsStock();
    }
    
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
        _inactiveTime = 5;
    }
    
    void Kitchen::setCook(Cook const &cook) noexcept
    {
        _cooks.push_back(cook);
    }
    
    void Kitchen::setIngredientsStock(const std::string &ingredient) noexcept
    {
        _ingredientsStock.emplace(ingredient, 5);
    }
    
    bool Kitchen::checkCookStatus() noexcept
    {
        int i = 0;
    }
    
    Kitchen& Kitchen::operator<<(Pizza const &pizza) noexcept
    {
        _kitchen
    }   
}
