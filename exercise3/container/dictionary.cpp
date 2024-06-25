
namespace lasd {

/* ************************************************************************** */
//InsertAll 
template<typename Data>
inline bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data>& TravCont) {
    bool check = true;
    TravCont.Traverse([this, &check](const Data& dato){
        check &= Insert(dato);
    }
    );
    return check;
}


//InsertAll 
template<typename Data>
inline bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data>&& MapCont) noexcept {
    bool check = true;
    MapCont.Map([this, &check](Data& dato){
        check &= Insert(std::move(dato));
    }
    );
    return check;
}

//RemoveAll 
template<typename Data>
inline bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data>& TravCont) {
    bool check = true;
    TravCont.Traverse([this, &check](const Data& dato){
        check &= Remove(dato);
    }
    );
    return check;
}

//InsertSome 
template<typename Data>
inline bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data>& TravCont){
    bool check = false;
    TravCont.Traverse([this, &check](const Data& dato){
        check |= Insert(dato);
    }
    );
    return check;
}

//InsertSome 
template<typename Data>
inline bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data>&& MapCont) noexcept {
    bool check = false;
    MapCont.Map([this, &check](Data& dato){
        check |= Insert(std::move(dato));
    }
    );
    return check;
}

//RemoveSome
template<typename Data>
inline bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data>& TravCont){
    bool check = false;
    TravCont.Traverse([this, &check](const Data& dato){
        check |= Remove(dato);
    }
    );
    return check;
}

/* ************************************************************************** */

}
