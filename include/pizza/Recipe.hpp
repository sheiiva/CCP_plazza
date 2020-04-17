/*
** EPITECH PROJECT, 2019
** INCLUDE // PIZZA
** File description:
** Recipe.hpp
*/

#ifndef RECIPE_HPP
#define RECIPE_HPP

#include "vector"

namespace Plazza
{
    class Recipe
    {
        public:
            Recipe(int bakeTime, std::vector<int> ingredients) noexcept;
            Recipe() noexcept = delete;
            Recipe(Recipe const& b) noexcept = delete;
            Recipe(Recipe&& b) noexcept = delete;
            ~Recipe() noexcept = default;

            Recipe& operator=(Recipe const& rhs) noexcept = delete;
            Recipe& operator=(Recipe&& rhs) noexcept = delete;

        public:
            int getBakeTime() const noexcept;

            std::vector<int> getIngredients() const noexcept;

        private:
            int _bakeTime;
            std::vector<int> _ingredients;
    };
}

#endif /* !RECIPE_HPP */