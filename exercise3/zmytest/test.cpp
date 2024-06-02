#include "test.hpp"

using namespace std;

//Menu principale
void mytest() {
    cout << "\n\n-------- Menù Principale ---------" << endl;

    string alt = SelezionaHashTable();
    string tipo = SelezionaDato();

    unsigned long dim;
    dim = SelezionaDimensioneHT();
    
    if (alt == "1") {
        if(tipo == "1") {
            lasd::HashTableClsAdr<int> ht;
            MenuHashTableClsAdr(ht, dim);
        }
        else if(tipo == "2") {
            lasd::HashTableClsAdr<double> ht;
            MenuHashTableClsAdr(ht, dim); 
        }
        else if(tipo == "3") {
            lasd::HashTableClsAdr<string> ht;
            MenuHashTableClsAdr(ht, dim); 
        }
    } else if(alt == "2") {
        if(tipo == "1") {
            lasd::HashTableOpnAdr<int> ht;
            MenuHashTableOpnAdr(ht, dim); 
        }
        else if(tipo == "2") {
            lasd::HashTableOpnAdr<double> ht;
            MenuHashTableOpnAdr(ht, dim); 
        }
        else if(tipo == "3") {
            lasd::HashTableOpnAdr<string> ht;
            MenuHashTableOpnAdr(ht, dim);
        }
    }
}


/*************************************************************/
//Menu strutture

//HashTableClsAdr
template <typename Data>
void MenuHashTableClsAdr(lasd::HashTableClsAdr<Data>& ht, unsigned long dim) {
    char choice;
    
    while (true) {
        cout << "\n\n--------- Menù HashTableClsAdr ---------" << endl;
        cout << "1: Size" << endl;
        cout << "2: Empty" << endl;
        cout << "3: Exists" << endl;
        cout << "4: Clear" << endl;
        cout << "5: Insert" << endl;
        cout << "6: Remove" << endl;
        cout << "7: Popola" << endl;
        cout << "0: Torna al menù principale" << endl;
        cout << "\nInserisci il numero corrispondente alla scelta: ";
        
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case '1': {
                FuncSize(ht);
                break;
            }
            case '2': {
                FuncEmpty(ht);
                break;
            }
            case '3': {
                FuncExists(ht);
                break;
            }
            case '4': {
                FuncClear(ht);
                break;
            }
            case '5': {
                FuncInsertDictionary(ht);
                break;
            }
            case '6': {
                FuncRemoveDictionary(ht);
                break;
            }
            case '7': {
                PopolaHashTableClsAdr(ht,dim);
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



//HashTableOpnAdr
template <typename Data>
void MenuHashTableOpnAdr(lasd::HashTableOpnAdr<Data>& ht, unsigned long dim) {
    char choice;
    
    while (true) {
        cout << "\n\n--------- Menù HashTableOpnAdr ---------" << endl;
        cout << "1: Size" << endl;
        cout << "2: Empty" << endl;
        cout << "3: Exists" << endl;
        cout << "4: Clear" << endl;
        cout << "5: Insert" << endl;
        cout << "6: Remove" << endl;
        cout << "7: Popola" << endl;
        cout << "0: Torna al menù principale" << endl;
        cout << "\nInserisci il numero corrispondente alla scelta: ";
        
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case '1': {
                FuncSize(ht);
                break;
            }
            case '2': {
                FuncEmpty(ht);
                break;
            }
            case '3': {
                FuncExists(ht);
                break;
            }
            case '4': {
                FuncClear(ht);
                break;
            }
            case '5': {
                FuncInsertDictionary(ht);
                break;
            }
            case '6': {
                FuncRemoveDictionary(ht);
                break;
            }
            case '7': {
                PopolaHashTableOpnAdr(ht,dim);
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

//FuncEmpty
template <typename Data>
void FuncEmpty(lasd::HashTable<Data>& ht) {
    bool var = ht.Empty();
    cout << "\nL'HashTable " << ((var) ? "è vuota" : "non è vuota")  << endl;
}



//FuncClear
template <typename Data>
void FuncClear(lasd::HashTable<Data>& ht) {
    ht.Clear();
    cout << "\nHashTable svuotata con successo!" << endl;
}


//FuncSize
template <typename Data>
void FuncSize(lasd::HashTable<Data>& ht) {
    cout << "\nLa size dell'HashTable è: " << ht.Size() << endl;  
}


//FuncResize
template <typename Data>
void FuncResize(lasd::HashTable<Data>& ht) {
    unsigned long val;
    cout << "\nInserisci una nuova dimensione per l'HashTable: " << endl;
    cin >> val;
    ht.Resize(val);
    cout << "\nResize effettuata con successo!" << endl;
}



//FuncExists
template <typename Data>
void FuncExists(lasd::HashTable<Data>& ht) {
    char ans;
    if (ht.Size() == 0) {
        cout << "\n\nL'HashTable è vuota, non è possibile cercare elementi!";
        return;
    }

    do {
        cout << "\nInserisci il valore da cercare: ";
        Data data;
        
        cin >> data;
        
        cout << (ht.Exists(data) ? "L'elemento è nel container." : "L'elemento non è nel container.") << endl;
        
        cout << "Vuoi cercare un altro elemento? [y/altro]: ";
        cin >> ans;
    } while (tolower(ans) == 'y');
}



//FuncInsert
template <typename Data>
void FuncInsertDictionary(lasd::HashTable<Data>& ht) {
    char ans;
    do {
        cout << "\nInserisci il valore che vuoi inserire nell'HashTable: ";
        Data val;
            
        cin >> val;
            
        cout << ((ht.Insert(val)) ? "\nValore inserito con successo !" : "\nValore non inserito !") << endl;
        
        cout << "Vuoi inserire un altro elemento? [y/altro]: ";

        cin >> ans;
    } while (tolower(ans) == 'y');      
}


//FuncRemove
template <typename Data>
void FuncRemoveDictionary(lasd::HashTable<Data>& ht) {
    char ans;
    do {
        cout << "\nInserisci il valore che vuoi eliminare nell'HashTable: ";
        Data val;
            
        cin >> val;
            
        cout << ((ht.Remove(val)) ? "\nValore eliminato con successo !" : "\nValore non eliminato !") << endl;
        
        cout << "Vuoi eliminare un altro elemento? [y/altro]: ";

        cin >> ans;
    } while (tolower(ans) == 'y');      
}

/*******************************************************************/

string SelezionaHashTable() {
    cout << "Scegli il tipo di struttura dati:" << endl;
    cout << "1: HashTableClsAdr" << endl;
    cout << "2: HashTableOpnAdr" << endl;
    cout << "\nInserisci il numero corrispondente alla scelta: ";

    string scelta;
    bool sceltaValida = false;

    while (!sceltaValida) {
        getline(cin, scelta);

        if (scelta == "1" || scelta == "2") {
            sceltaValida = true;
        } else {
            cout << "\nValore non valido, riprova: ";
        }
    }
    return scelta;
}

string SelezionaDato() {
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

unsigned long SelezionaDimensioneHT() {
    unsigned long dim = 0;
    cout << "\nInserisci la dimensione dell'HashTable: " << endl;
    bool riprova;
    do { 
        riprova = false;
        cin >> dim;
        if (dim > 1000000) {
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
    uniform_int_distribution<int> dist(0, 100000);


    for(unsigned long i = 0; i<dim; i++) {
        vec[i] = dist(generator);
    }
    cout << "\nGenerazione casuale per il popolamento della struttura completata !\n" << endl;
    return vec;
}

vector<double> generaDouble(unsigned long dim) {
    vector<double> vector(dim);

    default_random_engine generator(random_device{}());
    uniform_real_distribution<double> dist(0.0, 1000.0);


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
void PopolaHashTableClsAdr(lasd::HashTableClsAdr<int>& ht, unsigned long dim) {
    std::vector<int> generatedValues = generaInt(dim);
    for(unsigned long i = 0 ; i < dim ; i++) {
        ht.Insert(generatedValues[i]);
    }
}



void PopolaHashTableClsAdr(lasd::HashTableClsAdr<double>& ht, unsigned long dim) {
    std::vector<double> generatedValues = generaDouble(dim);
    for(unsigned long i = 0 ; i < dim ; i++) {
        ht.Insert(generatedValues[i]);
    }
}



void PopolaHashTableClsAdr(lasd::HashTableClsAdr<string>& ht, unsigned long dim) {
    std::vector<string> generatedValues = generaString(dim);
    for(unsigned long i = 0 ; i < dim ; i++) {
        ht.Insert(generatedValues[i]);
    }
}



void PopolaHashTableOpnAdr(lasd::HashTableOpnAdr<int>& ht, unsigned long dim) {
    std::vector<int> generatedValues = generaInt(dim);
    for(unsigned long i = 0 ; i < dim ; i++) {
        ht.Insert(generatedValues[i]);
    }
}



void PopolaHashTableOpnAdr(lasd::HashTableOpnAdr<double>& ht, unsigned long dim) {
    std::vector<double> generatedValues = generaDouble(dim);
    for(unsigned long i = 0 ; i < dim ; i++) {
        ht.Insert(generatedValues[i]);
    }
}



void PopolaHashTableOpnAdr(lasd::HashTableOpnAdr<string>& ht, unsigned long dim) {
    std::vector<string> generatedValues = generaString(dim);
    for(unsigned long i = 0 ; i < dim ; i++) {
        ht.Insert(generatedValues[i]);
    }
}



/********************************************************************************/
