//
// Created by kirill_kazarin on 26.02.2022.
//

#ifndef LAB2_MAP_TREE_ELEMENT_H
#define LAB2_MAP_TREE_ELEMENT_H

struct map_tree_node_base
{
    map_tree_node_base* parent= nullptr;

    map_tree_node_base* left= nullptr;
    map_tree_node_base* right= nullptr;


    map_tree_node_base() =default;

    ~map_tree_node_base()= default;

    explicit map_tree_node_base(map_tree_node_base *parent) : parent(parent) {}

    map_tree_node_base(map_tree_node_base *parent,
                       map_tree_node_base *left,
                       map_tree_node_base *right) : parent(
            parent), left(left), right(right) {}


    [[nodiscard]]/*возращаемое значение должно быть использованно*/ bool
    is_tree_leaf() const {
        if(left!= nullptr||right!= nullptr)return false;
        return true;
    }

    map_tree_node_base*
    return_min_element(){
        map_tree_node_base* res_elemeent= this;
        while (res_elemeent->left!= nullptr)
            res_elemeent=res_elemeent->left;
        return res_elemeent;
    }

    map_tree_node_base*
    return_max_element(){
        map_tree_node_base* res_elemeent= this;
        while (res_elemeent->right!= nullptr)
            res_elemeent=res_elemeent->right;

        return res_elemeent;
    }
};


map_tree_node_base* left_turn(map_tree_node_base* A){
    map_tree_node_base* B= A->right;
    A->right=B->left;
    B->left=A;
    return B;
}

map_tree_node_base* right_turn(map_tree_node_base* A){
    map_tree_node_base* B= A->left;
    A->right = B->left;
    A->right->left=A;
    return A->right;
}



map_tree_node_base* turn(map_tree_node_base* A, map_tree_node_base* A_child){
    if(A_child==A->left)return right_turn(A);
    return left_turn(A);
}

template<typename _type_elem>
struct tree_node: public map_tree_node_base{
    _type_elem _val;

};



template<typename _key_type,typename _type_elem>
struct map_tree_RB_node: public tree_node<std::pair<_key_type,_type_elem>>{

  enum color {
        Red_color=true,
        Black_color=false
    };

  map_tree_node_base* rebalance_after_insert(map_tree_node_base* _x ,map_tree_node_base* _header_of_tree){

       auto* x=static_cast<map_tree_RB_node*>(_x);
      //1случай
      if(_x==_header_of_tree){
          x->_color= color::Black_color;
          return static_cast<map_tree_node_base*>(this);
      }

       auto* parent_of_x=static_cast<map_tree_RB_node*>(_x->parent);
       //2случай
       if(!parent_of_x->_color){
           return static_cast<map_tree_node_base*>(this);
       }

       auto* uncle_of_x=static_cast<map_tree_RB_node*>(_x->parent->parent->left==_x->parent->parent ? _x->parent->parent->right:
                                                       _x->parent->parent->left );
       auto* gparent_of_x=static_cast<map_tree_RB_node*>(_x->parent->parent);
       //3случай
       if(parent_of_x->_color && uncle_of_x->_color){
           uncle_of_x->_color=parent_of_x->_color= color::Black_color;
           gparent_of_x->_color= color::Red_color;

           return rebalance_after_insert(gparent_of_x,_header_of_tree);
       }
//4случай
       if(parent_of_x->right==_x&&parent_of_x==gparent_of_x->left) {
           left_turn(parent_of_x);
           right_turn(gparent_of_x);
       }
      if(parent_of_x->left==_x&&parent_of_x==gparent_of_x->right){
          right_turn(parent_of_x);
          left_turn(gparent_of_x);
      }
           gparent_of_x->_color= color::Red_color;
           parent_of_x->_color= color::Black_color;
           return static_cast<map_tree_node_base*>(this);

  }

    void rebalance_after_del_black_node(map_tree_node_base* _x ,map_tree_node_base* _header_of_tree){

        //1случай
        if(_x==_header_of_tree){
            return;
        }

        //2случай
        auto* brother_of_x=static_cast<map_tree_RB_node*>(_x->parent->left==_x ? _x->parent->right:
                                                          _x->parent->left );
        auto* parent_of_x=static_cast<map_tree_RB_node*>(_x->parent);

        auto* left_of_br=static_cast<map_tree_RB_node*>(brother_of_x->left);
        auto* right_of_br=static_cast<map_tree_RB_node*>(brother_of_x->right);

        if(brother_of_x->_color){
            brother_of_x->_color=color::Black_color;
            parent_of_x->_color=color::Red_color;
            turn(parent_of_x,brother_of_x);
        } else{
            //3 случай
            if(!parent_of_x->_color &&
            !left_of_br->_color &&
            !right_of_br->_color ){
                brother_of_x->_color=color::Red_color;
                return rebalance_after_del_black_node(parent_of_x,_header_of_tree);
            }
        }
        //4случай
        if(!left_of_br->_color && !right_of_br->_color && parent_of_x->_color){
            brother_of_x->_color=color::Red_color;
            parent_of_x->_color=color::Black_color;
            return;
        }

        //случай 5
        //if()
    }

  color _color= color::Red_color;
};

template<typename _key_type,typename _type_elem>
struct map_tree_AVL_node: public tree_node<std::pair<_key_type,_type_elem>>{
    int8_t weight_node;
};


#endif //LAB2_MAP_TREE_ELEMENT_H
