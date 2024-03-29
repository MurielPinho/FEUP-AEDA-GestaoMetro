#ifndef MANUTENCAO_H_
#define MANUTENCAO_H_

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <string>


using namespace std;
// !  Classe Manutencao.
/*!
   Contem funcoes e dados das Manutencoes.
 */
class Manutencao {
protected:
//!Booleano.
/*!Existencia de avaria.*/
bool avaria;
//!String.
/*!Nome do trem.*/
string trem;
//!String.
/*!Tipo de manutencao.*/
string tipo;
//!Vector de Inteiros.
/*!Data da manutencao.*/
time_t data;
//!Inteiro.
/*!Diferenca de tempo em segundos ate a manutencao.*/
int datadif;

public:

//! Contrutor que recebe dois inteiros, uma string e um booleano.
/*!
    Constroi um funcionario generico.
    \param tr string de nome do trem.
    \param tp string de tipo de avaria.
    \param av booleano de existencia de avaria.
    \param dt vector<int> da data de marcacao.
    \param ddif int de tempo restante em segundos para a manutencao.
 */
Manutencao(string tr, string tp, bool av, time_t dt, int ddif);

//! Membro normal.
/*!
   \return Retorna o Trem da Marcacao.
 */
string getTrem() const;

//! Membro normal.
/*!
   \return Caso alguma avaria seja detectada, retornara uma explicacao desta avaria.
 */
string getTipo() const;

//! Membro normal.
/*!
   Altera a explicacao da avaria do trem.
 */

void setTipo(string tp);

//! Membro normal.
/*!
   Altera a data da manutencao
 */
void setData(time_t dt);

//! Membro normal.
/*!
   \return Retorna a diferenca de tempo ate a manutencao.
 */
int   getDdif() const;

//! Membro normal.
/*!
   \return Retorna a data da manutencao.
 */
time_t getData() const;

//! Membro normal.
/*!
   \return Retorna se foi detectada uma avaria no Trem da Marcacao.
 */
bool getAvaria() const;

//! Membro normal.
/*!
   \return Altera o valor booleano de avaria.
 */
void setAvaria(bool av);


//! Membro normal.
/*!
   \return Retorna uma string com a informacao da Manutencao.
 */
string getInformacao() const;

//! Membro normal.
/*!
   \return Retorna uma string com a informacao da Manutencao escrita na forma de Ficheiro.
 */
string getInfo() const;

//! Membro normal.
/*!
   \return valor booleano resultante da comparacao entre 2 manutencoes.
 */
bool operator<(const Manutencao &m1) const;

//! Membro normal.
/*!
   \return valor booleano resultante da comparacao entre 2 manutencoes.
 */
bool operator==(const Manutencao &m1) const;


};

#endif /*MANUTENCAO_H_*/
