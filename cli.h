#ifndef CLI
#define CLI
#include <iostream>
#include "pizza.h"
#include <cstdlib>
#include <iomanip>

namespace Cli
{
    float start();
    void main_menu();
    void order(std::vector<Pizza>&,float&, float&);
    void end(std::vector<Pizza>&,float&, float&);
}
#endif