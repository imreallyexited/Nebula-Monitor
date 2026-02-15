#ifndef SYS_INFO_H
#define SYS_INFO_H

#include <windows.h>

// Ensure C++ compiler handles C code correctly
#ifdef __cplusplus
extern "C" {
#endif

    // Structure to hold system memory statistics
    typedef struct {
        unsigned long long total_ram; // Total Physical RAM (MB)
        unsigned long long free_ram;  // Available RAM (MB)
        int memory_load;              // Memory Load (%)
    } NebulaStats;

    // Function prototype
    NebulaStats get_system_ram();

#ifdef __cplusplus
}
#endif

#endif