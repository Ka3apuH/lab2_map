
#include <iostream>
#include "map_tree_element.h"
#include "map_iterator.h"


#ifndef LAB2_TREE_MAP_H
#define LAB2_TREE_MAP_H

namespace h_work{

    template<typename _key_type,typename _mapped_type,
            typename _type_of_tree_node=map_tree_RB_node<_key_type,_mapped_type>,
                    typename _compare=std::less<_key_type>>
    class tree_for_map{
    public:

        //тип элемента который лежит в узлах дерева
        typedef std::pair<_key_type,_mapped_type> tree_elem;

        tree_for_map()=default;

        ~tree_for_map(){
            del_all_elem( head_node);
        }

        bool is_empty() noexcept{
            if(head_node == nullptr)return true;
            return false;
        }

        map_tree_iterator<tree_elem>& begin(){
            return new map_tree_iterator<_mapped_type>(
                    static_cast<map_tree_node_base>(head_node).return_min_element());
        }

        //работа с итераторм
        map_tree_iterator<tree_elem>& end(){
            return new map_tree_iterator<_mapped_type>(static_cast<map_tree_node_base>(head_node));
        }

        void del_all_elem(map_tree_node_base* del_elem){

            if(del_elem->left!= nullptr){
                del_all_elem(del_elem->left);
            }
            if(del_elem->right!= nullptr){
                del_all_elem(del_elem->right);
            }

            (new std::allocator<_type_of_tree_node>)
            ->template destroy(static_cast<_type_of_tree_node*>(del_elem));
        }

        map_tree_iterator<tree_elem> insert(tree_elem elem){

        }


        [[nodiscard]] int64_t get_size() const {
            return size;
        }

        _type_of_tree_node* get_head_node() const {
            return head_node;
        }

    private:

        class Compare: std::binary_function<_key_type,_key_type,bool>{

        };

        int64_t size=0;
        _type_of_tree_node* head_node;
    };

}
#endif //LAB2_TREE_MAP_H