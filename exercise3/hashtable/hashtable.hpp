
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

#define MAX_TABLESIZE 10000000161531

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {

public:

  unsigned long operator()(const Data&) const noexcept = 0; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public ResizableContainer,virtual public DictionaryContainer<Data> {
                  // Must extend ResizableContainer,
                  //             DictionaryContainer<Data>

private:

  // ...

protected:

  using DictionaryContainer<Data>::size;

  unsigned long acoeff = 1;
  unsigned long bcoeff = 0;
  static const unsigned long prime = 10000000161531;

  std::default_random_engine generator = std::default_random_engine(std::random_device {}());
  std::uniform_int_distribution<unsigned long> dista = std::uniform_int_distribution<unsigned long>(1, prime-1);
  std::uniform_int_distribution<unsigned long> distb = std::uniform_int_distribution<unsigned long>(0, prime-1);
  
  static const Hashable<Data> hash;
  unsigned long tablesize = 128;

  // Default constructor
  HashTable() {
    acoeff = dista(generator) | 1;
    bcoeff = distb(generator);
  }

  //Copy constructor
  HashTable(const HashTable& ht) {
    size = ht.size;
    acoeff = ht.acoeff;
    bcoeff = ht.bcoeff;
    tablesize = ht.tablesize;
  }

  //Move constructor
  HashTable(HashTable&& ht) {
    std::swap(size, ht.size);
    std::swap(acoeff, ht.acoeff);
    std::swap(bcoeff, ht.bcoeff);
    std::swap(tablesize, ht.tablesize);
  }

public:

  // Destructor
  virtual ~HashTable() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTable& operator=(const HashTable&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  HashTable& operator=(HashTable&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTable&) const noexcept = delete; // Comparison of abstract hashtable is possible but not required.
  bool operator!=(const HashTable&) const noexcept = delete; // Comparison of abstract hashtable is possible but not required.

protected:

  // Auxiliary member functions

  virtual unsigned long HashKey(const unsigned long) const noexcept;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
