#include <iostream>
#include <iomanip>
#include "Bilhete.h"
#include "Utentes.h"
using namespace std;

int Maquina()
{
  Bilhete B1;
  string  s;
  int     j, Z;

  cout << "Titulo unico ou diario ?" << endl << endl;
  cout << "1 - Unico" << endl;
  cout << "2 - Diario" << endl;
  cin >> j;
  cin.clear();
  system("clear");
  cout << "Tipo de bilhete: \n\n2 - Z2 \n3 - Z3 \n4 - Z4\n" << endl;
  cin >> Z;
  cin.clear();
  system("clear");

  switch (j) {
  case 1:
    B1 = Unico(Z);
    break;

  case 2:
    B1 = Diario(Z);
    break;
  }
  cout << std::setprecision(2) << std::fixed << "Valor: " << B1.preco << " euros" << endl;
  return 0;
}

int Loja()
{
  Bilhete B;
  string  s;
  int     i, j, Z;
  bool    b;

  cout << "Comprar bilhete ocasional ou renovar assinatura ?" << endl << endl;
  cout << "1 - Ocasional" << endl;
  cout << "2 - Assinatura\n" << endl;
  cin >> i;
  cin.clear();
  system("clear");

  if (i == 1) {
    cout << "Titulo unico ou diario ?" << endl << endl;
    cout << "1 - Unico" << endl;
    cout << "2 - Diario" << endl;
    cin >> j;
    cin.clear();
    system("clear");
    cout << "Tipo de bilhete: \n\n2 - Z2 \n3 - Z3 \n4 - Z4\n" << endl;
    cin >> Z;
    cin.clear();
    system("clear");

    switch (j) {
    case 1:
      B = Unico(Z);
      break;

    case 2:
      B = Diario(Z);
      break;
    }
  }
  else if (i == 2) {
    b = false;
    cout << "Tipo de bilhete:" << endl << endl;
    cout << "1 - Normal" << endl;
    cout << "2 - Estudante" << endl;
    cout << "3 - Junior" << endl;
    cout << "4 - Senior" << endl;
    cin >> j;
    cin.clear();
    system("clear");
    cout << "Tipo de bilhete: \n\n2 - Z2 \n3 - Z3 \n4 - Z4\n" << endl;
    cin >> Z;
    cin.clear();
    system("clear");
    string nm;
    cout << "Digite o seu nome" << endl;
    cin >> nm;
    cin.clear();
    system("clear");

    if (j == 1) {
      B = Normal(nm, Z);
    }
    else if ((j > 1) & (j <= 4)) {
      int cc;
      int id;
      string esc;
      cout << "Digite o numero do cartao de cidadao" << endl;
      cin >> cc;
      cin.clear();
      system("clear");
      cout << "Digite sua idade" << endl;
      cin >> id;
      cin.clear();
      system("clear");

      switch (j) {
      case 2:
        cout << "Nome da sua escola" << endl;
        cin >> esc;
        cin.clear();
        system("clear");
        B = Estudante(nm, Z, cc, id, esc);
        break;

      case 3:
        B = Junior(nm, Z, cc, id);
        break;

      case 4:
        B = Senior(nm, Z, cc, id);
        break;
      }
    }
  }
  cout << std::setprecision(2) << std::fixed << "Valor: " << B.preco << " euros" << endl << endl;
  return 0;
}
