#include "test.hpp"

using namespace std;

//Menu principale
void mytest() {
    cout << "\n\n-------- Menù Principale ---------" << endl;

    string alt = selezionaStrutturaAlbero();
    string tipo = selezionaDato();
    unsigned long dim = 0;
   
    dim = selezionaDimensioneBT();

    if (alt == "1") {
        if(tipo == "1") {
            lasd::List<int> list;
            PopolaBT(list, dim);
            lasd::BinaryTreeVec<int> bt(list);
            MenuBinaryTreeVec(bt,dim);

        }
        else if(tipo == "2") {
            lasd::List<double> list;
            PopolaBT(list, dim);
            lasd::BinaryTreeVec<double> bt(list);
            MenuBinaryTreeVec(bt,dim);
        }
        else if(tipo == "3") {
            lasd::List<string> list;
            PopolaBT(list, dim);
            lasd::BinaryTreeVec<string> bt(list);
            MenuBinaryTreeVec(bt,dim);
        }
    } else if(alt == "2") {
        if(tipo == "1") {
            lasd::List<int> list;
            PopolaBT(list, dim);
            lasd::BinaryTreeLnk<int> bt(list);
            MenuBinaryTreeLnk(bt,dim);
        }
        else if(tipo == "2") {
             lasd::List<double> list;
            PopolaBT(list, dim);
            lasd::BinaryTreeLnk<double> bt(list);
            MenuBinaryTreeLnk(bt,dim);
        }
        else if(tipo == "3") {
             lasd::List<string> list;
            PopolaBT(list, dim);
            lasd::BinaryTreeLnk<string> bt(list);
            MenuBinaryTreeLnk(bt,dim);
        }
    }
    else if(alt == "3") {
        if(tipo == "1") {
            lasd::BST<int> bst;
            PopolaBST(bst, dim);
            MenuBinarySearchTree(bst, dim); 
        }
        else if(tipo == "2") {
            lasd::BST<double> bst;
            PopolaBST(bst, dim);
            MenuBinarySearchTree(bst, dim); 
        }
        else if(tipo == "3") {
            lasd::BST<string> bst;
            PopolaBST(bst, dim);
            MenuBinarySearchTree(bst, dim);
        }
    }
}


/*************************************************************/
//Menu strutture

//BinaryTreeVec
template <typename Data>
void MenuBinaryTreeVec(lasd::BinaryTreeVec<Data>& bt,unsigned long dim) {
    char choice;
    
    while (true) {
        cout << "\n\n--------- Menù BinaryTreeVec ---------" << endl;
        cout << "1: Stampa     i: Info" << endl;
        cout << "2: Size" << endl;
        cout << "3: Empty" << endl;
        cout << "4: Root" << endl;
        cout << "5: Exists" << endl;
        cout << "6: Clear" << endl;
        cout << "a: Iterator PreOrder" << endl;
        cout << "b: Iterator PostOrder" << endl;
        cout << "c: Iterator InOrder" << endl;
        cout << "d: Iterator Breadth" << endl;

        cout << "0: Torna al menù principale" << endl;
        cout << "\nInserisci il numero corrispondente alla scelta: ";
        
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case '1': {
                try {
                    if (dim <= 100) {
                        PrintTree<Data>(&bt.Root(), 0, ' ');
                    } else {
                        cout << "\nLa dimensione dell'albero è troppo grande per permettere una visualizzazione godibile all'utente." << endl;
                    }
                } catch (length_error& e){
                    cout << e.what() << endl;
                }

                break;
            }
            case '2': {
                FunSize(bt);
                break;
            }
            case '3': {
                FunEmpty(bt);
                break;
            }
            case '4': {
                FunRoot(bt);
                break;
            }
            case '5': {
                FunExists(bt);
                break;
            }
            case '6': {
                FunClear(bt);
                break;
            }
            case 'a': {
                PrintPreOrder(bt);
                lasd::BTPreOrderIterator<Data> itr(bt);
                MenuPreOrderIterator(itr);
                break;
            }
            case 'b': {
                PrintPostOrder(bt);
                lasd::BTPostOrderIterator<Data> itr(bt);
                MenuPostOrderIterator(itr);
                break;
            }
            case 'c': {
                PrintInOrder(bt);
                lasd::BTInOrderIterator<Data> itr(bt);
                MenuInOrderIterator(itr);
                break;
            }
            case 'd': {
                PrintBreadth(bt);
                lasd::BTBreadthIterator<Data> itr(bt);
                MenuBreadthIterator(itr);
                break;
            }
            case '0': {
                return;
            }
            case 'i': {
                InfoStampa();
                break;
            }
            default: {
                cout << "\nValore non valido, riprova:" << endl;
                break;
            }
        }
    }
}

//Menu BinaryTreeLnk
template <typename Data>
void MenuBinaryTreeLnk(lasd::BinaryTreeLnk<Data>& bt,unsigned long dim) {
    char choice;
    
    while (true) {
        cout << "\n\n--------- Menù BinaryTreeLnk ---------" << endl;
        cout << "1: Stampa     i: Info" << endl;
        cout << "2: Size" << endl;
        cout << "3: Empty" << endl;
        cout << "4: Root" << endl;
        cout << "5: Exists" << endl;
        cout << "6: Clear" << endl;
        cout << "a: Iterator PreOrder" << endl;
        cout << "b: Iterator PostOrder" << endl;
        cout << "c: Iterator InOrder" << endl;
        cout << "d: Iterator Breadth" << endl;

        cout << "0: Torna al menù principale" << endl;
        cout << "\nInserisci il numero corrispondente alla scelta: ";
        
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case '1': {
                try {
                    if (dim <= 100) {
                        PrintTree<Data>(&bt.Root(), 0, ' ');
                    } else {
                        cout << "\nLa dimensione dell'albero è troppo grande per permettere una visualizzazione godibile all'utente." << endl;
                    }
                } catch (length_error& e){
                    cout << e.what() << endl;
                }

                break;
            }
            case '2': {
                FunSize(bt);
                break;
            }
            case '3': {
                FunEmpty(bt);
                break;
            }
            case '4': {
                FunRoot(bt);
                break;
            }
            case '5': {
                FunExists(bt);
                break;
            }
            case '6': {
                FunClear(bt);
                break;
            }
            case 'a': {
                PrintPreOrder(bt);
                lasd::BTPreOrderIterator<Data> itr(bt);
                MenuPreOrderIterator(itr);
                break;
            }
            case 'b': {
                PrintPostOrder(bt);
                lasd::BTPostOrderIterator<Data> itr(bt);
                MenuPostOrderIterator(itr);
                break;
            }
            case 'c': {
                PrintInOrder(bt);
                lasd::BTInOrderIterator<Data> itr(bt);
                MenuInOrderIterator(itr);
                break;
            }
            case 'd': {
                PrintBreadth(bt);
                lasd::BTBreadthIterator<Data> itr(bt);
                MenuBreadthIterator(itr);
                break;
            }
            case '0': {
                return;
            }
            case 'i': {
                InfoStampa();
                break;
            }
            default: {
                cout << "\nValore non valido, riprova:" << endl;
                break;
            }
        }
    }
}



//Menu BST
template <typename Data>
void MenuBinarySearchTree(lasd::BST<Data>& bst,unsigned long dim) {
    char choice;
    
    while (true) {
        cout << "\n\n--------- Menù BST ---------" << endl;
        cout << "1: Stampa  (*: Info)" << endl;
        cout << "2: Size              a: Max                        i: Successor&Remove" << endl;
        cout << "3: Empty             b: Remove Max                 j: Insert" << endl;
        cout << "4: Root              c: Max&Remove                 k: Remove" << endl;
        cout << "5: Exists            d: Predecessor                l: Iterator PreOrder" << endl;
        cout << "6: Clear             e: Remove Predecessor         m: Iterator PostOrder" << endl;
        cout << "7: Min               f: Predecessor&Remove         n: Iterator InOrder" << endl;
        cout << "8: Remove Min        g: Successor                  o: Iterator Breadth" << endl;
        cout << "9: Min&Remove        h: Remove Successor           " << endl << endl;
        
        cout << "0: Torna al menù principale" << endl;
        cout << "\nInserisci il carattere corrispondente alla scelta: ";
        
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case '1': {
                try {
                    if (dim <= 100) {
                        PrintTree<Data>(&bst.Root(), 0, ' ');
                    } else {
                        cout << "\nLa dimensione dell'albero è troppo grande per permettere una visualizzazione godibile all'utente." << endl;
                    }
                } catch (length_error& e){
                    cout << e.what() << endl;
                }

                break;
            }
            case '2': {
                FunSize(bst);
                break;
            }
            case '3': {
                FunEmpty(bst);
                break;
            }
            case '4': {
                FunRoot(bst);
                break;
            }
            case '5': {
                FunExists(bst);
                break;
            }
            case '6': {
                bst.Clear();
                cout << "\nAlbero svuotato con successo!" << endl;
                break;
            }
            case '7': {
                FunSearchMin(bst);
                break;
            }
            case '8': {
                FunRemoveMin(bst);
                break;
            }
            case '9': {
                FunSearchMinNRemove(bst);
                break;
            }
            case 'a': {
                FunSearchMax(bst);
                break;
            }
            case 'b': {
                FunRemoveMax(bst);
                break;
            }
            case 'c': {
                FunSearchMaxNRemove(bst);
                break;
            }
            case 'd': {
                FunSearchPredecessor(bst);
                break;
            }
            case 'e': {
                FunRemovePredecessor(bst);
                break;
            }
            case 'f': {
                FunSearchPredecessorNRemove(bst);
                break;
            }
            case 'g': {
                FunSearchSuccessor(bst);
                break;
            }
            case 'h': {
                FunRemoveSuccessor(bst);
                break;
            }
            case 'i': {
                FunSearchSuccessorNRemove(bst);
                break;
            }
            case 'j': {
                FunInsert(bst);
                break;
            }
            case 'k': {
                FunRemove(bst);
                break;
            }
            case 'l': {
                PrintPreOrder(bst);
                lasd::BTPreOrderIterator<Data> itr(bst);
                MenuPreOrderIterator(itr);
                break;
            }
            case 'm': {
                PrintPostOrder(bst);
                lasd::BTPostOrderIterator<Data> itr(bst);
                MenuPostOrderIterator(itr);
                break;
            }
            case 'n': {
                PrintInOrder(bst);
                lasd::BTInOrderIterator<Data> itr(bst);
                MenuInOrderIterator(itr);
                break;
            }
            case 'o': {
                PrintBreadth(bst);
                lasd::BTBreadthIterator<Data> itr(bst);
                MenuBreadthIterator(itr);
                break;
            }
            case '0': {
                return;
            }
            case '*': {
                InfoStampa();
                break;
            }
            default: {
                cout << "\nValore non valido, riprova:" << endl;
                break;
            }
        }
    }
}


//Menu Iteratori


//Menu PreOrderIterator
template <typename Data>
void MenuPreOrderIterator(lasd::BTPreOrderIterator<Data>& itr) {
    char choice;
    
    while (true) {
        cout << "\n\n--------- Menù Iterator Pre Order ---------" << endl;
        cout << "1: Visualizza dato" << endl;
        cout << "2: Avanza" << endl;
        cout << "3: Terminato" << endl;
        cout << "4: Reset" << endl;
        cout << "0: Torna indietro" << endl;
        cout << "\nInserisci il numero corrispondente alla scelta: ";
        
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case '1': {
                FunPrintData(itr);
                break;
            }
            case '2': {
                FunForwardIterator(itr);
                break;
            }
            case '3': {
                FunTerminatedIterator(itr);
                break;
            }
            case '4': {
                FunResetIterator(itr);
                break;
            }
            case '0': {
                return;
            }
            default: {
                cout << "\nValore non valido, riprova:" << endl;
                break;
            }
        }
    }
}




//Menu PostOrderIterator
template <typename Data>
void MenuPostOrderIterator(lasd::BTPostOrderIterator<Data>& itr) {
    char choice;
    
    while (true) {
        cout << "\n\n--------- Menù Iterator Post Order ---------" << endl;
        cout << "1: Visualizza dato" << endl;
        cout << "2: Avanza" << endl;
        cout << "3: Terminato" << endl;
        cout << "4: Reset" << endl;
        cout << "0: Torna indietro" << endl;
        cout << "\nInserisci il numero corrispondente alla scelta: ";
        
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case '1': {
                FunPrintData(itr);
                break;
            }
            case '2': {
                FunForwardIterator(itr);
                break;
            }
            case '3': {
                FunTerminatedIterator(itr);
                break;
            }
            case '4': {
                FunResetIterator(itr);
                break;
            }
            case '0': {
                return;
            }
            default: {
                cout << "\nValore non valido, riprova:" << endl;
                break;
            }
        }
    }
}



//Menu InOrderIterator
template <typename Data>
void MenuInOrderIterator(lasd::BTInOrderIterator<Data>& itr) {
    char choice;
    
    while (true) {
        cout << "\n\n--------- Menù Iterator In Order ---------" << endl;
        cout << "1: Visualizza dato" << endl;
        cout << "2: Avanza" << endl;
        cout << "3: Terminato" << endl;
        cout << "4: Reset" << endl;
        cout << "0: Torna indietro" << endl;
        cout << "\nInserisci il numero corrispondente alla scelta: ";
        
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case '1': {
                FunPrintData(itr);
                break;
            }
            case '2': {
                FunForwardIterator(itr);
                break;
            }
            case '3': {
                FunTerminatedIterator(itr);
                break;
            }
            case '4': {
                FunResetIterator(itr);
                break;
            }
            case '0': {
                return;
            }
            default: {
                cout << "\nValore non valido, riprova:" << endl;
                break;
            }
        }
    }
}



//Menu BreadthIterator
template <typename Data>
void MenuBreadthIterator(lasd::BTBreadthIterator<Data>& itr) {
    char choice;
    
    while (true) {
        cout << "\n\n--------- Menù Iterator Breadth ---------" << endl;
        cout << "1: Visualizza dato" << endl;
        cout << "2: Avanza" << endl;
        cout << "3: Terminato" << endl;
        cout << "4: Reset" << endl;
        cout << "0: Torna indietro" << endl;
        cout << "\nInserisci il numero corrispondente alla scelta: ";
        
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case '1': {
                FunPrintData(itr);
                break;
            }
            case '2': {
                FunForwardIterator(itr);
                break;
            }
            case '3': {
                FunTerminatedIterator(itr);
                break;
            }
            case '4': {
                FunResetIterator(itr);
                break;
            }
            case '0': {
                return;
            }
            default: {
                cout << "\nValore non valido, riprova:" << endl;
                break;
            }
        }
    }
}
/**************************************************************/
//Funzioni


//FunRoot
template <typename Data>
void FunRoot(lasd::BinaryTree<Data>& bt) {
    try {
        cout << "\nLa radice dell'albero è: " << bt.Root().Element() << endl;
    } catch (length_error& e) {
        cout << e.what() << endl;
    }
}


//FunEmpty
template <typename Data>
void FunEmpty(lasd::BinaryTree<Data>& bt) {
    bool var = bt.Empty();
    cout << "\nL'Albero " << ((var) ? "è vuoto" : "non è vuoto")  << endl;
}


//FunClear
template <typename Data>
void FunClear(lasd::MutableBinaryTree<Data>& bt) {
    bt.Clear();
    cout << "\nAlbero svuotato con successo !" << endl;
}


//FunSize
template <typename Data>
void FunSize(lasd::BinaryTree<Data>& bt) {
    cout << "\nLa size dell'albero è: " << bt.Size() << endl;  
}


//FunExists
template <typename Data>
void FunExists(lasd::BinaryTree<Data>& bt) {
    char ans;
    if (bt.Size() == 0) {
        cout << "\n\nL'albero è vuoto, non è possibile cercare elementi!";
        return;
    }

    do {
        cout << "\nInserisci il valore da cercare: ";
        Data data;
        
        cin >> data;
        
        cout << (bt.Exists(data) ? "L'elemento è nel container." : "L'elemento non è nel container.") << endl;
        
        cout << "Vuoi cercare un altro elemento? [y/altro]: ";
        cin >> ans;
    } while (tolower(ans) == 'y');
}


//PrintPreOrder
template <typename Data>
void PrintPreOrder(lasd::BinaryTree<Data>& bt) {
    try {
        cout << "\nL'albero visitato in pre-order è: " << endl;
        bt.PreOrderTraverse(&Print<Data>);
        cout << endl << endl;   
    } catch (length_error& e) {
        cout << endl << e.what() << endl;
    }
}


//PrintPostOrder
template <typename Data>
void PrintPostOrder(lasd::BinaryTree<Data>& bt) {
    try {
        cout << "\nStampo l'albero in post-order: " << endl;
        bt.PostOrderTraverse(&Print<Data>);
        cout << endl << endl;  
    } catch (length_error& e) {
        cout << endl << e.what() << endl;
    }
}


//PrintInOrder
template <typename Data>
void PrintInOrder(lasd::BinaryTree<Data>& bt) {
    try {
        cout << "\nStampo l'albero in in-order: " << endl;
        bt.InOrderTraverse(&Print<Data>);
        cout << endl << endl;    
    } catch (length_error& e) {
        cout << endl << e.what() << endl;
    }
}


//PrintBreadth
template <typename Data>
void PrintBreadth(lasd::BinaryTree<Data>& bt) {
    try {
        cout << "\nStampo l'albero in ampiezza: " << endl;
        bt.BreadthTraverse(&Print<Data>);
        cout << endl << endl;     
    } catch (length_error& e) {
        cout << endl << e.what() << endl;
    }
}


//FunSearchMin
template <typename Data>
void FunSearchMin(lasd::BST<Data>& bst) {
    try {
        cout << "\nIl minimo del BST è: " << bst.Min() << endl;
    } catch (length_error& e) {
        cout << endl << e.what() << endl;
    }
}


//FunRemoveMin
template <typename Data>
void FunRemoveMin(lasd::BST<Data>& bst) {
    try {
        bst.RemoveMin();
        cout << "\nMinimo rimosso con successo !"  << endl;
        cout << "Il nuovo minimo del BST è: " << bst.Min() << endl;
    } catch (length_error& e) {
        cout << endl << e.what() << endl;
    }
}


//FunSearchMinNRemove
template <typename Data>
void FunSearchMinNRemove(lasd::BST<Data>& bst) {
    try {
        cout << "Il minimo del BST: " << bst.MinNRemove() << " è stato rimosso con successo !" << endl;
        cout << "Il nuovo minimo del BST è: " << bst.Min() << endl;
    } catch (length_error& e) {
        cout << endl << e.what() << endl;
    }
}


//FunSearchMax
template <typename Data>
void FunSearchMax(lasd::BST<Data>& bst) {
    try {
        cout << "\nIl massimo del BST è: " << bst.Max() << endl;
    } catch (length_error& e) {
        cout << endl << e.what() << endl;
    }
}


//FunRemoveMax
template <typename Data>
void FunRemoveMax(lasd::BST<Data>& bst) {
    try {
        bst.RemoveMax();
        cout << "\nMassimo rimosso con successo !"  << endl;
        cout << "Il nuovo massimo del BST è: " << bst.Max() << endl;
    } catch (length_error& e) {
        cout << endl << e.what() << endl;
    }
}


//FunSearchMaxNRemove
template <typename Data>
void FunSearchMaxNRemove(lasd::BST<Data>& bst) {
    try {
        cout << "Il massimo del BST: " << bst.MaxNRemove() << " è stato rimosso con successo !" << endl;
        cout << "Il nuovo massimo del BST è: " << bst.Max() << endl;
    } catch (length_error& e) {
        cout << endl << e.what() << endl;
    }
}


//FunSearchPredecessor
template <typename Data>
void FunSearchPredecessor(lasd::BST<Data>& bst) {
    char ans;
    do {
        try {
            cout << "\nInserisci il valore per cui vuoi cercare il predecessore: ";
            Data val;
            
            cin >> val;
            
            cout << "Il predecessore di " << val << " è: " << bst.Predecessor(val) << endl;
        } catch (length_error& e) {
            cout << endl << e.what() << endl;
        }
        
        cout << "Vuoi cercare un altro elemento? [y/altro]: ";
        cin >> ans;
    } while (tolower(ans) == 'y');
}


//FunSearchSuccessor
template <typename Data>
void FunSearchSuccessor(lasd::BST<Data>& bst) {
    char ans;
    do {
        try {
            cout << "\nInserisci il valore per cui vuoi cercare il successore: ";
            Data val;
            
            cin >> val;
            
            cout << "Il successore di " << val << " è: " << bst.Successor(val) << endl;
        } catch (length_error& e) {
            cout << endl << e.what() << endl;
        }
        
        cout << "Vuoi cercare un altro elemento? [y/altro]: ";
        cin >> ans;
    } while (tolower(ans) == 'y');
}



//FunRemovePredecessor
template <typename Data>
void FunRemovePredecessor(lasd::BST<Data>& bst) {
    char ans;
    do {
        try {
            cout << "\nInserisci il valore per cui vuoi eliminare il predecessore: ";
            Data val;
            
            cin >> val;
            
            bst.RemovePredecessor(val);
            cout << "Il predecessore di " << val << " è stato eliminato con successo !" << endl;
        } catch (length_error& e) {
            cout << endl << e.what() << endl;
        }
        
        cout << "Vuoi eliminare un altro elemento? [y/altro]: ";
        cin >> ans;
    } while (tolower(ans) == 'y');
}



//FunRemoveSuccessor
template <typename Data>
void FunRemoveSuccessor(lasd::BST<Data>& bst) {
    char ans;
    do {
        try {
            cout << "\nInserisci il valore per cui vuoi eliminare il successore: ";
            Data val;
            
            cin >> val;

            bst.RemoveSuccessor(val);
            cout << "Il successore di " << val << " è stato eliminato con successo !" << endl;
        } catch (length_error& e) {
            cout << endl << e.what() << endl;
        }
        
        cout << "Vuoi eliminare un altro elemento? [y/altro]: ";
        cin >> ans;
    } while (tolower(ans) == 'y');
}


//FunSearchPredecessorNRemove
template <typename Data>
void FunSearchPredecessorNRemove(lasd::BST<Data>& bst) {
    char ans;
    do {
        try {
            cout << "\nInserisci il valore per cui vuoi eliminare il predecessore: ";
            Data val;
            
            cin >> val;
            
            cout << "Il predecessore di " << val << " è:" << bst.PredecessorNRemove(val) << endl;
            cout << "Il predecessore è stato rimosso con successo!" << endl; 
        } catch (length_error& e) {
            cout << endl << e.what() << endl;
        }
        
        cout << "Vuoi eliminare un altro elemento? [y/altro]: ";
        cin >> ans;
    } while (tolower(ans) == 'y');
}


//FunSearchSuccessorNRemove
template <typename Data>
void FunSearchSuccessorNRemove(lasd::BST<Data>& bst) {
    char ans;
    do {
        try {
            cout << "\nInserisci il valore per cui vuoi eliminare il successore: ";
            Data val;
            
            cin >> val;
            
            cout << "Il successore di " << val << " è:" << bst.SuccessorNRemove(val) << endl;
            cout << "Il successore è stato rimosso con successo!" << endl; 
        } catch (length_error& e) {
            cout << endl << e.what() << endl;
        }
        
        cout << "Vuoi eliminare un altro elemento? [y/altro]: ";
        cin >> ans;
    } while (tolower(ans) == 'y');
}


//FunInsert
template <typename Data>
void FunInsert(lasd::BST<Data>& bst) {
    char ans;
    do {
        cout << "\nInserisci il valore che vuoi inserire nel BST: ";
        Data val;
            
        cin >> val;
            
        cout << ((bst.Insert(val)) ? "\nValore inserito con successo !" : "\nValore non inserito !") << endl;
        
        cout << "Vuoi inserire un altro elemento? [y/altro]: ";

        cin >> ans;
    } while (tolower(ans) == 'y');      
}


//FunRemove
//Insert
template <typename Data>
void FunRemove(lasd::BST<Data>& bst) {
    char ans;
    do {
        cout << "\nInserisci il valore che vuoi eliminare nel BST: ";
        Data val;
            
        cin >> val;
            
        cout << ((bst.Remove(val)) ? "\nValore eliminato con successo !" : "\nValore non eliminato !") << endl;
        
        cout << "Vuoi eliminare un altro elemento? [y/altro]: ";

        cin >> ans;
    } while (tolower(ans) == 'y');      
}

/***********************************************************************************/
//Funzioni Iterator


//FunPrintData   
template <typename Data>
void FunPrintData(lasd::Iterator<Data>& itr) {
    try {
        cout << "Indirizzo puntato dall'iteratore: " << &(*itr) << "\nDato contenuto: " << (*itr) << endl;
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }
}

template <typename Data>
void FunTerminatedIterator(lasd::ForwardIterator<Data>& itr) {
    if (itr.Terminated()) {
        cout << "\nL'iteratore è terminato." << endl;
    } else {
        cout << "\nL'iteratore non è terminato." << endl;
    }
    
}


template <typename Data>
void FunResetIterator(lasd::ResettableIterator<Data>& itr) { 
        itr.Reset();
        cout << "\nIteratore resettato con successo!" << endl;
        FunPrintData(itr);
}

template <typename Data>
void FunForwardIterator(lasd::ForwardIterator<Data>& itr) {
        try {
            ++itr;
            cout << "\nIteratore avanzato con successo!" << endl;
            FunPrintData(itr);
        } catch(out_of_range& e) {
            cout << e.what() << endl;
        }
}
/*******************************************************************/

string selezionaStrutturaAlbero() {
    cout << "Scegli il tipo di struttura dati:" << endl;
    cout << "1: BinaryTreeVec" << endl;
    cout << "2: BinaryTreeLnk" << endl;
    cout << "3: BST" << endl;
    cout << "\nInserisci il numero corrispondente alla scelta: ";

    string scelta;
    bool sceltaValida = false;

    while (!sceltaValida) {
        getline(cin, scelta);

        if (scelta == "1" || scelta == "2" || scelta == "3") {
            sceltaValida = true;
        } else {
            cout << "\nValore non valido, riprova: ";
        }
    }
    return scelta;
}

string selezionaDato() {
    cout << "Scegli il tipo di dati:" << endl;
    cout << "1: int" << endl;
    cout << "2: double" << endl;
    cout << "3: string" << endl;
    cout << "\nInserisci un numero per selezionare: ";

    string scelta;
    bool sceltaValida = false;

    while (!sceltaValida) {
        getline(cin, scelta);

        if (scelta == "1" || scelta == "2" || scelta == "3") {
            sceltaValida = true;
        } else {
            cout << "\nValore non valido, riprova: ";
        }
    }
    return scelta;
}


unsigned long selezionaDimensioneBT() {
    unsigned long dim = 0;
    cout << "\nInserisci la dimensione dell'albero binario: " << endl;
    bool riprova;
    do { 
        riprova = false;
        cin >> dim;
        if (dim > 50000) {
            cout << "\n\nDimensione troppo grande, riprova !\n";
            riprova = true;
        }
    } while (riprova == true);
   
    return dim;    
}

/******************************************************/

//Generatori
vector<int> generaInt(unsigned long dim) {
    vector<int> vec(dim);

    default_random_engine generator(random_device{}());
    uniform_int_distribution<int> dist(0, 100);


    for(unsigned long i = 0; i<dim; i++) {
        vec[i] = dist(generator);
    }
    cout << "\nGenerazione casuale per il popolamento della struttura completata !\n" << endl;
    return vec;
}

vector<double> generaDouble(unsigned long dim) {
    vector<double> vector(dim);

    default_random_engine generator(random_device{}());
    uniform_real_distribution<double> dist(0.0, 100.0);


    for(unsigned long i = 0; i<dim; i++) {
        vector[i] = dist(generator);
    }
    cout << "\nGenerazione casuale per il popolamento della struttura completata !\n" << endl;
    return vector;
}

vector<string> generaString(unsigned long dim) {
    vector<string> vec(dim);    

    char lettere[52] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                         'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    default_random_engine generator(random_device{}());
    uniform_int_distribution<int> dist(0, 51);

    for(unsigned long i = 0; i<dim; i++) {
        string str = "";
        for (int j = 0; j < 3; j++) {
            str += lettere[dist(generator)];
        }
        vec[i]=str;
    }
    cout << "\nGenerazione casuale per il popolamento della struttura completata !\n" << endl;
    return vec;
}




/******************************************************/

//Popolamento

//List
void PopolaBT(lasd::List<int>& list, unsigned long dim) {
    std::vector<int> generatedValues = generaInt(dim);
    for(unsigned int i = 0; i < dim; ++i) {
        list.InsertAtBack(generatedValues[i]);
    }
}


void PopolaBT(lasd::List<double>& list, unsigned long dim) {
    std::vector<double> generatedValues = generaDouble(dim);
    for(unsigned int i = 0; i < dim; ++i) {
        list.InsertAtBack(generatedValues[i]);
    }
}


void PopolaBT(lasd::List<string>& list, unsigned long dim) {
    std::vector<string> generatedValues = generaString(dim);
    for(unsigned int i = 0; i < dim; ++i) {
        list.InsertAtBack(generatedValues[i]);
    }
}



//BST
void PopolaBST(lasd::BST<int>& bst,unsigned long dim) {
    std::vector<int> generatedValues = generaInt(dim);
    for(unsigned long i = 0; i < dim; i++) {
            bst.Insert(generatedValues[i]);
    }
}



void PopolaBST(lasd::BST<double>& bst, unsigned long dim) {
    std::vector<double> generatedValues = generaDouble(dim);
    for (unsigned long i = 0; i < dim; i++) {
        bst.Insert(generatedValues[i]);
    }
}


void PopolaBST(lasd::BST<std::string>& bst, unsigned long dim) {
    std::vector<std::string> generatedValues = generaString(dim);
    for (unsigned long i = 0; i < dim; i++) {
        bst.Insert(generatedValues[i]);
    }
}


/********************************************************************************/
//PrintTree
template <typename Data>
void PrintTree(const typename lasd::BinaryTree<Data>::Node* root, int level, char childType) {
    if (root == nullptr) {
        throw length_error("L'albero è vuoto!");
    }

    if (level == 0) {
        cout << "\n\nStampa dell'albero: " << endl << endl ;
    }

    
    for (int i = 0; i < level; ++i) {
        cout << "    ";
    }

    cout << childType << "--> " << root->Element() << endl;
    if (root->HasLeftChild()) {
        PrintTree<Data>(&root->LeftChild(), level + 1, 'L');
    }

    if (root->HasRightChild()) {
        PrintTree<Data>(&root->RightChild(), level + 1, 'R');
    }

}


void InfoStampa() {
    cout << "\nLa funzione di stampa organizza i livelli dell'albero,partendo dalla radice" << endl;
    cout << "da sinistra verso destra con uno 'shift'." << endl;
    cout << "Esempio: \n";
    cout << "       7      " << endl;
    cout << "      / \\    " << endl;
    cout << "     5   8    " << endl;
    cout << "    /         " << endl;
    cout << "   2          " << endl << endl;
    cout << "Stampa:       " << endl;
    cout << "--> 7         " << endl;
    cout << "    L --> 5   " << endl;
    cout << "          L --> 2    " << endl;
    cout << "    R --> 8   " << endl;
}

/********************************************************************************/
