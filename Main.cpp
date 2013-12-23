/* 
 * File:   Main.cpp
 * Author: Gab
 *
 * Created on 23 de Janeiro de 2013, 22:42
 */

#include <windows.h>
#include <Plus.hpp>
#include <stdio.h>
/*
 * Main function
 *
 * @param  int    argc Number of arguments passed
 * @param  char** argv Pointer to argument strings
 * @return int    Exit code
 */
EXPORT(int) main(int argc, char** argv){
    Plus::Config::initialize();
    Plus::Graphics::initialize(544, 416);
    
    while (1){
        Plus::Graphics::update();
    }
    return 1;
}

/*
 * DLL Entry Point
 *
 * @param  HINSTANCE hinstDLL   Handle to DLL module
 * @param  DWORD     fdwReason  Reason for calling function
 * @param  LPVOID    lpReserved Reserved
 * 
 * @return BOOL      Permission to load or not the DLL.
 */

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved){
    return TRUE;
    
    // Perform actions based on the reason for calling.
    switch(fdwReason) { 
    case DLL_PROCESS_ATTACH:
        // Initialize once for each new process.
        // Return FALSE to fail DLL load.
        break;

    case DLL_THREAD_ATTACH:
        // Do thread-specific initialization.
        break;

    case DLL_THREAD_DETACH:
        // Do thread-specific cleanup.
        break;

    case DLL_PROCESS_DETACH:
        // Perform any necessary cleanup.
        break;

    default:
        // Other reason
        return FALSE;
    }

    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}