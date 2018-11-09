#include <iostream>
#include "Bilhete.h"
#include "Utentes.h"
#include "Venda.h"
#include "Pontovenda.h"
#include "Local.h"

using namespace std;

// Este arquivo de origem simula a venda de um bilhete em uma maquina
int main() {
  int  option = 0;
  char control;

  do {
    if (option != 0)
    {
      do {
        cout << "Deseja realizar outra operação ? (s/n)" << endl;
        cin >> control;
        cin.clear();
        system("clear");

        if (control == 'n')
        {
          writeFile();
          return 0;
        }
      } while (control != 's');
    }

    if (option == 0)
    {
      readFile();
    }

    system("clear");
    cout << "              Menu Inicial              " << endl;
    cout << "========================================" << endl;
    cout << "Local Atual: " << LocalAtual() << " "     << endl;
    cout << "========================================" << endl;
    cout << "\nEscolha a operação desejada         \n" << endl;
    cout << "1 - Comprar Bilhetes                  \n" << endl;
    cout << "2 - Remover Bilhete                   \n" << endl;
    cout << "3 - Verificar Bilhetes                \n" << endl;
    cout << "4 - Verificar dados de um bilhete     \n" << endl;
    cout << "5 - Alterar localidade                \n" << endl;
    cout << "0 - Sair                              \n" << endl;


    cin.clear();
    cin >> option;

    switch (option) {
    case 1:
      system("clear");
      comprarBilhete();
      break;

    case 2:
      system("clear");
      break;

    case 3:
      system("clear");
      Bilhetes();
      break;

    case 4:
      system("clear");
      dadosBilhete();
      break;

    case 5:
      system("clear");
      Locais();
      AlterarLocal();
      break;

    case 6:
      system("clear");
      readFile();
      break;
    }
  } while (option != 0);
  writeFile();
  return 0;
}
