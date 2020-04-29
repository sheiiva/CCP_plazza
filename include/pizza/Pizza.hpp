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
#include "../kitchen/Kitchen.hpp"
#include "Recipe.hpp"

namespace Plazza
{
    class Pizza {
    public:
        Pizza() noexcept = delete;
        Pizza(const std::string &pizzaName, std::vector<int> &neededIngredients, int bakeTime) noexcept;
        Pizza(Pizza const& b) noexcept;
        Pizza(Pizza&& b) noexcept;
        ~Pizza() noexcept;
        Pizza& operator=(Pizza const& rhs) noexcept;
        Pizza& operator=(Pizza&& rhs) noexcept;
        
    public:
        //GETTERS
        int getClock(void) const noexcept;
        std::vector<int> getNeededIngredients(void) const noexcept;
        int getNeedIngredient(int index) const noexcept;
        Recipe getRecipe(void) noexcept;
        //SETTERS
        void setClock(int clock) noexcept;
        void setNeededIngredients(int neededIngredient) noexcept;
        //METHODS
        void bake(void) noexcept;
        // Pizza& operator<<(std::list<int> &ingredients) noexcept; // SAME AS bake
        // Pizza& operator>>(const Kitchen &kitchen) noexcept;
                
    protected:
        int _clock;
        std::vector<int> _neededIngredients;
        Recipe _recipe;
    };
}

#endif /* !PIZZA_HPP */
