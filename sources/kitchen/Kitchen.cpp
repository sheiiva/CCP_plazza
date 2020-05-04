/*
** EPITECH PROJECT, 2020
** Kitchen.cpp
** File description:
** kitchen functions
*/

#include "Kitchen.hpp"

namespace Plazza
{
    Kitchen::Kitchen(std::vector<std::string> stock, int maxCook) noexcept :
        _pid(0), _ppid(getpid()),_inactiveTime(time(NULL)), _maxCook(maxCook)
    {
        for (auto &ingredient : stock)
            _ingredientsStock[ingredient] = 5;
        _pid = fork();
        if (_pid == -1) {
            std::cerr << "Fork failed :: Can't create a new Kitchen" << std::endl;
            this->~Kitchen();
        } else if (!_pid) {
            _pid = getpid();
            _ppid = getppid();
        }
    }

    Kitchen::Kitchen(Kitchen const& b) noexcept :
        _pid(b._pid),
        _inactiveTime(b._inactiveTime),
        _maxCook(b._maxCook),
        _cooks(b._cooks),
        _ingredientsStock(b._ingredientsStock)
    {
    }

    Kitchen::Kitchen(Kitchen&& b) noexcept :
        _pid(b._pid),
        _inactiveTime(b._inactiveTime),
        _maxCook(b._maxCook),
        _cooks(std::move(b._cooks)),
        _ingredientsStock(std::move(b._ingredientsStock))
    {
    }
    
    Kitchen &Kitchen::operator=(Kitchen const& rhs) noexcept
    {
        _pid = rhs._pid;
        _inactiveTime = rhs._inactiveTime;
        _maxCook = rhs._maxCook,
        _cooks = rhs._cooks;
        _ingredientsStock = rhs._ingredientsStock;
        return (*this);
    }

    Kitchen &Kitchen::operator=(Kitchen&& rhs) noexcept
    {
        _pid = rhs._pid;
        _inactiveTime = rhs._inactiveTime;
        _maxCook = rhs._maxCook,
        _cooks.swap(rhs._cooks);
        _ingredientsStock.swap(rhs._ingredientsStock);
        return (*this);
    }

    pid_t Kitchen::getPid() const noexcept
    {
        return (_pid);
    }

    pid_t Kitchen::getPpid() const noexcept
    {
        return (_ppid);
    }

    time_t Kitchen::getInactiveTime(void) const noexcept
    {
        return (_inactiveTime);
    }

    size_t Kitchen::getMaxCook(void) const noexcept
    {
        return (_maxCook);
    }
    
    Cook Kitchen::getCook(int index) const
    {
        return (_cooks[index]);
    }
    
    int Kitchen::getIngredientStock(std::string const& ingredient) const noexcept
    {
        return (_ingredientsStock.find(ingredient)->second);
    }

    void Kitchen::setInactiveTime(time_t time) noexcept
    {
        _inactiveTime = time;
    }
    
    void Kitchen::setIngredientToStock(std::string const& ingredient) noexcept
    {
        _ingredientsStock.emplace(ingredient, 5);
    }

    void Kitchen::updateTime(bool reset) noexcept
    {
        static long int initialTime = time(NULL);

        if (reset)
            initialTime = time(NULL);
        _inactiveTime = time(NULL) - initialTime;
    }

    bool Kitchen::isKitchenActive(void) noexcept
    {
        if (_cooks.size() != 0) {
            updateTime(true);
            return (true);
        } else {
            updateTime(false);
            return (false);
        }
    }

    void Kitchen::contractCook(Pizza const& pizza) noexcept
    {
        std::cout << "New cook in the kitchen!" << std::endl;
        _cooks.push_back(Cook(pizza));
    }

    bool Kitchen::assignOrder(Pizza const& pizza, int importance) noexcept
    {
        if (_cooks.size() < _maxCook) {
            contractCook(pizza);
            return (true);
        }
        for (auto &i : _cooks) {
            if (i.getStatus() < importance) {
                i.setStatus(i.getStatus() + 1);
                i.assignOrder(pizza);
                return (true);
            }
        }
        return (false);
    }
}
