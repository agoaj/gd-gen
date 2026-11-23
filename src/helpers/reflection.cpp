#include "reflection.h"

#include <filesystem>
#include <vector>

//Note: On c++23 we could change this to #ifdef and #elifdef
#if defined(_WIN32)
#include <windows.h>
#elif defined(__linux__)
#include <unistd.h>
#elif defined(__APPLE__)
#include <mach-o/dyld.h>
#endif


std::filesystem::path reflection::get_executable_path()
{
#ifdef _WIN32
    wchar_t path[MAX_PATH];
    GetModuleFileNameW(nullptr, path, MAX_PATH);
    return path;
#endif
#ifdef __linux__
    return std::filesystem::read_symlink("/proc/self/exe");
#endif
#ifdef __APPLE__
    uint32_t pathSize = 0;
    _NSGetExecutablePath(nullptr, &pathSize);
    std::vector<char> pathChars;
    pathChars.resize(pathSize);
    int error = _NSGetExecutablePath(pathChars.data(), &pathSize);
    if (error == 0)
    {
        //remove any ./..
        return std::filesystem::canonical(path.data());
    }
    return {};
#endif
}