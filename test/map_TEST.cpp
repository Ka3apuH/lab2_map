#include <iostream>

#include "tree_for_map.h"
#include "gtest/gtest.h"
#include "map_tree_element.h"

//#include "testing_main_func_map.h"

using namespace std;

/*TEST_F(Testing_main_func_priority_queue,add_element){

    unsigned int sizeOfHeap=randomDevice()%103;
    //чтобы не было часто равно 0.... взял простое число

    h_work::map<int,int> map;

    for (unsigned int i = 0; i < sizeOfHeap; ++i) {
        auto element=randomDevice();
        test_heap.add_element(element);
        real_heap.push(element);
    }

    for (unsigned int i = 0; i < sizeOfHeap; ++i) {

        ASSERT_EQ(test_heap.max_elem(),real_heap.top());
        test_heap.pop();
        real_heap.pop();
    }
}*/
TEST(aaa,add_2_element){

    enum color {
        Red_color=true,
        Black_color=false
    };

}
/*TEST_F(Testing_main_func_priority_queue,add_2_element){


    unsigned int sizeOfHeap=randomDevice()%103;
    //чтобы не было часто равно 0.... взял простое число

    for (unsigned int i = 0; i < sizeOfHeap; ++i) {
        auto element=randomDevice();
        test_heap.add_element(element);
        real_heap.push(element);
    }

    for (unsigned int i = 0; i < sizeOfHeap; ++i) {

        ASSERT_EQ(test_heap.max_elem(),real_heap.top());
        test_heap.pop();
        real_heap.pop();
    }
}*/


