#ifndef VENDA_H_
#define VENDA_H_

#include <fstream>
#include <limits>

#include "Utentes.h"
#include "Bilhete.h"

using namespace std;
// !  Classe Venda.
/*!
   Contem funcoes responsaveis por controlar a gestao dos bilhetes.
 */
class Venda {
public:

//! Membro normal.
/*!
   Chama a cadeia de funcoes para a compra do Bilhete.
 */
void     comprarBilhete();

//! Membro normal.
/*!
   Continuacao da funcao comprarBilhete() para compra em Maquina, adiciona o Bilhete ao vetor seu respectivo vetor.
 */
void     comprarMaquina();

//! Membro normal.
/*!
   Continuacao da funcao comprarBilhete() para compra em Loja, adiciona o Bilhete ao vetor seu respectivo vetor.
 */
void     comprarLoja();

//! Membro normal.
/*!
   Continuacao da funcao comprarBilhete() para bilhetes ocasionais.
   \return Retorna um ponteiro de Bilhete do tipo ocasional.
 */
Bilhete* criarOcasional();

//! Membro normal.
/*!
    Continuacao da funcao comprarBilhete() para bilhetes assinaturas.
    \return Retorna um ponteiro de Bilhete do tipo assinatura.
 */
Bilhete* criarAssinatura();

//! Membro normal.
/*!
    Efetua a confirmacao do pagamento, apos o output de preco.
    \param preco float contendo o preco do bilhete.
    \return Retorna o booleano relativo a realizacao do pagamento.
 */
bool     Pagamento(float preco);

//! Membro normal.
/*!
   Renova o bilhete do tipo Assinatura.
 */
void     renovarAss();

//! Membro normal.
/*!
   Valida um bilhete
 */
void     validar();

//! Membro normal.
/*!
    Imprime na tela a informacao resumida de cada bilhete atual.
 */
void     Bilhetes();

//! Membro normal.
/*!
    Imprime na tela todos os dados do bilhete escolhido pelo usuario.
 */
void     dadosBilhete();

//! Membro normal.
/*!
    Faz a leitura do ficheiro, bilhetes.txt, com os dados da execucao anterior e do ficheiro, locais.txt, com os dados dos pontos de venda e os adiciona nos vetores apropriados.
 */
void     readData();

//! Membro normal.
/*!
    Escreve os bilhetes presentes nos vetores no ficheiro bilhetes.txt .
 */
void     writeData();

//! Membro normal.
/*!
    \return a diferenca de duas datas em minutos.
 */
int     DataDiff(vector<int> d1, vector<int> d2);

//! Membro normal.
/*!
    Altera o localAtual de acordo com o numero do local escolhido.
 */
void     alterarLocal();

//! Membro normal.
/*!
    \return Uma string com o nome do local atual.
 */
string   localAtual();

//! Membro normal.
/*!
    Imprime na tela a informacao de todos os pontos de venda.
 */
void     Locais();

//! Membro normal.
/*!
    Remove o bilhete escolhido pelo usuario, caso esse exista.
 */
void     removeBilhete();

//! Membro normal.
/*!
    \param Z inteiro contendo o numero de zonas.
    \param D inteiro contendo a identificacao do desconto.
    \return Um float do preco de bilhete de acordo com o numero de zonas e seu desconto.
 */
float precos(int Z, int D);

};

#endif /*VENDA_H_*/
