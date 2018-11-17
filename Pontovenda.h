#ifndef pontoVenda_H_
#define pontoVenda_H_

#include "Venda.h"
#include <string>

class pontoVenda {
protected:

  string nome;
  int identificacao;
  bool tipo;

public:

  // ! Constroi um ponto de venda generico com identificacao, nome e tipo
  pontoVenda(int id, string n, bool t);

  // ! Retorna o nome do ponto de venda
  string getNome() const;

  // ! Retorna uma string com toda a informacao do ponto de venda
  string getInformacao() const;

  // ! Retorna a identificao do ponto de venda
  int    getIdentificacao() const;

  // ! Retorna o tipo do ponto de venda
  int    getTipo() const;
  virtual ~pontoVenda() {}
};
class Maquina : public pontoVenda {
public:

  // Funções
  // ! Constroi um ponto de venda do tipo Maquina, que adiciona as informacoes do pontoVenda
  Maquina(int id, string n, bool t);
};
class Loja : public pontoVenda {
public:

  // Funções
  // ! Constroi um ponto de venda do tipo Loja, que adiciona as informacoes do pontoVenda
  Loja(int id, string n, bool t);
};
#endif /*pontoVenda_H_*/
