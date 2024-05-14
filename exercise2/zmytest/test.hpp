
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
template <typename Data>
void MenuPreOrderIterator(lasd::BTPreOrderIterator<Data>&);

template <typename Data>
void MenuPostOrderIterator(lasd::BTPostOrderIterator<Data>&);

template <typename Data>
void MenuInOrderIterator(lasd::BTInOrderIterator<Data>&);

template <typename Data>
void MenuBreadthIterator(lasd::BTBreadthIterator<Data>&);

template <typename Data>
void MenuBinaryTreeVec(lasd::BinaryTreeVec<Data>&,unsigned long);

// template <typename Data>
// void MenuBinaryTreeLnk(lasd::BinaryTreeLnk<Data>&);

// template <typename Data>
// void MenuBinarySearchTree(lasd::BST<Data>&);


/********************************************************************************/
string selezionaStrutturaAlbero();

unsigned long selezionaDimensioneBT();

string selezionaDato();

unsigned long selezionaDimensioneBST();

/********************************************************************************/
//Popolamento 

//List

void PopolaBT(lasd::List<int>&, unsigned long);

void PopolaBT(lasd::List<double>&, unsigned long);

void PopolaBT(lasd::List<string>&, unsigned long);

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

template <typename Data>
void FunExists(lasd::BinaryTree<Data>&);

template <typename Data>
void PrintPreOrder(lasd::BinaryTree<Data>&);

template <typename Data>
void PrintPostOrder(lasd::BinaryTree<Data>&);

template <typename Data>
void PrintInOrder(lasd::BinaryTree<Data>&);

template <typename Data>
void PrintBreadth(lasd::BinaryTree<Data>&);

template <typename Data>
void FunPrintData(lasd::Iterator<Data>&);

template <typename Data>
void FunTerminatedIterator(lasd::ForwardIterator<Data>&);

template <typename Data>
void FunResetIterator(lasd::ResettableIterator<Data>&);

template <typename Data>
void FunForwardIterator(lasd::ForwardIterator<Data>&);






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