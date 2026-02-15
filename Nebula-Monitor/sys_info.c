#include "sys_info.h"
#include <stdio.h>

// Retrieve system memory status using Windows API
NebulaStats get_system_ram() {
    NebulaStats stats;
    MEMORYSTATUSEX statex;

    statex.dwLength = sizeof(statex);

    // Call GlobalMemoryStatusEx to get system info
    GlobalMemoryStatusEx(&statex);

    // Convert Bytes to Megabytes (1024 * 1024)
    stats.total_ram = statex.ullTotalPhys / (1024 * 1024);
    stats.free_ram = statex.ullAvailPhys / (1024 * 1024);
    stats.memory_load = statex.dwMemoryLoad;

    return stats;
}