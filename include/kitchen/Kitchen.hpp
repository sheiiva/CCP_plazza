/*
** EPITECH PROJECT, 2019
** INCLUDE // KITCHEN
** File description:
** Kitchen.hpp
*/

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include <map>
#include <string>
#include <algorithm>
#include "Cook.hpp"
#include "../pizza/Pizza.hpp"

namespace Plazza
{
    class Cook;
    class Kitchen
    {
    public:

        Kitchen() noexcept;
        Kitchen(Kitchen const& b) noexcept;
        Kitchen(Kitchen&& b) noexcept;
        ~Kitchen() noexcept;
        Kitchen& operator=(Kitchen const& rhs) noexcept;
        Kitchen& operator=(Kitchen&& rhs) noexcept;

        //GETTER
        int getInactiveTime(void) const noexcept;
        Cook getCook(int index) const noexcept;
        std::vector<Cook> getCooks() const noexcept;
        int getIngredientsStock(const std::string &ingredient) const noexcept;
        std::map<std::string, int> getIngredientsStock() const noexcept;
        //SETTER
        void setInactiveTime(int time) noexcept;
        void setCook(Cook const &cook) noexcept;
        void setIngredientsStock(const std::string &ingredient) noexcept;
        //METHODS
        bool checkCookStatus() noexcept;
        Kitchen& operator<<(Pizza const &pizza) noexcept;
        // virtual Pizza& operator>>(Pizza&& rhsCook &cook) noexcept = 0;
        
    protected:
        int _inactiveTime;
        std::vector<Cook> _cooks;
        std::map<std::string, int> _ingredientsStock;
    };
}

#endif /* !KITCHEN_HPP */
