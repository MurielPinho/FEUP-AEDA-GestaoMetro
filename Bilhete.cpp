#include "Bilhete.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>


using namespace std;

Bilhete::Bilhete(int id, int z, float p, bool t)
{
  identificacao = id;
  preco         = p;
  tipo          = t;
  zona          = z;
}

string Bilhete::getInformacao() const {
  stringstream ss;

  ss << setprecision(2) << fixed << identificacao << "," << zona << "," <<  preco << "," << tipo;
  return ss.str();
}

float Bilhete::getPreco() const
{
  return preco;
}

int Bilhete::getZona() const
{
  return zona;
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

int Bilhete::getDesconto() const
{
  return 0;
}

string Bilhete::getNome() const
{
  return "";
}

Assinatura::Assinatura(int id, int z, float p, bool t, string n, int d) : Bilhete(id, z, p, t)
{
  nome     = n;
  desconto = d;
}

int Assinatura::getDuracao() const
{
  return 0;
}

int Assinatura::getDesconto() const
{
  return desconto;
}

string Assinatura::getNome() const
{
  return nome;
}

string Assinatura::getInformacao() const
{
  stringstream ss;

  ss << Bilhete::getInformacao() << "," << nome << "," << desconto;
  return ss.str();
}

Normal::Normal(int id, int z, float p, bool t, string n, int d) : Assinatura(id, z, p, t, n, d)
{}


string Normal::getInformacao() const {
  stringstream ss;

  ss << "Normal" << "," << Assinatura::getInformacao();
  return ss.str();
}

Estudante::Estudante(int id, int z, float p, bool t, string n, int d, int idd, int cc, string esc) : Assinatura(id,
                                                                                                                z,
                                                                                                                p,
                                                                                                                t,
                                                                                                                n, d)
{
  idade  = idd;
  CC     = cc;
  escola = esc;
}

string Estudante::getInformacao() const {
  stringstream ss;

  ss << "Estudante" << "," << Assinatura::getInformacao() << "," << idade << "," << CC << "," << escola;
  return ss.str();
}

Junior::Junior(int id, int z, float p, bool t, string n, int d, int idd, int cc) : Assinatura(id, z, p, t, n, d)
{
  idade = idd;
  CC    = cc;
}

string Junior::getInformacao() const {
  stringstream ss;

  ss << "Junior" << "," << Assinatura::getInformacao() << "," << idade << "," << CC;
  return ss.str();
}

Senior::Senior(int id, int z, float p, bool t, string n, int d, int idd, int cc) : Assinatura(id, z, p, t, n, d)
{
  idade = idd;
  CC    = cc;
}

string Senior::getInformacao() const {
  stringstream ss;

  ss << "Senior" << "," << Assinatura::getInformacao() << "," << idade << "," << CC;
  return ss.str();
}

Ocasional::Ocasional(int id, int z, float p, bool t, int d, string pt, int v, bool vdd) : Bilhete(id, z, p, t)
{
  duracao  = d;
  partida  = pt;
  viagens  = v;
  validado = vdd;
}

string Ocasional::getInformacao() const
{
  stringstream ss;

  ss << Bilhete::getInformacao() << "," << duracao << "," << partida << "," << viagens << "," << validado;
  return ss.str();
}

int Ocasional::getDuracao() const
{
  return duracao;
}

int Ocasional::getDesconto() const
{
  return 0;
}

string Ocasional::getNome() const
{
  return "";
}

Diario::Diario(int id, int z, float p, bool t, int d, string pt, int v, bool vdd) : Ocasional(id, z, p, t, d, pt, v,
                                                                                              vdd)
{}

string Diario::getInformacao() const
{
  stringstream ss;

  ss << "Diario" << "," << Ocasional::getInformacao();
  return ss.str();
}

Unico::Unico(int id, int z, float p, bool t, int d, string pt, int v, bool vdd) : Ocasional(id, z, p, t, d, pt, v, vdd)
{}

string Unico::getInformacao() const
{
  stringstream ss;

  ss << "Unico" << "," << Ocasional::getInformacao();
  return ss.str();
}
