/*
** EPITECH PROJECT, 2019
** INCLUDE // KITCHEN
** File description:
** Kitchen.hpp
*/

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include <algorithm>
#include <map>
#include <string>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

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
            pid_t getPid() const noexcept;
            pid_t getPpid() const noexcept;
            time_t getInactiveTime(void) const noexcept;
            size_t getMaxCook(void) const noexcept;
            Cook getCook(int index) const;
            int getIngredientStock(std::string const& ingredient) const noexcept;
            //SETTER
            void setInactiveTime(time_t time) noexcept;
            void setIngredientToStock(const std::string &ingredient) noexcept;
            //METHODS
            bool isKitchenActive(void) noexcept;
            void contractCook(Pizza const& pizza) noexcept;
            bool assignOrder(Pizza const& pizza, int importance) noexcept;

        private:
            void updateTime(bool reset) noexcept;

        private:
            int _pipefd[2];
            pid_t _pid;
            pid_t _ppid;
            time_t _inactiveTime;
            size_t _maxCook;
            std::vector<Cook> _cooks;
            std::map<std::string, int> _ingredientsStock;
    };
}

#endif /* !KITCHEN_HPP */
