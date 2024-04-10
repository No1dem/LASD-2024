
namespace lasd {

/* ************************************************************************** */
//InsertAll versione Non-Mutable
template<typename Data>
bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data>& TravCont) {
    bool check = true;
    TravCont.Traverse([this, &check](const Data& dato){
        check = Insert(dato);
    }
    );
    return check;
}


//InsertAll versione Mutable
template<typename Data>
bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data>&& MapCont) noexcept {
    bool check = true;
    MapCont.Map([this, &check](Data& dato){
        check = Insert(std::move(dato));
    }
    );
    return check;
}

//RemoveAll 
template<typename Data>
bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data>& TravCont) {
    bool check = true;
    TravCont.Traverse([this, &check](const Data& dato){
        check = Remove(dato);
    }
    );
    return check;
}

//InsertSome versione Non-Mutable
template<typename Data>
bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data>& TravCont){
    bool check = false;
    TravCont.Traverse([this, &check](const Data& dato){
        check |= Insert(dato);
    }
    );
    return check;
}

//InsertSome versione Mutable 
template<typename Data>
bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data>&& MapCont) noexcept {
    bool check = false;
    MapCont.Traverse([this, &check](Data& dato){
        check |= Insert(std::move(dato));
    }
    );
    return check;
}

//RemoveSome
template<typename Data>
bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data>& TravCont){
    bool check = false;
    TravCont.Traverse([this, &check](const Data& dato){
        check |= Remove(dato);
    }
    );
    return check;
}

/* ************************************************************************** */

}
