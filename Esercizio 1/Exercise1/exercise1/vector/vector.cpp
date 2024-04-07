
namespace lasd {

/* ************************************************************************** */


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
Vector<Data>::Vector(const Vector<Data>& vector) noexcept{
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
bool Vector<Data>::operator==(const Vector&) const noexcept{
    
}


//Comparison !=



//Clear 
template<typename Data>
void Vector::Clear() override{

}

/* ************************************************************************** */

}
