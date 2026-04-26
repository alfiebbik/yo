#include <windows.h>

extern "C" __declspec(dllexport) void Init() {}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    return TRUE;
}
