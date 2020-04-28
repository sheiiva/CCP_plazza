/*
** EPITECH PROJECT, 2020
** Cook.cpp
** File description:
** cook functions
*/

#include "Cook.hpp"

Plazza::Cook::Cook(Cook const& b) noexcept {}

Plazza::Cook::Cook(Kitchen const& Kitchen) noexcept {}

Plazza::Cook::Cook& operator=(Cook const& rhs) noexcept {}

int Plazza::Cook::getStatus() noexcept
{
    return (_status);
}

Pizza& Plazza::Cook::getOrder(int index) noexcept
{
    return (_orders[index]);
}

Kitchen Plazza::Cook::getKitchen() noexcept
{
    return (_kitchen);
}

void Plazza::Cook::setStatus(int status) noexcept
{
    _status = status;
}

void Plazza::Cook::setOrder(Pizza const& pizza) noexcept
{
    _orders.back(pizza);
}
