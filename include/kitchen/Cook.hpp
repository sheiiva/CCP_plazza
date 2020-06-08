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
    #include <unistd.h>
    #include <condition_variable>

    #include "Pizza.hpp"

    namespace Plazza
    {
        enum STATUS {
            FIRED       = -1,
            INACTIVE    = 0,
            ACTIVE      = 1,
            BUSY        = 2
        };

        class Cook
        {
            public:
                Cook();
                Cook(Cook const& b) noexcept = delete;
                Cook(Cook&& b) noexcept = delete;
                ~Cook() noexcept;
                Cook& operator=(Cook const& rhs) noexcept = delete;
                Cook& operator=(Cook&& rhs) noexcept = delete;

                //GETTERS
                int getStatus() const noexcept;
                //SETTERS
                void setStatus(int status) noexcept;
                //METHODS
                bool assignOrder(Pizza const& pizza) noexcept;
                void bake(void);
                void unlock(void);
                bool pred(void);

            private:
                std::condition_variable _condition;
                int _status = INACTIVE;
                std::queue<Pizza> _orders;
                std::thread _thread;
        };
    
    }

#endif /* !COOK_HPP */