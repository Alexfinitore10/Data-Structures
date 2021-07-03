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

template<typename Data>
void Stampa(lasd::BST<Data>& b)
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
uint FuncMolt(lasd::BST<Data>& b, uint n)
{
  uint acc = 1;
  b.FoldPreOrder(&Func<Data>, &n, &acc);
  if(acc == 1){return acc = 0;}else
  return acc;
}

template <typename Data>
float FuncSomma(lasd::BST<Data>& b, float n)
{
  float acc = 0;
  b.FoldPreOrder(&FuncFloat<Data>, &n, &acc);
  return acc;
}

template<typename Data>
void HubBT(lasd::BST<Data>& b)
{
  uint funcval, controllavalore, n;
  Data controllo, elemento;
  string controllostring;
  cout << "Cosa vuoi fare adesso?" << '\n';
  cout << "1)Stampa elementi" << '\n';
  cout << "2)Controllo Esistenza Valore" << '\n';
  cout << "3)Esegui funzione" << '\n';
  cout << "4)Inserimento Elemento" << '\n';
  cout << "5)Eliminazione di un elemento" << '\n';
  cout << "6)Eliminazione Elemento Minimo" << '\n';
  cout << "7)Eliminazione Elemento Massimo" << '\n';
  cout << "8)Eliminazione del Successore dell'elemento" << '\n';
  cout << "9)Eliminazione del Predecessore dell'elemento" << '\n';
  cout << "10)Eliminazione con lettura di Min" << '\n';
  cout << "11)Eliminazione con lettura di Max" << '\n';
  cout << "12)Eliminazione con lettura del Successore" << '\n';
  cout << "13)Eliminazione con lettura del Predecessore" << '\n';
  cout << "14)Lettura del Minimo" << '\n';
  cout << "15)Lettura del Massimo" << '\n';
  cout << "16)Lettura del successore dell'elemento" << '\n';
  cout << "17)Lettura del predecessore dell'elemento" << '\n';
  cin>>funcval;
  switch (funcval) {
    case 1:
      {
        Stampa(b);
        HubBT(b);
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
        HubBT(b);
      }
      break;
    case 3:
      {
        if((typeid(Data))==typeid(int))
        {
          int acc=1;
          cout << "Inserisci un valore n" << '\n';
          cin>>n;
          acc = FuncMolt(b, n);
          cout<< acc<< '\n';
          HubBT(b);
        }else
        {
          cout << "Inserisci un valore n" << '\n';
          cin>>n;
          float acc = FuncSomma(b, n);
          cout<< acc<< '\n';
        }
      }
      break;
    case 4:
    {
      std::cout << "Inserisci l'elemento che vuoi aggiungere" << '\n';
      cin>>elemento;
      b.Insert(elemento);
      HubBT(b);
    }
    break;
    case 5:
    {
      std::cout << "Inserisci l'elemento che vuoi eliminare" << '\n';
      cin>>elemento;
      if(b.Exists(elemento))
      {
        b.Remove(elemento);
      }
      HubBT(b);
    }
    break;
    case 6:
    {
      try
      {
        b.RemoveMin();
      }catch(...)
      {
        std::cout << "Eccezione!" << '\n';
      }
      HubBT(b);
    }
    break;
    case 7:
    {
      try
      {
        b.RemoveMax();
      }catch(...)
      {
        std::cout << "Eccezione!" << '\n';
      }
      HubBT(b);
    }
    break;
    case 8:
    {
      try
      {
        std::cout << "Inserisci l'elemento che vuoi eliminare" << '\n';
        cin>>elemento;
        b.RemoveSuccessor(elemento);
      }catch(...)
      {
        std::cout << "Eccezione!" << '\n';
      }
      HubBT(b);
    }
    break;
    case 9:
    {
      try
      {
        std::cout << "Inserisci l'elemento che vuoi eliminare" << '\n';
        cin>>elemento;
        b.RemovePredecessor(elemento);
      }catch(...)
      {
        std::cout << "Eccezione!" << '\n';
      }
      HubBT(b);
    }
    break;
    case 10:
    {
      try
      {
        elemento = b.MinNRemove();
        std::cout << elemento << '\n';
      }catch(...)
      {
        std::cout << "Eccezione!" << '\n';
      }
      HubBT(b);
    }
    break;
    case 11:
    {
      try
      {
        elemento = b.MaxNRemove();
        std::cout << elemento << '\n';
      }catch(...)
      {
        std::cout << "Eccezione!" << '\n';
      }
      HubBT(b);
    }
    break;
    case 12:
    {
      try
      {
        std::cout << "Inserisci l'elemento che vuoi eliminare" << '\n';
        cin>>elemento;
        elemento = b.SuccessorNRemove(elemento);
        std::cout << elemento << '\n';
      }catch(...)
      {
        std::cout << "Eccezione!" << '\n';
      }
      HubBT(b);
    }
    break;
    case 13:
    {
      try
      {
        std::cout << "Inserisci l'elemento che vuoi eliminare" << '\n';
        cin>>elemento;
        elemento = b.PredecessorNRemove(elemento);
        std::cout << elemento << '\n';
      }catch(...)
      {
        std::cout << "Eccezione!" << '\n';
      }
      HubBT(b);
    }
    break;
    case 14:
    {
      try
      {
        std::cout << b.Min() << '\n';
      }catch(...)
      {
        std::cout << "Eccezione!" << '\n';
      }
      HubBT(b);
    }
    break;
    case 15:
    {
      try
      {
        std::cout << b.Max() << '\n';
      }catch(...)
      {
        std::cout << "Eccezione!" << '\n';
      }
      HubBT(b);
    }
    break;
    case 16:
    {
      try
      {
        std::cout << "Inserisci l'elemento che vuoi visualizzare" << '\n';
        cin>>elemento;
        std::cout << b.Successor(elemento) << '\n';
      }catch(...)
      {
        std::cout << "Eccezione!" << '\n';
      }
      HubBT(b);
    }
    break;
    case 17:
    {
      try
      {
        std::cout << "Inserisci l'elemento che vuoi visualizzare" << '\n';
        cin>>elemento;
        std::cout << b.Predecessor(elemento) << '\n';
      }catch(...)
      {
        std::cout << "Eccezione!" << '\n';
      }
      HubBT(b);
    }
    break;
  }
}

template<typename Data>
void HubBTString(lasd::BST<Data>& b)
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
        Stampa(b);
        HubBTString(b);
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
        HubBTString(b);
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

  uint tipoval, nval, grand;
  cout << "Scegli il tipo di dato su cui operare:" << '\n';
  cout << "1)Intero" << '\n';
  cout << "2)Float" << '\n';
  cout << "3)String" << '\n';
  cout << "4)Test del Professore" << '\n';
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
        lasd::BST<int> BT(list);
        HubBT(BT);
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
        lasd::BST<float> BT(list);
        HubBT(BT);
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
        lasd::BST<string> BT(list);
        HubBTString(BT);
        break;
      }
    case 4:
      {
        lasdtest();
      }
    }
}
