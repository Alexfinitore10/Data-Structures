
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec: public Queue<Data>, protected Vector<Data> { // Must extend Queue<Data> and Vector<Data>

private:

  // ...

protected:

  using Vector<Data>::size;
  using Vector<Data>::Elements;
  ulong stacksize = 0;
  ulong testa = 0;
  ulong coda = 0;
  // ...

public:

  // Default constructor
  QueueVec();

  /* ************************************************************************ */

  // Specific constructor
  QueueVec(const LinearContainer<Data>&) ; // A queue obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  QueueVec(const QueueVec<Data>&);

  // Move constructor
  QueueVec(QueueVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~QueueVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  QueueVec<Data>& operator=(const QueueVec<Data>&);

  // Move assignment
  QueueVec<Data>& operator=(QueueVec<Data>&&)noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueVec<Data>&)const noexcept;
  bool operator!=(const QueueVec<Data>&)const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  virtual void Enqueue(const Data&)override; // Override Queue member (copy of the value)
  virtual void Enqueue(Data&&)noexcept override; // Override Queue member (move of the value)
  virtual Data& Head()override; // Override Queue member (must throw std::length_error when empty)
  virtual void Dequeue()override; // Override Queue member (must throw std::length_error when empty)
  virtual Data HeadNDequeue()override; // Override Queue member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  virtual bool Empty()const noexcept override; // Override Container member

  virtual ulong Size()const noexcept override; // Override Container member

  virtual void Clear()override; // Override Container member

protected:

  // Auxiliary member functions poi li faccio

  void Expand();
  void Reduce();
  void SwapVectors();
  bool Full();

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
