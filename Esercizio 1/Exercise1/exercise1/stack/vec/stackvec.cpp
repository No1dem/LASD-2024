
namespace lasd {

/* ************************************************************************** */

template<typename Data>
StackVec<Data>::StackVec(const TraversableContainer<Data>& TravCon) : Vector<Data>::Vector(TravCon) {
    top = TravCon.Size();
    if (size < DEFAULT_SIZE) {
        IncreaseSize(DEFAULT_SIZE);
    }
}


template <typename Data>
StackVec<Data>::StackVec(MappableContainer<Data>&& MapCon) : Vector<Data>::Vector(std::move(MapCon)) {
    top = MapCon.Size();
    if (size < DEFAULT_SIZE) {
        IncreaseSize(DEFAULT_SIZE);
    }
}


//Copy constructor
template<typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& stack) : Vector<Data>::Vector(stack){
    top = stack.top;
}



//Move constructor
template<typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& stack) noexcept : Vector<Data>::Vector(std::move(stack)) {
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
    if (top == stack.top) {
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
const Data& StackVec<Data>::Top() const {
    if (top == 0){
        throw std::length_error("Stack is empty!");
    }
    return Elements[top-1];
}


//Top verione mutable
template <typename Data> 
Data& StackVec<Data>::Top() {
    if (top == 0){
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
Data StackVec<Data>::TopNPop() {
    if (top == 0) {
        throw std::length_error("The stack is empty");
    }
    
    DecreaseSize();
    return Elements[--top];
}



//Push
template <typename Data>
void StackVec<Data>::Push(const Data& data) {
    Elements[index] = data;
    index++;
    IncreaseSize();
}




//Push move
template <typename Data>
void StackVec<Data>::Push(Data&& data) noexcept {
    Elements[index] = std::move(data);
    index++;
    IncreaseSize();
}


/* ************************************************************************** */

}
