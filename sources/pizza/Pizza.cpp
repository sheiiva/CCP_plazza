/*
** EPITECH PROJECT, 2020
** Pizza.cpp
** File description:
** pizza class
*/

#include "Pizza.hpp"

namespace Plazza
{
    Pizza::Pizza(const std::string &pizzaName, std::vector<int> &neededIngredients, int bakeTime) noexcept
    {
        _neededIngredients = neededIngredients;
        _bakeTime = bakeTime;
        _recipe(pizzaName, neededIngredients, bakeTime);
        _clock = 0;
    }

    Pizza::~Pizza(void) {}
    
    int Pizza::getBakeTime(void) const noexcept
    {
        return (_bakeTime);
    }

    int Pizza::getClock(void) const noexcept
    {
        return (_clock);
    }

    std::vector<int> Pizza::getNeededIngredients(void) const noexcept
    {
        return (_neededIngredients);
    }

    int Pizza::getNeedIngredient(int index) const noexcept
    {
        return (_neededIngredients[index]);
    }

    void Pizza::setBakeTime(int bakeTime) noexcept
    {
        _bakeTime = bakeTime;
    }

    void Pizza::setClock(int clock) noexcept
    {
        _clock = clock;
    }

    void Pizza::setNeededIngredients(int neededIngredient) noexcept
    {
        _neededIngredients.push_back(neededIngredient);
    }

    void Pizza::bake(void) noexcept
    {

    }
}
