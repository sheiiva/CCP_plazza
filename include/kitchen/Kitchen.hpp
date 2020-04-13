/*
** EPITECH PROJECT, 2019
** INCLUDE // KITCHEN
** File description:
** Kitchen.hpp
*/

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include <list>
#include <map>
#include <string>
#include "Cook.hpp"
#include "Pizza.hpp"

namespace Plazza
{
    class Kitchen
    {
        public:
            Kitchen() noexcept = default;
            Kitchen(Kitchen const& b) noexcept = default;
            Kitchen(Kitchen&& b) noexcept = default;
            ~Kitchen() noexcept = default;
            Kitchen& operator=(Kitchen const& rhs) noexcept;
            Kitchen& operator=(Kitchen&& rhs) noexcept;

            //GETTER
            int getInactiveTime(void) noexcept;
            Cook getCook(int index) const noexcept;
            std::list<Cook> getCooks() const noexcept;
            int getIngredientsStock(const std::string &ingredient) const noexcept;
            std::map<std::string, int> getIngredientsStock() const noexcept;
            //SETTER
            void setInactiveTime(int time) noexcept;
            void setCook(Cook const &cook) const noexcept;
            void setIngredientsStock(const std::string &ingredient) const noexcept;
            //METHODS
            bool checkCookStatus() noexcept;
            Kitchen& operator<<(Pizza const &pizza) noexcept;
            // virtual Pizza& operator>>(Pizza&& rhsCook &cook) noexcept = 0;

        protected:
            int _inactiveTime;
            std::list<Cook> _cooks;
            std::map<std::string, int> _ingredientsStock;
    };
}

#endif /* !KITCHEN_HPP */