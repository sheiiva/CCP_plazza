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

    Pizza &Pizza::operator=(const Pizza &rhs) noexcept
    {
        _clock = rhs._clock;
        // _recipe = rhs._recipe; DO THE operator= IN RECIPE
        return *this;
    }

    //GETTERS
    int Pizza::getBakeTime(void) const noexcept
    {
        return this->_recipe.getBakeTime();
    }

    int Pizza::getClock(void) const noexcept
    {
        return (0);
    }

    std::vector<int> Pizza::getNeededIngredients() const noexcept
    {
        std::vector<int> list;

        return (list);
    }

    int Pizza::getNeedIngredients(int index) const noexcept
    {
        (void)index;
        return (0);
    }

    Recipe Pizza::getRecipe(void) noexcept
    {
        return (_recipe);
    }

    //SETTERS
    void Pizza::setBakeTime(int bakeTime) const noexcept
    {
        (void)bakeTime;
    }

    void Pizza::setClock(int clock) const noexcept
    {
        (void)clock;
    }

    void Pizza::setNeededIngredients(int neededIngredient) const noexcept
    {
        (void)neededIngredient;
    }

    //METHODS
    void Pizza::bake() noexcept
    {

    }
    // Pizza& operator<<(std::list<int> &ingredients) noexcept; // SAME AS bake
    // Pizza& operator>>(const Kitchen &kitchen) noexcept;
}