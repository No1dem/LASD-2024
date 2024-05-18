
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
            InsertAtBack(currNode->element);
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



//Copy assignment
template<typename Data>
List<Data>& List<Data>::operator=(const List<Data>& list){
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



// Operator ==
template<typename Data>
bool List<Data>::operator==(const List<Data>& list) const noexcept {
    if (this == &list) {
        return true;
    }

    if (size != list.size){
        return false;
    }

    Node *tmp1 = head;
    Node *tmp2 = list.head;

    while (tmp1 != nullptr) {
        if (tmp1->element != tmp2->element){
            return false;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    return true;
}


// Operator !=
template<typename Data>
inline bool List<Data>::operator!=(const List<Data>& list) const noexcept {
    return !(*this == list);
}


//InsertAtFront (Copy)
template<typename Data>
void List<Data>::InsertAtFront(const Data& dato) {
    Node* newNode = new Node(dato); 

    if (head == nullptr) { 
        head = newNode;
        tail = newNode; 
    } else {
        newNode->next = head;
        head = newNode;
    }
    size++;
}


//InsertAtFront (Move)
template<typename Data>
void List<Data>::InsertAtFront(Data&& dato) noexcept {
    Node* newNode = new Node(std::move(dato));

    if (head == nullptr) { 
        head = newNode;
        tail = newNode; 
    } else {
        newNode->next = head;
        head = newNode;
    }
    size++;
}


//RemoveFromFront 
template<typename Data>
void List<Data>::RemoveFromFront() {
    if(size == 0){
        throw std::length_error("List is empty!");
    }

    Node* tmp = head;
    head = head->next;
    tmp->next = nullptr;

    delete tmp;

    if (size == 1) {
        tail = nullptr;
    }

    size--;

} 


//FrontNRemove
template<typename Data>
inline Data List<Data>::FrontNRemove() {
    if(size == 0) {
        throw std::length_error("Empty List!");
    }

    Data tmp = Front();
    RemoveFromFront();

    return tmp;
}

//InsertAtBack (Copy)
template<typename Data>
void List<Data>::InsertAtBack(const Data& data) {
    Node* newNode = new Node(data);

    if (head == nullptr){
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
} 


//InsertAtBack (Move)
template<typename Data>
void List<Data>::InsertAtBack(Data&& data) noexcept {
    Node* newNode = new Node(std::move(data));

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
} 


//Clear 
template <typename Data>
void List<Data>::Clear() {
    while(head != nullptr) {
       RemoveFromFront(); 
    }
}



// Specific member functions (inherited from DictionaryContainer)

//Insert (Copy)
template<typename Data>
bool List<Data>::Insert(const Data& data){
    if(Exists(data)){
        return false;
    }
    InsertAtBack(data);
    return true;
}


//Insert (Move)
template<typename Data>
bool List<Data>::Insert(Data&& data) noexcept{
    if(Exists(data)){
        return false;
    }
    InsertAtBack(std::move(data));
    return true;
}



//Remove
template<typename Data>
bool List<Data>::Remove(const Data& data) {
    if (size == 0){
        return false;
    }

    if (head->element == data){
        RemoveFromFront();
        return true;
    }

    Node* currNode = head->next;
    Node* precNode = head;

    while (currNode != nullptr){
        if (currNode->element == data) {
            Node* tmp = currNode;

            precNode->next = currNode->next;
            tmp->next = nullptr;

            if (currNode == tail) {
               tail = precNode;
               delete tmp;
               size --;
               return true;
            } else {
                delete tmp;
                size--;
                return true;
            }
        } else {
            precNode = currNode;
            currNode = currNode->next;
        }
    }
    return false;
}

//Operator [] versione non-mutable
template<typename Data>
const Data& List<Data>::operator[](const unsigned long index) const {
    if(size == 0) {
        throw std::length_error("Empty List!");
    }

    if(index >= size) {
        throw std::out_of_range("Index out of bounds!");
    } 

    if(index == size-1) {
        return tail->element;
    }

    Node* currNode = head;
    for(unsigned long i=0; i<index; i++) {
        currNode = currNode->next;
    }
    return currNode->element;
}


//Operator [] versione mutable
template<typename Data>
Data& List<Data>::operator[](const unsigned long index) {
    if(size==0) {
        throw std::length_error("Empty List!");
    }

    if(index >= size) {
        throw std::out_of_range("Index out of bounds!");
    } 

    if(index == size-1) {
        return tail->element;
    }

    Node* currNode = head;
    for(unsigned long i=0; i<index; i++) {
        currNode = currNode->next;
    }
    return currNode->element;
}


//Front versione non-mutable
template <typename Data> 
inline const Data& List<Data>::Front() const {
  if (size == 0) {
    throw std::length_error("Empty List!");
  }
  return head->element;
}


//Front versione mutable
template <typename Data> 
inline Data& List<Data>::Front() {
  if (size == 0) {
    throw std::length_error("Empty List!");
  }
  return head->element;
}

//Back versione non-mutable
template <typename Data> 
inline const Data& List<Data>::Back() const {
  if (size == 0) {
    throw std::length_error("Empty List!");
  }
  return tail->element;
}


//Back versione mutable
template <typename Data> 
inline Data& List<Data>::Back() {
  if (size == 0) {
    throw std::length_error("Empty List!");
  }
  return tail->element;
}

/***************************************************************/
//Auxiliar function

template <typename Data>
void List<Data>::PreOrderTraverse(TraverseFun fun, Node* currNode) const {
  if (currNode == nullptr)
    return;
  fun(currNode->element);
  PreOrderTraverse(fun, currNode->next);
}

template <typename Data>
void List<Data>::PostOrderTraverse(TraverseFun fun, Node* currNode) const {
  if (currNode == nullptr)
    return;
  PostOrderTraverse(fun, currNode->next);
  fun(currNode->element);
}


template <typename Data>
void List<Data>::PreOrderMap(MapFun fun, Node* currNode) const {
  if (currNode == nullptr)
    return;
  fun(currNode->element);
  PreOrderMap(fun, currNode->next);
}


template <typename Data>
void List<Data>::PostOrderMap(MapFun fun, Node* currNode) const {
  if (currNode == nullptr)
    return;
  PostOrderMap(fun, currNode->next);
  fun(currNode->element);
}



/* ************************************************************************** */
}
