
namespace lasd {

/* ************************************************************************** */

//Copy assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst<Data>& stack) {
    List<Data>::operator=(stack);
    return *this;
}

//Move assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst<Data>&& stack) noexcept {
    List<Data>::operator=(std::move(stack));
    return *this;
}


//Operator ==
template <typename Data>
bool StackLst<Data>::operator==(const StackLst<Data>& stack) const noexcept {
    return List<Data>::operator==(stack);
}


//Top
template <typename Data>
const Data& StackLst<Data>::Top() const {
    return List<Data>::Front();
}

//Top mutable
template <typename Data>
Data& StackLst<Data>::Top() {
    return List<Data>::Front();
}

//Pop
template <typename Data>
void StackLst<Data>::Pop() {
    return List<Data>::RemoveFromFront();
}

//TopNPop
template <typename Data>
Data StackLst<Data>::TopNPop() {
    return List<Data>::FrontNRemove();
}

//Push (copy of the value)
template <typename Data>
void StackLst<Data>::Push(const Data& data) {
    return List<Data>::InsertAtFront(data);
}

//Push (move of the value)
template <typename Data>
void StackLst<Data>::Push(Data&& data) noexcept {
    return  List<Data>::InsertAtFront(data);
}

/* ************************************************************************** */

}
