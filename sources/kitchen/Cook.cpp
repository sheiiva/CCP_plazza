/*
** EPITECH PROJECT, 2020
** Cook.cpp
** File description:
** cook functions
*/

#include "Cook.hpp"

namespace Plazza
{
    Cook::Cook(Cook const& b) noexcept :
        _status(b._status), _orders(b._orders)//, _kitchen(b._kitchen)
    {
    }

    Cook::Cook(Cook&& b) noexcept :
        _status(b._status),_orders(std::move(b._orders)) //, _kitchen(b._kitchen)
    {
    }

    Cook &Cook::operator=(Cook const& rhs) noexcept
    {
        _status = rhs._status;
        _orders = rhs._orders;
        return (*this);
    }

    Cook &Cook::operator=(Cook&& rhs) noexcept
    {
        _status = rhs._status;
        _orders.swap(rhs._orders);
        return (*this);
    }

    // Cook::Cook(Kitchen const& Kitchen) noexcept : _status(0),_kitchen(Kitchen)
    // {
    // }
    
    int Cook::getStatus() const noexcept
    {
        return (_status);
    }

    Pizza& Cook::getOrder() noexcept
    {
        return (_orders.front());
    }

    // Kitchen Cook::getKitchen() const noexcept
    // {
    //     return (_kitchen);
    // }

    void Cook::setStatus(int status) noexcept
    {
        if (status == ACTIVE || status == INACTIVE)
            _status = status;
        else
            std::cerr << "Wrong input :: wrong status" << std::endl;
    }

    void Cook::setOrder(Pizza const& pizza) noexcept
    {
        _orders.push(pizza);
    }

    // Cook& Cook::operator<<(Pizza const& pizza) noexcept
    // {
    //     return (*this);
    // }
}
