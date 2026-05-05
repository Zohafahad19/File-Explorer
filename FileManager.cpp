
#include "FileManager.h"
#include <iostream>
#include <fstream>

FileManager::FileManager() {
    currentPath = fs::current_path();
}

std::string FileManager::getCurrentPath() {
    return currentPath.string();
}

void FileManager::listDirectory() {
    std::cout << "\nContents of: " << currentPath << "\n";

    for (const auto& entry : fs::directory_iterator(currentPath)) {
        std::cout << (entry.is_directory() ? "[DIR] " : "[FILE] ");
        std::cout << entry.path().filename().string() << "\n";
    }
}

void FileManager::changeDirectory(const std::string& path) {
    fs::path newPath = currentPath / path;

    if (fs::exists(newPath) && fs::is_directory(newPath)) {
        currentPath = fs::canonical(newPath);
    } else {
        std::cout << "Invalid directory.\n";
    }
}

void FileManager::goUpDirectory() {
    if (currentPath.has_parent_path()) {
        currentPath = currentPath.parent_path();
    }
}

void FileManager::createFile(const std::string& name) {
    std::ofstream file(currentPath / name);
    if (file) {
        std::cout << "File created.\n";
    } else {
        std::cout << "Failed to create file.\n";
    }
}

void FileManager::createDirectory(const std::string& name) {
    if (fs::create_directory(currentPath / name)) {
        std::cout << "Directory created.\n";
    } else {
        std::cout << "Failed to create directory.\n";
    }
}

void FileManager::deleteFile(const std::string& name) {
    if (fs::remove(currentPath / name)) {
        std::cout << "File deleted.\n";
    } else {
        std::cout << "Failed to delete file.\n";
    }
}

void FileManager::deleteDirectory(const std::string& name) {
    if (fs::remove_all(currentPath / name)) {
        std::cout << "Directory deleted.\n";
    } else {
        std::cout << "Failed to delete directory.\n";
    }
}

void FileManager::showMetadata(const std::string& name) {
    fs::path p = currentPath / name;

    if (!fs::exists(p)) {
        std::cout << "File does not exist.\n";
        return;
    }

    std::cout << "\nMetadata for: " << name << "\n";

    std::cout << "Size: ";
    if (fs::is_regular_file(p))
        std::cout << fs::file_size(p) << " bytes\n";
    else
        std::cout << "N/A\n";

    std::cout << "Type: ";
    if (fs::is_directory(p)) std::cout << "Directory\n";
    else if (fs::is_regular_file(p)) std::cout << "File\n";
    else std::cout << "Other\n";

    auto perms = fs::status(p).permissions();

    std::cout << "Permissions: ";
    std::cout << ((perms & fs::perms::owner_read) != fs::perms::none ? "r" : "-");
    std::cout << ((perms & fs::perms::owner_write) != fs::perms::none ? "w" : "-");
    std::cout << ((perms & fs::perms::owner_exec) != fs::perms::none ? "x" : "-");
    std::cout << "\n";
}
