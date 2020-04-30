/*
** EPITECH PROJECT, 2020
** t_kitchen.cpp
** File description:
** kitchen tests
*/

#include "cri_func.hpp"
#include "Kitchen.hpp"

Test(getInactiveTime, get_inactive_time, .init=redirect_all_std)
{
    Plazza::Kitchen kitchen;
    
    cr_assert_eq(kitchen.getInactiveTime(), 0);
}


/*Test(getCook, get_cook, .init=redirect_all_std)

  Test(getCooks, get_cooks, .init=redirect_all_std)*/

Test(getIngredientsStock, get_ingredient_stock_int, .init=redirect_all_std)
{
    Plazza::Kitchen kitchen;
    const std::string &str("tomato");
    
    cr_assert_eq(kitchen.getIngredientsStock(str), 5);
}

Test(getIngredientsStock, get_ingredient_stock_map, .init=redirect_all_std)
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
}

/*Test(checkCookStatus, check_cook_status, .init=redirect_all_std)
{
    Plazza::Kitchen kitchen;

    cr_assert_eq(kitchen.checkCookStatus(), true);
    }*/
