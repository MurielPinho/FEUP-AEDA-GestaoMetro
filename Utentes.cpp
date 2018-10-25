#include "Utentes.h"
#include "Menu.h"
#include <sstream>

#include <iostream>

using namespace std;

void Utentes::adicionaAssinatura(Bilhete *a1)
{
  assinaturas.push_back(a1);
}

void Utentes::adicionaOcasional(Bilhete *o1)
{
  ocasionais.push_back(o1);
}

int Utentes::numAssinaturas() const
{
  return assinaturas.size();
}

int Utentes::numOcasionais() const
{
  return ocasionais.size();
}

string Utentes::getOcasionais() const

{
  stringstream ss;

  for (unsigned int i = 0; i < ocasionais.size(); i++) {
    ss << ocasionais[i]->getInformacao() << "\n";
  }
  return ss.str();
}

string Utentes::getAssinaturas() const

{
  stringstream ss;

  for (unsigned int i = 0; i < assinaturas.size(); i++) {
    ss << assinaturas[i]->getInformacao() << "\n";
  }
  return ss.str();
}

// void Utentes::getOcasionais()
// {
//   vector<Bilhete *>::const_iterator it = ocasionais.begin();
//
//   while (it != ocasionais.end()) {
//     cout << *it->getInformacao() << endl;
//     it++;
//   }
// }
