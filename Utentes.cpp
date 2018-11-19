#include "Utentes.h"
#include <sstream>

#include <iostream>
#include <iomanip>

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
      ss << right << setw(7) << "Unico";
      ss << " " << right << setw(4) << ocasionais[i]->getIdentificacao();
      ss << "   " << "Z" << left << setw(3) <<  ocasionais[i]->getZona();
      ss << "\n";

      // ss << "Unico" << " " << ocasionais[i]->getIdentificacao() << " " << "Z" << ocasionais[i]->getZona() << "\n";
    }
    else
    {
      ss << right << setw(7) << "Diario";
      ss << " "  << right << setw(4) << ocasionais[i]->getIdentificacao();
      ss << "   " << "Z" << left << setw(3) <<  ocasionais[i]->getZona();
      ss << "\n";

      //  ss << "Diario" << " " << ocasionais[i]->getIdentificacao() << " " << "Z" << ocasionais[i]->getZona() << "\n";
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
      ss << right << setw(10) << "Normal";
    }
    else if (assinaturas[i]->getDesconto() == 1)
    {
      ss << right << setw(10) << "Estudante";
    }
    else if (assinaturas[i]->getDesconto() == 2)
    {
      ss << right << setw(10) << "Junior";
    }
    else if (assinaturas[i]->getDesconto() == 3)
    {
      ss << right << setw(10) << "Senior";
    }

    ss << " " << right << setw(4) << assinaturas[i]->getIdentificacao();
    ss << "  " << left << setw(15) << assinaturas[i]->getNome();
    ss << " Z" << left << setw(3) << assinaturas[i]->getZona();
    ss << "\n";
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

Bilhete * Utentes::getVecOcasional(int i) const
{
  return ocasionais[i];

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

Bilhete * Utentes::getVecAssinatura(int i) const
{
  return assinaturas[i];

  return NULL;
}

bool Utentes::removeAssinatura(int id)
{
  for (int i = 0; i < assinaturas.size(); i++)
  {
    if (assinaturas[i]->getIdentificacao() == id)
    {
      assinaturas.erase(assinaturas.begin() + i);
      return true;
    }
  }
  return false;
}

bool Utentes::removeOcasional(int id)
{
  for (int i = 0; i < ocasionais.size(); i++)
  {
    if (ocasionais[i]->getIdentificacao() == id)
    {
      ocasionais.erase(ocasionais.begin() + i);
      return true;
    }
  }
  return false;
}

void Utentes::OrdenarOcasional()
{
  int i, j, k, n;
  Bilhete *B1, *B2, *T;

  n = ocasionais.size();

  for (i = n / 2; i > 0; i = i / 2)
  {
    for (j = i; j < n; j++)
    {
      for (k = j - i; k >= 0; k = k - i)
      {
        B1 = ocasionais.at(k + i);
        B2 = ocasionais.at(k);

        if (B1->getIdentificacao() >= B2->getIdentificacao())
        {
          break;
        }
        else
        {
          T                    = B2;
          ocasionais.at(k)     = B1;
          ocasionais.at(k + i) = T;
        }
      }
    }
  }
}

void Utentes::OrdenarAssinatura()
{
  int i, j, k, n;
  Bilhete *B1, *B2, *T;

  n = assinaturas.size();

  for (i = n / 2; i > 0; i = i / 2)
  {
    for (j = i; j < n; j++)
    {
      for (k = j - i; k >= 0; k = k - i)
      {
        B1 = assinaturas.at(k + i);
        B2 = assinaturas.at(k);

        if (B1->getIdentificacao() >= B2->getIdentificacao())
        {
          break;
        }
        else
        {
          T                     = B2;
          assinaturas.at(k)     = B1;
          assinaturas.at(k + i) = T;
        }
      }
    }
  }
}
