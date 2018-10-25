#ifndef VENDA_H_
#define VENDA_H_

#include <vector>
#include "Bilhete.h"
using namespace std;

int      Maquina();
int      Loja();
Bilhete* FOcasional();
Bilhete* FAssinatura();
bool     Pagamento(float preco);
void     Bilhetes();
int      numBilhetes();


#endif /*VENDA_H_*/
