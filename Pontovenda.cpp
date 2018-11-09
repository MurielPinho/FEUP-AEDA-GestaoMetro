#include "Pontovenda.h"
#include <sstream>
#include <iostream>

using namespace std;

Pontovenda::Pontovenda(int id, string n, bool t)

{
  identificacao = id;
  nome          = n;
  tipo          = t;
}

string Pontovenda::getNome() const
{
  return nome;
}

int Pontovenda::getIdentificacao() const
{
  return identificacao;
}

int Pontovenda::getTipo() const
{
  return tipo;
}

string Pontovenda::getInformacao() const {
  stringstream ss;

  if (tipo)
  {
    ss << identificacao << " " <<  nome << " " << "Loja";
  }
  else
  {
    ss << identificacao << " " <<  nome << " " << "Maquina";
  }
  return ss.str();
}

Maquina::Maquina(int id, string n, bool t) : Pontovenda(id, n, t)
{}

Loja::Loja(int id, string n, bool t) : Pontovenda(id, n, t)
{}
