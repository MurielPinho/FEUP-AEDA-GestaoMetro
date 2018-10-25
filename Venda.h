#ifndef VENDA_H_
#define VENDA_H_

#include <vector>
#include "Bilhete.h"
using namespace std;

int      Maquina();
int      Loja();
Bilhete* Ocasional();
Bilhete* Assinatura();
bool     Pagamento(float preco);


#endif /*VENDA_H_*/
