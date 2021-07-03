#include "test.hpp"
#include "../zlasdtest/test.hpp"
#include <random>
#include <iostream>
#include <time.h>
#include <string>
#include <typeinfo>

using namespace std;

void Hub()
{

  Menu();

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
void Func(const Data& dat, const void* n, void* acc) noexcept
{
  if(dat < *((Data*)n))
  {
    *((Data*)acc) *= dat;
  }
}

template <typename Data>
uint FuncMoltCSR(lasd::MatrixCSR<Data>& m, uint n)
{
  uint acc = 1;
  m.FoldPreOrder(&Func<Data>, &n, &acc);
  if(acc == 1){return acc = 0;}else
  return acc;
}

template <typename Data>
uint FuncMoltVec(lasd::MatrixVec<Data>& m, uint n)
{
  uint acc = 1;
  m.FoldPreOrder(&Func<Data>, &n, &acc);
  if(acc == 1){return acc = 0;}else
  return acc;
}

template <typename Data>
float FuncSommaCSR(lasd::MatrixCSR<Data>& m, float n)
{
  float acc = 0;
  m.FoldPreOrder(&FuncFloat<Data>, &n, &acc);
  return acc;
}

template <typename Data>
float FuncSommaVec(lasd::MatrixVec<Data>& m, float n)
{
  float acc = 0;
  m.FoldPreOrder(&FuncFloat<Data>, &n, &acc);
  return acc;
}

template<typename Data>
void MapPrint(const Data& dat, void* _)
{
  std::cout << dat << " ";
  std::cout << '\n';
}

template<typename Data>
void MatrixCSRHub(lasd::MatrixCSR<Data>& m)
{
  ulong i;
  Data isso;
  Data controllo;
  cout << "Cosa vuoi fare ora?" << '\n';
  cout << "1) Visualizzazione elementi in PreOrder" << '\n';
  cout << "2) Visualizzazione elementi in PostOrder" << '\n';
  cout << "3) Controlla se esiste il valore" << '\n';
  cout << "4) Leggi il valore" << '\n';
  cout << "5) Inserisci Valore" << '\n';
  cout << "6) Ridimensionamento Colonne" << '\n';
  cout << "7) Ridimensionamento Righe" << '\n';
  cout << "8) Esegui funzione" << '\n';
  cin>>i;
  switch (i) {
    case 1:
        {
          m.MapPreOrder(MapPrint<Data>,0);
        }
        break;
    case 2:
        {
          m.MapPostOrder(MapPrint<Data>,0);
        }
        break;
    case 3:
        {
          std::cout << "Inserisci un valore da controllare" << '\n';
          cin>>controllo;
          if(m.Exists(controllo))
          {
            std::cout << "Il valore esiste" << '\n';
          }else std::cout << "Il valore non esiste" << '\n';
        }
        break;
    case 4:
        {
          ulong col, rig;
          cout << "Inserisci la riga da controllare" << '\n';
          cin>>rig;
          cout << "Inserisci la colonna da controllare" << '\n';
          cin>>col;
          cout << "Il valore di posizione ("<< rig<<","<<col<<") è :"<< m(rig,col) << '\n';
        }
        break;
    case 5:
        {
          Data e;
          ulong col, rig;
          cout << "Inserisci il valore che vuoi inserire" << '\n';
          cin>>e;
          cout << "Inserisci la riga per l'inserimento" << '\n';
          cin>>rig;
          cout << "Inserisci la colonna per l'inserimento" << '\n';
          cin>>col;
          m(rig,col) = e;
          cout << "Il valore inserito in posizione ("<< rig<<","<<col<<") è :"<< m(rig,col) << '\n';
        }
      break;
    case 6:
        {
          ulong a;
          cout << "Inserisci la grandezza della colonna che vuoi ridimensionare" << '\n';
          cin>>a;
          m.ColumnResize(a);
        }
      break;
    case 7:
        {
          ulong a;
          cout << "Inserisci la grandezza della riga che vuoi ridimensionare" << '\n';
          cin>>a;
          m.RowResize(a);
        }
      break;
    case 8:
        {
          if((typeid(Data))==typeid(int))
          {
            uint acc = 1;
            ulong n;
            std::cout << "Inserisci un numero n" << '\n';
            cin>>n;
            acc = FuncMoltCSR(m, n);
            std::cout << "Risultato: "<< acc << '\n';
          }else
          {
            ulong n;
            std::cout << "Inserisci un numero n" << '\n';
            cin>>n;
            float acc = FuncSommaCSR(m, n);
            std::cout << "Risultato: "<< acc << '\n';
          }
        }
      break;
  }
  MatrixCSRHub(m);
}

template<typename Data>
void MatrixCSRHubString(lasd::MatrixCSR<Data>& m)
{
  ulong i;
  Data controllo;
  cout << "Cosa vuoi fare ora?" << '\n';
  cout << "1) Visualizzazione elementi in PreOrder" << '\n';
  cout << "2) Visualizzazione elementi in PostOrder" << '\n';
  cout << "3) Controlla se esiste il valore" << '\n';
  cout << "4) Leggi il valore" << '\n';
  cout << "5) Inserisci Valore" << '\n';
  cout << "6) Ridimensionamento Colonne" << '\n';
  cout << "7) Ridimensionamento Righe" << '\n';
  cin>>i;
  switch (i) {
    case 1:
        {
          m.MapPreOrder(MapPrint<Data>,0);
        }
      break;
    case 2:
        {
          m.MapPostOrder(MapPrint<Data>,0);
        }
      break;
    case 3:
        {
          std::cout << "Inserisci un valore da controllare" << '\n';
          cin>>controllo;
          if(m.Exists(controllo))
          {
            std::cout << "Il valore esiste" << '\n';
          }else std::cout << "Il valore non esiste" << '\n';
        }
      break;
    case 4:
        {
          ulong col, rig;
          cout << "Inserisci la riga da controllare" << '\n';
          cin>>rig;
          cout << "Inserisci la colonna da controllare" << '\n';
          cin>>col;
          cout << "Il valore di posizione ("<< rig<<","<<col<<") è :"<< m(rig,col) << '\n';
        }
    break;
    case 5:
        {
          Data e;
          ulong col, rig;
          cout << "Inserisci il valore che vuoi inserire" << '\n';
          cin>>e;
          cout << "Inserisci la riga per l'inserimento" << '\n';
          cin>>rig;
          cout << "Inserisci la colonna per l'inserimento" << '\n';
          cin>>col;
          m(rig,col) = e;
          cout << "Il valore inserito in posizione ("<< rig<<","<<col<<") è :"<< m(rig,col) << '\n';
        }
      break;
    case 6:
        {
          ulong a;
          cout << "Inserisci la grandezza della colonna che vuoi ridimensionare" << '\n';
          cin>>a;
          m.ColumnResize(a);
        }
    break;
    case 7:
        {
          ulong a;
          cout << "Inserisci la grandezza della riga che vuoi ridimensionare" << '\n';
          cin>>a;
          m.RowResize(a);
        }
      break;
    }
    MatrixCSRHubString(m);
}

template<typename Data>
void MatrixVecHub(lasd::MatrixVec<Data>& m)
{
  ulong i;
  Data controllo;
  cout << "Cosa vuoi fare ora?" << '\n';
  cout << "1) Visualizzazione elementi in PreOrder" << '\n';
  cout << "2) Visualizzazione elementi in PostOrder" << '\n';
  cout << "3) Controlla se esiste il valore" << '\n';
  cout << "4) Leggi il valore" << '\n';
  cout << "5) Inserisci Valore" << '\n';
  cout << "6) Ridimensionamento Colonne" << '\n';
  cout << "7) Ridimensionamento Righe" << '\n';
  cout << "8) Esegui funzione" << '\n';
  cout << "9) Esci" << '\n';
  cin>>i;
  switch (i) {
    case 1:
        {
          m.MapPreOrder(MapPrint<Data>,0);
        }
      break;
    case 2:
        {
          m.MapPostOrder(MapPrint<Data>,0);
        }
      break;
    case 3:
        {
          std::cout << "Inserisci un valore da controllare" << '\n';
          cin>>controllo;
          if(m.Exists(controllo))
          {
            std::cout << "Il valore esiste" << '\n';
          }else std::cout << "Il valore non esiste" << '\n';
        }
      break;
    case 4:
        {
          ulong col, rig;
          cout << "Inserisci la riga da controllare" << '\n';
          cin>>rig;
          cout << "Inserisci la colonna da controllare" << '\n';
          cin>>col;
          cout << "Il valore di posizione ("<< rig<<","<<col<<") è :"<< m(rig,col) << '\n';
        }
    break;
    case 5:
        {
          Data e;
          ulong col, rig;
          cout << "Inserisci il valore che vuoi inserire" << '\n';
          cin>>e;
          cout << "Inserisci la riga per l'inserimento" << '\n';
          cin>>rig;
          cout << "Inserisci la colonna per l'inserimento" << '\n';
          cin>>col;
          m(rig,col) = e;
          cout << "Il valore inserito in posizione ("<< rig<<","<<col<<") è :"<< m(rig,col) << '\n';
        }
      break;
    case 6:
        {
          ulong a;
          cout << "Inserisci la grandezza della colonna che vuoi ridimensionare" << '\n';
          cin>>a;
          m.ColumnResize(a);
        }
    break;
    case 7:
        {
          ulong a;
          cout << "Inserisci la grandezza della riga che vuoi ridimensionare" << '\n';
          cin>>a;
          m.RowResize(a);
        }
      break;
    case 8:
        {
          if((typeid(Data))==typeid(int))
          {
            uint acc = 1;
            ulong n;
            std::cout << "Inserisci un numero n" << '\n';
            cin>>n;
            acc = FuncMoltVec(m, n);
            std::cout << "Risultato: "<< acc << '\n';
          }else
          {
            ulong n;
            std::cout << "Inserisci un numero n" << '\n';
            cin>>n;
            float acc = FuncSommaVec(m, n);
            std::cout << "Risultato: "<< acc << '\n';
          }
        }
    break;
  }
  MatrixVecHub(m);
}

template<typename Data>
void MatrixVecHubString(lasd::MatrixVec<Data>& m)
{
  ulong i;
  Data controllo;
  cout << "Cosa vuoi fare ora?" << '\n';
  cout << "1) Visualizzazione elementi in PreOrder" << '\n';
  cout << "2) Visualizzazione elementi in PostOrder" << '\n';
  cout << "3) Controlla se esiste il valore" << '\n';
  cout << "4) Leggi il valore" << '\n';
  cout << "5) Inserisci Valore" << '\n';
  cout << "6) Ridimensionamento Colonne" << '\n';
  cout << "7) Ridimensionamento Righe" << '\n';
  cin>>i;
  switch (i) {
    case 1:
        {
          m.MapPreOrder(MapPrint<Data>,0);
        }
      break;
    case 2:
        {
          m.MapPostOrder(MapPrint<Data>,0);
        }
      break;
    case 3:
        {
          std::cout << "Inserisci un valore da controllare" << '\n';
          cin>>controllo;
          if(m.Exists(controllo))
          {
            std::cout << "Il valore esiste" << '\n';
          }else std::cout << "Il valore non esiste" << '\n';
        }
      break;
    case 4:
        {
          ulong col, rig;
          cout << "Inserisci la riga da controllare" << '\n';
          cin>>rig;
          cout << "Inserisci la colonna da controllare" << '\n';
          cin>>col;
          cout << "Il valore di posizione ("<< rig<<","<<col<<") è :"<< m(rig,col) << '\n';
        }
    break;
    case 5:
        {
          Data e;
          ulong col, rig;
          cout << "Inserisci il valore che vuoi inserire" << '\n';
          cin>>e;
          cout << "Inserisci la riga per l'inserimento" << '\n';
          cin>>rig;
          cout << "Inserisci la colonna per l'inserimento" << '\n';
          cin>>col;
          m(rig,col) = e;
          cout << "Il valore inserito in posizione ("<< rig<<","<<col<<") è :"<< m(rig,col) << '\n';
        }
      break;
    case 6:
        {
          ulong a;
          cout << "Inserisci la grandezza della colonna che vuoi ridimensionare" << '\n';
          cin>>a;
          m.ColumnResize(a);
        }
    break;
    case 7:
        {
          ulong a;
          cout << "Inserisci la grandezza della riga che vuoi ridimensionare" << '\n';
          cin>>a;
          m.RowResize(a);
        }
      break;
    }
    MatrixVecHubString(m);
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

  uint tipostruct, tipoval, nri, ncol;
  cout << "Scegli l'implementazione :" << '\n';
  cout << "1)Matrice Vettoriale" << '\n';
  cout << "2)Matrice Yale Format" << '\n';
  cout << "3)Test del Professore" << '\n';
  cout << "4)Esci" << '\n';
  cin>> tipoval;
  switch (tipoval) {
    case 1:
      {
        cout << "Scegli il tipo di dato su cui operare:" << '\n';
        cout << "1)Intero" << '\n';
        cout << "2)Float" << '\n';
        cout << "3)String" << '\n';
        cin>> tipoval;
        switch (tipoval) {
          case 1:
            {
              cout << "Scegli la grandezza delle righe della matrice:" << '\n';
              cin>>nri;
              cout << "Scegli la grandezza delle colonne della matrice:" << '\n';
              cin>>ncol;
              lasd::MatrixVec<int> MV(nri, ncol);
              for(ulong i = 0; i<nri; i++)
              {
                for(ulong j = 0; j<ncol; j++)
                {
                  MV(i,j) = intero(gen);
                }
              }
              MatrixVecHub(MV);
            }
            break;
          case 2:
            {
              cout << "Scegli la grandezza delle righe della matrice:" << '\n';
              cin>>nri;
              cout << "Scegli la grandezza delle colonne della matrice:" << '\n';
              cin>>ncol;
              lasd::MatrixVec<float> MV(nri, ncol);
              for(ulong i = 0; i<nri; i++)
              {
                for(ulong j = 0; j<ncol; j++)
                {
                  MV(i,j) = doubl(gen);
                }
              }
              MatrixVecHub(MV);
            }
            break;
          case 3:
            {
              uint grand, j =0;
              string pass;
              cout << "Scegli la grandezza delle righe della matrice:" << '\n';
              cin>>nri;
              cout << "Scegli la grandezza delle colonne della matrice:" << '\n';
              cin>>ncol;
              cout << "Scegli la grandezza delle strighe:" << '\n';
              cin>>grand;
              lasd::MatrixVec<string> MV(nri, ncol);
              for (uint i = 0; i<nri; ++i)
              {
                for(uint f = 0; f< ncol; f++)
                {
                  for(; j<grand; ++j)
                  {
                    pass+=getRandomChar(caratteri, poolsize);
                  }
                  j=0;
                  MV(i,f) = pass;
                  pass = "";
                }
              }
              MatrixVecHubString(MV);
            }
            break;
        }
      }
      break;
    case 2:
      {

        cout << "Scegli il tipo di dato su cui operare:" << '\n';
        cout << "1)Intero" << '\n';
        cout << "2)Float" << '\n';
        cout << "3)String" << '\n';
        cin>> tipoval;
        switch (tipoval) {
          case 1:
            {
              ulong nval, rigrand, colrand;
              cout << "Scegli la grandezza delle righe della matrice:" << '\n';
              cin>>nri;
              cout << "Scegli la grandezza delle colonne della matrice:" << '\n';
              cin>>ncol;
              lasd::MatrixCSR<int> MCSR(nri, ncol);
              cout << "Quanti valori vuoi riempire?" << '\n';
              cin>>nval;
              for (ulong i = 0; i<nval;++i) {
                uint randrig = rand()%nri;
                uint randcol = rand()%ncol;
                // std::cout << "riga: "<< randrig << '\n';
                // std::cout << "colonna: "<< randcol << '\n';
                MCSR(randrig, randcol) = intero(gen);
              }
              MatrixCSRHub(MCSR);
            }
            break;
          case 2:
            {
              ulong nval;
              cout << "Scegli la grandezza delle righe della matrice:" << '\n';
              cin>>nri;
              cout << "Scegli la grandezza delle colonne della matrice:" << '\n';
              cin>>ncol;
              lasd::MatrixCSR<float> MCSR(nri, ncol);
              cout << "Quanti valori vuoi riempire?" << '\n';
              cin>>nval;
              for (ulong i = 0; i<nval;++i) {
                uint randrig = rand()%nri;
                uint randcol = rand()%ncol;
                MCSR(randrig, randcol) = doubl(gen);
              }
              MatrixCSRHub(MCSR);
            }
            break;
          case 3:
            {
              ulong grand, valori, j =0;
              uint randrig, randcol;
              string pass;
              cout << "Scegli la grandezza delle righe della matrice:" << '\n';
              cin>>nri;
              cout << "Scegli la grandezza delle colonne della matrice:" << '\n';
              cin>>ncol;
              lasd::MatrixCSR<string> MCSR(nri, ncol);
              cout << "Scegli quanti valori vuoi avere:" << '\n';
              cin>>valori;
              cout << "Scegli la grandezza delle strighe:" << '\n';
              cin>>grand;
              for (ulong i = 0; i<valori; ++i)
              {
                  for(; j<grand; ++j)
                  {
                    pass+=getRandomChar(caratteri, poolsize);
                  }
                  j=0;
                  randrig = rand()%nri;
                  randcol = rand()%ncol;
                  MCSR(randrig,randcol) = pass;
                  pass = "";
              }
              MatrixCSRHubString(MCSR);
            }
            break;
        }
      }
      break;
    case 3:
      {
        lasdtest();
        Menu();
      }
      break;
    case 4:
      return;
      break;
  }
}
