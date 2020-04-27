/*
** EPITECH PROJECT, 2019
** TESTS / GENERIC
** File description:
** redirect.cpp
*/

#include "cri_func.hpp"
#include "ArgumentsHandler.hpp"

Test(check, with_normal_case, .init=redirect_all_std)
{
    int ac = 4;
    char *av[4] = {(char *)"./plazza",
                    (char *)"2",
                    (char *)"5",
                    (char *)"2000"};

    cr_assert_eq(Plazza::ArgumentsHandler::check(ac, av), 0);
}

Test(check, with_h_case, .init=redirect_all_std)
{
    int ac = 2;
    char *av[2] = {(char *)"./plazza",
                    (char *)"-h"};

    cr_assert_eq(Plazza::ArgumentsHandler::check(ac, av), 1);
}

Test(check, with_wrong_h_case, .init=redirect_all_std)
{
    int ac = 2;
    char *av[2] = {(char *)"./plazza",
                    (char *)"-hh"};

    cr_assert_eq(Plazza::ArgumentsHandler::check(ac, av), 84);
}

Test(check, with_help_case, .init=redirect_all_std)
{
    int ac = 2;
    char *av[2] = {(char *)"./plazza",
                    (char *)"--help"};

    cr_assert_eq(Plazza::ArgumentsHandler::check(ac, av), 1);
}

Test(check, with_wrong_help_case, .init=redirect_all_std)
{
    int ac = 2;
    char *av[2] = {(char *)"./plazza",
                    (char *)"-help"};

    cr_assert_eq(Plazza::ArgumentsHandler::check(ac, av), 84);
}

Test(check, with_wrong_arg_nb, .init=redirect_all_std)
{
    int ac = 3;
    char *av[3] = {(char *)"./plazza",
                    (char *)"2",
                    (char *)"2000"};

    cr_assert_eq(Plazza::ArgumentsHandler::check(ac, av), 84);
}

Test(check, with_1_not_float, .init=redirect_all_std)
{
    int ac = 4;
    char *av[4] = {(char *)"./plazza",
                    (char *)"2a",
                    (char *)"5",
                    (char *)"2000"};

    cr_assert_eq(Plazza::ArgumentsHandler::check(ac, av), 84);
}

Test(check, with_2_not_int, .init=redirect_all_std)
{
    int ac = 4;
    char *av[4] = {(char *)"./plazza",
                    (char *)"2",
                    (char *)"5a",
                    (char *)"2000"};

    cr_assert_eq(Plazza::ArgumentsHandler::check(ac, av), 84);
}

Test(check, with_3_not_int, .init=redirect_all_std)
{
    int ac = 4;
    char *av[4] = {(char *)"./plazza",
                    (char *)"2",
                    (char *)"5",
                    (char *)"2a000"};

    cr_assert_eq(Plazza::ArgumentsHandler::check(ac, av), 84);
}

Test(check, with_1_neg_value, .init=redirect_all_std)
{
    int ac = 4;
    char *av[4] = {(char *)"./plazza",
                    (char *)"-2",
                    (char *)"5",
                    (char *)"2000"};

    cr_assert_eq(Plazza::ArgumentsHandler::check(ac, av), 84);
}

Test(check, with_1_null_value, .init=redirect_all_std)
{
    int ac = 4;
    char *av[4] = {(char *)"./plazza",
                    (char *)"0.0",
                    (char *)"5",
                    (char *)"2000"};

    cr_assert_eq(Plazza::ArgumentsHandler::check(ac, av), 84);
}

Test(check, with_2_neg_value, .init=redirect_all_std)
{
    int ac = 4;
    char *av[4] = {(char *)"./plazza",
                    (char *)"2",
                    (char *)"-5",
                    (char *)"2000"};

    cr_assert_eq(Plazza::ArgumentsHandler::check(ac, av), 84);
}

Test(check, with_2_null_value, .init=redirect_all_std)
{
    int ac = 4;
    char *av[4] = {(char *)"./plazza",
                    (char *)"0.1",
                    (char *)"0",
                    (char *)"2000"};

    cr_assert_eq(Plazza::ArgumentsHandler::check(ac, av), 84);
}

Test(check, with_3_neg_value, .init=redirect_all_std)
{
    int ac = 4;
    char *av[4] = {(char *)"./plazza",
                    (char *)"2",
                    (char *)"5",
                    (char *)"-2000"};

    cr_assert_eq(Plazza::ArgumentsHandler::check(ac, av), 84);
}

Test(check, with_3_null_value, .init=redirect_all_std)
{
    int ac = 4;
    char *av[4] = {(char *)"./plazza",
                    (char *)"0.0",
                    (char *)"5",
                    (char *)"0"};

    cr_assert_eq(Plazza::ArgumentsHandler::check(ac, av), 84);
}