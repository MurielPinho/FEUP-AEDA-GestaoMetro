#include <iostream>
#include "Bilhete.h"
#include "Utentes.h"
#include "Venda.h"
#include "pontoVenda.h"
#include "Local.h"
#include "Metro.h"
#include <time.h>

using namespace std;

/*! \mainpage Documentação Das Classes
 * Este site tem como objetivo ilustrar o sistema de classes utilizado, contendo descrições detalhadas dos membros-dado
 * e membros-função de todas as classes criadas.
 *
 * \section intro_sec Diagrama
 *
 *
 * Todas as classes podem ser acessadas através do menu abaixo que está ordenado alfabeticamente e além disso segue a
 * hierarquia das classes, agrupando classes e subclasses.
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
  Venda  v;
  Metro  m;
  int    option = 0, start = 0, op = 0;
  char   control;
  char   buffer[80];
  time_t now;
  struct tm horario;

  v.readData();
  m.readData();

  do {
    if (((op == 1) && ((option >= 1) && (option <= 8))) || ((op == 2) && ((option >= 1) && (option <= 9))))
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
    time(&now);
    horario = *localtime(&now);
    cout << "              Menu Inicial              " << endl;
    cout << "========================================" << endl;
    cout << "Local Atual: " << v.localAtual() << " "   << endl;
    strftime(buffer, 80, "Data Atual: %d/%m/%y %I:%M%p", &horario);
    puts(buffer);
    cout << "========================================" << endl;
    cout << "\nEscolha o tipo de operação desejada \n" << endl;
    cout << "1 - Gerenciamento de Bilhetes         \n" << endl;
    cout << "2 - Gerenciamento do Metro            \n" << endl;
    cout << "0 - Sair                              \n" << endl;

    cin.clear();
    cin >> start;

    switch (start) {
    case 1:
      system("clear");
      op = 1;
      break;

    case 2:
      system("clear");
      op = 2;
      break;
    }

    if (start == 0) break;


    if (op == 1) {
      system("clear");
      cout << "              Bilhetes                  " << endl;
      cout << "========================================" << endl;
      cout << "Local Atual: " << v.localAtual() << " "   << endl;
      strftime(buffer, 80, "Data Atual: %d/%m/%y %I:%M%p", &horario);
      puts(buffer);
      cout << "========================================" << endl;
      cout << "\nEscolha a operação desejada         \n" << endl;
      cout << "1 - Comprar Bilhetes                  \n" << endl;
      cout << "2 - Remover Bilhete                   \n" << endl;
      cout << "3 - Renovar Assinatura                \n" << endl;
      cout << "4 - Validar Bilhete                   \n" << endl;
      cout << "5 - Verificar Bilhetes                \n" << endl;
      cout << "6 - Verificar dados de um bilhete     \n" << endl;
      cout << "7 - Alterar localidade                \n" << endl;
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
        v.renovarAss();
        break;

      case 4:
        system("clear");
        v.validar();
        break;

      case 5:
        system("clear");
        v.Bilhetes();
        break;

      case 6:
        system("clear");
        v.dadosBilhete();
        break;

      case 7:
        system("clear");
        v.alterarLocal();
        break;
      }
    }

    if (op == 2) {
      cout << "               Metro                    " << endl;
      cout << "========================================" << endl;
      cout << "Local Atual: " << v.localAtual() << " "   << endl;
      strftime(buffer, 80, "Data Atual: %d/%m/%y %I:%M%p", &horario);
      puts(buffer);
      cout << "========================================" << endl;
      cout << "\nEscolha a operação desejada         \n" << endl;
      cout << "1 - Contratar Funcionario             \n" << endl;
      cout << "2 - Demitir Funcionario               \n" << endl;
      cout << "3 - Verificar Funcionarios            \n" << endl;
      cout << "4 - Verificar dados de um Funcionario \n" << endl;
      cout << "5 - Alterar salario de um Funcionario \n" << endl;
      cout << "6 - Marcar nova Manutencao            \n" << endl;
      cout << "7 - Mudanca da manutencao por avaria  \n" << endl;
      cout << "8 - Imprimir ordem de manutencoes     \n" << endl;
      cout << "0 - Sair                              \n" << endl;


      cin.clear();
      cin >> option;

      switch (option) {
      case 1:
        system("clear");
        m.addFuncionario();
        break;

      case 2:
        system("clear");
        m.removeFuncionario();
        break;

      case 3:
        system("clear");
        m.dadosFuncionario();
        break;

      case 4:
        system("clear");
        m.dadoFuncionario();
        break;

      case 5:
        system("clear");
        m.SalarioFuncionario();
        break;

      case 6:
        system("clear");
        m.AddManutencao();
        break;

      case 7:
        system("clear");
        m.setAv();
        break;

      case 8:
        system("clear");
        m.PrintFila();
        break;
      }
    }
  } while (option != 0);
  v.writeData();
  m.writeData();

  return 0;
}
