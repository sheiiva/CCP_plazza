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
#include "Kitchen.hpp"

namespace Plazza
{
    class Pizza
    {
        public:
            Pizza() noexcept = delete;
            Pizza(std::list<int> &neededIngredients, int bakeTime) noexcept;
            Pizza(Pizza const& b) noexcept = default;
            Pizza(Pizza&& b) noexcept = default;
            ~Pizza() noexcept = default;
            Pizza& operator=(Pizza const& rhs) noexcept = default;
            Pizza& operator=(Pizza&& rhs) noexcept = default;

        public:
            //GETTERS
            int getBakeTime(void) const noexcept;
            int getClock(void) const noexcept;
            std::list<int> getNeededIngredients() const noexcept;
            int getNeedIngredients(int index) const noexcept;
            //SETTERS
            void setBakeTime(int bakeTime) const noexcept;
            void setClock(int clock) const noexcept;
            void setNeededIngredients(int neededIngredient) const noexcept;
            //METHODS
            void bake() noexcept;
            // Pizza& operator<<(std::list<int> &ingredients) noexcept; // SAME AS bake
            //Pizza& operator>>(Kitchen const &kitchen) noexcept;

        protected:
            int _bakeTime;
            int _clock;
            std::list<int> _neededIngredients;
    };
}

#endif /* !PIZZA_HPP */
