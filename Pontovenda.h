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
//! Constroi um ponto de venda generico com identificacao, nome e tipo
Pontovenda(int id, string n, bool t);
//! Retorna o nome do ponto de venda
string getNome() const;
//! Retorna uma string com toda a informacao do ponto de venda
string getInformacao() const;
//! Retorna a identificao do ponto de venda
int    getIdentificacao() const;
//! Retorna o tipo do ponto de venda
int    getTipo() const;
virtual ~Pontovenda() {
}
};
class Maquina : public Pontovenda {
public:

// Funções
//! Constroi um ponto de venda do tipo Maquina, que adiciona as informacoes do Pontovenda
Maquina(int id, string n, bool t);
};
class Loja : public Pontovenda {
public:

// Funções
//! Constroi um ponto de venda do tipo Loja, que adiciona as informacoes do Pontovenda
Loja(int id, string n, bool t);
};
#endif /*PONTOVENDA_H_*/
