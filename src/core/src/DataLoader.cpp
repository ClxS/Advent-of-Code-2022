#include "core/DataLoader.h"

#include <filesystem>
#include <fstream>

namespace
{
    std::string loadFile(const std::filesystem::path& path)
    {
        std::ifstream file;
        file.open(path, std::ios::binary | std::ios::ate);

        const std::streamoff uiLength = file.tellg();

        // ReSharper disable once CppRedundantCastExpression
        file.seekg((std::streamoff)0, std::ios::beg);

        const std::unique_ptr<uint8_t[]> pData(new uint8_t[uiLength]);
        file.read(reinterpret_cast<char*>(pData.get()), uiLength);

        const auto pStrData = reinterpret_cast<const char*>(pData.get());
        std::string input(pStrData, uiLength / sizeof(char));
        return input;
    }
}

std::string core::loadSampleData(const std::filesystem::path& subPath)
{
    const std::filesystem::path path = std::filesystem::current_path();
    return loadFile(path / "data" / subPath / "sample.txt");
}

std::string core::loadData(const std::filesystem::path& subPath)
{
    const std::filesystem::path path = std::filesystem::current_path();
    return loadFile(path / "data" / subPath / "input.txt");
}
