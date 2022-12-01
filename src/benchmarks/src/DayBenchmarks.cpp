#include "benchmark/benchmark.h"
#include "day1/externs.h"

namespace data
{
}

#define DO(DAY)\
    namespace data\
    {\
        std::string DAY;\
    }\
    void load##DAY##Data([[maybe_unused]] const benchmark::State& state)\
    {\
        data::##DAY = DAY##_loadData(false);\
    }\
    void bench_##DAY##_part1([[maybe_unused]] benchmark::State& state)\
    {\
        for (auto _ : state)\
        {\
            DAY##_part1(data::##DAY);\
        }\
    }\
    void bench_##DAY##_part2([[maybe_unused]] benchmark::State& state)\
    {\
        for (auto _ : state)\
        {\
            DAY##_part2(data::##DAY);\
        }\
    }\
    BENCHMARK(bench_##DAY##_part1)->Setup(load##DAY##Data)->Unit(benchmark::kMicrosecond);\
    BENCHMARK(bench_##DAY##_part2)->Setup(load##DAY##Data)->Unit(benchmark::kMicrosecond);

DO(day1);