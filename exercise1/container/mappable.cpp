
namespace lasd {

/* ************************************************************************** */

template<typename Data>
inline void PreOrderMappableContainer<Data>::Map(MapFun func) {
    PreOrderMap(func);
};


template<typename Data>
inline void PostOrderMappableContainer<Data>::Map(MapFun func) {
    PostOrderMap(func);
};


template<typename Data>
inline void InOrderMappableContainer<Data>::Map(MapFun func) {
    InOrderMap(func);
};


template<typename Data>
inline void BreadthMappableContainer<Data>::Map(MapFun func) {
    BreadthMap(func);
};

/* ************************************************************************** */

}
