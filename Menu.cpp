#include <iostream>
#include "Bilhete.h"
#include "Utentes.h"
#include "Venda.h"
#include "Menu.h"
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
          write();
          return 0;
        }
      } while (control != 's');
    }

    if (option == 0)
    {
      read();
    }

    system("clear");
    cout << "              Menu Inicial              " << endl;
    cout << "========================================" << endl;
    cout << "\nEscolha a operação desejada         \n" << endl;
    cout << "1 - Loja                              \n" << endl;
    cout << "2 - Maquina                           \n" << endl;
    cout << "3 - Verificar Bilhetes                \n" << endl;
    cout << "4 - Verificar dados de um bilhete     \n" << endl;
    cout << "0 - Sair                              \n" << endl;

    cin.clear();
    cin >> option;

    switch (option) {
    case 1:
      system("clear");
      Loja();
      break;

    case 2:
      system("clear");
      Maquina();
      break;

    case 3:
      system("clear");
      Bilhetes();
      break;

    case 4:
      system("clear");
      test();
      break;

    case 5:
      system("clear");

      break;
    }
  } while (option != 0);
  write();
  return 0;
}
