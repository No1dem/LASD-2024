
namespace lasd {

/* ************************************************************************** */
//NodeVec


//Specific constructor
template<typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data & d, unsigned long i, Vector<NodeVec*> * vec) {
    data = d;
    currIndex = i;
    childsVec = vec;
}


//Copy assignment
template<typename Data>
BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(const NodeVec& node) {
    data = node.data;
    currIndex = node.currIndex;
    childsVec = node.childsVec;
    return *this;
}

//Move assignment
template<typename Data>
BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(NodeVec&& node) noexcept {
    std::swap(data, node.data);
    std::swap(currIndex, node.currIndex);
    std::swap(childsVec, node.childsVec);
    return *this;
}



//Element
template<typename Data>
inline const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
    return data;
}




//Element versione mutable
template<typename Data>
inline Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept {
    return data;
}



//isLeaf
template<typename Data>
inline bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept {
    return ((2*currIndex+1) >= childsVec->Size());
}



//HasRightChild
template<typename Data>
inline bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    return ((2*currIndex+2) < childsVec->Size());
}



//HasLeftChild
template<typename Data>
inline bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
    return ((2*currIndex+1) < childsVec->Size());
}


//RightChild
template<typename Data>
const BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec::RightChild() const {
    if(!HasRightChild()) {
        throw std::out_of_range("Right child doesn't exist !");
    } 

    return *childsVec->operator[](2*currIndex+2);
}


//LeftChild
template<typename Data>
const BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    if(!HasLeftChild()) {
        throw std::out_of_range("Left child doesn't exist !");
    } 

    return *childsVec->operator[](2*currIndex+1);
}


//RightChild mutable
template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::RightChild() {
    if(!HasRightChild()) {
        throw std::out_of_range("Right child doesn't exist !");
    } 

    return *childsVec->operator[](2*currIndex+2);

}




//LeftChild mutable
template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::LeftChild() {
    if(!HasLeftChild()) {
        throw std::out_of_range("Left child doesn't exist !");
    } 

    return *childsVec->operator[](2*currIndex+1);
}

/* ************************************************************************** */
//BinaryTreeVec



//Specific constructors

template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data>& TravCon) {
    size = TravCon.Size();
    if(size > 0) {
        treeVec = new Vector<NodeVec*>(size);
        unsigned long idx = 0;
        TravCon.Traverse([this, &idx](const Data& data) {
            NodeVec* node = new NodeVec(data, idx, treeVec);
            (*treeVec)[idx] = node;
            idx++;
        });
    }
}



template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data>&& MapCon) noexcept {
    size = MapCon.Size();
    if(size > 0) {
        treeVec = new Vector<NodeVec*>(size);
        unsigned long idx = 0;
        MapCon.Map([this, &idx](Data& data) {
            NodeVec* node = new NodeVec(data, idx, treeVec);
            (*treeVec)[idx] = node;
            idx++;
        });
    }
}



//Copy constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& bt) {
    size = bt.Size();
    if(size > 0) {
        treeVec =  new Vector<NodeVec*>(size);
        for(unsigned long i=0; i<size; i++) {
            NodeVec* tmp = new NodeVec((*bt.treeVec)[i]->Element(), i, treeVec);
            (*treeVec)[i] = tmp;
        }
    }
    
}

//Move constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& bt) noexcept {
    std::swap(size, bt.size);
    std::swap(treeVec, bt.treeVec);
}



//Destructor
template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec() {
    Clear();
    delete treeVec;
    treeVec = nullptr;
}




//Copy assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& bt) {
    if (this != &bt) {
        BinaryTreeVec<Data>* tmp = new BinaryTreeVec<Data>(bt);
        std::swap(*this, *tmp);
        delete tmp;
    }
    return *this;
}

//Move assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& bt) noexcept {
    std::swap(size, bt.size);
    std::swap(treeVec, bt.treeVec);
    return *this;
}


//Root
template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeVec<Data>::Root() const {
    if(size > 0) {
        return *treeVec->operator[](0);
    } else {
        throw std::length_error("Tree is empty !");
    }
}



//Root versione mutable 
template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::Root() {
    if(size > 0) {
        return *treeVec->operator[](0);
    } else {
        throw std::length_error("Tree is empty !");
    }
}



//Clear
template <typename Data>
void BinaryTreeVec<Data>::Clear() {
    if(size > 0) {
        for(unsigned long i=0; i<size; i++) {
            if((*treeVec)[i] != nullptr) {
                delete (*treeVec)[i];
            }
        }
        treeVec->Clear();
        size = 0;
    }
}




//BreadthTraverse
template <typename Data>
void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun fun) const {
    for(unsigned long i=0; i<size; i++) {
        if((*treeVec)[i] != nullptr) {
            fun((*treeVec)[i]->Element());
        }
    }
}





//BreadthMap
template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MapFun fun) {
    for(unsigned long i=0; i<size; i++) {
        if((*treeVec)[i] != nullptr) {
            fun((*treeVec)[i]->Element());
        }
    }
}



}
