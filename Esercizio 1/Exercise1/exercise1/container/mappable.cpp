
namespace lasd {

/* ************************************************************************** */

template<typename Data>
inline void PreOrderMappableContainer<Data>::Map(MapFun func) const {
    PreOrderMap(func);
};


template<typename Data>
inline void PostOrderMappableContainer<Data>::Map(MapFun func) const {
    PostOrderMap(func);
};


template<typename Data>
inline void InOrderMappableContainer<Data>::Map(MapFun func) const {
    InOrderMap(func);
};


template<typename Data>
inline void BreadthMappableContainer<Data>::Map(MapFun func) const {
    BreadthMap(func);
};

/* ************************************************************************** */

}
