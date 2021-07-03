
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

// #include "matrix/csr/matrixcsr.hpp"

#include "bst/bst.hpp"


/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

template<typename Data>
void MapPrint(const Data& dat, void* _)
{
  std::cout << dat << " ";
  std::cout <<"bugha"<< '\n';
}

template<typename Data>
void FoldPrint(const Data& dat,const void* _, void* a)
{
  std::cout << dat << " ";
  std::cout << "teatrino" << '\n';
}


int main() {
  std::cout << "Lasd Libraries 2020" << std::endl;
  // lasdtest(); // To call in the menu of your library test!
  Hub();


  // lasd::BST<int> a;
  //
  // a.MapPostOrder(MapPrint<int>, 0);
  // a.MapInOrder(MapPrint<int>, 0);
  // a.MapPreOrder(MapPrint<int>, 0);
  // a.MapBreadth(MapPrint<int>, 0);
  //
  // a.FoldPostOrder(FoldPrint<int>, 0,0);
  // a.FoldInOrder(FoldPrint<int>, 0,0);
  // a.FoldPreOrder(FoldPrint<int>, 0,0);
  // a.FoldBreadth(FoldPrint<int>, 0,0);
  // lasd::MatrixCSR<int> a(5,5);
  //
  // lasd::MatrixCSR<int> b(5,5);
  //
  // a(2,1) = 5;
  // a(2,2) = 10;
  // std::cout << "/* quando */" << '\n';
  //
  // // a.RowResize(2);
  //
  // b(2,1) = 5;
  // b(2,2) = 10;
  // std::cout << "/* sborri */" << '\n';
  //
  // std::cout << (a==b) << '\n';
  //
  // lasd::MatrixCSR<int> c(a);
  //
  // c.RowResize(1);
  //
  // b.RowResize(1);
  //
  // std::cout << (c==b) << '\n';


  return 0;
}
