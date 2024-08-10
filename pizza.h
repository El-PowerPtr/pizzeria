#ifndef PIZZA
#define PIZZA
#include <string>
#include <vector>
#include <iostream>

typedef struct
{
    std::string name;
    float price;
}Ingredient;

const Ingredient ingredient_table[] = {{"Piña",3.7} , {"Jamón", 10.0}, {"Cebolla",8.1}};
const int ingred_num = 3;

class Pizza
{
    public:
        std::string name;
        float price;
        std::vector<Ingredient> ingredients; 
        void add(Ingredient);
        friend std::ostream &operator<< (std::ostream&, const Pizza&);
};      

class Pizza1 : public Pizza
{
    public : Pizza1();
};
class Pizza2 : public Pizza
{
    public : Pizza2();
};
class Pizza3 : public Pizza
{
    public : Pizza3();
};

#endif