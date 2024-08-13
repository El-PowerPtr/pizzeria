#ifndef CLI
#define CLI

#include <iostream>
#include "pizza.h"
#include <cstdlib>
#include <iomanip>

namespace Cli
{
    void append_fill(std::string&, int, int, std::string);
    void centered_print(std::string, int, std::string);
    void centered_print(std::string, int, std::string, std::string);
    void add_ingredients(Pizza&, float&, float&);
    float setprice();
    void main_menu();
    Pizza order(float&, float&);
    void end(Pizza&, float&, float&);
}
#endif