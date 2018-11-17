#ifndef UTENTES_H_
#define UTENTES_H_

#include <vector>
#include "Bilhete.h"
using namespace std;


class Utentes {
protected:

  vector<Bilhete *>assinaturas;
  vector<Bilhete *>ocasionais;

public:

  // ! adiciona o bilhete ao vetor de assinaturas
  void     adicionaAssinatura(Bilhete *a1);

  // ! adiciona o bilhete ao vetor de ocasionais
  void     adicionaOcasional(Bilhete *o1);

  // ! retorna o numero de bilhetes ocasionais
  int      numOcasionais() const;

  // ! retorna o numero de assinaturas ocasionais
  int      numAssinaturas() const;

  // ! retorna uma string de todos os bilhetes ocasionais
  string   getOcasionais() const;

  // ! retorna uma string de todos os bilhetes assinaturas
  string   getAssinaturas() const;

  // ! retorna o bilhete ocasional de determinada identificacao
  Bilhete* getOcasional(int id) const;

  // ! retorna o vetor de bilhetes ocasionais
  Bilhete* getVecOcasional(int i) const;

  // ! retorna o vetor de bilhetes assinaturas
  Bilhete* getVecAssinatura(int i) const;

  // ! retorna o bilhete assinatura de determinada identificacao
  Bilhete* getAssinatura(int id) const;

  // ! remove o bilhete ocasional de determinada identificacao
  bool     removeOcasional(int id);

  // ! remove o bilhete assinatura de determinada identificacao
  bool     removeAssinatura(int id);

  // ! ordena o vetor de bilhetes ocasionais conforme a identificacao
  void     OrdenarOcasional();

  // ! ordena o vetor de bilhetes assinaturas conforme a identificacao
  void     OrdenarAssinatura();
};


#endif /*UTENTES_H_*/
