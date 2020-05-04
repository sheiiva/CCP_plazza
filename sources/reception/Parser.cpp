/*
** EPITECH PROJECT, 2019
** INCLUDE // KITCHEN
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

namespace Plazza
{

    bool Parser::isValidSize(std::string const& inputSize) const noexcept
    {
        std::string sizes[5] = {"S", "M", "L", "XL", "XXL"};

        for (auto &size : sizes) {
            if (!inputSize.compare(size))
                return (true);
        }
        return (false);
    }

    bool Parser::isValidName(std::string const& inputName, std::map<std::string, Pizza> menu) const noexcept
    {
        for (auto &name : menu) {
            if (!inputName.compare(name.first))
                return (true);
        }
        return (false);
    }

    size_t Parser::isValidNbr(const std::string &inputNbr) const noexcept
    {
        int integer = 0;

        if (inputNbr[0] != 'x')
            return (0);
        else if (!ArgumentsHandler::isType(integer, inputNbr.c_str() + 1))
            return (0);
        return (atoi(inputNbr.c_str() + 1));
    }

    bool Parser::addPizzatoOrder(std::vector<std::string> parsedInput, size_t sep,
                                std::queue<Pizza> &orders, std::map<std::string, Pizza> menu)
    {
        size_t nbr = 0;
        
        if ((parsedInput.size() % 3) != 0 || (((parsedInput.size() / 3) - 1) != sep)) {
            std::cerr << "Wrong input :: number of arguments." << std::endl;
            return (false);
        }
        for (size_t i = 0; i < parsedInput.size(); i += 3) {
            if (isValidName(parsedInput[PIZZANAME + i], menu) == false) {
                std::cerr << "Wrong input :: name of pizza." << std::endl;
                break;
            } else if (isValidSize(parsedInput[SIZE + i]) == false) {
                std::cerr << "Wrong input :: size of pizza." << std::endl;
                break;
            } else if (!(nbr = isValidNbr(parsedInput[NUMBER + i]))) {
                std::cerr << "Wrong input :: number of pizza." << std::endl;
                break;
            } else {
                for(size_t index = 0; index < nbr; index++)
                    orders.push(Pizza(menu[parsedInput[PIZZANAME + i]]));
                //WHAT ABOUT THE SIZE ? HAVE TO STOCK IT IN THE PIZZA
                return (true);
            }
        }
        return (false);
    }

    int Parser::run(const std::string &input,
                    std::queue<Pizza> &orders,
                    std::map<std::string, Pizza> &menu)
    {
        std::string command(input);
        size_t sep = std::count(command.begin(), command.end(), ';');
        std::replace(command.begin(), command.end(), ';', ' ');
        std::istringstream iss(command);
        std::vector<std::string> parsedInput(std::istream_iterator<std::string>{iss},
                                        std::istream_iterator<std::string>()); 

        if (!command.compare("HELP"))
            return (HELP);
        else if (!command.compare("QUIT"))
            return (QUIT);
        return (addPizzatoOrder(parsedInput, sep, orders, menu) == true ? COMMAND : NOACTION);
    }

}