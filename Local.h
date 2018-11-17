#ifndef LOCAL_H_
#define LOCAL_H_

#include <vector>
#include "pontoVenda.h"
using namespace std;


class Local {
protected:

  int LocalAtual;
  vector<pontoVenda *>locais;

public:

  // ! adiciona o ponto de venda ao vetor de locais
  void        adicionaLocal(pontoVenda *l1);

  // ! representa o local atual de acordo com um numero de identificacao
  void        defineLocal(int i);

  // ! retorna o ponto de venda de determinado numero de identificacao
  pontoVenda* getLocal(int id) const;

  // ! retorna a string com a informacao de todos os pontos de venda
  string      getLocais() const;

  // ! retorna o ponto de venda do local atual
  pontoVenda* getLocalAtual() const;

  // ! remove o local de determinada identificacao
  bool        removeLocal(int id);

  // ! ordena o vetor de locais conforme a identificacao
  void        OrdenarLocais();
};


#endif /*LOCAL_H_*/
