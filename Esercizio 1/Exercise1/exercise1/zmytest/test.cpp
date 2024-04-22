#include "test.hpp"

#include <iostream>
#include <string>
#include <random>


using namespace std;

//Menu principale
void test() {
    cout << "\n\n######## Menù Principale #########" << endl;

    string alt = selezionaStruttura();
    string tipo = selezionaTipo();
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
            lasd::Vector<std::string> vector(dim);
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
            lasd::List<std::string> list;
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
                list.Map(&MapPrint<Data>);
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
                funInsertD(list);
                break;
            }
            case 'j': {
                funRemoveD(list);
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
                vector.Map(&MapPrint<Data>);
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
    Data data;
    bool repeat = false;
    do {
        cout << "\nInserisci il valore da cercare: ";
        cin >> data;
        string message = con.Exists(data) ? ("L'elemento è nel container.") : ("L'elemento non è nel container.");
        cout << message << endl;
        cout << "Vuoi cercare un altro elemento? (y/n): ";
        char ans;
        cin >> ans;
        repeat = (ans == 'y');
    } while (repeat);
}

template <typename Data>
void funFront(lasd::LinearContainer<Data>& con) {
    Data data;
    try{
        data = con.Front();
        cout << "\nRisultato: " << data << endl;
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
        cout << "\nRisultato" << data << endl;
    } catch(length_error& e) {
        cout << e.what() << endl;
    }
    return;
}

template <typename Data>
void funSort(lasd::SortableLinearContainer<Data>& con) {
    cout << "\nPrima :" << endl;
    con.Map(&MapPrint<Data>);
    cout << "\nDopo :" << endl;
    con.Sort();
    con.Map(&MapPrint<Data>);
}

template <typename Data>
void funPush(lasd::Stack<Data>& stack) {
    Data data;
    bool repeat = false;
    do {
        cout << "\nInserisci il valore che vuoi inserire nello stack: ";
        cin >> data;
        stack.Push(data);
        cout << " Inserito!" << endl;
        cout << "Vuoi inserire un altro elemento? (y/n): ";
        char ans;
        cin >> ans;
        repeat = (ans == 'y');
    } while (repeat);
}

template <typename T>
void funEnqueue(lasd::Queue<T>& que) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore che vuoi inserire nella queue: ";
        std::cin >> value;
        que.Enqueue(value);
        std::cout << " Inserito!" << std::endl;
        std::cout << "Vuoi inserire un altro elemento? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);    
}

template <typename T>
void funPop(lasd::Stack<T>& stk) {
    std::cout << "\nEffettuo Pop..." << std::endl;
    try {
        stk.Pop();
        std::cout << "Pop effettuata con successo!" << std::endl; 
    } catch(std::length_error& ex) {
        std::cout << ex.what() << std::endl;
    }
}

template<typename T>
void funDequeue(lasd::Queue<T>& que) {
        std::cout << "\nEffettuo Dequeue..." << std::endl;
    try {
        que.Dequeue();
        std::cout << "Dequeue effettuata con successo!" << std::endl; 
    } catch(std::length_error& ex) {
        std::cout << ex.what() << std::endl;
    }

}

template <typename T>
void funTop(lasd::Stack<T>& stk) {
       std::cout << "\nEffettuo Top..." << std::endl;
    try {
        std::cout << stk.Top() << " Pop effettuata con successo!" << std::endl; 
    } catch(std::length_error& ex) {
        std::cout << ex.what() << std::endl;
    } 
}

template <typename T>
void funHead(lasd::Queue<T>& que) {
       std::cout << "\nEffettuo Head..." << std::endl;
    try {
        std::cout << que.Head() << " Head effettuata con successo!" << std::endl; 
    } catch(std::length_error& ex) {
        std::cout << ex.what() << std::endl;
    }     
}

template <typename T>
void funTopPop(lasd::Stack<T>& stk) {
       std::cout << "\nEffettuo TopNPop..." << std::endl;
    try {
        std::cout << stk.TopNPop() << " TopNPop effettuata con successo!" << std::endl; 
    } catch(std::length_error& ex) {
        std::cout << ex.what() << std::endl;
    }     
}

template <typename T>
void funHeadNDequeue(lasd::Queue<T>& que) {
       std::cout << "\nEffettuo HeadNDequeue..." << std::endl;
    try {
        std::cout << que.HeadNDequeue() << " HeadNDequeue effettuata con successo!" << std::endl; 
    } catch(std::length_error& ex) {
        std::cout << ex.what() << std::endl;
    }        
}

template <typename T>
void funInsertD(lasd::DictionaryContainer<T>& con) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore che vuoi inserire nel dizionario: ";
        std::cin >> value;
        if(con.Insert(value)) {
            std::cout << " Inserito!" << std::endl;
        } else {
            std::cout << " Valore non Inserito!" << std::endl;
        }
        
        std::cout << "Vuoi inserire un altro elemento? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);     
}

template <typename T>
void funRemoveD(lasd::DictionaryContainer<T>& con) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore che vuoi rimuovere dal dizionario: ";
        std::cin >> value;
        if(con.Remove(value)) {
            std::cout << " Rimosso!" << std::endl;
        } else {
            std::cout << " Valore non rimosso!" << std::endl;
        }
        
        std::cout << "Vuoi rimuovere un altro elemento? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);     
}

template <typename T>
void funFrontNRemove(lasd::List<T>& lst) {
       std::cout << "\nEffettuo FrontNRemove..." << std::endl;
    try {
        std::cout << lst.FrontNRemove() << " FrontNRemove effettuata con successo!" << std::endl; 
    } catch(std::length_error& ex) {
        std::cout << ex.what() << std::endl;
    }     
}

template <typename T>
void funInsertAtBack(lasd::List<T>& lst) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore che vuoi inserire nella lista: ";
        std::cin >> value;
        lst.InsertAtBack(value);
        std::cout << " Inserito in coda!" << std::endl;
        std::cout << "Vuoi inserire un altro elemento? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);   
}

template <typename T>
void funInsertAtFront(lasd::List<T>& lst) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore che vuoi inserire nella lista: ";
        std::cin >> value;
        lst.InsertAtFront(value);
        std::cout << " Inserito in testa!" << std::endl;
        std::cout << "Vuoi inserire un altro elemento? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);     
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

string selezionaTipo() {
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
    cin >> dim;
    return dim;    
}
/******************************************************/

//Generatori
vector<int> generaInt(unsigned long dim) {
    default_random_engine generator(random_device{}());
    uniform_int_distribution<int> dist(0, 100);

    vector<int> vec;

    for(unsigned long i = 0; i<dim; i++) {
        vec.push_back(dist(generator));
    }
    cout << "\nGenerazione casuale per il popolamento della struttura completata !\n" << endl;
    return vec;
}

vector<double> generaDouble(unsigned long dim) {
    default_random_engine generator(random_device{}());
    uniform_real_distribution<double> dist(0.0, 100.0);

    vector<double> vec;

    for(unsigned long i = 0; i<dim; i++) {
        vec.push_back(dist(generator));
    }
    cout << "\nGenerazione casuale per il popolamento della struttura completata !\n" << endl;
    return vec;
}

    vector<string> generaString(unsigned long dim) {
    char lettere[52] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                         'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    default_random_engine generator(random_device{}());
    uniform_int_distribution<int> dist(0, 51);

    vector<string> vec;

    for(unsigned long i = 0; i<dim; i++) {
        string str = "";
        str = str + lettere[dist(generator)];
        vec.push_back(str);
    }
    cout << "\nGenerazione casuale per il popolamento della struttura completata !\n" << endl;
    return vec;
}



/******************************************************/

void popolaVector(lasd::Vector<int>& vector, unsigned long dim) {
    unsigned int j = 0;
    for(int i: generaInt(dim)) {
        vector[j] = i;
        j++;
    }
}

void popolaVector(lasd::Vector<double>& vector, unsigned long dim) {
    unsigned int j = 0;
    for(double i: generaDouble(dim)) {
        vector[j] = i;
        j++;
    }
}

void popolaVector(lasd::Vector<string>& vector, unsigned long dim) {
    unsigned int j = 0;
    for(string i: generaString(dim)) {
        vector[j] = i;
        j++;
    }
}

void popolaList(lasd::List<int>& list, unsigned long dim) {
    for(int i: generaInt(dim)) {
        list.InsertAtBack(i);
    }
}

void popolaList(lasd::List<double>& list, unsigned long dim) {
    for(double i: generaDouble(dim)) {
        list.InsertAtBack(i);
    }
}

void popolaList(lasd::List<string>& list, unsigned long dim) {
    for(string i: generaString(dim)) {
        list.InsertAtBack(i);
    }
}

void popolaStack(lasd::Stack<int>& stack, unsigned long dim) {
    for(int i: generaInt(dim)) {
        stack.Push(i);
    }
}

void popolaStack(lasd::Stack<double>& stack, unsigned long dim) {
    for(double i: generaDouble(dim)) {
        stack.Push(i);
    }
}

void popolaStack(lasd::Stack<std::string>& stack, unsigned long dim) {
    for(string i: generaString(dim)) {
        stack.Push(i);
    }
}

void popolaQueue(lasd::Queue<int>& queue, unsigned long dim) {
    for(int i: generaInt(dim)) {
        queue.Enqueue(i);
    }
}

void popolaQueue(lasd::Queue<double>& queue, unsigned long dim) {
    for(double i: generaDouble(dim)) {
        queue.Enqueue(i);
    }
}

void popolaQueue(lasd::Queue<string>& queue, unsigned long dim) {
    for(string i: generaString(dim)) {
        queue.Enqueue(i);
    }
}


/********************************************************************************/
