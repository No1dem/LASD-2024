#include "test.hpp"

#include <iostream>
#include <random>
#include <string>

using namespace std;

//Menu principale
void mytest() {
    cout << "\n\n######## Menù Principale #########" << endl;

    string alt = selezionaStruttura();
    string tipo = selezionaDato();
    unsigned long dim = selezionaDimensione();

    if(alt == "1") {
        if(tipo == "1") {
            lasd::Vector<int> vector(dim);
            popolaVector(vector, dim);
            menuVector(vector);

        }
        else if(tipo == "2") {
            lasd::Vector<double> vector(dim);
            popolaVector(vector, dim);
            menuVector(vector);
        }
        else if(tipo == "3") {
            lasd::Vector<string> vector(dim);
            popolaVector(vector, dim);
            menuVector(vector);
        }
    } else if(alt == "2") {
        if(tipo == "1") {
            lasd::List<int> list;
            popolaList(list, dim);
            menuList(list);
        }
        else if(tipo == "2") {
            lasd::List<double> list;
            popolaList(list, dim);
            menuList(list);
        }
        else if(tipo == "3") {
            lasd::List<string> list;
            popolaList(list, dim);
            menuList(list);
        }
    }
    else if(alt == "3") {
        if(tipo == "1") {
            lasd::StackVec<int> stack;
            popolaStack(stack, dim);
            menuStack(stack);
        }
        else if(tipo == "2") {
            lasd::StackVec<double> stack;
            popolaStack(stack, dim);
            menuStack(stack);
        }
        else if(tipo == "3") {
            lasd::StackVec<string> stack;
            popolaStack(stack, dim);
            menuStack(stack);
        }
    }
    else if(alt == "4") {
        if(tipo == "1") {
            lasd::StackLst<int> stack;
            popolaStack(stack, dim);
            menuStack(stack);
        }
        else if(tipo == "2") {
            lasd::StackLst<double> stack;
            popolaStack(stack, dim);
            menuStack(stack);
        }
        else if(tipo == "3") {
            lasd::StackLst<std::string> stack;
            popolaStack(stack, dim);
            menuStack(stack);
        }
    }
    else if(alt == "5") {
        if(tipo == "1") {
            lasd::QueueVec<int> queue;
            popolaQueue(queue, dim);
            menuQueue(queue);
        }
        else if(tipo == "2") {
            lasd::QueueVec<double> queue;
            popolaQueue(queue, dim);
            menuQueue(queue);
        }
        else if(tipo == "3") {
            lasd::QueueVec<string> queue;
            popolaQueue(queue, dim);
            menuQueue(queue);
        }
    }
    else if(alt == "6") {
            if(tipo == "1") {
            lasd::QueueLst<int> queue;
            popolaQueue(queue, dim);
            menuQueue(queue);
        }
        else if(tipo == "2") {
            lasd::QueueLst<double> queue;
            popolaQueue(queue, dim);
            menuQueue(queue);
        }
        else if(tipo == "3") {
            lasd::QueueLst<string> queue;
            popolaQueue(queue, dim);
            menuQueue(queue);
        } 
    }
}


/*************************************************************/

//Stack Menù
template <typename Data>
void menuStack(lasd::Stack<Data>& stack) {
    char alt;
    
    while (true) {
        cout << "\n\n######## Menù Stack ########" << endl;
        cout << "1: Size" << endl;
        cout << "2: Clear" << endl;
        cout << "3: Empty" << endl;
        cout << "4: Push" << endl;
        cout << "5: Pop" << endl;
        cout << "6: Top" << endl;
        cout << "7: TopNPop" << endl;
        cout << "0: Torna al menù principale" << endl;
        cout << "\nInserisci il numero corrispondente alla scelta: ";
        cout << "\n\n";
        
        cin >> alt;
        cin.ignore();
        
        switch (alt) {
            case '1': {
                cout << "\nLa size dello stack è: " << stack.Size() << endl;
                break;
            }
            case '2': {
                stack.Clear();
                cout << "\nStack svuotato con successo !" << endl;
                break;
            }
            case '3': {
                bool isEmpty = stack.Empty();
                cout << "\nLo Stack " << (isEmpty ? "è vuoto" : "non è vuoto") << endl;
                break;
            }
            case '4': {
                funPush(stack);
                break;
            }
            case '5': {
                funPop(stack);
                break;
            }
            case '6': {
                funTop(stack);
                break;
            }
            case '7': {
                funTopPop(stack);
                break;
            }
            case '0': {
                stack.Clear();
                return;
            }
            default: {
                cout << "\nValore non valido, riprova:" << endl;
                break;
            }
        }
    }
}




//List Menù
template <typename Data>
void menuList(lasd::List<Data>& list) {
    char alt;
    
    while (true) {
        cout << "\n\n########### Menù Lista #############" << endl;
        cout << "a: Stampa Lista" << endl;
        cout << "b: Empty" << endl;
        cout << "c: Size" << endl;
        cout << "d: Front" << endl;
        cout << "e: Back" << endl;
        cout << "f: Exists" << endl;
        cout << "g: Insert At Back" << endl;
        cout << "h: Insert At Front" << endl;
        cout << "i: Insert Dictionary" << endl;
        cout << "j: Remove Dictionary" << endl;
        cout << "k: FrontNRemove" << endl;
        cout << "l: Clear" << endl;
        cout << "0: Indietro" << endl;
        cout << "\nInserisci la lettera corrispondente alla scelta: ";
        cout << "\n\n";
        
        cin >> alt;
        cin.ignore();
        
        switch (alt) {
            case 'a': {
                cout << "\nStampa della lista: " << endl;
                list.Map(&Print<Data>);
                break;
            }
            case 'b': {
                bool isEmpty = list.Empty();
                cout << "\nLa Lista " << (isEmpty ? "è vuota" : "non è vuota") << endl;
                break;        
            }
            case 'c': {
                cout << "\nLa size della Lista è: " << list.Size() << endl;
                break;        
            }
            case 'd': {
                funFront(list);
                break; 
            }
            case 'e': {
                funBack(list);
                break; 
            }
            case 'f': {
                funExists(list);
                break;
            }
            case 'g': {
                funInsertAtBack(list);
                break;
            }
            case 'h': {
                funInsertAtFront(list);
                break;
            }
            case 'i': {
                funInsertDictionary(list);
                break;
            }
            case 'j': {
                funRemoveDictionary(list);
                break;
            }
            case 'k': {
                funFrontNRemove(list);
                break;
            }
            case 'l': {
                list.Clear();
                cout << "\nLista svuotata con successo !" << endl;
                break;         
            }
            case '0': {
                list.Clear();
                return;
            }
            default: {
                cout << "\nScelta non valida, riprova:" << endl;
                break;
            }
        }
    }
}

template <typename Data>
void menuQueue(lasd::Queue<Data>& queue) {
    char alt;
    
    while (true) {
        cout << "\n\n########### Menù Queue ############" << endl;
        cout << "1: Size" << endl;
        cout << "2: Clear" << endl;
        cout << "3: Empty" << endl;
        cout << "4: Enqueue" << endl;
        cout << "5: Dequeue" << endl;
        cout << "6: Head" << endl;
        cout << "7: HeadNDequeue" << endl;
        cout << "0: Torna al menù principale" << endl;
        cout << "\nInserisci il numero corrispondente alla scelta: ";
        cout << "\n\n";
        
        cin >> alt;
        cin.ignore();
        
        switch (alt) {
            case '1': {
                cout << "\nLa queue ha size: " << queue.Size() << endl;
                break;
            }
            case '2': {
                queue.Clear();
                cout << "\nQueue svuotata" << endl;
                break;
            }
            case '3': {
                bool isEmpty = queue.Empty();
                cout << "\nLa Queue " << (isEmpty ? "è vuota" : "non è vuota") << endl;
                break;
            }
            case '4': {
                funEnqueue(queue);
                break;
            }
            case '5': {
                funDequeue(queue);
                break;
            }
            case '6': {
                funHead(queue);
                break;
            }
            case '7': {
                funHeadNDequeue(queue);
                break;
            }
            case '0': {
                queue.Clear();
                return;
            }
            default: {
                cout << "\nScelta non valida, riprova:" << endl;
                break;
            }
        }
    }
}



//Vector Menù
template <typename Data>
void menuVector(lasd::Vector<Data>& vector) {
    char alt;
    
    while (true) {
        cout << "\n\n########## Menù Vector ############" << endl;
        cout << "1: Stampa Vector" << endl;
        cout << "2: Clear" << endl;
        cout << "3: Size" << endl;
        cout << "4: Empty" << endl;
        cout << "5: Front" << endl;
        cout << "6: Back" << endl;
        cout << "7: Exists" << endl;
        cout << "8: Sort" << endl;
        cout << "0: Torna al menù principale" << endl;
        cout << "\nInserisci il numero corrispondente alla scelta: ";
        cout << "\n\n";
        
        cin >> alt;
        cin.ignore();
        
        switch (alt) {
            case '1': {
                cout << "\nStampa del vettore: " << endl;
                vector.Map(&Print<Data>);
                break;
            }
            case '2': {
                vector.Clear();
                cout << "\nVettore svuotato con successo !" << endl;
                break;
            }
            case '3': {
                cout << "\nLa size del Vettore è: " << vector.Size() << endl;
                break;  
            }
            case '4': {
                bool isEmpty = vector.Empty();
                cout << "\nIl vettore " << (isEmpty ? "è vuoto" : "non è vuoto") << endl;
                break;        
            }
            case '5': {
                funFront(vector);
                break; 
            }
            case '6': {
                funBack(vector);
                break; 
            }
            case '7': {
                funExists(vector);
                break; 
            }
            case '8': {
                lasd::SortableVector<Data> sortableVector(vector);
                funSort(sortableVector);
                break; 
            }
            case '0': {
                vector.Clear();
                return;
            }
            default: {
                cout << "\nScelta non valida, riprova:" << endl;
                break;
            }
        }
    }
}


/**************************************************************/
//Funzioni
template <typename Data>
void funExists(lasd::LinearContainer<Data>& con) {
    char ans;
    do {
        cout << "\nInserisci il valore da cercare: ";
        Data data;
        cin >> data;
        
        cout << (con.Exists(data) ? "L'elemento è nel container." : "L'elemento non è nel container.") << endl;
        
        cout << "Vuoi cercare un altro elemento? (y/n): ";
        cin >> ans;
    } while (tolower(ans) == 'y');
}


template <typename Data>
void funEnqueue(lasd::Queue<Data>& queue) {
    char ans;
    
    do {
        cout << "\nInserisci il valore che vuoi inserire nella queue: ";
        Data data;
        cin >> data;
        queue.Enqueue(data);
        cout << " Inserito!" << endl;
        
        cout << "Vuoi inserire un altro elemento? (y/n): ";
        cin >> ans;
    } while (tolower(ans) == 'y');
}

template<typename Data>
void funDequeue(lasd::Queue<Data>& queue) {
    try {
        queue.Dequeue();
        cout << "Dequeue effettuata con successo!" << endl; 
    } catch(length_error& e) {
        cout << e.what() << endl;
    }

}


template <typename Data>
void funFront(lasd::LinearContainer<Data>& con) {
    Data data;
    try{
        data = con.Front();
        cout << "\nRisultato : " << data << endl;
    } catch(length_error& e) {
        cout << e.what() << endl;
    }
    return;
}


template <typename Data>
void funBack(lasd::LinearContainer<Data>& con) {
    Data data;
    try{
        data = con.Back();
        cout << "\nRisultato : " << data << endl;
    } catch(length_error& e) {
        cout << e.what() << endl;
    }
    return;
}


template <typename Data>
void funSort(lasd::SortableLinearContainer<Data>& con) {
    if (con.Size() == 0) {
        cout << "Il container è vuoto !";
        return;
    }
    cout << "\nPrima :\n\n" << endl;
    con.Map(&Print<Data>);
    cout << "\nDopo :\n\n" << endl;
    con.Sort();
    con.Map(&Print<Data>);
}


template <typename Data>
void funPush(lasd::Stack<Data>& stack) {
    char ans;
    do {
        cout << "\nInserisci il valore che vuoi inserire nello stack: ";
        Data data;
        cin >> data;
        stack.Push(data);
        cout << " Inserito!" << endl;
        
        cout << "Vuoi inserire un altro elemento? (y/n): ";
        cin >> ans;
    } while (tolower(ans) == 'y');
}



template <typename Data>
void funPop(lasd::Stack<Data>& stack) {
    try {
        stack.Pop();
        cout << "Pop effettuata con successo!" << endl; 
    } catch(length_error& e) {
        cout << e.what() << endl;
    }
}



template <typename Data>
void funTop(lasd::Stack<Data>& stack) {
    try {
        cout << stack.Top() << " Top effettuata con successo!" << endl; 
    } catch(length_error& e) {
        cout << e.what() << endl;
    } 
}

template <typename Data>
void funHead(lasd::Queue<Data>& queue) {
    try {
        cout << queue.Head() << " Head effettuata con successo!" << endl; 
    } catch(length_error& e) {
        cout << e.what() << endl;
    }     
}

template <typename Data>
void funTopPop(lasd::Stack<Data>& stack) {
    try {
        cout << stack.TopNPop() << " TopNPop effettuata con successo!" << endl; 
    } catch(length_error& e) {
        cout << e.what() << endl;
    }     
}

template <typename Data>
void funHeadNDequeue(lasd::Queue<Data>& queue) {
    try {
        cout << queue.HeadNDequeue() << " HeadNDequeue effettuata con successo!" << endl; 
    } catch(length_error& e) {
        cout << e.what() << endl;
    }        
}



template <typename Data>
void funInsertDictionary(lasd::DictionaryContainer<Data>& con) {
    char ans;
    do {
        cout << "\nInserisci il valore da inserire nel dizionario: ";
        Data data;
        cin >> data;
        
        if (con.Insert(data)) {
            cout << " Valore inserito con successo !" << endl;
        } else {
            cout << " Il valore non è stato inserito !" << endl;
        }
        
        cout << "Vuoi inserire un altro elemento? (y/n): ";
        cin >> ans;
    } while (tolower(ans) == 'y');
}


template <typename Data>
void funRemoveDictionary(lasd::DictionaryContainer<Data>& con) {
    char ans;
    do {
        cout << "\nInserisci il valore da rimuovere dal dizionario: ";
        Data data;
        cin >> data;
        
        if (con.Remove(data)) {
            cout << "Valore rimosso con successo !" << endl;
        } else {
            cout << "Il valore non è stato rimosso!" << endl;
        }
        
        cout << "Vuoi rimuovere un altro elemento? (y/n): ";
        cin >> ans;
    } while (tolower(ans) == 'y');
}


template <typename Data>
void funFrontNRemove(lasd::List<Data>& list) {
    try {
        cout << list.FrontNRemove() << "La FrontNRemove è stata effettuata con successo!" << endl; 
    } catch(length_error& e) {
        cout << e.what() << endl;
    }     
}

template <typename Data>
void funInsertAtBack(lasd::List<Data>& list) {
    char ans;
    do {
        cout << "\nInserisci il valore che vuoi inserire nella lista: ";
        Data data;
        cin >> data;
        list.InsertAtBack(data);
        cout << " Inserito in coda!" << endl;
        
        cout << "Vuoi inserire un altro elemento? (y/n): ";
        cin >> ans;
    } while (tolower(ans) == 'y');
}


template <typename Data>
void funInsertAtFront(lasd::List<Data>& list) {
    char ans;
    do {
        cout << "\nInserisci il valore che vuoi inserire nella lista: ";
        Data data;
        cin >> data;
        list.InsertAtFront(data);
        cout << " Inserito in testa!" << endl;
        
        cout << "Vuoi inserire un altro elemento? (y/n): ";
        cin >> ans;
    } while (tolower(ans) == 'y');
}


/*******************************************************************/

string selezionaStruttura() {
    cout << "Scegli il tipo di struttura dati:" << endl;
    cout << "1: Vettore" << endl;
    cout << "2: Lista" << endl;
    cout << "3: StackVec" << endl;
    cout << "4: StackLst" << endl;
    cout << "5: CodaVec" << endl;
    cout << "6: CodaLst" << endl;
    cout << "\nInserisci il numero corrispondente alla scelta: ";

    string scelta;
    bool sceltaValida = false;

    while (!sceltaValida) {
        getline(cin, scelta);

        if (scelta == "1" || scelta == "2" || scelta == "3" || scelta == "4" || scelta == "5" || scelta == "6") {
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
    do { 
        cin >> dim;
        if (dim > 50000) {
            cout << "\n\nDimensione troppo lunga, riprova !\n";
        }
    } while (dim > 50000);
   
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
void popolaVector(lasd::Vector<int>& vector, unsigned long dim) {
    unsigned int j = 0;
    std::vector<int> generatedValues = generaInt(dim);
    for(unsigned int i=0; i<dim; i++) {
        vector[j] = generatedValues[i];
        j++;
    }
}


void popolaVector(lasd::Vector<double>& vector, unsigned long dim) {
    unsigned int j = 0;
    std::vector<double> generatedValues = generaDouble(dim);
    for(unsigned int i = 0; i < dim; ++i) {
        vector[j] = generatedValues[i];
        ++j;
    }
}

void popolaVector(lasd::Vector<string>& vector, unsigned long dim) {
    unsigned int j = 0;
    std::vector<string> generatedValues = generaString(dim);
    for(unsigned int i = 0; i < dim; ++i) {
        vector[j] = generatedValues[i];
        ++j;
    }
}

void popolaList(lasd::List<int>& list, unsigned long dim) {
    std::vector<int> generatedValues = generaInt(dim);
    for(unsigned int i = 0; i < dim; ++i) {
        list.InsertAtBack(generatedValues[i]);
    }
}

void popolaList(lasd::List<double>& list, unsigned long dim) {
    std::vector<double> generatedValues = generaDouble(dim);
    for(unsigned int i = 0; i < dim; ++i) {
        list.InsertAtBack(generatedValues[i]);
    }
}

void popolaList(lasd::List<string>& list, unsigned long dim) {
    std::vector<string> generatedValues = generaString(dim);
    for(unsigned int i = 0; i < dim; ++i) {
        list.InsertAtBack(generatedValues[i]);
    }
}

void popolaStack(lasd::Stack<int>& stack, unsigned long dim) {
    std::vector<int> generatedValues = generaInt(dim);
    for(unsigned int i = 0; i < dim; ++i) {
        stack.Push(generatedValues[i]);
    }
}

void popolaStack(lasd::Stack<double>& stack, unsigned long dim) {
    std::vector<double> generatedValues = generaDouble(dim);
    for(unsigned int i = 0; i < dim; ++i) {
        stack.Push(generatedValues[i]);
    }
}

void popolaStack(lasd::Stack<std::string>& stack, unsigned long dim) {
    std::vector<string> generatedValues = generaString(dim);
    for(unsigned int i = 0; i < dim; ++i) {
        stack.Push(generatedValues[i]);
    }
}

void popolaQueue(lasd::Queue<int>& queue, unsigned long dim) {
    std::vector<int> generatedValues = generaInt(dim);
    for(unsigned int i = 0; i < dim; ++i) {
        queue.Enqueue(generatedValues[i]);
    }
}

void popolaQueue(lasd::Queue<double>& queue, unsigned long dim) {
    std::vector<double> generatedValues = generaDouble(dim);
    for(unsigned int i = 0; i < dim; ++i) {
        queue.Enqueue(generatedValues[i]);
    }
}

void popolaQueue(lasd::Queue<string>& queue, unsigned long dim) {
    std::vector<string> generatedValues = generaString(dim);
    for(unsigned int i = 0; i < dim; ++i) {
        queue.Enqueue(generatedValues[i]);
    }
}



/********************************************************************************/
