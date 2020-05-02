/*
** EPITECH PROJECT, 2019
** INCLUDE // KITCHEN
** File description:
** Kitchen.hpp
*/

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include <time.h>
#include <map>
#include <string>
#include <algorithm>
#include "Cook.hpp"
#include "Pizza.hpp"

namespace Plazza
{
    class Kitchen
    {
    public:
        Kitchen() noexcept = delete;
        Kitchen(std::vector<std::string> stock, int maxCook) noexcept;
        Kitchen(Kitchen const& b) noexcept;
        Kitchen(Kitchen&& b) noexcept;
        ~Kitchen() noexcept = default;
        Kitchen& operator=(Kitchen const& rhs) noexcept;
        Kitchen& operator=(Kitchen&& rhs) noexcept;

        //GETTER
        long int getInactiveTime(void) const noexcept;
        Cook getCook(int index) const noexcept;
        int getIngredientStock(const std::string &ingredient) const noexcept;
        //SETTER
        void setInactiveTime(long int time) noexcept;
        void setIngredientToStock(const std::string &ingredient) noexcept;
        //METHODS
        bool isKitchenActive() noexcept;
        bool assignOrder(Pizza const &pizza, int importance) noexcept;
 
        // Kitchen& operator<<(Pizza const &pizza) noexcept;
        // virtual Pizza& operator>>(Pizza&& rhsCook &cook) noexcept = 0;
        void updateIngredientsStock(std::vector<std::string> stock) noexcept;
        void contractCook(Pizza const &pizza) noexcept;

        private:
            void updateTime(bool reset) noexcept;
            bool isInStock(std::string ingredient);

    protected:
        long int _inactiveTime;
        int _maxCook;
        std::vector<Cook> _cooks;
        std::map<std::string, int> _ingredientsStock;
    };
}

#endif /* !KITCHEN_HPP */
