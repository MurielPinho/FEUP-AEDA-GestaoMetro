#include "Funcionario.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

Funcionario::Funcionario(string n, int id, string l, float sal, string f)
{
        salario       = sal;
        local         = l;
        nome          = n;
        funcao        = f;
        identificacao   = id;
}

string Funcionario::getInformacao() const {
        stringstream ss;

        ss << setprecision(2) << fixed << "Nome : " << nome << endl << "Identificacao : " << identificacao << endl << "Local : " << local << endl << "Salario : " << salario << endl << "Função : " << funcao << endl;
        return ss.str();
}

string Funcionario::getInfo() const {
        stringstream ss;

        ss << setprecision(2) << fixed << nome << "," << identificacao << "," << local << "," << salario << "," << funcao;
        return ss.str();
}

int Funcionario::getId() const
{
        return identificacao;
}

float Funcionario::getSalario() const
{
        return salario;
}

void Funcionario::setSalario(float nS)
{
        salario = nS;
}

string Funcionario::getName() const
{
        return nome;
}

string Funcionario::getLocal() const
{
        return local;
}

string Funcionario::getFuncao() const
{
        return funcao;
}

bool Funcionario::operator<(const Funcionario &f1) const {
        if(salario == f1.salario) {
                return (nome < f1.nome);
        }
        else
                return (salario < f1.salario);
}

bool Funcionario::operator==(const Funcionario &f1) const {
        return ((identificacao == f1.identificacao) || ((salario == f1.salario) && (nome == f1.nome)));
}
