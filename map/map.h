//
// Created by kirill_kazarin on 21.03.2022.
//

#include "tree_for_map.h"
#include "map_iterator.h"

#ifndef LAB2_MAP_H
#define LAB2_MAP_H

namespace h_work{

    template<typename _key_type,typename _mapped_type,
            typename _type_of_tree_node=map_tree_RB_node<_key_type,_mapped_type>,
            typename _compare=std::less<_key_type>>
    class map {
    public:

        //тип элемента который лежит в узлах дерева
        typedef std::pair<_key_type,_mapped_type> tree_elem;

        //тип дерева
        typedef tree_for_map<_key_type,_mapped_type,_type_of_tree_node,_compare> _type_tree;

        //дефолт конструктор+
        map()=default;

        //деструктор+
        ~map() {
            tree.del_all_elem(tree.get_head_node());
        }

        //проверка на пустоту+
        bool is_empty(){
            return tree.is_empty();
        }

        //удаление всех эементов+
        bool del_all_elem(){
            return tree.del_all_elem(tree.begin());
        }

        //вставка элемента (сразу кортежем)
        map_tree_iterator<tree_elem> insert(tree_elem elem){
            return this->tree.insert(elem);
        }

        //оператор возвращающий ссылку на значение
        _mapped_type& operator[](_key_type& key){
            return tree.find(key);
        }

        //копирующий оператор присваивания
        map& operator=(map cop_elem){
            this->tree=cop_elem.tree;
        }

        //поиск элемента по ключу и возвращение кортежа
        tree_elem& find(_key_type& key){
            return tree.find(key);
        }

        //работа с итераторм
        map_tree_iterator<tree_elem>& begin(){
            return tree.begin;
        }

        //работа с итераторм
        map_tree_iterator<tree_elem>& end(){
            return tree.end;
        }

        bool del_elem(map_tree_iterator<tree_elem>& elem){
            return tree.del_elem(elem);
        }

        //удаление элемента по значению ключа
        bool del_elem(_key_type key_elem){
            return tree.del_elem(key_elem);
        }

    private:
        _type_tree tree;
    };
}

#endif //LAB2_MAP_H
