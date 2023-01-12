#include "../utils/render.h"
#include "../core/hooks.h"

void __cdecl Hooks::hkGlDrawHud( int w, int h, int curfps, int nquads, int curvert, bool underwater, int elapsed ) {
	const auto og{ GlDrawHud.Original<decltype( &hkGlDrawHud )>( ) };

	og( w, h, curfps, nquads, curvert, underwater, elapsed );

	Render::BeginDraw( );
	{
		Render::Rect( { 100, 100 }, { 900, 900 }, Color( 255,0,0 ) );
		Render::RectFilled( { 100, 100 }, { 900, 900 }, Color( 0,0,255 ) );
	}
	Render::EndDraw( );
}