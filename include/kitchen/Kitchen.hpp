/*
** EPITECH PROJECT, 2019
** INCLUDE // KITCHEN
** File description:
** Kitchen.hpp
*/

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include <algorithm>
#include <fcntl.h>
#include <iostream>
#include <iterator>
#include <map>
#include <poll.h>
#include <sstream>
#include <string>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include "Cook.hpp"
#include "Pizza.hpp"

namespace Plazza
{
    enum NAMEDPIPE {
        READ_END    = 0,
        WRITE_END   = 1
    };

    class Kitchen
    {
        public:
            Kitchen() noexcept = delete;
            Kitchen(std::map<std::string, Pizza> menu, std::vector<std::string> stock, int maxCook) noexcept;
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
            Pizza& getPizza(std::string const& pizzaName) noexcept;
            //SETTER
            void setInactiveTime(time_t time) noexcept;
            void setIngredientToStock(const std::string &ingredient) noexcept;
            //METHODS
            bool isKitchenActive(void) noexcept;
            void contractCook(Pizza const& pizza) noexcept;
            bool assignOrder(Pizza& pizza, int importance) noexcept;
            bool childLoop(void);
            bool parsInput(std::string&& command);
            void status(void);
            void quit(void);

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
            std::map<std::string, Pizza> _menu;
    };
}

#endif /* !KITCHEN_HPP */
