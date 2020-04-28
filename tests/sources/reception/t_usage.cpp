/*
** EPITECH PROJECT, 2019
** TESTS / SOURCES
** File description:
** t_usage.cpp
*/

#include <iostream>
#include <fcntl.h>
#include <fstream>  
#include <unistd.h>

#include "cri_func.hpp"
#include "Usage.hpp"

static bool exists(const std::string& name)
{
    return (access(name.c_str(), F_OK) != -1);
}

Test(show, with_normal_case, .init=redirect_all_std)
{
    std::string output("this\nis\nmy usage!\n");
    std::ofstream outfile(FILEPATH);

    outfile << output;
    cr_expect_eq(exists(FILEPATH), true);
    outfile.close();
    cr_expect_eq(outfile.is_open(), 0);
    Plazza::Usage::show();

    cr_assert_stdout_eq_str(output.c_str());
    std::remove(FILEPATH);
    cr_expect_eq(exists(FILEPATH), false);
}

Test(show, with_no_file, .init=redirect_all_std)
{
    std::string output(FILEPATH);

    output.append(": no such file\n\0");
    cr_expect_eq(exists(FILEPATH), false);
    Plazza::Usage::show();

    cr_assert_stderr_eq_str(output.c_str());
}