#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    printf("Parent Process ID: %lu\n", GetCurrentProcessId());

    // Create child process
    if (CreateProcess(
            NULL,
            (LPSTR)"notepad.exe",     // FIXED
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si,
            &pi
        )) {

        printf("Child Process created successfully!\n");
        printf("Child Process ID: %lu\n", pi.dwProcessId);
    } else {
        printf("Failed to create child process.\n");
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
