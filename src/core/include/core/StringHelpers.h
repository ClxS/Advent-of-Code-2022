#pragma once
#include <string_view>
#include <vector>

namespace core
{
    std::vector<std::string_view> splitString(std::string_view str, const std::string_view splitter)
    {
        std::vector<std::string_view> result{16};

        size_t t;
        while ((t = str.find(splitter)) != std::string_view::npos)
        {
            auto firstHalf = str.substr(0, t);
            result.push_back(firstHalf);
            str = str.substr(t + splitter.size());
        }

        result.push_back(str);
        return result;
    }
}
