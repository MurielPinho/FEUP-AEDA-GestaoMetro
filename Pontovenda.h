#ifndef pontoVenda_H_
#define pontoVenda_H_

#include "Venda.h"
#include <string>
// !  Classe Ponto de venda.
/*!
   Contem funcoes e dados sobre as possiveis localizacoes.
 */
class pontoVenda {
protected:
  //!String.
  /*!Indica o nome do ponto de venda.*/
  string nome;
  //!Inteiro.
  /*!Indica a identificacao do ponto de venda.*/
  int identificacao;
  //!Booleano.
  /*!Indica o tipo do ponto de venda.*/
  bool tipo;

public:
  //! Contrutor que recebe um inteiro, uma string e um booleano.
  /*!
      Constroi um ponto de venda generico.
      \param id inteiro de identificacao do ponto de venda.
      \param n string de nome do ponto de venda.
      \param t booleano de tipo do ponto de venda, 0 para loja e 1 para maquina.
   */
  pontoVenda(int id, string n, bool t);
  //! Membro normal.
  /*!
     \return Retorna o nome do ponto de venda.
   */
  string getNome() const;
  //! Membro normal.
  /*!
     \return Retorna uma string com toda a informacao do ponto de venda.
   */
  string getInformacao() const;
  //! Membro normal.
  /*!
     \return Retorna a identificao do ponto de venda.
   */
  int    getIdentificacao() const;
  //! Membro normal.
  /*!
     \return Retorna o tipo do ponto de venda.
   */
  int    getTipo() const;
  //! Destrutor.

  virtual ~pontoVenda() {}
};
// !  Classe Maquina.
/*!
   Contem funcoes e dados de ponto de vendas do tipo maquina.
 */
class Maquina : public pontoVenda {
public:
  //! Contrutor que recebe um inteiro, uma string e um booleano.
  /*!
      Constroi um ponto de venda do tipo Maquina.
      \param id inteiro de identificacao da Maquina.
      \param n string de nome da Maquina.
      \param t booleano de tipo da Maquina, 0 para loja e 1 para maquina.
   */
  Maquina(int id, string n, bool t);
};
// !  Classe Loja.
/*!
   Contem funcoes e dados de ponto de vendas do tipo loja.
 */
class Loja : public pontoVenda {
public:
  //! Contrutor que recebe um inteiro, uma string e um booleano.
  /*!
      Constroi um ponto de venda do tipo Loja.
      \param id inteiro de identificacao da Loja.
      \param n string de nome da Loja.
      \param t booleano de tipo da Loja, 0 para loja e 1 para maquina.
   */
  Loja(int id, string n, bool t);
};
#endif /*pontoVenda_H_*/
