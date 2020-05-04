/*
** EPITECH PROJECT, 2019
** INCLUDE // PIZZA
** File description:
** Pizza.hpp
*/

#ifndef PIZZA_HPP
#define PIZZA_HPP

#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <mutex>
#include "Recipe.hpp"

namespace Plazza
{

    class Pizza
    {
        public:
            Pizza() noexcept = default;
            Pizza(const std::string &pizzaName, std::vector<int> &neededIngredients, int bakeTime) noexcept;
            Pizza(const Pizza &b) noexcept;
            Pizza(Pizza &&b) noexcept;
            ~Pizza() noexcept = default;
            Pizza &operator=(const Pizza &rhs) noexcept;
            Pizza &operator=(Pizza &&rhs) noexcept;
    
        public:
            //GETTERS
            int getClock(void) const noexcept;
            Recipe getRecipe(void) noexcept;
            //SETTERS
            void setClock(int clock) noexcept;
            //METHODS
            void bake(void);

        private:
            int _clock;
            Recipe _recipe;
    };
}

#endif /* !PIZZA_HPP */
