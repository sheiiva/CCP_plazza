/*
** EPITECH PROJECT, 2019
** INCLUDE // RECEPTION
** File description:
** Core.hpp
*/

#ifndef CORE_HPP
#define CORE_HPP

#include <map>
#include <string>
#include <vector>
#include <queue>
#include "Pizza.hpp"
#include "Kitchen.hpp"

namespace Plazza
{
    class Core
    {
        public:
            Core() noexcept = default;
            Core(Core const& b) noexcept = default;
            Core(Core&& b) noexcept = default;
            ~Core() noexcept = default;
            Core& operator=(Core const& rhs) noexcept = default;
            Core& operator=(Core&& rhs) noexcept = default;

            //GETTERS
            Kitchen& getKitchen(int index) noexcept;
            std::vector<Kitchen> getKitchen() noexcept;
            // int getStock(std::string) const noexcept;
            // std::map<std::string, int> getStock() noexcept;
            int getPizza(std::string) const noexcept;
            std::map<std::string, int> getPizza() noexcept;
            //SETTERS
            void setKitchen(Kitchen &kitchen) noexcept;
            // void setStock(const std::string &ingredient) noexcept;
            void setPizza(Pizza &pizza) noexcept;
            //METHODS
            int run() noexcept;
            std::string read_stdin(void) noexcept;
            void parser(void) noexcept;
            int assignOrder(void) noexcept;
            int checkKitchen() noexcept;
            bool status() noexcept;
            // Core& operator<<(Pizza const &pizza) noexcept; // 
            // Core& operator>>(Core&& rhs) noexcept;

        private:
            std::string _input;
            std::queue<Pizza> _orders;
            std::vector<Kitchen> _kitchens;
            // std::map<std::string, int> _stock;
            std::map<std::string, std::list<int>> _menu;
            std::map<std::string, int> _bakeTime;
    };
}

#endif /* !CORE_HPP */