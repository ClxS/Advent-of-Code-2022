#pragma once

#include <string>
#include <ranges>
#include <string>
#include <cstdint>
#include <execution>
#include <vector>
#include <algorithm>

#include "core/DataLoader.h"
#include "core/StringHelpers.h"

namespace day1
{
    struct Elf
    {
        int32_t m_CalorieCount{0};
    };
}

inline std::string day1_loadData(const bool sampleData)
{
    return sampleData ? core::loadSampleData("day1") : core::loadData("day1");
}

inline int32_t day1_part1(const std::string& data)
{
    int32_t maxCalories = 0;
    for(const auto& elfText : core::splitString(data, "\n\n"))
    {
        day1::Elf elf{};
        for(const auto& calorieText : core::splitString(elfText, "\n"))
        {
            int32_t calories = 0;
            std::from_chars(calorieText.data(), calorieText.data() + calorieText.size(), calories);
            elf.m_CalorieCount += calories;
        }

        maxCalories = std::max(maxCalories, elf.m_CalorieCount);
    }

    return maxCalories;
}

inline int32_t day1_part2(const std::string& data)
{
    int32_t currentLowestIdx = 0;
    int32_t currentMin = 0;
    int32_t maxCalories[3] = {
        0, 0, 0
    };
    
    for(const auto& elfText : core::splitString(data, "\n\n"))
    {
        day1::Elf elf{};
        for(const auto& calorieText : core::splitString(elfText, "\n"))
        {
            int32_t calories = 0;
            std::from_chars(calorieText.data(), calorieText.data() + calorieText.size(), calories);
            elf.m_CalorieCount += calories;
        }

        if (currentMin < elf.m_CalorieCount)
        {
            maxCalories[currentLowestIdx] = elf.m_CalorieCount;

            int lowestIdx = 0;
            int32_t lowestValue = maxCalories[0];
            for(int i = 1; i < 3; i++)
            {
                if (maxCalories[i] < lowestValue)
                {
                    lowestValue = maxCalories[i];
                    lowestIdx = i;
                }
            }
            
            currentLowestIdx = lowestIdx;
            currentMin = lowestValue;
        }
    }

    return maxCalories[0] + maxCalories[1] + maxCalories[2];
}