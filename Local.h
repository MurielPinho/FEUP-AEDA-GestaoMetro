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

//! adiciona o ponto de venda ao vetor de locais
void        adicionaLocal(Pontovenda *l1);
//! representa o local atual de acordo com um numero
void        defineLocal(int i);
//! retorna o ponto de venda de determinado numero
Pontovenda* getLocal(int id) const;
//! retorna a string de todos os pontos de venda
string      getLocais() const;
//! retorna o ponto de venda do local atual
Pontovenda* getLocalAtual() const;
//! remove o local de determinada identificacao
bool        removeLocal(int id);
//! ordena o vetor de locais conforme a identificacao
void        Organizar();
};


#endif /*LOCAL_H_*/
