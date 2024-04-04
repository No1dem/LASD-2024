
namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline void LinearContainer<Data>::PreOrderTraverse(Traverse ){
    for (ulong index = 0; index < size ; ++index){
        fun(operator[](--index)); /*controlla*/
    }
}

/* ************************************************************************** */

}
