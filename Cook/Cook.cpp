/*
** EPITECH PROJECT, 2020
** Cook.cpp
** File description:
** cook functions
*/

#include "Cook.hpp"

namespace Plazza
{
    Cook::Cook(Cook const& b) noexcept : _status(b.getStatus()), _orders(b._orders), _kitchen(b.getKitchen())
    {
    }
    
    Cook::Cook(Kitchen const& Kitchen) noexcept : _kitchen(Kitchen)
    {
    }
    
    int Cook::getStatus() const noexcept
    {
        return (_status);
    }

    Pizza& Cook::getOrder(int index) noexcept
    {
        return (_orders.front());
    }

    Kitchen Cook::getKitchen() const noexcept
    {
        return (_kitchen);
    }

    void Cook::setStatus(int status) noexcept
    {
        _status = status;
    }

    void Cook::setOrder(Pizza const& pizza) noexcept
    {
        _orders.push(pizza);
    }

//operator

    Cook& Cook::operator<<(Pizza const& pizza) noexcept
    {
        return (*this);
    }
}
