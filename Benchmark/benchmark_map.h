//
// Created by kirill_kazarin on 24.02.2022.
//


#ifndef LAB1_BENCHMARK_MAP_H
#define LAB1_BENCHMARK_MAP_H

#include <random>
#include "benchmark/benchmark.h"
#include "tree_for_map.h"
#include "map.h"

class benchmark_priority_queue_fix: public benchmark::Fixture{

public:
    benchmark_priority_queue_fix()  = default;

    ~benchmark_priority_queue_fix() override = default;

    void SetUp(const ::benchmark::State &state) override  {

        //pr_heap.clear();
        for (int64_t i = 0; i < state.range(0); ++i) {
        }
        std::cout<<"set"<<std::endl;
    }

    void TearDown(const ::benchmark::State &state) override {
        std::cout<<"down"<<std::endl;
    }


protected:
    h_work::map<unsigned int,int64_t> test_map;
    std::random_device randomDevice;
};

#endif //LAB1_BENCHMARK_MAP_H
