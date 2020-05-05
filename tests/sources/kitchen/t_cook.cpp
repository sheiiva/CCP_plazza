#include "cri_func.hpp"
#include "Cook.hpp"

Test(getStatus, status_is_zero)
{
    Plazza::Cook cook;
    
    cr_assert_eq(cook.getStatus(), 0);
}

Test(getStatus, status_is_one)
{
    Plazza::Cook cook;
    
    cr_assert_eq(cook.getStatus(), 1);
}
/*
Test(getOrder, get_order)
{
    Plazza::Cook cook;
    Plazza::Pizza pizza;
    int index = 1;
    
    cr_assert_eq(cook.getOrder(1), pizza);
    }*/
