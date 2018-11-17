#include "Local.h"
#include <sstream>

#include <iostream>

using namespace std;

void Local::adicionaLocal(pontoVenda *l1)
{
  locais.push_back(l1);
}

void Local::defineLocal(int i)
{
  LocalAtual = i;
}

pontoVenda * Local::getLocal(int id) const
{
  for (unsigned int i = 0; i < locais.size(); i++)
  {
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

pontoVenda * Local::getLocalAtual() const
{
  pontoVenda *P = getLocal(LocalAtual);

  return P;
}

bool Local::removeLocal(int id)
{
  for (int i = 0; i < locais.size(); i++)
  {
    if (locais[i]->getIdentificacao() == id)
    {
      locais.erase(locais.begin() + i);
      return true;
    }
  }
  return false;
}

void Local::OrdenarLocais()
{
  int i, j, k, n;
  pontoVenda *P1, *P2, *T;

  n = locais.size();

  for (i = n / 2; i > 0; i = i / 2)
  {
    for (j = i; j < n; j++)
    {
      for (k = j - i; k >= 0; k = k - i)
      {
        P1 = locais.at(k + i);
        P2 = locais.at(k);

        if (P1->getIdentificacao() >= P2->getIdentificacao()) break;
        else
        {
          T                = P2;
          locais.at(k)     = P1;
          locais.at(k + i) = T;
        }
      }
    }
  }
}
