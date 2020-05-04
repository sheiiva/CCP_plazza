/*
** EPITECH PROJECT, 2019
** SOURCES // PIZZA
** File description:
** Recipe.hpp
*/

#include "Recipe.hpp"

namespace Plazza
{
    Recipe::Recipe(const std::string &pizzaName, std::vector<int> ingredients, int bakeTime) noexcept :
         _pizzaName(pizzaName), _ingredients(ingredients), _bakeTime(bakeTime)
    {
    }

    Recipe::Recipe(Recipe const& b) noexcept :
        _pizzaName(b._pizzaName), _ingredients(b._ingredients), _bakeTime(b._bakeTime)
    {
    }

    Recipe::Recipe(Recipe&& b) noexcept :
        _pizzaName(std::move(b._pizzaName)),
        _ingredients(std::move(b._ingredients)),
        _bakeTime(b._bakeTime)
    {
    }

    Recipe& Recipe::operator=(Recipe const& rhs) noexcept
    {
        _pizzaName = rhs._pizzaName;
        _ingredients = rhs._ingredients;
        _bakeTime = rhs._bakeTime;
        return (*this);
    }

    Recipe& Recipe::operator=(Recipe&& rhs) noexcept
    {
        _pizzaName.assign(rhs._pizzaName);
        _ingredients.swap(rhs._ingredients);
        _bakeTime = rhs._bakeTime;
        return (*this);
    }

    std::string Recipe::getPizzaName(void) noexcept
    {
        return (_pizzaName);
    }

    std::vector<int> Recipe::getIngredients(void) const noexcept
    {
        return (_ingredients);
    }

    int Recipe::getBakeTime(void) const noexcept
    {
        return (_bakeTime);
    }
}