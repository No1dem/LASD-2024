
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec :virtual public Stack<Data>,virtual protected Vector<Data>{
  // Must extend Stack<Data>,
  //             Vector<Data>

private:

  static const unsigned long DEFAULT_SIZE = 4;
  static const unsigned long INCREASE_FACTOR = 2;
  static const unsigned long DECREASE_FACTOR = 2;
  static const unsigned long REDUCE_THRESHOLD = 4;

protected:

  using Vector<Data>::size;
  using Vector<Data>::Elements;
  unsigned long top = 0;

public:

  // Default constructor
  StackVec() : Vector<Data>::Vector(DEFAULT_SIZE) {};

  /* ************************************************************************ */

  // Specific constructor
  StackVec(const TraversableContainer<Data>&); // A stack obtained from a TraversableContainer
  StackVec(MappableContainer<Data>&&) noexcept; // A stack obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackVec(const StackVec<Data>&);

  // Move constructor
  StackVec(StackVec<Data>&&);

  /* ************************************************************************ */

  // Destructor
  virtual ~StackVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackVec<Data>& operator=(const StackVec<Data>&);

  // Move assignment
  StackVec<Data>& operator=(StackVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackVec<Data>&) const noexcept;

  inline bool operator!=(const StackVec<Data>& stack) const noexcept {return !(*this == stack);};

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  inline const Data& Top() const override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  inline Data& Top() override; // Override Stack member (mutable version; must throw std::length_error when empty)
  inline void Pop() override; // Override Stack member (must throw std::length_error when empty)
  inline Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
  inline void Push(const Data&) override; // Override Stack member (copy of the value)
  inline void Push(Data&&) noexcept override; // Override Stack member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  inline bool Empty() const noexcept override {return (top == 0);}; // Override Container member

  inline unsigned long Size() const noexcept override {return top;}; // Override Container member


  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() override; // Override ClearableContainer member

protected:

  inline void IncreaseSize();
  inline void DecreaseSize();

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
