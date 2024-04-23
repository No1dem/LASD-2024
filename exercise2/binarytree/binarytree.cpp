
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
template <typename Data>
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
/* ************************************************************************** */

}
