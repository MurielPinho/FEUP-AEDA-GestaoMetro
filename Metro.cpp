#include "Metro.h"
#include <ctime>

Local local;
vector<int> dataAtual;

Metro::Metro() : funcionarios(Funcionario("",-1,"",0,"")){
}

void Metro::readData()
{
        ifstream locais, fs, tm;
        Funcionario *F;
        pontoVenda *P;

        tm.open("Data.txt", ios_base::in);
        fs.open("Funcionarios.txt", ios_base::in);
        locais.open("Locais.txt", ios_base::in);

        if(!tm) {
                cerr << "Arquivo não encontrado!\n";
        }
        else {
                string line;

                getline(tm, line);
                stringstream linestream(line);
                string value;
                vector<string> data;
                while(getline(linestream,value,'/')) {
                        data.push_back(value);
                }
                int dia,mes,ano;
                dia = stoi(data.at(0));
                mes = stoi(data.at(1));
                ano = stoi(data.at(2));
                getline(tm, line);
                stringstream lines(line);
                while(getline(lines,value,':')) {
                        data.push_back(value);
                }
                int hora, min;
                hora = stoi(data.at(3));
                min = stoi(data.at(4));
                dataAtual.push_back(dia);
                dataAtual.push_back(mes);
                dataAtual.push_back(ano);
                dataAtual.push_back(hora);
                dataAtual.push_back(min);
        }
        tm.close();
        if(!fs) {
                cerr << "Arquivo não encontrado!\n";
        }
        else {
                string line;

                while(getline(fs, line)) {
                        stringstream linestream(line);
                        string value;
                        vector<string> data;
                        while(getline(linestream,value,',')) {
                                data.push_back(value);
                        }
                        string nome, local, funcao;
                        float salario;
                        int id;
                        nome = data.at(0);
                        id = stoi(data.at(1));
                        local = data.at(2);
                        salario = stof(data.at(3));
                        funcao = data.at(4);
                        F = new Funcionario(nome, id, local, salario, funcao);
                        funcionarios.insert(*F);
                }
        }
        if (!locais)
        {
                cerr << "Arquivo não encontrado!\n";
        }
        else
        {
                string line;
                vector<string> word;

                while (getline(locais, line))
                {
                        stringstream linestream(line);
                        string value;
                        vector<string> word;

                        while (getline(linestream, value, ','))
                        {
                                word.push_back(value);
                        }
                        string tipo, nome;
                        int identificacao;
                        tipo          = word.at(0);
                        identificacao = stoi(word.at(1));
                        nome          = word.at(2);

                        if (tipo == "Maquina")
                        {
                                P = new Maquina(identificacao, nome, 0);
                                local.adicionaLocal(P);
                        }
                        else if (tipo == "Loja") {
                                P = new Loja(identificacao, nome, 1);
                                local.adicionaLocal(P);
                        }
                }

                local.defineLocal(1);
        }
        locais.close();
        fs.close();
        tm.close();
}

void Metro::writeData()
{
        ofstream out, tm;

        out.open("Funcionarios.txt");
        tm.open("Data.txt");
        BSTItrIn<Funcionario> it(funcionarios);
        while(!it.isAtEnd()) {
                out << it.retrieve().getInfo() << endl;
                it.advance();
        }
        tm << setw(2) << setfill('0') << dataAtual[0] << "/" << setw(2) << setfill('0') << dataAtual[1] << "/" << setw(4) << setfill('0') << dataAtual[2] << endl;
        tm << setw(2) << setfill('0') << dataAtual[3] << ":" << setw(2) << setfill('0') << dataAtual[4];
        out.close();
        tm.close();
}

void Metro::Locais()
{
        cout << "Locais de Venda :" << endl << endl;
        cout << local.getLocais() <<  endl;
}

string Metro::dataAt()
{
        stringstream ss;

        ss << setw(2) << setfill('0') << dataAtual[0] << "/" << setw(2) << setfill('0') << dataAtual[1] << "/" << setw(4) << setfill('0') << dataAtual[2];
        ss << " " << setw(2) << setfill('0') << dataAtual[3] << ":" << setw(2) << setfill('0') << dataAtual[4];
        return ss.str();
}

void Metro::alterarData()
{
        int dia, mes, ano, hora, min;
        cout << "Dia : ";
        cin >> dia;
        cout << "Mes : ";
        cin >> mes;
        cout << "Ano : ";
        cin >> ano;
        cout << "Hora : ";
        cin >> hora;
        cout << "Minutos : ";
        cin >> min;
        if(ano < 0) {
                cout << "Data Invalida" << endl << endl;
                return;
        }
        if((mes < 1) && (mes > 12)) {
                cout << "Data Invalida" << endl << endl;
                return;
        }

        switch(mes) {
        case 1:
                if((dia < 1) && (dia > 31)) {
                        cout << "Data Invalida" << endl << endl;
                        return;
                }
                break;
        case 2:
                if(ano%4 == 0) {
                        if((dia < 1) && (dia > 29)) {
                                cout << "Data Invalida" << endl << endl;
                                return;
                        }
                }
                else{
                        if((dia < 1) && (dia > 28)) {
                                cout << "Data Invalida" << endl << endl;
                                return;
                        }
                }
                break;
        case 3:
                if((dia < 1) && (dia > 31)) {
                        cout << "Data Invalida" << endl << endl;
                        return;
                }
                break;
        case 4:
                if((dia < 1) && (dia > 30)) {
                        cout << "Data Invalida" << endl << endl;
                        return;
                }
                break;
        case 5:
                if((dia < 1) && (dia > 31)) {
                        cout << "Data Invalida" << endl << endl;
                        return;
                }
                break;
        case 6:
                if((dia < 1) && (dia > 30)) {
                        cout << "Data Invalida" << endl << endl;
                        return;
                }
                break;
        case 7:
                if((dia < 1) && (dia > 31)) {
                        cout << "Data Invalida" << endl << endl;
                        return;
                }
                break;
        case 8:
                if((dia < 1) && (dia > 31)) {
                        cout << "Data Invalida" << endl << endl;
                        return;
                }
                break;
        case 9:
                if((dia < 1) && (dia > 30)) {
                        cout << "Data Invalida" << endl << endl;
                        return;
                }
                break;
        case 10:
                if((dia < 1) && (dia > 31)) {
                        cout << "Data Invalida" << endl << endl;
                        return;
                }
                break;
        case 11:
                if((dia < 1) && (dia > 30)) {
                        cout << "Data Invalida" << endl << endl;
                        return;
                }
                break;
        case 12:
                if((dia < 1) && (dia > 31)) {
                        cout << "Data Invalida" << endl << endl;
                        return;
                }
                break;
        }

        if(((0 > min) && (min > 60)) || ((0 > hora) && (hora > 23))) {
                cout << "Data Invalida" << endl << endl;
                return;
        }

        cout << "Data Alterada para : " << setw(2) << setfill('0') << dia << "/" << setw(2) << setfill('0') << mes << "/" << setw(4) << setfill('0') << ano << endl;
        cout << setw(2) << setfill('0') << fixed << hora << ":" << min;

        dataAtual.at(0) = dia;
        dataAtual.at(1) = mes;
        dataAtual.at(2) = ano;
        dataAtual.at(3) = hora;
        dataAtual.at(4) = min;
}

int Metro::DataDiff(vector<int> d1, vector<int> d2){
        int t1, t2, ano, mes, dia;
        switch(d1[1]) {
        case 1:
                mes = 31;
                break;
        case 2:
                mes = 59;
                break;
        case 3:
                mes = 90;
                break;
        case 4:
                mes = 120;
                break;
        case 5:
                mes = 151;
                break;
        case 6:
                mes = 181;
                break;
        case 7:
                mes = 212;
                break;
        case 8:
                mes = 243;
                break;
        case 9:
                mes = 273;
                break;
        case 10:
                mes = 304;
                break;
        case 11:
                mes = 334;
                break;
        case 12:
                mes = 365;
                break;
        }
        if(d1[0]%4 == 0) {
                ano = 366*d1[2];
                mes++;
        }
        else
                ano = 365*d1[2];
        dia = d1[0];
        t1 = ano + mes + dia;
        switch(d2[1]) {
        case 1:
                mes = 31;
                break;
        case 2:
                mes = 59;
                break;
        case 3:
                mes = 90;
                break;
        case 4:
                mes = 120;
                break;
        case 5:
                mes = 151;
                break;
        case 6:
                mes = 181;
                break;
        case 7:
                mes = 212;
                break;
        case 8:
                mes = 243;
                break;
        case 9:
                mes = 273;
                break;
        case 10:
                mes = 304;
                break;
        case 11:
                mes = 334;
                break;
        case 12:
                mes = 365;
                break;
        }
        if(d2[0]%4 == 0) {
                ano = 366*d2[2];
                mes++;
        }
        else
                ano = 365*d2[2];
        dia = d2[0];
        t2 = ano + mes + dia;
        t1 = t1*24*60 + d1[3]*60 + d1[4];
        t2 = t2*24*60 + d2[3]*60 + d2[4];
        return abs(t1-t2);
}

void Metro::alterarLocal()
{
        int i;

        do {
                Locais();

                cout << "Insira o número do local desejado:" << endl << endl;
                cin >> i;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("clear");
        } while (i < 1 || i > 16);

        local.defineLocal(i);
}

string Metro::localAtual()
{
        pontoVenda *P = local.getLocalAtual();

        if (P != NULL)
        {
                return P->getNome();
        }
        return "Trindade";
}

void Metro::addFuncionario(){
        char control;
        string nm, lv, fc;
        float sal;
        cout << "Nome : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, nm);
        system("clear");
        alterarLocal();
        cout << "Salario : ";
        cin >> sal;
        system("clear");
        cout << "Função : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, fc);

        Funcionario fNotFound("",-1,"",0,"");

        int id = 0, copy = -1;

        while(copy != id) {
                copy = id;
                BSTItrIn<Funcionario> it(funcionarios);
                while(!it.isAtEnd()) {
                        if(it.retrieve().getId() == id) {
                                id++;
                        }
                        it.advance();
                }
        }


        Funcionario f(nm, id, localAtual(), sal, fc);

        cout << endl << f.getInformacao() << endl << endl;

        do {
                cout << "Deseja Confirmar a Operacao ? (s/n)" << endl;
                cin >> control;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("clear");

                if (control == 'n')
                {
                        cout << "Operação Cancelada" << endl;
                        return;
                }
        } while (control != 's');

        Funcionario fTry = funcionarios.find(f);
        if(fTry == fNotFound) {
                funcionarios.insert(f);
                cout << "Operação Efetuada" << endl << endl;
        }
        else {
                cout << "Funcionário ja existe" << endl << endl;
        }
}

void Metro::removeFuncionario(){
        char control;
        int id;
        cout << "Identificacao : ";
        cin >> id;
        system("clear");

        Funcionario f("",id,"",-1,"");
        Funcionario *fTry;

        BSTItrIn<Funcionario> it(funcionarios);

        while(!it.isAtEnd()) {
                if(it.retrieve() == f) {

                        cout << it.retrieve().getInformacao() << endl;

                        do {
                                cout << "Deseja Confirmar a Operacao ? (s/n)" << endl << endl;
                                cin >> control;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                system("clear");

                                if (control == 'n')
                                {
                                        cout << "Operação Cancelada" << endl;
                                        return;
                                }
                        } while (control != 's');

                        funcionarios.remove(it.retrieve());
                        cout << "Funcionário removido" << endl << endl;
                        return;
                }
                it.advance();
        }

        cout << "Funcionario nao existe" << endl << endl;
}

void Metro::dadosFuncionario(){
        BSTItrIn<Funcionario> it(funcionarios);
        while(!it.isAtEnd()) {
                cout << it.retrieve().getInfo() << endl;
                it.advance();
        }
}

void Metro::dadoFuncionario(){
        int id;
        cout << "Identificacao : ";
        cin >> id;
        system("clear");

        Funcionario f("",id,"",0,"");

        BSTItrIn<Funcionario> it(funcionarios);

        while(!it.isAtEnd()) {
                if(it.retrieve() == f) {

                        cout << it.retrieve().getInformacao() << endl;
                        return;
                }
                it.advance();
        }

        cout << "Funcionario nao existe" << endl << endl;
}

void Metro::SalarioFuncionario(){
        int id;
        float newS;
        cout << "Identificacao : ";
        cin >> id;
        system("clear");

        Funcionario f("",id,"",0,"");
        Funcionario *FS;

        BSTItrIn<Funcionario> it(funcionarios);

        while(!it.isAtEnd()) {
                if(it.retrieve() == f) {

                        cout << it.retrieve().getInformacao() << endl;
                        cout << "Salario Novo : ";
                        cin >> newS;
                        system("clear");
                        FS = new Funcionario(it.retrieve());
                        FS->setSalario(newS);
                        funcionarios.remove(it.retrieve());
                        funcionarios.insert(*FS);
                        return;
                }
                it.advance();
        }

        cout << "Funcionario nao existe" << endl << endl;
}
