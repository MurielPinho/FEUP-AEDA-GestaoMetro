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

  // ! Constroi um bilhete generico com identificao, preco, tipo e zona
  Bilhete(int id, int z, float p, bool t);

  // ! Retorna o preco do bilhete
  float          getPreco() const;

  // ! Retorna a zona do Bilhete
  int            getZona() const;

  // ! Retorna o tipo de bilhete
  bool           getTipo() const;

  // ! Retorna uma string com toda a informacao sobre um bilhete.
  virtual string getInformacao() const;
  virtual string getInformacaoTab() const;

  // ! Retorna a identificacao do bilhete
  int            getIdentificacao() const;

  // ! Retorna a duracao do bilhete, caso este parametro nao exista, retorna 0
  virtual int    getDuracao() const;

  // ! Retorna o desconto do bilhete, caso este parametro nao exista, retorna 0
  virtual int    getDesconto() const;

  // ! Retorna a duracao do bilhete, caso este parametro nao exista, retorna string vazia
  virtual string getNome() const;
  virtual ~Bilhete() {}
};

class Assinatura : public Bilhete {
protected:

  string nome;
  int desconto;

public:

  // Funções
  // ! Constroi um bilhete do tipo Assinatura, que adiciona as informacoes de nome e desconto ao Bilhete Generico
  Assinatura(int id, int z, float p, bool t, string n, int d);
  virtual string getInformacao() const;
  virtual string getInformacaoTab() const;
  int            getDuracao() const;
  int            getDesconto() const;
  string         getNome() const;
};
class Normal : public Assinatura {
public:

  // Funções
  // ! Constroi um bilhete do tipo Normal, que adiciona as informacoes do Bilhete Assinatura
  Normal(int id, int z, float p, bool t, string n, int d);
  string getInformacao() const;
  string getInformacaoTab() const;
};
class Estudante : public Assinatura {
protected:

  int idade, CC;
  string escola;

public:

  // Funções
  // ! Constroi um bilhete do tipo Estudante, que adiciona as informacoes de idade, CC e escola ao Bilhete Assinatura
  Estudante(int id, int z, float p, bool t, string n, int d, int idd, int cc, string esc);
  string getInformacao() const;
  string getInformacaoTab() const;
};

class Junior : public Assinatura {
  int idade, CC;

public:

  // Funções
  // ! Constroi um bilhete do tipo Junior, que adiciona as informacoes de idade e CC ao Bilhete Assinatura
  Junior(int id, int z, float p, bool t, string n, int d, int idd, int cc);
  string getInformacao() const;
  string getInformacaoTab() const;
};

class Senior : public Assinatura {
  int idade, CC;

public:

  // Funções
  // ! Constroi um bilhete do tipo Senior, que adiciona as informacoes de idade e CC ao Bilhete Assinatura
  Senior(int id, int z, float p, bool t, string n, int d, int idd, int cc);
  string getInformacao() const;
  string getInformacaoTab() const;
};

class Ocasional : public Bilhete {
protected:

  int duracao, viagens;
  bool validado;
  string partida;

public:

  // Funções
  // ! Constroi um bilhete do tipo Ocasional que adiciona duracao, partida, viagens e validado ao Bilhete Generico
  Ocasional(int id, int z, float p, bool t, int d, string pt, int v, bool vdd);
  virtual string getInformacao() const;
  virtual string getInformacaoTab() const;
  int            getDuracao() const;
  string         getNome() const;
  int            getDesconto() const;
};

class Diario : public Ocasional {
public:

  // Funções
  // ! Constroi um bilhete do tipo Diario que adiciona informacoes do Bilhete Ocasional
  Diario(int id, int z, float p, bool t, int d, string pt, int v, bool vdd);
  string getInformacao() const;
  string getInformacaoTab() const;
};

class Unico : public Ocasional {
public:

  // Funções
  // ! Constroi um bilhete do tipo Unico que adiciona informacoes do Bilhete Ocasional
  Unico(int id, int z, float p, bool t, int d, string pt, int v, bool vdd);
  string getInformacao() const;
  string getInformacaoTab() const;
};


#endif /*BILHETE_H_*/
