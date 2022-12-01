#pragma once
#include <filesystem>
#include <string>

namespace core
{
    std::string loadSampleData(const std::filesystem::path& subPath);
    std::string loadData(const std::filesystem::path& subPath);    
}
