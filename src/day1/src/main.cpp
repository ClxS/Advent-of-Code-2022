#include <string>

#include "core/Logging.h"
#include "day1/externs.h"

int main()
{
    const auto data = day1_loadData(false);
    AT_INFO(Day1, "Part 1: {}", day1_part1(data));
    AT_INFO(Day2, "Part 2: {}", day1_part2(data));
    return 0;
}