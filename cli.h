#ifndef CLI
#define CLI

#include <iostream>
#include "pizza.h"
#include <cstdlib>
#include <iomanip>

namespace Cli
{
    void centered_print(std::string, int, std::string);
    void centered_print(std::string, int, std::string, std::string);
    float start();
    void main_menu();
    Pizza order(float&, float&);
    void end(Pizza&, float&, float&);
}
#endif