//
// Created by lilu on 09/02/2022.
//

#include "FileManager.h"
#include "SDL.h"
//#define XSTRINGIFY(A) STRINGIFY(A)
#define STRINGIFY(A) #A
namespace
{
    constexpr const char* DefaultFilePaths[] =
            {
                    "",
                    "res/",
                    "../res/"
            };
}

void FileManager::setFindPaths(std::vector<std::string> findPaths)
{
    _findPaths = std::move(findPaths);
}

std::string FileManager::resourceLocation(std::string filename) const
{
    std::replace(filename.begin(), filename.end(), '\\', '/');

    std::string result;
    this->forEachPath([&](const std::string& path)
                      {
                          SDL_RWops *file = SDL_RWFromFile((path + filename).c_str(), "r");

                          if (file != nullptr)
                          {
                              SDL_RWclose(file);

                              result = path + filename;
                              return;
                          }

                      });

    return result;
}

void FileManager::forEachPath(const std::function<void(std::string)> &callback) const
{
    for (const auto& path : _findPaths)
    {
        callback(path);
        //callback(XSTRINGIFY(PROJECT_ROOT_FOLDER)"/" + path);
    }

    for (const auto& path : DefaultFilePaths)
    {
        callback(path);
        //callback(std::string(XSTRINGIFY(PROJECT_ROOT_FOLDER)"/") + path);
    }
}
