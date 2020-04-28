/*
** EPITECH PROJECT, 2019
** TESTS / GENERIC
** File description:
** redirect.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
