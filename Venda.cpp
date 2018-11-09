#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

#include "Bilhete.h"
#include "Utentes.h"
#include "Local.h"

using namespace std;

void     comprarBilhete();
void     comprarMaquina();
void     comprarLoja();
Bilhete* FOcasional();
Bilhete* FAssinatura();
float    precos(int Z, int D);
bool     Pagamento(float preco);
int      numBilhetes(bool A);
void     dadosBilhete();
void     readFile();
void     writeFile();
void     AlterarLocal();
string   LocalAtual();
void     Locais();


Utentes u;
Local   l;

void comprarBilhete()
{
  Pontovenda *P = l.getLocalAtual();
  bool tipo;

  if (P != NULL)
  {
    tipo = P->getTipo();

    if (tipo)
    {
      comprarLoja();
    }
    else
    {
      comprarMaquina();
    }
  }
}

void comprarMaquina()
{
  Bilhete *B;

  B = FOcasional();


  if (Pagamento(B->getPreco()))
  {
    u.adicionaOcasional(B);
    cout << "Pagamento concluido" << endl << endl;
  }
}

void comprarLoja()
{
  Bilhete *B = NULL;
  int i;

  cout << "Comprar bilhete ocasional ou renovar assinatura ?" << endl << endl;
  cout << "1 - Ocasional" << endl;
  cout << "2 - Assinatura\n" << endl;
  cin >> i;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  system("clear");

  if (i == 1) {
    B = FOcasional();
  }
  else  {
    B =  FAssinatura();
  }

  if (Pagamento(B->getPreco()))
  {
    if (B->getTipo()) {
      u.adicionaOcasional(B);
    }
    else {
      u.adicionaAssinatura(B);
    }

    cout << "Pagamento concluido" << endl << endl;
  }
}

bool Pagamento(float preco)
{
  char control;

  do {
    cout << "Deseja realizar o pagamento ? (s/n)" << endl << endl;
    cout << setprecision(2) << fixed << "Valor: " << preco << " euros" << endl << endl;

    cin >> control;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("clear");

    if (control == 'n')
    {
      return false;
    }
  } while (control != 's');
  return true;
}

Bilhete* FOcasional()
{
  Bilhete *B1;
  int i, Z;

  cout << "Titulo unico ou diario ?" << endl << endl;
  cout << "1 - Unico" << endl;
  cout << "2 - Diario" << endl;
  cin >> i;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  system("clear");
  cout << "Tipo de bilhete: \n\n2 - Z2 \n3 - Z3 \n4 - Z4\n" << endl;
  cin >> Z;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  system("clear");

  switch (i) {
  case 1:

    B1 = new Unico(u.numOcasionais() + 1, Z, precos(Z, 1), 1, 2, LocalAtual(), 1, false);
    break;

  case 2:
    B1 = new Diario(u.numOcasionais() + 1, Z, precos(Z, 2), 1, 24, LocalAtual(), 1, false);
    break;
  }
  return B1;
}

Bilhete* FAssinatura()
{
  Bilhete *B = NULL;

  int i, cc, id, Z;
  string nm, esc;

  cout << "Tipo de bilhete:" << endl << endl;
  cout << "1 - Normal" << endl;
  cout << "2 - Estudante" << endl;
  cout << "3 - Junior" << endl;
  cout << "4 - Senior" << endl;
  cin >> i;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  system("clear");
  cout << "Tipo de bilhete: \n\n2 - Z2 \n3 - Z3 \n4 - Z4\n" << endl;
  cin >> Z;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  system("clear");
  cout << "Digite o seu nome" << endl;
  getline(cin, nm);
  system("clear");

  if (i == 1) {
    B = new Normal(u.numAssinaturas() + 1, Z, precos(Z, 0), 0, nm, 0);
  }
  else if ((i > 1) & (i <= 4)) {
    cout << "Digite o numero do cartao de cidadao" << endl;
    cin >> cc;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("clear");
    cout << "Digite sua idade" << endl;
    cin >> id;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("clear");

    switch (i) {
    case 2:
      cout << "Nome da sua escola" << endl;
      cin >> esc;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      system("clear");
      B = new Estudante(u.numAssinaturas() + 1, Z, precos(Z, 0) * 0.75, 0, nm, 1, id, cc, esc);
      break;

    case 3:
      B = new Junior(u.numAssinaturas() + 1, Z, precos(Z, 0) * 0.75, 0, nm, 2, id, cc);
      break;

    case 4:
      B = new Senior(u.numAssinaturas() + 1, Z, precos(Z, 0) * 0.75, 0, nm, 3, id, cc);
      break;
    }
  }
  return B;
}

void Bilhetes()
{
  cout << "Ocasionais :" << endl << endl;
  cout << u.getOcasionais() <<  endl;
  cout << "Assinaturas :" << endl << endl;
  cout << u.getAssinaturas() <<  endl;
}

void dadosBilhete()
{
  int i, j;

  cout << "Escolha o tipo de bilhete" << endl;
  cout << "1 - Ocasional" << endl;
  cout << "2 - Assinatura\n" << endl;
  cin >> i;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << endl;

  if (i == 1)
  {
    cout << "Insira o numero do bilhete" << endl;
    cin >> j;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;

    Bilhete *B = u.getOcasional(j);

    if (B == NULL)
    {
      cout << "Ocasional não existe" << endl;
    }
    else {
      cout << B->getInformacao() << endl << endl;
    }
  }
  else {
    cout << "Insira o numero do bilhete" << endl;
    cin >> j;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;

    Bilhete *B = u.getAssinatura(j);

    if (B == NULL)
    {
      cout << "Assinatura não existe" << endl;
    }
    else {
      cout << B->getInformacao() << endl << endl;
    }
  }
}

void readFile()
{
  ifstream bilhetes, locais;
  Bilhete *B;
  Pontovenda *P;

  bilhetes.open("Bilhetes.txt", ios_base::in);
  locais.open("Locais.txt", ios_base::in);

  if (!bilhetes)
  {
    cerr << "Arquivo não encontrado!\n";
  }
  else
  {
    string line;
    vector<string> word;

    while (getline(bilhetes, line))
    {
      stringstream linestream(line);
      string value;
      vector<string> data;

      while (getline(linestream, value, ','))
      {
        data.push_back(value);
      }
      float  preco;
      string tipo, nome;
      int    identificacao, zona;
      tipo          = data.at(0);
      identificacao = stoi(data.at(1));
      zona          = stoi(data.at(2));
      preco         = stof(data.at(3));

      if (tipo == "Unico")
      {
        int d, v;
        string pt;
        bool   t, vdd;
        t   = 1;
        d   = stoi(data.at(5));
        pt  = data.at(6);
        v   = stoi(data.at(7));
        vdd = 0;
        B   = new Unico(identificacao, zona, preco, t, d, pt, v, vdd);
        u.adicionaOcasional(B);
      }
      else if (tipo == "Diario")
      {
        int d, v;
        string pt;
        bool   t, vdd;
        t   = 1;
        d   = stoi(data.at(5));
        pt  = data.at(6);
        v   = stoi(data.at(7));
        vdd = 0;
        B   = new Diario(identificacao, zona, preco, t, d, pt, v, vdd);
        u.adicionaOcasional(B);
      }
      else if (tipo == "Normal")
      {
        int    d;
        bool   t;
        string n;
        t = 0;
        n = data.at(5);
        d = stoi(data.at(6));
        B = new Normal(identificacao, zona, preco, t,  n, d);
        u.adicionaAssinatura(B);
      }
      else if (tipo == "Estudante")
      {
        int    idd, cc, d;
        bool   t;
        string n, esc;
        t   = 0;
        n   = data.at(5);
        d   = stoi(data.at(6));
        idd = stoi(data.at(7));
        cc  = stoi(data.at(8));
        esc = data.at(9);
        B   = new Estudante(identificacao, zona, preco, t, n, d, idd, cc, esc);
        u.adicionaAssinatura(B);
      }
      else if (tipo == "Junior")
      {
        int    idd, cc, d;
        bool   t;
        string n;
        t   = 0;
        n   = data.at(5);
        d   = stoi(data.at(6));
        idd = stoi(data.at(7));
        cc  = stoi(data.at(8));
        B   = new Junior(identificacao, zona, preco, t,  n, d, idd, cc);
        u.adicionaAssinatura(B);
      }
      else if (tipo == "Senior")
      {
        int    idd, cc, d;
        bool   t;
        string n;
        t   = 0;
        n   = data.at(5);
        d   = stoi(data.at(6));
        idd = stoi(data.at(7));
        cc  = stoi(data.at(8));
        B   = new Senior(identificacao, zona, preco, t,  n, d, idd, cc);
        u.adicionaAssinatura(B);
      }

      {
        // for (string line; getline(bilhetes, line);)
        // {
        //   istringstream in(line);
        //   string tipo;
        //   in >> tipo;
        //
        //   if (tipo == "Unico")
        //   {
        //     int    id, d, v, z;
        //     float  p;
        //     string pt;
        //     bool   t, vdd;
        //     in >> id >> z >> p  >> t  >> d >> pt  >> v >> vdd;
        //     B = new Unico(id, z, p, t, d, pt, v, vdd);
        //     u.adicionaOcasional(B);
        //   }
        //   else if (tipo == "Diario")
        //   {
        //     int    id, d, v, z;
        //     float  p;
        //     string pt;
        //     bool   t, vdd;
        //     in >> id  >> z >> p  >> t  >> d >> pt >> v >> vdd;
        //     B = new Diario(id, z, p, t, d, pt, v, vdd);
        //     u.adicionaOcasional(B);
        //   }
        //   else if (tipo == "Normal")
        //   {
        //     int    id, z, d;
        //     float  p;
        //     bool   t;
        //     string n;
        //     in >> id  >> z >> p  >> t  >> n >> d;
        //     B = new Normal(id, z, p, t,  n, d);
        //     u.adicionaAssinatura(B);
        //   }
        //   else if (tipo == "Estudante")
        //   {
        //     int    id, idd, cc, z, d;
        //     float  p;
        //     bool   t;
        //     string n, esc;
        //     in >> id  >> z >> p  >> t  >> n  >> d >> idd  >> cc  >> esc;
        //     B = new Estudante(id, z, p, t, n, d, idd, cc, esc);
        //     u.adicionaAssinatura(B);
        //   }
        //   else if (tipo == "Junior")
        //   {
        //     int    id, idd, cc, z, d;
        //     float  p;
        //     bool   t;
        //     string n;
        //     in >> id  >> z >> p  >> t  >> n  >> d >> idd  >> cc;
        //     B = new Junior(id, z, p, t,  n, d, idd, cc);
        //     u.adicionaAssinatura(B);
        //   }
        //   else if (tipo == "Senior")
        //   {
        //     int    id, idd, cc, z, d;
        //     float  p;
        //     bool   t;
        //     string n;
        //     in >> id  >> z >> p  >> t  >> n  >> d >> idd  >> cc;
        //     B = new Senior(id, z, p, t,  n, d, idd, cc);
        //     u.adicionaAssinatura(B);
        //   }
      }
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
      int    identificacao;
      tipo          = word.at(0);
      identificacao = stoi(word.at(1));
      nome          = word.at(2);

      if (tipo == "Maquina")
      {
        cout << "maquina criada" << endl;
        P = new Maquina(identificacao, nome, 0);
        l.adicionaLocal(P);
      }
      else if (tipo == "Loja") {
        P = new Loja(identificacao, nome, 1);
        l.adicionaLocal(P);
      }
    }

    l.defineLocal(1);
  }
  bilhetes.close();
  locais.close();
}

void writeFile()
{
  ofstream out;

  out.open("Bilhetes.txt");
  int numO = u.numOcasionais();
  int numA = u.numAssinaturas();

  for (int i = 1; i <= numO; i++)
  {
    Bilhete *B = u.getOcasional(i);
    out << B->getInformacao() << endl;
  }

  for (int i = 1; i <= numA; i++)
  {
    Bilhete *B = u.getAssinatura(i);
    out << B->getInformacao() << endl;
  }
}

float precos(int Z, int D)
{
  if (D == 0) {
    switch (Z) {
    case 2:
      return 30.60f;

    case 3:
      return 37.75f;

    case 4:
      return 48.05f;
    }
  } else if (D == 1) {
    switch (Z) {
    case 2:
      return 1.2f;

    case 3:
      return 1.6f;

    case 4:
      return 2.0f;
    }
  } else if (D == 2)  {
    switch (Z) {
    case 2:
      return 4.15f;

    case 3:
      return 5.50f;

    case 4:
      return 6.90f;
    }
  }

  return 0.00f;
}

void Locais()
{
  cout << "Locais de venda :" << endl << endl;
  cout << l.getLocais() <<  endl;
}

void AlterarLocal()
{
  int i;

  cout << "Insira o numero do local desejado:" << endl << endl;
  cin >> i;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');


  l.defineLocal(i);
  system("clear");
}

string LocalAtual()
{
  Pontovenda *P = l.getLocalAtual();

  if (P != NULL)
  {
    return P->getNome();
  }
  return "Trindade";
}
