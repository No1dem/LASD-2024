
namespace lasd {

/* ************************************************************************** */

template<typename Data>
inline void PreOrderMappableContainer<Data>::Map(const MapFun func) {
    PreOrderMap(func);
};


template<typename Data>
inline void PostOrderMappableContainer<Data>::Map(const MapFun func) {
    PostOrderMap(func);
};


template<typename Data>
inline void InOrderMappableContainer<Data>::Map(const MapFun func) {
    InOrderMap(func);
};


template<typename Data>
inline void BreadthMappableContainer<Data>::Map(const MapFun func) {
    BreadthMap(func);
};

/* ************************************************************************** */

}
