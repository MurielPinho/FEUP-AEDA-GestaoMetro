#include <iostream>
#include "Bilhete.h"
#include "Utentes.h"
#include "Venda.h"
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
        cin.clear();
        cin >> control;
        system("clear");

        if (control == 'n')
        {
          return 0;
        }
      } while (control != 's');
    }

    system("clear");
    cout << "              Menu Inicial              " << endl;
    cout << "========================================" << endl;
    cout << "\nEscolha a operação desejada         \n" << endl;
    cout << "1 - Comprar / Renovar bilhete         \n" << endl;
    cout << "2 - Alterar localização               \n" << endl;
    cout << "3 - Verificar Validade                \n" << endl;
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
    }
  } while (option != 0);

  return 0;
}
