#include "Local.h"
#include <ctime>
#include <time.h>
#include <unordered_set>

using namespace std;

// ! Membro normal.

/*!
   Funcao de igualdade da tabela de dispersao.
   \return Booleano da comparacao de duas assinaturas.
 */
struct strEq {
  bool operator()(const Assinatura& b1, const Assinatura& b2) const {
    return b1.getIdentificacao() == b2.getIdentificacao();
  }
};

// ! Membro normal.

/*!
   Funcao hash da tabela de dispersao.
   \return Int com a posicao onde o dado deve ser inserido na tabela de dispersao.
 */
struct strHash {
  int operator()(const Assinatura& b1) const {
    int h1 = hash<int>{} (b1.getIdentificacao());

    return h1;
  }
};

typedef unordered_set<Assinatura, strHash, strEq> TabH;

TabH AssInativas;
Utentes u;
Local   l;
time_t  dataAt;

void Venda::comprarBilhete()
{
  pontoVenda *P = l.getLocalAtual();
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

void Venda::comprarMaquina()
{
  Bilhete *B;

  B = criarOcasional();


  if (Pagamento(B->getPreco()))
  {
    u.adicionaOcasional(B);
    u.OrdenarOcasional();
    cout << "Pagamento concluido" << endl << endl;
  }
}

void Venda::comprarLoja()
{
  Bilhete *B = NULL;
  int i;

  cout << "Comprar bilhete ocasional ou assinatura ?" << endl << endl;
  cout << "1 - Ocasional" << endl;
  cout << "2 - Assinatura\n" << endl;
  cin >> i;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  system("clear");

  if (i == 1) {
    B = criarOcasional();
  }
  else  {
    B =  criarAssinatura();
  }

  if (Pagamento(B->getPreco()))
  {
    if (B->getTipo()) {
      u.adicionaOcasional(B);
      u.OrdenarOcasional();
    }
    else {
      u.adicionaAssinatura(B);
      u.OrdenarAssinatura();
    }

    cout << "Pagamento concluido" << endl << endl;
  }
}

bool Venda::Pagamento(float preco)
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

Bilhete * Venda::criarOcasional()
{
  Bilhete *B1;
  int i, Z, id, v;

  do {
    cout << "Titulo unico ou diario ?" << endl << endl;
    cout << "1 - Unico" << endl;
    cout << "2 - Diario" << endl;
    cin >> i;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("clear");
  } while (i != 1 && i != 2);

  do {
    cout << "Tipo de bilhete: \n\n2 - Z2 \n3 - Z3 \n4 - Z4\n" << endl;
    cin >> Z;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("clear");
  } while (Z < 2 || Z > 4);

  do {
    cout << "Numero de viagens ?" << endl;
    cin >> v;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("clear");
  } while (v <= 0);

  for (int i = 1; i <= u.numOcasionais() + 1; i++)
  {
    if (u.getOcasional(i) == NULL)
    {
      id = i;
      break;
    }
  }


  switch (i)
  {
  case 1:

    B1 = new Unico(id, Z, precos(Z, 1) * v, 1, time(&dataAt), 2, localAtual(), v, false);
    break;

  case 2:
    B1 = new Diario(id, Z, precos(Z, 2) * v, 1, time(&dataAt), 24, localAtual(), v, false);
    break;
  }
  return B1;
}

Bilhete * Venda::criarAssinatura()
{
  Bilhete *B = NULL;

  int i, cc, id, idd, Z;
  string nm, esc;


  do {
    cout << "Tipo de bilhete:" << endl << endl;
    cout << "1 - Normal" << endl;
    cout << "2 - Estudante" << endl;
    cout << "3 - Junior" << endl;
    cout << "4 - Senior" << endl;
    cin >> i;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("clear");
  } while (i < 1 || i > 4);

  do {
    cout << "Tipo de bilhete: \n\n2 - Z2 \n3 - Z3 \n4 - Z4\n" << endl;
    cin >> Z;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("clear");
  } while (Z < 2 || Z > 4);

  cout << "Digite o seu nome" << endl;
  getline(cin, nm);
  system("clear");

  for (int i = 1; i <= u.numAssinaturas() + 1; i++)
  {
    if (u.getAssinatura(i) == NULL)
    {
      id = i;
      break;
    }
  }

  if (i == 1) {
    B = new Normal(id, Z, precos(Z, 0), 0, time(&dataAt), nm, 0);
  }
  else if ((i >= 2) & (i <= 4)) {
    do {
      do
      {
        cout << "Digite o numero do cartao de cidadao (8 digitos)" << endl;
        cin >> cc;

        if (!cin.fail())
        {
          system("clear");
          break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("clear");
      } while (1);
    } while (cc <= 9999999 || cc > 99999999);

    if (i != 1)
    {
      do {
        do {
          cout << "Digite sua idade (3 digitos)" << endl;
          cin >> idd;

          if (!cin.fail())
          {
            system("clear");
            break;
          }
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          system("clear");
        } while (1);
      } while (idd <= 0 || idd > 199);
    }

    switch (i) {
    case 2:
      cout << "Nome da sua escola" << endl;
      cin >> esc;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      system("clear");
      B = new Estudante(id, Z, precos(Z, 0) * 0.75, 0, time(&dataAt), nm, 1, idd, cc, esc);
      break;

    case 3:
      B = new Junior(id, Z, precos(Z, 0) * 0.75, 0, time(&dataAt), nm, 2, idd, cc);
      break;

    case 4:
      B = new Senior(id, Z, precos(Z, 0) * 0.75, 0, time(&dataAt), nm, 3, idd, cc);
      break;
    }
  }
  return B;
}

void Venda::Bilhetes()
{
  cout << "Ocasionais :" << endl << endl;
  cout << "  Tipo | ID | Zona |" << endl;
  cout << u.getOcasionais() <<  endl;
  cout << "Assinaturas :" << endl << endl;
  cout << "   Tipo   | ID |     Nome     | Zona |" << endl;
  cout << u.getAssinaturas() <<  endl;
}

void Venda::renovarAss() {
  int i;

  cout << "Assinaturas:" << endl << endl;
  cout << "   Tipo   | ID |     Nome     | Zona |" << endl;
  cout << u.getAssinaturas() << endl;
  cout << "Insira o numero do bilhete" << endl;
  cin >> i;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  system("clear");
  Bilhete *B = u.getAssinatura(i);

  if (B == NULL)
  {
    cout << "Assinatura não existe" << endl;
  }

  B->Renovar();

  Assinatura *A = BilAss(*B);
  auto it       = AssInativas.find(*A);

  if (it == AssInativas.end()) return;

  AssInativas.erase(it);
}

void Venda::validar() {
  int i;

  cout << "Ocasionais:" << endl << endl;
  cout << "  Tipo | ID | Zona |" << endl;
  cout << u.getOcasionais() << endl;
  cout << "Insira o numero do bilhete" << endl;
  cin >> i;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  system("clear");
  Bilhete *B = u.getOcasional(i);

  if (B == NULL)
  {
    cout << "Bilhete não existe" << endl;
  }

  if (B->getViagens() != 0) {
    B->Validacao(true);
  }
}

void Venda::dadosBilhete()
{
  int i, j;

  do
  {
    cout << "Escolha o tipo de bilhete" << endl;
    cout << "1 - Ocasional" << endl;
    cout << "2 - Assinatura\n" << endl;
    cin >> i;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("clear");
  } while (i != 1 && i != 2);

  if (i == 1)
  {
    cout << "Ocasionais:" << endl << endl;
    cout << " Tipo  | ID | Zona |" << endl;
    cout << u.getOcasionais() << endl;
    cout << "Insira o numero do bilhete" << endl;
    cin >> j;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("clear");
    Bilhete *B = u.getOcasional(j);

    if (B == NULL)
    {
      cout << "Ocasional não existe" << endl;
    }
    else {
      int d = B->getDuracao();

      if (d == 2)      {
        cout << "   Tipo   | ID | Zonas | Preco | Viagens |" << endl;
      } else if (d == 24) {
        cout << "   Tipo   | ID | Zonas | Preco | Viagens |" << endl;
      }
      cout << B->getInformacaoTab() << endl << endl;
    }
  }
  else if (i == 2)
  {
    cout << "Assinaturas:" << endl << endl;
    cout << "   Tipo   | ID |     Nome     | Zona |" << endl;
    cout << u.getAssinaturas() << endl;
    cout << "Insira o numero do bilhete" << endl;
    cin >> j;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("clear");
    Bilhete *B = u.getAssinatura(j);

    if (B == NULL)
    {
      cout << "Assinatura não existe" << endl;
    }
    else {
      int d = B->getDesconto();

      if (d == 0)      {
        cout << "   Tipo   | ID | Zonas | Preco |     Nome     |" << endl;
      } else if (d == 1) {
        cout << "   Tipo   | ID | Zonas | Preco |     Nome     | Idade | Cartao Cidadao | Instituicao |" <<
          endl;
      } else if (d == 2) {
        cout << "   Tipo   | ID | Zonas | Preco |     Nome     | Idade | Cartao Cidadao |" << endl;
      } else if (d == 3) {
        cout << "   Tipo   | ID | Zonas | Preco |     Nome     | Idade | Cartao Cidadao |" << endl;
      }
      cout << B->getInformacaoTab() << endl << endl;
    }
  }
}

void Venda::readData()
{
  ifstream bilhetes, locais, tm;
  Bilhete *B;
  pontoVenda *P;

  time(&dataAt);
  u.Clean();

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
      time_t dt;
      tipo          = data.at(0);
      identificacao = stoi(data.at(1));
      zona          = stoi(data.at(2));
      preco         = stof(data.at(3));
      dt            = stoi(data.at(5));

      if (tipo == "Unico")
      {
        int v;
        v = stoi(data.at(8));
        bool vdd;
        vdd = stoi(data.at(9));

        if (vdd == true) {
          if (abs(difftime(dt, dataAt)) > 7200) {
            v--;
            vdd = false;
          }
        }

        if (v > 0) {
          int d;
          string pt;
          bool   t;
          t  = 1;
          d  = stoi(data.at(6));
          pt = data.at(7);
          B  = new Unico(identificacao, zona, preco, t, dt, d, pt, v, vdd);
          u.adicionaOcasional(B);
        }
      }
      else if (tipo == "Diario")
      {
        int v;
        v = stoi(data.at(8));
        bool vdd;
        vdd = stoi(data.at(9));

        if (vdd == true) {
          if (abs(difftime(dt, dataAt)) > 86400) {
            v--;
            vdd = false;
          }
        }

        if (v > 0) {
          int d;
          string pt;
          bool   t;
          t  = 1;
          d  = stoi(data.at(6));
          pt = data.at(7);
          B  = new Diario(identificacao, zona, preco, t, dt, d, pt, v, vdd);
          u.adicionaOcasional(B);
        }
      }
      else if (tipo == "Normal")
      {
        int    d;
        bool   t;
        string n;
        t = 0;
        n = data.at(6);
        d = stoi(data.at(7));
        B = new Normal(identificacao, zona, preco, t, dt, n, d);

        if (abs(difftime(dt, dataAt)) > 5256000) {
          Assinatura *A = BilAss(*B);
          AssInativas.insert(*A);
        }
        u.adicionaAssinatura(B);
      }
      else if (tipo == "Estudante")
      {
        int    idd, cc, d;
        bool   t;
        string n, esc;
        t   = 0;
        n   = data.at(6);
        d   = stoi(data.at(7));
        idd = stoi(data.at(8));
        cc  = stoi(data.at(9));
        esc = data.at(10);
        B   = new Estudante(identificacao, zona, preco, t, dt, n, d, idd, cc, esc);

        if (abs(difftime(dt, dataAt)) > 5256000) {
          Assinatura *A = BilAss(*B);
          AssInativas.insert(*A);
        }
        u.adicionaAssinatura(B);
      }
      else if (tipo == "Junior")
      {
        int    idd, cc, d;
        bool   t;
        string n;
        t   = 0;
        n   = data.at(6);
        d   = stoi(data.at(7));
        idd = stoi(data.at(8));
        cc  = stoi(data.at(9));
        B   = new Junior(identificacao, zona, preco, t, dt, n, d, idd, cc);

        if (abs(difftime(dt, dataAt)) > 5256000) {
          Assinatura *A = BilAss(*B);
          AssInativas.insert(*A);
        }
        u.adicionaAssinatura(B);
      }
      else if (tipo == "Senior")
      {
        int    idd, cc, d;
        bool   t;
        string n;
        t   = 0;
        n   = data.at(6);
        d   = stoi(data.at(7));
        idd = stoi(data.at(8));
        cc  = stoi(data.at(9));
        B   = new Senior(identificacao, zona, preco, t, dt, n, d, idd, cc);

        if (abs(difftime(dt, dataAt)) > 5256000) {
          Assinatura *A = BilAss(*B);
          AssInativas.insert(*A);
        }
        u.adicionaAssinatura(B);
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

void Venda::writeData()
{
  ofstream out, hash;

  hash.open("Hash.txt");
  out.open("Bilhetes.txt");
  int numO = u.numOcasionais();
  int numA = u.numAssinaturas();

  auto it = AssInativas.begin();

  while (it != AssInativas.end()) {
    hash << (*it).getInformacao() << endl;
    it++;
  }

  for (int i = 0; i < numO; i++)
  {
    Bilhete *B = u.getVecOcasional(i);
    int    v   = B->getViagens();
    bool   vdd = B->getValidade();
    time_t dt  = B->getData();

    if (B->getDuracao() == 2) {
      if ((abs(difftime(dt, dataAt)) > 7200) && (vdd = true)) {
        B->setViagens(v--);
        B->Validacao(false);
      }
    }
    else {
      if ((abs(difftime(dt, dataAt)) > 86400) && (vdd = true)) {
        B->setViagens(v--);
        B->Validacao(false);
      }
    }

    if (v > 0) {
      out << B->getInformacao() << endl;
    }
  }

  for (int i = 0; i < numA; i++)
  {
    Bilhete *B = u.getVecAssinatura(i);
    out << B->getInformacao() << endl;
  }
  out.close();
  hash.close();
}

float Venda::precos(int Z, int D)
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

void Venda::Locais()
{
  cout << "Locais de venda :" << endl << endl;
  cout << l.getLocais() <<  endl;
}

void Venda::alterarLocal()
{
  int i;

  do {
    Locais();

    cout << "Insira o numero do local desejado:" << endl << endl;
    cin >> i;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("clear");
  } while (i < 1 || i > 16);

  l.defineLocal(i);
}

string Venda::localAtual()
{
  pontoVenda *P = l.getLocalAtual();

  if (P != NULL)
  {
    return P->getNome();
  }
  return "Trindade";
}

void Venda::removeBilhete()
{
  int i, j;

  cout << "Escolha o tipo de bilhete" << endl;
  cout << "1 - Ocasional" << endl;
  cout << "2 - Assinatura\n" << endl;
  cin >> i;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << endl;
  system("clear");

  if (i == 1)
  {
    cout << "Ocasionais:" << endl << endl;
    cout << u.getOcasionais() << endl;
    cout << "Insira a identificacao do ocasional a ser removido:" << endl << endl;
  }
  else if (i == 2)
  {
    cout << "Assinaturas:" << endl << endl;
    cout << u.getAssinaturas() << endl;
    cout << "Insira a identificacao da assinatura a ser removida:" << endl << endl;
  }

  cin >> j;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  system("clear");

  if (i == 1)
  {
    if (u.removeOcasional(j))
    {
      cout << "Ocasional Removido" << endl << endl;
    }
    else
    {
      cout << "Ocasional nao encontrado" << endl << endl;
    }
  }
  else if (i == 2)
  {
    if (u.removeAssinatura(j))
    {
      cout << "Assinatura Removida" << endl << endl;
    }
    else
    {
      cout << "Assinatura nao encontrada" << endl << endl;
    }
  }
}

void Venda::AssinaturasInativas()
{
  auto it = AssInativas.begin();
  stringstream ss;
  int d = 0;

  cout << "Assinaturas inativas:" << endl << endl;
  cout << "   Tipo   | ID |     Nome     | Zona | Tempo Inativa" << endl;

  while (it != AssInativas.end()) {
    if ((*it).getDesconto() == 0)
    {
      ss << right << setw(10) << "Normal";
    }
    else if ((*it).getDesconto() == 1)
    {
      ss << right << setw(10) << "Estudante";
    }
    else if ((*it).getDesconto() == 2)
    {
      ss << right << setw(10) << "Junior";
    }
    else if ((*it).getDesconto() == 3)
    {
      ss << right << setw(10) << "Senior";
    }
    ss << " " << right << setw(4) << (*it).getIdentificacao();
    ss << "  " << left << setw(15) << (*it).getNome();
    ss << " Z" << left << setw(3) << (*it).getZona();
    d = abs(difftime((*it).getData(), time(&dataAt))) / 86400;
    ss << "  " << right << setw(5) << d << " dias";
    ss << "\n";
    cout << ss.str() << endl;
    it++;
  }
}

Assinatura * Venda::BilAss(const Bilhete& b1) const
{
  Assinatura *A = new Assinatura(b1.getIdentificacao(), b1.getZona(), b1.getPreco(), 0, b1.getData(), b1.getNome(), 1);

  return A;
}
