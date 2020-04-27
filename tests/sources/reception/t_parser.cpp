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

    Test(addIngredientToStock, with_normal_case, .init=redirect_all_std)
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

    // Test(addPizzaToMenu, with_normal_case, .init=redirect_all_std)
    // {
    //     const std::string &input("ADD PIZZA pizzaName 3 ingredient1 ingredient2\n");
    //     std::string output("ingredient1 added to the stock!\n"
    //                         "ingredient2 added to the stock!\n"
    //                         "pizzaName added to the stock!\n");
    //     std::queue<Pizza> orders;
    //     std::vector<std::string> stock;
    //     std::map<std::string, Pizza> menu;
    //     Parser parser;

    //     cr_assert_eq(parser.run(input, orders, stock, menu), ADDITEM);
    //     cr_assert_stdout_eq_str(output.c_str());
    //     cr_assert_eq(stock.size(), 2);
    //     cr_assert_str_eq(stock[0].c_str(), "ingredient1");
    //     cr_assert_str_eq(stock[1].c_str(), "ingredient2");
    //     cr_assert_eq(menu.size(), 1);
    //     cr_assert_neq(menu.find("pizzaName"), menu.end());
    //     cr_assert_eq(menu["pizzaName"].getBakeTime(), 3);
    // }

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

}