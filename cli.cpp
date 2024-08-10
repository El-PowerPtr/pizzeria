#include "cli.h"

namespace Cli
{
    float start()
    {
        float credit;
        std::system("cls");
        do
            {
                std::cout<< "Inserte el crédito que está dispuesto a gastar" << std::endl;
                std::cin >> credit;
                if (credit > 0)
                    break;
                else
                {
                    std::cout << "Cantidad inválida (" << credit 
                        << ") el crédito introducido debe ser mayor que 0" <<std::endl;        
                    std::system("cls");
                }
        }while(true);

        std::cout << "Su crédito es de " << credit << "$" << std::endl;

        return credit;
    }

    void main_menu()
    {
        float used = 0;
        std::vector<Pizza> pizzas;
        int choice;
        std::system("cls");
        std::cout<<"Bienvenido/a!"<<std::endl;
        float credit = start();        
        do
        {   
            
            std::cout << "Teclee el número correspondiente para efectuar la función deseada" <<std::endl
                      << "1 - Ordenar una nueva pizza"                                       <<std::endl
                      << "2 - Reajustar su presupuesto"                                      <<std::endl
                      << "3 - Efectuar la compra"                                            <<std::endl
                      << "4 - Salir"                                                         <<std::endl;
            std::cout << "Importe/Crédito:" << std::setw(68) <<used<<"/"<<credit             <<std::endl;

            std::cin>>choice;
            switch (choice)
            {
                case 1:
                    order(pizzas, used, credit);
                    break;
                
                case 2:
                    credit = start();
                    break;
                
                case 3:
                    if (used != 0)
                        end(pizzas, used, credit);
                    else if(used > credit)
                    {
                        std::cout << "Dinero Insuficiente";
                        choice = 0;
                    }
                    else if(used == 0)
                    {
                        std::cout << "No has ordenado ninguna pizza";
                        choice = 0;
                    }
                    break;
                case 4:
                    std::cout << "Está seguro que desea salir?"<<std::endl
                            << "1 - Sí."                     <<std::endl
                            << "2 - No."                     <<std::endl;
                    std::cin>>choice;
                    if (choice == 1){
                        choice = 4;
                        std::cout<<"Vuelva pronto!"<<std::endl;
                    }
                    break;
                default:
                    std::cout<<"Usted ha Introducido un valor incorrecto, inténtelo de nuevo"<<std::endl;
                    break;
            }
            std::system("cls");
        }while(choice != 4 && choice != 3);
    }

    void order(std::vector<Pizza>& pizzas, float& used, float& credit)
    {
        int choice = 0;
        Pizza pizza;
        do
        {
            std::system("cls");
            std::cout<< "Escriba el número correspondiente al tipo de pizza deseado:" <<std::endl;
            std::cout<< "1 - Pizza Pequeña"                                           <<std::endl;
            std::cout<< "2 - Pizza Mediana"                                           <<std::endl;
            std::cout<< "3 - Pizza Grande"                                            <<std::endl;
            std::cout<< "Importe/Crédito:" << std::setw(61) << used << "/" << credit  <<std::endl;
            std::cout<< "0 - Cancelar la compra"<<std::endl;
            std::cin >> choice;
            switch (choice)
            {
                case 1:
                    if (credit - used >= Pizza1().price);
                        pizzas.push_back(Pizza1());
                        used += pizzas.back().price; 
                    break;
                case 2:
                    if (credit - used >= Pizza2().price);
                        pizzas.push_back(Pizza2());
                        used += pizzas.back().price; 
                    break;
                case 3:
                    if (credit - used >= Pizza3().price);
                        pizzas.push_back(Pizza3());
                        used += pizzas.back().price; 
                    break;               
                default:
                    std::cout<<"Inserte un número válido"<<std::endl;
                    choice = 0;
                    std::system("cls");
                    break;
            }
        } while (!choice);
        
        do
        {
            std::cout<<"Para añadir ingredientes extra seleccione el número correspondiente al agregado deseado"<<std::endl;
            
            for (int i = 0; i < ingred_num; i++)                        
                std::cout<< i + 1<<" - "<< ingredient_table[i].name << "   " <<  ingredient_table[i].price      <<std::endl;
            std::cout<< "Importe/Crédito:        "<< std::setw(90) << used << "/" << credit                     <<std::endl; 
            std::cout<< "Si no desea agregar otro ingrediente, digite ,en cambio, 0"                            <<std::endl;

            std::cin>>choice;

            if (choice > 1 && choice <= ingred_num)
            {
                if (credit - used >= ingredient_table[choice - 1].price)
                {
                    std::cout << "Desea agregar " <<  ingredient_table[choice - 1].name << "a su pizza por " << ingredient_table[choice - 1].price
                        <<"?" <<std::endl << "Balance tras la transacción" << used + ingredient_table[choice - 1].price <<"/"<<credit<<std::endl;
                    std::cout<<"Digite 1 para confirmar"<<std::endl;
                    std::cin>>choice;
                    if (choice == 1)
                    {
                        pizza.add(ingredient_table[choice - 1]);
                        used += ingredient_table[choice - 1].price;
                        std::cout<<"Se ha agregado"<< ingredient_table[choice - 1].name <<"a su pizza"<<std::endl;
                    }
                    std::cout<<"No se agregó ningún ingrediente"<<std::endl;
                }
                else
                {
                    std::cout<<"Crédito Insuficiente"<<std::endl
                    << "Digite 1 si quiere cambiar su presupuesto, de lo contrario puede introducir caulquier otra cosa" <<std::endl;
                    std::cin>>choice;
                    if (choice == 1)
                        credit = start();
                }
            }
            else if(choice != 0)
                std::cout<<"Inserte un número válido"<<std::endl;
        } while (choice);

    }            
    void end(std::vector<Pizza>& pizzas,float& used, float& credit)
    {
        std::system("cls");
        std::cout << "Pizzas compradas:"<<std::endl;
        for (auto &pizza : pizzas)
            std::cout << pizza;
        std::cout << "Total" << std::setw(68) << used<<std::endl;      
        std::cout << "Cambio"<< std::setw(68) << credit - used<<std::endl;
        std::system("pause");
    }
}

