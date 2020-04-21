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

    Recipe::Recipe(const Recipe &b) noexcept
    {
        std::vector<int> newlist(b._ingredients);

        _pizzaName.assign(b._pizzaName);
        _ingredients.swap(newlist);
        _bakeTime = b._bakeTime;
    }

    std::string Recipe::getPizzaName(void) noexcept
    {
        return _pizzaName;
    }

    std::vector<int> Recipe::getIngredients() const noexcept
    {
        return _ingredients;
    }

    int Recipe::getBakeTime() const noexcept
    {
        return _bakeTime;
    }
}