#ifndef BILHETE_H_
#define BILHETE_H_

#include <string>
#include <vector>
#include <string>


using namespace std;
// !  Classe Bilhete.
/*!
   Contem funcoes e dados dos bilhetes.
 */
class Bilhete {
protected:
//!Float.
/*!Preco do bilhete.*/
float preco;
//!Booleano.
/*!Tipo do bilhete.*/
bool tipo;
//!Inteiro.
/*!Identificacao do bilhete.*/
int identificacao;
//!Inteiro.
/*!Zona do bilhete.*/
int zona;

public:
//! Contrutor que recebe dois inteiros, uma string e um booleano.
/*!
    Constroi um bilhete generico.
    \param id inteiro de identificacao do bilhete.
    \param z numero de zonas do bilhete.
    \param p float de preco do bilhete.
    \param t booleano de tipo do bilhete, 0 para ocasional e 1 para assinatura.
 */
Bilhete(int id, int z, float p, bool t);

//! Membro normal.
/*!
   \return Retorna o preco do bilhete.
 */
float          getPreco() const;

//! Membro normal.
/*!
   \return Retorna a zona do Bilhete.
 */
int            getZona() const;

//! Membro normal.
/*!
   \return Retorna o tipo de bilhete.
 */
bool           getTipo() const;

//! Membro virtual.
/*!
   \return Retorna uma string com a informacao essencial de um bilhete.
 */
virtual string getInformacao() const;

//! Membro virtual.
/*!
   \return Retorna uma string com a informacao essencial de um bilhete tabulada.
 */
virtual string getInformacaoTab() const;

//! Membro normal.
/*!
   \return Retorna a identificacao do bilhete.
 */
int            getIdentificacao() const;

//! Membro virtual.
/*!
   \return Retorna a duracao do bilhete, caso este parametro nao exista, retorna 0.
 */
virtual int    getDuracao() const;

//! Membro virtual.
/*!
   \return Retorna o desconto do bilhete, caso este parametro nao exista, retorna 0.
 */
virtual int    getDesconto() const;

//! Membro virtual.
/*!
   \return Retorna o nome do dono do bilhete, caso este parametro nao exista, retorna string vazia.
 */
virtual string getNome() const;
//! Destrutor.
virtual ~Bilhete() {
}
};
// !  Classe Assinatura.
/*!
   Contem funcoes e dados dos bilhetes do tipo assinatura.
 */
class Assinatura : public Bilhete {
protected:
//!String.
/*!Nome do utente da assinatura.*/
string nome;
//!Inteiro.
/*!Identificacao do desconto da assinatura*/
int desconto;

public:
//! Contrutor que recebe tres inteiros, uma string, um float e um booleano.
/*!
    Constroi um bilhete do tipo assinatura.
    \param id inteiro de identificacao da assinatura.
    \param z numero de zonas da assinatura.
    \param p float de preco da assinatura.
    \param t booleano de tipo da assinatura, 0 para ocasional e 1 para assinatura.
    \param n string de nome da assinatura.
    \param d inteiro de desconto da assinatura.
 */
Assinatura(int id, int z, float p, bool t, string n, int d);
virtual string getInformacao() const;
virtual string getInformacaoTab() const;
int            getDuracao() const;
int            getDesconto() const;
string         getNome() const;
};
// !  Classe Normal.
/*!
   Contem funcoes e dados dos bilhetes de assinatura do tipo normal.
 */
class Normal : public Assinatura {
public:
//! Contrutor que recebe tres inteiros, uma string, um float e um booleano.
/*!
    Constroi uma assinatura do tipo Normal.
    \param id inteiro de identificacao da assinatura.
    \param z inteiro numero de zonas da assinatura.
    \param p float de preco da assinatura.
    \param t booleano de tipo da assinatura, 0 para ocasional e 1 para assinatura.
    \param n string de nome da assinatura.
    \param d inteiro de desconto da assinatura.
 */
Normal(int id, int z, float p, bool t, string n, int d);
string getInformacao() const;
string getInformacaoTab() const;
};
// !  Classe Estudante.
/*!
   Contem funcoes e dados dos bilhetes de assinatura do tipo estudante.
 */
class Estudante : public Assinatura {
protected:
//!Inteiro.
/*!Idade do estudante*/
int idade;
//!Inteiro.
/*!Cartao cidadao do estudante*/
int CC;
//!String.
/*!Escola do estudante*/
string escola;

public:
//! Contrutor que recebe cinco inteiros, duas strings, um float e um booleano.
/*!
    Constroi uma assinatura do tipo Estudante.
    \param id inteiro de identificacao da assinatura.
    \param z numero de zonas da assinatura.
    \param p float de preco da assinatura.
    \param t booleano de tipo da assinatura, 0 para ocasional e 1 para assinatura.
    \param n string de nome da assinatura.
    \param d inteiro de desconto da assinatura.
    \param idd inteiro de idade do titular da assinatura.
    \param cc numero do cartao cidadao do titular  da assinatura.
    \param n string de nome da instituicao de ensino do titular da assinatura.

 */
Estudante(int id, int z, float p, bool t, string n, int d, int idd, int cc, string esc);
string getInformacao() const;
string getInformacaoTab() const;
};
// !  Classe Junior.
/*!
   Contem funcoes e dados dos bilhetes de assinatura do tipo junior.
 */
class Junior : public Assinatura {
protected:
//!Inteiro.
/*!Idade do utente*/
int idade;
//!Inteiro.
/*!Cartao cidadao do utente */
int CC;
public:
//! Contrutor que recebe cinco inteiros, uma string, um float e um booleano.
/*!
    Constroi uma assinatura do tipo Junior.
    \param id inteiro de identificacao da assinatura.
    \param z numero de zonas da assinatura.
    \param p float de preco da assinatura.
    \param t booleano de tipo da assinatura, 0 para ocasional e 1 para assinatura.
    \param n string de nome da assinatura.
    \param d inteiro de desconto da assinatura.
    \param idd inteiro de idade do titular da assinatura.
    \param cc numero do cartao cidadao do titular  da assinatura.
 */
Junior(int id, int z, float p, bool t, string n, int d, int idd, int cc);
string getInformacao() const;
string getInformacaoTab() const;
};
// !  Classe Senior.
/*!
   Contem funcoes e dados dos bilhetes de assinatura do tipo junior.
 */
class Senior : public Assinatura {
protected:
//!Inteiro.
/*!Idade do utente*/
int idade;
//!Inteiro.
/*!Cartao cidadao do utente*/
int CC;
public:
//! Contrutor que recebe cinco inteiros, uma string, um float e um booleano.
/*!
    Constroi uma assinatura do tipo Senior.
    \param id inteiro de identificacao da assinatura.
    \param z numero de zonas da assinatura.
    \param p float de preco da assinatura.
    \param t booleano de tipo da assinatura, 0 para ocasional e 1 para assinatura.
    \param n string de nome da assinatura.
    \param d inteiro de desconto da assinatura.
    \param idd inteiro de idade do titular da assinatura.
    \param cc numero do cartao cidadao do titular  da assinatura.
 */
Senior(int id, int z, float p, bool t, string n, int d, int idd, int cc);
string getInformacao() const;
string getInformacaoTab() const;
};
// !  Classe Ocasional.
/*!
   Contem funcoes e dados dos bilhetes do tipo ocasional.
 */
class Ocasional : public Bilhete {
protected:
//!Inteiro.
/*!Tempo de duracao do bilhete*/
int duracao;
//!Inteiro.
/*!Numero de viagens*/
int viagens;
//!Booleano.
/*!Estado do bilhete ocasional, 0 para nao validade e 1 para validado*/
bool validado;
//!String.
/*!Local de partida*/
string partida;

public:
//! Contrutor que recebe quatro inteiros, uma string, um float e dois booleanos.
/*!
    Constroi um bilhete do tipo ocasional.
    \param id inteiro de identificacao do bilhete.
    \param z numero de zonas do bilhete.
    \param p float de preco do bilhete.
    \param t booleano de tipo do bilhete, 0 para ocasional e 1 para assinatura.
    \param d inteiro de duracao do bilhete.
    \param pt string de nome do local de partida do bilhete.
    \param v numero de viagens do bilhete.
    \param vdd booleano de estado de validacao do bilhete.
 */
Ocasional(int id, int z, float p, bool t, int d, string pt, int v, bool vdd);
virtual string getInformacao() const;
virtual string getInformacaoTab() const;
int            getDuracao() const;
string         getNome() const;
int            getDesconto() const;
};
// !  Classe Diario.
/*!
   Contem funcoes e dados dos bilhetes ocasionais do tipo diario.
 */
class Diario : public Ocasional {
public:
//! Contrutor que recebe quatro inteiros, uma string, um float e dois booleanos.
/*!
    Constroi um bilhete ocasional do tipo diario.
    \param id inteiro de identificacao do bilhete.
    \param z numero de zonas do bilhete.
    \param p float de preco do bilhete.
    \param t booleano de tipo do bilhete, 0 para ocasional e 1 para assinatura.
    \param d inteiro de duracao do bilhete.
    \param pt string de nome do local de partida do bilhete.
    \param v numero de viagens do bilhete.
    \param vdd booleano de estado de validacao do bilhete.
 */
Diario(int id, int z, float p, bool t, int d, string pt, int v, bool vdd);
string getInformacao() const;
string getInformacaoTab() const;
};
// !  Classe Unico.
/*!
   Contem funcoes e dados dos bilhetes ocasionais do tipo unico.
 */
class Unico : public Ocasional {
public:
//! Contrutor que recebe quatro inteiros, uma string, um float e dois booleanos.
/*!
    Constroi um bilhete ocasional do tipo Unico.
    \param id inteiro de identificacao do bilhete.
    \param z numero de zonas do bilhete.
    \param p float de preco do bilhete.
    \param t booleano de tipo do bilhete, 0 para ocasional e 1 para assinatura.
    \param d inteiro de duracao do bilhete.
    \param pt string de nome do local de partida do bilhete.
    \param v numero de viagens do bilhete.
    \param vdd booleano de estado de validacao do bilhete.
 */
Unico(int id, int z, float p, bool t, int d, string pt, int v, bool vdd);
string getInformacao() const;
string getInformacaoTab() const;
};


#endif /*BILHETE_H_*/
