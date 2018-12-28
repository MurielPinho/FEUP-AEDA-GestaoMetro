#include "Metro.h"

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
                dataAtual.push_back(dia);
                dataAtual.push_back(mes);
                dataAtual.push_back(ano);
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
        ofstream out, tm;

        out.open("Funcionarios.txt");
        tm.open("Data.txt");
        BSTItrIn<Funcionario> it(funcionarios);
        while(!it.isAtEnd()) {
                out << it.retrieve().getInfo() << endl;
                it.advance();
        }
        tm << setw(2) << setfill('0') << dataAtual[0] << "/" << setw(2) << setfill('0') << dataAtual[1] << "/" << setw(4) << setfill('0') << dataAtual[2];
        out.close();
        tm.close();
}

void Metro::Locais()
{
        cout << "Locais de Venda :" << endl << endl;
        cout << local.getLocais() <<  endl;
}

void Metro::alterarData()
{
        int dia, mes, ano;
        cout << "Dia : ";
        cin >> dia;
        cout << "Mes : ";
        cin >> mes;
        cout << "Ano : ";
        cin >> ano;
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

        cout << "Data Alterada para : " << setw(2) << setfill('0') << dia << "/" << setw(2) << setfill('0') << mes << "/" << setw(4) << setfill('0') << ano << endl << endl;

        dataAtual.at(0) = dia;
        dataAtual.at(1) = mes;
        dataAtual.at(2) = ano;
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
