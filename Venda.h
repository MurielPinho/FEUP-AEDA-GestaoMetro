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
Bilhete* criarOcasional();
//! Continuacao da funcao comprarBilhete() para bilhetes assinaturas e cria o objeto bilhete assinatura
Bilhete* criarAssinatura();
//! Efetua a confirmacao do pagamento, apos o output de preco
bool     Pagamento(float preco);
//! Imprime na tela a informacao de todos os bilhetes
void     Bilhetes();
//! Imprime na tela os dados de determinado bilhete de acordo com as informacoes de input: tipo e identificacao
void     dadosBilhete();
//! Faz a leitura do ficheiro com os dados da execucao anterior e adiciona nos vetores apropriados
void     readData();
//! Escreve os bilhetes no ficheiro de bilhetes
void     writeData();
//! Altera o local de acordo com o input: numero do local
void     alterarLocal();
//! Retorna uma string com o nome do local atual
string   localAtual();
//! Imprime na tela todos os locais
void     Locais();
//! Remove o bilhete de acordo com as informacoes de input: tipo e identificacao
void     removeBilhete();




#endif /*VENDA_H_*/
