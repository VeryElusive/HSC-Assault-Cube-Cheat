#include <thread>
#include "core/hooks.h"

void Entry( HMODULE hModule ) {
	Hooks::Init( );

	while ( true ) {
		if ( GetAsyncKeyState( VK_F11 ) )
			break;


		std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
	}

	FreeLibraryAndExitThread( hModule, EXIT_SUCCESS );
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD dwReason, LPVOID lpReserved ) {
	if ( dwReason == DLL_PROCESS_ATTACH ) {
		// no need for DLL_THREAD_ATTACH and DLL_THREAD_DETACH calls
		DisableThreadLibraryCalls( hModule );

		// once the cheat is uninjected we want to close the windows handle for our cheat process.
		CloseHandle( CreateThread( 0, 0, LPTHREAD_START_ROUTINE( Entry ), hModule, 0, 0 ) );

		return TRUE;
	}

	return FALSE;
}