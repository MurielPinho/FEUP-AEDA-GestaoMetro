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
    if (ocasionais[i]->getDuracao() == 2)
    {
      ss << "Unico" << " " << ocasionais[i]->getIdentificacao() << " " << "Z" << ocasionais[i]->getZona() << "\n";
    }
    else
    {
      ss << "Diario" << " " << ocasionais[i]->getIdentificacao() << " " << "Z" << ocasionais[i]->getZona() << "\n";
    }
  }
  return ss.str();
}

string Utentes::getAssinaturas() const

{
  stringstream ss;

  for (unsigned int i = 0; i < assinaturas.size(); i++) {
    if (assinaturas[i]->getDesconto() == 0)
    {
      ss << "Normal" << " ";
    }
    else if (assinaturas[i]->getDesconto() == 1)
    {
      ss << "Estudante" << " ";
    }
    else if (assinaturas[i]->getDesconto() == 2)
    {
      ss << "Junior" << " ";
    }
    else if (assinaturas[i]->getDesconto() == 3)
    {
      ss << "Senior" << " ";
    }

    ss << assinaturas[i]->getIdentificacao() << " ";
    ss << assinaturas[i]->getNome() << " " << "Z";
    ss << assinaturas[i]->getZona() << "\n";
  }
  return ss.str();
}

Bilhete * Utentes::getOcasional(int id) const
{
  for (unsigned int i = 0; i < ocasionais.size(); i++)
  {
    if (ocasionais[i]->getIdentificacao() == id)
    {
      return ocasionais[i];
    }
  }
  return NULL;
}

Bilhete * Utentes::getAssinatura(int id) const
{
  for (unsigned int i = 0; i < assinaturas.size(); i++) {
    if (assinaturas[i]->getIdentificacao() == id)
    {
      return assinaturas[i];
    }
  }
  return NULL;
}
