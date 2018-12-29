#ifndef MANUTENCAO_H_
#define MANUTENCAO_H_

#include <vector>
#include <string>
#include <array>


using namespace std;
// !  Classe Manutencao.
/*!
   Contem funcoes e dados dos Manutencaos.
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
/*!Tipo de avaria(se existente).*/
string tipo;
//!Vector de Inteiros.
/*!Data da manutencao.*/
array<int,3> data;

public:

//! Contrutor que recebe dois inteiros, uma string e um booleano.
/*!
    Constroi um funcionario generico.
    \param tr string de nome do trem.
    \param tp string de tipo de avaria.
    \param av booleano de existencia de avaria.
    \param dia inteiro de dia da manutencao
    \param mes inteiro de mes da manutencao
    \param ano inteiro de ano da manutencao
 */
Manutencao(string tr, string tp, bool av, int dia, int mes, int ano);

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
   \return Retorna a data da manutencao.
 */
array<int,3> getData() const;

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


};

#endif /*MANUTENCAO_H_*/
