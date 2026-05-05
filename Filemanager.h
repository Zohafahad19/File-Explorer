#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <filesystem>

namespace fs = std::filesystem;

class FileManager {
private:
    fs::path currentPath;

public:
    FileManager();

    void listDirectory();
    void changeDirectory(const std::string& path);
    void goUpDirectory();

    void createFile(const std::string& name);
    void createDirectory(const std::string& name);

    void deleteFile(const std::string& name);
    void deleteDirectory(const std::string& name);

    void showMetadata(const std::string& name);

    std::string getCurrentPath();
};

#endif
