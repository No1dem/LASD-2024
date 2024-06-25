
namespace lasd {

/* ************************************************************************** */

//Default Constructor
template<typename Data>
QueueVec<Data>::QueueVec() : Vector<Data>(DEFAULT_SIZE) {
    sentinel = DEFAULT_SIZE - 1;
};


//Specific constructor (TraversableContainer)
template<typename Data>
inline QueueVec<Data>::QueueVec(const TraversableContainer<Data>& TravCon) {
    size = TravCon.Size()*INCREASE_FACTOR;
    sentinel = size-1;
    Elements = new Data[size] {};
    TravCon.Traverse([this](const Data& data) {
        Enqueue(data);
    });
}



//Specific constructor (MappableContainer)
template<typename Data>
inline QueueVec<Data>::QueueVec(MappableContainer<Data>&& MapCon) noexcept {
    size = MapCon.Size()*INCREASE_FACTOR;
    sentinel = size-1;
    Elements = new Data[size] {};
    MapCon.Map([this](Data& data) {
        Enqueue(std::move(data));
    });
}



//Copy constructor
template <typename Data>
inline QueueVec<Data>::QueueVec(const QueueVec<Data>& queue) : Vector<Data>(queue) {   
    tail = queue.tail;
    sentinel = queue.sentinel;
}



//Move constructor
template <typename Data>
inline QueueVec<Data>::QueueVec(QueueVec<Data>&& queue) noexcept :  Vector<Data>(std::move(queue))  {
    std::swap(head, queue.head);
    std::swap(tail, queue.tail);
    std::swap(sentinel, queue.sentinel);
}



//Copy assignment
template<typename Data>
inline QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& qv) {
    Vector<Data>::operator=(qv); 
    head = qv.head;
    tail = qv.tail;
    sentinel = qv.sentinel;
    return *this;
}


//Move assignment
template<typename Data>
inline QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& qv) noexcept {
    Vector<Data>::operator=(std::move(qv)); 
    std::swap(head, qv.head);
    std::swap(tail, qv.tail);
    std::swap(sentinel, qv.sentinel);
    return *this;
}


//Operatore ==
template<typename Data>
bool QueueVec<Data>::operator==(const QueueVec<Data>& qv) const noexcept {
    if (Size() != qv.Size()) {
        return false;
    }

    if(Size() == 0 && qv.Size() == 0) {
        return true;
    }

    for (unsigned long i = 0; i < Size(); ++i) {

        unsigned long idx1 = (head + i) % size;
        unsigned long idx2 = (qv.head + i) % qv.size;

        if (Elements[idx1] != qv.Elements[idx2]) {
            return false; 
        }
    }

    return true;
}

//Head versione non-muatble
template<typename Data>
inline const Data& QueueVec<Data>::Head() const {
    if (Size() == 0) {
        throw std::length_error("Queue is empty!");
    }
    return (*this)[head];
}



//Head versione mutable
template<typename Data>
inline Data& QueueVec<Data>::Head() {
    if (Size() == 0) {
        throw std::length_error("Queue is empty!");
    }
    return (*this)[head];
}



//Dequeue
template<typename Data>
inline void QueueVec<Data>::Dequeue() {
    if (Size() == 0) {
        throw std::length_error("Queue is empty!");
    }

    if (Size() < size/REDUCE_THRESHOLD){
        DecreaseSize();
    }

    sentinel = head++;  //sentinel = head; 
                        //head++;

    if(head == size) {  //Se head ha superato size-1 deve tornare a 0 
        head = 0;
    }
}



//HeadNDequeue
template <typename Data>
Data QueueVec<Data>::HeadNDequeue() {
    if(Size() == 0) {
        throw std::length_error("Queue is empty!");
    } 

    Data tmp = Head();
    Dequeue();
    return tmp;
}


//Enqueue
template <typename Data>
void QueueVec<Data>::Enqueue(const Data& data) {
    if(tail == sentinel) {
        IncreaseSize();
    }

    Elements[tail] = data;
    tail++;

    if(tail == size) {
        tail = 0;
    }
}


//Enqueue move
template <typename Data>
void QueueVec<Data>::Enqueue(Data&& data) noexcept {
    if(tail == sentinel) {
        IncreaseSize();
    }

    Elements[tail] = std::move(data);
    tail++;

    if(tail == size) {
        tail = 0;
    }
}



//Size
template<typename Data>
unsigned long QueueVec<Data>::Size() const noexcept {
    if (head <= tail) {
        return (tail - head);
    }
    return ((tail-head)+size)%size;
}

//Clear
template<typename Data>
void QueueVec<Data>::Clear() {
    Vector<Data>::Clear();
    size = DEFAULT_SIZE;
    Elements = new Data[size] {};
    tail = 0;
    head = 0;
    sentinel = size - 1;
}

//Auxiliar function

//IncreaseSize
template<typename Data>
void QueueVec<Data>::IncreaseSize(){
    if(tail < head) {
        Data* tmp = new Data[INCREASE_FACTOR*size] {};
        unsigned long i = 0;

        for(unsigned long j = head; j<size; ++j) {
            std::swap(Elements[j], tmp[i++]);
        }

        for(unsigned long j = 0; j<tail; ++j) {
            std::swap(Elements[j], tmp[i++]);
        }
        
        std::swap(Elements, tmp);

        head = 0;
        tail = i;
        size = size*INCREASE_FACTOR;
        sentinel = size-1;

        delete[] tmp;

    } else {
        Vector<Data>::Resize(size*INCREASE_FACTOR);
        sentinel = size-1;
    }
}


//DecreaseSize
template<typename Data>
void QueueVec<Data>::DecreaseSize() {
    Data* tmp = new Data[size/DECREASE_FACTOR] {};
    unsigned long i = 0;

    if(tail<head) {

        for(unsigned long j = head; j<size; ++j) {
            std::swap(Elements[j], tmp[i++]);
        }
        for(unsigned long j = 0; j<tail; ++j) {
            std::swap(Elements[j], tmp[i++]);
        }
        
    } else {

        for(unsigned long j = head; j<tail; ++j) {
            std::swap(Elements[j], tmp[i++]);
        }
    }

    std::swap(Elements, tmp);

    head = 0;
    tail = i;
    size = size/DECREASE_FACTOR;
    sentinel = size-1;
    
    delete[] tmp;
}

/* ************************************************************************** */

}
