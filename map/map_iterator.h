//
// Created by kirill_kazarin on 02.03.2022.
//

#include "map_tree_element.h"

#ifndef LAB2_MAP_ITERATOR_H
#define LAB2_MAP_ITERATOR_H

template<typename _type_node>
struct map_tree_iterator{

    map_tree_node_base* _base_of_iter;

public:

    explicit map_tree_iterator(map_tree_node_base *baseOfIter) : _base_of_iter(baseOfIter) {}

    ~map_tree_iterator() = default;

    map_tree_iterator& operator++() noexcept {
         _base_of_iter=fun_increment(this);

        return *this;
    }

    map_tree_iterator& operator--() noexcept {
        _base_of_iter=fun_decrement(this);
        return *this;
    }

    _type_node& operator*() noexcept {
        return *static_cast<tree_node<_type_node>*>(_base_of_iter)->_val;
     }

    _type_node& operator->() noexcept {
        return static_cast<tree_node<_type_node>*>(_base_of_iter)->_val;
    }



};

#endif //LAB2_MAP_ITERATOR_H
