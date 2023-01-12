#include "hooks.h"

void Hooks::Init( ) {
	if ( MH_Initialize( ) != MH_OK )
		return;

	// gl_drawhud
	GlDrawHud.Hook(
		reinterpret_cast< void* >( Memory::FindPattern( "55 8B EC 83 E4 F8 81 EC ? ? ? ? A1 ? ? ? ? 89" ) ),  
		&hkGlDrawHud );
}