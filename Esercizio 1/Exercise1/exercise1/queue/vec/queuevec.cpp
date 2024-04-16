
namespace lasd {

/* ************************************************************************** */

// Copy assignment
template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& qv){
    Vector<Data>::operator=(qv); 
    return *this;
}

// Move assignment
template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& qv) noexcept{
    Vector<Data>::operator=(std::move(qv)); 
    return *this;
}

/* ************************************************************************** */

}
