#ifndef FUNCIONARIO_H_
#define FUNCIONARIO_H_

#include <string>
#include <vector>
#include <string>


using namespace std;
// !  Classe funcionario.
/*!
   Contem funcoes e dados dos funcionarios.
 */
class Funcionario {
protected:
//!Float.
/*!Salario do funcionario.*/
float salario;
//!String.
/*!Local do funcionario.*/
string local;
//!String.
/*!Nome do funcionario.*/
string nome;
//!String,
/*!Funcao do funcionario.*/
string funcao;


public:
//! Contrutor que recebe dois inteiros, uma string e um booleano.
/*!
    Constroi um funcionario generico.
    \param n string de nome do funcionario.
    \param s float de salario do funcionario.
    \param l string de local do funcionario.
    \param f string de funcao do funcionario.
 */
Funcionario(float sal, string l, string n, string f);

//! Membro normal.
/*!
   \return Retorna o salario do funcionario.
 */

float getSalario() const;

//! Membro normal.
/*!
   \return Retorna o ponto de venda do funcionario.
 */
string getLocal() const;

//! Membro normal.
/*!
   \return Retorna o nome do funcionario.
 */
string getName() const;

//! Membro normal.
/*!
   \return Retorna a funcao do funcionario.
 */
string getFuncao() const;

//! Membro normal.
/*!
   \return Retorna uma string com a informacao essencial de um funcionario.
 */
string getInformacao() const;

//! Membro normal.
/*!
   \return Retorna uma string com a informacao do funcionario em forma de escrita do ficheiro.
 */
string getInfo() const;

//! Membro normal.
/*!
   \return valor booleano resultante da comparacao entre 2 funcionarios.
 */
bool operator<(const Funcionario &f1) const;

//! Membro normal.
/*!
   \return valor booleano resultante da comparacao entre 2 funcionarios.
 */
bool operator==(const Funcionario &f1) const;

//! Destrutor.
~Funcionario() {
}
};

#endif /*FUNCIONARIO_H_*/
