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
            Recipe(const std::string &pizzaName, std::vector<int> ingredients, int bakeTime) noexcept;
            Recipe(const Recipe &b) noexcept;
            Recipe(Recipe &&b) noexcept;
            ~Recipe() noexcept;

            Recipe &operator=(Recipe const &rhs) noexcept;
            Recipe &operator=(Recipe &&rhs) noexcept;

        public:
            std::string getPizzaName(void) const noexcept;
            std::vector<int> getIngredients() const noexcept;
            int getBakeTime() const noexcept;

        private:
            std::string _pizzaName;
            std::vector<int> _ingredients;
            int _bakeTime;
    };
}

#endif /* !RECIPE_HPP */
