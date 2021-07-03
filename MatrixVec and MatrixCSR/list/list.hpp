
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public LinearContainer<Data>,virtual public MappableContainer<Data>,virtual public FoldableContainer<Data>{ // Must extend LinearContainer<Data>, MappableContainer<Data>, and FoldableContainer<Data>

private:

  // ...

protected:

  using LinearContainer<Data>::size;

  struct Node
  {
    //Data
    Data dato;
    struct Node* link = nullptr;

    /* ********************************************************************** */

    Node() = default;

    // Specific constructors
    Node(Data);

    /* ********************************************************************** */

    // Copy constructor
    Node(const Node&);

    // Move constructor
    Node(Node&&) noexcept;

    /* ********************************************************************** */

    // Destructor
    virtual ~Node();

    /* ********************************************************************** */

    // Comparison operators
    bool operator==(const Node&)const noexcept;
    bool operator!=(const Node&)const noexcept;

    /* ********************************************************************** */

    // Specific member functions

  };

  public :
    struct Node* head = nullptr;
    struct Node* coda = nullptr;

public:


  // Default constructor
   List() = default;

  /* ************************************************************************ */

  // Specific constructor
  List(const LinearContainer<Data>&); // A list obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  List(const List&);

  // Move constructor
  List(List&&)noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~List();

  /* ************************************************************************ */

  // Copy assignment
  List& operator=(const List&);

  // Move assignment
  List& operator=(List&&)noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const List&) const noexcept;
  bool operator!=(const List&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  virtual void InsertAtFront(const Data&); // Copy of the value
  virtual void InsertAtFront(Data&&) noexcept; // Move of the value
  virtual void RemoveFromFront(); // (must throw std::length_error when empty)
  virtual Data FrontNRemove(); // (must throw std::length_error when empty)

  virtual void InsertAtBack(const Data&); // Copy of the value
  virtual void InsertAtBack(Data&&)noexcept; // Move of the value

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  virtual void Clear() override; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  virtual Data& Front()const override; // Override LinearContainer member (must throw std::length_error when empty)
  virtual Data& Back()const override; // Override LinearContainer member (must throw std::length_error when empty)

  virtual Data& operator[](const ulong)const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  void MapPreOrder(const MapFunctor, void*) override; // Override MappableContainer member
  void MapPostOrder(const MapFunctor, void*) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  void FoldPreOrder(const FoldFunctor, const void*, void*)const override; // Override FoldableContainer member
  void FoldPostOrder(const FoldFunctor, const void*, void*)const override; // Override FoldableContainer member

protected:

  // Auxiliary member functions (for MappableContainer)

  // type MapPreOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards
  // type MapPostOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards

  /* ************************************************************************ */

  // Auxiliary member functions (for FoldableContainer)

  // type FoldPreOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards
  // type FoldPostOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
