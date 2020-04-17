/*
** EPITECH PROJECT, 2019
** INCLUDE // PIZZA
** File description:
** Recipe.hpp
*/

#include "vector"
#include "Recipe.hpp"

namespace Plazza
{
    Recipe::Recipe(int bakeTime, std::vector<int> ingredients) noexcept :
         _bakeTime(bakeTime), _ingredients(ingredients)
    {
    }

    int Recipe::getBakeTime() const noexcept
    {
        return _bakeTime;
    }

    std::vector<int> Recipe::getIngredients() const noexcept
    {
        return _ingredients;
    }
}