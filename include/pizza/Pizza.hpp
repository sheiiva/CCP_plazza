/*
** EPITECH PROJECT, 2019
** INCLUDE // PIZZA
** File description:
** Pizza.hpp
*/

#ifndef PIZZA_HPP
#define PIZZA_HPP

#include <vector>
#include <string>
#include "Recipe.hpp"

namespace Plazza
{

    class Pizza
    {
        public:
            Pizza() noexcept = default;
            Pizza(const std::string &pizzaName, std::vector<int> &neededIngredients, int bakeTime) noexcept;
            Pizza(const Pizza &b) noexcept = default;
            Pizza(Pizza &&b) noexcept = default;
            ~Pizza() noexcept = default;
            Pizza &operator=(const Pizza &rhs) noexcept;
            Pizza &operator=(Pizza &&rhs) noexcept = default;
    

        public:
            //GETTERS
            int getBakeTime(void) const noexcept;
            int getClock(void) const noexcept;
            std::vector<int> getNeededIngredients() const noexcept;
            int getNeedIngredients(int index) const noexcept;
            Recipe getRecipe(void) noexcept;
            //SETTERS
            void setBakeTime(int bakeTime) const noexcept;
            void setClock(int clock) const noexcept;
            void setNeededIngredients(int neededIngredient) const noexcept;
            //METHODS
            void bake() noexcept;
            // Pizza& operator<<(std::list<int> &ingredients) noexcept; // SAME AS bake
            //Pizza& operator>>(Kitchen const &kitchen) noexcept

        protected:
            int _clock;
            Recipe _recipe;
    };
}

#endif /* !PIZZA_HPP */
