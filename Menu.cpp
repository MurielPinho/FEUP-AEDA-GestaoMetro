#include <iostream>
#include "Bilhete.h"
#include "Utentes.h"
#include "Venda.h"
#include "pontoVenda.h"
#include "Local.h"

using namespace std;

int main() {
  int  option = 0;
  char control;

  readData();

  do {
    if ((option >= 1) && (option <= 5))
    {
      do {
        cout << "Deseja realizar outra operação ? (s/n)" << endl;
        cin >> control;
        cin.clear();
        system("clear");

        if (control == 'n')
        {
          writeData();
          return 0;
        }
      } while (control != 's');
    }
    system("clear");
    cout << "              Menu Inicial              " << endl;
    cout << "========================================" << endl;
    cout << "Local Atual: " << localAtual() << " "     << endl;
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
      removeBilhete();
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
      alterarLocal();
      break;
    }
  } while (option != 0);
  writeData();
  return 0;
}
