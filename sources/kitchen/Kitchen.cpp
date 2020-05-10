/*
** EPITECH PROJECT, 2020
** Kitchen.cpp
** File description:
** kitchen functions
*/

#include "Kitchen.hpp"

namespace Plazza
{
    Kitchen::Kitchen(std::map<std::string, Pizza> menu, std::vector<std::string> stock, int maxCook) noexcept :
        _pid(0), _ppid(getpid()),_inactiveTime(time(NULL)), _maxCook(maxCook), _menu(menu)
    {
        for (auto &ingredient : stock)
            _ingredientsStock[ingredient] = 5;
        if (pipe(_pipefd) == -1) {
            std::cerr << "Pipe :: failed" << std::endl;
            this->~Kitchen();
            return;
        }
        _pid = fork();
        if (_pid == -1) {
            std::cerr << "Fork failed :: Can't create a new Kitchen" << std::endl;
            this->~Kitchen();
        } else if (_pid) {
            if (close(_pipefd[READ_END]) == -1)
                std::cerr << "Close :: can't close unused read end" << std::endl;
        } else {
            _pid = getpid();
            childLoop();
        }
    }

    Kitchen::Kitchen(Kitchen const& b) noexcept :
        _pid(b._pid),
        _inactiveTime(b._inactiveTime),
        _maxCook(b._maxCook),
        _cooks(b._cooks),
        _ingredientsStock(b._ingredientsStock),
        _menu(b._menu)
    {
    }

    Kitchen::Kitchen(Kitchen&& b) noexcept :
        _pid(b._pid),
        _inactiveTime(b._inactiveTime),
        _maxCook(b._maxCook),
        _cooks(std::move(b._cooks)),
        _ingredientsStock(std::move(b._ingredientsStock)),
        _menu(std::move(b._menu))
    {
    }

    Kitchen &Kitchen::operator=(Kitchen const& rhs) noexcept
    {
        _pid = rhs._pid;
        _inactiveTime = rhs._inactiveTime;
        _maxCook = rhs._maxCook,
        _cooks = rhs._cooks;
        _ingredientsStock = rhs._ingredientsStock;
        _menu = rhs._menu;
        return (*this);
    }

    Kitchen &Kitchen::operator=(Kitchen&& rhs) noexcept
    {
        _pid = rhs._pid;
        _inactiveTime = rhs._inactiveTime;
        _maxCook = rhs._maxCook,
        _cooks.swap(rhs._cooks);
        _ingredientsStock.swap(rhs._ingredientsStock);
        _menu.swap(rhs._menu);
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

    Pizza& Kitchen::getPizza(std::string const& pizzaName) noexcept
    {
        return _menu[pizzaName];
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

    bool Kitchen::assignOrder(Pizza& pizza, int importance) noexcept
    {
        std::string command("PIZZA");

        if (_ppid == getpid()) {
            command.append(";");
            command.append(pizza.getRecipe().getPizzaName());
            command.append(";");
            command.append(std::to_string(importance));
            fdopen(_pipefd[1], "w");
            if (write(_pipefd[WRITE_END], command.c_str(), command.length()) == -1)
                std::cerr << "Write :: Can't write in the pipe" << std::endl;
            close(_pipefd[WRITE_END]);
            //wait for return value
            return (true);
        } else {
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

    void Kitchen::status(void) const
    {
        std::string command;

        if (_ppid == getpid()) {
            command.assign("STATUS");
            fdopen(_pipefd[1], "w");
            if (write(_pipefd[WRITE_END], command.c_str(), command.length()) == -1)
                std::cerr << "Write :: Can't write in the pipe" << std::endl;
            close(_pipefd[WRITE_END]);
        } else {
            for (auto &cook : _cooks) {
                if (cook.getStatus() == INACTIVE)
                    std::cout << "Cook inactive." << std::endl;
                else {
                    std::cout << "Cook is cooking";
                    if (cook.getStatus() == BUSY)
                        std::cout << ", another pending order." << std::endl;
                    else
                        std::cout << "." << std::endl;
                }
            }
        }
    }

    void Kitchen::quit(void)
    {
        std::string command;

        if (_ppid == getpid()) {
            command.assign("QUIT");
            fdopen(_pipefd[1], "w");
            if (write(_pipefd[WRITE_END], command.c_str(), command.length()) == -1)
                std::cerr << "Write :: Can't write in the pipe" << std::endl;
            close(_pipefd[WRITE_END]);
        } else
            _exit(EXIT_SUCCESS);
    }

    bool Kitchen::parsInput(std::string&& command)
    {
        std::replace(command.begin(), command.end(), ';', ' ');
        std::istringstream iss(command);
        std::vector<std::string> parsedInput(std::istream_iterator<std::string>{iss},
                                        std::istream_iterator<std::string>()); 

        if (!command.compare("QUIT"))
            _exit(EXIT_SUCCESS);
        else if (!command.compare("STATUS"))
            status();
        else if (!parsedInput[0].compare("PIZZA"))
            return (assignOrder(_menu[parsedInput[1]], atoi(parsedInput[2].c_str())));
        return (true);
    }

    bool Kitchen::childLoop()
    {
        pollfd pfds;
        char c;
        char buf[100];
        size_t i = 0;
        bool status = true;

        pfds.fd = _pipefd[READ_END];
        pfds.events = POLLIN;
        if (close(_pipefd[WRITE_END]) == -1)
            std::cerr << "Close :: can't close unused write end" << std::endl;
        memset(buf, 0, 100);
        while(status) {
            if (poll(&pfds, 2, -1)) {
                while (read(_pipefd[READ_END], &c, 1) > 0)
                    buf[i++] = c;
                i = 0;
                close(_pipefd[READ_END]);
                parsInput(std::string(buf));
                memset(buf, 0, 100);
            }
        }
        _exit(EXIT_SUCCESS);
    }

}
