#include "Bilhete.h"

using namespace std;

Bilhete::Bilhete(int id, int z, float p, bool t, time_t dt)
{
  identificacao = id;
  preco         = p;
  tipo          = t;
  zona          = z;
  data          = dt;
}

string Bilhete::getInformacao() const {
  stringstream ss;

  ss << setprecision(2) << fixed << identificacao << "," << zona << "," <<  preco << "," << tipo << "," << data;
  return ss.str();
}

string Bilhete::getInformacaoTab() const {
  stringstream ss;

  ss << right << setw(4) << identificacao;
  ss << right << setw(7) << zona;
  ss << " " << right << setw(7) << preco;
  return ss.str();
}

time_t Bilhete::getData() const
{
  return data;
}

bool Bilhete::getValidade() const
{
  return false;
}

int Bilhete::getViagens() const
{
  return 0;
}

void  Bilhete::setViagens(int v) {}

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

void Bilhete::Renovar() {}

void Bilhete::Validacao(bool vdd) {}

Assinatura::Assinatura(int id, int z, float p, bool t, time_t dt, string n, int d) : Bilhete(id, z, p, t, dt)
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

string Assinatura::getInformacaoTab() const
{
  stringstream ss;

  ss << Bilhete::getInformacaoTab();
  ss << " " <<  right << setw(14) << nome;
  return ss.str();
}

void Assinatura::Renovar() {
  time(&data);
}

Normal::Normal(int id, int z, float p, bool t, time_t dt, string n, int d) : Assinatura(id, z, p, t, dt, n, d)
{}

string Normal::getInformacao() const {
  stringstream ss;

  ss << "Normal" << "," << Assinatura::getInformacao();
  return ss.str();
}

string Normal::getInformacaoTab() const {
  stringstream ss;

  ss << "    Normal ";
  ss << Assinatura::getInformacaoTab();
  return ss.str();
}

Estudante::Estudante(int id, int z, float p, bool t, time_t dt, string n, int d, int idd, int cc,
                     string esc) : Assinatura(id,
                                              z,
                                              p,
                                              t,
                                              dt,
                                              n,
                                              d)
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

string Estudante::getInformacaoTab() const {
  stringstream ss;

  ss << " Estudante ";
  ss << Assinatura::getInformacaoTab();
  ss << " " << right << setw(7) << idade;
  ss << " " << right << setw(16) << CC;
  ss << " " << right << setw(13) << escola;
  return ss.str();
}

Junior::Junior(int id, int z, float p, bool t, time_t dt, string n, int d, int idd, int cc) : Assinatura(id,
                                                                                                         z,
                                                                                                         p,
                                                                                                         t,
                                                                                                         dt,
                                                                                                         n,
                                                                                                         d)
{
  idade = idd;
  CC    = cc;
}

string Junior::getInformacao() const {
  stringstream ss;

  ss << "Junior" << "," << Assinatura::getInformacao() << "," << idade << "," << CC;
  return ss.str();
}

string Junior::getInformacaoTab() const {
  stringstream ss;

  ss << "    Junior ";
  ss << Assinatura::getInformacaoTab();
  ss << " " << right << setw(7) << idade;
  ss << " " << right << setw(16) << CC;
  return ss.str();
}

Senior::Senior(int id, int z, float p, bool t, time_t dt, string n, int d, int idd, int cc) : Assinatura(id,
                                                                                                         z,
                                                                                                         p,
                                                                                                         t,
                                                                                                         dt,
                                                                                                         n,
                                                                                                         d)
{
  idade = idd;
  CC    = cc;
}

string Senior::getInformacao() const {
  stringstream ss;

  ss << "Senior" << "," << Assinatura::getInformacao() << "," << idade << "," << CC;
  return ss.str();
}

string Senior::getInformacaoTab() const {
  stringstream ss;

  ss << "    Senior ";
  ss << Assinatura::getInformacaoTab();
  ss << " " << right << setw(7) << idade;
  ss << " " << right << setw(16) << CC;
  return ss.str();
}

Ocasional::Ocasional(int id, int z, float p, bool t, time_t dt, int d, string pt, int v, bool vdd) : Bilhete(id,
                                                                                                             z,
                                                                                                             p,
                                                                                                             t,
                                                                                                             dt)
{
  duracao  = d;
  partida  = pt;
  viagens  = v;
  validado = vdd;
}

void Ocasional::Validacao(bool vdd) {
  validado = vdd;
}

bool Ocasional::getValidade() const
{
  return validado;
}

int Ocasional::getViagens() const
{
  return viagens;
}

void Ocasional::setViagens(int v) {
  viagens = v;
}

string Ocasional::getInformacao() const
{
  stringstream ss;

  ss << Bilhete::getInformacao() << "," << duracao << "," << partida << "," << viagens << "," << validado;
  return ss.str();
}

string Ocasional::getInformacaoTab() const
{
  stringstream ss;

  ss << Bilhete::getInformacaoTab();
  ss << right << setw(9) << viagens;
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

Diario::Diario(int id, int z, float p, bool t, time_t dt, int d, string pt, int v, bool vdd) : Ocasional(id,
                                                                                                         z,
                                                                                                         p,
                                                                                                         t,
                                                                                                         dt,
                                                                                                         d,
                                                                                                         pt,
                                                                                                         v,
                                                                                                         vdd)
{}

string Diario::getInformacao() const
{
  stringstream ss;

  ss << "Diario" << "," << Ocasional::getInformacao();
  return ss.str();
}

string Diario::getInformacaoTab() const
{
  stringstream ss;

  ss << "    Diario ";
  ss << Ocasional::getInformacaoTab();

  return ss.str();
}

Unico::Unico(int id, int z, float p, bool t, time_t dt, int d, string pt, int v, bool vdd) : Ocasional(id,
                                                                                                       z,
                                                                                                       p,
                                                                                                       t,
                                                                                                       dt,
                                                                                                       d,
                                                                                                       pt,
                                                                                                       v,
                                                                                                       vdd)
{}

string Unico::getInformacao() const
{
  stringstream ss;

  ss << "Unico" << "," << Ocasional::getInformacao();
  return ss.str();
}

string Unico::getInformacaoTab() const
{
  stringstream ss;

  ss << "     Unico ";
  ss << Ocasional::getInformacaoTab();
  return ss.str();
}
