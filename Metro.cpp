#include "Metro.h"

Local local;
vector<int> dataAtual;
priority_queue<Manutencao> Fila;

Metro::Metro() : funcionarios(Funcionario("",-1,"",0,"")){
}

void Metro::readData()
{
        ifstream locais, fs, tm, mn;
        Funcionario *F;
        pontoVenda *P;
        Manutencao *M;

        mn.open("Manutencao.txt", ios_base::in);
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
        if(!mn) {
                cerr << "Arquivo não encontrado!\n";
        }
        else {
                string line;

                while(getline(mn, line)) {
                        stringstream linestream(line);
                        string value;
                        vector<string> data;
                        while(getline(linestream,value,',')) {
                                data.push_back(value);
                        }
                        string tr, tp;
                        bool av;
                        int dia, mes, ano, hora, min, ddif;
                        vector<int> dt;
                        tr = data.at(0);
                        if(stoi(data.at(1)) == 1)
                                av = true;
                        else
                                av = false;
                        tp = data.at(2);
                        dia = stoi(data.at(3));
                        mes = stoi(data.at(4));
                        ano = stoi(data.at(5));
                        hora = stoi(data.at(6));
                        min = stoi(data.at(7));
                        dt.push_back(dia);
                        dt.push_back(mes);
                        dt.push_back(ano);
                        dt.push_back(hora);
                        dt.push_back(min);
                        int i = 14; //2 semanas;
                        ddif = DataDiff(dt,dataAtual);
                        if(ddif < 0) {
                                tp = "Periodica";
                                av = false;
                                ddif = abs(ddif);
                                while(i < ddif) {
                                        i += 14;
                                }
                                dt = {SomarTempo(dt,i)[0],SomarTempo(dt,i)[1],SomarTempo(dt,i)[2],SomarTempo(dt,i)[3],SomarTempo(dt,i)[4]};
                        }
                        M = new Manutencao(tr, tp, av, dt, DataDiff(dt,dataAtual));
                        Fila.push(*M);
                }
        }
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
        ofstream out, tm, mn;

        Manutencao *M;

        mn.open("Manutencao.txt");
        out.open("Funcionarios.txt");
        tm.open("Data.txt");
        BSTItrIn<Funcionario> it(funcionarios);
        while(!it.isAtEnd()) {
                out << it.retrieve().getInfo() << endl;
                it.advance();
        }
        tm << setw(2) << setfill('0') << dataAtual[0] << "/" << setw(2) << setfill('0') << dataAtual[1] << "/" << setw(4) << setfill('0') << dataAtual[2] << endl;
        tm << setw(2) << setfill('0') << dataAtual[3] << ":" << setw(2) << setfill('0') << dataAtual[4];
        while(!Fila.empty()) {
                vector<int> dt = Fila.top().getData();
                int ddif = DataDiff(dt, dataAtual), i = 14;
                if(ddif <= 0) {
                        ddif = abs(ddif);
                        while(i < ddif) {
                                i += 14;
                        }
                        dt = {SomarTempo(dt,i)[0],SomarTempo(dt,i)[1],SomarTempo(dt,i)[2],SomarTempo(dt,i)[3],SomarTempo(dt,i)[4]};
                        M = new Manutencao(Fila.top().getTrem(), "Periodica", 0, dt, DataDiff(dt,dataAtual));
                        mn << M->getInfo() << endl;
                        Fila.pop();
                }
                mn << Fila.top().getInfo() << endl;
                Fila.pop();
        }
        mn.close();
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

        cout << "Data Alterada para : " << setw(2) << setfill('0') << dia << "/" << setw(2) << setfill('0') << mes << "/" << setw(4) << setfill('0') << ano << " ";
        cout << setw(2) << setfill('0') << hora << ":"  << setw(2) << setfill('0') << min << endl << endl;

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
                mes = 0;
                break;
        case 2:
                mes = 31;
                break;
        case 3:
                mes = 59;
                break;
        case 4:
                mes = 90;
                break;
        case 5:
                mes = 120;
                break;
        case 6:
                mes = 151;
                break;
        case 7:
                mes = 181;
                break;
        case 8:
                mes = 212;
                break;
        case 9:
                mes = 243;
                break;
        case 10:
                mes = 273;
                break;
        case 11:
                mes = 304;
                break;
        case 12:
                mes = 334;
                break;
        }
        if(d1[2]%4 == 0) {
                ano = 366*d1[2];
                if(mes >= 59)
                        mes++;
        }
        else
                ano = 365*d1[2];
        dia = d1[0];
        t1 = ano + mes + dia;
        switch(d2[1]) {
        case 1:
                mes = 0;
                break;
        case 2:
                mes = 31;
                break;
        case 3:
                mes = 59;
                break;
        case 4:
                mes = 90;
                break;
        case 5:
                mes = 120;
                break;
        case 6:
                mes = 151;
                break;
        case 7:
                mes = 181;
                break;
        case 8:
                mes = 212;
                break;
        case 9:
                mes = 243;
                break;
        case 10:
                mes = 273;
                break;
        case 11:
                mes = 304;
                break;
        case 12:
                mes = 334;
                break;
        }
        if(d2[2]%4 == 0) {
                ano = 366*d2[2];
                if(mes >= 59)
                        mes++;
        }
        else
                ano = 365*d2[2];
        dia = d2[0];
        t2 = ano + mes + dia;
        return (t1-t2);
}


vector<int> Metro::SomarTempo(vector<int> d1, int i){
        vector<int> t;
        int ano, mes, dia;
        switch(d1[1]) {
        case 1:
                mes = 0;
                break;
        case 2:
                mes = 31;
                break;
        case 3:
                mes = 59;
                break;
        case 4:
                mes = 90;
                break;
        case 5:
                mes = 120;
                break;
        case 6:
                mes = 151;
                break;
        case 7:
                mes = 181;
                break;
        case 8:
                mes = 212;
                break;
        case 9:
                mes = 243;
                break;
        case 10:
                mes = 273;
                break;
        case 11:
                mes = 304;
                break;
        case 12:
                mes = 334;
                break;
        }
        ano = d1[2];
        dia = d1[0];
        i += mes + dia;
        if(ano%4 == 0) {
                while(i > 366) {
                        ano++;
                        i -= 366;
                }
        }
        while(i > 365) {
                ano++;
                i-= 365;
        }
        if (i == 0) {
                ano--;
                i = 365;
        }
        while(true) {
                mes = 31;
                if(i < mes) {
                        mes = 1;
                        break;
                }
                mes = 59;
                if(ano%4 == 0)
                        mes++;
                if(i < mes) {
                        i-=31;
                        mes = 2;
                        break;
                }
                mes = 90;
                if(ano%4 == 0) {
                        mes++;
                        i--;
                }
                if(i < mes) {
                        i-=59;
                        mes = 3;
                        break;
                }
                mes = 120;
                if(ano%4 == 0)
                        mes++;
                if(i < mes) {
                        i-= 90;
                        mes = 4;
                        break;
                }
                mes = 151;
                if(ano%4 == 0)
                        mes++;
                if(i < mes) {
                        i-= 120;
                        mes = 5;
                        break;
                }
                mes = 181;
                if(ano%4 == 0)
                        mes++;
                if(i < mes) {
                        i-= 151;
                        mes = 6;
                        break;
                }
                mes = 212;
                if(ano%4 == 0)
                        mes++;
                if(i < mes) {
                        i-= 181;
                        mes = 7;
                        break;
                }
                mes = 243;
                if(ano%4 == 0)
                        mes++;
                if(i < mes) {
                        i -= 212;
                        mes = 8;
                        break;
                }
                mes = 273;
                if(ano%4 == 0)
                        mes++;
                if(i < mes) {
                        i -= 243;
                        mes = 9;
                        break;
                }
                mes = 304;
                if(ano%4 == 0)
                        mes++;
                if(i < mes) {
                        i -= 273;
                        mes = 10;
                        break;
                }
                mes = 334;
                if(ano%4 == 0)
                        mes++;
                if(i < mes) {
                        i -= 304;
                        mes = 11;
                        break;
                }
                mes = 365;
                if(i <= mes) {
                        i -= 334;
                        mes = 12;
                        break;
                }
                break;
        }
        dia = i;
        t = {dia,mes,ano,d1[3],d1[4]};
        return t;
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

void Metro::AddManutencao(){
        char tr;
        stringstream trem;
        string tp;
        bool av;
        int dia, mes, ano, hora, min;
        char control;
        do {
                cout << "Trem : (A/Z) ";
                cin >> tr;
        } while(!isalpha(tr));
        tp = "Periodica";
        av = false;
        tr = toupper(tr);
        trem << tr;
        system("clear");
        do {
                cout << "Avaria Detectada ? (s/n) ";
                cin >> control;
                system("clear");

                if (control == 's')
                {
                        av = true;
                        cout << "Tipo de Avaria : ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        getline(cin, tp);
                        system("clear");
                        break;
                }
        } while (control != 'n');
        bool t = false;
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

        do {
                if(ano < 0) {
                        t == true;

                }
                if((mes < 1) && (mes > 12)) {
                        t == true;

                }

                switch(mes) {
                case 1:
                        if((dia < 1) && (dia > 31)) {
                                t == true;
                        }
                        break;
                case 2:
                        if(ano%4 == 0) {
                                if((dia < 1) && (dia > 29)) {
                                        t == true;
                                }
                        }
                        else{
                                if((dia < 1) && (dia > 28)) {
                                        t == true;
                                }
                        }
                        break;
                case 3:
                        if((dia < 1) && (dia > 31)) {
                                t == true;
                        }
                        break;
                case 4:
                        if((dia < 1) && (dia > 30)) {
                                t == true;
                        }
                        break;
                case 5:
                        if((dia < 1) && (dia > 31)) {
                                t == true;
                        }
                        break;
                case 6:
                        if((dia < 1) && (dia > 30)) {
                                t == true;
                        }
                        break;
                case 7:
                        if((dia < 1) && (dia > 31)) {
                                t == true;
                        }
                        break;
                case 8:
                        if((dia < 1) && (dia > 31)) {
                                t == true;
                        }
                        break;
                case 9:
                        if((dia < 1) && (dia > 30)) {
                                t == true;
                        }
                        break;
                case 10:
                        if((dia < 1) && (dia > 31)) {
                                t == true;
                        }
                        break;
                case 11:
                        if((dia < 1) && (dia > 30)) {
                                t == true;
                        }
                        break;
                case 12:
                        if((dia < 1) && (dia > 31)) {
                                t == true;
                        }
                        break;
                }

                if(((0 > min) && (min > 60)) || ((0 > hora) && (hora > 23))) {
                        t == true;
                }
                if(t == true) {
                        cout << "Data Invalida" << endl << endl;
                }
        } while(t == true);
        system("clear");
        vector<int> dt;
        dt.push_back(dia);
        dt.push_back(mes);
        dt.push_back(ano);
        dt.push_back(hora);
        dt.push_back(min);
        Manutencao m(trem.str(), tp, av, dt, DataDiff(dt,dataAtual));
        Fila.push(m);
}

void Metro::setAv(){
        char tr;
        stringstream trem;
        string tp;
        bool find = false;
        vector<Manutencao> copy;

        do {
                cout << "Trem : (A/Z) ";
                cin >> tr;
        } while(!isalpha(tr));
        tr = toupper(tr);
        trem << tr;

        system("clear");

        while(!Fila.empty()) {
                if(Fila.top().getTrem() == trem.str()) {
                        find = true;
                        break;
                }
                copy.push_back(Fila.top());
                Fila.pop();
        }
        if(find == false) {
                cout << "Trem não encontrado" << endl << endl;
                for(unsigned int i = 0; i < copy.size(); i++) {
                        Fila.push(copy[i]);
                }
                return;
        }

        Manutencao M = Fila.top();
        Fila.pop();

        for(unsigned int i = 0; i < copy.size(); i++) {
                Fila.push(copy[i]);
        }

        cout << "Tipo de Avaria : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, tp);
        system("clear");

        vector<int> dt = M.getData();
        dt = SomarTempo(dt, -10);
        M.setData(dt);
        M.setAvaria(true);
        M.setTipo(tp);

        Fila.push(M);
}

void Metro::PrintFila(){
        vector<Manutencao> copy;
        while(!Fila.empty()) {
                cout << Fila.top().getInformacao() << endl << endl;
                copy.push_back(Fila.top());
                Fila.pop();
        }
        for(unsigned int i = 0; i < copy.size(); i++) {
                Fila.push(copy[i]);
        }
}
