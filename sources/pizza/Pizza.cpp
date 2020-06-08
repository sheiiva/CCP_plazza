/*
** EPITECH PROJECT, 2019
** SOURCES // PIZZA
** File description:
** Pizza.cpp
*/

#include "Pizza.hpp"

namespace Plazza
{
    Pizza::Pizza(const std::string &pizzaName, std::vector<int> &neededIngredients, int bakeTime) noexcept:
        _clock(0), _pizzaName(pizzaName), _ingredients(neededIngredients), _bakeTime(bakeTime)
    {
    }

    Pizza::Pizza(Pizza const& b) noexcept :
        _clock(b._clock), _pizzaName(b._pizzaName), _ingredients(b._ingredients), _bakeTime(b._bakeTime)
    {
    }

    Pizza::Pizza(Pizza&& b) noexcept :
        _clock(b._clock), _pizzaName(b._pizzaName), _ingredients(b._ingredients), _bakeTime(b._bakeTime)
    {
    }

    Pizza &Pizza::operator=(Pizza const& rhs) noexcept
    {
        _clock = rhs._clock;
        _pizzaName = rhs._pizzaName;
        _ingredients = rhs._ingredients;
        _bakeTime = rhs._bakeTime;
        return (*this);
    }

    Pizza& Pizza::operator=(Pizza&& rhs) noexcept
    {
        _clock = rhs._clock;
        _pizzaName.swap(rhs._pizzaName);
        _ingredients.swap(rhs._ingredients);
        _bakeTime = rhs._bakeTime;
        return (*this);
    }

    int Pizza::getClock(void) const noexcept
    {
        return (_clock);
    }

    // void Pizza::setClock(int clock) noexcept
    // {
    //     _clock = clock;
    // }

    std::string Pizza::getPizzaName(void) const noexcept
    {
        return (_pizzaName);
    }

    std::vector<int> Pizza::getIngredients(void) const noexcept
    {
        return (_ingredients);
    }

    int Pizza::getBakeTime(void) const noexcept
    {
        return (_bakeTime);
    }
}