#include "Funcionario.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

Funcionario::Funcionario(float sal, string l, string n, string f)
{
        salario       = sal;
        local         = l;
        nome          = n;
        funcao        = f;
}

string Funcionario::getInformacao() const {
        stringstream ss;

        ss << setprecision(2) << fixed << "Nome : " << nome << endl << "Local : " << local << endl << "Salario : " << salario << endl << "Função : " << funcao << endl;
        return ss.str();
}

string Funcionario::getInfo() const {
        stringstream ss;

        ss << setprecision(2) << fixed << nome << "," << local << "," << salario << "," << funcao;
        return ss.str();
}


float Funcionario::getSalario() const
{
        return salario;
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
        return ((salario == f1.salario) && (nome == f1.nome));
}
