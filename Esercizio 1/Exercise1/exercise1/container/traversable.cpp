
namespace lasd {

/* ************************************************************************** */

inline Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> fun, Accumulator acc) const {
Traverse(
    [fun, &acc](const Data& dat){
        acc = fun(dat, acc);
    }
);
return acc;
}

template <typename Data>
inline bool TraversableContainer<Data>::Exists(const Data& val) const noexcept{
    bool exists = false;
    Traverse(
        [val, &exists](const Data& dat){
            exists |= (dat == val);   //exists = exists || (dot == val)
        }
    );
    return exists;
}
/* ************************************************************************** */

template <typename Data>
template <typename Accumulator>
inline Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator>, Accumulator){
    PreOrderTraverse(
        [fun, &acc](const Data& dat){
            acc = fun(dat, acc);
        }
    );
    return acc;
}

template <typename Data>
inline void PreOrderTraversableContainer<Data>::Traverse(TraverseFun fun) const {
    PreOrderTraverse(fun);
}


}
