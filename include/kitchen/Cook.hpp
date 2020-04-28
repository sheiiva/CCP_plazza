/*
** EPITECH PROJECT, 2019
** INCLUDE // KITCHEN
** File description:
** Cook.hpp
*/

#ifndef COOK_HPP
#define COOK_HPP

#include <queue>
#include <thread>
#include <mutex>
#include "Kitchen.hpp"
#include "Pizza.hpp"

namespace Plazza
{
    enum STATUS {
        INACTIVE    = 0,
        ACTIVE      = 1
    };

    class Kitchen;
    class Pizza;
    class Cook
    {
    public:
        Cook() noexcept = delete;
        Cook(const Kitchen& Kitchen) noexcept;
        Cook(Cook const& b) noexcept;
        Cook(Cook&& b) noexcept = default;
        ~Cook() noexcept = default;
        Cook& operator=(Cook const& rhs) noexcept = default;
        Cook& operator=(Cook&& rhs) noexcept = default;
        
        //GETTERS
        int getStatus() noexcept;
        Pizza& getOrder(int index) noexcept;
        Kitchen getKitchen() const noexcept;
        //SETTERS
        void setStatus(int status) noexcept;
        void setOrder(Pizza const& pizza) noexcept;
        //METHODS
        // Cook& operator>>(Cook&& rhs) noexcept = default;
        Cook& operator<<(Pizza const& pizza) noexcept; // SAME AS setOrder
        
    private:
        int _status;
        std::thread _thread;
        std::mutex _mutex;
        std::queue<Pizza> _orders;
        const Kitchen &_kitchen;
    };
}

#endif /* !COOK_HPP */
