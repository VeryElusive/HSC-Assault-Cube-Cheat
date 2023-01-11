#include "hooks.h"
#include "memory.h"

void Hooks::Init( ) {
	if ( MH_Initialize( ) != MH_OK )
		return;

	// gl_drawframe
	GlDrawFrame.Hook(
		reinterpret_cast< void* >( Memory::FindPattern( "55 8B EC 83 E4 F0 81 EC ? ? ? ? 83 3D ? ? ? ? ? F3 0F 10 05" ) ),  
		&hkGlDrawFrame );
}