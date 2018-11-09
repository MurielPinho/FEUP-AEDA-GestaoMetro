#ifndef VENDA_H_
#define VENDA_H_

#include <vector>
#include "Bilhete.h"

using namespace std;


void     comprarBilhete();
void     comprarMaquina();
void     comprarLoja();
Bilhete* FOcasional();
Bilhete* FAssinatura();
bool     Pagamento(float preco);
void     Bilhetes();
int      numBilhetes();
void     dadosBilhete();
void     readFile();
void     writeFile();
void     AlterarLocal();
string   LocalAtual();
void     Locais();
void     removeBilhete();



#endif /*VENDA_H_*/
