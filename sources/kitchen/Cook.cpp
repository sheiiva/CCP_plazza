/*
** EPITECH PROJECT, 2020
** Cook.cpp
** File description:
** cook functions
*/

#include "Cook.hpp"

namespace Plazza
{
    Cook::Cook(Cook const& b) noexcept : _status(b._status), _orders(b._orders), _kitchen(b._kitchen)
    {
    }

    Cook::Cook(Cook&& b) noexcept : _status(b._status), _orders(b._orders), _kitchen(b._kitchen)
    {
        b._status = 0;
        while(!b._orders.empty())
            b._orders.pop();
    }

    Cook &Cook::operator=(Cook const& rhs) noexcept
    {
        _status = rhs._status;
        _orders = rhs._orders;
        return (*this);
    }

    Cook &Cook::operator=(Cook&& rhs) noexcept
    {
         if (this != &rhs) {
            _status = rhs._status;
            _orders = rhs._orders;
            rhs._status = 0;
            while(!rhs._orders.empty())
                rhs._orders.pop();
         }
         return (*this);
    }
    
    Cook::Cook(Kitchen const& Kitchen) noexcept : _status(0),_kitchen(Kitchen)
    {
    }
    
    int Cook::getStatus() const noexcept
    {
        return (_status);
    }

    Pizza& Cook::getOrder(int index) noexcept
    {
        index = index;
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

    /* Cook& Cook::operator<<(Pizza const& pizza) noexcept
    {
        return (*this);
        }*/
}
