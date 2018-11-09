#ifndef BILHETE_H_
#define BILHETE_H_

#include <string>
#include <vector>
#include <ctime>
#include <string>


using namespace std;


class Bilhete {
protected:

  float preco;
  bool tipo;
  int identificacao, zona;

public:

  // Funções
  Bilhete(int id, int z, float p, bool t);
  float          getPreco() const;
  int            getZona() const;
  bool           getTipo() const;
  virtual string getInformacao() const;
  int            getIdentificacao() const;
  virtual int    getDuracao() const;
  virtual int    getDesconto() const;
  virtual string getNome() const;
};

class Assinatura : public Bilhete {
protected:

  string nome;
  int desconto;

public:

  // Funções
  Assinatura(int id, int z, float p, bool t, string n, int d);
  virtual string getInformacao() const;
  int            getDuracao() const;
  int            getDesconto() const;
  string         getNome() const;
};
class Normal : public Assinatura {
public:

  // Funções
  Normal(int id, int z, float p, bool t, string n, int d);
  string getInformacao() const;
};
class Estudante : public Assinatura {
protected:

  int idade, CC;
  string escola;

public:

  // Funções
  Estudante(int id, int z, float p, bool t, string n, int d, int idd, int cc, string esc);
  string getInformacao() const;
};

class Junior : public Assinatura {
  int idade, CC;

public:

  // Funções
  Junior(int id, int z, float p, bool t, string n, int d, int idd, int cc);
  string getInformacao() const;
};

class Senior : public Assinatura {
  int idade, CC;

public:

  // Funções
  Senior(int id, int z, float p, bool t, string n, int d, int idd, int cc);
  string getInformacao() const;
};

class Ocasional : public Bilhete {
protected:

  int duracao, viagens;
  bool validado;
  string partida;

public:

  // Funções
  Ocasional(int id, int z, float p, bool t, int d, string pt, int v, bool vdd);
  virtual string getInformacao() const;
  int            getDuracao() const;
  string         getNome() const;
  int            getDesconto() const;
};

class Diario : public Ocasional {
public:

  // Funções
  Diario(int id, int z, float p, bool t, int d, string pt, int v, bool vdd);
  string getInformacao() const;
};

class Unico : public Ocasional {
public:

  // Funções
  Unico(int id, int z, float p, bool t, int d, string pt, int v, bool vdd);
  string getInformacao() const;
};


#endif /*BILHETE_H_*/
