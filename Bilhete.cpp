#include "Bilhete.h"
#include "Precos.cpp"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>


using namespace std;

Bilhete::Bilhete(int id, float p, bool t)
{
  identificacao = id;
  preco         = p;
  tipo          = t;
}

string Bilhete::getInformacao() const {
  stringstream ss;

  ss << setprecision(2) << fixed << identificacao << ", " <<  preco << ", " << tipo;
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

int Bilhete::getIdentificacao() const
{
  return identificacao;
}

Assinatura::Assinatura(int id, float p, bool t, string n) : Bilhete(id, p, t)
{
  nome = n;
}

string Assinatura::getInformacao() const
{
  stringstream ss;

  ss << nome << ", " << Bilhete::getInformacao();
  return ss.str();
}

Normal::Normal(int id, float p, bool t, string n) : Assinatura(id, p, t, n)
{}

string Normal::getInformacao() const {
  stringstream ss;

  ss << Assinatura::getInformacao();
  return ss.str();
}

Estudante::Estudante(int id, float p, bool t, string n, int idd, int cc, string esc) : Assinatura(id, p, t, n)
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

Junior::Junior(int id, float p, bool t, string n, int idd, int cc) : Assinatura(id, p, t, n)
{
  idade = id;
  CC    = cc;
}

string Junior::getInformacao() const {
  stringstream ss;

  ss << Assinatura::getInformacao() << ", " << idade << ", " << CC;
  return ss.str();
}

Senior::Senior(int id, float p, bool t, string n, int idd, int cc) : Assinatura(id, p, t, n)
{
  idade = id;
  CC    = cc;
}

string Senior::getInformacao() const {
  stringstream ss;

  ss << Assinatura::getInformacao() << ", " << idade << ", " << CC;
  return ss.str();
}

Ocasional::Ocasional(int id, float p, bool t, int d, int v) : Bilhete(id, p, t)
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

Diario::Diario(int id, float p, bool t, int d, int v) : Ocasional(id, p, t, d, v)
{}

Unico::Unico(int id, float p, bool t, int d, int v) : Ocasional(id, p, t, d, v)
{}
