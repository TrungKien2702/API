#include <iostream>
#include <windows.h>

int main() {
    MEMORYSTATUSEX memoryStatus;
    memoryStatus.dwLength = sizeof(memoryStatus);

    if (GlobalMemoryStatusEx(&memoryStatus)) {
        std::cout << "Total physical memory: " << memoryStatus.ullTotalPhys / (1024 * 1024) << " MB" << std::endl;
        std::cout << "Available physical memory: " << memoryStatus.ullAvailPhys / (1024 * 1024) << " MB" << std::endl;
        std::cout << "Total virtual memory: " << memoryStatus.ullTotalVirtual / (1024 * 1024) << " MB" << std::endl;
        std::cout << "Available virtual memory: " << memoryStatus.ullAvailVirtual / (1024 * 1024) << " MB" << std::endl;
    } else {
        std::cerr << "GlobalMemoryStatusEx failed (" << GetLastError() << ")." << std::endl;
        return 1;
    }

    return 0;
}

