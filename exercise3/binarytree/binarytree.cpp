
namespace lasd {

/* ************************************************************************** */
//Node


//Operator ==
template<typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept {
    if (node.Element() != this->Element()) {
        return false;
    }

    bool LeftChild = (node.HasLeftChild() && this->HasLeftChild());
    bool RightChild = (node.HasRightChild() && this->HasRightChild());
    bool RightNLeftChild = LeftChild && RightChild;

    if (RightNLeftChild) {
        if((this->LeftChild() == node.LeftChild()) && (this->RightChild() == node.RightChild())) {   //Ricorsione
            return true;
        } else {
            return false;
        }
    } else if (LeftChild) {
        if(this->LeftChild() == node.LeftChild()) {
            return true;
        } else {
            return false;
        }
    }
    else if (RightChild) {
        if(this->RightChild() == node.RightChild()) {
            return true;
        } else {
            return false;
        }
    }
    return true;    //No childs  
}

/*******************************************************************************/
//Binary Tree


//Operator ==
template<typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data>& bt) const noexcept {
    if(size == bt.size) {
        if(size == 0) {
            return true;
        } else {
            return (this->Root() == bt.Root());
        }
    }
    return false;
}


//PreOrderTraverse
template<typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun,const Node* node) const {
    if (node != nullptr) {
        fun(node->Element());

        if (node->HasLeftChild()) {
            PreOrderTraverse(fun, &node->LeftChild());
        }

        if (node->HasRightChild()) {
            PreOrderTraverse(fun, &node->RightChild());
        }
    }
    
}


//PostOrderTraverse
template<typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun,const Node* node) const {
    if (node != nullptr) {

        if (node->HasLeftChild()) {
            PostOrderTraverse(fun, &node->LeftChild());
        }


        if (node->HasRightChild()) {
            PostOrderTraverse(fun, &node->RightChild());
        }

        fun(node->Element());
    }
}


//InOrderTraverse
template<typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun,const Node* node) const {
    if (node != nullptr) {
       
        if (node->HasLeftChild()) {
            InOrderTraverse(fun, &node->LeftChild());
        }

        fun(node->Element());

        if (node->HasRightChild()) {
            InOrderTraverse(fun, &node->RightChild());
        }
    }

}


//BreadthTraverse
template<typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun fun, const Node* node) const {
    if (node != nullptr) {
        lasd::QueueVec<const Node*> queue;
        queue.Enqueue(node);

        while (!queue.Empty()) {
            const Node* currentNode = queue.Head();
            fun(currentNode->Element());

            if (currentNode->HasLeftChild()) {
                queue.Enqueue(&currentNode->LeftChild());
            }

            if (currentNode->HasRightChild()) {
                queue.Enqueue(&currentNode->RightChild());
            }

            queue.Dequeue();
        }
    }
}

/* ************************************************************************** */
//MutableBinaryTree

//PreOrderMap
template<typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MapFun fun, MutableNode* node) {
    if (node != nullptr) {
        fun(node->Element());

        if (node->HasLeftChild()) {
            PreOrderMap(fun, &node->LeftChild());
        }

        if (node->HasRightChild()) {
            PreOrderMap(fun, &node->RightChild());
        }
    }
}



//PostOrderMap
template<typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun fun, MutableNode* node) {
    if (node != nullptr) {
       
        if (node->HasLeftChild()) {
            PostOrderMap(fun, &node->LeftChild());
        }

        if (node->HasRightChild()) {
            PostOrderMap(fun, &node->RightChild());
        }

        fun(node->Element());
    }
}




//InOrderMap
template<typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun fun, MutableNode* node) {
    if (node != nullptr) {

        if (node->HasLeftChild()) {
            InOrderMap(fun, &node->LeftChild());
        }

        fun(node->Element());

        if (node->HasRightChild()) {
            InOrderMap(fun, &node->RightChild());
        }
    }
}


//BreadthMap
template<typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun fun, MutableNode* node) {
    if (node != nullptr) {
        lasd::QueueVec<MutableNode*> queue;
        queue.Enqueue(node);

        while (!queue.Empty()) {
            MutableNode* currentNode = queue.Head();
            fun(currentNode->Element());

            if (currentNode->HasLeftChild()) {
                queue.Enqueue(&currentNode->LeftChild());
            }

            if (currentNode->HasRightChild()) {
                queue.Enqueue(&currentNode->RightChild());
            }

            queue.Dequeue();
        }
    }
}

/**************************************************************************/
//BTPreOrderIterator


//Specific constructor
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& bt) {
    if (bt.Size() != 0) {
        root = &bt.Root();
        currNode = root;
    }
}


//Copy constructor 
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data>& iterator) {
        root = iterator.root;
        currNode = iterator.currNode;
        stk = iterator.stk;
}


//Move constructor
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& iterator) noexcept {
        std::swap(root, iterator.root);
        std::swap(currNode, iterator.currNode);
        std::swap(stk, iterator.stk);
}

// Copy assignment
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data>& iterator) {
    root = iterator.root;
    stk = iterator.stk;
    currNode = iterator.currNode;
    return *this;
}

// Move assignment
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& iterator) noexcept {
    std::swap(root, iterator.root);
    std::swap(stk, iterator.stk); 
    std::swap(currNode, iterator.currNode);
    return *this;
}



//Operator *
template<typename Data>
inline const Data& BTPreOrderIterator<Data>::operator*() const {
    if (Terminated()) {
        throw std::out_of_range("Iterator terminated !");
    }
    return currNode->Element();
}



//Operator ++
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++() {
    if (Terminated()) {
        throw std::out_of_range("Iterator terminated !");
    }

    if (currNode != nullptr) {
        if (currNode->HasLeftChild() && currNode->HasRightChild()) {
            stk.Push(&(currNode->RightChild()));
        }

        if (currNode->HasLeftChild()) {
            currNode = &(currNode->LeftChild());

        } else if (currNode->HasRightChild()) {
            currNode = &(currNode->RightChild());

        } else if (!stk.Empty()) {
            currNode = stk.TopNPop();

        } else {
            currNode = nullptr;
        }
    }
    
    return *this;
}






//Reset
template <typename Data>
inline void BTPreOrderIterator<Data>::Reset() noexcept {
    stk.Clear();
    currNode = root;
}


/************************************************************************/
//BTPreOrderMutableIterator 


template<typename Data>
inline Data& BTPreOrderMutableIterator<Data>::operator*() {
    if(this->Terminated()) {
      throw std::out_of_range("Iterator Terminated!");
    } 
    return const_cast<Data&>(currNode->Element());
}

/************************************************************************/
//BTPostOrderIterator


//Specific constructor
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& bt) {
    if(bt.Size() != 0) {
        root = &bt.Root();
        currNode = root;
        LeftMostLeaf();
    }
}

// Copy constructor
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator& it) {
    root = it.root;
    currNode = it.currNode;
    stk = it.stk;
}



//Move constructor
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator&& it) noexcept {
    std::swap(root, it.root);
    std::swap(currNode, it.currNode);
    std::swap(stk, it.stk);
}


//Copy assignemnt
template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator& it) {
    root = it.root;
    currNode = it.currNode;
    stk = it.stk;
    return *this;
}




//Move assignment
template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator&& it) noexcept {
    std::swap(root, it.root);
    std::swap(currNode, it.currNode);
    std::swap(stk, it.stk);
    return *this;
}

//Operator *
template<typename Data>
const Data& BTPostOrderIterator<Data>::operator*() const {
    if(Terminated()) {
      throw std::out_of_range("Iterator terminated!");
    }
    return currNode->Element();
}


//Operator ++
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++() {
    if(Terminated()) {
        throw std::out_of_range("Iterator Terminated!");
    }

    if(!stk.Empty()) {
        if(stk.Top()->HasRightChild() && (&stk.Top()->RightChild() != currNode)) {
            currNode = &stk.Top()->RightChild();
            LeftMostLeaf();
        } else {
            currNode = stk.TopNPop();
        }
    } else {
        currNode = nullptr;
    }
    return *this;
}




//Reset
template<typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept {
    stk.Clear();
    currNode = root;
    LeftMostLeaf();
}




//LeftMostLeaf
template <typename Data>
void BTPostOrderIterator<Data>::LeftMostLeaf() {
    if (currNode != nullptr) {
        while (currNode->HasLeftChild() || currNode->HasRightChild()) {
            if (currNode->HasLeftChild()) {
                stk.Push(currNode);
                currNode = &currNode->LeftChild();
            } else {
                stk.Push(currNode);
                currNode = &currNode->RightChild();
            }
        }
    }
}


/********************************************************************************/
//BTPostOrderMutableIterator

//Operator *
template<typename Data>
Data& BTPostOrderMutableIterator<Data>::operator*() {
    if (this->Terminated()) {
        throw std::out_of_range("Iterator terminated !");
    }

    return const_cast<Data&>(currNode->Element());
}

/*******************************************************************************/
//BTInOrderIterator

//Specific constructor
template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& bt) {
    if (bt.Size() != 0) {
        root = &bt.Root();
        currNode = root;
        LeftMostNode();
    }
}



//Copy constructor
template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator& it) {
    root = it.root;
    currNode = it.currNode;
    stk = it.stk;
}



//Move constructor
template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator&& it) noexcept {
    std::swap(root, it.root);
    std::swap(currNode, it.currNode);
    std::swap(stk, it.stk);
}



//Copy assignment
template<typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator& it) {
    root = it.root;
    currNode = it.currNode;
    stk = it.stk;
    return *this;
}


//Move assigment 
template<typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator&& it) noexcept {
    std::swap(root, it.root);
    std::swap(currNode, it.currNode);
    std::swap(stk, it.stk);
    return *this;
}



//Operator *
template<typename Data>
const Data& BTInOrderIterator<Data>::operator*() const {
    if(Terminated()) {
        throw std::out_of_range("Iterator terminated !");
    } 
    return currNode->Element();
}



//Operator ++
template<typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++() {
    if(!Terminated()) {
        if (currNode->HasRightChild()) {
            currNode = &(currNode->RightChild());
            LeftMostNode();
        } else {
            if (stk.Empty()) {
                currNode = nullptr;
            } else {
                currNode = stk.TopNPop();
            }   
        }
        return *this;
    } else {
        throw std::out_of_range("Iterator terminated !");
    }
}




//Reset 
template<typename Data>
void BTInOrderIterator<Data>::Reset() noexcept {
    stk.Clear();
    currNode = root;
    LeftMostNode();
}



//LeftMostNode
template<typename Data>
void BTInOrderIterator<Data>::LeftMostNode() {
    if (!Terminated()) {
        while (currNode->HasLeftChild()) {
            stk.Push(currNode);
            currNode = &currNode->LeftChild();
        }
    }
}

/*******************************************************************************/
//BTInOrderMutableIterator

//Operator *
template<typename Data>
Data& BTInOrderMutableIterator<Data>::operator*() {
    if(currNode != nullptr) {
      return const_cast<Data&>(currNode->Element());
    } else {
      throw std::out_of_range("Iterator terminated !");
    }
} 

/*******************************************************************************/
//BTBreadthIterator

// Specific constructors
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& bt) {
    if(bt.Size() != 0) {
      root = &(bt.Root());
      currNode = root;
    }
}



//Copy Constructor
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator& it) {
    root = it.root;
    currNode = it.currNode;
    que = it.que;
}



//Move Constructor
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator&& it) noexcept {
    std::swap(root, it.root);
    std::swap(currNode, it.currNode);
    std::swap(que, it.que);
}




//Copy assignment
template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator& it) {
    root = it.root;
    currNode = it.currNode;
    que = it.que;
    return *this;
}




//Move assignment
template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator&& it) noexcept {
    std::swap(root, it.root);
    std::swap(currNode, it.currNode);
    std::swap(que, it.que);
    return *this;
}



//Operator *
template<typename Data>
const Data& BTBreadthIterator<Data>::operator*() const {
    if(!Terminated()) {
      return currNode->Element();
    } else {
      throw std::out_of_range("Iterator terminated !");
    }
}


//Operator ++
template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++() {
    if (!Terminated()) {
        if (currNode->HasLeftChild()) {
            que.Enqueue(&currNode->LeftChild());
        }
        if (currNode->HasRightChild()) {
            que.Enqueue(&currNode->RightChild());
        }
        if (que.Empty()) {
            currNode = nullptr;
        } else {
            currNode = que.HeadNDequeue();
        }
        return *this;
    } else {
        throw std::out_of_range("Iterator terminated !");
    }
}



//Reset
template<typename Data>
void BTBreadthIterator<Data>::Reset() noexcept {
    currNode = root;
    que.Clear();
}

/*******************************************************************************/
//BTBreadthMutableIterator


//Operator *
template<typename Data>
Data& BTBreadthMutableIterator<Data>::operator*() {
    if (this->Terminated()) {
        throw std::out_of_range("Iterator terminated !");
    } 
    return const_cast<Data&>(currNode->Element()); 
}




}
