#include "cli.h"

namespace Cli
{
    void append_fill(std::string& builder, int width,int length, std::string fill)
    {
        for (int i = 0; i < (width - length) / 2;)
        {
            builder.append(fill);
            i += fill.length();
        }
    }

    void centered_print(std::string text, int width, std::string fill = " ")
    {
        std::string builder;

        append_fill(builder, width, text.length(), fill);
        builder.append(text);
        append_fill(builder, width, text.length(), fill);

        std::cout<< builder<<std::endl;        
    }

    void centered_print(std::string text, int width, std::string fill1, std::string fill2)
    {
        std::string builder;

        append_fill(builder, width, text.length(), fill1);
        builder.append(text);
        append_fill(builder, width, text.length(), fill2);


        std::cout<<builder<<std::endl;        
    }

    float setprice()
    {
        float credit;
        
        do
            {
                std::cout<< "Inserte el crédito que está dispuesto a gastar" << std::endl;
                std::cin >> credit;
                std::fflush(stdin);
                if (25 - credit <= 0.001)
                    break;
                else
                {
                    std::cout << "Cantidad inválida (" << credit 
                        << ") el crédito introducido debe ser mayor que 25 (el mínimo que puedes usar para comprar una pizza)" <<std::endl;
                }
        }while(true);

        std::cout << "Su crédito es de " << credit << "$" << std::endl;

        return credit;
    }

    void main_menu()
    {
        float used = 0;
        Pizza pizza;
        int choice;
        
        std::cout<<"Bienvenido/a!"<<std::endl;
        float credit = setprice();        
        do
        {   
            
            std::cout << "Teclee el número correspondiente para efectuar la función deseada" <<std::endl
                      << "1 - Ordenar una nueva pizza"                                       <<std::endl
                      << "2 - Reajustar su presupuesto"                                      <<std::endl;
            std::cout << "3 - Salir"                                                         <<std::endl;
            std::cout << "Importe/Crédito:" << std::setw(50) <<used<<"/"<<credit             <<std::endl;

            std::cin>>choice;
            std::fflush(stdin);
            switch (choice)
            {
                case 1:
                    pizza = order(used, credit);
                    if(used - credit <= 0.01)
                        add_ingredients(pizza, used, credit);
                    if (used - credit >= 0.01)
                    {
                        std::cout << " Crédito disponible insuficiente, reformule su pedido"<<std::endl;
                        used = 0;
                    }
                    else
                    {
                        end(pizza, used, credit);
                        choice = 3;
                    }
                    break;
                
                case 2:
                    credit = setprice();
                    break;
                
                case 3:
                    std::cout << "Está seguro que desea salir?"<<std::endl
                            << "1 - Sí."                     <<std::endl
                            << "2 - No."                     <<std::endl;
                    std::cin>>choice;
                    std::fflush(stdin);
                    
                    if (choice == 1)
                        choice = 3;
                    break;
                default:
                    std::cout<<"Usted ha Introducido un valor incorrecto, inténtelo de nuevo"<<std::endl;
                    break;
            }
        }while(choice != 3);
        std::cout<<"Vuelva pronto!"<<std::endl;
    }

    Pizza order(float& used, float& credit)
    {
        int pizza_choice = 0;
        Pizza pizza;
        do
        {
            std::cout << "Qué tipo de pizza desea?"<<std::endl;
            for (int i = 0; i < pizza_num; i++)
                std::cout << i + 1 << " - " << "Pizza " << pizzas[i].name << std::right << std::setw(38 - pizzas[i].name.length()) 
                    << std::setprecision(1) << std::fixed << pizzas[i].price << "$" << std::endl;
            std::cout << "Importe/Crédito:" << std::setw(25) << used << "/" <<credit <<std::endl << std::setw(0);

            std::cin >> pizza_choice;
            std::fflush(stdin);
            
            if(pizza_choice >= 1 && pizza_choice <= pizza_num)
            {
                pizza = pizzas[pizza_choice - 1];
                used += pizzas[pizza_choice - 1].price;
            }
            else
            {
                std::cout << "Introduce un numero valido" << std::endl;
                pizza_choice = 0;
            }
        }while(!pizza_choice);

        return pizza;
    }

    void add_ingredients(Pizza& pizza, float& used, float& credit)
    {
        int ingredient_choice;
        do
        {
            std::cout << "Qué ingrediente desea añadir a su pizza?"<<std::endl;
            for (int i = 0; i < ingred_num; i++)
                std::cout << i + 1 << " - " << ingredient_table[i].name << std::setw(42 - ingredient_table[i].name.length()) 
                    << std::setprecision(1) << std::fixed << ingredient_table[i].price << "$" << std::endl;
            std::cout << "Si no desea añadir un nuevo ingrediente, introduzca 0" << std::endl;
            std::cout << "Importe/Crédito:" << std::setw(25) << used << "/" <<credit <<std::endl << std::setw(0);

            std::cin >> ingredient_choice;
            std::fflush(stdin); 

            if(ingredient_choice >= 1 && ingredient_choice <= ingred_num)
            {

                if (used - credit > 0.01)
                {
                    std::cout << "Crédito insuficiente, reformule su pedido" << std::endl;
                    break; 
                }
                else
                {
                    pizza.add(ingredient_table[ingredient_choice - 1]);
                    std::cout<< "se ha añadido " << ingredient_table[ingredient_choice - 1].name << "a su pedido"<< std::endl;
                    used += ingredient_table[ingredient_choice - 1].price;
                } 

            }
            else if (ingredient_choice == 0)
            {
                break;
            }
            else
            {
                std::cout << "Introduce un numero valido" << std::endl;
            }
        }while(true);
    }

    void end(Pizza& pizza,float& used, float& credit)
    {
        
        centered_print("RECIBO", 75, "-");
        std::cout << std::left << "Pizza " << pizza.name << std::right << std::setw(67 - pizza.name.length()) << pizza.price << std::endl;
        std::cout << std::setw(74) << std::setfill('-') << "-" << std::endl << std::setfill(' ');        

        if(!pizza.ingredients.empty())
            for(auto ingredient : pizza.ingredients)
            {
                std::cout  << std::left << ingredient.name << std::right << std::setw(73 - ingredient.name.length()) << ingredient.price << std::endl;
            }
        std::cout << std::setw(74) << std::setfill('-') << "-" << std::endl << std::setfill(' ');

        std::cout << "Usado"<< std::setw(68) << used<<std::endl;
        std::cout << "Cambio"<< std::setw(67) << credit - used<<std::endl;
        std::cout << "Total" << std::setw(68) << credit <<std::endl;      

        std::fflush(stdin);
        std::cin.get();
    }
}

