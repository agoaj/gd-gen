#pragma once
#include <filesystem>

class reflection
{
public:
    static std::filesystem::path get_executable_path();
};
