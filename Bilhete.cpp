#include "Bilhete.h"
#include "Precos.cpp"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>


using namespace std;

Bilhete::Bilhete(float p, bool t)
{
  preco = p;
  tipo  = t;
}

string Bilhete::getInformacao() const {
  stringstream ss;

  ss << setprecision(2) << fixed <<  preco << ", " << tipo;
  return ss.str();
}

float Bilhete::getPreco() const
{
  return preco;
}

bool Bilhete::getTipo() const
{
  return tipo;
}

Assinatura::Assinatura(float p, bool t, string n) : Bilhete(p, t)
{
  nome = n;
}

string Assinatura::getInformacao() const
{
  stringstream ss;

  ss << Bilhete::getInformacao() << ", " << nome;
  return ss.str();
}

Normal::Normal(float p, bool t, string n) : Assinatura(p, t, n)
{}

string Normal::getInformacao() const {
  stringstream ss;

  ss << Assinatura::getInformacao();
  return ss.str();
}

Estudante::Estudante(float p, bool t, string n, int id, int cc, string esc) : Assinatura(p, t, n)
{
  idade  = id;
  CC     = cc;
  escola = esc;
}

string Estudante::getInformacao() const {
  stringstream ss;

  ss << Assinatura::getInformacao() << ", " << idade << ", " << CC << ", " << escola;
  return ss.str();
}

Junior::Junior(float p, bool t, string n, int id, int cc) : Assinatura(p, t, n)
{
  idade = id;
  CC    = cc;
}

string Junior::getInformacao() const {
  stringstream ss;

  ss << Assinatura::getInformacao() << ", " << idade << ", " << CC;
  return ss.str();
}

Senior::Senior(float p, bool t, string n, int id, int cc) : Assinatura(p, t, n)
{
  idade = id;
  CC    = cc;
}

string Senior::getInformacao() const {
  stringstream ss;

  ss << Assinatura::getInformacao() << ", " << idade << ", " << CC;
  return ss.str();
}

Ocasional::Ocasional(float p, bool t, int d, int v) : Bilhete(p, t)
{
  duracao  = d;
  partida  = 0;
  viagens  = v;
  validado = false;
}

string Ocasional::getInformacao() const
{
  stringstream ss;

  ss << Bilhete::getInformacao() << ", " << duracao << ", " << partida << ", " << viagens << ", " << validado;
  return ss.str();
}

Diario::Diario(float p, bool t, int d, int v) : Ocasional(p, t, d, v)
{}

Unico::Unico(float p, bool t, int d, int v) : Ocasional(p, t, d, v)
{}
