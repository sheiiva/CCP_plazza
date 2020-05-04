/*
** EPITECH PROJECT, 2019
** INCLUDE // KITCHEN
** File description:
** Cook.hpp
*/

#ifndef COOK_HPP
#define COOK_HPP

#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

#include "Pizza.hpp"

namespace Plazza
{
    enum STATUS {
        INACTIVE    = 0,
        ACTIVE      = 1,
        BUSY        = 2
    };

    class Cook
    {
        public:
            Cook() noexcept = delete;
            Cook(Pizza const& pizza) noexcept;
            Cook(Cook const& b) noexcept;
            Cook(Cook&& b) noexcept;
            ~Cook() noexcept = default;
            Cook& operator=(Cook const& rhs) noexcept;
            Cook& operator=(Cook&& rhs) noexcept;

            //GETTERS
            int getStatus() const noexcept;
            //SETTERS
            void setStatus(int status) noexcept;
            //METHODS
            bool assignOrder(Pizza const& pizza) noexcept;
            void cook();

        private:
            int _status;
            std::queue<Pizza> _orders;
    };
}

#endif /* !COOK_HPP */