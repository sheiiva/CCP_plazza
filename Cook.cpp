/*
** EPITECH PROJECT, 2020
** Cook.cpp
** File description:
** cook functions
*/

#include "Cook.hpp"

namespace Plazza {

    Cook::Cook(Kitchen const& Kitchen) noexcept
    {
        
    }

    Cook(Cook const& b) noexcept
    {

    }
    
    int Cook::getStatus() noexcept
    {
        return (_status);
    }
    
    Pizza& Cook::getOrder(int index) noexcept
    {
        return (_orders[index]);
}
    
    Kitchen Cook::getKitchen() noexcept
    {
        return (_kitchen);
    }
    
    void Cook::setStatus(int status) noexcept
    {
        _status = status;
    }
    
    void Cook::setOrder(Pizza const& pizza) noexcept
    {
        _orders.back(pizza);
    }

}
//operator
