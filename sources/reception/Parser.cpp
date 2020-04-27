/*
** EPITECH PROJECT, 2019
** INCLUDE // KITCHEN
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

namespace Plazza
{

    void Parser::addIngredientToStock(std::vector<std::string> parsedInput, std::vector<std::string> &stock)
    {
        if (parsedInput.size() <= 2)
            std::cerr << "Wrong input :: Insert an ingredient to add to the stock" << std::endl;
        else {
            for (size_t i = 2; i < parsedInput.size(); i++) {
                stock.push_back(parsedInput[i]);
                std::cout << parsedInput[i] << " added to the stock!" << std::endl;
            }
        }
    }

    void Parser::addPizzaToMenu(std::vector<std::string> parsedInput,
                                std::vector<std::string> &stock,
                                std::map<std::string, Pizza> &menu)
    {
        int bakeTime = 0;
        std::string pizzaName;
        std::vector<int> ingredients;
        
        parsedInput.erase(parsedInput.begin());
        parsedInput.erase(parsedInput.begin());
        if (parsedInput.size() < 3) {
            std::cerr << "Wrong input :: PIZZANAME BAKETIME INGREDIENTS" << std::endl;
            return;
        }
        pizzaName.assign(*parsedInput.begin());
        if (menu.find(pizzaName) != menu.end()) {
            std::cerr << "Wrong input :: " << pizzaName << " already on the menu" << std::endl;
            return;
        }
        parsedInput.erase(parsedInput.begin());
        if (!ArgumentsHandler::isType(0, (*parsedInput.begin()).c_str())) {
            std::cerr << "Wrong input :: Baketime should be an int" << std::endl;
            return;
        }
        bakeTime = atoi((*parsedInput.begin()).c_str());
        parsedInput.erase(parsedInput.begin());
        for (auto &ingredient : parsedInput) {
            if (getIngredient(ingredient, stock) == -1) {
                stock.push_back(ingredient);
                std::cout << ingredient << " added to the stock!" << std::endl;
            }
            ingredients.push_back(getIngredient(ingredient, stock));
        }
        menu[pizzaName] = Pizza(pizzaName, ingredients, bakeTime);
        std::cout << pizzaName << " added to the menu!" << std::endl;
    }

    void Parser::addItem(std::vector<std::string> parsedInput,
                        std::vector<std::string> &stock,
                        std::map<std::string, Pizza> &menu)
    {
        if (!parsedInput[1].compare("PIZZA"))
            addPizzaToMenu(parsedInput, stock, menu);
        else if (!parsedInput[1].compare("INGREDIENT"))
            addIngredientToStock(parsedInput, stock);
        else
            std::cerr << "Wrong input :: ADD [PIZZA | INGREDIENT]" << std::endl;
    }

    bool Parser::isValidSize(const std::string &inputSize) noexcept
    {
        std::string sizes[5] = {"S", "M", "L", "XL", "XXL"};

        for (auto &size : sizes) {
            if (!inputSize.compare(size))
                return true;
        }
        return false;
    }

    int Parser::getIngredient(std::string ingredient, std::vector<std::string> stock) noexcept
    {
        for (size_t i = 0; i < stock.size(); i++) {
            if (!ingredient.compare(stock[i]))
                return (i);
        }
        return (-1);
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
        if (inputNbr.size() == 0)
            return (0);
        if (inputNbr[0] != 'x')
            return (0);
        else if (!ArgumentsHandler::isType(0, inputNbr.c_str() + 1))
            return (0);
        return atoi(inputNbr.c_str() + 1);
    }

    void Parser::addPizzatoOrder(std::vector<std::string> parsedInput, size_t sep,
                                        std::queue<Pizza> &orders,
                                        std::map<std::string, Pizza> menu)
    {
        size_t nbr = 0;
        
        if ((parsedInput.size() % 3) != 0 || (((parsedInput.size() / 3) - 1) != sep)) {
            std::cerr << "Wrong input :: number of arguments." << std::endl;
        } else {
            for (size_t i = 0; i < parsedInput.size(); i += 3) {
                if (isValidName(parsedInput[PIZZANAME + i], menu) == false)
                    std::cerr << "Wrong input :: name of pizza." << std::endl;
                else if (isValidSize(parsedInput[SIZE + i]) == false)
                    std::cerr << "Wrong input :: size of pizza." << std::endl;
                else if (!(nbr = isValidNbr(parsedInput[NUMBER + i])))
                    std::cerr << "Wrong input :: number of pizza." << std::endl;
                else {
                    for(size_t index = 0; index < nbr; index++)
                        orders.push(Pizza(menu[parsedInput[PIZZANAME + i]]));
                    //WHAT ABOUT THE SIZE ? HAVE TO STOCK IT IN THE PIZZA
                }
            }
        }
    }

    int Parser::run(const std::string &input, std::queue<Pizza> &orders,
                std::vector<std::string> &stock, std::map<std::string, Pizza> &menu) noexcept
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
        else if (parsedInput.size() < 2) {
            std::cerr << "Wrong input :: number of pizza." << std::endl;
        } else {
            if (!parsedInput[0].compare("ADD")) {
                addItem(parsedInput, stock, menu);
                return (ADDITEM);
            } else {
                addPizzatoOrder(parsedInput, sep, orders, menu);
                return (COMMAND);
            }
        }
        return (NOACTION);
    }

}