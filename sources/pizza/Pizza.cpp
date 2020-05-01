/*
** EPITECH PROJECT, 2020
** Pizza.cpp
** File description:
** pizza class
*/

#include "Pizza.hpp"

namespace Plazza
{
    Pizza::Pizza(const std::string &pizzaName, std::vector<int> &neededIngredients, int bakeTime) noexcept :  _recipe(pizzaName, neededIngredients, bakeTime)
    {
        _neededIngredients = neededIngredients;       
        _clock = 0;
    }

    Pizza::Pizza(Pizza const& b) noexcept : _recipe(b._recipe)
    {
        _neededIngredients = b._neededIngredients;
        _clock = b._clock;
    }

    Pizza::Pizza(Pizza&& b) noexcept : _recipe(b._recipe)
    {
        _neededIngredients = b._neededIngredients;
        _clock = b._clock;

        b._neededIngredients.empty();
        b._clock = 0;
    }

    Pizza &Pizza::operator=(Pizza const& rhs) noexcept
    {
        _neededIngredients = rhs._neededIngredients;
        _recipe = rhs._recipe;
        _clock = rhs._clock;
        return (*this);
    }

    Pizza &Pizza::operator=(Pizza&& rhs) noexcept
    {
        _neededIngredients = rhs._neededIngredients;
        _recipe = rhs._recipe;
        _clock = rhs._clock;

        rhs._neededIngredients.empty();
        rhs._clock = 0;
        return (*this);
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

    Recipe Pizza::getRecipe(void) noexcept
    {
        return (_recipe);
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

    /*Pizza &Pizza::operator>>(const Kitchen &kitchen) noexcept
    {
        return (*this);
        }*/
}
