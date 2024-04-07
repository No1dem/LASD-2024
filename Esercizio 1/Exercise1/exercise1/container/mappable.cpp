
namespace lasd {

/* ************************************************************************** */

template<typename Data>
inline void PreOrderMappableContainer<Data>::Map(MapFun func) const override{
    PreOrderMap(func);
};


template<typename Data>
inline void PostOrderMappableContainer<Data>::Map(MapFun func) const override{
    PostOrderMap(func);
};


template<typename Data>
inline void InOrderMappableContainer<Data>::Map(MapFun func) const override{
    InOrderMap(func);
};


template<typename Data>
inline void BreadthMappableContainer<Data>::Map(MapFun func) const override{
    BreadthMap(func);
};

/* ************************************************************************** */

}
