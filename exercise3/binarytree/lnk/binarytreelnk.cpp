
namespace lasd {

/* ************************************************************************** */
//NodeLnk


//Specific constructor
template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& data) {
    this->data = data;
}



template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& data) noexcept {
    std::swap(this->data,data);
}



//Copy constructor 
template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk& node) {
    if(node.LeftChild != nullptr) {
        LChild = new NodeLnk(*node.LChild);
    }

    if(node.RChild != nullptr) {
        RChild = new NodeLnk(*node.RChild);
    }

    data = node.data;
}



//Move constructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk&& node) noexcept {
    std::swap(data, node.data);
    std::swap(LChild, node.LChild);
    std::swap(RChild, node.RChild);
}



//Destructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk() {
    delete LChild;
    delete RChild;
}


//Copy assignment
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk& node) {
    if (this != &node) {
        data = node.data;

        if(node.HasLeftChild()) {
            LChild = node.LChild;
        }

        if(node.HasRightChild()) {
            RChild = node.RChild;
        }

        return *this;
    }
}




//Move assignment
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& node) noexcept {
    std::swap(data, node.data);
    std::swap(LChild, node.LChild);
    std::swap(RChild, node.RChild);
    return *this;
}


//Operator ==
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator==(const NodeLnk& node) const noexcept {
    if(data != node.data) {
        return false;
    }

    bool LChild = node->HasLeftChild();
    bool RChild = node->HasRightChild();
    bool LNRChild = LChild && RChild;

    if (LNRChild) {
        if (&node->LeftChild() == this->LeftChild() && &node->RightChild() == this->RightChild()) {
            return true;
        } else {
            return false;
        }
    } else if (LChild) {
        if (&node->LeftChild() == this->LeftChild()) {
            return true;
        } else {
            return false;
        }
    } else if (RChild) {
        if (&node->RightChild() == this->RightChild()) {
            return true;
        } else {
            return false;
        }
    }
    return true;
}


//Specific function

//Element versione non mutable
template <typename Data>
inline const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept {
    return data;
}




//Element versione mutable
template <typename Data>
inline Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept {
    return data;
}




//isLeaf
template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept {
    return (!(HasLeftChild()) && !(HasRightChild()));
}




//HasRightChild
template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
    return (RChild != nullptr);
}



//HasLeftChild
template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {
    return (LChild != nullptr);
}



//RightChild
template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::RightChild() const {
    if(!HasRightChild()) {
        throw std::out_of_range("No Right child !");
    } 
    return *RChild;
}

//LeftChild
template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {
    if(!HasLeftChild()) {
        throw std::out_of_range("No Left child !");    
    } 
    return *LChild;
}

//RightChild mutable
template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::RightChild() {
    if(!HasRightChild()) {
        throw std::out_of_range("No Right child !");
    }
    return *RChild;
}

//LeftChild mutable
template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::LeftChild() {
    if(!HasLeftChild()) {
        throw std::out_of_range("No Left child !"); 
    }
    return *LChild;
}

/* ************************************************************************** */
//BinaryTreeLnk


//Specific constructors

//TraversableContainer
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data>& TravCon) {
    size = TravCon.Size();
    QueueVec<NodeLnk**> que;
    que.Enqueue(&root);
    TravCon.Traverse([&que](const Data& data) {
        NodeLnk*& tmp = *que.HeadNDequeue();
        tmp = new NodeLnk(data);
        que.Enqueue(&tmp->LChild);
        que.Enqueue(&tmp->RChild);
    });
}


//MappableContainer
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data>&& MapCon) noexcept {
    size = MapCon.Size();
    QueueVec<NodeLnk**> que;
    que.Enqueue(&root);
    MapCon.Map([&que](Data& data) {
        NodeLnk*& tmp = *que.HeadNDequeue();
        tmp = new NodeLnk(std::move(data));
        que.Enqueue(&tmp->left);
        que.Enqueue(&tmp->right);
    });
}




//Copy constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk& bt) {
    size = bt.Size();
    if(bt.Size() > 0) {
        root = CopyTree(bt.root);
    }
}


//Copy assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk& bt) {
    if(bt.Size() == 0) {
        Clear();
    } else {
        if (this != &bt) {
            BinaryTreeLnk<Data>* tmp = new BinaryTreeLnk<Data>(bt);
            std::swap(*tmp, *this);
            delete tmp;
        }
    }
    return *this;
}


//Move assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk&& bt) noexcept {
    std::swap(root, bt.root);
    std::swap(size, bt.size);
    return *this;
}


//Move constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk&& bt) noexcept {
        std::swap(root, bt.root);
        std::swap(size, bt.size);
}
    



//Destructor
template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk() {
    Clear();
}


//Operator ==
template <typename Data>
inline bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk& bt) const noexcept {
    return BinaryTree<Data>::operator==(bt);
}



//Root
template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeLnk<Data>::Root() const {
    if(root == nullptr) {
        throw std::length_error("Tree is empty !");
    } 
    return *root;
}

//Root mutable 
template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeLnk<Data>::Root() {
    if(root == nullptr) {
        throw std::length_error("Tree is empty !");
    }
    return *root;
}


//Clear
template <typename Data>
void BinaryTreeLnk<Data>::Clear() {
    delete root;
    size = 0;
    root = nullptr;
}



//CopyTree
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::CopyTree(NodeLnk* node) {
    if(node == nullptr) {
        return nullptr; 
    }

    NodeLnk* NewNode = new NodeLnk(node->data);
    
    NewNode->LChild = CopyTree(node->LChild);
    
    NewNode->RChild = CopyTree(node->RChild);
    
    return NewNode; 
}


}
