
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../iterator/iterator.hpp"
#include "../list/list.hpp"
#include "../binarytree/binarytree.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../bst/bst.hpp"

#include <string>
#include <iostream>
#include <random>

using namespace std;

/* ************************************************************************** */

void mytest();
/*******************************************************************************/
void InfoStampa();
/*******************************************************************************/
// template <typename Data>
// void MenuBTPreOrderIt(lasd::BinaryTreeVec<Data>&);

// template <typename Data>
// void MenuBTPostOrderIt(lasd::BinaryTreeVec<Data>&);

// template <typename Data>
// void MenuBTInOrderIt(lasd::BinaryTreeVec<Data>&);

// template <typename Data>
// void MenuBTBreadthIt(lasd::BinaryTreeVec<Data>&);

template <typename Data>
void MenuBinaryTreeVec(lasd::BinaryTreeVec<Data>&);

// template <typename Data>
// void MenuBinaryTreeLnk(lasd::BinaryTreeLnk<Data>&);

// template <typename Data>
// void MenuBinarySearchTree(lasd::BST<Data>&);


/********************************************************************************/
string selezionaStrutturaAlbero();

unsigned long selezionaDimensione();

string selezionaDato();

unsigned long selezionaDimensioneBT();

/********************************************************************************/
//Popolamento 

//List

void PopolaList(lasd::List<int>&, unsigned long);

void PopolaList(lasd::List<double>&, unsigned long);

void PopolaList(lasd::List<string>&, unsigned long);

//BST
void PopolaBST(lasd::BST<int>&, unsigned long);

void PopolaBST(lasd::BST<double>&, unsigned long);

void PopolaBST(lasd::BST<string>&, unsigned long);


/***************************************************************/
//Funzioni
template <typename Data>
void FunEmpty(lasd::BinaryTree<Data>&);

template <typename Data>
void FunSize(lasd::BinaryTree<Data>&);

template <typename Data>
void FunRoot(lasd::BinaryTree<Data>&);

template <typename Data>
void FunClear(lasd::MutableBinaryTree<Data>&);





/**************************************************************/
//Generatori
vector<int> generaInt(unsigned long);

vector<double> generaDouble(unsigned long);

vector<string> generaString(unsigned long);

/* ************************************************************************** */
//Stampe

template <typename Data>
void Print(const Data& data) {
  cout << data << " ";
}


template <typename Data>
void PrintTree(typename lasd::MutableBinaryTree<Data>::MutableNode*, int, char);


#endif