/*
** EPITECH PROJECT, 2019
** TESTS / SOURCES
** File description:
** t_reception.cpp
*/

#include "cri_func.hpp"
#include "Reception.hpp"

namespace Plazza
{
    
    Test(getStock, with_normal_case)
    {
        Reception reception(2, 5, 2000);

        cr_assert_eq(reception.getStock("tomato"), 1);
    }

    Test(getStock, with_wrong_ingredient)
    {
        Reception reception(2, 5, 2000);

        cr_assert_eq(reception.getStock("None"), -1);
    }

    Test(getPizza, with_normal_case)
    {
        Reception reception(2, 5, 2000);
        Pizza pizza(reception.getPizza("Margarita"));

        cr_assert_str_eq(pizza.getRecipe().getPizzaName().c_str(), "Margarita");
    }

    Test(getPizza, with_wrong_name)
    {
        Reception reception(2, 5, 2000);
        Pizza pizza(reception.getPizza("Wrong"));

        cr_assert_str_empty(pizza.getRecipe().getPizzaName().c_str());
    }

    Test(getBakeTimeWeight, with_normal_case)
    {
        Reception reception(2, 5, 2000);

        cr_assert_eq(reception.getBakeTimeWeight(), 2);
    }

    Test(getMaxCook, with_normal_case)
    {
        Reception reception(2, 5, 2000);

        cr_assert_eq(reception.getMaxCook(), 5);
    }

    Test(getStockRegen, with_normal_case)
    {
        Reception reception(2, 5, 2000);

        cr_assert_eq(reception.getStockRegen(), 2000);
    }

}
