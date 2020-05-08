/*
** EPITECH PROJECT, 2019
** SOURCES // PIZZA
** File description:
** Pizza.cpp
*/

#include "Pizza.hpp"

namespace Plazza {

    Pizza::Pizza(const std::string &pizzaName, std::vector<int> &neededIngredients, int bakeTime) noexcept:
        _clock(0), _recipe(pizzaName, neededIngredients, bakeTime)
    {
    }

    Pizza::Pizza(Pizza const& b) noexcept :
        _clock(b._clock), _recipe(b._recipe)
    {
    }

    Pizza::Pizza(Pizza&& b) noexcept :
        _clock(b._clock), _recipe(std::move(b._recipe))
    {
    }

    Pizza &Pizza::operator=(Pizza const& rhs) noexcept
    {
        _clock = rhs._clock;
        _recipe = rhs._recipe;
        return (*this);
    }

    Pizza& Pizza::operator=(Pizza&& rhs) noexcept
    {
        _clock = rhs._clock;
        _recipe = std::move(rhs._recipe);
        return (*this);
    }

    int Pizza::getClock(void) const noexcept
    {
        return (_clock);
    }

    Recipe Pizza::getRecipe(void) noexcept
    {
        return (_recipe);
    }

    void Pizza::setClock(int clock) noexcept
    {
        _clock = clock;
    }

    void Pizza::bake(void)
    {
        // std::mutex mutex;
        int initTime = time(NULL);

        // mutex.lock();
        std::cout << "Let's bake a " << _recipe.getPizzaName() << "..." << std::endl;
        while ((time(NULL) - initTime) <= _recipe.getBakeTime());
        std::cout << _recipe.getPizzaName() << " ready!" << std::endl;
        // mutex.unlock();
    }
}