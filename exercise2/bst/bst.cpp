
namespace lasd {

/* ************************************************************************** */

//Specific constructors

//TraversableContainer
template<typename Data>
BST<Data>::BST(const TraversableContainer<Data>& TravCon) {
     TravCon.Traverse([this](const Data& data) {
        Insert(data);
    });
}


//MappableContainer
template <typename Data>
BST<Data>::BST(MappableContainer<Data>&& MapCon) noexcept {
    MapCon.Map([this](Data& dataIN) {
        Insert(std::move(dataIN));
    });
}



// Copy assignment
template <typename Data>
BST<Data>& BST<Data>::operator=(const BST& bst) {
    BinaryTreeLnk<Data>::operator=(bst);
    return *this;
}



// Move assignment
template <typename Data>
BST<Data>& BST<Data>::operator=(BST&& bst) noexcept {
    BinaryTreeLnk<Data>::operator=(std::move(bst));
    return *this;
}



//Operator ==
template <typename Data>
bool BST<Data>::operator==(const BST& bst) const noexcept {
     if (size == bst.Size()){
        BTInOrderIterator<Data> itr1(*this);
        BTInOrderIterator<Data> itr2(bst);

        while (!itr1.Terminated() && !itr2.Terminated()) {
            if (*itr1 != *itr2) {
                return false;
            }

            ++itr1;
            ++itr2;
        }

        if (itr1.Terminated() && itr2.Terminated()) {
            return true;
        }
    }

    return false;
}

/*****************************************************************************/


//Min
template <typename Data>
const Data& BST<Data>::Min() const {
    if (this->Empty()) {
        throw std::length_error("Tree is empty!");
    }
    return FindPointerToMin(root)->data;
}



//MinNRemove
template <typename Data>
Data BST<Data>::MinNRemove(){
    if (this->Empty()) {
        throw std::length_error("Tree is empty!");
    }
    return DataNDelete(DetachMin(root));
}



//RemoveMin
template <typename Data>
void BST<Data>::RemoveMin(){
    if (this->Empty()) {
        throw std::length_error("Tree is empty!");
    }
    delete DetachMin(root);  //delete del puntatore al nodo che restituisce DetachMin
}




//Max
template <typename Data>
const Data& BST<Data>::Max() const {
    if (this->Empty()) {
        throw std::length_error("Tree is empty !");
    }
    return FindPointerToMax(root)->data;
}




//MaxNDelete
template <typename Data>
Data BST<Data>::MaxNRemove() {
    if (this->Empty()) {
        throw std::length_error("Tree is empty !");
    }
    return DataNDelete(DetachMax(root));
}




//RemoveMax
template <typename Data>
void BST<Data>::RemoveMax(){
    if(this->Empty()) {
        throw std::length_error("Tree is empty!");
    }
    delete DetachMax(root);
}




//Predecessor
template <typename Data>
const Data& BST<Data>::Predecessor(const Data& dataIN) const {
    NodeLnk* const* tmp = FindPointerToPredecessor(root, dataIN);

    if(tmp == nullptr) {
        throw std::length_error("Predecessor not found!");
    }
    
    return (*tmp)->data;
}





//PredecessorNRemove
template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data& dataIN){
    NodeLnk** tmp = FindPointerToPredecessor(root, dataIN);

    if(tmp == nullptr) {
        throw std::length_error("Predecessor not found!");
    }
    
    return DataNDelete(Detach(*tmp));
}





//RemovePredecessor
template <typename Data>
void BST<Data>::RemovePredecessor(const Data& dataIN){
    NodeLnk** tmp = FindPointerToPredecessor(root, dataIN);

    if(tmp == nullptr) {
        throw std::length_error("Predecessor not found!");
    }
    
    delete Detach(*tmp);
}




//Successor
template <typename Data>
const Data& BST<Data>::Successor(const Data& dataIN) const{
    NodeLnk* const* tmp = FindPointerToSuccessor(root, dataIN);

    if(tmp == nullptr) {
        throw std::length_error("Successor not found!");
    }
    
    return (*tmp)->data;
}




//SuccessorNRemove
template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data& dataIN){
    NodeLnk** tmp = FindPointerToSuccessor(root, dataIN);

    if(tmp == nullptr) {
        throw std::length_error("Successor not found!");
    }
    
    return DataNDelete(Detach(*tmp));
}




//RemoveSuccessor
template <typename Data>
void BST<Data>::RemoveSuccessor(const Data& dataIN){
    NodeLnk** tmp = FindPointerToSuccessor(root, dataIN);

    if(tmp == nullptr) {
        throw std::length_error("Successor not found!");
    }
    
    delete Detach(*tmp);
}




//Root
template <typename Data>
const BinaryTree<Data>::Node& BST<Data>::Root() const {
    return BinaryTreeLnk<Data>::Root();
}




//Insert  (Copy of the value)
template <typename Data>
bool BST<Data>::Insert(const Data& dataIN) {
    NodeLnk*& tmp = FindPointerTo(root, dataIN);
    if(tmp != nullptr) {
        return false;
    } 

    size++;
    tmp = new NodeLnk(dataIN);
    return true;
}




//Insert (Move of the value)
template <typename Data>
bool BST<Data>::Insert(Data&& dataIN) noexcept {
    NodeLnk*& tmp = FindPointerTo(root, dataIN);
    if(tmp != nullptr) {
        return false;
    }

    size++;
    tmp = new NodeLnk(std::move(dataIN));
    return true;
}




//Remove
template <typename Data>
bool BST<Data>::Remove(const Data& dataIN) {
    NodeLnk*& tmp = FindPointerTo(root, dataIN);
    if(tmp != nullptr) {
        delete Detach(tmp);
        return true;
    } 
    return false;    
}




//Exists
template <typename Data>
bool BST<Data>::Exists(const Data& data) const noexcept {
    return !(FindPointerTo(root, data) == nullptr);
}




//Clear
template <typename Data>
void BST<Data>::Clear() {
    BinaryTreeLnk<Data>::Clear();
}




//DataNDelete
template <typename Data>
Data BST<Data>::DataNDelete(NodeLnk* node) {
    Data data {};
    std::swap(data, node->data);
    delete node;
    return data;
}



//Detach 
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Detach(NodeLnk*& node) noexcept{
    if(node != nullptr) {
        if(!node->HasLeftChild()){
            return Skip2Right(node);
        }
        else if(!node->HasRightChild()){
            return Skip2Left(node);
        }
        else {
            NodeLnk* tmp = DetachMax(node->LChild);
            std::swap(node->data, tmp->data);
            return tmp;
        }
    }
    return nullptr;
}




//DetachMin
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk*& node) noexcept{
    return Skip2Right(FindPointerToMin(node));
}



//DetachMax
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk*& node) noexcept{
    return Skip2Left(FindPointerToMax(node));
}



//Skip2Left
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Left(NodeLnk*& node) noexcept {
    NodeLnk* tmp = nullptr;
    if(node != nullptr) {
        std::swap(tmp, node->LChild);
        std::swap(tmp, node);
        size--;
    }
    return tmp;
}

 


//Skip2Right
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Right(NodeLnk*& node) noexcept {
    NodeLnk* tmp = nullptr;
    if(node != nullptr) {
        std::swap(tmp, node->RChild);
        std::swap(tmp, node);
        size--;
    }
    return tmp;
}




//FindPointerToMin  unmutable
template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(NodeLnk* const& node) const noexcept{
    NodeLnk* const* tmp = &node;

    if(*tmp != nullptr) {
        while((*tmp)->LChild != nullptr){
            tmp = &(*tmp)->LChild;
        }
    }

    return *tmp;
}





//FindPointerToMin mutable
template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(NodeLnk*& node) noexcept{
    return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMin(node));
}



//FindPointerToMax  unmutable
template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(NodeLnk* const& node) const noexcept{
    NodeLnk* const* tmp = &node;

    if(*tmp != nullptr) {
        while((*tmp)->RChild != nullptr){
            tmp = &(*tmp)->RChild;
        }
    }

    return *tmp;
}


//FindPointerToMax mutable
template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(NodeLnk*& node) noexcept{
    return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMax(node));
}



// //FindPointerTo unmutable
// template <typename Data>
// typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerTo(NodeLnk* const & node, const Data& dataIN) const noexcept{
//     NodeLnk* const* tmp = &node;

//     if(*tmp != nullptr) {
        
//         if ((*tmp)->data == dataIN) {
//             return *tmp;
//         } else if ((*tmp)->data > dataIN) {
//             tmp = & FindPointerTo(node->LChild,dataIN);
//         } else {
//             tmp = & FindPointerTo(node->RChild,dataIN);
//         }
//     }
//     return *tmp;
// }



// FindPointerTo unmutable   VERSIONE 2 Da controllare
template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerTo(NodeLnk* const & node, const Data& dataIN) const noexcept {
    if (node == nullptr || node->data == dataIN) {
        return node;
    } else if (node->data > dataIN) {
        return FindPointerTo(node->LChild, dataIN);
    } else {
        return FindPointerTo(node->RChild, dataIN);
    }
}


//FindPointerTo mutable
template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk*& node, const Data& dataIN) noexcept {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerTo(node, dataIN));
}



//FindPointerToPredecessor unmutable
template <typename Data>
typename BST<Data>::NodeLnk* const* BST<Data>::FindPointerToPredecessor(NodeLnk* const& node, const Data& dataIN) const noexcept{
    NodeLnk* const * currNode = &node;
    NodeLnk* const * last = nullptr;

    while(*currNode != nullptr && (*currNode)->data != dataIN) {
        if((*currNode)->data > dataIN) {
            currNode = &((*currNode)->LChild);
        } else if((*currNode)->data < dataIN) {
            last = currNode;
            currNode = &((*currNode)->RChild);
        }
    }

    if(*currNode != nullptr && (*currNode)->HasLeftChild()){
        return &FindPointerToMax((*currNode)->LChild);
    }

    return last;
}



//FindPointerToPredecessor mutable
template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToPredecessor(NodeLnk*& node, const Data& dataIN) noexcept{
    return const_cast<NodeLnk**>(static_cast<const BST<Data>*> (this)->FindPointerToPredecessor(node, dataIN));
}




//FindPointerToSuccessor unmutable
template <typename Data>
typename BST<Data>::NodeLnk* const* BST<Data>::FindPointerToSuccessor(NodeLnk* const& node, const Data& dataIN) const noexcept{
    NodeLnk* const * currNode = &node;
    NodeLnk* const * last = nullptr;

    while(*currNode != nullptr && (*currNode)->data != dataIN) {
        if((*currNode)->data > dataIN) {
            last = currNode;
            currNode = &((*currNode)->LChild);
        } else if((*currNode)->data < dataIN) {
            currNode = &((*currNode)->RChild);
        }
    }

    if(*currNode != nullptr && (*currNode)->HasRightChild()){
        return &FindPointerToMin((*currNode)->RChild);
    }

    return last;
}



//FindPointerToSuccessor mutable
template <typename Data>
typename BST<Data>::NodeLnk* * BST<Data>::FindPointerToSuccessor(NodeLnk*& node, const Data& data) noexcept {
    return const_cast<NodeLnk**>(static_cast<const BST<Data> *>(this)->FindPointerToSuccessor(node, data));
}

/* ************************************************************************** */

}
