#ifndef METRO_H_
#define METRO_H_

#include "Funcionario.h"
#include "Local.h"
#include "BST.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <sstream>

using namespace std;

class Metro {
BST<Funcionario> funcionarios;

public:
Metro();
void addFuncionario();
void removeFuncionario();
void dadosFuncionario();
void dadoFuncionario();
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
};

#endif /*METRO_H_*/
