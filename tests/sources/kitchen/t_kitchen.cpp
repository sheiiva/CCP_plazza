/*
** EPITECH PROJECT, 2020
** t_kitchen.cpp
** File description:
** kitchen tests
*/

#include "cri_func.hpp"
#include "Kitchen.hpp"
#include "Pizza.hpp"

using namespace Plazza;

Test(getChildPid, get_child_pid, .init=redirect_all_std)
{
    const std::string pizzaname = "Margarita";
    std::vector<int> neededIngredients;
    int bakeTime = 0;
    Plazza::Pizza pizza(pizzaname, neededIngredients, bakeTime);
    std::map<std::string, Pizza> menu;
    std::map<std::string, int> stock;
    int maxCook = 0;
    Plazza::Kitchen kitchen(menu, stock, maxCook);

    kitchen.setChildPid(0);
    cr_assert_eq(kitchen.getChildPid(), 0);
}

Test(getParentPid, get_parent_pid, .init=redirect_all_std)
{
    const std::string pizzaname = "Margarita";
    std::vector<int> neededIngredients;
    int bakeTime = 0;
    Plazza::Pizza pizza(pizzaname, neededIngredients, bakeTime);
    std::map<std::string, Pizza> menu;
    std::map<std::string, int> stock;
    int maxCook = 0;
    Plazza::Kitchen kitchen(menu, stock, maxCook);

    kitchen.setParentPid(0);
    cr_assert_eq(kitchen.getParentPid(), 0);
}

Test(getInactiveTime, get_inactive_time, .init=redirect_all_std)
{
    const std::string pizzaname = "Margarita";
    std::vector<int> neededIngredients;
    int bakeTime = 0;

    Plazza::Pizza pizza(pizzaname, neededIngredients, bakeTime);
    std::map<std::string, Pizza> menu;
    std::map<std::string, int> stock;
    int maxCook = 0;
    Plazza::Kitchen kitchen(menu, stock, maxCook);

    kitchen.setInactiveTime(5);
    cr_assert_eq(kitchen.getInactiveTime(), 5);
}

Test(getMaxCook, get_max_cook, .init=redirect_all_std)
{
    const std::string pizzaname = "Margarita";
    std::vector<int> neededIngredients;
    int bakeTime = 0;
    Plazza::Pizza pizza(pizzaname, neededIngredients, bakeTime);
    std::map<std::string, Pizza> menu;
    std::map<std::string, int> stock;
    int maxCook = 0;
    Plazza::Kitchen kitchen(menu, stock, maxCook);
    
    cr_assert_eq(kitchen.getMaxCook(), 0);
}

/*Test(getCook, get_cook, .init=redirect_all_std)
{
    Plazza::Kitchen kitchen;
    Plazza::Cook cook(kitchen);

    cr_assert_eq(kitchen.getCook(0), cook);
    }*/

 /*Test(getCooks, get_cooks, .init=redirect_all_std)
{
    Plazza::Kitchen kitchen;
    Plazza::Cook cook(kitchen);
    std::vector<Plazza::Cook> cooks;

    cooks.push_back(cook);
    cr_assert_eq(kitchen.getCooks(), cooks);
    }*/

/*Test(getIngredientsStock, get_ingredient_stock_int, .init=redirect_all_std)
{
    Plazza::Kitchen kitchen;
    const std::string &str("tomato");
    
    cr_assert_eq(kitchen.getIngredientsStock(str), 5);
    }*/

/*Test(getIngredientsStock, get_ingredient_stock_map, .init=redirect_all_std)
{
    Plazza::Kitchen kitchen;
    std::map<std::string, int> ingredients_stock;

    ingredients_stock["doe"] = 5;
    ingredients_stock["tomato"] = 5;
    ingredients_stock["gruyere"] = 5;
    ingredients_stock["ham"] = 5;
    ingredients_stock["mushrooms"] = 5;
    ingredients_stock["steak"] = 5;
    ingredients_stock["eggplant"] = 5;
    ingredients_stock["goat cheese"] = 5;
    ingredients_stock["chief love"] = 5;
    cr_assert_eq(kitchen.getIngredientsStock(), ingredients_stock);
    }*/

/*Test(checkCookStatus, check_cook_status, .init=redirect_all_std)
{
    Plazza::Kitchen kitchen;

    cr_assert_eq(kitchen.checkCookStatus(), false);
    }*/
