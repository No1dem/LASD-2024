
namespace lasd {

/* ************************************************************************** */
/*Vector*/

//Constructor with a given dimension
template<typename Date>
Vector<Data>::Vector(const unsigned long NewSize){
    size = NewSize;
    Elements = new Data[size] {}; 
}


//Constructor from TraversableContainer 
template<typename Data>
Vector<Data>::Vector(const TraversableContainer<Data>&  TravCont) : Vector(TravCont.Size()){
    unsigned long index = 0;
    TravCont.Traverse(
        [this, &index](const Data& dato){
            Elements[index++] = dato;
        }
    );
}


//Constructor from MappableContainer
template<typename Data>
Vector<Data>::Vector(MappableContainer<Data>&& MapCont) : Vector(MapCont.Size()){
    unsigned long index = 0;
    MapCont.Map(
        [this, &index](Data& dato){
            Elements[index++] = std::move(dato);
        }
    );
}


//Copy constructor
template<typename Data>
Vector<Data>::Vector(const Vector<Data>& vector){
    size = vector.size;
    Elements = new Data[size] {};
    std::copy(vector.Elements, vector.Elements + size, Elements)
}


//Move constructor
template<typename Data>
Vector<Data>::Vector(Vector<Data>&& vector) noexcept{  /*controllla input*/
    std::swap(size,vector.size);
    std::swap(Elements,vector.Elements);
}


//Destructor 
template<typename Data>
Vector<Data>::~Vector(){
    delete[] Elements;
}


//Copy Assignment
template <typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector<Data>& vector) {
    Vector<Data>* tmp = new Vector<Data>(vector);
    std::swap(*tmp, *this);
    delete tmp;
    return *this;
}


//Move Assignment
template <typename Data>
Vector<Data>& Vector<Data>::operator=(Vector<Data>&& vector) {
    std::swap(vector.size, size);
    std::swap(vector.Elements, Elements);
    return *this;
}


//Comparison ==
template<typename Data>
bool Vector<Data>::operator==(const Vector& vector) const noexcept{
    if(size != vector.size) {
        return false;
    } for(unsigned long index = 0; index < size; index++) {
        if(Elements[index]!= vector.Elements[index]) {
            return false;
        }
    }
    return true;
}


//Comparison !=
template<typename Data>
bool Vector<Data>::operator!=(const Vector& vector) const noexcept{
    return !(*this == vector);
}



//Clear 
template<typename Data>
void Vector<Data>::Clear() {
    delete[] Elements;
    size = 0;
    Elements = nullptr;
}


//Resize 
template<typename Data>
void Vector<Data>::Resize(unsigned long NewSize) {
    if(NewSize != size && NewSize > 0){
        Data* temp = new Data[NewSize] {};
        unsigned long min;
        if (size < newSize){
            min = size;
        }
        else{
            min = NewSize;
        }
        for(unsigned long i = 0; i < min; i++) {
            std::swap(Elements[i], temp[i]);
        }
        std::swap(Elements, temp);
        size = NewSize;
        delete[] temp;
    }
    else if (NewSize == 0){
        Clear();
    }
}

//Operatore [] versione Non-Mutable
template<typename Data>
const Data& Vector<Data>::operator[](const unsigned long index) const {
    if(index > size){
        throw std::out_of_range("Out of bounds!");
    } 
    else {
        return Elements[index];
    }
}


//Operatore [] versione Mutable
template<typename Data>
Data& Vector<Data>::operator[](const unsigned long index) {
    if(index > size){
        throw std::out_of_range("Out of bounds!");
    } 
    else {
        return Elements[index];
    }
}


//Front versione Non-Mutable
template<typename Data>
const Data& Vector<Data>::Front() const{
    if (size == 0){
        throw std::length_error("Vector is empty!");
    }
    else {
        return Elements[0];
    }
}


//Front versione Mutable
template<typename Data>
Data& Vector<Data>::Front() {
    if (size == 0){
        throw std::length_error("Vector is empty!");
    }
    else {
        return Elements[0];
    }
}


//Back versione Non-Mutable
template <typename Data>
const Data& Vector<Data>::Back() const {
    if(size == 0) {
        throw std::length_error("Vector is empty!");
    } else {
        return Elements[size-1];
    }
}


//Back versione mutable
template <typename Data>
Data& Vector<Data>::Back() {
    if(size == 0) {
        throw std::length_error("Vector is empty!");
    } else {
        return Elements[size-1];
    }
}
/* ************************************************************************** */
/*Sortable Vector*/


// Specific constructors
template<typename Data>
SortableVector<Data>::SortableVector(const unsigned long NewSize) : Vector<Data>(NewSize) {};


template<typename Data>
SortableVector<Data>::SortableVector(const TraversableContainer<Data>& TravCont) : Vector<Data>(TravCont) {};


template<typename Data>
SortableVector<Data>::SortableVector(MappableContainer<Data>&& MapCont) :  Vector<Data>(std::move(MapCont)) {};


//Copy Contructor
template<typename Data>
SortableVector<Data>::SortableVector(const SortableVector<Data>& vector) : Vector<Data>(vector) {};


//Move Constructor
template<typename Data>
SortableVector<Data>::SortableVector(SortableVector<Data>&& vector) noexcept : Vector<Data>(std::move(vector)) {};


//Copy Assignment
template<typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector<Data>& vector) {
    Vector<Data>::operator=(vector);
    return *this;
}


//Move Assignment
template<typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(SortableVector<Data>&& vector) noexcept {
    Vector<Data>::operator=(std::move(vector));
    return *this;
}

}
