
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : virtual public MutableBinaryTree<Data>{
  // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  using BinaryTree<Data>::size;   

  // ...
public:
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

protected:

  struct NodeLnk : virtual MutableNode{ // Must extend MutableNode

  private:

    // ...

  protected:

    // ...

  public:

    Data data;
    NodeLnk * LChild = nullptr;
    NodeLnk * RChild = nullptr;

    //Default constructor
    NodeLnk() = default;

    //Specific constructors
    NodeLnk(const Data&);

    NodeLnk(Data&&) noexcept;

    //Copy constructor
    NodeLnk(const NodeLnk&);

    //Move constructor
    NodeLnk(NodeLnk&&) noexcept;

    //Destructor
    virtual ~NodeLnk();

    //Copy assignment
    NodeLnk& operator=(const NodeLnk&);

    //Move assignment
    NodeLnk& operator=(NodeLnk&&) noexcept;

    //Comparison operators
    bool operator==(const NodeLnk&) const noexcept;
    inline bool operator!=(const NodeLnk& node) const noexcept {return !(*this == node);};

    //Specific functions
    inline const Data& Element() const noexcept override;
    inline Data& Element() noexcept override;
    inline bool IsLeaf() const noexcept override;
    inline bool HasRightChild() const noexcept override;
    inline bool HasLeftChild() const noexcept override;
    virtual const Node& RightChild() const override;
    virtual const Node& LeftChild() const override;
    virtual MutableNode& RightChild() override;
    virtual MutableNode& LeftChild() override;

  };

  NodeLnk* root = nullptr;

public:

  // Default constructor
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeLnk(const TraversableContainer<Data>&); // A binary tree obtained from a TraversableContainer
  BinaryTreeLnk(MappableContainer<Data>&&) noexcept; // A binary tree obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk&);

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk& operator=(const BinaryTreeLnk&);

  // Move assignment
  BinaryTreeLnk& operator=(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BinaryTreeLnk&) const noexcept;
  inline bool operator!=(const BinaryTreeLnk& bt) const noexcept {return !(*this == bt);};

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  const Node& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  MutableNode& Root() override; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

  protected:

  //Auxiliar function
  NodeLnk* CopyTree(NodeLnk*);

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
