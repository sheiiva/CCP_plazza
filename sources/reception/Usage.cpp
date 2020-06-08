/*
** EPITECH PROJECT, 2019
** INCLUDE // RECEPTION
** File description:
** Usage.cpp
*/

#include "Usage.hpp"

namespace Plazza
{

    void Usage::readFromFile(void) noexcept
    {
        std::ifstream infile(FILEPATH);
        std::string line;

        if (infile.fail()) {
            std::cerr << FILEPATH << ": no such file." << std::endl;
        } else {
            while (std::getline(infile, line))
                std::cout << line << std::endl;
            infile.close();
        }
    }

}