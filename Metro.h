#ifndef METRO_H_
#define METRO_H_

#include "Funcionario.h"
#include "Manutencao.h"
#include "Local.h"
#include "BST.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <sstream>
#include <queue>
#include <string>

using namespace std;
// !  Classe Metro.
/*!
   Contem funcoes responsaveis por controlar a gestao das manutencoes e funcionarios.
 */
class Metro {
BST<Funcionario> funcionarios;

public:
//! Construtor da classe Metro
Metro();
//! Membro normal.
/*!
    Adiciona um funcionario a arvore binaria de pesquisa funcionarios.
 */
void addFuncionario();
//! Membro normal.
/*!
    Remove um funcionario da arvore binaria de pesquisa funcionarios.
 */
void removeFuncionario();
//! Membro normal.
/*!
    Imprime na tela os dados de todos os funcionarios.
 */
void dadosFuncionario();
//! Membro normal.
/*!
    Imprime na tela os dados de um funcionario especifico.
 */
void dadoFuncionario();
//! Membro normal.
/*!
    Altera o salario de um funcionario especifico.
 */
void     SalarioFuncionario();
//! Membro normal.
/*!
    Faz a leitura do ficheiro, funcionarios.txt, com os dados da execucao anterior e do ficheiro, locais.txt, com os dados dos pontos de venda e os adiciona nos vetores apropriados.
 */
void     readData();

//! Membro normal.
/*!
    Escreve os funcionarios presentes nos vetores no ficheiro funcionarios.txt .
 */
void     writeData();
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
    Adiciona uma nova manutencao a fila de prioridade.
 */
void     AddManutencao();

//! Membro normal.
/*!
    Adiciona avaria a marcacao de manutencao.
 */
void     setAv();

//! Membro normal.
/*!
    Imprime a fila de manutencoes.
 */
void PrintFila();
};

#endif /*METRO_H_*/
