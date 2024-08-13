#include "cli.h"
#include <locale>
int main()
{
    Cli::centered_print("PIZZERÍA PENESOTE", 68,"->","<-");
    Cli::main_menu();
}