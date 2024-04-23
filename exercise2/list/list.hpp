
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"
#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public ClearableContainer, virtual public LinearContainer<Data>, virtual public DictionaryContainer<Data>{
  // Must extend ClearableContainer,
  //             LinearContainer<Data>,
  //             DictionaryContainer<Data>

private:

  // ...

protected:

  using Container::size;

  struct Node {



    Data element;
    Node* next = nullptr;
   

    /* ********************************************************************** */

    // Specific constructors
    inline Node(const Data& dato) : element(dato) {};
    inline Node(Data&& dato) noexcept : element(std::move(dato)) {}; 

    /* ********************************************************************** */

    // Copy constructor
    inline Node(const Node& node) : element(node.element) {};

    // Move constructor
    inline Node(Node&& node) noexcept;

    /* ********************************************************************** */

    // Destructor
    virtual ~Node() {
      delete next;
    };

    /* ********************************************************************** */

    // Comparison operators
    bool operator==(const Node&) const noexcept;
    bool operator!=(const Node&) const noexcept;

    /* ********************************************************************** */

    // Specific member functions

    // ...

  };

  Node* head = nullptr;
  Node* tail = nullptr;

  

public:

  // Default constructor
  List() = default;

  /* ************************************************************************ */

  // Specific constructor
  List(const TraversableContainer<Data>&); // A list obtained from a TraversableContainer
  List(MappableContainer<Data>&&); // A list obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  List(const List<Data>&);

  // Move constructor
  List(List<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~List() {
    delete head;
  }

  /* ************************************************************************ */

  // Copy assignment
  List<Data>& operator=(const List<Data>&);

  // Move assignment
  List<Data>& operator=(List<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const List<Data>&) const noexcept;
  inline bool operator!=(const List<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  void InsertAtFront(const Data&); // Copy of the value
  void InsertAtFront(Data&&) noexcept; // Move of the value

  void RemoveFromFront(); // (must throw std::length_error when empty)
  inline Data FrontNRemove(); // (must throw std::length_error when empty)

  void InsertAtBack(const Data&); // Copy of the value
  void InsertAtBack(Data&&) noexcept; // Move of the value

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

  /* ************************************************************************ */

  using TestableContainer<Data>::Exists;

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data&); // Copy of the value
  bool Insert(Data&&) noexcept; // Move of the value
  bool Remove(const Data&);

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  const Data& operator[](const unsigned long) const override; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  Data& operator[](const unsigned long) override; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

  inline const Data& Front() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  inline Data& Front() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  inline const Data& Back() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  inline Data& Back() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  inline void Traverse(TraverseFun fun)  const override{
    PreOrderTraverse(fun);
  } // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  inline void PreOrderTraverse(TraverseFun fun) const override {
    PreOrderTraverse(fun, head);
  }// Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  inline void PostOrderTraverse(TraverseFun fun) const override {
    PostOrderTraverse(fun, head);
  } // Override PostOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  inline void Map(MapFun fun) override {
    PreOrderMap(fun);
  } // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  inline void PreOrderMap(MapFun fun) override {
    PreOrderMap(fun, head);
  } // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  inline void PostOrderMap(MapFun fun) override {
    PostOrderMap(fun, head);
  } // Override PostOrderMappableContainer member

protected:

  // Auxiliary functions, if necessary!
  void PreOrderTraverse(TraverseFun, Node*) const;

  void PostOrderTraverse(TraverseFun, Node*) const;

  void PreOrderMap(MapFun, Node*) const;

  void PostOrderMap(MapFun, Node*) const;

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
