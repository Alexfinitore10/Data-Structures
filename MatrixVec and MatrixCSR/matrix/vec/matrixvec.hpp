
#ifndef MATRIXVEC_HPP
#define MATRIXVEC_HPP

/* ************************************************************************** */

#include "../matrix.hpp"

#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MatrixVec: virtual public Matrix<Data>, virtual protected Vector<Data> { // Must extend Matrix<Data>

private:

  // ...

protected:

  using Matrix<Data>::row;
  using Matrix<Data>::column;
  using Vector<Data>::Elements;
  using LinearContainer<Data>::size;
  // ...

public:

  // Default constructor
  MatrixVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  MatrixVec(ulong, ulong); // A matrix of some specified dimension

  /* ************************************************************************ */

  // Copy constructor
  MatrixVec(const MatrixVec&);

  // Move constructor
  MatrixVec(MatrixVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~MatrixVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  MatrixVec& operator=(const MatrixVec&);

  // Move assignment
  MatrixVec& operator=(MatrixVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MatrixVec&) const;
  bool operator!=(const MatrixVec&) const;

  /* ************************************************************************ */

  // Specific member functions (inherited from Matrix)

  void RowResize(ulong)override; // Override Matrix member
  void ColumnResize(ulong)override; // Override Matrix member

  bool ExistsCell(const ulong, const ulong)const noexcept override; // Override Matrix member (should not throw exceptions)

  Data& operator()(ulong, ulong) override; // Override Matrix member (mutable access to the element; throw out_of_range when out of range)
  const Data& operator()(const ulong, const ulong) const override; // Override Matrix member (immutable access to the element; throw out_of_range when out of range and length_error when not present)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  void MapPreOrder(const MapFunctor,void*) override; // Override MappableContainer member
  void MapPostOrder(const MapFunctor,void*) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  void FoldPreOrder(const FoldFunctor,const void*, void*)const override; // Override FoldableContainer member
  void FoldPostOrder(const FoldFunctor,const void*, void*)const override; // Override FoldableContainer member


using FoldableContainer<Data>::Exists;
};

/* ************************************************************************** */

}

#include "matrixvec.cpp"

#endif
