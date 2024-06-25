
namespace lasd {

/* ************************************************************************** */

//Default constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr() {
    table = new BST<Data>[tablesize]{}; 
}



//Specific constructors
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long sizeIN) {
    if (sizeIN < MIN_TABLESIZE) {
        sizeIN = MIN_TABLESIZE;

    } else if (sizeIN > MAX_TABLESIZE) {
        sizeIN = MAX_TABLESIZE;

    } else if (sizeIN != MAX_TABLESIZE && sizeIN != MIN_TABLESIZE) {
        sizeIN = NextPrime(sizeIN);

    }

    tablesize = sizeIN;
    table = new BST<Data>[tablesize]{}; 
}



template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data>& TravCon) : HashTableClsAdr() {
    InsertAll(TravCon);
}



template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long sizeIN, const TraversableContainer<Data>& TravCon) : HashTableClsAdr(sizeIN)  {
    InsertAll(TravCon);
}



template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data>&& MapCon) : HashTableClsAdr() {
    InsertAll(std::move(MapCon));
}



template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long sizeIN, MappableContainer<Data>&& MapCon) : HashTableClsAdr(sizeIN)  {
    InsertAll(std::move(MapCon));
}



//Copy constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& ht) : HashTable<Data>(ht) {
    table = new BST<Data>[tablesize]{};
    for (unsigned long i = 0; i < tablesize; ++i) {  
        table[i] = ht.table[i]; 
    }
}



//Move constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& ht) noexcept : HashTable<Data>(std::move(ht)) {
    std::swap(table, ht.table);
}



//Destructor
template <typename Data>
HashTableClsAdr<Data>::~HashTableClsAdr() {
    delete[] table;
}



//Copy assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data>& ht) {
    if (this != &ht) {
        HashTableClsAdr<Data> tmp(ht);
        std::swap(*this, tmp);
    }
    return *this;
}



//Move assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data>&& ht) noexcept {
    if (this != &ht) {
        std::swap(table, ht.table);
        std::swap(size, ht.size);
        std::swap(acoeff, ht.acoeff);
        std::swap(bcoeff, ht.bcoeff);
        std::swap(tablesize, ht.tablesize);
    }
    return *this;
}


//Operator ==
template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data>& ht) const noexcept {
    bool res = true;
    if(ht.size == size) {

        for (unsigned long i = 0 ; i < tablesize ; i++) {
            table[i].Traverse(
                [&ht,&res](const Data& data) {
                    if(!ht.Exists(data)) {
                        res = false;
                        return;
                    }
                }
            );

            if (res == false) {
                return false;
            }  
        }
        return true;
    }
    return false;
}



//Insert (Copy of the value)
template <typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& data) {
    unsigned long pos = HashKey(hash(data));

    if(table[pos].Insert(data)) {
        size++;
        return true;
    } 

    return false;
}



//Insert (Move of the value)
template <typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& data) noexcept {
    unsigned long pos = HashKey(hash(data));

    if(table[pos].Insert(std::move(data))) {
        size++;
        return true;
    } 

    return false;
}



//Remove
template <typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& data) {
    unsigned long pos = HashKey(hash(data));

    if(table[pos].Remove(data)) {
        size--;
        return true;
    } 

    return false;
}



//Exists
template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& data) const noexcept {
    unsigned long pos = HashKey(hash(data));

    if (table[pos].Exists(data)) {
        return true;
    }

    return false;
}



//Resize
template <typename Data>
void HashTableClsAdr<Data>::Resize(const unsigned long sizeIN) {
    if (sizeIN == 0) {
        Clear();
        return;
    }

    unsigned long newTableSize = NextPrime(sizeIN);
    BST<Data>* tmp = new BST<Data>[newTableSize] {};
    
    size = 0;
    
    std::swap(tmp, table);
    std::swap(newTableSize, tablesize);

    for(unsigned long i = 0; i < newTableSize; i++) {
        InsertAll(tmp[i]);
    }

    delete[] tmp;
}



//Clear
template <typename Data>
void HashTableClsAdr<Data>::Clear() {
    delete[] table;
    table = new BST<Data>[tablesize]{};
    size = 0;
}



//NextPrime
template <typename Data>
unsigned long HashTableClsAdr<Data>::NextPrime(unsigned long num) const noexcept {
    for (unsigned long i = 2; i <= num/2; ++i) {
        if (num % i == 0) {
            num++;
            i = 2;
        }
    }
    return num;
}

/* ************************************************************************** */

}
