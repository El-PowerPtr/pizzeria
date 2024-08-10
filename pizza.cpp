#include "pizza.h"

void Pizza::add(Ingredient ingredient)
{
    ingredients.push_back(ingredient);
    price += ingredient.price;
}

Pizza1::Pizza1()
{
    name = "pizza pequeña";
    price = 30.0;
}

Pizza2::Pizza2()
{
    name = "pizza mediana";
    price = 35.0;
}

Pizza3::Pizza3() 
{
    name = "pizza grande";
    price = 50.8;
}

std::ostream &operator<< (std::ostream& os, const Pizza& pizza)
{
    os << pizza.name;
    if (!pizza.ingredients.empty())
    {
        os<<" [";
        for(auto& ingredient : pizza.ingredients)
            os << ingredient.name << ", ";
        os<<" ]";
    }
    os << "\t\t" << pizza.price << "\n";
    return os;
}