//
// Created by kirill_kazarin on 20.03.2022.
//

#ifndef LAB2_FUN_MAP_ITER_H
#define LAB2_FUN_MAP_ITER_H


#include "map_iterator.h"

//std::stack<map_tree_node_base*> stack_of_heads{};
//map_tree_node_base* previos_iter;

map_tree_node_base* fun_increment(map_tree_node_base*) noexcept;/* {
    *//*для корня дерева*//*
    if(treeElem.parent== nullptr)return treeElem;

    if(!treeElem->is_tree_leaf() &&
       previos_iter==treeElem->left){

        stack_of_heads.push(treeElem);

        previos_iter=treeElem;

        treeElem=
                treeElem->right->return_min_element();
        return treeElem;
    }

    while(!stack_of_heads.empty() && treeElem->parent==stack_of_heads.top()){
        previos_iter=treeElem;
        treeElem=stack_of_heads.top();
        stack_of_heads.pop();
    }

    previos_iter=treeElem;
    treeElem=treeElem->parent;

    return *this;
}*/

map_tree_node_base* fun_decrement(map_tree_node_base*) noexcept;/* {

    if(!treeElem->is_tree_leaf() &&
       previos_iter==treeElem->left){

        treeElem=previos_iter;
        while (treeElem->right!= nullptr){
            stack_of_heads.push(treeElem);
            treeElem=treeElem->right;
        }
        previos_iter=treeElem->parent;

        return treeElem;
    }
    *//*нужно немного дописать*//*
    return *this;
}*/
#endif //LAB2_FUN_MAP_ITER_H
