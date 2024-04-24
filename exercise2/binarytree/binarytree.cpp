
namespace lasd {

/* ************************************************************************** */
//Node


//Operator ==

template<typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept {
    if (node.Element() != this->Element()) {
        return false;
    }

    bool onlyLeftChild = (node.HasLeftChild() && this->HasLeftChild());
    bool onlyRightChild = (node.HasRightChild() && this->HasRightChild());
    bool rightNLeftChild = onlyLeftChild && onlyRightChild;

    if (onlyLeftChild) {
        if(this->LeftChild() == node->LeftChild()) {
            return true;
        }
        return false;
    }
    else if (onlyRightChild) {
        if(this->RightChild() == node->RightChild()) {
            return true;
        }
        return false;
    }
    else if (rightNLeftChild) {
        if((this->LeftChild() == node->LeftChild()) && (this->RightChild() == node->RightChild())) {   //Ricorsione
            return true;
        }
        return false;
    }
    return false;
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
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun,const Node& node) const {
    if (node != nullptr) {
        fun(node.Element());

        if (node.HasLeftChild()) {
            PreOrderTraverse(fun, node.LeftChild());
        }

        if (node.HasRightChild()) {
            PreOrderTraverse(fun, node.RightChild());
        }
    }
    
}


//PostOrderTraverse
template<typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun,const Node& node) const {
    if (node != nullptr) {

        if (node.HasLeftChild()) {
            PostOrderTraverse(fun, node.LeftChild());
        }


        if (node.HasRightChild()) {
            PostOrderTraverse(fun, node.RightChild());
        }

        fun(node.Element());
    }
}


//InOrderTraverse
template<typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun,const Node& node) const {
    if (node != nullptr) {
       
        if (node.HasLeftChild()) {
            InOrderTraverse(fun, node.LeftChild());
        }

        fun(node.Element());

        if (node.HasRightChild()) {
            InOrderTraverse(fun, node.RightChild());
        }
    }

}


//BreadthTraverse
template<typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun fun, const Node& node) const {
    if (node != nullptr) {
        lasd::QueueVec<const Node&> queue;
        queue.Enqueue(node);

        while (!queue.Empty()) {
            const Node& currentNode = queue.Head();
            fun(currentNode.Element());

            if (currentNode.HasLeftChild()) {
                queue.Enqueue(currentNode.LeftChild());
            }

            if (currentNode.HasRightChild()) {
                queue.Enqueue(currentNode.RightChild());
            }

            queue.Dequeue();
        }
    }
}

/* ************************************************************************** */
//MutableBinaryTree

template<typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MapFun fun, MutableNode& node) {
    if (node != nullptr) {
        fun(node.Element());

        if (node.HasLeftChild()) {
            PreOrderTraverse(fun, node.LeftChild());
        }

        if (node.HasRightChild()) {
            PreOrderTraverse(fun, node.RightChild());
        }
    }
}




template<typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun fun, MutableNode& node) {
    if (node != nullptr) {
       
        if (node.HasLeftChild()) {
            PostOrderTraverse(fun, node.LeftChild());
        }

        if (node.HasRightChild()) {
            PostOrderTraverse(fun, node.RightChild());
        }

        fun(node.Element());
    }
}





template<typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun fun, MutableNode& node) {
    if (node != nullptr) {

        if (node.HasLeftChild()) {
            InOrderTraverse(fun, node.LeftChild());
        }

        fun(node.Element());

        if (node.HasRightChild()) {
            InOrderTraverse(fun, node.RightChild());
        }
    }
}


//BreadthTraverse
template<typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun fun, MutableNode& node) {
    if (node != nullptr) {
        lasd::QueueVec<const Node&> queue;
        queue.Enqueue(node);

        while (!queue.Empty()) {
            MutableNode& currentNode = queue.Head();
            fun(currentNode.Element());

            if (currentNode.HasLeftChild()) {
                queue.Enqueue(currentNode.LeftChild());
            }

            if (currentNode.HasRightChild()) {
                queue.Enqueue(currentNode.RightChild());
            }

            queue.Dequeue();
        }
    }
}

}
