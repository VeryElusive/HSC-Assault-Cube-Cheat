#include "../core/hooks.h"

void __cdecl Hooks::hkGlDrawFrame( int w, int h ) {
	const auto og{ GlDrawFrame.Original<decltype( &hkGlDrawFrame )>( ) };

	og( w, h );
}