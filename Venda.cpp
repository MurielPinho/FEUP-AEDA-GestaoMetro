#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>


#include "Precos.cpp"
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
int      numBilhetes();
Utentes u;

int      Maquina()
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

    B1 = new Unico(precosU(Z), 1, 2, 1);
    break;

  case 2:
    B1 = new Diario(precosD(Z), 1, 24, 1);
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
    B = new Normal(precosA(Z), 0, nm);
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
      B = new Estudante(precosA(Z) * 0.75, 0, nm, id, cc, esc);
      break;

    case 3:
      B = new Junior(precosA(Z) * 0.75, 0, nm, id, cc);
      break;

    case 4:
      B = new Senior(precosA(Z) * 0.75, 0, nm, id, cc);
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

int numBilhetes()
{
  int Num;
  ifstream infile;
  ofstream outfile;
  string   file4write, strNum;
  ostringstream BilNum;


  infile.open("NumBilhetes.txt");

  if (infile.fail())
  {
    cerr << "Erro ao abrir arquivo" << endl;
    exit(1);
  }
  getline(infile, strNum);
  Num = stoi(strNum);
  Num++;
  outfile.open("NumBilhetes.txt");

  // BilNum << "O";
  // BilNum << setfill('0') << setw(3) << to_string(Num) << ".txt";
  outfile << Num << endl;


  outfile.close();
  return Num;
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
