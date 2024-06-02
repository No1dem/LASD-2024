
namespace lasd
{

    /* ************************************************************************** */

    // Default Constructor
    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr() {
        tablesize = MIN_TABLESIZE;
        size = 0;

        table.Resize(tablesize);
        flag.Resize(tablesize);

        for (unsigned long i = 0; i < tablesize; i++) {
            flag[i] = Empty;
        }

        fillpercentage = (static_cast<double>(size) / static_cast<double>(tablesize)) * 100;
    }


    // Specific constructors
    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long sizeIN) {
        tablesize = NextPowerOf2(sizeIN);
        size = 0; 

        table.Resize(tablesize);
        flag.Resize(tablesize);

        for (unsigned long i = 0; i < tablesize; i++) {
            flag[i] = Empty;
        }

        fillpercentage = (static_cast<double>(size) / static_cast<double>(tablesize)) * 100;
    }



    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data> &TravCon) : HashTableOpnAdr() {
        InsertAll(TravCon);
    }



    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long sizeIN, const TraversableContainer<Data> &TravCon) : HashTableOpnAdr(sizeIN) {
        InsertAll(TravCon);
    }



    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data> &&MapCon) : HashTableOpnAdr() {
        InsertAll(std::move(MapCon));
    }



    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long sizeIN, MappableContainer<Data> &&MapCon) : HashTableOpnAdr(sizeIN) {
        InsertAll(std::move(MapCon));
    }



    // Copy Constructor
    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data> &ht) {
        tablesize = ht.tablesize;
        size = ht.size;
        acoeff = ht.acoeff;
        bcoeff = ht.bcoeff;
        table = ht.table;
        flag = ht.flag;
        fillpercentage = ht.fillpercentage;
    }

    // Move Constructor
    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data> &&ht) noexcept {
        std::swap(tablesize, ht.tablesize);
        std::swap(size, ht.size);
        std::swap(acoeff, ht.acoeff);
        std::swap(bcoeff, ht.bcoeff);
        std::swap(table, ht.table);
        std::swap(flag, ht.flag);
        std::swap(fillpercentage, ht.fillpercentage);
    }



    // Copy Assignemnt
    template <typename Data>
    HashTableOpnAdr<Data> &HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data> &ht) {
        if (this != &ht) {
            HashTableOpnAdr<Data> tmp(ht);
            std::swap(*this, tmp);
        }
        return *this;
    }



    // Move Assignment
    template <typename Data>
    HashTableOpnAdr<Data> &HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data> &&ht) noexcept {
        if (this != &ht) {
            std::swap(tablesize, ht.tablesize);
            std::swap(size, ht.size);
            std::swap(acoeff, ht.acoeff);
            std::swap(bcoeff, ht.bcoeff);
            std::swap(table, ht.table);
            std::swap(flag, ht.flag);
            std::swap(fillpercentage, ht.fillpercentage);
        }
        return *this;
    }



    // Operator ==
    template <typename Data>
    bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr<Data> &ht) const noexcept {
        if (size != ht.size) {
            return false;
        }

        for (unsigned long i = 0; i < tablesize; i++) {
            if (flag[i] == Full) {
                if (!ht.Exists(table[i])) {
                    return false;
                }
            }
        }

        return true;
    }



    // Insert (Copy of the value)
    template <typename Data>
    bool HashTableOpnAdr<Data>::Insert(const Data &data) {
        fillpercentage = (static_cast<double>(size) / static_cast<double>(tablesize)) * 100;

        if (fillpercentage > MAX_FILLPERCENTAGE) {
            Resize(2 * tablesize);
        }

        if (!Exists(data)) {
            unsigned long idx = FindEmpty(data, 0);

            if (idx < tablesize) {
                unsigned long pos = HashKey(data, idx);

                if (flag[pos] != Full) {
                    flag[pos] = Full;
                    table[pos] = data;
                    size++;
                    return true;
                }
            }
        }
        return false;
    }



    // Insert (Move of the value)
    template <typename Data>
    bool HashTableOpnAdr<Data>::Insert(Data &&data) noexcept {
        fillpercentage = (static_cast<double>(size) / static_cast<double>(tablesize)) * 100;

        if (fillpercentage > MAX_FILLPERCENTAGE) {
            Resize(2 * tablesize);
        }

        if (!Exists(data)) {
            unsigned long idx = FindEmpty(data, 0);

            if (idx < tablesize) {
                unsigned long pos = HashKey(data, idx);

                if (flag[pos] != Full) {
                    flag[pos] = Full;
                    table[pos] = std::move(data);
                    size++;
                    return true;
                }
            }
        }
        return false;
    }



    // Remove
    template <typename Data>
    bool HashTableOpnAdr<Data>::Remove(const Data &data) {
        fillpercentage = (static_cast<double>(size) / static_cast<double>(tablesize)) * 100;

        bool result = Remove(data, 0);

        if (fillpercentage < MIN_FILLPERCENTAGE) {
            Resize(tablesize / 2);
        }

        return result;
    }




    // Exists
    template <typename Data>
    bool HashTableOpnAdr<Data>::Exists(const Data &data) const noexcept {
        if (size > 0) {
            unsigned long idx = Find(data, 0);

            if (idx < tablesize) {

                unsigned long pos = HashKey(data, idx);

                if (flag[pos] == Full && table[pos] == data) {
                    return true;
                }
            }
        }
        return false;
    }
    


    //Resize
    template <typename Data>
    void HashTableOpnAdr<Data>::Resize(unsigned long sizeIN) {
        if (sizeIN == 0) {
            Clear();
            return;
        }
    
        if (!CheckResize(sizeIN)) {
            return;
        }
        unsigned long newSize = NextPowerOf2(sizeIN);

        if(newSize == tablesize) {
            return;
        }

        HashTableOpnAdr<Data> tmp(newSize);

        for (unsigned long i = 0; i < tablesize; i++) {
            if (flag[i] == Full) {
                tmp.Insert(table[i]);
            }
        }

        std::swap(*this, tmp);
    }




    // Clear
    template <typename Data>
    void HashTableOpnAdr<Data>::Clear() {
        tablesize = MIN_TABLESIZE;
        size = 0;

        table.Clear();
        table.Resize(tablesize);
        flag.Resize(tablesize);

        for (unsigned long i = 0; i < tablesize; i++) {
            flag[i] = Empty;
        }
    }



    // HashKey
    template <typename Data>
    unsigned long HashTableOpnAdr<Data>::HashKey(const Data& data, unsigned long collision) const noexcept {
        unsigned long key = hash(data);
        return ((HashKey(key) + acoeff * collision + bcoeff * collision * collision) % tablesize); 
    }




    // Find
    template <typename Data>
    unsigned long HashTableOpnAdr<Data>::Find(const Data& data, unsigned long idx) const noexcept {
        while (idx < tablesize) {
            unsigned long pos = HashKey(data, idx);

            if (table[pos] == data) {
                return idx;
            }

            if (flag[pos] == Empty) {
                return tablesize;
            }

            idx++;
        }
        return idx;
    }



    // FindEmpty
    template <typename Data>
    unsigned long HashTableOpnAdr<Data>::FindEmpty(const Data &data, unsigned long idx) const noexcept {
        unsigned long pos = HashKey(data, idx);
        while (idx < tablesize) {
            if (flag[pos] != Full) {
                return idx;
            }
            idx++;
            pos = HashKey(data, idx);
        }
        return idx;
    }

    // Remove
    template <typename Data>
    bool HashTableOpnAdr<Data>::Remove(const Data &data, unsigned long index) {
        if (size > 0) {
            unsigned long idx = Find(data, index);

            if (idx < tablesize) {
                unsigned long pos = HashKey(data, idx);

                if (flag[pos] == Full && table[pos] == data) {
                    flag[pos] = Removed;
                    size--;
                    return true;
                }
            }
        }
        return false;
    }

    // NextPowerOf2
    template <typename Data>
    unsigned long HashTableOpnAdr<Data>::NextPowerOf2(unsigned long sizeIN) const noexcept {
        unsigned long newsize = MIN_TABLESIZE;

        if (sizeIN >= MAX_TABLESIZE) {
            return MAX_2POW;
        }

        while (newsize < sizeIN) {

            if (newsize > MAX_TABLESIZE) {
                return MAX_2POW;
            }

            newsize = newsize << 1;
        }

        return newsize;
    }

    // CheckResize
    template <typename Data>
    bool HashTableOpnAdr<Data>::CheckResize(unsigned long newTableSize) {
        if (newTableSize == tablesize) {
            return false;
        } else {
            double newFillPercentage = (static_cast<double>(size) / static_cast<double>(newTableSize)) * 100;

            if (newFillPercentage < MIN_FILLPERCENTAGE || newFillPercentage > MAX_FILLPERCENTAGE) {
                return false;
            }            
            return true;
        }
    }

    /* ************************************************************************** */

}
