#include "Local.h"
#include "Menu.h"
#include <sstream>

#include <iostream>

using namespace std;

void Local::adicionaLocal(Pontovenda *l1)
{
  locais.push_back(l1);
}

void Local::defineLocal(int i)
{
  LocalAtual = i;
}

Pontovenda * Local::getLocal(int id) const
{
  for (unsigned int i = 0; i < locais.size(); i++) {
    if (locais[i]->getIdentificacao() == id)
    {
      return locais[i];
    }
  }
  return NULL;
}

string Local::getLocais() const
{
  stringstream ss;

  for (unsigned int i = 0; i < locais.size(); i++)
  {
    ss << locais[i]->getInformacao() << "\n";
  }
  return ss.str();
}

Pontovenda * Local::getLocalAtual() const
{
  Pontovenda *P = getLocal(LocalAtual);

  return P;
}
