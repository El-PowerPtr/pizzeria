#include "pizza.h"

Pizza::Pizza(std::string _name, float _price) :
    name {_name}, price {_price}
{}

void Pizza::add(Ingredient ingredient)
{
    ingredients.push_back(ingredient);
}


