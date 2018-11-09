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

  void     adicionaAssinatura(Bilhete *a1);
  void     adicionaOcasional(Bilhete *o1);
  int      numOcasionais() const;
  int      numAssinaturas() const;
  string   getOcasionais() const;
  string   getAssinaturas() const;
  Bilhete* getOcasional(int id) const;
  Bilhete* getAssinatura(int id) const;
  bool     removeOcasional(int id);
  bool     removeAssinatura(int id);
};


#endif /*UTENTES_H_*/
