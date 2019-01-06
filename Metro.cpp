#include "Metro.h"
#include <ctime>
#include <time.h>

Local local;
time_t dataAtual;
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
        fs.open("Funcionarios.txt", ios_base::in);
        locais.open("Locais.txt", ios_base::in);


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
                        int ddif;
                        time_t dt;
                        tr = data.at(0);
                        if(stoi(data.at(1)) == 1)
                                av = true;
                        else
                                av = false;
                        tp = data.at(2);
                        dt = stoi(data.at(3));
                        ddif = difftime(dt,time(&dataAtual));
                        if(ddif < 0) {
                                tp = "Periodica";
                                av = false;
                                dt += 1209600;
                        }
                        M = new Manutencao(tr, tp, av, dt, difftime(dt,dataAtual));
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
        BSTItrIn<Funcionario> it(funcionarios);
        while(!it.isAtEnd()) {
                out << it.retrieve().getInfo() << endl;
                it.advance();
        }
        while(!Fila.empty()) {
                time_t dt = Fila.top().getData();
                int ddif = difftime(dt, time(&dataAtual));
                if(ddif < 0) {
                        dt += 1209600;
                        M = new Manutencao(Fila.top().getTrem(), "Periodica", 0, dt, difftime(dt,dataAtual));
                        cout << ctime(&dt) << endl;
                        mn << M->getInfo() << endl;
                        Fila.pop();
                }
                mn << Fila.top().getInfo() << endl;
                Fila.pop();
        }
        mn.close();
        out.close();
}

void Metro::Locais()
{
        cout << "Locais de Venda :" << endl << endl;
        cout << local.getLocais() <<  endl;
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
        string tp,inv;
        bool av, t=false,f=false;
        int dia, mes, ano, hora, min;
        char control;
        time_t mdt;
        priority_queue<Manutencao> temp;
        temp = Fila;
        struct tm *mdts;
        do{
        do {
          f=false;
          cout << f << endl;

                cout << "Trem : (A/Z) ";

                cin >> tr;
                cout << tr << endl;

        } while(!isalpha(tr));
        tr = toupper(tr);
        trem.str("");
        inv="";
        trem << tr;
        trem >> inv;
        while(!temp.empty())
              {
                if(temp.top().getTrem()==inv)
                {
                  system("clear");
                  cout << "Trem já existente" << endl;
                f=true;
                break;
                }
                temp.pop();
              }
        }while(f==true);
        tp = "Periodica";
        av = false;
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
do {
  system("clear");
        t = false;
        cout << "Dia : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> dia;
        cout << "Mes : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> mes;
        cout << "Ano : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> ano;
        cout << "Hora : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> hora;
        cout << "Minutos : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> min;


                if(ano < 0) {
                        t = true;

                }
                if((mes < 1) || (mes > 12)) {
                        t = true;

                }

                switch(mes) {
                case 1:
                        if((dia < 1) || (dia > 31)) {
                                t = true;
                        }
                        break;
                case 2:
                        if(ano%4 == 0) {
                                if((dia < 1) || (dia > 29)) {
                                        t = true;
                                }
                        }
                        else{
                                if((dia < 1) || (dia > 28)) {
                                        t = true;
                                }
                        }
                        break;
                case 3:
                        if((dia < 1) || (dia > 31)) {
                                t = true;
                        }
                        break;
                case 4:
                        if((dia < 1) || (dia > 30)) {
                                t = true;
                        }
                        break;
                case 5:
                        if((dia < 1) || (dia > 31)) {
                                t = true;
                        }
                        break;
                case 6:
                        if((dia < 1) || (dia > 30)) {
                                t = true;
                        }
                        break;
                case 7:
                        if((dia < 1) || (dia > 31)) {
                                t = true;
                        }
                        break;
                case 8:
                        if((dia < 1) || (dia > 31)) {
                                t = true;
                        }
                        break;
                case 9:
                        if((dia < 1) || (dia > 30)) {
                                t = true;
                        }
                        break;
                case 10:
                        if((dia < 1) || (dia > 31)) {
                                t = true;
                        }
                        break;
                case 11:
                        if((dia < 1) || (dia > 30)) {
                                t = true;
                        }
                        break;
                case 12:
                        if((dia < 1) || (dia > 31)) {
                                t = true;
                        }
                        break;
                }

                if(((0 > min) || (min > 60)) && ((0 > hora) || (hora > 23))) {
                        t = true;
                }
                if(t == true) {
                        cout << "Data Invalida" << endl << endl;
                }
        } while(t == true);
        system("clear");

        time ( &mdt );
        mdts = localtime ( &mdt );
        mdts->tm_mday = dia;
        mdts->tm_mon = mes-1;
        mdts->tm_year = ano-1900;
        mdts->tm_hour = hora;
        mdts->tm_min = min;
        mdt = mktime(mdts);
        cout << ctime(&mdt) << endl;
        Manutencao m(trem.str(), tp, av, mdt, (difftime(mdt,time(&dataAtual)))/86400);
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

        time_t dt = M.getData();
        int ddif = difftime(dt,time(&dataAtual));
        if(ddif >= 7)
                M.setData(dataAtual);
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
void Metro::test()
{
  cout << Fila.top().getData() << endl;
}
