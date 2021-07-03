
#include "zlasdtest/test.hpp"

#include "binarytree/lnk/binarytreelnk.hpp"

#include "binarytree/vec/binarytreevec.hpp"

#include "zmytest/test.hpp"


/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2020" << std::endl;
  // lasdtest(); // To call in the menu of your library test!
  Hub();

  // lasd::List<double> lst;
  // //
  // lst.InsertAtBack(0);
  // lst.InsertAtBack(1);
  // lst.InsertAtBack(2);
  // lst.InsertAtBack(3);
  // lst.InsertAtBack(4);
  //
  // lasd::List<int> lst2;
  // lst2 = lst;
  // lasd::BinaryTreeVec<double> BT1(lst);
  // lasd::BinaryTreeVec<double> BT2(std::move(BT1));
  // lasd::BinaryTreeVec<int> BT2(lst2);
  // std::cout << "/* message */" << '\n';
  // BT1 = BT2;
  // std::cout << "/* message */" << '\n';
  // std::cout << BT1.Size() << '\n';
  //
  // std::cout << BT1.Root().Element() << " ";
  // std::cout << BT1.Root().LeftChild().Element() << " ";
  // std::cout << BT1.Root().RightChild().Element() << " ";
  // std::cout << BT1.Root().LeftChild().LeftChild().Element() << " ";
  // std::cout << BT1.Root().LeftChild().RightChild().Element() << " ";

  // std::cout << BT2.Root().Element() << " ";
  // std::cout << BT2.Root().LeftChild().Element() << " ";
  // std::cout << BT2.Root().RightChild().Element() << " ";
  // std::cout << BT2.Root().LeftChild().LeftChild().Element() << " ";
  // std::cout << BT2.Root().LeftChild().RightChild().Element() << " ";
  // //
  // std::cout << BT1.Root().Element() << " ";
  // std::cout << "/* message */" << '\n';
  // std::cout << BT1.Root().LeftChild().Element() << " ";
  // std::cout << BT1.Root().RightChild().Element() << " ";
  // std::cout << BT1.Root().LeftChild().LeftChild().Element() << " ";
  // std::cout << BT1.Root().LeftChild().RightChild().Element() << " ";

  return 0;
}
