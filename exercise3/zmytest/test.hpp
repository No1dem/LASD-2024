
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/dictionary.hpp"
#include "../container/linear.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "../hashtable/hashtable.hpp"
#include "../hashtable/clsadr/htclsadr.hpp"
#include "../hashtable/opnadr/htopnadr.hpp"
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
//Menu
template <typename Data>
void MenuHashTableClsAdr(lasd::HashTableClsAdr<Data>&, unsigned long);


template <typename Data>
void MenuHashTableOpnAdr(lasd::HashTableOpnAdr<Data>&, unsigned long);

/********************************************************************************/
unsigned long SelezionaDimensioneHT();

string SelezionaHashTable();

string SelezionaDato();

/********************************************************************************/
//Popolamento 

//HashTableClsAdr


void PopolaHashTableClsAdr(lasd::HashTableClsAdr<int>&, unsigned long);

void PopolaHashTableClsAdr(lasd::HashTableClsAdr<double>&, unsigned long);

void PopolaHashTableClsAdr(lasd::HashTableClsAdr<std::string>&, unsigned long);

//HashTableOpnAdr


void PopolaHashTableOpnAdr(lasd::HashTableOpnAdr<int>&, unsigned long);

void PopolaHashTableOpnAdr(lasd::HashTableOpnAdr<double>&, unsigned long);

void PopolaHashTableOpnAdr(lasd::HashTableOpnAdr<string>&, unsigned long);


/***************************************************************/
//Funzioni
template <typename Data>
void FuncInsertDictionary(lasd::HashTable<Data>&);


template <typename Data>
void FuncRemoveDictionary(lasd::HashTable<Data>&);


template <typename Data>
void FuncResize(lasd::HashTable<Data>&);


template <typename Data>
void FuncEmpty(lasd::HashTable<Data>&);


template <typename Data>
void FuncClear(lasd::HashTable<Data>&);


template <typename Data>
void FuncExists(lasd::HashTable<Data>&);


template <typename Data>
void FuncSize(lasd::HashTable<Data>&);


/**************************************************************/
//Generatori
vector<int> generaInt(unsigned long);

vector<double> generaDouble(unsigned long);

vector<string> generaString(unsigned long);

/* ************************************************************************** */

#endif