
namespace lasd {

/* ************************************************************************** */

// Copy assignment
template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& qv){
    Vector<Data>::operator=(qv); 
    return *this;
}

// Move assignment
template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& qv) noexcept{
    Vector<Data>::operator=(std::move(qv)); 
    return *this;
}



//Head versione non-muatble
template<typename Data>
const Data& QueueVec<Data>::Head() const {
    return (*this)[head];
}



//Head versione mutable
template<typename Data>
Data& QueueVec<Data>::Head() override {
    return (*this)[head];
}


//Dequeue
template<typename Data>
inline void QueueVec<Data>::Dequeue() {
    if (Size() == 0) {
        throw std::length_error("Queue is empty!")
    }

    if (Size() < size/4){
        DecreaseSize();
    }
    sentinel = head++;

    if(head == size) {
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
    if(tail==sentinel) {
        Expand();
    }
    Elements[tail] = data;
    tail++;
    if(tail==size) {
        tail = 0;
    }
}



//Empty
template <typename Data>
bool QueueVec<Data>::Empty() const noexcept {
    return (head==tail);
}


//Size
template<typename Data>
unsigned long QueueVec<Data>::Size() const noexcept {
    return sentinel;
}



//Auxiliar function

IncreaseSize()

DecreaseSize()


/* ************************************************************************** */

}
