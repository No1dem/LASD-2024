
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../list/list.hpp"
#include "../vector/vector.hpp"
#include "../stack/stack.hpp"
#include "../queue/queue.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"

#include <string>
#include <iostream>

using namespace std;

/* ************************************************************************** */

void test();


/*******************************************************************************/
template <typename Data>
void menuStack(lasd::Stack<Data>&);

template <typename Data>
void menuQueue(lasd::Queue<Data>&);

template <typename Data>
void menuList(lasd::List<Data>&);

template <typename Data>
void menuVector(lasd::Vector<Data>&);


/********************************************************************************/
string selezionaStruttura();

string selezionaTipo();

unsigned long selezionaDimensione();


/********************************************************************************/
//popolamento

//vector
template <typename Data>
void popolaVector(lasd::Vector<Data>&, unsigned long);

void popolaVector(lasd::Vector<int>&, unsigned long);

void popolaVector(lasd::Vector<double>&, unsigned long);

void popolaVector(lasd::Vector<string>&, unsigned long);

//list
template <typename Data>
void popolaList(lasd::List<Data>&, unsigned long);

void popolaList(lasd::List<int>&, unsigned long);

void popolaList(lasd::List<double>&, unsigned long);

void popolaList(lasd::List<string>&, unsigned long);

//Stack
template <typename Data>
void popolaStack(lasd::Stack<Data>&, unsigned long) ;

void popolaStack(lasd::Stack<int>&, unsigned long);

void popolaStack(lasd::Stack<double>&, unsigned long);

void popolaStack(lasd::Stack<string>&, unsigned long);

//Queue
template <typename Data>
void popolaQueue(lasd::Queue<Data>&, unsigned long);

void popolaQueue(lasd::Queue<int>&, unsigned long);

void popolaQueue(lasd::Queue<double>&, unsigned long);

void popolaQueue(lasd::Queue<string>&, unsigned long);

/***************************************************************/
//Operazioni
template <typename Data>
void funEmpty(lasd::LinearContainer<Data>&) {};

template <typename Data>
void funSize(lasd::LinearContainer<Data>&) {};

template <typename Data>
void funFront(lasd::LinearContainer<Data>&);

template <typename Data>
void funBack(lasd::LinearContainer<Data>&);

template <typename Data>
void funExists(lasd::LinearContainer<Data>&);

template <typename Data>
void funSort(lasd::SortableLinearContainer<Data>&);

template <typename Data>
void funPush(lasd::Stack<Data>&);

template <typename Data>
void funEnqueue(lasd::Queue<Data>&);

template <typename Data>
void funPop(lasd::Stack<Data>&);

template<typename Data>
void funDequeue(lasd::Queue<Data>&);

template <typename Data>
void funTop(lasd::Stack<Data>&);

template <typename Data>
void funHead(lasd::Queue<Data>&);

template <typename Data>
void funTopPop(lasd::Stack<Data>&);

template <typename Data>
void funHeadNDequeue(lasd::Queue<Data>&);

template <typename Data>
void funInsertD(lasd::DictionaryContainer<Data>&);

template <typename Data>
void funRemoveD(lasd::DictionaryContainer<Data>&);

template <typename Data>
void funInsertAtBack(lasd::List<Data>&);

template <typename Data>
void funInsertAtFront(lasd::List<Data>&);

template <typename Data>
void funFrontNRemove(lasd::List<Data>&);

template <typename Data>
vector<Data> generaDati(unsigned long) {};

vector<int> generaInt(unsigned long);

vector<double> generaDouble(unsigned long);

vector<string> generaString(unsigned long);

template <typename Data>
void Print(const Data& dat) {
  cout << dat << " ";
}

/* ************************************************************************** */

#endif