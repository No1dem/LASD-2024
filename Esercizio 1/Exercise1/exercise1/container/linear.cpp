
namespace lasd {

/* ************************************************************************** */

//Operatore ==
template<typename Data>
inline bool LinearContainer<Data>::operator==(const LinearContainer& LinCont) const noexcept{
    if(size!=LinCont.size) {
        return false;
    } 
    for(unsigned long i = 0; i<size; i++) {
        if(operator[](i) != LinCont.operator[](i)){
            return false;
        }
    }
    return true;
}


//Operatore !=
template<typename Data>
inline bool LinearContainer<Data>::operator!=(const LinearContainer& LinCont) const noexcept{
    return !(*this == LinCont);
}


//Front versione Non-Mutable
template<typename Data>
inline const Data& LinearContainer<Data>::Front() const{
    if (size == 0){ throw std::length_error("Container is empty!"); }
    return operator[](0);
}


//Front versione Mutable
template<typename Data>
inline Data& LinearContainer<Data>::Front() {
    if (size == 0){ throw std::length_error("Container is empty!"); }
    return operator[](0);
}


//Back versione Non-Mutable
template<typename Data>
inline const Data& LinearContainer<Data>::Back() const{
    if (size == 0){ throw std::length_error("Container is empty!"); }
    return operator[](size-1);
}


//Back versione Mutable
template<typename Data>
inline Data& LinearContainer<Data>::Back() {
    if (size == 0){ throw std::length_error("Container is empty!"); }
    return operator[](size-1);
}


template <typename Data>
inline void LinearContainer<Data>::PreOrderTraverse(TraverseFun fun) const{
    for (unsigned long index = 0; index < size ; ++index){
        fun(operator[](index)); 
    }
}


template <typename Data>
inline void LinearContainer<Data>::PostOrderTraverse(TraverseFun fun) const{
    unsigned long index = size;
    while (index > 0){
        fun(operator[](--index));
    }
}


template<typename Data>
inline void Map(MapFun fun) const{
    PreOrderMap(fun);
}


template <typename Data>
inline void LinearContainer<Data>::PreOrderMap(MapFun fun){
    for (unsigned long index = 0; index < size ; ++index){
        fun(operator[](index));
    }    
}


template <typename Data>
inline void LinearContainer<Data>::PostOrderMap(MapFun fun){
    unsigned long index = size;
    while (index > 0){
        fun(operator[](--index));
    }
}


template<typename Data>
void SortableLinearContainer<Data>::Sort() noexcept { 
    QuickSort(0,size-1);
}


template<typename Data>
void SortableLinearContainer<Data>::QuickSort(unsigned long l,unsigned long r) noexcept{
    if (l < r) {
        unsigned long q = Partition(l, r);
        QuickSort(l, q);
        QuickSort(q + 1, r);
    }
}


template<typename Data>
void SortableLinearContainer<Data>::Partition(unsigned long l, unsigned long r) noexcept{
    Data z = operator[](l);
    unsigned long i = l - 1;
    unsigned long j = r + 1;

    do{
        do { j--; }
        while (z < operator[](j));
        do { i++; }
        while (x > operator[](i));
        if(i < j){ std::swap(operator[](i),operator[](j)); }
    }
    while (i < j);
    return j;
}


/* ************************************************************************** */

}
