/*
** EPITECH PROJECT, 2020
** SOURCES || KITCHEN
** File description:
** cook functions
*/

#include "Cook.hpp"

namespace Plazza
{
    Cook::Cook() :
        _thread(&Cook::bake, this)
    {
    }

    Cook::~Cook()
    {
        if (_thread.joinable())
            _thread.join();
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
        if (_orders.size() >= 2)
            return (false);
        _orders.push(pizza);
        std::cout << _orders.back().getPizzaName() << ": assigned to a cooker!" << std::endl;
        _condition.notify_one();
        return (true);
    }

    void Cook::bake(void)
    {
        std::mutex _mtx;
        std::unique_lock<std::mutex> lock(_mtx);

        while (_status != FIRED) {
            _condition.wait(lock, [&](){return (!_orders.empty());});
            std::cout << "Let's bake a " << _orders.front().getPizzaName() << "..." << std::endl;
            sleep(_orders.front().getBakeTime());
            std::cout << _orders.front().getPizzaName() << " cooked!" << std::endl;
            _orders.pop();
            _condition.notify_one();
            _status = ((_status - 1) <= INACTIVE) ? INACTIVE : (_status - 1);
        }
    }
}
