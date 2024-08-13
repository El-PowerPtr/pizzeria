#ifndef PIZZA
#define PIZZA
#include <string>
#include <vector>
#include <iostream>
#include <array>

struct Ingredient
{
    std::string name;
    float price;
};

const Ingredient ingredient_table[] = {{"Piña",3.7} , {"Jamón", 10.0}, {"Cebolla",8.1}};
constexpr size_t ingred_num = std::size(ingredient_table);

class Pizza
{
    public:
        std::string name;
        float price;

        Pizza () = default;
        Pizza (std::string, float);
        std::vector<Ingredient> ingredients; 
        void add(Ingredient);
};      

const Pizza pizzas[] = {{"Pequeña", 25.0}, {"Mediana", 32.5}, {"Grande", 40.0}, {"Familiar", 60.0}};
const size_t pizza_num = std::size(pizzas);

#endif