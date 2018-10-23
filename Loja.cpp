#include <iostream>
#include "Bilhete.h"
#include "Utentes.h"
using namespace std;

// Este arquivo de origem simula a venda de um bilhete em uma loja

int main1() {
  Bilhete B;
  string  s;
  int     i, j, Z;
  bool    b;

  cout << "1 - Ocasional" << endl;
  cout << "2 - Assinatura\n" << endl;
  cin >> i;

  if (i == 1) {
    cout << "\n1 - Titulo de Viagem" << endl;
    cout << "2 - Titulo Diario\n" << endl;
    cin >> j;
    cout << "\nTipo de bilhete: \n\n2 - Z2 \n3 - Z3 \n4 - Z4\n" << endl;
    cin >> Z;

    switch (j) {
    case 1:
      B = Unico(Z);

    case 2:
      B = Diario(Z);
    }
  }
  else if (i == 2) {
    b = false;
    cout << "\n1 - Normal" << endl;
    cout << "2 - Estudante" << endl;
    cout << "3 - Junior" << endl;
    cout << "4 - Senior" << endl;
    cin >> j;
    cout << "\nTipo de bilhete: 1 - z1, 2- z2, 3 - z3, 4 - z4)" << endl;
    cin >> Z;
    string nm;
    cout << "\nDigite o seu nome" << endl;
    cin >> nm;

    if (j == 1) {
      B = Normal(nm, Z);
    }
    else if ((j > 1) & (j <= 4)) {
      int cc;
      int id;
      string esc;
      cout << "\nDigite o numero do cartao de cidadao" << endl;
      cin >> cc;
      cout << "\nDigite sua idade" << endl;
      cin >> id;

      switch (j) {
      case 2:
        cout << "\nNome da sua escola" << endl;
        cin >> esc;
        B = Estudante(nm, Z, cc, id, esc);

      case 3:
        B = Junior(nm, Z, cc, id);

      case 4:
        B = Senior(nm, Z, cc, id);
      }
    }
  }
  cout << "\nValor: " << B.preco << " euros";
  cin >> i;
  return 0;
}
