/*
** EPITECH PROJECT, 2019
** INCLUDE // PIZZA
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

    int Recipe::getBakeTime() const noexcept
    {
        return _bakeTime;
    }

    std::vector<int> Recipe::getIngredients() const noexcept
    {
        return _ingredients;
    }
}