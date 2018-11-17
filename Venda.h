#ifndef VENDA_H_
#define VENDA_H_

#include <vector>
#include "Bilhete.h"

using namespace std;

//! Chama a cadeia de funcoes que ira efetuar a compra do Bilhete
void     comprarBilhete();
//! Continuacao da funcao comprarBilhete() para a opcao de compra em Maquina
void     comprarMaquina();
//! Continuacao da funcao comprarBilhete() para a opcao de compra em Loja
void     comprarLoja();
//! Continuacao da funcao comprarBilhete() para bilhetes ocasionais e cria o objeto bilhete ocasional
Bilhete* FOcasional();
//! Continuacao da funcao comprarBilhete() para bilhetes assinaturas e cria o objeto bilhete assinatura
Bilhete* FAssinatura();
//! Efetua a confirmacao do pagamento, apos o output de preco
bool     Pagamento(float preco);
//! Imprime na tela a informacao de todos os bilhetes
void     Bilhetes();
int      numBilhetes();
//! Imprime na tela os dados de determinado bilhete de acordo com as informacoes de input: tipo e identificacao
void     dadosBilhete();
//! Abre o ficheiro dos bilhetes e adiciona nos vetores apropriados
void     readFile();
//! Escreve os bilhetes no ficheiro de bilhetes
void     writeFile();
//! Altera o local de acordo com o input: numero do local
void     AlterarLocal();
//! Retorna uma string com o nome do local atual
string   LocalAtual();
//! Imprime na tela todos os locais
void     Locais();
//! Remove o bilhete de acordo com as informacoes de input: tipo e identificacao
void     removeBilhete();
void     test();




#endif /*VENDA_H_*/
