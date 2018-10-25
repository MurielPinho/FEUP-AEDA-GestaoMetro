#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

#include "Bilhete.h"
#include "Utentes.h"
#include "Menu.h"

using namespace std;

int      Maquina();
int      Loja();
Bilhete* FOcasional();
Bilhete* FAssinatura();
float    precosA(int Z);
float    precosU(int Z);
float    precosD(int Z);
bool     Pagamento(float preco);
int      numBilhetes(bool A);
void     test();
void     read();
void     write();


Utentes u;

int Maquina()
{
  Bilhete *B;

  B = FOcasional();


  if (Pagamento(B->getPreco()))
  {
    u.adicionaOcasional(B);
    cout << "Pagamento concluido" << endl << endl;
  }

  return 0;
}

int Loja()
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

  return 0;
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

    B1 = new Unico(u.numOcasionais() + 1, precosU(Z), 1, 2, "Trindade", 1, false);
    break;

  case 2:
    B1 = new Diario(u.numOcasionais() + 1, precosD(Z), 1, 24, "Trindade", 1, false);
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
  cin >> nm;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  system("clear");

  if (i == 1) {
    B = new Normal(u.numAssinaturas() + 1, precosA(Z), 0, nm);
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
      B = new Estudante(u.numAssinaturas() + 1, precosA(Z) * 0.75, 0, nm, id, cc, esc);
      break;

    case 3:
      B = new Junior(u.numAssinaturas() + 1, precosA(Z) * 0.75, 0, nm, id, cc);
      break;

    case 4:
      B = new Senior(u.numAssinaturas() + 1, precosA(Z) * 0.75, 0, nm, id, cc);
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

void test()
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

void read()
{
  ifstream source;
  Bilhete *B;

  source.open("Bilhetes.txt", ios_base::in);

  if (!source)
  {
    cerr << "Can't open Data!\n";
  }
  else
  {
    for (string line; getline(source, line);)
    {
      istringstream in(line);
      string tipo;
      in >> tipo;
      cout << tipo << endl;

      if (tipo == "Unico")
      {
        int    id, d, v;
        float  p;
        string pt;
        bool   t, vdd;
        in >> id  >> p  >> t  >> d >> pt  >> v >> vdd;
        B = new Unico(id, p, t, d, pt, v, vdd);
        u.adicionaOcasional(B);
      }
      else if (tipo == "Diario")
      {
        int    id, d, v;
        float  p;
        string pt;
        bool   t, vdd;
        in >> id  >> p  >> t  >> d >> pt >> v >> vdd;
        B = new Diario(id, p, t, d, pt, v, vdd);
        u.adicionaOcasional(B);
      }
      else if (tipo == "Normal")
      {
        int    id;
        float  p;
        bool   t;
        string n;
        in >> id  >> p  >> t  >> n;
        B = new Normal(id, p, t,  n);
        u.adicionaAssinatura(B);
      }
      else if (tipo == "Estudante")
      {
        int    id, idd, cc;
        float  p;
        bool   t;
        string n, esc;
        in >> id  >> p  >> t  >> n  >> idd  >> cc  >> esc;
        B = new Estudante(id, p, t, n, idd, cc, esc);
        u.adicionaAssinatura(B);
      }
      else if (tipo == "Junior")
      {
        int    id, idd, cc;
        float  p;
        bool   t;
        string n;
        in >> id  >> p  >> t  >> n  >> idd  >> cc;
        B = new Junior(id, p, t,  n, idd, cc);
        u.adicionaAssinatura(B);
      }
      else if (tipo == "Senior")
      {
        int    id, idd, cc;
        float  p;
        bool   t;
        string n;
        in >> id  >> p  >> t  >> n  >> idd  >> cc;
        B = new Senior(id, p, t,  n, idd, cc);
        u.adicionaAssinatura(B);
      }
    }
  }
}

void write()
{
  ofstream out;

  out.open("Bilhetes.txt");
  int numO = u.numOcasionais();
  int numA = u.numAssinaturas();

  for (int i = 1; i <= numO; i++)
  {
    Bilhete *B = u.getOcasional(i);

    if (B->getDuracao() == 2) {
      out << B->getInformacao() << endl;
    } else {
      out << B->getInformacao() << endl;
    }
  }

  for (int i = 1; i <= numA; i++)
  {
    Bilhete *B = u.getAssinatura(i);
    out << B->getInformacao() << endl;
  }
}

float precosA(int Z)
{
  switch (Z) {
  case 2:
    return Assinatura_Z2;

  case 3:
    return Assinatura_Z3;

  case 4:
    return Assinatura_Z4;
  }
  return 0.00f;
}

float precosU(int Z)
{
  switch (Z) {
  case 2:
    return Unico_Z2;

  case 3:
    return Unico_Z3;

  case 4:
    return Unico_Z4;
  }
  return 0.00f;
}

float precosD(int Z)
{
  switch (Z) {
  case 2:
    return Diario_Z2;

  case 3:
    return Diario_Z3;

  case 4:
    return Diario_Z4;
  }
  return 0.00f;
}
