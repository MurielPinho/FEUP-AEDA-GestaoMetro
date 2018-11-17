#include "pontoVenda.h"
#include <sstream>
#include <iostream>

using namespace std;

pontoVenda::pontoVenda(int id, string n, bool t)

{
  identificacao = id;
  nome          = n;
  tipo          = t;
}

string pontoVenda::getNome() const
{
  return nome;
}

int pontoVenda::getIdentificacao() const
{
  return identificacao;
}

int pontoVenda::getTipo() const
{
  return tipo;
}

string pontoVenda::getInformacao() const {
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

Maquina::Maquina(int id, string n, bool t) : pontoVenda(id, n, t)
{}

Loja::Loja(int id, string n, bool t) : pontoVenda(id, n, t)
{}
