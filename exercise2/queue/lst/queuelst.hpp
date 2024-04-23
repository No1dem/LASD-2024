
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : virtual public Queue<Data>, virtual public List<Data> {
  // Must extend Queue<Data>,
  //             List<Data>

private:

  // ...

protected:

  using List<Data>::size;

  // ...

public:

  // Default constructor
  QueueLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  inline QueueLst(const TraversableContainer<Data>& TravCon) : List<Data>(TravCon) {}; // A stack obtained from a TraversableContainer
  inline QueueLst(MappableContainer<Data>&& TravCon) : List<Data>(std::move(TravCon)) {}; // A stack obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  inline QueueLst(const QueueLst<Data>& queue) : List<Data>(queue) {};

  // Move constructor
  inline QueueLst(QueueLst<Data>&& queue) : List<Data>(std::move(queue)) {};


  /* ************************************************************************ */

  // Destructor
  virtual ~QueueLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  QueueLst<Data>& operator=(const QueueLst<Data>&);

  // Move assignment
  QueueLst<Data>& operator=(QueueLst<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const QueueLst<Data>& queue) const noexcept {
    return List<Data>::operator==(queue);
  }


  inline bool operator!=(const QueueLst<Data>& queue) const noexcept {
    return !(*this == queue);
  }

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  inline const Data& Head() const override; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  inline Data& Head() override; // Override Queue member (mutable version; must throw std::length_error when empty)
  inline void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  inline Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)
  inline void Enqueue(const Data&) override; // Override Queue member (copy of the value)
  inline void Enqueue(Data&&) noexcept override; // Override Queue member (move of the value)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
