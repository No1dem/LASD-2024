
namespace lasd {

/* ************************************************************************** */

template<typename Data>
StackVec<Data>::StackVec(const TraversableContainer<Data>& TravCon) : Vector<Data>::Vector(TravCon) {
    top = TravCon.Size();
    if (size < DEFAULT_SIZE) {
        Vector<Data>::Resize(DEFAULT_SIZE);
    }
}



template <typename Data>
StackVec<Data>::StackVec(MappableContainer<Data>&& MapCon) noexcept: Vector<Data>::Vector(std::move(MapCon)) {
    top = MapCon.Size();
    if (size < DEFAULT_SIZE) {
        Vector<Data>::Resize(DEFAULT_SIZE);
    }
}



//Copy constructor
template<typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& stack) : Vector<Data>::Vector(stack){
    top = stack.top;
}



//Move constructor
template<typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& stack) : Vector<Data>::Vector(std::move(stack)) {
    std::swap(top,stack.top);
}




// Copy assignment
template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& stack) {
    Vector<Data>::operator=(stack);
    top = stack.top;
    return *this;
}



// Move assignment
template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& stack) noexcept {
    Vector<Data>::operator=(std::move(stack));
    std::swap(top,stack.top);
    return *this;
}




//Operator ==
template<typename Data>
bool StackVec<Data>::operator==(const StackVec<Data>& stack) const noexcept {
    if (top != stack.top) {
        return false;
    }

    for (unsigned long i=0;i<top;i++){
        if(Elements[i] != stack.Elements[i]){
            return false;
        }
    }

    return true;
}



//Top versione not-mutable
template <typename Data> 
inline const Data& StackVec<Data>::Top() const {
    if (top == 0) {
        throw std::length_error("Stack is empty!");
    }
    return Elements[top-1];
}


//Top verione mutable
template <typename Data> 
inline Data& StackVec<Data>::Top() {
    if (top == 0) {
        throw std::length_error("Stack is empty!");
    }
    return Elements[top-1];
}




//Pop
template <typename Data> 
inline void StackVec<Data>::Pop() {
    if (top == 0) {
        throw std::length_error("The stack is empty");
    }
    
    DecreaseSize();
    top--;
}



//TopNPop
template<typename Data>
inline Data StackVec<Data>::TopNPop() {
    if (top == 0) {
        throw std::length_error("The stack is empty");
    }
    
    DecreaseSize();
    return std::move(Elements[--top]);
}




//Push copy
template <typename Data>
inline void StackVec<Data>::Push(const Data& data) {
    Elements[top] = data;
    top++;
    IncreaseSize();
}



//Push move
template <typename Data>
inline void StackVec<Data>::Push(Data&& data) noexcept {
    Elements[top] = std::move(data);
    top++;
    IncreaseSize();
}



//Clear
template<typename Data>
inline void StackVec<Data>::Clear() {
    top = 0;
    Vector<Data>::Resize(DEFAULT_SIZE);
}



//IncreaseSize
template <typename Data>
inline void StackVec<Data>::IncreaseSize() {
    if (top == size) {
        Vector<Data>::Resize(size*INCREASE_FACTOR);
    }
}


//DecreaseSize
template<typename Data>
inline void StackVec<Data>::DecreaseSize() {
    if (top == size/REDUCE_THRESHOLD) {
        Vector<Data>::Resize(size/DECREASE_FACTOR);
    }
}



/* ************************************************************************** */

}
