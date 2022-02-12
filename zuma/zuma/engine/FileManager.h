//
// Created by lilu on 09/02/2022.
//

#ifndef ZUMA_FILEMANAGER_H
#define ZUMA_FILEMANAGER_H

#include <string>
#include <string_view>
#include <vector>
#include <functional>

class FileManager
{
public:
    [[nodiscard]] std::string resourceLocation(std::string filename) const;

    void setFindPaths(std::vector<std::string> findPaths);
    void forEachPath(const std::function<void(std::string)>& callback) const;

private:
    std::vector<std::string> _findPaths;
};


#endif //ZUMA_FILEMANAGER_H
