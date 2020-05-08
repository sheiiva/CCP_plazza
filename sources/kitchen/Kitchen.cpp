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
        _pid(0), _ppid(0),_inactiveTime(time(NULL)), _maxCook(maxCook), _menu(menu)
    {
        for (auto &ingredient : stock)
            _ingredientsStock[ingredient] = 5;
        if (pipe(_pipefd) == -1) {
            std::cerr << "Pipe :: failed" << std::endl;
            this->~Kitchen();
            return;
        }
        _pid = fork();
        std::cout << "PID = " << _pid << std::endl;
        if (_pid == -1) {
            std::cerr << "Fork failed :: Can't create a new Kitchen" << std::endl;
            this->~Kitchen();
        } else if (_pid) {
            //parent
            _ppid = getpid();
            // close(_pipefd[READ_END]);
            std::cout << "PPID = " << _ppid << std::endl;
        } else {
            //child
            _pid = getpid();
            _ppid = getppid();
            // close(_pipefd[WRITE_END]);
            childLoop();
        }
    }

    Kitchen::Kitchen(Kitchen const& b) noexcept :
        _pid(b._pid),
        _ppid(b._ppid),
        _inactiveTime(b._inactiveTime),
        _maxCook(b._maxCook),
        _cooks(b._cooks),
        _ingredientsStock(b._ingredientsStock),
        _menu(b._menu)
    {
    }

    Kitchen::Kitchen(Kitchen&& b) noexcept :
        _pid(b._pid),
        _ppid(b._ppid),
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
        _ppid = rhs._ppid;
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
        _ppid = rhs._ppid;
        _inactiveTime = rhs._inactiveTime;
        _maxCook = rhs._maxCook,
        _cooks.swap(rhs._cooks);
        _ingredientsStock.swap(rhs._ingredientsStock);
        _menu.swap(rhs._menu);
        return (*this);
    }

    void read_from_pipe (int file, std::string buf)
    {
        FILE *stream;
        int c = 0;

        stream = fdopen(file, "r");
        if (!stream) {
            perror("fdopen :: can't open pipe (read en)");
        }
        buf.clear();
        while((c = fgetc(stream)) != '\n')
            buf.append(reinterpret_cast<char*>(&c));
        fclose(stream);
    }

    void write_to_pipe(int file, const char *str)
    {
        FILE *stream;

        stream = fdopen(file, "w");
        if (!stream) {
            perror("fdopen :: can't open pipe (write en)");
            return;
        }
        fprintf(stream, "%s\n", str);
        fclose(stream);
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

        std::cout << "assignOrder" << std::endl;
        std::cout << "current pid: " << getpid();
        std::cout << "\tparent = " << _ppid << std::endl;
        if (_ppid == getpid()) {
            std::cout << "PARENT" << std::endl;
            command.append(";");
            command.append(pizza.getRecipe().getPizzaName());
            command.append(";");
            command.append(std::to_string(importance));
            // command.append("\n");
            write_to_pipe(_pipefd[WRITE_END], command.c_str());
            // if (write(_pipefd[WRITE_END], command.c_str(), command.length()) == -1)
            //     perror("Write :: Can't write in the pipe");
            //Read for answer            
            return (true);
        } else {
            std::cout << "ENFANT" << std::endl;
            if (_cooks.size() < _maxCook) {
                contractCook(pizza);
                return (true);
            }
            for (auto &cook : _cooks) {
                if (cook.getStatus() < importance) {
                    cook.assignOrder(pizza);
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
            write_to_pipe(_pipefd[WRITE_END], command.c_str());
            // if (write(_pipefd[WRITE_END], command.c_str(), command.length()) == -1)
            //     std::cerr << "Write :: Can't write in the pipe" << std::endl;
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
            std::cout << "PARENT: About to quit" << std::endl;
            command.assign("QUIT");
            write_to_pipe(_pipefd[WRITE_END], command.c_str());
            // if (write(_pipefd[WRITE_END], command.c_str(), command.length()) == -1)
            //     std::cerr << "Write :: Can't write in the pipe" << std::endl;
        } else
            _exit(EXIT_SUCCESS);
    }

    bool Kitchen::parsInput(std::string&& command)
    {
        std::replace(command.begin(), command.end(), ';', ' ');
        std::istringstream iss(command);
        std::vector<std::string> parsedInput(std::istream_iterator<std::string>{iss},
                                        std::istream_iterator<std::string>()); 

        std::cout << "Command: " << command << std::endl;
        if (!command.compare("QUIT"))
            _exit(EXIT_SUCCESS);
        else if (!command.compare("STATUS"))
            status();
        else if (!parsedInput[0].compare("PIZZA"))
            return (assignOrder(_menu[parsedInput[1]], atoi(parsedInput[2].c_str())));
        return (true);
    }

    bool Kitchen::childLoop(void)
    {
        pollfd pfds[2];
        std::string buffer;
        char buf[100];
        bool status = true;

        pfds[READ_END].fd = _pipefd[READ_END];
        pfds[WRITE_END].fd = _pipefd[WRITE_END];
        pfds[READ_END].events = POLLIN;
        pfds[WRITE_END].events = POLLIN;
        while (status) {
            if (poll(pfds, 2, -1)) {
                memset(buf, 0, 100);
                // while ((read(_pipefd[READ_END], &c, 1) != -1) && (c != '\n')) {
                //     std::cout << c;
                //     buf[i++] = c;
                // }
                read_from_pipe(_pipefd[READ_END], buffer);
                std::cout << std::endl;
                std::cout << "hihi" << std::endl;
                std::cout << "BUFFER: " << buf << std::endl;
                parsInput(std::string(buf));
            }
        }
        _exit(EXIT_SUCCESS);
    }
}
