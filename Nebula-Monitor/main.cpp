#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
#include "sys_info.h" // Link to our C engine

using namespace std;

// Function to draw the UI header
void render_header() {
    system("cls"); // Clear console screen

    // Set Color: Green (A)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

    cout << "========================================" << endl;
    cout << "   NEBULA-MONITOR v1.0 (SYSTEM CORE)    " << endl;
    cout << "========================================" << endl;

    // Set Color: White (7)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "Status: ACTIVE | Press Ctrl+C to exit" << endl << endl;
}

int main() {
    // Set the window title
    SetConsoleTitleA("Nebula-Monitor | Active Protection");

    while (true) {
        // 1. Fetch data from C Engine
        NebulaStats ram_data = get_system_ram();

        // 2. Render Interface
        render_header();

        cout << "[+] SYSTEM MEMORY DIAGNOSTICS:" << endl;
        cout << "------------------------------" << endl;
        cout << "TOTAL RAM : " << ram_data.total_ram << " MB" << endl;
        cout << "FREE RAM  : " << ram_data.free_ram << " MB" << endl;

        // Progress Bar Logic
        cout << "LOAD      : [";
        int bar_count = ram_data.memory_load / 5; // 1 bar for every 5%

        // Filled part (Red - 12)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        for (int i = 0; i < bar_count; i++) cout << "#";

        // Empty part (Grey - 8)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        for (int i = bar_count; i < 20; i++) cout << ".";

        // Reset color and print percentage
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << "] " << ram_data.memory_load << "%" << endl;

        // Refresh every 1 second
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    return 0;
}