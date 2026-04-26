#include <Windows.h>

// This is the most basic entry point that won't throw errors
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        // This will show a message when the client loads on your Xbox/PC
        MessageBoxA(NULL, "BikBotClient Loaded!", "Success", MB_OK);
        break;
    }
    return TRUE;
}

// Exporting a dummy function to ensure the DLL actually builds
extern "C" __declspec(dllexport) void Init() {}
