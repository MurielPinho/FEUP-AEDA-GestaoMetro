#include "Bilhete.h"
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

  ss << setprecision(2) << fixed << identificacao << " " <<  preco << " " << tipo;
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

int Bilhete::getDuracao() const
{
  return 0;
}

Assinatura::Assinatura(int id, float p, bool t, string n) : Bilhete(id, p, t)
{
  nome = n;
}

int Assinatura::getDuracao() const
{
  return 0;
}

string Assinatura::getInformacao() const
{
  stringstream ss;

  ss << Bilhete::getInformacao() << " " << nome;
  return ss.str();
}

Normal::Normal(int id, float p, bool t, string n) : Assinatura(id, p, t, n)
{}


string Normal::getInformacao() const {
  stringstream ss;

  ss << "Normal " << Assinatura::getInformacao();
  return ss.str();
}

Estudante::Estudante(int id, float p, bool t, string n, int idd, int cc, string esc) : Assinatura(id, p, t, n)
{
  idade  = idd;
  CC     = cc;
  escola = esc;
}

string Estudante::getInformacao() const {
  stringstream ss;

  ss << "Estudante " << Assinatura::getInformacao() << " " << idade << " " << CC << " " << escola;
  return ss.str();
}

Junior::Junior(int id, float p, bool t, string n, int idd, int cc) : Assinatura(id, p, t, n)
{
  idade = idd;
  CC    = cc;
}

string Junior::getInformacao() const {
  stringstream ss;

  ss << "Junior " << Assinatura::getInformacao() << " " << idade << " " << CC;
  return ss.str();
}

Senior::Senior(int id, float p, bool t, string n, int idd, int cc) : Assinatura(id, p, t, n)
{
  idade = idd;
  CC    = cc;
}

string Senior::getInformacao() const {
  stringstream ss;

  ss << "Senior " << Assinatura::getInformacao() << " " << idade << " " << CC;
  return ss.str();
}

Ocasional::Ocasional(int id, float p, bool t, int d, string pt, int v, bool vdd) : Bilhete(id, p, t)
{
  duracao  = d;
  partida  = pt;
  viagens  = v;
  validado = vdd;
}

string Ocasional::getInformacao() const
{
  stringstream ss;

  ss << Bilhete::getInformacao() << " " << duracao << " " << partida << " " << viagens << " " << validado;
  return ss.str();
}

int Ocasional::getDuracao() const
{
  return duracao;
}

Diario::Diario(int id, float p, bool t, int d, string pt, int v, bool vdd) : Ocasional(id, p, t, d, pt, v, vdd)
{}

string Diario::getInformacao() const
{
  stringstream ss;

  ss << "Diario " << Ocasional::getInformacao();
  return ss.str();
}

Unico::Unico(int id, float p, bool t, int d, string pt, int v, bool vdd) : Ocasional(id, p, t, d, pt, v, vdd)
{}

string Unico::getInformacao() const
{
  stringstream ss;

  ss << "Unico " << Ocasional::getInformacao();
  return ss.str();
}
