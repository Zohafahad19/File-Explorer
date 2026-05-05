#include "FileManager.h"
#include <iostream>

int main() {
    FileManager fm;
    int choice;
    std::string name;

    while (true) {
        std::cout << "\n===== Simple File Explorer =====\n";
        std::cout << "Current Path: " << fm.getCurrentPath() << "\n";

        std::cout << "\n1. List Directory\n";
        std::cout << "2. Change Directory\n";
        std::cout << "3. Go Up Directory\n";
        std::cout << "4. Create File\n";
        std::cout << "5. Create Directory\n";
        std::cout << "6. Delete File\n";
        std::cout << "7. Delete Directory\n";
        std::cout << "8. Show Metadata\n";
        std::cout << "9. Exit\n";

        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                fm.listDirectory();
                break;
            case 2:
                std::cout << "Enter directory name: ";
                std::cin >> name;
                fm.changeDirectory(name);
                break;
            case 3:
                fm.goUpDirectory();
                break;
            case 4:
                std::cout << "Enter file name: ";
                std::cin >> name;
                fm.createFile(name);
                break;
            case 5:
                std::cout << "Enter directory name: ";
                std::cin >> name;
                fm.createDirectory(name);
                break;
            case 6:
                std::cout << "Enter file name: ";
                std::cin >> name;
                fm.deleteFile(name);
                break;
            case 7:
                std::cout << "Enter directory name: ";
                std::cin >> name;
                fm.deleteDirectory(name);
                break;
            case 8:
                std::cout << "Enter file/directory name: ";
                std::cin >> name;
                fm.showMetadata(name);
                break;
            case 9:
                return 0;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}
