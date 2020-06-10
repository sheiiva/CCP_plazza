/*
** EPITECH PROJECT, 2019
** TESTS / SOURCES
** File description:
** t_parser.cpp
*/

#include "cri_func.hpp"
#include "Parser.hpp"
#include "Kitchen.hpp"
#include "Pizza.hpp"

namespace Plazza {

    /*Test(addIngredientToStock, with_normal_case, .init=redirect_all_std)
    {
        const std::string &input("ADD INGREDIENT ingredient1 ingredient2");
        std::string output("ingredient1 added to the stock!\ningredient2 added to the stock!\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        cr_assert_eq(parser.run(input, orders, stock, menu), ADDITEM);
        cr_assert_stdout_eq_str(output.c_str());
        cr_assert_eq(stock.size(), 2);
        cr_assert_str_eq(stock[0].c_str(), "ingredient1");
        cr_assert_str_eq(stock[1].c_str(), "ingredient2");
    }

    Test(addIngredientToStock, with_wrong_input, .init=redirect_all_std)
    {
        const std::string &input("ADD INGREDIENT  ");
        std::string output("Wrong input :: Insert an ingredient to add to the stock\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        cr_assert_eq(parser.run(input, orders, stock, menu), ADDITEM);
        cr_assert_stderr_eq_str(output.c_str());
        cr_assert_eq(stock.size(), 0);
    }

    Test(addPizzaToMenu, with_normal_case, .init=redirect_all_std)
    {
        const std::string &input("ADD PIZZA pizzaName 3 ingredient1 ingredient2\n");
        std::string output("ingredient1 added to the stock!\n"
                            "ingredient2 added to the stock!\n"
                            "pizzaName added to the menu!\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        cr_assert_eq(parser.run(input, orders, stock, menu), ADDITEM);
        cr_assert_stdout_eq_str(output.c_str());
        cr_assert_eq(stock.size(), 2);
        cr_assert_str_eq(stock[0].c_str(), "ingredient1");
        cr_assert_str_eq(stock[1].c_str(), "ingredient2");
        cr_assert_eq(menu.size(), 1);
        cr_assert_neq(menu.find("pizzaName"), menu.end());
        cr_assert_eq(menu["pizzaName"].getBakeTime(), 3);
    }

    Test(addPizzaToMenu, with_one_existing_ingredient, .init=redirect_all_std)
    {
        const std::string &input("ADD PIZZA pizzaName 3 ingredient1 ingredient2\n");
        std::string output("ingredient2 added to the stock!\n"
                            "pizzaName added to the menu!\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        stock.push_back("ingredient1");
        cr_assert_eq(parser.run(input, orders, stock, menu), ADDITEM);
        cr_assert_stdout_eq_str(output.c_str());
        cr_assert_eq(stock.size(), 2);
        cr_assert_str_eq(stock[0].c_str(), "ingredient1");
        cr_assert_str_eq(stock[1].c_str(), "ingredient2");
        cr_assert_eq(menu.size(), 1);
        cr_assert_neq(menu.find("pizzaName"), menu.end());
        cr_assert_eq(menu["pizzaName"].getBakeTime(), 3);
    }
    
    Test(addPizzaToMenu, with_arg_nbr, .init=redirect_all_std)
    {
        const std::string &input("ADD PIZZA pizzaName\n");
        std::string output("Wrong input :: PIZZANAME BAKETIME INGREDIENTS\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        cr_assert_eq(parser.run(input, orders, stock, menu), ADDITEM);
        cr_assert_stderr_eq_str(output.c_str());
        cr_assert_eq(menu.size(), 0);
    }

    Test(addPizzaToMenu, with_existing_pizza, .init=redirect_all_std)
    {
        std::string pizzaName("pizzaName");
        std::vector<int> ingredient;
        const std::string &input("ADD PIZZA pizzaName 3 ingredient1 ingredient2\n");
        std::string output("Wrong input :: pizzaName already on the menu\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        menu[pizzaName] = Pizza(pizzaName, ingredient, 3);
        cr_assert_eq(parser.run(input, orders, stock, menu), ADDITEM);
        cr_assert_stderr_eq_str(output.c_str());
        cr_assert_eq(menu.size(), 1);
    }

    Test(addPizzaToMenu, with_wrong_baketime, .init=redirect_all_std)
    {
        const std::string &input("ADD PIZZA pizzaName a ingredient1 ingredient2\n");
        std::string output("Wrong input :: Baketime should be an int\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        cr_assert_eq(parser.run(input, orders, stock, menu), ADDITEM);
        cr_assert_stderr_eq_str(output.c_str());
        cr_assert_eq(stock.size(), 0);
        cr_assert_eq(menu.size(), 0);
    }

    Test(addItem, with_wrong_case, .init=redirect_all_std)
    {
        const std::string &input("ADD WRONGKEY ingredient1 ingredient2\n");
        std::string output("Wrong input :: ADD [PIZZA | INGREDIENT]\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        cr_assert_eq(parser.run(input, orders, stock, menu), ADDITEM);
        cr_assert_stderr_eq_str(output.c_str());
    }

    Test(isValidSize, with_normal_case, .init=redirect_all_std)
    {
        std::string pizzaName("pizzaName");
        std::vector<int> ingredient;
        const std::string &input("pizzaName S x3\n");
        std::string output("Wrong input :: size of pizza.\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        menu[pizzaName] = Pizza(pizzaName, ingredient, 3);
        cr_assert_eq(parser.run(input, orders, stock, menu), COMMAND);
        cr_assert_stderr_neq_str(output.c_str());
    }

    Test(isValidSize, with_wrong_case, .init=redirect_all_std)
    {
        std::string pizzaName("pizzaName");
        std::vector<int> ingredient;
        const std::string &input("pizzaName a x3\n");
        std::string output("Wrong input :: size of pizza.\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        menu[pizzaName] = Pizza(pizzaName, ingredient, 3);
        cr_assert_eq(parser.run(input, orders, stock, menu), COMMAND);
        cr_assert_stderr_eq_str(output.c_str());
    }

    Test(isValidName, with_normal_case, .init=redirect_all_std)
    {
        std::string pizzaName("pizzaName");
        std::vector<int> ingredient;
        const std::string &input("pizzaName S x3\n");
        std::string output("Wrong input :: name of pizza.\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        menu[pizzaName] = Pizza(pizzaName, ingredient, 3);
        cr_assert_eq(parser.run(input, orders, stock, menu), COMMAND);
        cr_assert_stderr_neq_str(output.c_str());
    }

    Test(isValidName, with_wrong_case, .init=redirect_all_std)
    {
        std::string pizzaName("pizzaname");
        std::vector<int> ingredient;
        const std::string &input("pizzaName a x3\n");
        std::string output("Wrong input :: name of pizza.\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        menu[pizzaName] = Pizza(pizzaName, ingredient, 3);
        cr_assert_eq(parser.run(input, orders, stock, menu), COMMAND);
        cr_assert_stderr_eq_str(output.c_str());
    }

    Test(isValidNbr, with_normal_case, .init=redirect_all_std)
    {
        std::string pizzaName("pizzaName");
        std::vector<int> ingredient;
        const std::string &input("pizzaName S x3\n");
        std::string output("Wrong input :: number of pizza.\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        menu[pizzaName] = Pizza(pizzaName, ingredient, 3);
        cr_assert_eq(parser.run(input, orders, stock, menu), COMMAND);
        cr_assert_stderr_neq_str(output.c_str());
    }

    Test(isValidNbr, with_no_x_format, .init=redirect_all_std)
    {
        std::string pizzaName("pizzaName");
        std::vector<int> ingredient;
        const std::string &input("pizzaName S 3\n");
        std::string output("Wrong input :: number of pizza.\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        menu[pizzaName] = Pizza(pizzaName, ingredient, 3);
        cr_assert_eq(parser.run(input, orders, stock, menu), COMMAND);
        cr_assert_stderr_eq_str(output.c_str());
    }

    Test(isValidNbr, with_not_an_int, .init=redirect_all_std)
    {
        std::string pizzaName("pizzaName");
        std::vector<int> ingredient;
        const std::string &input("pizzaName S xA\n");
        std::string output("Wrong input :: number of pizza.\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        menu[pizzaName] = Pizza(pizzaName, ingredient, 3);
        cr_assert_eq(parser.run(input, orders, stock, menu), COMMAND);
        cr_assert_stderr_eq_str(output.c_str());
    }

    Test(addPizzatoOrder, with_normal_case, .init=redirect_all_std)
    {
        std::string pizzaName("pizzaName");
        std::vector<int> ingredient;
        const std::string &input("pizzaName S x3\n");
        std::string output("Wrong input :: number of pizza.\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        menu[pizzaName] = Pizza(pizzaName, ingredient, 3);
        cr_assert_eq(parser.run(input, orders, stock, menu), COMMAND);
        cr_assert_stderr_neq_str(output.c_str());
        cr_assert_eq(orders.size(), 3); 
        cr_assert_str_eq(pizzaName.c_str(), orders.front().getRecipe().getPizzaName().c_str());
        cr_assert_eq(3, orders.front().getRecipe().getBakeTime());
    }

    Test(addPizzatoOrder, with_multicommand, .init=redirect_all_std)
    {
        std::string pizzaName("pizzaName");
        std::vector<int> ingredient;
        const std::string &input("pizzaName S x3 ; pizzaName S x3\n");
        std::string output("Wrong input :: number of pizza.\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        menu[pizzaName] = Pizza(pizzaName, ingredient, 3);
        cr_assert_eq(parser.run(input, orders, stock, menu), COMMAND);
        std::cout << orders.size() << std::endl;
        cr_assert_stderr_neq_str(output.c_str());
        cr_assert_eq(orders.size(), 6); 
        for (int i = 0; i < 6; i++) { 
            cr_assert_eq(orders.size(), 6-i); 
            cr_assert_str_eq(pizzaName.c_str(), orders.front().getRecipe().getPizzaName().c_str());
            cr_assert_eq(3, orders.front().getRecipe().getBakeTime());
            orders.pop();
        }
    }

    Test(addPizzatoOrder, with_wrong_arg_not_modulo_3, .init=redirect_all_std)
    {
        std::string pizzaName("pizzaName");
        std::vector<int> ingredient;
        const std::string &input("pizzaName S x3 ; pizzaName S\n");
        std::string output("Wrong input :: number of arguments.\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        menu[pizzaName] = Pizza(pizzaName, ingredient, 3);
        cr_assert_eq(parser.run(input, orders, stock, menu), COMMAND);
        cr_assert_stderr_eq_str(output.c_str());
        cr_assert_eq(orders.size(), 0);
    }

    Test(addPizzatoOrder, with_wrong_separator, .init=redirect_all_std)
    {
        std::string pizzaName("pizzaName");
        std::vector<int> ingredient;
        const std::string &input("pizzaName S x3 , pizzaName S x3\n");
        std::string output("Wrong input :: number of arguments.\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        menu[pizzaName] = Pizza(pizzaName, ingredient, 3);
        cr_assert_eq(parser.run(input, orders, stock, menu), COMMAND);
        cr_assert_stderr_eq_str(output.c_str());
        cr_assert_eq(orders.size(), 0);
    }

    Test(parser_run, with_help)
    {
        const std::string &input("HELP");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        cr_assert_eq(parser.run(input, orders, stock, menu), HELP);
    }

    Test(parser_run, with_quit)
    {
        const std::string &input("QUIT");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        cr_assert_eq(parser.run(input, orders, stock, menu), QUIT);
    }

    Test(parser_run, with_wrong_command, .init=redirect_all_std)
    {
        const std::string &input("command");
        std::string output("Wrong input :: wrong command\n");
        std::queue<Pizza> orders;
        std::vector<std::string> stock;
        std::map<std::string, Pizza> menu;
        Parser parser;

        cr_assert_eq(parser.run(input, orders, stock, menu), NOACTION);
        cr_assert_stderr_eq_str(output.c_str());
        }*/
}
