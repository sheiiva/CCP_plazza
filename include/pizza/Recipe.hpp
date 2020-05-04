/*
** EPITECH PROJECT, 2019
** INCLUDE // PIZZA
** File description:
** Recipe.hpp
*/

#ifndef RECIPE_HPP
#define RECIPE_HPP

#include <vector>
#include <string>
namespace Plazza
{
    class Recipe
    {
        public:
            Recipe() noexcept = default;
            Recipe(std::string const& pizzaName, std::vector<int> ingredients, int bakeTime) noexcept;
            Recipe(Recipe const& b) noexcept;
            Recipe(Recipe&& b) noexcept;
            ~Recipe() noexcept = default;

            Recipe& operator=(Recipe const& rhs) noexcept;
            Recipe& operator=(Recipe&& rhs) noexcept;

        public:
            std::string getPizzaName(void) noexcept;
            std::vector<int> getIngredients(void) const noexcept;
            int getBakeTime(void) const noexcept;

        private:
            std::string _pizzaName;
            std::vector<int> _ingredients;
            int _bakeTime;
    };
}

#endif /* !RECIPE_HPP */