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

}

