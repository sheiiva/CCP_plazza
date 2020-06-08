/*
** EPITECH PROJECT, 2019
** INCLUDE // RECEPTION
** File description:
** Usage.hpp
*/

#ifndef USAGE_HPP
    #define USAGE_HPP

    #include <iostream>
    #include <sstream>
    #include <string>
    #include <fstream>

    namespace Plazza
    {

        #define FILEPATH "deps/usage.txt"

        class Usage
        {
            private:
                Usage() noexcept = default;
                Usage(const Usage &b) noexcept = default;
                Usage(Usage &&b) noexcept = default;
                ~Usage() noexcept = default;
        
                Usage &operator=(const Usage &rhs) noexcept = default;
                Usage &operator=(Usage &&rhs) noexcept = default;
        
            private:
                void readFromFile(void) noexcept;

            public:
                static void show(void) noexcept
                {
                    Usage usage;

                    usage.readFromFile();
                }
        };

    }

#endif /* !USAGE_HPP */