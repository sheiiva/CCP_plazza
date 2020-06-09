/*
** EPITECH PROJECT, 2019
** INCLUDE // RECEPTION
** File description:
** Reception.hpp
*/

#ifndef RECEPTION_HPP
    #define RECEPTION_HPP

    #include <map>
    #include <string>
    #include "Kitchen.hpp"
    #include "Parser.hpp"
    #include "Pizza.hpp"

    namespace Plazza
    {
        enum ReturnState
        {
            SUCCESS = 0,
            FAILURE = 1
        };

        class Reception
        {
            public:
                Reception() noexcept = delete;
                Reception(int bakeTimeWeight, int maxCook, int stockRegen) noexcept;
                Reception(Reception const& b) noexcept = delete;
                Reception(Reception&& b) noexcept = delete;
                ~Reception() noexcept = default;
                Reception& operator=(Reception const& rhs) noexcept = delete;
                Reception& operator=(Reception&& rhs) noexcept = delete;

            public:
            
                // //GETTERS
                int getBakeTimeWeight(void) const noexcept;
                int getMaxCook(void) const noexcept;
                int getStockRegen(void) const noexcept;
                // //SETTERS
                void setBakeTimeWeight(int value) noexcept;
                void setMaxCook(int value) noexcept;
                void setStockRegen(int value) noexcept; 
                // //METHODS
                void initStock(void) noexcept;
                void initMenu(void) noexcept;
                int run() noexcept;
                bool process(int action) noexcept;
                std::string read_stdin(void) noexcept;
                void createNewKitchen(void) noexcept;
                bool assignToKitchen(int importance) noexcept;
                void assignOrder(void) noexcept;
                void status() const noexcept;

            public:
                static int start(int bakeTimeWeight, int maxCook, int stockRegen) noexcept
                {
                    Reception reception(bakeTimeWeight, maxCook, stockRegen);

                    return (reception.run());
                }

            private:
                int _bakeTimeWeight;
                int _maxCook;
                int _stockRegen;
                std::queue<Pizza> _orders;
                std::vector<Kitchen> _kitchens;
                std::map<std::string, int>_stock;
                std::map<std::string, Pizza> _menu;
        };
    }

#endif /* !RECEPTION_HPP */
