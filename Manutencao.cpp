#include "Manutencao.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

Manutencao::Manutencao(string tr, string tp, bool av, int dia, int mes, int ano){
        avaria = av;
        trem = tr;
        tipo = tp;
        data[0]=dia;
        data[1]=mes;
        data[2]=ano;



}


string Manutencao::getInformacao() const {
        stringstream ss;

        ss << setw(2) << setfill('0') << fixed << "Trem : " << trem << endl << "Avaria : " << avaria << endl << "Tipo : " << tipo << endl << "Data : " << data.at(0) << "/" << data.at(1) << "/" << setw(4) << data.at(2);
        return ss.str();
}

string Manutencao::getInfo() const {
        stringstream ss;

        ss << setw(2) << setfill('0') << fixed << trem << "," << avaria << "," << tipo << "," << data.at(0) << "," << data.at(1) << "," << setw(4) << data.at(2);
        return ss.str();
}

string Manutencao::getTrem() const
{
        return trem;
}

string Manutencao::getTipo() const
{
        return tipo;
}

void Manutencao::setTipo(string tp)
{
        tipo = tp;
}

bool Manutencao::getAvaria() const
{
        return avaria;
}

void Manutencao::setAvaria(bool av)
{
        avaria = av;
}

array<int,3>  Manutencao::getData() const
{
        return data;
}
