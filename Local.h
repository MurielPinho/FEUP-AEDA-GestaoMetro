#ifndef LOCAL_H_
#define LOCAL_H_

#include <vector>
#include "pontoVenda.h"
using namespace std;

// !  Classe Local.
/*!
   Contem funcoes e dados sobre o local onde o usuario se encontra.
 */
class Local {
protected:
  //!Inteiro.
  /*!Indica o local atual do usuario.*/
  int LocalAtual;
  //!Vetor de Ponteiros.
  /*! Contem ponteiros dos locais existentes.*/
  vector<pontoVenda *>locais;
public:

  //! Membro normal que recebe um ponteiro de ponto de venda.
  /*!
     Adiciona esse ponteiro ao vetor locais.
     \param *l1 um ponteiro de pontoVenda.
   */
  void adicionaLocal(pontoVenda *l1);

  //! Membro normal que recebe um inteiro.
  /*!
     Altera LocalAtual para o local com a identificacao recebida.
     \param i um parametro inteiro.
   */
  void defineLocal(int i);

  //! Membro normal que recebe um inteiro.
  /*!
     \param id um parametro inteiro.
     \return Ponteiro do tipo pontoVenda com identificacao igual ao parametro fornecido.
   */
  pontoVenda* getLocal(int id) const;

  //! Membro normal.
  /*!
     \return String contendo a informacao de todos os pontos de venda.
   */
  string getLocais() const;

  //! Membro normal.
  /*!
     \return Ponteiro do tipo pontoVenda do local atual.
   */
  pontoVenda* getLocalAtual() const;

  //! Membro normal que recebe um inteiro.
  /*!
     Remove do vetor locais o pontoVenda com identificacao igual a recebida.
     \return Booleano correspondente ao sucesso da remocao.
   */
  bool removeLocal(int id);

  //! Membro normal.
  /*!
     Ordena o vetor locais em relacao a identificacao em ordem crescente.
   */
  void OrdenarLocais();
};


#endif /*LOCAL_H_*/
