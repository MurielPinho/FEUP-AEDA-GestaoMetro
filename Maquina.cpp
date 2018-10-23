#include <iostream>
#include "Bilhete.h"
#include "Utentes.h"
using namespace std;

// Este arquivo de origem simula a venda de um bilhete em uma maquina

int main2() {
  Bilhete B1;
  string  s;
  int     j, Z;

  cout << "\n1 - Titulo de Viagem" << endl;
  cout << "2 - Titulo Diario" << endl;
  cin >> j;
  cout << "\nTipo de bilhete: 1 - z1, 2- z2, 3 - z3, 4 - z4)" << endl;
  cin >> Z;

  switch (j) {
  case 1:
    B1 = Unico(Z);

  case 2:
    B1 = Diario(Z);
  }
  cout << "\nValor: " << B1.preco << " euros" << endl;
  return 0;
}
