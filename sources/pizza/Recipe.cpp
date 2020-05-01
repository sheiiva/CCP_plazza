/*
** EPITECH PROJECT, 2019
** INCLUDE // PIZZA
** File description:
** Recipe.hpp
*/

#include "Recipe.hpp"

namespace Plazza
{
    Recipe::Recipe(const std::string &pizzaName, std::vector<int> ingredients, int bakeTime) noexcept : _pizzaName(pizzaName), _ingredients(ingredients), _bakeTime(bakeTime) {}

    Recipe::Recipe(const Recipe &b) noexcept
    {
        std::vector<int> newlist(b._ingredients);

        _pizzaName.assign(b._pizzaName);
        _ingredients.swap(newlist);
        _bakeTime = b._bakeTime;
    }

    Recipe::Recipe(Recipe &&b) noexcept
    {
        std::vector<int> newlist(b._ingredients);

        _pizzaName.assign(b._pizzaName);
        _ingredients.swap(newlist);
        _bakeTime = b._bakeTime;

        b._pizzaName.clear();
        b._ingredients.clear();
        b._bakeTime = 0;
    }

    Recipe &Recipe::operator=(Recipe const &rhs) noexcept
    {
         std::vector<int> newlist(rhs._ingredients);

        _pizzaName.assign(rhs._pizzaName);
        _ingredients.swap(newlist);
        _bakeTime = rhs._bakeTime;
        return (*this);
    }

    Recipe &Recipe::operator=(Recipe &&rhs) noexcept
    {
         std::vector<int> newlist(rhs._ingredients);

         if (this != &rhs) {          
             _pizzaName.assign(rhs._pizzaName);
             _ingredients.swap(newlist);
             _bakeTime = rhs._bakeTime;

             rhs._pizzaName.clear();
             rhs._ingredients.clear();
             rhs._bakeTime = 0;
         }
         return (*this);
    }

    Recipe::~Recipe() noexcept {}
    
    std::string Recipe::getPizzaName(void) const noexcept
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
