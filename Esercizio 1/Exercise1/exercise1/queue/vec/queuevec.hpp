
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"
#define DEFAULT_SIZE 4
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

  using Vector<Data>::size;
  using Vector<Data>::Elements;
  unsigned long head = 0;
  unsigned long tail = 0;
  unsigned long sentinel = 0;
  // ... 

public:

  // Default constructor
  QueueVec();

  /* ************************************************************************ */

  // Specific constructor
  inline QueueVec(const TraversableContainer<Data>& TravCon);// A stack obtained from a TraversableContainer
  inline QueueVec(MappableContainer<Data>&& MapCon) noexcept; // A stack obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  inline QueueVec(const QueueVec<Data>& qv);

  // Move constructor
  inline QueueVec(QueueVec<Data>&& qv) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~QueueVec() = default;

  /* ************************************************************************ */


  // Copy assignment
  inline QueueVec<Data>& operator=(const QueueVec<Data>&);


  // Move assignment
  inline QueueVec<Data>& operator=(QueueVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueVec<Data>& qv) const noexcept;
  inline bool operator!=(const QueueVec<Data>& qv) const noexcept {return !(*this == qv);};

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  inline const Data& Head() const override; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  inline Data& Head() override; // Override Queue member (mutable version; must throw std::length_error when empty)
  inline void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)
  void Enqueue(const Data&) override; // Override Queue member (copy of the value)
  void Enqueue(Data&&) noexcept override; // Override Queue member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  inline bool Empty() const noexcept override {return (head == tail);}; // Override Container member

  unsigned long Size() const noexcept override; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary functions, if necessary!
  void IncreaseSize();
  void DecreaseSize();
};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
