#ifndef BILHETE_H_
#define BILHETE_H_

#include <string>
#include <vector>
#include <ctime>

using namespace std;


class Bilhete {
protected:

  float preco;

public:

  // Funções
};

class Assinatura : public Bilhete {
  string nome;
  vector<int>zonas;
  vector<int>validade(2); // MM::AA

public:

  // Funções
}
class Normal : public Assinatura {
public:

  Normal(float pc, string nm, vector<int>z);

  // Funções
}
class Estudante : public Assinatura {
  int idade, cc;
  string escola;

public:

  Estudante(float pc, string nm, vector<int>z, int id, int cc, string esc);

  // Funções
}
class Junior : public Assinatura {
  int idade, cc;

public:

  Junior(float pc, string nm, vector<int>z, int id, int cc);

  // Funções
}

class Senior : public Assinatura {
  int idade, cc;

public:

  Junior(float pc, string nm, vector<int>z, int id, int cc);

  // Funções
}

class Ocasional : public Bilhete {
  int viagens, duracao, tipo, partida;
  bool validado;
  vector<int>validade(5);

public:

  // Funções
}
class Diario : public Ocasional {
public:

  Diario(float pc, int vg, int dr, int tp);

  // Funções
}
class Unico : public Ocasional {
public:

  Diario(float pc, int vg, int dr, int tp);

  // Funções
}
#endif /*BILHETE_H_*/
