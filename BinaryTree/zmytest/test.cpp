
#include "test.hpp"
#include <random>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

void Hub()
{
    while (true)
    {
      Menu();
    }
}
template<typename Data>
void MapPrint(const Data& dat, void* _)
{
  std::cout << dat << " ";
}

template <typename Data>
void Func(const Data& dat, const void* n, void* acc) noexcept
{
  if(dat < *((Data*)n))
  {
    *((Data*)acc) *= dat;
  }
}

template <typename Data>
void FuncFloat(const Data& dat, const void* n, void* acc) noexcept
{
  if(dat > *((Data*)n))
  {
    *((Data*)acc) += dat;
  }
}

template <typename Data>
float FuncSommaLnk(lasd::BinaryTreeLnk<Data>& b, float n)
{
  float acc = 0;
  b.FoldPreOrder(&FuncFloat<Data>, &n, &acc);
  return acc;
}

template <typename Data>
uint FuncMoltLnk(lasd::BinaryTreeLnk<Data>& b, uint n)
{
  uint acc = 1;
  b.FoldPreOrder(&Func<Data>, &n, &acc);
  if(acc == 1){return acc = 0;}else
  return acc;
}

template <typename Data>
float FuncSommaVec(lasd::BinaryTreeVec<Data>& b, float n)
{
  float acc = 1;
  b.FoldPreOrder(&Func<Data>, &n, &acc);
  if(acc == 1)
  {return 0;}else
  return acc;
}

template <typename Data>
uint FuncMoltVec(lasd::BinaryTreeVec<Data>& b, uint n)
{
  uint acc = 1;
  b.FoldPreOrder(&Func<Data>, &n, &acc);
  if(acc == 1){return acc = 0;}else
  return acc;
}

template<typename Data>
void StampaLink(lasd::BinaryTreeLnk<Data> b)
{
  uint visual;
  cout << "Che tipo di visualizzazione vuoi avere?" << '\n';
  cout << "1)Ampiezza" << '\n';
  cout << "2)Pre-Order" << '\n';
  cout << "3)Post-Order" << '\n';
  cout << "4)In Order" << '\n';
  cin>>visual;
  switch (visual) {
    case 1:
      b.MapBreadth(MapPrint<Data>, 0);
      break;
    case 2:
      b.MapPreOrder(MapPrint<Data>, 0);
      break;
    case 3:
      b.MapPostOrder(MapPrint<Data>, 0);
      break;
    case 4:
      b.MapInOrder(MapPrint<Data>, 0);
      break;
  }
  cout << '\n';
}

template<typename Data>
void StampaVec(lasd::BinaryTreeVec<Data> b)
{
  uint visual;
  cout << "Che tipo di visualizzazione vuoi avere?" << '\n';
  cout << "1)Ampiezza" << '\n';
  cout << "2)Pre-Order" << '\n';
  cout << "3)Post-Order" << '\n';
  cout << "4)In Order" << '\n';
  cin>>visual;
  switch (visual) {
    case 1:
      b.MapBreadth(MapPrint<Data>, 0);
      break;
    case 2:
      b.MapPreOrder(MapPrint<Data>, 0);
      break;
    case 3:
      b.MapPostOrder(MapPrint<Data>, 0);
      break;
    case 4:
      b.MapInOrder(MapPrint<Data>, 0);
      break;
  }
  cout << '\n';
}


template<typename Data>
void HubTreeLnk(lasd::BinaryTreeLnk<Data>& b)
{
  uint funcval, controllavalore, n;
  Data controllo;
  string controllostring;
  cout << "Cosa vuoi fare adesso?" << '\n';
  cout << "1)Stampa elementi" << '\n';
  cout << "2)Controllo Esistenza Valore" << '\n';
  cout << "3)Esegui funzione" << '\n';
  cin>>funcval;
  switch (funcval) {
    case 1:
      {
        StampaLink(b);
        HubTreeLnk(b);
      }
      break;
    case 2:
      {
        cout << "Inserisci il valore da controllare" << '\t';
        cin>>controllo;
        if(b.Exists(controllo))
        {
          cout << "Il valore esiste" << '\n';
        }else
          cout << "Il valore non esiste" << '\n';
          cout<< '\n';
        HubTreeLnk(b);
      }
      break;
    case 3:
      {
        if((typeid(Data))==typeid(int))
        {
          int acc=1;
          cout << "Inserisci un valore n" << '\n';
          cin>>n;
          acc = FuncMoltLnk(b, n);
          cout<< acc<< '\n';
          HubTreeLnk(b);
        }else
        {
          cout << "Inserisci un valore n" << '\n';
          cin>>n;
          float acc = FuncSommaLnk(b, n);
          cout<< acc<< '\n';
        }
      }
      break;
  }
}

template<typename Data>
void HubTreeLnkString(lasd::BinaryTreeLnk<Data>& b)
{
  uint funcval, controllavalore, n;
  double acc = 1;
  Data controllo;
  string controllostring;
  cout << "Cosa vuoi fare adesso?" << '\n';
  cout << "1)Stampa elementi" << '\n';
  cout << "2)Controllo Esistenza Valore" << '\n';
  cout << "3)Esegui funzione" << '\n';
  cin>>funcval;
  switch (funcval) {
    case 1:
      {
        StampaLink(b);
        HubTreeLnkString(b);
      }
      break;
    case 2:
      {
        cout << "Inserisci il valore da controllare" << '\t';
        cin>>controllo;
        if(b.Exists(controllo))
        {
          cout << "Il valore esiste" << '\n';
        }else
          cout << "Il valore non esiste" << '\n';
          cout<< '\n';
        HubTreeLnkString(b);
      }
      break;
    case 3:
      {
      }
      break;
    }
  }


template<typename Data>
void HubTreeVec(lasd::BinaryTreeVec<Data>& b)
{
  uint funcval, controllavalore, n, acc = 0;
  Data controllo;
  string controllostring;
  cout << "Cosa vuoi fare adesso?" << '\n';
  cout << "1)Stampa elementi" << '\n';
  cout << "2)Controllo Esistenza Valore" << '\n';
  cout << "3)Esegui una funzione" << '\n';
  cin>>funcval;
  switch (funcval) {
    case 1:
      {
        StampaVec(b);
        HubTreeVec(b);
      }
      break;
    case 2:
      {
        cout << "Inserisci il valore da controllare" << '\t';
        cin>>controllo;
        if(b.Exists(controllo))
        {
          cout << "Il valore esiste" << '\n';
        }else
          cout << "Il valore non esiste" << '\n';
          cout<< '\n';
          HubTreeVec(b);
      }
      break;
    case 3:
      {
        if((typeid(Data))==typeid(int))
        {
          cout << "Inserisci un valore n" << '\n';
          cin>>n;
          uint acc = FuncSommaVec(b, n);
          cout<< acc<< '\n';
          HubTreeVec(b);
      }else
      {
        cout << "Inserisci un valore n" << '\n';
        cin>>n;
        b.FoldPreOrder(&FuncFloat<Data>, &n, &acc);
        if(acc == 1)
        {
          acc=0;
        }
        cout<< acc<< '\n';
      }
      }
      break;
  }
}

template<typename Data>
void HubTreeVecString(lasd::BinaryTreeVec<Data>& b)
{
  uint funcval, controllavalore, n;
  Data controllo;
  string controllostring;
  cout << "Cosa vuoi fare adesso?" << '\n';
  cout << "1)Stampa elementi" << '\n';
  cout << "2)Controllo Esistenza Valore" << '\n';
  cin>>funcval;
  switch (funcval) {
    case 1:
      {
        StampaVec(b);
        HubTreeVecString(b);
      }
      break;
    case 2:
      {
        cout << "Inserisci il valore da controllare" << '\t';
        cin>>controllo;
        if(b.Exists(controllo))
        {
          cout << "Il valore esiste" << '\n';
        }else
          cout << "Il valore non esiste" << '\n';
          cout<< '\n';
          HubTreeVecString(b);
      }
      break;
    case 3:
      {

      }
      break;
  }
}

char getRandomChar(const char caratteri[],  int& poolsize)
{
  return caratteri[rand() % poolsize];
}

void Menu()
{
  default_random_engine gen(random_device{}());
  uniform_int_distribution<uint> intero(0, 1000);
  uniform_real_distribution<double> doubl(0.0, 1000.0);

  srand(time(0));
  const char caratteri[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  int poolsize = sizeof(caratteri) -1;


  uint tipostruct, tipoval, nval;

  cout << "Scegli l' operazione da fare :" << '\n';
  cout << "1)BinaryTreeLnk" << endl;
  cout << "2)BinaryTreeVec" << endl;
  cout << "3)Fai Test Professore" << '\n';
  cout << "4)Esci" << '\n';
  cin>>tipostruct;

  switch (tipostruct) {
    case 1:
    cout << "Ora scegli il tipo di dato su cui operare:" << '\n';
    cout << "1)Intero" << '\n';
    cout << "2)Float" << '\n';
    cout << "3)String" << '\n';
    cin>> tipoval;
      switch (tipoval) {
        case 1:
        {
          lasd::List<int> list;
          cout << "Ora scegli quanti valori devono essere dati alla lista:" << '\n';
          cin>>nval;
          for(uint i = 0; i< nval; ++i)
          {
            list.InsertAtBack(intero(gen));
          }
          cout << "Lista creata correttamente" << '\n';
          lasd::BinaryTreeLnk<int> BT(list);
          HubTreeLnk(BT);
          break;
        }
        case 2:
        {
          lasd::List<float> list;
          cout << "Ora scegli quanti valori devono essere dati alla lista:" << '\n';
          cin>>nval;
          for(uint i = 0; i< nval; ++i)
          {
            list.InsertAtBack(doubl(gen));
          }
          cout << "Lista creata correttamente" << '\n';
          lasd::BinaryTreeLnk<float> BT(list);
          HubTreeLnk(BT);
          break;
        }
        case 3:
        {
          lasd::List<string> list;
          uint grand, i, j;
          string pass;
          cout << "Ora inserisci quanti valori vuoi aggiungere alla lista" << '\n';
          cin>>nval;
          cout << "Inserisci la grandezza base delle stringhe" << '\n';
          cin>>grand;
          cout <<'\n';
          for (uint i = 0; i<nval; ++i) {
            for(uint j = 0; j<grand; ++j)
            {
              pass+=getRandomChar(caratteri, poolsize);
            }
            j=0;
            list.InsertAtBack(pass);
            pass = "";
          }
          lasd::BinaryTreeLnk<string> BT(list);
          HubTreeLnkString(BT);
          break;
        }
      }
      break;
    case 2:
    {
      cout << "Ora scegli il tipo di dato su cui operare:" << '\n';
      cout << "1)Intero" << '\n';
      cout << "2)Float" << '\n';
      cout << "3)String" << '\n';
      cin>> tipoval;
      switch (tipoval) {
        case 1:
        {
          lasd::List<int> list;
          cout << "Ora scegli quanti valori devono essere dati alla lista:" << '\n';
          cin>>nval;
          for(uint i = 0; i< nval; ++i)
          {
            list.InsertAtBack(intero(gen));
          }
          cout << "Lista creata correttamente" << '\n';
          lasd::BinaryTreeVec<int> BT(list);
          HubTreeVec(BT);
          break;
        }
        case 2:
        {
          lasd::List<float> list;
          cout << "Ora scegli quanti valori devono essere dati alla lista:" << '\n';
          cin>>nval;
          for(uint i = 0; i< nval; ++i)
          {
            list.InsertAtBack(doubl(gen));
          }
          cout << "Lista creata correttamente" << '\n';
          lasd::BinaryTreeVec<float> BT(list);
          HubTreeVec(BT);
          break;
        }
        case 3:
        {
          lasd::List<string> list;
          uint grand, i, j;
          string pass;
          cout << "Ora inserisci quanti valori vuoi aggiungere alla lista" << '\n';
          cin>>nval;
          cout << "Inserisci la grandezza base delle stringhe" << '\n';
          cin>>grand;
          cout <<'\n';
          for (uint i = 0; i<nval; ++i) {
            for(uint j = 0; j<grand; ++j)
            {
              pass+=getRandomChar(caratteri, poolsize);
            }
            j=0;
            list.InsertAtBack(pass);
            pass = "";
          }
          lasd::BinaryTreeVec<string> BT(list);
          HubTreeVecString(BT);
          break;
        }
      }
      break;
    }
    case 3:
      lasdtest();
      break;
  }
}
