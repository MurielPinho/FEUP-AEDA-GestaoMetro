#include "Manutencao.h"

using namespace std;

Manutencao::Manutencao(string tr, string tp, bool av, vector<int> dt, int ddif){
        avaria = av;
        trem = tr;
        tipo = tp;
        data = {dt[0],dt[1],dt[2],dt[3],dt[4]};
        datadif = ddif;
}


string Manutencao::getInformacao() const {
        stringstream ss;

        ss << "Trem : " << trem << endl;
        ss << "Avaria : " << avaria << endl;
        ss << "Tipo : " << tipo << endl;
        ss << "Data : " << setw(2) << setfill('0') << data.at(0) << "/" << setw(2) << setfill('0') << data.at(1) << "/" << setw(4) << setfill('0') << data.at(2) << endl;
        ss << "Hora : " << setw(2) << setfill('0') << data.at(3) << ":" << setw(2) << setfill('0') << data.at(4);
        return ss.str();
}

string Manutencao::getInfo() const {
        stringstream ss;

        ss << trem << "," << avaria << "," << tipo << "," << data.at(0) << "," << data.at(1) << "," << data.at(2) << ",";
        ss << data.at(3) << "," << data.at(4);
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

int Manutencao::getDdif() const
{
        return datadif;
}

vector<int> Manutencao::getData() const
{
        return data;
}

void Manutencao::setData(vector<int> dt)
{
        data[0] = dt[0];
        data[1] = dt[1];
        data[2] = dt[2];
        data[3] = dt[3];
        data[4] = dt[4];
}

bool Manutencao::operator<(const Manutencao &m1) const {
        if(datadif == m1.datadif)
                return m1.avaria;
        else
                return (datadif > m1.datadif);
}

bool Manutencao::operator==(const Manutencao &m1) const {
        return ((datadif == m1.datadif) && (avaria == m1.avaria));
}
