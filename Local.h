#ifndef LOCAL_H_
#define LOCAL_H_

#include <vector>
#include "Pontovenda.h"
using namespace std;


class Local {
protected:

  int LocalAtual;
  vector<Pontovenda *>locais;

public:

  void        adicionaLocal(Pontovenda *l1);
  void        defineLocal(int i);
  Pontovenda* getLocal(int id) const;
  string      getLocais() const;
  Pontovenda* getLocalAtual() const;
  bool        removeLocal(int id);
};


#endif /*LOCAL_H_*/
