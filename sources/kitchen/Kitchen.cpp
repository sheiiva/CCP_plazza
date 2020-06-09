/*
** EPITECH PROJECT, 2020
** Kitchen.cpp
** File description:
** kitchen functions
*/

#include "Kitchen.hpp"

namespace Plazza
{
    Kitchen::Kitchen(std::map<std::string, Pizza> menu, std::map<std::string, int> stock, int maxCook) noexcept :
        _childPid(0), _parentPid(getpid()),_inactiveTime(time(NULL)), _maxCook(maxCook), _menu(menu)
    {
        if (pipe(_pipefdP) == -1) {
            perror("Pipe :: failed");
            // this->~Kitchen(); // PREFER TO THROW AN ERROR AND quit THE PROGRAM
            return;
        }
        if (pipe(_pipefdC) == -1) {
            perror("Pipe :: failed");
            // this->~Kitchen(); // PREFER TO THROW AN ERROR AND quit THE PROGRAM
            return;
        }
        _childPid = fork();
        if (_childPid == -1) {
            perror("Fork failed :: Can't create a new Kitchen");
            // this->~Kitchen(); // PREFER TO THROW AN ERROR AND quit THE PROGRAM
        } else if (_childPid == 0) {
            for (auto &ingredient : stock)
                _ingredientsStock[ingredient.first] = 5;
            for (size_t i = 0; i < _maxCook ; i++)
                _cooks.push_back(new Cook());
            _childPid = getpid();
            childLoop();
        }
    }

    Kitchen::Kitchen(Kitchen&& b) noexcept :
        _childPid(b._childPid),
        _parentPid(b._parentPid),
        _inactiveTime(b._inactiveTime),
        _maxCook(b._maxCook),
        _cooks(std::move(b._cooks)),
        _ingredientsStock(std::move(b._ingredientsStock)),
        _menu(std::move(b._menu))
    {
        _pipefdP[READ_END] = b._pipefdP[READ_END];
        _pipefdP[WRITE_END] = b._pipefdP[WRITE_END];
        _pipefdC[READ_END] = b._pipefdC[READ_END];
        _pipefdC[WRITE_END] = b._pipefdC[WRITE_END];
    }

    Kitchen &Kitchen::operator=(Kitchen&& rhs) noexcept
    {
        _pipefdP[READ_END] = rhs._pipefdP[READ_END];
        _pipefdP[WRITE_END] = rhs._pipefdP[WRITE_END];
        _pipefdC[READ_END] = rhs._pipefdC[READ_END];
        _pipefdC[WRITE_END] = rhs._pipefdC[WRITE_END];
        _childPid = rhs._childPid;
        _parentPid = rhs._parentPid;
        _inactiveTime = rhs._inactiveTime;
        _maxCook = rhs._maxCook,
        _cooks.swap(rhs._cooks);
        _ingredientsStock.swap(rhs._ingredientsStock);
        _menu.swap(rhs._menu);
        return (*this);
    }

    Kitchen::~Kitchen() noexcept
    {
        for (auto &cook : _cooks)
            delete cook;
    }

    pid_t Kitchen::getChildPid() const noexcept
    {
        return (_childPid);
    }
    pid_t Kitchen::getParentPid() const noexcept
    {
        return (_parentPid);
    }

    time_t Kitchen::getInactiveTime(void) const noexcept
    {
        return (_inactiveTime);
    }

    size_t Kitchen::getMaxCook(void) const noexcept
    {
        return (_maxCook);
    }
    
    // Cook Kitchen::getCook(int index) const
    // {
    //     return (_cooks[index]);
    // }
    
    int Kitchen::getIngredientStock(std::string const& ingredient) const noexcept
    {
        return (_ingredientsStock.find(ingredient)->second);
    }

    Pizza& Kitchen::getPizza(std::string const& pizzaName) noexcept
    {
        return (_menu[pizzaName]);
    }

    void Kitchen::setIngredientStock(std::string const& ingredient, int stock) noexcept
    {
        _ingredientsStock[ingredient] = stock;
    }

    // void Kitchen::updateTime(bool reset) noexcept
    // {
    //     static long int initialTime = time(NULL);

    //     if (reset)
    //         initialTime = time(NULL);
    //     _inactiveTime = time(NULL) - initialTime;
    // }

    // bool Kitchen::isKitchenActive(void) noexcept
    // {
    //     if (_cooks.size() != 0) {
    //         updateTime(true);
    //         return (true);
    //     } else {
    //         updateTime(false);
    //         return (false);
    //     }
    // }

    // // COMPARE TIMESTAMP KITCHEN TO ACTUAL TIMESTAMP TO RECHARGE INGREDIENT

    bool Kitchen::assignOrder(Pizza& pizza, int importance) noexcept
    {       
        std::string command("PIZZA");
        char c = 0;
        size_t i = 0;
        pollfd pfds;
        char buf[100];

        if (_parentPid == getpid()) {
            command.append(";");
            command.append(pizza.getPizzaName());
            command.append(";");
            command.append(std::to_string(importance));
            command.append("\n");
            if (write(_pipefdP[WRITE_END], command.c_str(), command.length()) == -1)
                perror("Write :: Can't write in the pipe");
            pfds.fd = _pipefdC[READ_END];
            pfds.events = POLLIN;
            if (poll(&pfds, 1, -1)) {
                if (!memset(buf, 0, 100)) {
                    std::cerr << "Memset :: failed" << std::endl;
                    return (false);
                }
                while (read(_pipefdC[READ_END], &c, 1) > 0) {
                    if (c == '\n')
                        break;
                    buf[i++] = c;
                }
            }
            return ((std::string(buf) == "True") ? true : false);
        } else {
            for (auto &cook : _cooks) {
                if (cook->getStatus() < importance) {
                    cook->setStatus(cook->getStatus() + 1);
                    cook->assignOrder(pizza);
                    if (write(_pipefdC[WRITE_END], "True\n", 5) == -1)
                        perror("Write :: Can't write in the pipe");
                    return (true);
                }
            }
            if (write(_pipefdC[WRITE_END], "False\n", 6) == -1)
                perror("Write :: Can't write in the pipe");
            return (false);
        }
        return (true);
    }

    void Kitchen::status(void) const
    {
        std::string command;

        if (_parentPid == getpid()) {
            command.assign("status\n");
            if (write(_pipefdP[WRITE_END], command.c_str(), command.length()) == -1)
                perror("Write :: Can't write in the pipe");
        } else {
            for (auto &cook : _cooks) {
                if (cook->getStatus() == INACTIVE)
                    std::cout << "Cook inactive." << std::endl;
                else {
                    std::cout << "Cook is cooking";
                    if (cook->getStatus() == BUSY)
                        std::cout << ", another pending order";
                    std::cout << "." << std::endl;
                }
            }
        }
    }

    void Kitchen::quit(void)
    {
        std::string command;

        if (_parentPid == getpid()) {
            command.assign("quit\n");
            if (write(_pipefdP[WRITE_END], command.c_str(), command.length()) == -1)
                perror("Write :: Can't write in the pipe");
        } else {
            for (auto &cook : _cooks)
                delete cook;
            _exit(EXIT_SUCCESS);
        }
    }

    std::vector<std::string> Kitchen::parsInput(std::string const& input)
    {
        std::string command(input);
        std::replace(command.begin(), command.end(), ';', ' ');
        std::istringstream iss(command);
        std::vector<std::string> parsedInput(std::istream_iterator<std::string>{iss},
                                        std::istream_iterator<std::string>()); 

        return (parsedInput);
    }

    void Kitchen::process(std::string&& command)
    {
        std::vector<std::string> parsedInput = parsInput(command);

        if (!command.compare("quit"))
            quit();
        else if (!command.compare("status"))
            status();
        else if (parsedInput[0] == "PIZZA")
            assignOrder(_menu[parsedInput[1]], atoi(parsedInput[2].c_str()));
    }

    void Kitchen::childLoop(void)
    {
        char c = 0;
        size_t i = 0;
        pollfd pfds;
        char buf[100];
        bool status = true;

        pfds.fd = _pipefdP[READ_END];
        pfds.events = POLLIN;
        while (status) {
            if (poll(&pfds, 1, -1)) {
                if (!memset(buf, 0, 100)) {
                    perror("Memset :: failed");
                    return;
                }
                while (read(_pipefdP[READ_END], &c, 1) > 0) {
                    if (c == '\n')
                        break;
                    buf[i++] = c;
                }
                i = 0;
                process(std::string(buf));
            }
        }
        _exit(EXIT_SUCCESS);
    }
}
