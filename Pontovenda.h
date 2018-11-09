#ifndef PONTOVENDA_H_
#define PONTOVENDA_H_

#include "Venda.h"
#include <string>

class Pontovenda {
protected:

  string nome;
  int identificacao;
  bool tipo;

public:

  // Funções
  Pontovenda(int id, string n, bool t);
  string getNome() const;
  string getInformacao() const;
  int    getIdentificacao() const;
  int    getTipo() const;
  virtual ~Pontovenda() {}
};
class Maquina : public Pontovenda {
public:

  // Funções
  Maquina(int id, string n, bool t);
};
class Loja : public Pontovenda {
public:

  // Funções
  Loja(int id, string n, bool t);
};
#endif /*PONTOVENDA_H_*/
