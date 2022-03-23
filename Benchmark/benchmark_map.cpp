#include <random>

#include "benchmark/benchmark.h"
#include "tree_for_map.h"
#include <map>
#include "benchmark_map.h"


BENCHMARK_DEFINE_F(benchmark_priority_queue_fix,BM_priority_queue_add_elements) (benchmark::State& state) {

    std::map<int,std::string> aa;

    for(auto _ : state) {
        //pr_heap.add_element(INT32_MAX);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK_DEFINE_F(benchmark_priority_queue_fix,BM_priority_queue_del_elements) (benchmark::State& state) {
    for (auto _ : state) {
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK_DEFINE_F(benchmark_priority_queue_fix,BM_priority_queue_sort_elements) (benchmark::State& state) {
    for (auto _ : state) {
        for (int64_t i = 0; i <state.range(0) ; ++i) {
        }
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK_REGISTER_F(benchmark_priority_queue_fix, BM_priority_queue_add_elements)
->RangeMultiplier(2)
->Range(8<<3, 8<<12)
        ->Iterations(10)
->Complexity(benchmark::oAuto);

BENCHMARK_REGISTER_F(benchmark_priority_queue_fix, BM_priority_queue_del_elements)
->RangeMultiplier(2)
->Range(8<<3, 8<<12)
        ->Iterations(10)
->Complexity(benchmark::oAuto);

BENCHMARK_REGISTER_F(benchmark_priority_queue_fix, BM_priority_queue_sort_elements)
        ->RangeMultiplier(2)
        ->Range(8<<3, 8<<12)
        ->Iterations(10)
        ->Complexity(benchmark::oAuto);

// Run the benchmark
//BENCHMARK_MAIN();



