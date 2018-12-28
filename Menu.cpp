#include <iostream>
#include "Bilhete.h"
#include "Utentes.h"
#include "Venda.h"
#include "Pontovenda.h"
#include "Local.h"
#include "Metro.h"

using namespace std;
/*! \mainpage Documentação Das Classes
 * Este site tem como objetivo ilustrar o sistema de classes utilizado, contendo descrições detalhadas dos membros-dado e membros-função de todas as classes criadas.
 *
 * \section intro_sec Diagrama
 *
 *
 * Todas as classes podem ser acessadas através do menu abaixo que está ordenado alfabeticamente e além disso segue a hierarquia das classes, agrupando classes e subclasses.
 *
 *
 *
 *
 *
 *
 *
 *
 */
int main() {
        Venda v;
        Metro m;
        int option = 0;
        char control;

        v.readData();
        m.readData();

        do {
                if ((option >= 1) && (option <= 10))
                {
                        do {
                                cout << "Deseja realizar outra operação ? (s/n)" << endl;
                                cin >> control;
                                cin.clear();
                                system("clear");

                                if (control == 'n')
                                {
                                        v.writeData();
                                        m.writeData();
                                        return 0;
                                }
                        } while (control != 's');
                }
                system("clear");
                cout << "              Menu Inicial              " << endl;
                cout << "========================================" << endl;
                cout << "Local Atual: " << v.localAtual() << " "     << endl;
                cout << "========================================" << endl;
                cout << "\nEscolha a operação desejada         \n" << endl;
                cout << "1 - Comprar Bilhetes                  \n" << endl;
                cout << "2 - Remover Bilhete                   \n" << endl;
                cout << "3 - Verificar Bilhetes                \n" << endl;
                cout << "4 - Verificar dados de um bilhete     \n" << endl;
                cout << "5 - Alterar localidade                \n" << endl;
                cout << "6 - Contratar Funcionario             \n" << endl;
                cout << "7 - Demitir Funcionario               \n" << endl;
                cout << "8 - Verificar funcionarios            \n" << endl;
                cout << "9 - Verificar dados de um funcionario \n" << endl;
                cout << "10 - Alterar Salario de um funcionario\n" << endl;
                cout << "0 - Sair                              \n" << endl;


                cin.clear();
                cin >> option;

                switch (option) {
                case 1:
                        system("clear");
                        v.comprarBilhete();
                        break;

                case 2:
                        system("clear");
                        v.removeBilhete();
                        break;

                case 3:
                        system("clear");
                        v.Bilhetes();
                        break;

                case 4:
                        system("clear");
                        v.dadosBilhete();
                        break;

                case 5:
                        system("clear");
                        v.alterarLocal();
                        break;
                case 6:
                        system("clear");
                        m.addFuncionario();
                        break;
                case 7:
                        system("clear");
                        m.removeFuncionario();
                        break;
                case 8:
                        system("clear");
                        m.dadosFuncionario();
                        break;
                case 9:
                        system("clear");
                        m.dadoFuncionario();
                        break;
                case 10:
                        system("clear");
                        m.SalarioFuncionario();
                        break;
                }
        } while (option != 0);
        v.writeData();
        m.writeData();

        return 0;
}
