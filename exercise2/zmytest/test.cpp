#include "test.hpp"

using namespace std;

//Menu principale
void mytest() {
    cout << "\n\n######## Menù Principale #########" << endl;

    string alt = selezionaStrutturaAlbero();
    string tipo = selezionaDato();
    unsigned long dim = 0;
    if (alt == "3") {
        dim = selezionaDimensioneBST();
    } else {
        dim = selezionaDimensioneBT();
    }

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
            
        }
        else if(tipo == "2") {
            
        }
        else if(tipo == "3") {
            
        }
    }
    else if(alt == "3") {
        if(tipo == "1") {
        
        }
        else if(tipo == "2") {
            
        }
        else if(tipo == "3") {
            
        }
    }
    else if(alt == "4") {
        if(tipo == "1") {
            
        }
        else if(tipo == "2") {
            
        }
        else if(tipo == "3") {
            
        }
    }
    else if(alt == "5") {
        if(tipo == "1") {
            
        }
        else if(tipo == "2") {
            
        }
        else if(tipo == "3") {
            
        }
    }
    else if(alt == "6") {
            if(tipo == "1") {
            
        }
        else if(tipo == "2") {
            
        }
        else if(tipo == "3") {
            
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
        cout << "\n\n--------- Menù Binary Tree ---------" << endl;
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


//Menu Iteratori


//PreOrderIterator
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




//PostOrderIterator
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



//InOrderIterator
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



//BreadthIterator
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
        cout << "\nL'albero visitato in pre-order è: " << endl;
        bt.PreOrderTraverse(&Print<Data>);
        cout << endl << endl;   
}


//PrintPostOrder
template <typename Data>
void PrintPostOrder(lasd::BinaryTree<Data>& bt) {
        cout << "\nStampo l'albero in post-order: " << endl;
        bt.PostOrderTraverse(&Print<Data>);
        cout << endl << endl;  
}


//PrintInOrder
template <typename Data>
void PrintInOrder(lasd::BinaryTree<Data>& bt) {
        cout << "\nStampo l'albero in in-order: " << endl;
        bt.InOrderTraverse(&Print<Data>);
        cout << endl << endl;    
}


//PrintBreadth
template <typename Data>
void PrintBreadth(lasd::BinaryTree<Data>& bt) {
        cout << "\nStampo l'albero in ampiezza: " << endl;
        bt.BreadthTraverse(&Print<Data>);
        cout << endl << endl;     
}


//Funzioni Iterator


//FunPrintData   
template <typename Data>
void FunPrintData(lasd::Iterator<Data>& itr) {
    cout << "Indirizzo puntato dall'iteratore: " << &(*itr) << "\nDato contenuto: " << (*itr) << endl;
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

unsigned long selezionaDimensioneBST() {
    unsigned long dim = 0;
    cout << "\nInserisci la dimensione del BST: " << endl;
    bool riprova;
    do { 
        riprova = false;
        cin >> dim;
        if (dim > 100) {
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
        str = str + lettere[dist(generator)];
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
void PrintTree(typename lasd::MutableBinaryTree<Data>::MutableNode* root, int level, char childType) {
    if (root == nullptr) {
        throw length_error("L'albero è vuoto.");
    }

    if (level == 0) {
        cout << "\n\nStampa dell'albero: " << endl << endl ;
    }

    if (root != nullptr) {

        for (int i = 0; i < level; ++i)
            cout << "    ";

        cout << childType << "--> " << root->Element() << endl;
        if (root->HasLeftChild()) {
            PrintTree<Data>(&root->LeftChild(), level + 1, 'L');
        }

        if (root->HasRightChild()) {
            PrintTree<Data>(&root->RightChild(), level + 1, 'R');
        }
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
