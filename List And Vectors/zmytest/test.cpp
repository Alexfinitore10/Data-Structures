#include"test.hpp"
#include<iostream>
#include<random>
#include<typeinfo>

using namespace std;

template<typename Data>
void MapPrint(const Data& dat, void* _)
{
  std::cout << dat << " ";
}

template<typename Data>
void StampaList(lasd::List<Data>& lst)
{
  lst.MapPreOrder(MapPrint<Data>, 0);
}

template<typename Data>
void StampaVett(lasd::Vector<Data>& vett)
{
  vett.MapPreOrder(MapPrint<Data>, 0);
}
template<typename Data>
bool Checkint(lasd::List<Data>& lst)
{
  return (typeid(Data)) == typeid(int);
}
template<typename Data>
bool Checkdouble(lasd::List<Data>& lst)
{
  return (typeid(Data)) == typeid(double);
}

template<typename Data>
void HubOpList(lasd::List<Data>& lst)
{
  uint funcval, controllavalore, n;
  Data controllo;
  string controllostring;
  cout << "Cosa vuoi fare adesso?" << '\n';
  cout << "1)Stampa elementi" << '\n';
  cout << "2)Controllo Esistenza Indice" << '\n';
  cout << "3)Controlla valore in testa" << '\n';
  cout << "4)Controlla valore in coda" << '\n';
  cout << "5)Controllo Esistenza valore" << '\n';
  cin>>funcval;
  switch (funcval) {
    case 1:
      StampaList(lst);
      cout<< '\n';
      HubOpList(lst);
      break;
    case 2:
      cout << "Inserscimi l'indice da controllare" << '\n';
      cin>>controllavalore;
      cout << lst[controllavalore-1] << '\n';
      HubOpList(lst);
      break;
    case 3:
      cout <<'\n';
      cout <<"Il valore in testa è : " << lst.Front() << '\n';
      cout <<'\n';
      HubOpList(lst);
      break;
    case 4:
      cout <<'\n';
      cout << "Il valore in coda è : " <<lst.Back() << '\n';
      cout <<'\n';
      HubOpList(lst);
      break;
    case 5:
    {
      cout << "Inserisci il valore da controllare" << '\t';
      cin>>controllo;
      if(lst.Exists(controllo))
      {
        cout << "Il valore esiste" << '\n';
      }else
        cout << "Il valore non esiste" << '\n';
        cout<< '\n';
      HubOpList(lst);
      break;
    }
    default:
      break;
    }
}

template<typename Data>
void HubOpVett(lasd::Vector<Data>& vett)
{
  uint risp, controllavalore;
  Data controllo;
  cout << "Cosa vuoi fare adesso?" << '\n';
  cout << "1)Stampa elementi" << '\n';
  cout << "2)Controllo Esistenza indice" << '\n';
  cout << "3)Controlla valore in testa" << '\n';
  cout << "4)Controlla valore in coda" << '\n';
  cout << "5)Controllo Esistenza valore" << '\n';
  cin>> risp;
  switch (risp) {
    case 1:
      StampaVett(vett);
      cout<< '\n';
      HubOpVett(vett);
      break;
    case 2:
      cout << "Inseriscimi l'indice da controllare :" << '\t';
      cin>>controllavalore;
      cout<< '\n';
      cout << "Il valore controllato è :" <<vett[controllavalore-1] << '\n';
      HubOpVett(vett);
      break;
    case 3:
      cout<< '\n';
      cout << "Il valore in testa del vettore è :"<< vett.Front() << '\n';
      cout<< '\n';
      HubOpVett(vett);
      break;
    case 4:
      cout<< '\n';
      cout << "Il valore in coda al vettore è :"<< vett.Back() << '\n';
      cout<< '\n';
      HubOpVett(vett);
      break;
    case 5:
      cout << "Inserisci il valore da controllare" << '\t';
      cin>>controllo;
      cout<< '\n';
      if(vett.Exists(controllo))
      {
        cout << "Il valore esiste" << '\n';
      }else
        cout << "Il valore non esiste" << '\n';
      cout<< '\n';
      HubOpVett(vett);
      break;
  }
}

void Hub()
{
  while (true)
  {
    Menu();
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
  cout << "1)Lista" << endl;
  cout << "2)Vettore" << endl;
  cout << "3)Fai Test Professore" << '\n';
  cout << "4)Esci" << '\n';

  cin >> tipostruct;
  switch (tipostruct) {
    case 1:
      cout << "Ora scegli il tipo di dato su cui operare:" << '\n';
      cout << "1)Intero" << '\n';
      cout << "2)Float" << '\n';
      cout << "3)String" << '\n';
      cin>> tipoval;
      switch (tipoval) {
        case 1:{
          lasd::List<int> list;
          cout << "Ora inserisci quanti valori vuoi aggiungere alla lista" << '\n';
          cin>>nval;
          //...da continuare le funzioni da fare poi...
          cout << "I valori per la lista intera verranno scelti randomicamente..." << '\n';
          cout <<'\n';
          for(uint i = 0; i< nval; ++i)
          {
            list.InsertAtBack(intero(gen));
          }
          cout <<'\n';
          cout << "La lista è stata creata" << '\n';
          cout << "------------------" << '\n';
          // list.MapPreOrder(MapPrint<int>, 0);
          cout <<'\n';
          cout << "------------------" << '\n';
          cout <<'\n';
          HubOpList(list);
          break;
        }
        case 2:{
          lasd::List<double> list;
          cout << "Ora inserisci quanti valori vuoi aggiungere alla lista" << '\n';
          cin>>nval;
          cout << "I valori per la lista intera verranno scelti randomicamente..." << '\n';
          cout <<'\n';
          for(uint i = 0; i< nval; ++i)
          {
            list.InsertAtBack(doubl(gen));
          }
          cout <<'\n';
          cout << "La lista è stata creata" << '\n';
          cout << "------------------" << '\n';
          // list.MapPreOrder(MapPrint<double>, 0);
          cout <<'\n';
          cout << "------------------" << '\n';
          cout <<'\n';
          HubOpList(list);
          break;
        }
      case 3:{
        lasd::List<string> list;
        uint grand, i, j;
        string pass;
        cout << "Ora inserisci quanti valori vuoi aggiungere alla lista" << '\n';
        cin>>nval;
        cout << "Inserisci la grandezza base delle stringhe" << '\n';
        cin>>grand;
        cout <<'\n';
        cout << "I valori per la lista intera verranno scelti randomicamente..." << '\n';
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
        cout << "La lista è stata creata" << '\n';
        cout << "------------------" << '\n';
        // list.MapPreOrder(MapPrint<string>, 0);
        cout << "------------------" << '\n';
        cout <<'\n';
        HubOpList(list);
        break;
      }
    }

      break;
    case 2:
      cout << "Ora scegli il tipo di dato su cui operare:" << '\n';
      cout << "1)Intero" << '\n';
      cout << "2)Float" << '\n';
      cout << "3)String" << '\n';
      cin>> tipoval;
      switch (tipoval) {
        case 1:{
          cout << "Ora inserisci quanti valori vuoi aggiungere alla lista" << '\n';
          cin>>nval;
          lasd::Vector<uint> vett(nval);
          cout << '\n';
          cout << "I valori per il vettore intero verranno scelti randomicamente..." << '\n';
          for(uint i = 0; i< nval; ++i)
          {
            vett[i] = intero(gen);
          }
          cout << '\n';
          cout << "Il vettore è stato creato" << '\n';
          cout << "------------------" << '\n';
          // vett.MapPreOrder(MapPrint<int>, 0);
          cout<< '\n';
          cout << "------------------" << '\n';
          cout<< '\n';
          HubOpVett(vett);
          break;
        }
        case 2:{
          cout << "Ora inserisci quanti valori vuoi aggiungere alla lista" << '\n';
          cin>>nval;
          lasd::Vector<double> vett(nval);
          cout << '\n';
          cout << "I valori per il vettore intero verranno scelti randomicamente..." << '\n';
          for(uint i = 0; i< nval; ++i)
          {
            vett[i] = doubl(gen);
          }
          cout << '\n';
          cout << "Il vettore è stato creato" << '\n';
          cout << "------------------" << '\n';
          // vett.MapPreOrder(MapPrint<double>, 0);
          cout<< '\n';
          cout << "------------------" << '\n';
          cout<< '\n';
          HubOpVett(vett);
          break;
        }
        case 3:{
        uint grand, i, j;
        string pass;
        cout << "Ora inserisci quanti valori vuoi aggiungere al vettore" << '\n';
        cin>>nval;
        lasd::Vector<string> vett(nval);
        cout << "Inserisci la grandezza base delle stringhe" << '\n';
        cin>>grand;
        cout <<'\n';
        cout << "I valori per il vettore verranno scelti randomicamente..." << '\n';
        cout <<'\n';
        for (uint i = 0; i<nval; ++i) {
          for(uint j = 0; j<grand; ++j)
          {
            pass+=getRandomChar(caratteri, poolsize);
          }
          j=0;
          vett[i] = pass;
          pass = "";
        }
        cout << "La lista è stata creata" << '\n';
        cout << "------------------" << '\n';
        // vett.MapPreOrder(MapPrint<string>, 0);
        cout <<'\n';
        cout << "------------------" << '\n';
        cout <<'\n';
        HubOpVett(vett);
        break;
      }
          break;

      }
      break;
    case 3:
      std::cout << "Lasd Libraries 2020" << std::endl;
      lasdtest();
      break;
    case 4:
      exit(0);
    default:
      Menu();
  }

}
