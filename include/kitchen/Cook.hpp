/*
** EPITECH PROJECT, 2019
** INCLUDE // KITCHEN
** File description:
** Cook.hpp
*/

#ifndef COOK_HPP
#define COOK_HPP

#include <iostream>
#include <functional>
#include <queue>
#include <thread>
#include <mutex>
// #include "Kitchen.hpp"
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
            Cook(Pizza const& pizza) noexcept;// = delete;
            // Cook(const Kitchen &Kitchen) noexcept;
            Cook(Cook const &b) noexcept;
            Cook(Cook &&b) noexcept;
            ~Cook() noexcept;
            Cook& operator=(Cook const &rhs) noexcept;
            Cook& operator=(Cook &&rhs) noexcept;

            //GETTERS
            int getStatus() const noexcept;
            // Pizza &getOrder() noexcept;
            // Kitchen getKitchen() const noexcept;
            //SETTERS
            void setStatus(int status) noexcept;
            //METHODS
            bool assignOrder(Pizza const &pizza) noexcept;
            // Cook& operator>>(Cook&& rhs) noexcept = default;
            // Cook& operator<<(Pizza const& pizza) noexcept; // SAME AS setOrder

        private:
            int _status;
            std::thread _thread;
            std::mutex _mutex;
            std::queue<Pizza> _orders;
            // const Kitchen _kitchen; //THIS SHOULD NOT BE A POINTER
    };
}

#endif /* !COOK_HPP */