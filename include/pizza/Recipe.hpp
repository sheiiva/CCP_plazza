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
            Recipe(const std::string &pizzaName, std::vector<int> ingredients, int bakeTime) noexcept;
            Recipe() noexcept = delete;
            Recipe(const Recipe &b) noexcept = default;
            Recipe(Recipe &&b) noexcept = default;
            ~Recipe() noexcept = default;

            Recipe &operator=(Recipe &rhs) noexcept = default;
            Recipe &operator=(Recipe &&rhs) noexcept = default;

        public:
            int getBakeTime() const noexcept;

            std::vector<int> getIngredients() const noexcept;

        private:
            std::string _pizzaName;
            std::vector<int> _ingredients;
            int _bakeTime;
    };
}

#endif /* !RECIPE_HPP */