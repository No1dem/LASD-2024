
namespace lasd {

/* ************************************************************************** */
/*Node*/

//Move constructor
template <typename Data>
List<Data>::Node::Node(Node&& node) noexcept {
    std::swap(element, node.element);
    std::swap(next, node.next);
}


//Operator == 
template<typename Data>
bool List<Data>::Node::operator==(const Node& node) const noexcept {
    return (node.element == this->element && node.next == this->next);
}


//Operator !=
template<typename Data>
bool List<Data>::Node::operator!=(const Node& node) const noexcept {
    return !(*this == node);
}
/* ************************************************************************** */
/*List*/

//Specific constructors

template <typename Data>
List<Data>::List(const TraversableContainer<Data>& TravCont) {
    TravCont.Traverse([this](const Data & data) {
        InsertAtBack(data);
    }
    );
}

template <typename Data>
List<Data>::List(MappableContainer<Data>&& MapCont) {
    MapCont.Map([this](Data & data) {
        InsertAtBack(std::move(data));
    }
    );
}


//Copy constructor
template <typename Data>
List<Data>::List(const List<Data>& list) {
    if(list.head != nullptr) {
        Node* currNode = list.head;
        while(currNode != nullptr) {
            InsertAtBack(currNode->info);
            currNode = currNode->next;
        }
    }
}


//Move constructor
template <typename Data>
List<Data>::List(List<Data>&& list) noexcept {
    std::swap(size, list.size);
    std::swap(head, list.head);
    std::swap(tail, list.tail);
}


//Destructor
template <typename Data>
List<Data>::~List() {
    Clear();
}

//Copy assignment
template<typename Data>
List& List<Data>::operator=(const List<Data>& list){
    if (this != &list){
        List<Data> tmp(list);
        std::swap(*this, tmp);
    }
    return *this;
}


//Move assignment
template<typename Data>
List<Data>& List<Data>::operator=(List<Data>&& list) noexcept {
    if (this != &list) { 
        std::swap(head, list.head);
        std::swap(tail, list.tail);
        std::swap(size, list.size);
    }
    return *this;
}


/* ************************************************************************** */
}
