#ifndef UTENTES_H_
#define UTENTES_H_

#include <vector>
#include "Bilhete.h"
using namespace std;

// !  Classe Utentes.
/*!
   Contem funcoes e dados sobre os utentes e bilhetes do sistema de metro.
 */
class Utentes {
protected:
  //!Vetor de ponteiros.
  /*!Contem os bilhetes do tipo assinatura.*/
  vector<Bilhete *>assinaturas;
  //!Vetor de ponteiros.
  /*!Contem os bilhetes do tipo ocasional.*/
  vector<Bilhete *>ocasionais;

public:
  //! Membro normal que recebe um ponteiro da classe bilhete.
  /*!
  Adiciona o bilhete *a1 ao vetor de assinaturas.
  
    \param *a1 um ponteiro de bilhete.
   */
  void     adicionaAssinatura(Bilhete *a1);

  //! Membro normal que recebe um ponteiro da classe bilhete.
  /*!
  Adiciona o bilhete *o1 ao vetor de ocasionais.
    \param *o1 um ponteiro de bilhete.
   */
  void     adicionaOcasional(Bilhete *o1);

  //! Membro normal.
  /*!
     \return Retorna o numero de bilhetes ocasionais.
   */
  int      numOcasionais() const;

  //! Membro normal.
  /*!
     \return Retorna o numero de bilhetes assinaturas.
   */
  int      numAssinaturas() const;

  //! Membro normal.
  /*!
     \return Retorna uma string de todos os bilhetes ocasionais.
   */
  string   getOcasionais() const;

  //! Membro normal.
  /*!
     \return Retorna uma string de todos os bilhetes assinaturas.
   */
  string   getAssinaturas() const;

  //! Membro normal que recebe um inteiro.
  /*!
     \param id um inteiro de identificacao.
     \return Retorna o ponteiro de ocasional do vetor ocasionais com identificacao igual a id.
   */
  Bilhete* getOcasional(int id) const;

  //! Membro normal que recebe um inteiro.
  /*!
     \param id um inteiro de identificacao.
     \return Retorna o ponteiro de assinatura do vetor assinaturas com identificacao igual a id.
   */
  Bilhete* getAssinatura(int id) const;

  //! Membro normal que recebe um inteiro.
  /*!
      \param i um inteiro de posicao.
       \return Retorna o ponteiro de ocasional com posicao i no vetor ocasionais.
   */
  Bilhete* getVecOcasional(int i) const;

  //! Membro normal que recebe um inteiro.
  /*!
     \param i um inteiro de posicao.
     \return Retorna o ponteiro de assinatura com posicao i no vetor assinaturas.
   */
  Bilhete* getVecAssinatura(int i) const;

  //! Membro normal que recebe um inteiro.
  /*!
     Remove o bilhete ocasional de identificacao igual a id.
     \param id um inteiro de identificacao.
     \return Retorna o booleano relativo ao sucesso da remocao.
   */
  bool     removeOcasional(int id);

  //! Membro normal que recebe um inteiro.
  /*!
     Remove o bilhete assinatura de identificacao igual a id.
     \param id um inteiro de identificacao.
     \return Retorna o booleano relativo ao sucesso da remocao.
   */
  bool     removeAssinatura(int id);

  //! Membro normal.
  /*!
     Ordena o vetor ocasionais de forma crescente em relacao a identificacao.
   */
  void     OrdenarOcasional();

  //! Membro normal.
  /*!
     Ordena o vetor ocasionais de forma crescente em relacao a identificacao.
   */
  void     OrdenarAssinatura();
};


#endif /*UTENTES_H_*/
