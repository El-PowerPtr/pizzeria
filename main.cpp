#include "cli.h"
#include <clocale>
int main()
{
    setlocale(LC_ALL, "spanish");
    Cli::main_menu();
}