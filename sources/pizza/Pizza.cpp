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
        _recipe(pizzaName, neededIngredients, bakeTime);
        _clock = 0;
    }

    Pizza::Pizza(Pizza const& b) noexcept
    {
        _neededIngredients = b._neededIngredients;
        _recipe = b._recipe;
        _clock = b._clock;
    }

    Pizza::Pizza(Pizza&& b) noexcept
    {
        _neededIngredients = b._neededIngredients;
        _recipe = b._recipe;
        _clock = b._clock;

        b._neededIngredients.empty();
        b._clock = 0;
        
    }

    Pizza::Pizza& operator=(Pizza const& rhs) noexcept
    {
        _neededIngredients = b._neededIngredients;
        _recipe = b._recipe;
        _clock = b._clock;
    }

    Pizza::Pizza& operator=(Pizza&& rhs) noexcept
    {
        _neededIngredients = b._neededIngredients;
        _recipe = b._recipe;
        _clock = b._clock;

        b._neededIngredients.empty();
        b._clock = 0;
    }
    
    Pizza::~Pizza(void) {}
    
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
