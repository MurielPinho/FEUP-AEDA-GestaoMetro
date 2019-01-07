#include "Manutencao.h"

using namespace std;

Manutencao::Manutencao(string tr, string tp, bool av, time_t dt, int ddif) {
  avaria  = av;
  trem    = tr;
  tipo    = tp;
  data    = dt;
  datadif = ddif;
}

string Manutencao::getInformacao() const {
  stringstream ss;
  int ddif;
  time_t dataAtual;


  ss << "Trem : " << trem << endl;
  ss << "Avaria : ";

  if (avaria)
  {
    ss << "Sim";
  }
  else
  {
    ss << "Nao";
  }
  ss << endl;
  ss << "Tipo : " << tipo << endl;
  ss << "Data : " << ctime(&data);
  ss << "Tempo ate a Manutencao : ";
  ddif = difftime(data, time(&dataAtual));

  if (ddif < 86400)
  {
    ss << ddif / 3600 << " Hora(s)" << endl;
  }
  else
  {
    ss << ddif / 86400 << " dia(s)" << endl;
  }

  return ss.str();
}

string Manutencao::getInfo() const {
  stringstream ss;

  ss << trem << "," << avaria << "," << tipo << "," << data;
  return ss.str();
}

string Manutencao::getTrem() const
{
  return trem;
}

string Manutencao::getTipo() const
{
  return tipo;
}

void Manutencao::setTipo(string tp)
{
  tipo = tp;
}

bool Manutencao::getAvaria() const
{
  return avaria;
}

void Manutencao::setAvaria(bool av)
{
  avaria = av;
}

int Manutencao::getDdif() const
{
  return datadif;
}

time_t Manutencao::getData() const
{
  return data;
}

void Manutencao::setData(time_t dt)
{
  data = dt;
}

bool Manutencao::operator<(const Manutencao& m1) const {
  if (datadif == m1.datadif) return m1.avaria;
  else return datadif > m1.datadif;
}

bool Manutencao::operator==(const Manutencao& m1) const {
  return (datadif == m1.datadif) && (avaria == m1.avaria);
}
