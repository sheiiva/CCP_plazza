/*
** EPITECH PROJECT, 2019
** INCLUDE // PIZZA
** File description:
** Pizza.hpp
*/

#ifndef PIZZA_HPP
#define PIZZA_HPP

#include <list>
#include <string>
#include "../kitchen/Kitchen.hpp"

namespace Plazza
{
    class Pizza
    {
        public:
            Pizza() noexcept = delete;
            Pizza(std::vector<int> &neededIngredients, int bakeTime) noexcept;
            Pizza(Pizza const& b) noexcept = default;
            Pizza(Pizza&& b) noexcept = default;
            ~Pizza() noexcept;
            Pizza& operator=(Pizza const& rhs) noexcept = default;
            Pizza& operator=(Pizza&& rhs) noexcept = default;

        public:
            //GETTERS
            int getBakeTime(void) const noexcept;
            int getClock(void) const noexcept;
            std::vector<int> getNeededIngredients(void) const noexcept;
            int getNeedIngredient(int index) const noexcept;
            //SETTERS
            void setBakeTime(int bakeTime) noexcept;
            void setClock(int clock) noexcept;
            void setNeededIngredients(int neededIngredient) noexcept;
            //METHODS
            void bake(void) noexcept;
            // Pizza& operator<<(std::list<int> &ingredients) noexcept; // SAME AS bake
        // Pizza& operator>>(Kitchen const &kitchen) noexcept;

        protected:
            int _bakeTime;
            int _clock;
            std::vector<int> _neededIngredients;
    };
}

#endif /* !PIZZA_HPP */
