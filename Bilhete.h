#ifndef BILHETE_H_
#define BILHETE_H_

#include <string>
#include <vector>
#include <ctime>

using namespace std;


class Bilhete {
protected:

  int validade;

public:

  float preco;
  int z; // inteiro de 1 a 4 indicando a categoria relacionada às zonas
  // Funções
};

class Assinatura : public Bilhete {
protected:

  string nome;

public:

  float precosA(int Z);

  // Funções
};
class Normal : public Assinatura {
public:

  Normal(string nome, int z);

  // Funções
};
class Estudante : public Assinatura {
protected:

  int idade, cc;
  string escola;

public:

  Estudante(string nome, int z, int cc, int id, string escola);

  // Funções
};

class Junior : public Assinatura {
  int idade, cc;

public:

  Junior(string nome, int z, int id, int cc);

  // Funções
};

class Senior : public Assinatura {
  int idade, cc;

public:

  Senior(string nome, int z, int id, int cc);

  // Funções
};

class Ocasional : public Bilhete {
protected:

  int duracao, partida, validade;
  bool validado;

public:

  // Funções
};

class Diario : public Ocasional {
public:

  Diario(int Z);

  // Funções
};

class Unico : public Ocasional {
public:

  Unico(int Z);

  // Funções
};
#endif /*BILHETE_H_*/
