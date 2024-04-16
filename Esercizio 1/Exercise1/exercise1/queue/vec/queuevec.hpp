
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : virtual public Queue<Data>,virtual public Vector<Data>{
  // Must extend Queue<Data>,
  //             Vector<Data>

private:

  // ...

protected:

  using Container::size;
  using Vector<Data>::Elements;
  unsigned long head = 0;
  unsigned long tail = size;
  unsigned long sentinel = size;
  // ... 

public:

  // Default constructor
  QueueVec() = default;

  /* ************************************************************************ */

  // Specific constructor
  inline QueueVec(const TraversableContainer<Data>& TravCon) : Vector<Data>::Vector(TravCon) {};// A stack obtained from a TraversableContainer
  inline QueueVec(MappableContainer<Data>&& MapCon) noexcept : Vector<Data>::Vector(std::move(MapCon)) {}; // A stack obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  inline QueueVec(const QueueVec<Data>& qv) : Vector<Data>::Vector(qv) {};

  // Move constructor
  inline QueueVec(QueueVec<Data>&& qv) noexcept : Vector<Data>::Vector(std::move(qv)) {};

  /* ************************************************************************ */

  // Destructor
  virtual ~QueueVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  inline QueueVec<Data>& operator=(const QueueVec<Data>&) {
    Vector<Data>::operator=(qv); 
    return *this;
  };

  // Move assignment
  inline QueueVec<Data>& operator=(QueueVec<Data>&&) noexcept {
    Vector<Data>::operator=(std::move(qv)); 
    return *this;
  };

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const QueueVec<Data>& qv) const noexcept : Vector<Data>::operator==(qv) {};
  inline bool operator!=(const QueueVec<Data>& qv) const noexcept {return !(*this == qv)};

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  inline const Data& Head() const override; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  inline Data& Head() override; // Override Queue member (mutable version; must throw std::length_error when empty)
  inline void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  inline Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)
  inline void Enqueue(const Data&) override; // Override Queue member (copy of the value)
  inline void Enqueue(Data&&) noexcept override; // Override Queue member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  bool Empty() const noexcept override; // Override Container member

  unsigned long Size() const noexcept override; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
