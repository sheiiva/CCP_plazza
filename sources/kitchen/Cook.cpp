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
        _mutex.lock();
        // std::thread thread(std::bind(_orders.front().bake, this));
        _mutex.unlock();
    }

    Cook::~Cook() noexcept
    {
        if (_thread.joinable())
            _thread.join();
    }

    Cook::Cook(Cook const &b) noexcept :
        _status(b._status), _orders(b._orders)//, _kitchen(b._kitchen)
    {
    }

    Cook::Cook(Cook &&b) noexcept :
        _status(b._status),_orders(std::move(b._orders)) //, _kitchen(b._kitchen)
    {
    }

    Cook &Cook::operator=(Cook const &rhs) noexcept
    {
        _status = rhs._status;
        _orders = rhs._orders;
        return (*this);
    }

    Cook &Cook::operator=(Cook &&rhs) noexcept
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

    // Pizza &Cook::getOrder() noexcept
    // {
    //     return (_orders.front());
    // }

    // Kitchen Cook::getKitchen() const noexcept
    // {
    //     return (_kitchen);
    // }

    void Cook::setStatus(int status) noexcept
    {
        _status = status;
    }

    bool Cook::assignOrder(Pizza const &pizza) noexcept
    {
        if (_orders.size() > 2)
            return (false);
        _orders.push(pizza);
        return (true);
    }

    // Cook& Cook::operator<<(Pizza const& pizza) noexcept
    // {
    //     return (*this);
    // }
}
