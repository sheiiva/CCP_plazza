/*
** EPITECH PROJECT, 2019
** INCLUDE // PIZZA
** File description:
** Pizza.hpp
*/

#ifndef PIZZA_HPP
    #define PIZZA_HPP

    #include <iostream>
    #include <time.h>
    #include <vector>
    #include <string>
    #include <mutex>

    namespace Plazza
    {

         class Pizza
         {
             public:
                 Pizza() noexcept = default;
                 Pizza(const std::string &pizzaName, std::vector<int> &neededIngredients, int bakeTime) noexcept;
                 Pizza(const Pizza &b) noexcept;
                 Pizza(Pizza &&b) noexcept;
                 ~Pizza() noexcept = default;
                 Pizza &operator=(const Pizza &rhs) noexcept;
                 Pizza &operator=(Pizza &&rhs) noexcept;
    
             public:
                 //GETTERS
                 int getClock(void) const noexcept;
                 std::string getPizzaName(void) const noexcept;
                 std::vector<int> getIngredients(void) const noexcept;
                 int getBakeTime(void) const noexcept;
                 //SETTERS
                 void setClock(int clock) noexcept;
                 void setPizzaName(const std::string &) noexcept;
                 void setIngredients(std::vector<int> &) noexcept;
                 void setBakeTime(int) noexcept;
                 //METHODS
             
             private:
                 int _clock;
                 std::string _pizzaName;
                 std::vector<int> _ingredients;
                 int _bakeTime;
    };
}

#endif /* !PIZZA_HPP */
