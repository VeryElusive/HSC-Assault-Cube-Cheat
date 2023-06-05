#include "hooks.h"
#include <d3d9.h>
#include <thread>

void Hooks::Init( ) {
	if ( MH_Initialize( ) != MH_OK )
		return;

	// gl_drawhud
	GlDrawHud.Hook(
		reinterpret_cast< void* >( Memory::FindPattern( "55 8B EC 83 E4 F8 81 EC ? ? ? ? A1 ? ? ? ? 89" ) ),  
		&hkGlDrawHud );	
	

	HMODULE hMod = GetModuleHandle( "opengl32.dll" );

	if ( hMod )
		GlSwapBuffers.Hook(
			reinterpret_cast< void* >( GetProcAddress( hMod, "wglSwapBuffers" ) ),
			&hkGlSwapBuffers );



	//GlSwapBuffers = ( uintptr_t ) mem::TrampolineHook( ( void* ) GetProcAddress( hMod, function ), hFunction, 5 );


	//EnableNonClientDpiScaling( FindWindow( "SDL_app", NULL ) );
	OldWndProc = ( WNDPROC )SetWindowLongPtr( FindWindow( "SDL_app", NULL ), GWL_WNDPROC, ( LONG_PTR )hkWndProc );
}