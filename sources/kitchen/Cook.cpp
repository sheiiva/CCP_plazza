/*
** EPITECH PROJECT, 2020
** Cook.cpp
** File description:
** cook functions
*/

#include "Cook.hpp"

namespace Plazza
{
    Cook::Cook(Pizza const& pizza) noexcept :
        _status(STATUS::ACTIVE)
    {
        _orders.push(pizza);
        std::cout << _orders.back().getRecipe().getPizzaName()
                    << ": assigned to a cooker!" << std::endl;
        cook();
    }

    Cook::Cook(Cook const& b) noexcept :
        _status(b._status), _orders(b._orders)
    {
    }

    Cook::Cook(Cook&& b) noexcept :
        _status(b._status),_orders(std::move(b._orders))
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

    int Cook::getStatus() const noexcept
    {
        return (_status);
    }

    void Cook::setStatus(int status) noexcept
    {
        _status = status;
    }

    bool Cook::assignOrder(Pizza const& pizza) noexcept
    {
        if (_orders.size() > 2)
            return (false);
        _orders.push(pizza);
        std::cout << _orders.back().getRecipe().getPizzaName()
                    << ": assigned to a cooker!" << std::endl;
        return (true);
    }

    void Cook::cook()
    {
        std::thread thread(&Pizza::bake, _orders.front());
        if (thread.joinable())
            thread.join();
        _orders.pop();
        if (_orders.empty() == false)
            cook();
        _status = ((_status - 1) <= INACTIVE) ? INACTIVE : (_status - 1);
    }
}
