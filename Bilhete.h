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

public:

  // Funções
  Bilhete(float p, bool t);
  float          getPreco() const;
  bool           getTipo() const;
  virtual string getInformacao() const;
};

class Assinatura : public Bilhete {
protected:

  string nome;

public:

  // Funções
  Assinatura(float p, bool t, string n);
  virtual string getInformacao() const;
  float          precosA(int Z);
};
class Normal : public Assinatura {
public:

  // Funções
  Normal(float p, bool t, string n);
  string getInformacao() const;
};
class Estudante : public Assinatura {
protected:

  int idade, CC;
  string escola;

public:

  // Funções
  Estudante(float p, bool t, string n, int id, int cc, string esc);
  string getInformacao() const;
};

class Junior : public Assinatura {
  int idade, CC;

public:

  // Funções
  Junior(float p, bool t, string n, int id, int cc);
  string getInformacao() const;
};

class Senior : public Assinatura {
  int idade, CC;

public:

  // Funções
  Senior(float p, bool t, string n, int id, int cc);
  string getInformacao() const;
};

class Ocasional : public Bilhete {
protected:

  int duracao, partida, viagens;
  bool validado;

public:

  // Funções
  Ocasional(float p, bool t, int d, int v);
  string getInformacao() const;
};

class Diario : public Ocasional {
public:

  // Funções
  Diario(float p, bool t, int d, int v);
};

class Unico : public Ocasional {
public:

  // Funções
  Unico(float p, bool t, int d, int v);
};


#endif /*BILHETE_H_*/
