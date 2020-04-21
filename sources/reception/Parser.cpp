/*
** EPITECH PROJECT, 2019
** INCLUDE // KITCHEN
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

namespace Plazza
{

    bool Parser::isValidSize(const std::string &inputSize) noexcept
    {
        static std::string sizes[5] = {"S", "M", "L", "XL", "XXL"};

        for (auto &size : sizes) {
            if (!inputSize.compare(size))
                return true;
        }
        return false;
    }

    bool Parser::isValidName(const std::string &inputName, std::map<std::string, Pizza> menu) noexcept
    {
        for (auto &name : menu) {
            if (!inputName.compare(name.first))
                return true;
        }
        return false;
    }

    size_t Parser::isValidNbr(const std::string &inputNbr) noexcept
    {
        if (inputNbr[0] != 'x')
            return (0);
        else if (!atoi(inputNbr.c_str() + 1))
            return (0);
        return atoi(inputNbr.c_str() + 1);
    }


    int Parser::run(const std::string &input,
                std::queue<Pizza> orders,
                std::map<std::string, Pizza> menu) noexcept    {
        size_t nbr = 0;
        std::string command(input);
        size_t sep = std::count(command.begin(), command.end(), ';');
        std::replace(command.begin(), command.end(), ';', ' ');
        std::istringstream iss(command);
        std::vector<std::string> splitString(std::istream_iterator<std::string>{iss},
                                        std::istream_iterator<std::string>());
        
        if (!input.compare("HELP"))
            return (1);
        else if (!input.compare("ADD")) {
            // ADD PIZZA TO MENU (OPTION)
            return (0);
        }
        if ((splitString.size() % 3) != 0 || (((splitString.size() / 3) - 1) != sep)) {
            std::cerr << "Wrong input :: number of arguments." << std::endl;
            return (0);
        }
        for (size_t i = 0; i < splitString.size(); i += 3) {
            if (isValidName(splitString[PIZZANAME + i], menu) == false)
                std::cerr << "Wrong input :: name of pizza." << std::endl;
            else if (isValidSize(splitString[SIZE + i]) == false)
                std::cerr << "Wrong input :: size of pizza." << std::endl;
            else if (!(nbr = isValidNbr(splitString[NUMBER + i])))
                std::cerr << "Wrong input :: number of pizza." << std::endl;
            else {
                for(size_t index = 0; index < nbr; index++)
                    orders.push(Pizza(menu[splitString[PIZZANAME + i]]));
                //WHAT ABOUT THE SIZE ? HAVE TO STOCK IT IN THE PIZZA
            }
        }
        return (0);
    }

}