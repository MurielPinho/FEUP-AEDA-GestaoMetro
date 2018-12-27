#include "Metro.h"

Local local;

Metro::Metro() : funcionarios(Funcionario(0,"","","")){
}

void Metro::readData()
{
        ifstream locais, fs;
        Funcionario *F;
        pontoVenda *P;

        fs.open("Funcionarios.txt", ios_base::in);
        locais.open("Locais.txt", ios_base::in);

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
                        nome = data.at(0);
                        local = data.at(1);
                        salario = stof(data.at(2));
                        funcao = data.at(3);
                        F = new Funcionario(salario, local, nome, funcao);
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
}

void Metro::writeData()
{
        ofstream out;

        out.open("Funcionarios.txt");
        BSTItrIn<Funcionario> it(funcionarios);
        while(!it.isAtEnd()) {
                out << it.retrieve().getInfo() << endl;
                it.advance();
        }
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

        Funcionario f(sal, localAtual(), nm, fc);

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

        BSTItrIn<Funcionario> it(funcionarios);
        Funcionario fNotFound(0,"","","");
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
        string nm, lv;
        float sal;
        cout << "Nome : " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, nm);
        system("clear");
        cout << "Salario : " << endl;
        cin >> sal;

        Funcionario f(sal, "",nm, "");

        cout << endl << f.getName() << " " << f.getSalario() << endl;

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

        Funcionario fNotFound(0,"","","");
        Funcionario fTry = funcionarios.find(f);
        if(fTry == fNotFound) {
                cout << "Funcionario não existe" << endl << endl;
        }
        else {
                funcionarios.remove(f);
                cout << "Funcionário removido" << endl << endl;
        }
}

void Metro::dadosFuncionario(){
        BSTItrIn<Funcionario> it(funcionarios);
        while(!it.isAtEnd()) {
                cout << it.retrieve().getInfo() << endl;
                it.advance();
        }
}

void Metro::dadoFuncionario(){
        string nm;
        float sal;
        cout << "Nome : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, nm);
        system("clear");
        cout << "Salario : ";
        cin >> sal;
        system("clear");
        Funcionario f(sal, "", nm, "");
        Funcionario fNotFound(0,"","","");
        Funcionario fTry = funcionarios.find(f);
        if(fTry == fNotFound) {
                cout << "Funcionario não existe" << endl << endl;
        }
        else {
                cout << fTry.getInformacao() << endl;
        }
}
