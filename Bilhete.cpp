#include "Bilhete.h"
#include "Precos.cpp"
#include <iostream>

using namespace std;


float Assinatura::precosA(int Z)
{
	//Esta função determina o valor mensal de uma assinatura segundo a categoria (z)
	//(Usei valores arbitrarios pras 4 categorias ja que não sei o que colocar aqui)
	switch (z) {
	case 1:
		return Assinatura_Z1;
	case 2:
		return Assinatura_Z2;
	case 3:
		return Assinatura_Z3;
	case 4:
		return Assinatura_Z4;
	}
	return 0.0f;
}

Normal::Normal(string nm, int Z)
{
	nome = nm;
	z = Z;
	preco = precosA(z);
}

Estudante::Estudante(string nm, int Z, int CC, int id, string esc)
{
	nome = nm;
	z = Z;
	idade = id;
	cc = CC;
	escola = esc;
	preco = 0.75f*precosA(z); //Determinar o preço do bilhete com desconto de estudante
}

Junior::Junior(string nm, int Z, int id, int CC)
{
	nome = nm;
	z = Z;
	idade = id;
	cc = CC;
	preco = 0.75f*precosA(z); //Determinar o preço do bilhete com desconto de estudante
}

Senior::Senior(string nm, int Z, int id, int CC)
{
	nome = nm;
	z = Z;
	idade = id;
	cc = CC;
	preco = 0.75f*precosA(z); //Determinar o preço do bilhete com desconto de estudante
}

Diario::Diario(int Z)
{
	z = Z;
	switch (Z) {
	case 1:
		preco = Diario_Z1;
	case 2:
		preco = Diario_Z2;
	case 3:
		preco = Diario_Z3;
	case 4:
		preco = Diario_Z4;
	}
	duracao = 24;

}

Unico::Unico(int Z)
{
	z = Z;
	switch (Z) {
	case 1:
		preco = Viagem_Z1;
	case 2:
		preco = Viagem_Z2;
	case 3:
		preco = Viagem_Z3;
	case 4:
		preco = Viagem_Z4;
	}
	duracao = 2;

}
