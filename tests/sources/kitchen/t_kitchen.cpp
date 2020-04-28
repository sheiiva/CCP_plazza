/*
** EPITECH PROJECT, 2020
** t_kitchen.cpp
** File description:
** kitchen tests
*/

#include "cri_func.hpp"
#include "Kitchen.cpp"

Test(getInactiveTime, get_inactive_time, .init=redirect_all_std)
{
    Kitchen kitchen();
    
    cr_assert_eq(kitchen.getInactiveTime(), 0);
}


/*Test(getCook, get_cook, .init=redirect_all_std)

  Test(getCooks, get_cooks, .init=redirect_all_std)*/

Test(getIngredientsStock, get_ingredient_stock_int, .init=redirect_all_std)
{
    Kitchen kitchen();

    cr_assert_eq(kitchen.getIngredientsStock(tomato), 5);
}

/*Test(getIngredientsStock, get_ingredient_stock_map, .init=redirect_all_std)

Test(checkCookStatus, check_cook_status, .init=redirect_all_std)*/


