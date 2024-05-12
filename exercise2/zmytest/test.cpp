#include "test.hpp"

using namespace std;

//Menu principale
void mytest() {
    cout << "\n\n######## Menù Principale #########" << endl;

    string alt = selezionaStrutturaAlbero();
    string tipo = selezionaDato();
    unsigned long dim = selezionaDimensioneBT();

    if(alt == "1") {
        if(tipo == "1") {
            lasd::List<int> list;
            PopolaList(list, dim);
            lasd::BinaryTreeVec<int> bt(list);
            MenuBinaryTreeVec(bt);

        }
        else if(tipo == "2") {
            lasd::List<double> list;
            PopolaList(list, dim);
            lasd::BinaryTreeVec<double> bt(list);
            MenuBinaryTreeVec(bt);
        }
        else if(tipo == "3") {
            lasd::List<string> list;
            PopolaList(list, dim);
            lasd::BinaryTreeVec<string> bt(list);
            MenuBinaryTreeVec(bt);
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
void MenuBinaryTreeVec(lasd::BinaryTreeVec<Data>& bt) {
    char choice;
    
    while (true) {
        cout << "\n\n######## Menù Binary Tree ########" << endl;
        cout << "1: Stampa     i: Info" << endl;
        cout << "2: Size" << endl;
        cout << "3: Empty" << endl;
        cout << "4: Root" << endl;
        cout << "5: Exists" << endl;
        cout << "6: Clear" << endl;
        cout << "7: Visita in PreOrder" << endl;
        cout << "8: Visita in PostOrder" << endl;
        cout << "9: Visita in InOrder" << endl;
        cout << "a: Visita Breadth" << endl;
        cout << "b: Menu iteratori" << endl;
        cout << "0: Torna al menù principale" << endl;
        cout << "\nInserisci il numero corrispondente alla scelta: ";
        
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case '1': {
                try {
                    PrintTree<Data>(&bt.Root(), 0, ' ');
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
                // Chiamata alla funzione per verificare se un elemento esiste nell'albero
                // Esegui qui la chiamata alla funzione per verificare l'esistenza di un elemento
                break;
            }
            case '6': {
                FunClear(bt);
                break;
            }
            case '7': {
                // Chiamata alla funzione per la visita in preordine
                // Esegui qui la chiamata alla funzione per la visita in preordine
                break;
            }
            case '8': {
                // Chiamata alla funzione per la visita in postordine
                // Esegui qui la chiamata alla funzione per la visita in postordine
                break;
            }
            case '9': {
                // Chiamata alla funzione per la visita in ordine
                // Esegui qui la chiamata alla funzione per la visita in ordine
                break;
            }
            case 'a': {
                // Chiamata alla funzione per la visita in ampiezza
                // Esegui qui la chiamata alla funzione per la visita in ampiezza
                break;
            }
            case 'b': {
                // Chiamata al menù degli iteratori
                // Esegui qui la chiamata al menù degli iteratori
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


unsigned long selezionaDimensione() {
    unsigned long dim = 0;
    cout << "\nInserisci la dimensione della struttura scelta: " << endl;
    bool riprova = false;
    do { 
        cin >> dim;
        if (dim > 50000) {
            cout << "\n\nDimensione troppo grande, riprova !\n";
        }
    } while (riprova == true);
   
    return dim;    
}

unsigned long selezionaDimensioneBT() {
    unsigned long dim = 0;
    cout << "\nInserisci la dimensione dell'albero: " << endl;
    bool riprova = false;
    do { 
        cin >> dim;
        if (dim > 100) {
            cout << "\n\nDimensione troppo grande, riprova !\n";
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
void PopolaList(lasd::List<int>& list, unsigned long dim) {
    std::vector<int> generatedValues = generaInt(dim);
    for(unsigned int i = 0; i < dim; ++i) {
        list.InsertAtBack(generatedValues[i]);
    }
}


void PopolaList(lasd::List<double>& list, unsigned long dim) {
    std::vector<double> generatedValues = generaDouble(dim);
    for(unsigned int i = 0; i < dim; ++i) {
        list.InsertAtBack(generatedValues[i]);
    }
}


void PopolaList(lasd::List<string>& list, unsigned long dim) {
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
