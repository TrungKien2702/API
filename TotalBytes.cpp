#include <iostream>
#include <windows.h>

int main() {
    ULARGE_INTEGER totalBytesAvailable;
    ULARGE_INTEGER totalBytes;
    ULARGE_INTEGER totalFreeBytes;

    wchar_t currentDirectory[MAX_PATH];
    GetCurrentDirectoryW(MAX_PATH, currentDirectory);

    if (GetDiskFreeSpaceExW(currentDirectory, &totalBytesAvailable, &totalBytes, &totalFreeBytes)) {
        std::cout << "Total Bytes Available: " << totalBytesAvailable.QuadPart << " bytes" << std::endl;
        std::cout << "Total Bytes: " << totalBytes.QuadPart << " bytes" << std::endl;
        std::cout << "Total Free Bytes: " << totalFreeBytes.QuadPart << " bytes" << std::endl;
    }
    else {
        std::cout << "Failed to get disk information." << std::endl;
    }

    return 0;
}