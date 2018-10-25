#ifndef UTENTES_H_
#define UTENTES_H_

#include <vector>
#include "Bilhete.h"
using namespace std;


class Utentes {
  vector<Bilhete *>assinaturas;
  vector<Bilhete *>ocasionais;

public:

  void   adicionaAssinatura(Bilhete *a1);
  void   adicionaOcasional(Bilhete *o1);
  int    numOcasionais() const;
  int    numAssinaturas() const;
  string getOcasionais() const;
  string getAssinaturas() const;
};


#endif /*UTENTES_H_*/
